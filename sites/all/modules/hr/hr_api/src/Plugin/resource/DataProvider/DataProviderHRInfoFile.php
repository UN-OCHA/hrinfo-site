<?php

/**
 * @file
 * Contains \Drupal\hr_api\Plugin\resource\DataProvider\DataProviderHRInfoFile.
 */

namespace Drupal\hr_api\Plugin\resource\DataProvider;

use Drupal\restful\Exception\BadRequestException;
use Drupal\restful\Exception\ForbiddenException;
use Drupal\restful\Exception\ServiceUnavailableException;
use Drupal\restful\Http\RequestInterface;
use Drupal\restful\Plugin\resource\Field\ResourceFieldCollectionInterface;
use Drupal\restful\Plugin\resource\DataProviderFile;

/**
 * Class DataProviderFile.
 *
 * @package Drupal\restful\Plugin\resource\DataProvider
 */
class DataProviderHRInfoFile extends DataProviderFile {

  /**
   * An adaptation of file_save_upload() that includes more verbose errors.
   *
   * @param string $source
   *   A string specifying the filepath or URI of the uploaded file to save.
   * @param array $files
   *   Array containing information about the files.
   *
   * @return object
   *   The saved file object.
   *
   * @throws BadRequestException
   * @throws ServiceUnavailableException
   *
   * @see file_save_upload()
   */
  protected function fileSaveUpload($source, array $files) {
    static $upload_cache;

    $provider_options = $this->getOptions();
    $options = $provider_options['options'];

    $validators = empty($options['validators']) ? NULL : $options['validators'];
    $destination = $options['scheme'] . "://";
    $replace = empty($options['replace']) ? NULL : $options['replace'];

    // Return cached objects without processing since the file will have
    // already been processed and the paths in _FILES will be invalid.
    if (isset($upload_cache[$source])) {
      return $upload_cache[$source];
    }

    // Make sure there's an upload to process.
    if (empty($files['files']['name'][$source])) {
      return NULL;
    }

    $this->checkUploadErrors($source, $files);

    // Begin building file object.
    $file_array = array(
      'uid' => $this->getAccount()->uid,
      'status' => 0,
      'filename' => trim(drupal_basename($files['files']['name'][$source]), '.'),
      'uri' => $files['files']['tmp_name'][$source],
      'filesize' => $files['files']['size'][$source],
    );
    $file_array['filemime'] = file_get_mimetype($file_array['filename']);

    $file = (object) $file_array;

    $extensions = '';
    if (isset($validators['file_validate_extensions'])) {
      if (isset($validators['file_validate_extensions'][0])) {
        // Build the list of non-munged extensions if the caller provided them.
        $extensions = $validators['file_validate_extensions'][0];
      }
      else {
        // If 'file_validate_extensions' is set and the list is empty then the
        // caller wants to allow any extension. In this case we have to remove
        // the validator or else it will reject all extensions.
        unset($validators['file_validate_extensions']);
      }
    }
    else {
      // No validator was provided, so add one using the default list.
      // Build a default non-munged safe list for file_munge_filename().
      $extensions = 'jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp';
      $validators['file_validate_extensions'] = array();
      $validators['file_validate_extensions'][0] = $extensions;
    }

    if (!empty($extensions)) {
      // Munge the filename to protect against possible malicious extension
      // hiding within an unknown file type (ie: filename.html.foo).
      $file->filename = file_munge_filename($file->filename, $extensions);
    }

    // Rename potentially executable files, to help prevent exploits (i.e. will
    // rename filename.php.foo and filename.php to filename.php.foo.txt and
    // filename.php.txt, respectively). Don't rename if 'allow_insecure_uploads'
    // evaluates to TRUE.
    if (!variable_get('allow_insecure_uploads', 0) && preg_match('/\.(php|pl|py|cgi|asp|js)(\.|$)/i', $file->filename) && (substr($file->filename, -4) != '.txt')) {
      $file->filemime = 'text/plain';
      $file->uri .= '.txt';
      $file->filename .= '.txt';
      // The .txt extension may not be in the allowed list of extensions. We
      // have to add it here or else the file upload will fail.
      if (!empty($extensions)) {
        $validators['file_validate_extensions'][0] .= ' txt';

        // Unlike file_save_upload() we don't need to let the user know that
        // for security reasons, your upload has been renamed, since RESTful
        // will return the file name in the response.
      }
    }

    // If the destination is not provided, use the temporary directory.
    if (empty($destination)) {
      $destination = 'temporary://';
    }

    // Assert that the destination contains a valid stream.
    $destination_scheme = file_uri_scheme($destination);
    if (!$destination_scheme || !file_stream_wrapper_valid_scheme($destination_scheme)) {
      $message = format_string('The file could not be uploaded, because the destination %destination is invalid.', array('%destination' => $destination));
      throw new ServiceUnavailableException($message);
    }

    $file->source = $source;
    // A URI may already have a trailing slash or look like "public://".
    if (substr($destination, -1) != '/') {
      $destination .= '/';
    }
    $file->destination = file_destination($destination . $file->filename, $replace);
    // If file_destination() returns FALSE then $replace == FILE_EXISTS_ERROR
    // and there's an existing file so we need to bail.
    if ($file->destination === FALSE) {
      $message = format_string('The file %source could not be uploaded because a file by that name already exists in the destination %directory.', array('%source' => $source, '%directory' => $destination));
      throw new ServiceUnavailableException($message);
    }

    // Add in our check of the the file name length.
    $validators['file_validate_name_length'] = array();

    // Call the validation functions specified by this function's caller.
    $errors = file_validate($file, $validators);

    // Check for errors.
    if (!empty($errors)) {
      $message = format_string('The specified file %name could not be uploaded.', array('%name' => $file->filename));
      if (count($errors) > 1) {
        $message .= theme('item_list', array('items' => $errors));
      }
      else {
        $message .= ' ' . array_pop($errors);
      }

      throw new ServiceUnavailableException($message);
    }

    // Move uploaded files from PHP's upload_tmp_dir to Drupal's temporary
    // directory. This overcomes open_basedir restrictions for future file
    // operations.
    $file->uri = $file->destination;
    if (!$this::moveUploadedFile($files['files']['tmp_name'][$source], $file->uri)) {
      watchdog('file', 'Upload error. Could not move uploaded file %file to destination %destination.', array('%file' => $file->filename, '%destination' => $file->uri));
      $message = 'File upload error. Could not move uploaded file.';
      throw new ServiceUnavailableException($message);
    }

    // Set the permissions on the new file.
    drupal_chmod($file->uri);

    // If we are replacing an existing file re-use its database record.
    if ($replace == FILE_EXISTS_REPLACE) {
      $existing_files = file_load_multiple(array(), array('uri' => $file->uri));
      if (count($existing_files)) {
        $existing = reset($existing_files);
        $file->fid = $existing->fid;
      }
    }

    // Change the file status from temporary to permanent.
    $file->status = FILE_STATUS_PERMANENT;

    // If we made it this far it's safe to record this file in the database.
    if ($file = file_save($file)) {
      // Add file to the cache.
      $upload_cache[$source] = $file;
      return $file;
    }

    // Something went wrong, so throw a general exception.
    throw new ServiceUnavailableException('Unknown error has occurred.');
  }

}

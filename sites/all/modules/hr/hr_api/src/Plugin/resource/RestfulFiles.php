<?php

/**
 * @file
 * Contains \Drupal\hr_api\Plugin\resource\RestfulFiles
 */

namespace Drupal\hr_api\Plugin\resource;

use Drupal\restful\Exception\UnauthorizedException;
use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;
use Drupal\restful\Http\RequestInterface;

/**
 * Class RestfulFiles
 * @package Drupal\hr_api\Plugin\Resource
 *
 * @Resource(
 *   name = "files:1.0",
 *   resource = "files",
 *   label = "File upload",
 *   description = "A file upload wrapped with RESTful.",
 *   authenticationOptional = TRUE,
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   dataProvider = {
 *     "entityType": "file",
 *     "options": {
 *       "scheme": "public"
 *     }
 *   },
 *   menuItem = "files",
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */
class RestfulFiles extends ResourceCustom implements ResourceInterface {

  /**
   * {@inheritdoc}
   *
   * If "File entity" module exists, determine access by its provided
   * permissions otherwise, check if variable is set to allow anonymous users to
   * upload. Defaults to authenticated user.
   */
  public function access() {
    if ($this->getRequest()->getMethod() == RequestInterface::METHOD_OPTIONS) {
      return true;
    }
    // The getAccount method may return an UnauthorizedException when an
    // authenticated user cannot be found. Since this is called from the access
    // callback, not from the page callback we need to catch the exception.
    try {
      $account = $this->getAccount();
    }
    catch (UnauthorizedException $e) {
      // If a user is not found then load the anonymous user to check
      // permissions.
      $account = drupal_anonymous_user();
    }
    if (module_exists('file_entity')) {
      return user_access('bypass file access', $account) || user_access('create files', $account);
    }

    return (variable_get('restful_file_upload_allow_anonymous_user', FALSE) || $account->uid) && parent::access();
  }

  /**
   * {@inheritdoc}
   */
  protected function dataProviderClassName() {
    return '\Drupal\restful\Plugin\resource\DataProvider\DataProviderFile';
  }

}

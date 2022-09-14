<?php

/**
 * Could also implement Iterator: http://php.net/manual/en/class.iterator.php
 */
class SpatialKMZ {
  protected $extracted_path = '';
  protected $uri = '';

  public function __construct($uri) {
    $this->uri = $uri;
    $this->extracted_path = drupal_realpath('temporary://spatial_kmz_'. basename($this->uri, '.kmz'));

    // Unzip.
    $zip = new ArchiverZip(drupal_realpath($this->uri));
    $zip->extract($this->extracted_path);
  }

  public function __destruct() {
    // Delete extracted folder.
    file_unmanaged_delete_recursive($this->extracted_path);
  }

  public function process() {
    $result = array();

    /**
     * Look for KML files only at the top level of the unzipped folder, i.e. do not recurse.
     * @see https://developers.google.com/kml/documentation/kmzarchives
     */
    $kml_files = file_scan_directory($this->extracted_path, '/^.*\.(kml)$/', array('recurse' => FALSE));

    foreach ($kml_files as $kml_file) {
      if ($ogr2ogr_kml = ogr2ogr_open($kml_file->uri)) {
        if ($spatial_features = $ogr2ogr_kml->getWkt()) {
          $result = array_merge($result, $spatial_features);
        }
      }

      /**
       * According to https://developers.google.com/kml/documentation/kmzarchives ,
       * we can stop looking for KML files after finding the first one.
       */
      break;
    }

    return $result;
  }
}

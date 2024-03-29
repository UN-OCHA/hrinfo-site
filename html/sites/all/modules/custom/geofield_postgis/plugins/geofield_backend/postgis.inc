<?php

/**
 * @file
 * This is a contrib module, but no composer-compatible version exists.
 *
 * @see https://www.drupal.org/project/geofield_postgis.
 */

$plugin = array(
  'title' => 'PostGIS',
  'schema' => 'geofield_postgis_backend_schema',
  'save' => 'geofield_postgis_backend_save',
  'types' => array(
    'Point',
    'LineString',
    'Polygon',
    'MultiPoint',
    'MultiLineString',
    'MultiPolygon',
    'GeometryCollection',
  ),
  // @todo Additional validation callback. Takes a GeoPHP Geometry object.
  'validate' => NULL,
  'update_field' => 'geofield_postgis_backend_update_field',
  // If we need to get rid of any additional data not on the field table.
  'delete_field' => NULL,
  'requirements' => 'geofield_postgis_backend_requirements',
  'settings' => 'geofield_postgis_backend_settings',
);

/**
 * Backend schema.
 */
function geofield_postgis_backend_schema($field) {
  // @TODO: SRID
  $settings = $field['settings']['postgis'];
  return array(
    'type' => 'blob',
    'pgsql_type' => $settings['fieldtype'],
    'not null' => FALSE,
  );
}

/**
 * Backend save.
 */
function geofield_postgis_backend_save($geometry) {
  $geometry = geoPHP::load($geometry);
  $unpacked = unpack('H*', $geometry->out('ewkb'));
  return $unpacked[1];
}

/**
 * Backend requirements.
 */
function geofield_postgis_backend_requirements(&$error) {
  try {
    $value = db_query('SELECT substring(PostGIS_Version() from 1 for 3)')->fetchField();
    if (empty($value)) {
      $error = 'Could not detect postGIS version';
      return FALSE;
    }

    $comparisson = version_compare($value, '1.5');
    if ($comparisson === FALSE) {
      $error = 'Could not detect postGIS version';
      return FALSE;
    }
    if ($comparisson == -1) {
      $error = 'PostGIS 1.5 or later required';
      return FALSE;
    }
    return TRUE;
  }
  catch (PDOException $e) {
    $error = 'Could not detect postGIS';
    return FALSE;
  }
}

/**
 * Backend settings.
 */
function geofield_postgis_backend_settings($field, $instance, $has_data) {
  $form = array();
  $defaults = (isset($field['settings']['postgis'])) ? $field['settings']['postgis'] : array();

  $form['fieldtype'] = array(
    '#title' => 'PostGIS Type',
    '#type' => 'select',
    '#options' => array(
      'geometry' => t('Geometry'),
    ),
    '#default_value' => $defaults['fieldtype'] ?? 'geometry',
    '#disabled' => $has_data,
  );

  // If we are running postGIS 2.0, add an option to use geography fields.
  try {
    $version = db_query('SELECT substring(PostGIS_Version() from 1 for 3)')->fetchField();
    if (version_compare($version, '2.0', '>=')) {
      $form['fieldtype']['#options']['geography'] = 'Geography';
    }
  }
  catch (PDOException $e) {
    // Do nothing.
  }

  return $form;
}

/**
 * Backend update field.
 */
function geofield_postgis_backend_update_field($field, $prior_field, $has_data) {
  if (!$has_data) {
    // @TODO: is there a better way to find this info?
    $db_info = $field['storage']['details']['sql']['FIELD_LOAD_CURRENT'];
    $table = current(array_keys($db_info));
    $column = $db_info[$table]['geom'];
    db_query('CREATE INDEX ' . $table . '_' . $column . '_postgis_idx ON {' . $table . '} USING GIST ( ' . $column . ' )');
  }
}

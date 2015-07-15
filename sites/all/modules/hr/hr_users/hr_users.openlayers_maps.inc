<?php
/**
 * @file
 * hr_users.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function hr_users_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'hr_people';
  $openlayers_maps->title = 'People';
  $openlayers_maps->description = '';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-7.186510064978123e-9, 7.186501469422994e-9',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_attribution' => array(
        'separator' => '',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'hr_users_map_data' => 'hr_users_map_data',
        ),
        'panMapIfOutOfView' => 0,
        'keepInMap' => 1,
      ),
    ),
    'default_layer' => 'mapbox_world_bright',
    'layers' => array(
      'mapbox_world_bright' => 'mapbox_world_bright',
      'mapbox_world_dark' => 'mapbox_world_dark',
      'mapbox_world_light' => 'mapbox_world_light',
      'mapbox_world_print' => 'mapbox_world_print',
      'mapbox_world_black' => 'mapbox_world_black',
      'hr_users_map_data' => 'hr_users_map_data',
    ),
    'layer_weight' => array(
      'openlayers_geojson_picture_this' => '0',
      'openlayers_kml_example' => '0',
      'hr_bundles_p' => '0',
      'hr_bundles_geojson' => '0',
      'hr_operations_geojson' => '0',
      'hr_users_map_data' => '0',
      'postgis_formatter_layer' => '0',
      'hr_users_geojson' => '0',
      'hr_bundles_et' => '0',
      'hr_bundles_cccm' => '0',
      'hr_bundles_wash' => '0',
      'hr_bundles_es' => '0',
      'hr_bundles_education' => '0',
      'hr_bundles_h' => '0',
      'hr_bundles_fs' => '0',
      'hr_bundles_n' => '0',
      'hr_bundles_l' => '0',
      'hr_bundles_er' => '0',
    ),
    'layer_styles' => array(
      'hr_bundles_er' => '0',
      'hr_bundles_education' => '0',
      'hr_bundles_es' => '0',
      'hr_bundles_wash' => '0',
      'hr_bundles_h' => '0',
      'hr_bundles_fs' => '0',
      'hr_bundles_l' => '0',
      'hr_bundles_n' => '0',
      'hr_bundles_cccm' => '0',
      'hr_bundles_et' => '0',
      'hr_bundles_p' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'hr_bundles_geojson' => '0',
      'hr_operations_geojson' => '0',
      'hr_users_geojson' => '0',
      'postgis_formatter_layer' => '0',
      'hr_users_map_data' => 'hr_default',
    ),
    'layer_styles_select' => array(
      'hr_bundles_er' => '0',
      'hr_bundles_education' => '0',
      'hr_bundles_es' => '0',
      'hr_bundles_wash' => '0',
      'hr_bundles_h' => '0',
      'hr_bundles_fs' => '0',
      'hr_bundles_l' => '0',
      'hr_bundles_n' => '0',
      'hr_bundles_cccm' => '0',
      'hr_bundles_et' => '0',
      'hr_bundles_p' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'hr_bundles_geojson' => '0',
      'hr_operations_geojson' => '0',
      'hr_users_geojson' => '0',
      'postgis_formatter_layer' => '0',
      'hr_users_map_data' => 'hr_default',
    ),
    'layer_styles_temporary' => array(
      'hr_bundles_er' => '0',
      'hr_bundles_education' => '0',
      'hr_bundles_es' => '0',
      'hr_bundles_wash' => '0',
      'hr_bundles_h' => '0',
      'hr_bundles_fs' => '0',
      'hr_bundles_l' => '0',
      'hr_bundles_n' => '0',
      'hr_bundles_cccm' => '0',
      'hr_bundles_et' => '0',
      'hr_bundles_p' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'hr_bundles_geojson' => '0',
      'hr_operations_geojson' => '0',
      'hr_users_geojson' => '0',
      'postgis_formatter_layer' => '0',
      'hr_users_map_data' => 'hr_default',
    ),
    'layer_activated' => array(
      'hr_users_map_data' => 'hr_users_map_data',
      'hr_bundles_er' => 0,
      'hr_bundles_education' => 0,
      'hr_bundles_es' => 0,
      'hr_bundles_wash' => 0,
      'hr_bundles_h' => 0,
      'hr_bundles_fs' => 0,
      'hr_bundles_l' => 0,
      'hr_bundles_n' => 0,
      'hr_bundles_cccm' => 0,
      'hr_bundles_et' => 0,
      'hr_bundles_p' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'hr_bundles_geojson' => 0,
      'hr_operations_geojson' => 0,
      'hr_users_geojson' => 0,
      'postgis_formatter_layer' => 0,
    ),
    'layer_switcher' => array(
      'hr_users_map_data' => 0,
      'hr_bundles_er' => 0,
      'hr_bundles_education' => 0,
      'hr_bundles_es' => 0,
      'hr_bundles_wash' => 0,
      'hr_bundles_h' => 0,
      'hr_bundles_fs' => 0,
      'hr_bundles_l' => 0,
      'hr_bundles_n' => 0,
      'hr_bundles_cccm' => 0,
      'hr_bundles_et' => 0,
      'hr_bundles_p' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'hr_bundles_geojson' => 0,
      'hr_operations_geojson' => 0,
      'hr_users_geojson' => 0,
      'postgis_formatter_layer' => 0,
    ),
    'projection' => 'EPSG:3857',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'hr_default',
      'select' => 'hr_default',
      'temporary' => 'hr_default',
    ),
  );
  $export['hr_people'] = $openlayers_maps;

  return $export;
}

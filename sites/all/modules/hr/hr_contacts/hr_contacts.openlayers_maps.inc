<?php
/**
 * @file
 * hr_contacts.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function hr_contacts_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'hr_contacts';
  $openlayers_maps->title = 'Contacts';
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
          'hr_contacts_map_data' => 'hr_contacts_map_data',
        ),
        'panMapIfOutOfView' => 0,
        'keepInMap' => 1,
      ),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => array(
          'hr_contacts_map_data' => 'hr_contacts_map_data',
          'mapbox_world_bright' => 0,
          'mapbox_world_dark' => 0,
          'mapbox_world_light' => 0,
          'mapbox_world_print' => 0,
          'mapbox_world_black' => 0,
        ),
        'point_zoom_level' => '5',
        'zoomtolayer_scale' => '1',
      ),
      'openlayers_behavior_cluster' => array(
        'clusterlayer' => array(
          'hr_contacts_map_data' => 'hr_contacts_map_data',
        ),
        'distance' => '20',
        'threshold' => '',
        'display_cluster_numbers' => 1,
        'middle_lower_bound' => '15',
        'middle_upper_bound' => '50',
        'low_color' => '#DAACB1',
        'middle_color' => '#C8727B',
        'high_color' => '#B11121',
      ),
    ),
    'default_layer' => 'mapbox_world_bright',
    'layers' => array(
      'mapbox_world_bright' => 'mapbox_world_bright',
      'mapbox_world_dark' => 'mapbox_world_dark',
      'mapbox_world_light' => 'mapbox_world_light',
      'mapbox_world_print' => 'mapbox_world_print',
      'mapbox_world_black' => 'mapbox_world_black',
      'hr_contacts_map_data' => 'hr_contacts_map_data',
    ),
    'layer_weight' => array(
      'openlayers_geojson_picture_this' => '0',
      'openlayers_kml_example' => '0',
      'geofield_formatter' => '0',
      'hr_operations_geojson' => '0',
      'hr_users_map_data' => '0',
      'hr_contacts_map_data' => '0',
      'postgis_formatter_layer' => '0',
      'hr_bundles_geojson' => '0',
      'hr_bundles_p' => '0',
      'hr_bundles_et' => '0',
      'hr_bundles_wash' => '0',
      'hr_bundles_es' => '0',
      'hr_bundles_education' => '0',
      'hr_bundles_h' => '0',
      'hr_bundles_fs' => '0',
      'hr_bundles_cccm' => '0',
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
      'geofield_formatter' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'hr_operations_geojson' => '0',
      'hr_users_map_data' => 'hr_default',
      'hr_bundles_geojson' => '0',
      'postgis_formatter_layer' => '0',
      'hr_contacts_map_data' => 'hr_default',
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
      'geofield_formatter' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'hr_operations_geojson' => '0',
      'hr_users_map_data' => 'hr_default',
      'hr_bundles_geojson' => '0',
      'postgis_formatter_layer' => '0',
      'hr_contacts_map_data' => 'hr_default',
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
      'geofield_formatter' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'hr_operations_geojson' => '0',
      'hr_users_map_data' => 'hr_default',
      'hr_bundles_geojson' => '0',
      'postgis_formatter_layer' => '0',
      'hr_contacts_map_data' => 'hr_default',
    ),
    'layer_activated' => array(
      'hr_contacts_map_data' => 'hr_contacts_map_data',
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
      'geofield_formatter' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'hr_operations_geojson' => 0,
      'hr_users_map_data' => 0,
      'hr_bundles_geojson' => 0,
      'postgis_formatter_layer' => 0,
    ),
    'layer_switcher' => array(
      'hr_contacts_map_data' => 0,
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
      'geofield_formatter' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'hr_operations_geojson' => 0,
      'hr_users_map_data' => 0,
      'hr_bundles_geojson' => 0,
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
  $export['hr_contacts'] = $openlayers_maps;

  return $export;
}

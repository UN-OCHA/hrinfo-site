<?php

/**
 * @file
 * hr_core.openlayers_styles.inc
 */

/**
 * Implements hook_openlayers_styles().
 */
function hr_core_openlayers_styles() {
  $export = array();

  $openlayers_styles = new stdClass();
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'hr_default';
  $openlayers_styles->title = 'Humanitarianresponse Default';
  $openlayers_styles->description = 'Humanitarianresponse Default Style';
  $openlayers_styles->data = array(
    'fillColor' => '#BC2E3C',
    'fillOpacity' => 0.75,
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
    'pointRadius' => 6,
    'strokeColor' => '#FFFFFF',
    'strokeDashstyle' => 'solid',
    'strokeLinecap' => 'round',
    'strokeOpacity' => 1,
    'strokeWidth' => 1,
  );
  $export['hr_default'] = $openlayers_styles;

  return $export;
}

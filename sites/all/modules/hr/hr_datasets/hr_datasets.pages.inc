<?php

function hr_datasets_hdx_datasets($operation){
  $templates = array(
  	'hdx_datasets_list_view',
  );
  drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/underscore.js/1.8.2/underscore-min.js', array('type' => 'external'));
  drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/backbone.js/1.1.2/backbone-min.js', array('type' => 'external'));
  foreach ($templates as $template) {
    hr_datasets_load_template($template, $template);
  }
 
  //TODO: use the country field under the operation to get the country name instead of using the operation title.
  $operation_title = $operation->title;

  include_once DRUPAL_ROOT . '/includes/locale.inc';
  $countries = country_get_list();

  $iso2code = array_search(strtolower($operation_title), array_map('strtolower', $countries));
  $iso3code = hr_datasets_iso2_to_iso3($iso2code);

  drupal_add_js(drupal_get_path('module', 'hr_datasets') . '/js/hr_datasets.js');
  drupal_add_js(array('hr_datasets' => array('operation' => $iso3code)), 'setting');

  $html = '<div id="datasets-view">
  </div>
  <div id="datasets-list">
    <table id="datasets-list-table" class="table table-striped">
      <thead>
      <tr>
        <th>Dataset Title</th>
        <th>Dataset Link</th>
      </tr>
      </thead>
      <tbody>
      </tbody>
    </table>
    <div class="text-center">
      <ul class="pagination">
        <li class="pager-previous"><a id="previous" href="">Previous</a></li>
        <li class="pager-next"> <a id="next" href="">Next</a></li>
      </ul>
    </div>
  </div>
  <div id="loading"><p class="text-center lead"><i class="fa fa-spinner fa-pulse"></i> Please wait. Data is loading...</p></div>';

  return $html;
}

// adopted from the hid_profiles module(github.com/humanitarianresponse/hid_profiles).

function hr_datasets_load_template($file, $id) {
  $template =  DRUPAL_ROOT . '/' . drupal_get_path('module', 'hr_datasets') . '/templates/'.$file.'.html';
  $template = file_get_contents($template);
  $template_elt = array(
    '#tag' => 'script',
    '#attributes' => array(
      'type' => 'text/template',
      'id' => $id,
    ),
    '#value' => $template,
  );
  drupal_add_html_head($template_elt, 'hr_datasets_'.$file);
}

/**
* Function to get iso3 country code from an iso2 code.
* @param $iso2_country_code
* @return iso3 code
*/

function hr_datasets_iso2_to_iso3($iso2_country_code) {
  $codes_url = 'http://country.io/iso3.json';
  $codes = drupal_http_request($codes_url);
  if(isset($codes->data)) {
    $response = drupal_json_decode($codes->data);
    if(isset($response[$iso2_country_code])) {
      return strtolower($response[$iso2_country_code]);
    }
  }
  else {
    drupal_set_message(t('Could not reach the countries list on country.io, please consult the site admin.'), 'warning', false);
  }
}



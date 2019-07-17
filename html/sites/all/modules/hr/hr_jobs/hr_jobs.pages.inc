<?php

function hr_jobs_reliefweb_jobs($operation){
  $templates = array(
  	'jobs_list_view',
  );
  drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/underscore.js/1.8.2/underscore-min.js', array('type' => 'external'));
  drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/backbone.js/1.1.2/backbone-min.js', array('type' => 'external'));
  foreach ($templates as $template) {
    hr_jobs_load_template($template, $template);
  }

  drupal_add_js(drupal_get_path('module', 'hr_jobs') . '/js/hr_jobs.js');
  drupal_add_js(array('hr_jobs' => array('operation' => $operation->title)), 'setting');

  $html = '<div id="jobs-view">
  </div>
  <div id="jobs-list">
    <table id="jobs-list-table" class="table table-striped">
      <thead>
      <tr>
        <th>Job Title</th>
        <th>Job Link</th>
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

function hr_jobs_load_template($file, $id) {
  $template =  DRUPAL_ROOT . '/' . drupal_get_path('module', 'hr_jobs') . '/templates/'.$file.'.html';
  $template = file_get_contents($template);
  $template_elt = array(
    '#tag' => 'script',
    '#attributes' => array(
      'type' => 'text/template',
      'id' => $id,
    ),
    '#value' => $template,
  );
  drupal_add_html_head($template_elt, 'hr_jobs_'.$file);
}
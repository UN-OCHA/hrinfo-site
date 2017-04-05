<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('OCHA products'),
  'description' => t('OCHA products block.'),
  'category' => t('Documents'),
  'edit form' => 'hr_reliefweb_ocha_products_edit_form',
  'render callback' => 'hr_reliefweb_ocha_products_render',
  'defaults' => array(
    'hno_id' => '',
    'srp_id' => '',
    'monr_id' => '',
    'opr_id' => '',
    'orp_id' => '',
    'hno_title' => '',
    'srp_title' => '',
    'monr_title' => '',
    'opr_title' => '',
    'orp_title' => '',
    'show_sitrep' => TRUE,
    'show_humbul' => TRUE,
    'show_humsnap' => TRUE,
    'show_humdash' => TRUE,
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function hr_reliefweb_ocha_products_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['response_planning'] = array(
    '#type' => 'fieldset',
    '#title' => t('Response planning'),
  );

  $form['response_planning']['hno_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Humanitarian Needs Overview'),
    '#default_value' => $conf['hno_title'],
    '#autocomplete_path' => 'reliefweb/hno/autocomplete',
    '#maxlength' => 512,
  );

  $form['response_planning']['srp_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Strategic Response Plan'),
    '#default_value' => $conf['srp_title'],
    '#autocomplete_path' => 'reliefweb/srp/autocomplete',
    '#maxlength' => 512,
  );

  $form['response_planning']['monr_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Periodic Monitoring Report'),
    '#default_value' => $conf['monr_title'],
    '#autocomplete_path' => 'reliefweb/monr/autocomplete',
    '#maxlength' => 512,
  );

  $form['response_planning']['opr_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Operational Peer Review Summary'),
    '#default_value' => $conf['opr_title'],
    '#autocomplete_path' => 'reliefweb/opr/autocomplete',
    '#maxlength' => 512,
  );

  $form['response_planning']['orp_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Response plan'),
    '#default_value' => $conf['orp_title'],
    '#autocomplete_path' => 'reliefweb/orp/autocomplete',
    '#maxlength' => 512,
  );

  $form['ocha_products'] = array(
    '#type' => 'fieldset',
    '#title' => t('OCHA Products'),
  );

  $form['ocha_products']['show_sitrep'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the latest sitrep'),
    '#default_value' => $conf['show_sitrep'],
  );

  $form['ocha_products']['show_humbul'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the latest humanitarian bulletin'),
    '#default_value' => $conf['show_humbul'],
  );

  $form['ocha_products']['show_humsnap'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the latest humanitarian snapshot'),
    '#default_value' => $conf['show_humsnap'],
  );

  $form['ocha_products']['show_humdash'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the latest humanitarian dashboard'),
    '#default_value' => $conf['show_humdash'],
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function hr_reliefweb_ocha_products_edit_form_submit($form, &$form_state) {
  foreach (array('hno', 'srp', 'monr', 'opr', 'orp') as $base) {
    if (preg_match("/\s\((\d+)\)$/", $form_state['values'][$base . '_title'], $matches)) {
      $form_state['conf'][$base . '_title'] = $form_state['values'][$base . '_title'];
      $form_state['conf'][$base . '_id'] = $matches[1];
    }
  }

  $form_state['rebuild'] = TRUE;
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hr_reliefweb_ocha_products_render($subtype, $conf, $panel_args, $context = NULL) {
  // initial content is blank
  $block = new stdClass();
  $block->title = 'OCHA products';
  $block->content = '';

  // Override title.
  if ($conf['override_title']) {
    $block->title = $conf['override_title_text'];
  }

  $path = current_path() . '/reliefweb';
  $ocha_reports = hr_reliefweb_get_ocha_reports();

  // Response planning.
  $nodes = array();
  foreach (array('hno_id', 'srp_id', 'monr_id', 'opr_id', 'orp_id') as $hpc_key) {
    if (!empty($conf[$hpc_key])) {
      $data = hr_reliefweb_get_document_by_id($conf[$hpc_key]);
      $nodes[$hpc_key] = $data;
    }
  }

  uasort($nodes, '_hr_reliefweb_sort_hpc');

  $i = 0;
  foreach ($nodes as $key => $node) {
    $initial_state = 'hidden';
    if ($i == 0) {
      $initial_state = 'show';
      $i++;
    }
    $see_more_path = $path;
    $hpc[$key] = _hr_reliefweb_get_list_item($node, $node['title'], $key, $initial_state, $see_more_path, t('See more HPC documents'));
  }

  $hpc_images = '';
  $hpc_links = '';
  foreach ($hpc as $hpc_doc) {
    if (isset($hpc_doc['image'])) {
      $hpc_images .= $hpc_doc['image'];
    }
    if (isset($hpc_doc['link'])) {
      $hpc_links .= $hpc_doc['link'];
    }
  }

  // OCHA Reports.
  $ocha_images = '';
  $ocha_links = '';
  $i = 0;
  foreach ($ocha_reports as $key => $ocha_report) {
    if (isset($conf['show_' . $key]) && $conf['show_' . $key] == TRUE || !isset($conf['show_' . $key])) {
      $initial_state = 'hidden';
      if ($i == 0) {
        $initial_state = 'show';
      }
      $data = hr_reliefweb_get_latest_document_by_key($key);
      if ($data) {
        $see_more_path = $path . '/' . $ocha_report['field'] . '/' . $ocha_report['value'];
        $ocha_products[$key] = _hr_reliefweb_get_list_item($data, $ocha_report['label'], $key, $initial_state, $see_more_path, t('See more @term', array('@term' => $ocha_report['label'] . 's')));
        if (isset($ocha_products[$key]['image'])) {
          $ocha_images .= $ocha_products[$key]['image'];
        }
        if (isset($ocha_products[$key]['link'])) {
          $ocha_links .= $ocha_products[$key]['link'];
        }
        $i++;
      }
    }
  }

  $block->content = '<div class="clearfix hr-layout-operation-standard">
  <ul class="nav nav-tabs" role="tablist">';
  if (!empty($hpc)) {
    $block->content .= '<li class="active"><a href="#hpc" role="tab" data-toggle="tab">' . t('Response Planning') . '</a></li>';
    $block->content .= '<li>';
  }
  else {
    $block->content .= '<li class="active">';
  }
  $block->content .= '<a href="#ocha" role="tab" data-toggle="tab">' . t('OCHA Products') . '</a></li>
  </ul>

  <div class="tab-content">';
  if (!empty($hpc)) {
    $block->content .= '<div class="tab-pane active" id="hpc">
      <div class="row">
        <div class="col-xs-4">' . $hpc_images . '</div>
        <div class="col-xs-8 hr-layout-operation-standard-links">
          <div class="list-group">' . $hpc_links . '</div>
        </div>
      </div>
    </div>
    <div class="tab-pane" id="ocha">';
  }
  else {
    $block->content .= '<div class="tab-pane active" id="ocha">';
  }
  $block->content .= '<div class="col-xs-4">' . $ocha_images . '</div>
      <div class="col-xs-8 hr-layout-operation-standard-links">
        <div class="list-group">' . $ocha_links . '</div>
      </div>
    </div>
  </div>
  </div>

  <script type="text/javascript">
    (function($) {
      $(".hr-layout-operation-standard-links a").hover(
        function () {
          $(".hr-layout-operation-standard .tab-pane:visible a").removeClass("active");
          $(".hr-layout-operation-standard .tab-pane:visible .hr-thumbnail").removeClass("show");
          $(".hr-layout-operation-standard .tab-pane:visible .hr-thumbnail").addClass("hidden");
          $( this ).addClass("active");
          var selector = "#" + $( this ).attr("id") + "-thumbnail";
          $(selector).removeClass("hidden");
          $(selector).addClass("show");
        },
        function() { });
    })(jQuery);
  </script>';
  return $block;
}

/**
 * Creates the full list-item by calling the helper functions
 */
function _hr_reliefweb_get_list_item($value, $label, $prefix, $initial_state = 'hidden', $see_more_link = '', $see_more_title = '') {
  $out = array();

  $file = reset($value['files']);
  if (isset($file['preview']) && !empty($file['preview'])) {
    $img_link = '<a class="hr-thumbnail-image" target="reliefweb" title="' . $file['description'] .'" href = ' . $file['url'] . '>' . theme('image', array('path' => $file['preview'])) . '<span class="hr-thumbnail-text">' .t('Download') . '</span></a>';
  }
  elseif (!empty($file['url'])) {
    $img_link = '<a class="hr-thumbnail-no-image" target="reliefweb" title="' . $file['description'] .'" href = ' . $file['url'] . '>' . t('Download !file', array('!file' => $file['filename'])) . '</a>';
  }
  else {
    $img_link = '<div class="hr-thumbnail-no-download">No download available</div>';
  }

  $more_link = '';
  if (!empty($see_more_link)) {
    $more_link = l($see_more_title, $see_more_link, array('attributes' => array('class' => 'hr-layout-see-more')));
  }
  $img_link = '<div id="' . $prefix . '-thumbnail" class="hr-thumbnail ' . $initial_state . '">' . $img_link . $more_link . '</div>';
  $date_string = '';
  if (!empty($node->field_publication_date)) {
    $date = new DateObject($node->field_publication_date[LANGUAGE_NONE][0]['value'], $node->field_publication_date[LANGUAGE_NONE][0]['timezone_db']);
    $date_string = ' - '.date_format_date($date, 'custom', 'd M Y');
    $out['date'] = $node->field_publication_date[LANGUAGE_NONE][0]['value'];
  }
  $active_link = '';
  if ($initial_state == 'show') {
    $active_link = 'active';
  }
  $link = '<a target="reliefweb" href="' . $value['url'] . '" class="list-group-item ' . $active_link . '" id="' . $prefix . '">' . $label . ' - ' . format_date(strtotime($value['date_changed']), 'custom', 'd F Y') . '</a>';
  $out['image'] = $img_link;
  $out['link'] = $link;

  return $out;
}

/**
 * Helper function to sort docs by date
 */
function _hr_reliefweb_sort_hpc($a, $b) {
  $atime = strtotime($a['date_changed']);
  $btime = strtotime($b['date_changed']);
  if ($atime == $btime) {
    return 0;
  }
  return ($atime < $btime) ? 1 : -1;
}

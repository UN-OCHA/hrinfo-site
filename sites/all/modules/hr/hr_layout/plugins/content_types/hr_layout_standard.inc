<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Standard Products'),
  'description' => t('Shows a standard block for your operation home page.'),
  'category' => t('Humanitarianresponse'),
  'edit form' => 'hr_layout_standard_edit_form',
  'render callback' => 'hr_layout_standard_render',
  'defaults' => array(
    'gid' => '',
    'hno' => '',
    'srp' => '',
    'monr' => '',
    'opr' => '',
    'orp' => '',
    'show_sitrep' => TRUE,
    'show_humbul' => TRUE,
    'show_humsnap' => TRUE,
    'show_humdash' => TRUE,
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function hr_layout_standard_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['gid'] = array(
    '#type' => 'entityreference',
    '#title' => t('Operation'),
    '#era_entity_type' => 'node',
    '#era_bundles' => array('hr_operation'),
    '#default_value' => $conf['gid'],
    '#required' => TRUE,
  );

  $form['response_planning'] = array(
    '#type' => 'fieldset',
    '#title' => t('Response planning'),
  );

  $form['response_planning']['hno'] = array(
    '#type' => 'entityreference',
    '#title' => t('Humanitarian Needs Overview'),
    '#era_entity_type' => 'node',
    '#era_bundles' => array('hr_document'),
    '#default_value' => $conf['hno'],
  );

  $form['response_planning']['srp'] = array(
    '#type' => 'entityreference',
    '#title' => t('Strategic Response Plan'),
    '#era_entity_type' => 'node',
    '#era_bundles' => array('hr_document'),
    '#default_value' => $conf['srp'],
  );

  $form['response_planning']['monr'] = array(
    '#type' => 'entityreference',
    '#title' => t('Periodic Monitoring Report'),
    '#era_entity_type' => 'node',
    '#era_bundles' => array('hr_document'),
    '#default_value' => $conf['monr'],
  );

  $form['response_planning']['opr'] = array(
    '#type' => 'entityreference',
    '#title' => t('Operational Peer Review Summary'),
    '#era_entity_type' => 'node',
    '#era_bundles' => array('hr_document'),
    '#default_value' => $conf['opr'],
  );

  $form['response_planning']['orp'] = array(
    '#type' => 'entityreference',
    '#title' => t('Other Response plan'),
    '#era_entity_type' => 'node',
    '#era_bundles' => array('hr_document'),
    '#default_value' => $conf['orp'],
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
function hr_layout_standard_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hr_layout_standard_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $gid = $conf['gid']['entity_id'];

  // Get OCHA tid
  $ocha_org = array_keys(taxonomy_get_term_by_name('United Nations Office for the Coordination of Humanitarian Affairs', 'hr_organization'));
  $ocha_org_id = reset($ocha_org);

  $ocha_desc = array(
    'sitrep' => array('term' => 'Situation Report', 'type' => 'hr_document', 'see_more' => 'node/'.$gid.'/documents/document-type/situation-report'),
    'humbul' => array('term' => 'Humanitarian Bulletin', 'type' => 'hr_document', 'see_more' => 'node/'.$gid.'/documents/document-type/humanitarian-bulletin'),
    'humsnap' => array('term' => 'Humanitarian Snapshot', 'type' => 'hr_infographic', 'see_more' => 'node/'.$gid.'/infographics/infographic-type/humanitarian-snapshot'),
    'humdash' => array('term' => 'Humanitarian Dashboard', 'type' => 'hr_infographic', 'see_more' => 'node/'.$gid.'/infographics/infographic-type/humanitarian-dashboard'),
  );

  $ocha_products = array();
  $ocha_images = '';
  $ocha_links = '';
  $i = 0;
  foreach ($ocha_desc as $key => $value) {
    if (isset($conf['show_'.$key]) && $conf['show_'.$key] == TRUE || !isset($conf['show_'.$key])) {
      $initial_state = 'hidden';
      if ($i == 0) {
        $initial_state = 'show';
      }
      $node = _hr_layout_get_latest($gid, $value['term'], $value['type'], $ocha_org_id);
      if ($node) {
        $ocha_products[$key] = _hr_layout_get_list_item($node, $value['term'], $value['type'], $key, $initial_state, $value['see_more'], t('See more @term', array('@term' => $value['term'].'s')));
        $ocha_images .= $ocha_products[$key]['image'];
        $ocha_links .= $ocha_products[$key]['link'];
        $i++;
      }
    }
  }

  $hpc_keys = array(
    'hno' => array('term' => 'Humanitarian Needs Overview', 'see_more' => 'node/'.$gid.'/documents/document-type/humanitarian-programme-cycle'),
    'srp' => array('term' => 'Strategic Response Plan', 'see_more' => 'node/'.$gid.'/documents/document-type/humanitarian-programme-cycle'),
    'monr' => array('term' => 'Periodic Monitoring Report', 'see_more' => 'node/'.$gid.'/documents/document-type/humanitarian-programme-cycle'),
    'opr' => array('term' => 'Operational Peer Review Summary', 'see_more' => 'node/'.$gid.'/documents/document-type/humanitarian-programme-cycle'),
    'orp' => array('term' => 'Other Response Plan', 'see_more' => 'node/'.$gid.'/documents/document-type/other-response-plans'),
  );

  $nodes = array();
  foreach ($hpc_keys as $hpc_key => $hpc_row) {
    if (!empty($conf[$hpc_key])) {
      $node_tmp = node_load($conf[$hpc_key]['entity_id']);
      if ($node_tmp != FALSE) {
        $nodes[$hpc_key] = $node_tmp;
      }
    }
  }

  uasort($nodes, '_hr_layout_sort_hpc');

  $i = 0;
  foreach ($nodes as $key => $node) {
    $initial_state = 'hidden';
    if ($i == 0) {
      $initial_state = 'show';
      $i++;
    }
    $entity = entity_load_single('node', $node->nid);
    $term = entity_label('node', $entity);
    $hpc[$key] = _hr_layout_get_list_item($node, $term, 'hr_document', $key, $initial_state, $hpc_keys[$key]['see_more'], t('See more HPC documents'));
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


  // initial content is blank
  $block->title = '';
  $block->content = '';

  $block->content = '<div class="clearfix hr-layout-operation-standard">
  <ul class="nav nav-tabs" role="tablist">';
  if (!empty($hpc)) {
    $block->content .= '<li class="active"><a href="#hpc" role="tab" data-toggle="tab">'.t('Response Planning').'</a></li>';
    $block->content .= '<li>';
  }
  else {
    $block->content .= '<li class="active">';
  }
  $block->content .= '<a href="#ocha" role="tab" data-toggle="tab">'.t('OCHA Products').'</a></li>
  </ul>

  <!-- Tab panes -->
  <div class="tab-content">';
  if (!empty($hpc)) {
    $block->content .= '<div class="tab-pane active" id="hpc">
      <div class="row">
        <div class="col-xs-4">'.$hpc_images.'</div>
        <div class="col-xs-8 hr-layout-operation-standard-links">
          <div class="list-group">'.$hpc_links.'</div>
        </div>
      </div>
    </div>
    <div class="tab-pane" id="ocha">';
  }
  else {
    $block->content .= '<div class="tab-pane active" id="ocha">';
  }
  $block->content .= '<div class="col-xs-4">'.$ocha_images.'</div>
      <div class="col-xs-8 hr-layout-operation-standard-links">
        <div class="list-group">'.$ocha_links.'</div>
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
 * Helper function to sort hpc docs by date
 * See http://atrium.humanitarianresponse.info/humanitarian_response/node/4541
 */
function _hr_layout_sort_hpc($a, $b) {
  $atime = strtotime($a->field_publication_date[LANGUAGE_NONE][0]['value']);
  $btime = strtotime($b->field_publication_date[LANGUAGE_NONE][0]['value']);
  if ($atime == $btime) {
    return 0;
  }
  return ($atime < $btime) ? 1 : -1;
}


/**
 * Helper function to retrieve latest document/infographic of a specific doc type
 */
function _hr_layout_get_latest($gid, $term, $type, $org_id = NULL) {
  // Get term ID
  $terms = taxonomy_get_term_by_name($term, $type.'_type');
  $term = reset($terms);
  if ($term) {
    $field_type = 'field_document_type';
    if ($type == 'hr_infographic') {
      $field_type = 'field_infographic_type';
    }
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $type)
      ->fieldCondition($field_type, 'target_id', $term->tid, '=')
      ->fieldCondition(OG_AUDIENCE_FIELD, 'target_id', $gid, '=');
    if (!empty($org_id)) {
      $org_ids = array($org_id);
      $query->fieldCondition('field_organizations', 'target_id', $org_ids, 'IN');
    }
    $query->fieldOrderBy('field_publication_date', 'value', 'DESC')
      ->range(0, 1);

    $result = $query->execute();
    if (isset($result['node'])) {
      $node = reset($result['node']);
      return node_load($node->nid);
    }
  }
}

/**
 * Retrieves link to the file image based on the node object
 */
function _hr_layout_get_pdfpreview($node) {
  $fcid = $node->field_files_collection[LANGUAGE_NONE][0]['value'];
  $entity = entity_load_single('field_collection_item', $fcid);
  $file = $entity->field_file[LANGUAGE_NONE][0];
  $file_uri = '';
  if ($file['filemime'] == 'application/pdf') {
    $file_uri = _pdfpreview_create_preview($file);
  }
  else {
    $icon_dir = variable_get('media_icon_base_directory', 'public://media-icons') . '/' . variable_get('media_icon_set', 'default');
    $file_uri = file_icon_path($file, $icon_dir);
  }
  return $file_uri;
}

/**
 * Creates the full list-item by calling the helper functions
 */
function _hr_layout_get_list_item($node, $term, $type, $prefix, $initial_state = 'hidden', $see_more_link = '', $see_more_title = '') {
  $out = array();
  $file = _hr_layout_get_pdfpreview($node);
  if ($file) {
    $image = theme_image_style(array('style_name' => 'medium', 'path' => $file, 'alt' => $node->title, 'title' => $node->title, 'attributes' => array('class' => array('img-responsive')), 'width' => NULL, 'height' => NULL));
    $img_link = l($image, 'node/'.$node->nid, array('html' => TRUE));
    $more_link = '';
    if (!empty($see_more_link)) {
      $more_link = l($see_more_title, $see_more_link, array('attributes' => array('class' => 'hr-layout-see-more')));
    }
    $img_link = '<div id="'.$prefix.'-thumbnail" class="hr-thumbnail '.$initial_state.'">'.$img_link.$more_link.'</div>';
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
    $link = '<a class="list-group-item '.$active_link.'" id="'.$prefix.'">'.t($term).$date_string.'</a>';
    $out['image'] = $img_link;
    $out['link'] = $link;
  }
  return $out;
}

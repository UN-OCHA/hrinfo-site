<?php
/**
 * @file
 * Theme functions
 */

require_once dirname(__FILE__) . '/includes/structure.inc';
require_once dirname(__FILE__) . '/includes/comment.inc';
require_once dirname(__FILE__) . '/includes/form.inc';
require_once dirname(__FILE__) . '/includes/menu.inc';
require_once dirname(__FILE__) . '/includes/node.inc';
require_once dirname(__FILE__) . '/includes/panel.inc';
require_once dirname(__FILE__) . '/includes/user.inc';
require_once dirname(__FILE__) . '/includes/view.inc';

/**
 * Implements hook_css_alter().
 */
function humanitarianresponse_css_alter(&$css) {
  $radix_path = drupal_get_path('theme', 'radix');

  // Radix now includes compiled stylesheets for demo purposes.
  // We remove these from our subtheme since they are already included 
  // in compass_radix.
  unset($css[$radix_path . '/assets/stylesheets/radix-style.css']);
  unset($css[$radix_path . '/assets/stylesheets/radix-print.css']);
}

/**
 * Implements template_preprocess_page().
 */
function humanitarianresponse_preprocess_page(&$variables) {
  global $theme_path;
  $tree = menu_tree_page_data('main-menu', 1);
  $main_menu_dropdown = menu_tree_output($tree);
  $main_menu_dropdown['#theme_wrappers'] = array();
  $variables['main_menu_dropdown'] = $main_menu_dropdown;
  $variables['hr_tabs'] = array();
  $header_img_path = $theme_path.'/assets/images/headers/general.png';
  if (module_exists('og_context')) {
    $gid = og_context_determine_context('node');
    if (!empty($gid)) {
        $og_group = entity_load('node', array($gid));
        $og_group = $og_group[$gid];
        if ($og_group->type == 'hr_operation') {
          // Salahumanitaria logo
          if ($og_group->nid == 77) { // Nid of the Colombia operation
            $variables['logo'] = '/sites/all/themes/humanitarianresponse/assets/images/salahumanitaria_logo.png';
          }
          if (!empty($og_group->field_operation_type) && !empty($og_group->field_operation_region) && $og_group->field_operation_type[LANGUAGE_NONE][0]['value'] == 'country') {
            // Determine the region of the operation
            $region_id = $og_group->field_operation_region[LANGUAGE_NONE][0]['target_id'];
            $region = entity_load_single('node', $region_id);
            $region_uri = entity_uri('node', $region);
            $region_status = $region->field_operation_status[LANGUAGE_NONE][0]['value'];
            switch ($region_status) {
              case 'active':
                // Add the region to the tabs
                $variables['hr_tabs'][] = l($region->title, $region_uri['path'], $region_uri['options']);
                break;
              case 'inactive':
                break;
              case 'archived':
                break;
            }
          }
        }
        elseif ($og_group->type == 'hr_disaster') {
          $glide = $og_group->field_glide_number[LANGUAGE_NONE][0]['value'];
          if ($glide == 'EP-2014-000041-GIN') {
            $variables['logo'] = '/sites/all/themes/humanitarianresponse/assets/images/unmeer_logo.png';
          }
        }
        elseif ($og_group->type == 'hr_bundle') {
          // Get operation from bundle
          $op_gid = _hr_bundles_get_operation($og_group->nid);
          if (!empty($op_gid)) {
            $operation = entity_load_single('node', $op_gid);
            $op_uri = entity_uri('node', $operation);
            $variables['hr_tabs'][] = l($operation->title, $op_uri['path'], $op_uri['options']);
          }
        }
        $uri = entity_uri('node', $og_group);
        if ($og_group->status) { // Group is published
          $variables['hr_tabs'][] = l($og_group->title, $uri['path'], $uri['options']);
        }
        else {
          $variables['hr_tabs'][] = '<a href="#">'.$og_group->title.'</a>';
        }
        $group_img_path = '/assets/images/headers/'.$og_group->type.'/'.strtolower(str_replace(array(' ','/'), '-', $og_group->title)).'.png';
        if (file_exists(dirname(__FILE__).$group_img_path)) {
          $header_img_path = $theme_path.$group_img_path;
        }
      }
  }

  $variables['og_group_header_image'] = theme('image', array(
    'path' => $header_img_path,
    'alt' => 'Header image',
  ));

  if (user_is_anonymous()) {
    $variables['follow_us_link_href'] = 'user/login';
    $variables['follow_us_link_title'] = t('Login to follow us');
    $variables['follow_us_link_status'] = 'flag';
  }
  else {
    $temp = _humanitarianresponse_flag_follow_us();
    $variables['follow_us_link_href'] = $temp['link_href'];
    $variables['follow_us_link_title'] = $temp['link_title'];
    $variables['follow_us_link_status'] = $temp['link_status'];
  }

  $variables['hr_favorite_spaces'] = _humanitarianresponse_block_render('hr_bookmarks', 'hr_favorite_spaces');
}

/**
 * Implements template_preprocess_html().
 */
function humanitarianresponse_preprocess_html(&$variables) {
  if ($node = menu_get_object()) {
    if (og_is_group('node', $node->nid)) {
      $variables['classes_array'][] = 'hr-group-context';
    }
  }
}

function _humanitarianresponse_flag_follow_us() {
  global $user;
  // Some typing shotcuts:
  $flag = flag_get_flag('hr_follow');
  $entity_id = 2490; // Hardcoded nid of the "About" space
  $action = $flag->is_flagged($entity_id) ? 'unflag' : 'flag';

  // Generate the link URL.
  $link_type = $flag->get_link_type();
  $link = module_invoke($link_type['module'], 'flag_link', $flag, $action, $entity_id);
  if (isset($link['title']) && empty($link['html'])) {
    $link['title'] = check_plain($link['title']);
  }

  // Replace the link with the access denied text if unable to flag.
  if ($action == 'unflag' && !$flag->access($entity_id, 'unflag')) {
    $link['title'] = $flag->get_label('unflag_denied_text', $entity_id);
    unset($link['href']);
  }

  // Anonymous users always need the JavaScript to maintain their flag state.
  if ($user->uid == 0) {
    $link_type['uses standard js'] = TRUE;
  }

  // Load the JavaScript/CSS, if the link type requires it.
  if (!isset($initialized[$link_type['name']])) {
    if ($link_type['uses standard css']) {
      drupal_add_css(drupal_get_path('module', 'flag') . '/theme/flag.css');
    }
    if ($link_type['uses standard js']) {
      drupal_add_js(drupal_get_path('module', 'flag') . '/theme/flag.js');
    }
    $initialized[$link_type['name']] = TRUE;
  }

  $vars['link_href'] = isset($link['href']) ? check_url(url($link['href'], $link)) : FALSE;
  $vars['link_title'] = ($action == 'flag' ? t('Follow Us') : t('Stop following us'));
  $vars['link_status'] = $action;
  return $vars;

}

/**
 * Custom function to render a block so I can manually position it in the markup
 */
function _humanitarianresponse_block_render($module, $block_id) {
  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));
  $build = _block_get_renderable_array($block_content);
  $block_rendered = drupal_render($build);
  return $block_rendered;
}

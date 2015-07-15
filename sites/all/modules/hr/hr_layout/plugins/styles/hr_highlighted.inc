<?php

// Plugin definition
$plugin = array(
  'title' => t('Highlighted'),
  'description' => t('Presents the panes or panels in Humanitarianresponse Highlighted style'),
  'render pane' => 'panels_hr_highlighted_style_render_pane',
);

/**
 * Render callback for a single pane.
 */
function theme_panels_hr_highlighted_style_render_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];

  if (empty($content->content)) {
    return;
  }

  return '<div class="hr-highlighted">'.theme('panels_pane', array('content' => $content, 'pane' => $pane, 'display' => $display)).'</div>';
}


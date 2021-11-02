<?php

/**
 * @file
 * hr_wysiwyg.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function hr_wysiwyg_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: hr_wysiwyg.
  $profiles['hr_wysiwyg'] = array(
    'format' => 'hr_wysiwyg',
    'editor' => 'ckeditor',
    'settings' => array(
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'JustifyLeft' => 1,
          'JustifyCenter' => 1,
          'JustifyRight' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'BidiLtr' => 1,
          'BidiRtl' => 1,
          'Unlink' => 1,
          'Source' => 1,
          'HorizontalRule' => 1,
          'Format' => 1,
          'FontSize' => 1,
          'Table' => 1,
          'Iframe' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'theme' => '',
      'language' => 'en',
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 1,
      'acf_mode' => 0,
      'acf_allowed_content' => '',
      'css_setting' => 'theme',
      'css_theme' => 'ocha_basic',
      'css_path' => '',
      'stylesSet' => 'Styled Image (right)=img.pull-right
Styled Image (left)=img.pull-left
Clearfix=p.clearfix',
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'forcePasteAsPlainText' => 1,
      'pasteFromWordPromptCleanup' => 0,
      'pasteFromWordRemoveFontStyles' => 0,
    ),
    'preferences' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'add_to_summaries' => 0,
      'version' => '4.16.2.4e64f67219',
    ),
    'name' => 'formathr_wysiwyg',
  );

  // Exported profile: panopoly_html_text.
  $profiles['panopoly_html_text'] = array(
    'format' => 'panopoly_html_text',
    'editor' => 'markitup',
    'settings' => array(
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'stroke' => 1,
          'link' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'h1,h2,h3,h4,h5,h6',
      'css_setting' => 'theme',
      'css_path' => '',
      'css_classes' => '',
    ),
    'preferences' => array(
      'add_to_summaries' => FALSE,
      'default' => 1,
      'show_toggle' => 0,
      'user_choose' => 0,
      'version' => '1.1.14',
    ),
    'name' => 'formatpanopoly_html_text',
  );

  return $profiles;
}

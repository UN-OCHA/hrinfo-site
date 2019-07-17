<?php
/**
 * @file
 *
 * Twitter Timeline Widgt Pane plugin.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Twitter Timeline Widget Pane'),
  'description' => t('Adds a configurable interface for the Twitter Timeline widget embed.'),
  'category' => t('Twitter'),
  'edit form' => 'twitter_pane_edit_form',
  'render callback' => 'twitter_pane_render',
  'defaults' => array(
    'widget_id' => '',
    'theme' => '',
    'link_color' => '',
    'width' => '',
    'height' => '',
    'chrome' => array(),
    'border_color' => '',
    'language' => '',
    'tweet_limit' => '',
    'related' => '',
    'polite' => array(),
  ),
);

/**
 * An edit form for the pane's settings.
 */
function twitter_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $conf += array(
    'widget_id' => '',
    'theme' => '',
    'link_color' => '',
    'width' => '',
    'height' => '',
    'chrome' => array(),
    'border_color' => '',
    'language' => '',
    'tweet_limit' => '',
    'related' => '',
    'polite' => array(),
  );

  $form['widget_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Widget ID'),
    '#default_value' => $conf['widget_id'],
    '#required' => TRUE,
    '#description' => t('Each Twitter Block block requires a unique widget ID which determines, among other things, the source (user timeline, favourites, list or search) of the tweets to display. You can view a list of your existing embedded timeline widgets (and their widget IDs) or create new embedded timeline widgets by visiting the <a href="@widgets_section">widgets section of your settings page</a> (make sure that you\'re logged in). You can determine a widget\'s ID by editing it and inspecting the URL (which should be in the form of twitter.com/settings/widgets/WIDGET_ID/edit) or by looking at the widget\'s embed code (look for data-widget-id="WIDGET_ID").', array('@widgets_section' => 'https://twitter.com/settings/widgets')),
  );
  $form['appearance'] = array(
    '#type' => 'fieldset',
    '#title' => t('Appearance'),
  );
  $form['appearance']['theme'] = array(
    '#type' => 'select',
    '#title' => t('Theme'),
    '#default_value' => $conf['theme'],
    '#options' => array(
      '' => t('Default'),
      'dark' => t('Dark'),
    ),
    '#description' => t('Select a theme for the widget.'),
  );
  $form['appearance']['link_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Link color'),
    '#default_value' => $conf['link_color'],
    '#maxlength' => 6,
    '#size' => 6,
    '#field_prefix' => '#',
    '#description' => t('Change the link color used by the widget. Takes an %format hex format color. Note that some icons in the widget will also appear this color.', array('%format' => 'abc123')),
  );
  $form['appearance']['border_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Border color'),
    '#default_value' => $conf['border_color'],
    '#maxlength' => 6,
    '#size' => 6,
    '#field_prefix' => '#',
    '#description' => t('Change the border color used by the widget. Takes an %format hex format color.', array('%format' => 'abc123')),
  );
  $form['appearance']['chrome'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Chrome'),
    '#default_value' => $conf['chrome'],
    '#options' => array(
      'noheader' => t('No header'),
      'nofooter' => t('No footer'),
      'noborders' => t('No borders'),
      'noscrollbar' => t('No scrollbar'),
      'transparent' => t('Transparent'),
    ),
    '#description' => t('Control the widget layout and chrome.'),
  );
  $form['functionality'] = array(
    '#type' => 'fieldset',
    '#title' => t('Functionality'),
  );
  $form['functionality']['related'] = array(
    '#type' => 'textfield',
    '#title' => t('Related users'),
    '#default_value' => $conf['related'],
    '#description' => t('As per the Tweet and follow buttons, you may provide a comma-separated list of user screen names as suggested followers to a user after they reply, Retweet, or favorite a Tweet in the timeline.'),
  );
  $form['functionality']['tweet_limit'] = array(
    '#type' => 'select',
    '#title' => t('Tweet limit'),
    '#default_value' => $conf['tweet_limit'],
    '#options' => array('' => t('Auto')) + drupal_map_assoc(range(1, 20)),
    '#description' => t('Fix the size of a timeline to a preset number of Tweets between 1 and 20. The timeline will render the specified number of Tweets from the timeline, expanding the height of the widget to display all Tweets without scrolling. Since the widget is of a fixed size, it will not poll for updates when using this option.'),
  );
  $form['size'] = array(
    '#type' => 'fieldset',
    '#title' => t('Size'),
    '#description' => t('Embedded timelines are flexible and adaptive, functioning at a variety of dimensions ranging from wide to narrow, and short to tall. The default dimensions for a timeline are 520×600px, which can be overridden to fit the dimension requirements of your page. Setting a width is not required, and by default the widget will shrink to the width of its parent element in the page.'),
  );
  $form['size']['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#default_value' => $conf['width'],
    '#size' => 6,
    '#field_suffix' => 'px',
    '#description' => t('Change the width of the widget.'),
  );
  $form['size']['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#default_value' => $conf['height'],
    '#size' => 6,
    '#field_suffix' => 'px',
    '#description' => t('Change the height of the widget.'),
  );
  $form['size']['note'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . t('The minimum width of a timeline is 180px and the maximum is 520px. The minimum height is 200px.') . '</p>',
  );
  $form['accessibility'] = array(
    '#type' => 'fieldset',
    '#title' => t('Accessibility'),
  );
  $form['accessibility']['language'] = array(
    '#type' => 'textfield',
    '#title' => t('Language'),
    '#default_value' => $conf['language'],
    '#maxlength' => 5,
    '#size' => 5,
    '#description' => t('The widget language is detected from the page, based on the language of your content. Enter a <a href="@website">language code</a> to manually override the language.', array('@website' => 'http://www.w3.org/TR/html401/struct/dirlang.html#h-8.1.1')),
  );
  $form['accessibility']['polite'] = array(
    '#type' => 'select',
    '#title' => t('ARIA politeness'),
    '#options' => array(
      'polite' => t('Polite'),
      'assertive' => t('Assertive'),
    ),
    '#default_value' => $conf['polite'],
    '#description' => t('ARIA is an accessibility system that aids people using assistive technology interacting with dynamic web content. <a href="@website">Read more about ARIA on W3C\'s website</a>. By default, the embedded timeline uses the least obtrusive setting: "polite". If you\'re using an embedded timeline as a primary source of content on your page, you may wish to override this to the assertive setting, using "assertive".', array('@website' => 'http://www.w3.org/WAI/intro/aria.php')),
  );

  return $form;
}

/**
 * Submit function for pane settings.
 */
function twitter_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  drupal_set_message(t('Twitter timeline widget pane has been saved.'));
}

/**
 * Render Comments widget.
 */
function twitter_pane_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $block->title = '';

  // Verify that we have a valid widget id.
  if (isset($conf['widget_id'])) {
    $block->content = array(
      '#theme' => 'link',
      '#text' => 'Tweets by @twitterapi',
      '#path' => 'https://twitter.com/twitterapi',
      '#options' => array(
        'attributes' => array(
          'class' => array('twitter-timeline'),
          'data-widget-id' => $conf['widget_id'],
        ),
        'html' => FALSE,
      ),
      '#attached' => array(
        'js' => array(
          'https://platform.twitter.com/widgets.js' => array(
            'type' => 'external',
          ),
        ),
      ),
    );

    if (!empty($conf['theme'])) {
      $block->content['#options']['attributes']['data-theme'] = $conf['theme'];
    }

    if (!empty($conf['link_color'])) {
      $block->content['#options']['attributes']['data-link-color'] = '#' . $conf['link_color'];
    }

    if (!empty($conf['width'])) {
      $block->content['#options']['attributes']['width'] = $conf['width'];
    }

    if (!empty($conf['height'])) {
      $block->content['#options']['attributes']['height'] = $conf['height'];
    }

    if (!empty($conf['chrome'])) {
      $options = array();

      foreach ($conf['chrome'] as $option => $status) {
        if ($status) {
          $options[] = $option;
        }
      }

      if (count($options)) {
        $block->content['#options']['attributes']['data-chrome'] = implode(' ', $options);
      }
    }

    if (!empty($conf['border_color'])) {
      $block->content['#options']['attributes']['data-border-color'] = '#' . $conf['border_color'];
    }

    if (!empty($conf['language'])) {
      $block->content['#options']['attributes']['lang'] = $conf['language'];
    }

    if (!empty($conf['tweet_limit'])) {
      $block->content['#options']['attributes']['data-tweet-limit'] = $conf['tweet_limit'];
    }

    if (!empty($conf['related'])) {
      $block->content['#options']['attributes']['data-related'] = $conf['related'];
    }

    if (!empty($conf['polite'])) {
      $block->content['#options']['attributes']['data-aria-polite'] = $conf['polite'];
    }
  }
  else {
    $block->content = '<p>Twitter timeline not yet configured.</p>';
  }

  return $block;
}

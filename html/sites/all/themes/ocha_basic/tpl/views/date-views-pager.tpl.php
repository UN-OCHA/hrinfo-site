<?php
/**
 * @file
 * Template file for the example display.
 *
 * Variables available:
 * 
 * $plugin: The pager plugin object. This contains the view.
 *
 * $plugin->view
 *   The view object for this navigation.
 *
 * $nav_title
 *   The formatted title for this view. In the case of block
 *   views, it will be a link to the full view, otherwise it will
 *   be the formatted name of the year, month, day, or week.
 *
 * $prev_url
 * $next_url
 *   Urls for the previous and next calendar pages. The links are
 *   composed in the template to make it easier to change the text,
 *   add images, etc.
 *
 * $prev_options
 * $next_options
 *   Query strings and other options for the links that need to
 *   be used in the l() function, including rel=nofollow.
 */
?>
<?php if (!empty($pager_prefix)) print $pager_prefix; ?>
<div class="date-nav-wrapper clearfix<?php if (!empty($extra_classes)) print $extra_classes; ?>">
  <div class="group-nav">
    <?php if (!empty($prev_url)) : ?>
    <div class="prev">
      <?php print l('' . ($mini ? '' : ' ' . t('', array(), array('context' => 'date_nav'))), $prev_url, $prev_options); ?>
  </div>
    <?php endif; ?>
        <div class="title-nav"> <h3><?php print strip_tags($nav_title); ?></h3></div>
    <?php if (!empty($next_url)) : ?>
    <div class="next">
      <?php print l(($mini ? '' : t('', array(), array('context' => 'date_nav')) . ' ') . '', $next_url, $next_options); ?>
  </div>
    <?php endif; ?>
  </div>
</div>
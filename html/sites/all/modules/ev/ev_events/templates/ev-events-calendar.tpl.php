<?php

  /**
   * @file
   * Initial template for the ev-events documents.
   */
?>
<div class="ev-events--wrapper container">
 
  <div class="ev-events--sidebar col-md-3">
    <div class="ev-events--powered-by poweredby-logo">
      <p><?php print t('Powered by'); ?></p>
      <a href="http://ev-events.int/">
        <img src="/<?php print drupal_get_path('module', 'ev_events') ?>/assets/ev_events.svg" alt="ev-events">
      </a>
    </div>
    <div class="ev-events--summary current-search-filter">
      <?php print render($summary); ?>
    </div>
    <div class="ev-events--clearall current-reset-filter">
      <?php print render($clearall); ?>
    </div>
    <div class="ev-events--removefacets">
      <?php print render($removefacets); ?>
    </div>
    <div class="ev-events--facets">
      <?php print render($facets); ?>
    </div>
  </div>
  <div class="ev-events--content col-md-9">
    <h2 class="pb-header">Reports and Maps</h2>
    <?php if ($contents): ?>
    <div class="ev-events--intro">
      <?php print render($contents); ?>
    </div>
    <?php endif ?>
    <div class="ev-events--data">
      <?php print render($data); ?>
    </div>
    <div class="ev-events--pager">
      <?php print render($pager); ?>
    </div>
  </div>
</div>

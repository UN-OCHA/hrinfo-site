<?php
  /**
   * @file
   * Initial template for the reliefweb documents.
   */
?>
<div class="reliefweb--wrapper container">
 
  <div class="reliefweb--sidebar col-md-3">
    <div class="reliefweb--powered-by poweredby-logo">
      <p><?php print t('Powered by'); ?></p>
      <a href="http://reliefweb.int/">
        <img src="/<?php print drupal_get_path('module', 'hr_reliefweb') ?>/assets/reliefweb.svg" alt="ReliefWeb">
      </a>
    </div>
    <div class="reliefweb--summary current-search-filter">
      <?php print render($summary); ?>
    </div>
    <div class="reliefweb--clearall current-reset-filter">
      <?php print render($clearall); ?>
    </div>
    <div class="reliefweb--removefacets">
      <?php print render($removefacets); ?>
    </div>
    <div class="reliefweb--facets">
      <?php print render($facets); ?>
    </div>
  </div>
  <div class="reliefweb--content col-md-9">
    <h2 class="pb-header">Documents</h2>
    <?php if ($contents): ?>
    <div class="reliefweb--intro">
      <?php print render($contents); ?>
    </div>
     <?php endif ?>
    <div class="reliefweb--data">
      <?php print render($data); ?>
    </div>
    <div class="reliefweb--pager">
      <?php print render($pager); ?>
    </div>
  </div>
</div>

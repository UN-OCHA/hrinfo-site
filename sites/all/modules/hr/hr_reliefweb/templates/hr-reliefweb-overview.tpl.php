<?php
  /**
   * @file
   * Initial template for the reliefweb documents.
   */
?>

<div class="reliefweb--wrapper">
  <div class="reliefweb--intro">
    <?php print render($contents); ?>
  </div>
  <div class="reliefweb--sidebar">
    <div class="reliefweb--summary">
      <?php print render($summary); ?>
    </div>
    <div class="reliefweb--clearall">
      <?php print render($clearall); ?>
    </div>
    <div class="reliefweb--removefacets">
      <?php print render($removefacets); ?>
    </div>
    <div class="reliefweb--facets">
      <?php print render($facets); ?>
    </div>
  </div>
  <div class="reliefweb--content">
    <div class="reliefweb--data">
      <?php print render($data); ?>
    </div>
    <div class="reliefweb--pager">
      <?php print render($pager); ?>
    </div>
  </div>
</div>

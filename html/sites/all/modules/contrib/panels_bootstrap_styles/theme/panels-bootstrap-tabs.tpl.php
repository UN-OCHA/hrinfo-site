<?php

/**
 * @file
 * Panels tabs template panels-bootstrap-tabs.tpl.php.
 */
?>

<div class="panels-bootstrap-tabs">
  <div class="<?php print $nav_wrapper_classes; ?>">
    <ul class="<?php print $tab_classes; ?>">
      <?php foreach($tab_titles as $tab_title) : ?>
        <?php print $tab_title; ?>
      <?php endforeach ?>
    </ul>
  </div>

  <div class="<?php print $tab_content_wrapper_classes; ?>">
    <div class="tab-content">
      <?php foreach($tab_panes as $tab_pane) : ?>
        <?php print $tab_pane; ?>
      <?php endforeach ?>
    </div>
  </div>
</div>

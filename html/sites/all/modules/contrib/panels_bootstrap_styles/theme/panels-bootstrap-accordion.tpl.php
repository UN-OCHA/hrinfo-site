<?php

/**
 * @file
 * Panels accordion template panels-bootstrap-accordion.tpl.php.
 */
?>

<div class="panel-group" id="accordion-<?php print $display->did; ?>" role="tablist" aria-multiselectable="true">
  <?php foreach($panes as $panel_pane) : ?>
    <?php print $panel_pane; ?>
  <?php endforeach ?>
</div>

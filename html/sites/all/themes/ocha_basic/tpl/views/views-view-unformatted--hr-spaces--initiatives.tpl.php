<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="views-group col-md-6">
  <?php if (!empty($title)): ?>
    <h3 class="views-group-title"><?php print $title; ?></h3>
  <?php endif; ?>
  <?php if (!empty($title)): ?>
    <div class="views-group-content">
  <?php endif; ?>
  <?php foreach ($rows as $id => $row): ?>
    <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
      <?php print $row; ?>
    </div>
  <?php endforeach; ?>
  <?php if (!empty($title)): ?>
    </div>
  <?php endif; ?>
</div>

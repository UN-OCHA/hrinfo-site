<?php

/**
 * @file
 * Template for the report node edit form.
 */
?>

<?php print drupal_render($form['title_field']); ?>
<?php print drupal_render($form['language']); ?>
<fieldset class="main-inputs">
  <?php print drupal_render($form['field_address']); ?>
  <?php print drupal_render($form['field_email']); ?>
  <?php print drupal_render($form['field_phones']); ?>
</fieldset>
<fieldset class="details">
  <?php print drupal_render($form['og_group_ref']); ?>
  <?php print drupal_render($form['field_is_coordination_hub']); ?>
</fieldset>

<fieldset id="actions">
  <?php print drupal_render($form['actions']); ?>
</fieldset>

<?php print drupal_render_children($form); ?>

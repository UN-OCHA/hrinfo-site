<?php

/**
 * @file
 * Template for the report node edit form.
 */
?>

<?php print drupal_render($form['title_field']); ?>
<?php print drupal_render($form['language']); ?>
<?php print drupal_render($form['field_address']); ?>
<fieldset class="contact">
  <?php print drupal_render($form['field_is_coordination_hub']); ?>
  <?php print drupal_render($form['field_email']); ?>
</fieldset>
<?php print drupal_render($form['og_group_ref']); ?>
<?php print drupal_render($form['field_phones']); ?>

<fieldset id="actions">
  <?php print drupal_render($form['actions']); ?>
</fieldset>

<?php print drupal_render_children($form); ?>

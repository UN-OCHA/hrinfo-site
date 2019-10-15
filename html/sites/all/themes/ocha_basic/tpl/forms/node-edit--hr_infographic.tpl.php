<?php

/**
 * @file
 * Template for the report node edit form.
 */
?>

<?php print drupal_render($form['title_field']); ?>
<?php print drupal_render($form['language']); ?>
<fieldset class="main-inputs">
  <?php print drupal_render($form['body']); ?>
  <?php print drupal_render($form['field_files_collection']); ?>
</fieldset>
<fieldset class="details">
  <?php print drupal_render($form['field_exclude_reliefweb']); ?>
  <?php print drupal_render($form['field_sectors']); ?>
  <?php print drupal_render($form['field_publication_date']); ?>
  <?php print drupal_render($form['field_infographic_type']); ?>
  <?php print drupal_render($form['field_organizations']); ?>
  <?php print drupal_render($form['field_disasters']); ?>
</fieldset>
<fieldset class="main-inputs">
  <?php print drupal_render($form['og_group_ref']); ?>
</fieldset>
<fieldset class="details">
  <?php print drupal_render($form['field_coordination_hubs']); ?>
  <?php print drupal_render($form['field_bundles']); ?>
</fieldset>

<fieldset class="hr-additional">
  <div class="toggle">
    <?php print drupal_render($form['field_locations']); ?>
    <?php print drupal_render($form['field_themes']); ?>
    <?php print drupal_render($form['field_data_sources']); ?>
    <?php print drupal_render($form['field_related_content']); ?>
  </div>
</fieldset>

<fieldset id="actions">
  <?php print drupal_render($form['actions']); ?>
</fieldset>

<?php print drupal_render_children($form); ?>

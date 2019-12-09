<?php

/**
 * @file
 * Template for the report node edit form.
 */
?>

<?php print drupal_render($form['title_field']); ?>
<?php print drupal_render($form['language']); ?>
<fieldset class="main-inputs">
  <?php print drupal_render($form['field_infographic_type']); ?>
  <?php print drupal_render($form['body']); ?>
  <?php print drupal_render($form['field_files_collection']); ?>
</fieldset>
<fieldset class="details">
  <?php print drupal_render($form['og_group_ref']); ?>
  <?php print drupal_render($form['field_bundles']); ?>
  <?php print drupal_render($form['field_publication_date']); ?>
  <?php print drupal_render($form['field_organizations']); ?>
  <?php print drupal_render($form['field_coordination_hubs']); ?>
  <?php print drupal_render($form['field_disasters']); ?>
</fieldset>
<fieldset class="main-inputs">
</fieldset>
<fieldset class="details">
</fieldset>

<fieldset class="hr-additional">
  <div class="toggle">
    <?php print drupal_render($form['field_related_content']); ?>
    <?php print drupal_render($form['field_locations']); ?>
    <?php print drupal_render($form['field_themes']); ?>
  </div>
  <div class="optional-fields">
    Click to add Related content, Locations and Themes.
  </div>
</fieldset>

<?php print drupal_render($form['field_exclude_reliefweb']); ?>
<fieldset id="actions">
  <?php print drupal_render($form['actions']); ?>
</fieldset>
<?php print drupal_render_children($form); ?>

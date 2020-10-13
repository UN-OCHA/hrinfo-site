<?php

/**
 * @file
 * Template for the report node edit form.
 */
?>

<?php print drupal_render($form['title_field']); ?>
<?php print drupal_render($form['language']); ?>
<fieldset class="main-inputs">
  <?php print drupal_render($form['field_asst_status']); ?>
  <?php print drupal_render($form['field_asst_date']); ?>
  <?php print drupal_render($form['field_locations']); ?>
  <?php print drupal_render($form['field_asst_other_location']); ?>
  <?php print drupal_render($form['field_asst_report']); ?>
  <?php print drupal_render($form['field_asst_questionnaire']); ?>
  <?php print drupal_render($form['field_asst_data']); ?>
</fieldset>
<fieldset class="details">
  <?php print drupal_render($form['og_group_ref']); ?>
  <?php print drupal_render($form['field_bundles']); ?>
  <?php print drupal_render($form['field_organizations']); ?>
  <?php print drupal_render($form['field_organizations2']); ?>
  <?php print drupal_render($form['field_population_types']); ?>
  <?php print drupal_render($form['field_coordination_hubs']); ?>
  <?php print drupal_render($form['field_disasters']); ?>
</fieldset>

<fieldset class="hr-additional">
  <div class="toggle">
    <?php print drupal_render($form['field_asst_subject']); ?>
    <?php print drupal_render($form['field_asst_sample_size']); ?>
    <?php print drupal_render($form['field_asst_methodology']); ?>
    <?php print drupal_render($form['field_level_of_representation']); ?>
    <?php print drupal_render($form['field_asst_key_findings']); ?>
    <?php print drupal_render($form['field_asst_freq']); ?>
    <?php print drupal_render($form['field_related_content']); ?>
    <?php print drupal_render($form['field_asst_unit']); ?>
    <?php print drupal_render($form['field_asst_collection_method']); ?>
    <?php print drupal_render($form['field_themes']); ?>
  </div>
  <div class="optional-fields">
    <?php print t("Click to add Subject, Methodology, Key Findings, Related content, and other details."); ?>
  </div>
</fieldset>

<fieldset id="actions">
  <?php print drupal_render($form['actions']); ?>
</fieldset>
<?php print drupal_render_children($form); ?>

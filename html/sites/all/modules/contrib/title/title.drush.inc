<?php

/**
 * @file
 * Drush commands for Title module.
 */

/**
 * Implements hook_drush_help().
 */
function title_drush_help($section) {
  switch ($section) {
    case 'drush:upgrade-title-fields':
      return dt('Upgrade title fields to use title module, so that titles can be localized.');
  }
}

/**
 * Implements hook_drush_command().
 */
function title_drush_command() {
  $items['upgrade-title-fields'] = array(
    'description' => 'Upgrade title fields to use title module, so that titles can be localized.',
    'drupal dependencies' => array('title', 'entity_translation'),
  );
  $items['upgrade-title-field'] = array(
    'description' => 'Upgrade a title field on a legacy field. DO NOT call this command directly, it does not do any checking.',
    'hidden' => TRUE,
    'arguments' => array(
      'entity_type' => 'The type of entity, be it a node, user, term, etc.',
      'bundle' => 'The entity bundle.',
      'legacy_field' => 'The machine name of the legace field.',
    ),
  );

  return $items;
}

/**
 * Command callback for upgrade-title-fields.
 */
function drush_title_upgrade_title_fields() {
  $entity_type = 'node';
  $entity_info = entity_get_info($entity_type);
  if (empty($entity_info['field replacement'])) {
    drush_log(t('There are no available title fields to upgrade.'), 'error');
    return FALSE;
  }

  $field_replacement_info = $entity_info['field replacement'];

  $upgraded = $failed = $skipped = 0;
  foreach (title_content_types() as $bundle) {
    $dt_args['@bundle'] = $bundle;
    $field_instances = field_info_instances($entity_type, $bundle);
    $extra_fields = field_info_extra_fields($entity_type, $bundle, 'form');
    $possible_fields = array_merge($field_instances, $extra_fields);

    if ($info = array_intersect_key($field_replacement_info, $possible_fields)) {
      foreach (array_keys($info) as $legacy_field) {
        $dt_args['@legacy_field'] = $legacy_field;
        if (drush_invoke_process('@self', 'upgrade-title-field', array($entity_type, $bundle, $legacy_field))) {
          $upgraded++;
        }
        else {
          $failed++;
        }
      }
    }
    else {
      $skipped++;
      drush_log(dt('Title fields have already been upgraded on content type @bundle.', $dt_args), 'ok');
    }
  }

  $messages = array();
  if ($upgraded) {
    $dt_args['@upgraded'] = $upgraded;
    $messages[] = 'Upgraded @upgraded title field(s).';
  }
  if ($skipped) {
    $dt_args['@skipped'] = $skipped;
    $messages[] = 'Skipped @skipped title field(s).';
  }
  if ($failed) {
    $dt_args['@failed'] = $failed;
    $messages[] = '@failed failed.';
  }
  $message = empty($messages) ? 'No fields upgraded.' : implode(' ', $messages);
  drush_log(dt($message, $dt_args), 'completed');
  if ($failed) {
    return FALSE;
  }
}

/**
 * Command callback for upgrade-title-field.
 */
function drush_title_upgrade_title_field($entity_type, $bundle, $legacy_field) {
  $dt_args['@entity_type'] = $entity_type;
  $dt_args['@bundle'] = $bundle;
  $dt_args['@field'] = $legacy_field;
  if (!title_field_replacement_toggle($entity_type, $bundle, $legacy_field)) {
    drush_log(dt("Failed to upgrade title field '@field' on content type @bundle.", $dt_args), 'warning');
    return FALSE;
  }
  title_field_replacement_batch_set($entity_type, $bundle, $legacy_field);
  drush_backend_batch_process();

  if (drush_get_error()) {
    drush_log(dt("Failed upgrading title field '@field' on bundle '@bundle'. Your database is likely messed up now. Sorry about that.", $dt_args), 'error');
    return FALSE;
  }
  drush_log(dt("Upgraded title field '@field' on content type @bundle.", $dt_args), 'success');
  return TRUE;
}

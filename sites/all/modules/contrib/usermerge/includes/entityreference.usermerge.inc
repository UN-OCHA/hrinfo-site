<?php
/**
 * @file
 * Adds support for Entity Reference.
 * Supplemental include loaded via usermerge_load_includes().
 */

/**
 * Implement hook_usermerge_build_review_form_elements().
 */
function entityreference_usermerge_build_review_form_elements($review, $account_properties, $user_to_delete, $user_to_keep) {
  $entities = _entityreference_usermerge_get_referencing_entity_types();

  $entityreferences_user_to_delete = array();
  $entityreferences_user_to_keep = array();

  foreach ($entities as $entity_type => $fields) {
    foreach ($fields as $field) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', $entity_type)
        ->fieldCondition($field['field_name'], 'target_id', $user_to_delete->uid);

      $result = $query->execute();

      if (count($result)) {
        if (isset($entityreferences_user_to_delete[$entity_type])) {
          $entityreferences_user_to_delete[$entity_type] = $entityreferences_user_to_delete[$entity_type] + $result[$entity_type];
        }
        else {
          $entityreferences_user_to_delete[$entity_type] = $result[$entity_type];
        }
      }

      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', $entity_type)
        ->fieldCondition($field['field_name'], 'target_id', $user_to_keep->uid);

      $result = $query->execute();

      if (count($result)) {
        if (isset($entityreferences_user_to_keep[$entity_type])) {
          $entityreferences_user_to_keep[$entity_type] = $entityreferences_user_to_keep[$entity_type] + $result[$entity_type];
        }
        else {
          $entityreferences_user_to_keep[$entity_type] = $result[$entity_type];
        }
      }
    }
  }

  if (count($entityreferences_user_to_delete) || count($entityreferences_user_to_keep)) {
    $review['entityreference'] = array(
      '#tree' => TRUE,
      '#theme' => 'usermerge_data_review_form_table',
      '#title' => t('Referencing entities (!module)', array('!module' => t('Entity Reference'))),
      '#attributes' => array('no_merge', 'property_label' => t('Entity'))
    );

    foreach ($entityreferences_user_to_delete as $entity_type => $entity_list) {
      $review['entityreference'][$entity_type]['property_name'] = array(
          '#type' => 'markup',
          '#markup' => $entity_type
        );

      $review['entityreference'][$entity_type]['options']['user_to_delete'] = array(
        '#type' => 'markup',
        '#markup' => format_plural(count($entity_list), '1 %entity entity to be reassigned', '@count %entity entities to be reassigned', array('%entity' => $entity_type))
      );

      $review['entityreference'][$entity_type]['fields'] = array(
        '#type' => 'hidden',
        '#value' => serialize($entities[$entity_type])
      );
    }

    foreach ($entityreferences_user_to_keep as $entity_type => $entity_list) {
      $review['entityreference'][$entity_type]['property_name'] = array(
          '#type' => 'markup',
          '#markup' => $entity_type
        );

      $review['entityreference'][$entity_type]['options']['user_to_keep'] = array(
        '#type' => 'markup',
        '#markup' => format_plural(count($entity_list), '1 %entity entity to be maintained', '@count %entity entities to be maintained', array('%entity' => $entity_type))
      );
    }

    ksort($review['entityreference']);

    return $review;

  }
}

/**
 * Implement hook_usermerge_actions_supported().
 */
function entityreference_usermerge_actions_supported($items) {
  return array(
    'entityreference' => t('Assigning to the new user any entities (such as nodes) referencing the old user using the Entity Reference module.')
  );
}

/**
 * Implements hook_usermerge_merge_accounts().
 */
function entityreference_usermerge_merge_accounts($user_to_delete, $user_to_keep, $review) {
  if (isset($review['entityreference'])) {
    $fields = array();

    foreach ($review['entityreference'] as $entity_type => $entity_properties) {
      $fields = array_merge($fields, unserialize($entity_properties['fields']));
    }

    if (count($fields)) {
      foreach ($fields as $field_name => $field_properties) {
        $tables = array(
          'data' => 'field_data_' . $field_name,
          'revision' => 'field_revision_' . $field_name,
        );

        foreach ($tables as $table_name) {
          $query = db_update($table_name)
            ->fields(array(
                $field_name . '_target_id' => $user_to_keep->uid
              )
            )
            ->condition($field_name . '_target_id', $user_to_delete->uid)
            ->execute();
        }
      }
    }
  }
}

/**
 * Selects entities that reference users via the Entity Reference module.
 */
function _entityreference_usermerge_get_referencing_entity_types() {
  $fields = field_info_fields();
  $referencing_entity_types = array();

  foreach ($fields as $field_name => $field) {
    if ('entityreference' == $field['type']) {

      // Select only fields that are referencing user entities
      if ($field['settings']['target_type'] == 'user') {
        foreach ($field['bundles'] as $entity_type => $bundles) {
          $referencing_entity_types[$entity_type][$field_name] = $field;
        }
      }
    }
  }

  return $referencing_entity_types;
}

<?php

$result = db_select('og_features', 'ogf')
  ->fields('ogf', array('entity_id'))
  ->condition('ogf.entity_type', 'node')
  ->execute()
  ->fetchAllAssoc('entity_id');
$nids = array_keys($result);

foreach ($nids as $nid) {
  // Skip Ethiopia
  if ($nid == 65) {
    continue;
  }

  drush_log('Processing ' . $nid);
  
  $result = db_select('og_features', 'ogf')
    ->fields('ogf', array('settings'))
    ->condition('ogf.entity_type', 'node')
    ->condition('ogf.entity_id', $nid)
    ->execute()
    ->fetchField();

  $features = $result ? unserialize($result) : array();
  if (!empty($features)) {
    if (isset($features['hr_reliefweb_documents']) && $features['hr_reliefweb_documents'] == 0) {
      drush_log('Skipping ' . $nid);
      continue;
    }
    $features['hr_reliefweb_documents'] = 0;

    db_update('og_features')
      ->fields(array('settings' => serialize($features)))
      ->condition('entity_type', 'node')
      ->condition('entity_id', $nid)
      ->execute();

    $node = node_load($nid, NULL, TRUE);
    drush_log('Updated ' . $nid);
  }
}

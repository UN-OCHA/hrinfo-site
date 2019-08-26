<?php 

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);


$query = db_select('locales_source', 'ls')
  ->fields('ls', array('lid', 'source'));
$sources = $query->execute()->fetchAll();

$del_count = 0;

foreach ($sources as $source) {
  $lid = $source->lid;
  
  $query = db_select('locales_target', 'lt')
    ->fields('lt', array('lid', 'translation'))
    ->condition('lid', $lid);
  $target = $query->execute()->fetchObject();
  
  //There is translation - print it
  if (!isset($target->lid)) {
    $delq = db_delete('locales_source')
      ->condition('lid', $lid)
      ->execute();
    $del_count++;
  }
}

print 'Deleted ' . $del_count . ' untranslated locales_source entries.';
exit();

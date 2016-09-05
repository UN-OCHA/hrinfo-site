<?php 

$sql = "select t5.tid, d1.name as l1, d2.name as l2, d3.name as l3, d4.name as l4, d5.name as l5 from {taxonomy_term_hierarchy} t1 inner join {taxonomy_term_hierarchy} t2 on t2.parent = t1.tid inner join {taxonomy_term_hierarchy} t3 on t3.parent = t2.tid inner join {taxonomy_term_hierarchy} t4 on t4.parent = t3.tid inner join {taxonomy_term_hierarchy} t5 on t5.parent = t4.tid  inner join taxonomy_term_data d5 on d5.tid = t5.tid inner join taxonomy_term_data d4 on d4.tid = t4.tid  inner join taxonomy_term_data d3 on d3.tid = t3.tid inner join taxonomy_term_data d2 on d2.tid = t2.tid inner join taxonomy_term_data d1 on d1.tid = t1.tid limit 100;";
$result = db_query($sql);
$data = $result->fetchAllAssoc('tid');
$output = array();
foreach ($data as $row) {
  $nids = taxonomy_select_nodes($row->tid, FALSE);
  if ($nids) {
    drush_log('Fixing ' . $row->tid . ': ' . $row->l1 . ' > ' . $row->l2 . ' > ' . $row->l3 . ' > ' . $row->l4 . ' > ' . $row->l5);
    $parent = taxonomy_get_parents($row->tid);
    $parent_id = reset(array_keys($parent));
    
    $nids = array_unique($nids);
    drush_print_r($nids);
    $nodes = node_load_multiple($nids);
    foreach ($nodes as $node) {
      if (isset($node->field_locations)) {
        foreach ($node->field_locations as $lang => $items) {
          $parent_found = FALSE;
          foreach ($items as $i => $item) {
            // Check if parent exists.
            if ($item['target_id'] == $parent_id) {
              $parent_found = TRUE;
            }
          }
          if ($parent_found) {
            // Remove child.
            foreach ($items as $i => $item) {
              if ($item['target_id'] == $row->tid) {
                unset($node->field_locations[$lang][$i]);
                break;
              }
            }
          }
          else {
            // Replace child with parent.
            foreach ($items as $i => $item) {
              if ($item['target_id'] == $row->tid) {
                $node->field_locations[$lang][$i]['target_id'] = $parent_id;
                break;
              }
            }
          }
        }
      }
      else {
        foreach ($node->field_location as $lang => $items) {
          $parent_found = FALSE;
          foreach ($items as $i => $item) {
            // Check if parent exists.
            if ($item['target_id'] == $parent_id) {
              $parent_found = TRUE;
            }
          }
          if ($parent_found) {
            // Remove child.
            foreach ($items as $i => $item) {
              if ($item['target_id'] == $row->tid) {
                unset($node->field_location[$lang][$i]);
                break;
              }
            }
          }
          else {
            // Replace child with parent.
            foreach ($items as $i => $item) {
              if ($item['target_id'] == $row->tid) {
                $node->field_location[$lang][$i]['target_id'] = $parent_id;
                break;
              }
            }
          }
        }
      }
      node_save($node);
    }
  }
  else {
    taxonomy_term_delete($row->tid);
    drush_log('Deleting ' . $row->tid . ': ' . $row->l1 . ' > ' . $row->l2 . ' > ' . $row->l3 . ' > ' . $row->l4 . ' > ' . $row->l5);
  }
}


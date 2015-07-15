<?php
/**
 * @file
 * hr_discussions.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function hr_discussions_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:hr_bundle:access authoring options of hr_discussion content'
  $permissions['node:hr_bundle:access authoring options of hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:access publishing options of hr_discussion content'
  $permissions['node:hr_bundle:access publishing options of hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:access revisions options of hr_discussion content'
  $permissions['node:hr_bundle:access revisions options of hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:approve comment_node_hr_discussion'
  $permissions['node:hr_bundle:approve comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:create hr_discussion content'
  $permissions['node:hr_bundle:create hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:delete any hr_discussion content'
  $permissions['node:hr_bundle:delete any hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:delete comment_node_hr_discussion'
  $permissions['node:hr_bundle:delete comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:delete own hr_discussion content'
  $permissions['node:hr_bundle:delete own hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:edit comment_node_hr_discussion'
  $permissions['node:hr_bundle:edit comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:edit own comment_node_hr_discussion'
  $permissions['node:hr_bundle:edit own comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:post comment_node_hr_discussion'
  $permissions['node:hr_bundle:post comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:update any hr_discussion content'
  $permissions['node:hr_bundle:update any hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:update own hr_discussion content'
  $permissions['node:hr_bundle:update own hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_bundle:view any unpublished hr_discussion content'
  $permissions['node:hr_bundle:view any unpublished hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_disaster:access authoring options of hr_discussion content'
  $permissions['node:hr_disaster:access authoring options of hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_disaster:access publishing options of hr_discussion content'
  $permissions['node:hr_disaster:access publishing options of hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_disaster:access revisions options of hr_discussion content'
  $permissions['node:hr_disaster:access revisions options of hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_disaster:create hr_discussion content'
  $permissions['node:hr_disaster:create hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_disaster:delete any hr_discussion content'
  $permissions['node:hr_disaster:delete any hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_disaster:delete own hr_discussion content'
  $permissions['node:hr_disaster:delete own hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_disaster:update any hr_discussion content'
  $permissions['node:hr_disaster:update any hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_disaster:update own hr_discussion content'
  $permissions['node:hr_disaster:update own hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_disaster:view any unpublished hr_discussion content'
  $permissions['node:hr_disaster:view any unpublished hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_operation:access authoring options of hr_discussion content'
  $permissions['node:hr_operation:access authoring options of hr_discussion content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:access publishing options of hr_discussion content'
  $permissions['node:hr_operation:access publishing options of hr_discussion content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:approve comment_node_hr_discussion'
  $permissions['node:hr_operation:approve comment_node_hr_discussion'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:create hr_discussion content'
  $permissions['node:hr_operation:create hr_discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete any hr_discussion content'
  $permissions['node:hr_operation:delete any hr_discussion content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:delete comment_node_hr_discussion'
  $permissions['node:hr_operation:delete comment_node_hr_discussion'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:edit comment_node_hr_discussion'
  $permissions['node:hr_operation:edit comment_node_hr_discussion'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:edit own comment_node_hr_discussion'
  $permissions['node:hr_operation:edit own comment_node_hr_discussion'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hr_operation:post comment_node_hr_discussion'
  $permissions['node:hr_operation:post comment_node_hr_discussion'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hr_operation:update any hr_discussion content'
  $permissions['node:hr_operation:update any hr_discussion content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_operation:update own hr_discussion content'
  $permissions['node:hr_operation:update own hr_discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hr_operation:view any unpublished hr_discussion content'
  $permissions['node:hr_operation:view any unpublished hr_discussion content'] = array(
    'roles' => array(
      'manager' => 'manager',
    ),
  );

  // Exported og permission: 'node:hr_sector:access authoring options of hr_discussion content'
  $permissions['node:hr_sector:access authoring options of hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:access publishing options of hr_discussion content'
  $permissions['node:hr_sector:access publishing options of hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:access revisions options of hr_discussion content'
  $permissions['node:hr_sector:access revisions options of hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:approve comment_node_hr_discussion'
  $permissions['node:hr_sector:approve comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:create hr_discussion content'
  $permissions['node:hr_sector:create hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:delete any hr_discussion content'
  $permissions['node:hr_sector:delete any hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:delete comment_node_hr_discussion'
  $permissions['node:hr_sector:delete comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:delete own hr_discussion content'
  $permissions['node:hr_sector:delete own hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:edit comment_node_hr_discussion'
  $permissions['node:hr_sector:edit comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:edit own comment_node_hr_discussion'
  $permissions['node:hr_sector:edit own comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:post comment_node_hr_discussion'
  $permissions['node:hr_sector:post comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:update any hr_discussion content'
  $permissions['node:hr_sector:update any hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:update own hr_discussion content'
  $permissions['node:hr_sector:update own hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_sector:view any unpublished hr_discussion content'
  $permissions['node:hr_sector:view any unpublished hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:access authoring options of hr_discussion content'
  $permissions['node:hr_space:access authoring options of hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:access publishing options of hr_discussion content'
  $permissions['node:hr_space:access publishing options of hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:access revisions options of hr_discussion content'
  $permissions['node:hr_space:access revisions options of hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:approve comment_node_hr_discussion'
  $permissions['node:hr_space:approve comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:create hr_discussion content'
  $permissions['node:hr_space:create hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:delete any hr_discussion content'
  $permissions['node:hr_space:delete any hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:delete comment_node_hr_discussion'
  $permissions['node:hr_space:delete comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:delete own hr_discussion content'
  $permissions['node:hr_space:delete own hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:edit comment_node_hr_discussion'
  $permissions['node:hr_space:edit comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:edit own comment_node_hr_discussion'
  $permissions['node:hr_space:edit own comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:post comment_node_hr_discussion'
  $permissions['node:hr_space:post comment_node_hr_discussion'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:update any hr_discussion content'
  $permissions['node:hr_space:update any hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:update own hr_discussion content'
  $permissions['node:hr_space:update own hr_discussion content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hr_space:view any unpublished hr_discussion content'
  $permissions['node:hr_space:view any unpublished hr_discussion content'] = array(
    'roles' => array(),
  );

  return $permissions;
}

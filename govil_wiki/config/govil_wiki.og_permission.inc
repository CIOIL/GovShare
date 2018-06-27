<?php

/**
 * @file
 * govil_wiki.og_permission.inc
 */

/**
 * Update permissions on wiki page group.
 */
function govil_wiki_set_og_permissions() {
  $permissions = array();

  // Exported og permission: 'node:wiki_page:access authoring options of wiki_page content'.
  $permissions['node:wiki_page:access authoring options of wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'trusted member' => 'trusted member',
    ),
  );

  // Exported og permission: 'node:wiki_page:access publishing options of wiki_page content'.
  $permissions['node:wiki_page:access publishing options of wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'trusted member' => 'trusted member',
    ),
  );

  // Exported og permission: 'node:wiki_page:access revisions options of wiki_page content'.
  $permissions['node:wiki_page:access revisions options of wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:wiki_page:create wiki_page content'.
  $permissions['node:wiki_page:create wiki_page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:wiki_page:delete any wiki_page content'.
  $permissions['node:wiki_page:delete any wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:wiki_page:delete own wiki_page content'.
  $permissions['node:wiki_page:delete own wiki_page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:wiki_page:publish revisions of any wiki_page content'.
  $permissions['node:wiki_page:publish revisions of any wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'trusted member' => 'trusted member',
    ),
  );

  // Exported og permission: 'node:wiki_page:publish revisions of own wiki_page content'.
  $permissions['node:wiki_page:publish revisions of own wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'trusted member' => 'trusted member',
    ),
  );

  // Exported og permission: 'node:wiki_page:unpublish current revision'.
  $permissions['node:wiki_page:unpublish current revision'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'trusted member' => 'trusted member',
    ),
  );

  // Exported og permission: 'node:wiki_page:update any wiki_page content'.
  $permissions['node:wiki_page:update any wiki_page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:wiki_page:update own wiki_page content'.
  $permissions['node:wiki_page:update own wiki_page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:wiki_page:view any unpublished wiki_page content'.
  $permissions['node:wiki_page:view any unpublished wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:wiki_page:view revision status messages'.
  $permissions['node:wiki_page:view revision status messages'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'trusted member' => 'trusted member',
    ),
  );

  // Grant permissions to these roles.
  $roles = og_roles('node', 'wiki_page');

  foreach ($roles as $rid => $name) {
    $grant_perms = [];
    foreach ($permissions as $key => $permission) {
      // $key is 'entity_type:bundle:permission'.
      list($group_type, $bundle, $perm) = explode(':', $key);
      if (in_array($name, $permission['roles'])) {
        $grant_perms[] = $perm;
      }
    }
    og_role_grant_permissions($rid, $grant_perms);
  }

}

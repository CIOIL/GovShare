<?php
/**
 * @file
 * govil_wiki.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function govil_wiki_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:wiki_page:access authoring options of wiki_page content'
  $permissions['node:wiki_page:access authoring options of wiki_page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:wiki_page:access publishing options of wiki_page content'
  $permissions['node:wiki_page:access publishing options of wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'trusted member' => 'trusted member',
    ),
  );

  // Exported og permission: 'node:wiki_page:access revisions options of wiki_page content'
  $permissions['node:wiki_page:access revisions options of wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:wiki_page:administer group'
  $permissions['node:wiki_page:administer group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:wiki_page:administer og menu'
  $permissions['node:wiki_page:administer og menu'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:wiki_page:create wiki_page content'
  $permissions['node:wiki_page:create wiki_page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:wiki_page:delete any wiki_page content'
  $permissions['node:wiki_page:delete any wiki_page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:wiki_page:delete own wiki_page content'
  $permissions['node:wiki_page:delete own wiki_page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:wiki_page:invite people'
  $permissions['node:wiki_page:invite people'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:wiki_page:manage appearance'
  $permissions['node:wiki_page:manage appearance'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:wiki_page:publish revisions'
  $permissions['node:wiki_page:publish revisions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:wiki_page:publish revisions of any wiki_page content'
  $permissions['node:wiki_page:publish revisions of any wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'trusted member' => 'trusted member',
    ),
  );

  // Exported og permission: 'node:wiki_page:publish revisions of own wiki_page content'
  $permissions['node:wiki_page:publish revisions of own wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'trusted member' => 'trusted member',
    ),
  );

  // Exported og permission: 'node:wiki_page:unpublish current revision'
  $permissions['node:wiki_page:unpublish current revision'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:wiki_page:update any page content'
  $permissions['node:wiki_page:update any page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:wiki_page:update any wiki_page content'
  $permissions['node:wiki_page:update any wiki_page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:wiki_page:update own page content'
  $permissions['node:wiki_page:update own page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:wiki_page:update own wiki_page content'
  $permissions['node:wiki_page:update own wiki_page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:wiki_page:view any unpublished wiki_page content'
  $permissions['node:wiki_page:view any unpublished wiki_page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:wiki_page:view revision status messages'
  $permissions['node:wiki_page:view revision status messages'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'trusted member' => 'trusted member',
    ),
  );

  return $permissions;
}

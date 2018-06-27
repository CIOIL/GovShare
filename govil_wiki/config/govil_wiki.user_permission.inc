<?php
/**
 * @file
 * govil_wiki.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function govil_wiki_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create wiki_page content'.
  $permissions['create wiki_page content'] = array(
    'name' => 'create wiki_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any wiki_page content'.
  $permissions['delete any wiki_page content'] = array(
    'name' => 'delete any wiki_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own wiki_page content'.
  $permissions['delete own wiki_page content'] = array(
    'name' => 'delete own wiki_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any wiki_page content'.
  $permissions['edit any wiki_page content'] = array(
    'name' => 'edit any wiki_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own wiki_page content'.
  $permissions['edit own wiki_page content'] = array(
    'name' => 'edit own wiki_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'publish revisions of any wiki_page content'.
  $permissions['publish revisions of any wiki_page content'] = array(
    'name' => 'publish revisions of any wiki_page content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'publish revisions of own wiki_page content'.
  $permissions['publish revisions of own wiki_page content'] = array(
    'name' => 'publish revisions of own wiki_page content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of any wiki_page content'.
  $permissions['view revisions of any wiki_page content'] = array(
    'name' => 'view revisions of any wiki_page content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own wiki_page content'.
  $permissions['view revisions of own wiki_page content'] = array(
    'name' => 'view revisions of own wiki_page content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  return $permissions;
}

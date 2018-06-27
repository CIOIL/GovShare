<?php
/**
 * @file
 * govil_wiki.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function govil_wiki_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:wiki_page:trusted member'.
  $roles['node:wiki_page:trusted member'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'wiki_page',
    'name' => 'trusted member',
  );

  return $roles;
}

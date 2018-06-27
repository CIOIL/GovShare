<?php

/**
 * @file
 * govil_wiki.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function govil_wiki_create_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_locked'.
  $field_bases['field_locked'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_locked',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => 'Lock the page for editing',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  foreach ($field_bases as $field) {
    if (!field_info_field($field['field_name'])) {
      field_create_field($field);
    }
  }
}

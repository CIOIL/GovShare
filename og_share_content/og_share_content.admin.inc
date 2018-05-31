<?php

/**
 * @file
 * Og share content administration settings UI.
 */

/**
 * Implements hook_form().
 * Form builder function for Og share content configuration.
 */
function og_share_content_admin_settings() {
  $options = $group_audience_values = array();
  // Get all og content types in site.
  // Just content types who has children.
  $content_types = node_type_get_types();
  foreach ($content_types as $type => $info) {
    $og_fields = og_share_content_og_get_group_audience_values('node', $type);
    $group_audience_values[$type] = $og_fields;
  }
  foreach ($content_types as $type => $info) {
    if (og_is_group_type('node', $type)) {
      foreach ($group_audience_values as $group_audience_type) {
        $this_values = array_pop($group_audience_type);
        if (in_array($type, $this_values)) {
          $options[$type] = t($type);
          break;
        }
      }
    }
  }

  $form['og_share_content_group_type'] = array(
    '#type' => 'select',
    '#title' => t('Og share content og content type'),
    '#description' => t('Select a content type to share content with.'),
    '#options' => $options,
    '#required' => TRUE,
    '#default_value' => variable_get('og_share_content_group_type', ''),
  );

  $form['og_share_content_parent'] = array(
    '#type' => 'checkbox',
    '#title' => t('Og share content og parent content'),
    '#description' => t('Users can only share content between og groups under the same parent group.'),
    '#default_value' => variable_get('og_share_content_parent', NULL),
  );

  $form['og_share_content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content Types for sharing'),
    '#description' => t('Set the content types you want to allow to share in group.'),
    '#options' => node_type_get_names(),
    '#default_value' => variable_get('og_share_content_types', NULL),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * Return the og group audience values.
 *
 * @param string $entity_type
 * @param string $bundle_name
 * @param $group_type
 * @param $group_bundle
 *
 * @return array content type and group ausience and the values.
 */
function og_share_content_og_get_group_audience_values($entity_type = 'user', $bundle_name = 'user', $group_type = NULL, $group_bundle = NULL) {
  $return = &drupal_static(__FUNCTION__, array());
  $identifier = $entity_type . ':' . $bundle_name . ':' . $group_type . ':' . $group_bundle;
  if (isset($return[$identifier])) {
    return $return[$identifier];
  }
  $return[$identifier] = array();

  foreach (field_info_instances($entity_type, $bundle_name) as $field_name => $instance) {
    if (!og_is_group_audience_field($field_name)) {
      continue;
    }
    $field_info = field_info_field($instance['field_name']);
    if (isset($group_type) && $field_info['settings']['target_type'] != $group_type) {
      continue;
    }
    if ($group_bundle && !empty($field_info['settings']['handler_settings']['target_bundles']) && !in_array($group_bundle, $field_info['settings']['handler_settings']['target_bundles'])) {
      continue;
    }
    $return[$identifier][$field_name] = $field_info['settings']['handler_settings']['target_bundles'];
  }
  return $return[$identifier];
}

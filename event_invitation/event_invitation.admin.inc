<?php

/**
 * @file
 * Event invitation admin page settings.
 */

/**
 * Implements hook_form().
 *
 * Set the content type and fields of invitation.
 */
function event_invitation_admin_settings($form, &$form_state) {
  $form = [];
  $types = array_reduce(node_type_get_types(), "event_invitation_map_types", array());

  // Check if the form return from Ajax request.
  if (isset($form_state['values']['event_invitation_content_type'])) {
    $selected_type = $form_state['values']['event_invitation_content_type'];
  }
  else {
    $selected_type = variable_get('event_invitation_content_type', key($types));
  }

  $form['event_invitation_content_type'] = [
    '#type' => 'select',
    '#title' => t('Event invitation content type'),
    '#description' => t('Choose content type to event invitation'),
    '#options' => $types,
    '#default_value' => $selected_type,
    '#ajax' => [
      'callback' => 'event_invitation_load_type_fields',
      'wrapper' => 'fields-container-replace',
    ],
    '#required' => TRUE,
  ];

  $form['event_invitation_domain'] = [
    '#type' => 'textfield',
    '#title' => t('Invitation domain'),
    '#default_value' => variable_get('event_invitation_domain', ''),
  ];

  // Get all fields of selected content type.
  $type_fields = event_invitation_get_fields_to_type($selected_type);
  array_unshift($type_fields, ' - ' . t('Choose') . ' - ');

  $form['fields'] = [
    '#type' => 'fieldset',
    '#collapsed' => FALSE,
    '#title' => t('Fields to send on the invitation'),
    '#prefix' => '<div id="fields-container-replace">',
    '#suffix' => '</div>',
  ];

  $form['fields']['event_invitation_date_field'] = [
    '#type' => 'select',
    '#title' => t('Date'),
    '#description' => t('Select which field will be sent as the invitation date, the field must be of type date'),
    '#options' => $type_fields,
    '#default_value' => variable_get('event_invitation_date_field', ''),
    '#required' => TRUE,
  ];

  $form['fields']['event_invitation_desc_field'] = [
    '#type' => 'select',
    '#title' => t('Description'),
    '#description' => t('Select which text field will be sent as the invitation description.'),
    '#options' => $type_fields,
    '#default_value' => variable_get('event_invitation_desc_field', ''),
  ];

  $form['fields']['event_invitation_location_field'] = [
    '#type' => 'select',
    '#title' => t('Location'),
    '#description' => t('Select which field will be sent as the invitation location. the field must be of type addressfield'),
    '#options' => $type_fields,
    '#default_value' => variable_get('event_invitation_location_field', ''),
  ];

  // Show disabled subject field, to explain user that subject is the title.
  $form['fields']['inv_subject_field'] = [
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Subject will be always the content title'),
    '#default_value' => t('Title'),
    '#disabled' => TRUE,
  ];

  $form['#submit'][] = 'event_invitation_admin_settings_submit';
  return system_settings_form($form);
}

/**
 * Ajax callback to update fields selects by selected content type.
 */
function event_invitation_load_type_fields($form, &$form_state) {
  return $form['fields'];
}

/**
 * Helper function to map types array.
 */
function event_invitation_map_types(&$result, $item) {
  $result[$item->type] = $item->name;
  return $result;
}

/**
 * Validation of event invitation settings form.
 */
function event_invitation_admin_settings_validate($form, &$form_state) {
  // Check if selected content type has field of type date.
  if (isset($form_state['values']['event_invitation_content_type'])) {
    $fields = field_info_instances('node', $form_state['values']['event_invitation_content_type']);
    // Seperate keys and values to future use.
    $keys = array_keys($fields);
    $fields = array_values($fields);
    for ($i = 0; $i < count($fields) && $fields[$i]['widget']['module'] !== 'date'; $i++) {

    }
    if ($i == count($fields)) {
      form_set_error('event_invitation_content_type', t('Please choose content type that contains field of type date'));
    }
  }
  // Return the fields array to key value structure.
  $fields = array_combine($keys, $fields);
  // Check if the selected date field is of type date.
  if (isset($form_state['values']['event_invitation_location_field']) &&
    $field_name = $form_state['values']['event_invitation_location_field']) {
    $field_name = $form_state['values']['event_invitation_location_field'];
    if ($fields[$field_name]['widget']['module'] !== 'addressfield') {
      form_set_error('event_invitation_location_field', t('Location field must by of type addressfield'));
    }
  }
  // Check if the selected date field is of type addressfield.
  if (isset($form_state['values']['event_invitation_date_field'])) {
    $field_name = $form_state['values']['event_invitation_date_field'];
    if ($fields[$field_name]['widget']['module'] !== 'date') {
      form_set_error('event_invitation_date_field', t('Date field must be of type date'));
    }
  }
  // Check that description field is of type string.
  if (isset($form_state['values']['event_invitation_desc_field']) &&
    $field_name = $form_state['values']['event_invitation_desc_field']) {
    if ($fields[$field_name]['widget']['module'] !== 'text') {
      form_set_error('event_invitation_desc_field', t('Description field must by of type text'));
    }
  }
}

/**
 * Submit function to add instance of field send invitation to selected type.
 */
function event_invitation_admin_settings_submit($form, &$form_state) {
  $prev_type = variable_get('event_invitation_content_type', '');
  if ($prev_type !== $form_state['values']['event_invitation_content_type']) {
    // Create new instance.
    if (!field_info_instance('node', 'field_send_invitation', $form_state['values']['event_invitation_content_type'])) {
      event_invitation_create_field_instance($form_state['values']['event_invitation_content_type']);
    }
    // Remove the instance from previous type.
    if ($prev_type) {
      event_invitation_remove_prev_instance($prev_type);
    }
  }
}

/**
 * Create instance of field send invitation on given type.
 */
function event_invitation_create_field_instance($bundle) {
  $instance = array(
    'bundle' => $bundle,
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'block_sidebar' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'fences_wrapper' => 'div',
    'field_name' => 'field_send_invitation',
    'label' => 'שליחת זימון לאירוע',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 41,
    ),
  );
  field_create_instance($instance);
}

/**
 * Remove instance of field_send_invitation from the prev invitation bundle.
 */
function event_invitation_remove_prev_instance($bundle) {
  if ($instance = field_info_instance('node', 'field_send_invitation', $bundle)) {
    // Remove the instance.
    field_delete_instance($instance);
    // Remove the saved data.
    field_purge_batch(EVENT_INVITATION_BATCH_SIZE);
  }
}

/**
 * Get all fields of given content type.
 *
 * @param string $type
 *   Content type name to get all its fields.
 *
 * @return array
 *   Associative array keyed with the field name and the field label as
 *   the value.
 */
function event_invitation_get_fields_to_type($type) {
  $fields = field_info_instances('node', $type);
  $fields = array_reduce($fields, 'event_invitation_map_fields', array());
  return $fields;
}

/**
 * Helper function to map fields array.
 */
function event_invitation_map_fields(&$result, $item) {
  $result[$item['field_name']] = $item['label'];
  return $result;
}

<?php

/**
 * @file
 * Contains page callbacks for Gov IL OG Notifications module.
 */

function govil_og_notify_form($form, &$form_state, $group_type, $gid) {

  // Set the title of the page.
  $entity_wrapper = entity_metadata_wrapper($group_type, $gid);
  $entity_label = $entity_wrapper->label() ? $entity_wrapper->label() : $group_type . ' ' . $gid;
  drupal_set_title(t('Configure notifications for') . " " . $entity_label, PASS_THROUGH);
  // Set the breadcrumb.
  og_set_breadcrumb($group_type, $gid, array(l(t('Group'), "$group_type/$gid/group")));

  $form['#prefix'] = '<div id="notifications-form">';
  $form['#suffix'] = '</div>';

  $form['notifications'] = array(
    '#type' => 'fieldset',
    '#title' => t('Manage Notifications'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['notifications']['gid'] = array('#type' => 'hidden', '#value' => $gid);

  global $user;
  $og_roles = og_get_user_roles('node', $gid, $user->uid);
  $is_group_manager = is_array($og_roles) && in_array("administrator member", $og_roles) ? TRUE : FALSE;
  $uid = !empty($form_state['values']) ? $form_state['values']['uid'] : $user->uid;

  if ($is_group_manager) {
    $form['notifications']['uid'] = array(
      '#type' => 'select',
      '#title' => t('Users'),
      '#options' => array(
        '0'  => t('All members in the group'),
        $user->uid   => t('You'),
      ),
      '#description' => t('Do you want to change setting for you or for all members?'),
      '#default_value' => $uid,
      '#ajax' => array(
        'callback' => 'govil_og_notify_ajax_callback',
        'wrapper' => 'notifications-form',
      ),
    );
  }
  else {
    $form['notifications']['uid'] = array('#type' => 'hidden', '#value' => $uid);
  }

  $default_types = array();
  $frequency = $updates = NULL;
  $result = _govil_og_notify_select_from_db($gid, $uid);
  if ($result->rowCount() == 0) {
    // No have settings
    $default_types[] = 0;
  }
  else {
    foreach ($result as $record) {
      if ($record->state == 1) {
        $default_types =  explode('|', $record->content_type);
      }
      $frequency = $record->frequency;
      $updates = $record->updates;
    }
  }

  $admin = $is_group_manager && $uid == 0 ? TRUE : FALSE;

  $form['notifications'] = array_merge(
    $form['notifications'],
    govil_og_notify_get_form_elements($default_types, $frequency, $updates, $admin)
  );

  $form['notifications']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

function govil_og_notify_get_form_elements($default_types, $frequency, $updates, $admin) {
  $admin = isset($admin) && $admin === TRUE ? '_admin' : '';
  $notifications = array();

  $notifications['content_type' . $admin] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content Type'),
    '#options' => govil_og_notify_types_opts(),
    '#description' => t('Set the content types you want to send.'),
    '#default_value' => $default_types,
    '#multiple' => TRUE,
  );

  $notifications['frequency' . $admin] = array(
    '#type' => 'select',
    '#title' => t('Frequency'),
    '#options' => array(
      FREQUENCY_ONLINE  => t('Online'),
      FREQUENCY_DAILY   => t('Daily'),
      FREQUENCY_WEEKLY  => t('Weekly'),
      FREQUENCY_MONTHLY => t('Monthly'),
    ),
    '#description' => t('What is the frequency you want?'),
    '#default_value' => isset($frequency) ? $frequency : FREQUENCY_DAILY,
  );

  $notifications['updates' . $admin] = array(
    '#type' => 'select',
    '#title' => t('Update'),
    '#options' => array(
      UPDATE_ALL => t('All'),
      UPDATE_NEW => t('New'),
      UPDATE_OLD => t('Updated'),
    ),
    '#description' => t('Do you want to get notification about new or updated content?'),
    '#default_value' => !empty($updates) ? $updates : UPDATE_ALL,
  );

  return $notifications;
}

function govil_og_notify_ajax_callback($form, $form_state) {
  return $form;
}

/**
 * Submit handler for og_menu_menu_overview_form().
 */
function govil_og_notify_form_submit($form, &$form_state) {
  $form_content_type = isset($form_state['values']['content_type']) ? $form_state['values']['content_type'] : $form_state['values']['content_type_admin'];
  $form_frequency = isset($form_state['values']['frequency']) ? $form_state['values']['frequency'] : $form_state['values']['frequency_admin'];
  $form_updates = isset($form_state['values']['updates']) ? $form_state['values']['updates'] : $form_state['values']['updates_admin'];
  if (!is_int($form_content_type['0'])) {
    // If chosen all content types.
    _govil_og_notify_insert_to_db($form_state, array("0"), $form_frequency, $form_updates);
  }
  else {
    $con_types = '';
    foreach (govil_og_notify_types_opts() as $type => $item) {
      if (array_key_exists($type, $form_content_type) && $form_content_type[$type] !== 0) {
        $con_types .= $type . "|";
      }
    }
    $con_types = rtrim($con_types, "|");
    _govil_og_notify_insert_to_db($form_state, $con_types, $form_frequency, $form_updates);
  }
  drupal_set_message(t('Your configuration has been saved.'));
  $form_state['rebuild'] = TRUE;
}

function _govil_og_notify_insert_to_db(&$form_state, $content_type, $frequency, $updates) {
  // If user doesn't choose any content type it means that he doesn't want to get notifications.
  $state = empty($content_type) ? '0' : '1';
  $content_type = is_array($content_type) ? '0' : $content_type;
  db_merge('govil_og_notify')
    ->key(array(
      'gid' => $form_state['values']['gid'],
      'uid' => $form_state['values']['uid'],
      ))
    ->fields(array(
      'content_type' => $content_type,
      'updates' => $updates,
      'frequency' => $frequency,
      'state' => $state,
    ))
    ->execute();
}

function govil_og_notify_types_opts() {
  $all_types = node_type_get_names();
  $allowed_types = variable_get('govil_og_notify_content_types', NULL);
  $options = array('0' => t('All'));
  if (!empty($allowed_types)) {
    foreach ($allowed_types as $key => $value) {
      if ($value != '0') {
        $options[$key] = $all_types[$key];
      }
    }
  }
  else {
    $options += $all_types;
  }
  return $options;
}

function _govil_og_notify_select_from_db($gid, $uid) {
  // Select settings of specific user if exists.
  $query = db_select('govil_og_notify', 'gn')
    ->condition('gn.gid', $gid, '=')
    ->condition('gn.uid', $uid, '=')
    ->fields('gn');
  $result = $query->execute();
  if ($result->rowCount() > 0 || $uid == 0) {
    return $result;
  }
  // Select settings of all group.
  $query = db_select('govil_og_notify', 'gn')
    ->condition('gn.gid', $gid, '=')
    ->condition('gn.uid', 0, '=')
    ->condition('gn.state', 1, '=')
    ->fields('gn');
  return $query->execute();
}

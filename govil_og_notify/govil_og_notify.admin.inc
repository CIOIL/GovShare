<?php

/**
 * @file
 * Gov IL OG Notifications Configuration Page.
 */

/**
 * Implements hook_form().
 */
function govil_og_notify_admin_settings($form, &$form_state) {
    $form = [];

    $form['govil_og_notify_content_types'] = [
        '#type' => 'checkboxes',
        '#title' => t('Content Types for notifications'),
        '#description' => t('Set the content types you want to allow to use in notifications form.'),
        '#options' => node_type_get_names(),
        '#default_value' => variable_get('govil_og_notify_content_types', NULL),
        '#required' => TRUE,
    ];

    $options = [
        FREQUENCY_ONLINE => t('online'),
        FREQUENCY_DAILY => t('daily'),
        FREQUENCY_WEEKLY => t('weekly'),
        FREQUENCY_MONTHLY => t('monthly'),
    ];
    $form['govil_og_notify_default_send'] = [
      '#type' => 'radios',
      '#title' => t('Default frequency'),
      '#description' => t('Set the frequency you want to send notifications at.'),
      '#default_value' => variable_get('govil_og_notify_default_send', FREQUENCY_DAILY),
      '#options' => $options,
    ];

    $form['govil_og_notify_log'] = [
        '#type' => 'checkbox',
        '#title' => t('Test Notifications'),
        '#description' => t('The system will print status in log when notifications are sending.'),
        '#default_value' => variable_get('govil_og_notify_log', FALSE),
    ];

    $form['#submit'][] = 'govil_og_notify_admin_settings_submit';
    return system_settings_form($form);
}

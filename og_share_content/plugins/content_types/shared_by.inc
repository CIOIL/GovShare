<?php

/**
 * @file
 * Plugin that add a message in a shared node.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Shared by msg'),
  'description' => t('Show the group name that share this page.'),
  'category' => t('Miscellaneous'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
  'render callback' => 'og_share_content_render_custom_pane',
);

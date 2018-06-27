<?php

/**
 * @file
 * govil_wiki.inc
 */

include_once 'govil_wiki.views_default.inc';

/**
 * Implements hook_views_api().
 */
function govil_wiki_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function govil_wiki_node_info() {
  $items = array(
    'wiki_page' => array(
      'name' => t('Wiki page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Page name'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Enable wysiwyg footnote button.
 */
function govil_wiki_enable_wysiwyg_footnote() {
  $settings = db_select('wysiwyg', 'w')
    ->fields('w', array('settings'))
    ->condition('format', 'full_html')
    ->execute()->fetchField();
  $settings = unserialize($settings);
  $settings['buttons']['footnotes'] = ['footnotes' => 1];

  // Insert new profile data.
  db_merge('wysiwyg')
    ->key(array('format' => 'full_html'))
    ->fields(array(
      'settings' => serialize($settings),
    ))
    ->execute();
  // Clear the cache, to see the change.
  cache_clear_all();
}

/**
 * Enable some filters in full html text format.
 */
function govil_wiki_enable_text_filters() {
  $format_id = 'full_html';
  $format = filter_format_load($format_id);
  // Load filters.
  $filters = filter_list_format($format_id);
  foreach ($filters as $filter_id => $filter_opts) {
    $format->filters[$filter_id] = (array) $filter_opts;
  }
  // Add wiki filters.
  $format->filters['edit_section_filter'] = array(
    'weight' => -50,
    'status' => 1,
    'settings' => array(),
  );

  $format->filters['filter_footnotes'] = array(
    'weight' => -49,
    'status' => 1,
    'settings' => array(
      'footnotes_collapse' => 1,
    ),
  );
  $format->filters['freelinking'] = array(
    'weight' => -44,
    'status' => 1,
    'settings' => array(),
  );
  filter_format_save($format);
}

/**
 * Enable freelinking to all content types.
 */
function govil_wiki_define_freelinking() {
  $node_types = node_type_get_types();
  $node_types = array_keys($node_types);
  variable_set('freelinking_nodetitle_linkcontenttype', array_combine($node_types, $node_types));
}

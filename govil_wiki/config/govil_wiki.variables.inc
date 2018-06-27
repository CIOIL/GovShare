<?php

/**
 * @file
 * Gov_wiki_components.strongarm.inc.
 */

/**
 * Implements hook_strongarm().
 */
function govil_wiki_update_variables($function) {
  $export = array();

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'comment_anonymous_wiki_page';
  $variable->value = 0;
  $export['comment_anonymous_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'comment_default_mode_wiki_page';
  $variable->value = 1;
  $export['comment_default_mode_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'comment_default_per_page_wiki_page';
  $variable->value = '50';
  $export['comment_default_per_page_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'comment_form_location_wiki_page';
  $variable->value = 1;
  $export['comment_form_location_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'comment_preview_wiki_page';
  $variable->value = '1';
  $export['comment_preview_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'comment_subject_field_wiki_page';
  $variable->value = 1;
  $export['comment_subject_field_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'comment_wiki_page';
  $variable->value = '1';
  $export['comment_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'diff_enable_revisions_page_node_wiki_page';
  $variable->value = 1;
  $export['diff_enable_revisions_page_node_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'diff_show_preview_changes_node_wiki_page';
  $variable->value = 1;
  $export['diff_show_preview_changes_node_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'diff_view_mode_preview_node_wiki_page';
  $variable->value = 'full';
  $export['diff_view_mode_preview_node_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'extlink_target';
  $variable->value = '_blank';
  $export['extlink_target'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'field_bundle_settings_node__wiki_page';
  $variable->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '40',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'og_menu' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'language_content_type_wiki_page';
  $variable->value = '0';
  $export['language_content_type_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'node_options_wiki_page';
  $variable->value = array(
    0 => 'revision',
    1 => 'revision_moderation',
  );
  $export['node_options_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'node_preview_wiki_page';
  $variable->value = '1';
  $export['node_preview_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'node_submitted_wiki_page';
  $variable->value = 1;
  $export['node_submitted_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'pathauto_node_wiki_page_pattern';
  $variable->value = '[node:og-group-ref]/wiki/[node:title]';
  $export['pathauto_node_wiki_page_pattern'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'revisioning_auto_publish_wiki_page';
  $variable->value = 1;
  $export['revisioning_auto_publish_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'revisioning_in_views_show_unpublished_content_terms';
  $variable->value = 0;
  $export['revisioning_in_views_show_unpublished_content_terms'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'tableofcontents_nodetype_toc_automatic_wiki_page';
  $variable->value = '99';
  $export['tableofcontents_nodetype_toc_automatic_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'tableofcontents_nodetype_toc_remove_from_teaser_wiki_page';
  $variable->value = 1;
  $export['tableofcontents_nodetype_toc_remove_from_teaser_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'tableofcontents_nodetype_toc_vtoc_wiki_page';
  $variable->value = 1;
  $export['tableofcontents_nodetype_toc_vtoc_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'tableofcontents_remove_from_teaser_wiki_page';
  $variable->value = 1;
  $export['tableofcontents_remove_from_teaser_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'tableofcontents_toc_automatic_wiki_page';
  $variable->value = '99';
  $export['tableofcontents_toc_automatic_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'tableofcontents_vtoc_wiki_page';
  $variable->value = 1;
  $export['tableofcontents_vtoc_wiki_page'] = $variable;

  $variable = new stdClass();
  $variable->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $variable->api_version = 1;
  $variable->name = 'freelinking_nodetitle_linkcontenttype';
  $variable->value = ['webform' => 'webform'];
  $export['freelinking_nodetitle_linkcontenttype'] = $variable;

  foreach ($export as $name => $object) {
    $function($name, $object->value);
  }
}

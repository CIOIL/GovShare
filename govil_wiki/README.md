CONTENTS OF THIS FILE
---------------------
   
 * Introduction
 * Requirements
 * Installation
 * Configuration
 * Maintainers


INTRODUCTION
------------

Govil wiki is a drupal module that adds wiki content type with some settings 
to get a more wiki-like behavior:
* manage wiki revisions by the creator .
* new role of trusted member - that also can publish and revert revisions. 
* easily add footnotes and freelinks to your content.
* option to add toc (table of content) on the top wiki page.
* edit every section on the page separately.

This module works with og (organic groups) module:
Wiki page is og  group, and also og group content, 
and it inherits the members with roles and permission from the parent group.

After you installed and configured module, you can add wiki page, 
and use rich text format (full html) with the added options.
the wiki page editing will be open to all group members,
under the control of wiki creator - that will be have to 
confirm the publication of the edited content.

If the wiki creator wants to lock the page from editing, he can lock it from wiki node edit page.
('Lock the page for editing')


REQUIREMENTS
------------

No special requirements


INSTALLATION
------------

  * Install as you would normally install a contributed Drupal module. See:
    https://drupal.org/documentation/install/modules-themes/modules-7 for
    further information.
  
  * Run the patches from this module 'patches' directory, 
  that parted to sub direcories by module name to patch.
  Note that the path of files in the patch files is 
  'sites/all/modules/contrib/module', 
  check if the path is correct from your site.

  * Enable the Govil wiki module.
  * Grant permission of use text format full_html to which role you want  
  to edit the wiki pages.
  * Set these premissions on og group permissions 
  (on the groups content types in the site) grant permissions 
  at least to administrator.
    - update any wiki page content : to which role you want to edit the wiki 
    pages.
    - revert revisions
    - Access publishing options of Wiki page content
    - View any unpublished Wiki page content
    - Publish revisions of any Wiki page content
  

Author
------
Israel Government.

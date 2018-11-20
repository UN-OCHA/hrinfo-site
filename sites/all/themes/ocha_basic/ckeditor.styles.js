/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if (typeof(CKEDITOR) !== 'undefined') {
  CKEDITOR.addStylesSet('drupal',
    [
      /* Block Styles */

      // These styles are already available in the "Format" drop-down list, so they are
      // not needed here by default. You may enable them to avoid placing the
      // "Format" drop-down list in the toolbar, maintaining the same features.

      {name: 'Paragraph', element: 'p'},
      {name: 'Heading 1', element: 'h1'},
      {name: 'Heading 2', element: 'h2'},
      {name: 'Heading 3', element: 'h3'},
      {name: 'Heading 4', element: 'h4'},
      {name: 'Heading 5', element: 'h5'},
      {name: 'Heading 6', element: 'h6'},
      {name: 'Preformatted Text', element: 'pre'},
      {name: 'Address', element: 'address'}

    ]);
}
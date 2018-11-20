<?php

/**
 * @file
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $sort_by: The select box to sort the view using an exposed form.
 * - $sort_order: The select box with the ASC, DESC options to define order.
 *   May be optional.
 * - $items_per_page: The select box with the available items per page.
 *   May be optional.
 * - $offset: A textfield to define the offset of the view. May be optional.
 * - $reset_button: A button to reset the exposed filter applied.
 *   May be optional.
 * - $button: The submit button for the form.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($q)): ?>
  <?php
  // This ensures that, if clean URLs are off, the 'q' is added first so that
  // it shows up first in the URL.
  print $q;
  ?>
<?php endif; ?>

<?php if (in_array('filter-search_api_views_fulltext', array_keys($widgets))): ?>
  <?php $widget = $widgets['filter-search_api_views_fulltext']; ?>
  <div id="<?php print $widget->id; ?>-wrapper" class="cd-search--inline__form-inner">

    <label for="cd-search" class="element-invisible"><?php print $widget->label; ?></label>
    <input type="search" placeholder="<?php print $widget->label; ?>" name="search" id="edit-search-api-views-fulltext" class="cd-search--inline__input" autocomplete="off">

    <button type="submit" class="cd-search--inline__submit">

      <svg class="icon icon--search">
        <use xlink:href="#search"></use>
      </svg>
      <span class="element-invisible">Search</span>
    </button>

  </div>

<?php endif; ?>

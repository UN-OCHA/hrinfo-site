<?php

/**
 * @file
 * Views field handler for Assessment Registry fields.
 */

/**
 * Views field handler for Assessment Registry fields.
 */
class ocha_assessments_handler_field extends views_handler_field {

  /**
   * Set field_alias and avoid sql-specific query functionality.
   */
  function query() {
    $this->field_alias = $this->real_field;
  }

  /**
   * Return an html link, not plain text.
   */
  function render($values) {
    return $values->title;
  }

}

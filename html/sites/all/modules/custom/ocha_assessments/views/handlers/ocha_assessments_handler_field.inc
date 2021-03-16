<?php

/**
 * @file
 * Views field handler for Assessment Registry fields.
 */

/**
 * Views field handler for Assessment Registry fields.
 */
class OchaAssessmentsHandlerField extends views_handler_field {

  /**
   * Set field_alias and avoid sql-specific query functionality.
   */
  public function query() {
    $this->field_alias = $this->real_field;
  }

  /**
   * Return an html link, not plain text.
   */
  public function render($values) {
    return $values->title;
  }

}

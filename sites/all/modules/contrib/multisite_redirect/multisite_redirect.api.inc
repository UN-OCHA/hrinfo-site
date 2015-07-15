<?php

/**
 * Alter a redirect rule before execution.
 *
 * @param $rule
 */
function hook_redirect_execute_alter(&$rule) {}

function hook_redirect_execute($rule) {}

/**
 * Alter a redirect rule before saving.
 * @param $rule
 */
function hook_redirect_rule_alter(&$rule) {}

function hook_redirect_insert($rule) {}

function hook_redirect_update($rule) {}

function hook_redirect_load($rule) {}

function hook_redirect_delete($rid) {}

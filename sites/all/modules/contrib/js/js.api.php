<?php
/**
 * @file
 * This file contains no working PHP code; it exists to provide documentation
 * for this module's API.
 */

/**
 * Register JS callbacks. Read the documentation for a detailed explanation.
 *
 * @return array
 *   An associative array of callbacks where the key indicates name of the path
 *   callback that the info should be loaded. The value of each path callback
 *   is also an associative array containing the following possible keys:
 *   - callback function: (optional) The function to invoke for this callback.
 *     If omitted, the default function name is: MODULE_js_callback_CALLBACK.
 *   - callback arguments: (optional) Select which arguments from the URL to
 *     pass to the callback. Starting with 0 with the js/[module] stripped from
 *     the path. Please note that 0 will contain the used callback.
 *   - access callback: (optional) The function to invoke for determining
 *     access to the callback. If set, the minimum bootstrap level must be
 *     DRUPAL_BOOTSTRAP_SESSION to ensure proper access validation against the
 *     current user. WARNING: If not set, no access checks are performed at all.
 *     Defaults to "user_access" if the below option (access arguments) has
 *     a value.
 *   - access arguments: (optional) Arguments for the access callback.
 *   - delivery callback: (optional) The function to call to package the results
 *     of the callback function and send it to the browser. Defaults to
 *     js_deliver_json(). Note that this function is called even if the
 *     access checks fail, so any custom delivery callback function should take
 *     that into account. See js_deliver_json() for an example.
 *   - bootstrap: (optional) The bootstrap level Drupal should boot to,
 *     defaults to DRUPAL_BOOTSTRAP_DATABASE. If an access argument/callback or
 *     tokens are used, defaults to DRUPAL_BOOTSTRAP_SESSION.
 *   - includes: (optional) Load additional files from the /includes directory,
 *     without the extension.
 *   - dependencies: (optional) Load additional modules for this callback.
 *   - file: (optional) The file where the callback function is defined.
 *   - path: (optional) The path where the callback function is defined.
 *   - lang: (optional) Boolean to forcefully enable or disable multilingual
 *     support. JS auto-detects the language string in request paths. Set
 *     this option to TRUE to enable translations, if you're not getting the
 *     desired results.
 *   - methods: (optional) The request methods allowed. This must be an array
 *     of string values. If the request does not match any of the allowed
 *     methods defined by the callback, it will be rejected.
 *   - process request: (optional) Process $_REQUEST data and provide them as
 *     matched arguments against the callback's parameter names (or as a single
 *     $data parameter). Defaults to TRUE. If unsure what this does, it's best
 *     to just leave this enabled. See js_process_post_data() for more
 *     information.
 *   - skip init: (optional) Set to TRUE to skip the init hooks. Warning:
 *     This might cause unwanted behavior and should only be disabled with care.
 *   - token: (optional) Use tokens to prevent CSRF attacks. When enabled, the
 *     minimum bootstrap level must be DRUPAL_BOOTSTRAP_SESSION to ensure
 *     proper token validation against the authenticated user. It is strongly
 *     recommended that this is not disabled, otherwise your site will be
 *     susceptible to CSRF attacks and be considered "insecure".
 *   - xhprof: (optional) Flag indicating whether to output the called functions
 *     or methods used in the request determined by XHProf. Note: enabling this
 *     property to TRUE will automatically increase the callback's bootstrap
 *     level to DRUPAL_BOOTSTRAP_FULL. This will allow all enabled modules and
 *     includes to be loaded so the callback can succeed. This property is only
 *     intended to be used for debugging purposes since it will always print out
 *     the used functions via drupal_set_message(). It also requires the
 *     xhprof_enable() and xhprof_disable() functions to be defined (which can
 *     be provided by the XHProf PHP extension).
 *   - xss: (optional) Filters data in drupal_deliver_json() before it's sent to
 *     browser. It is strongly recommended that this is not disabled, otherwise
 *     your site will be susceptible to XSS attacks and be considered
 *     "insecure".
 */
function hook_js_info() {
  // Simple callback definition:
  $callbacks['simple'] = array();

  // Example of a more complex definition:
  $callbacks['complex'] = array(
    'access callback'  => 'my_module_custom_access_check',
    'access arguments' => array(1, 2),
    'bootstrap' => DRUPAL_BOOTSTRAP_SESSION,
    'callback function' => 'my_module_custom_callback_function',
    'callback arguments' => array(1, 2),
    'delivery callback' => 'my_module_custom_delivery_callback',
    'includes' => array('path', 'authorize', 'form'),
    'dependencies' => array('system', 'views'),
    'lang' => TRUE,
    'method' => array('PUT'),
    'skip init' => TRUE,
    'process request' => FALSE,
    'token' => FALSE,
  );
  return $callbacks;
}


/**
 * Register JS server information.
 *
 * @return array
 *   An associative array of servers where the key indicates the machine name of
 *   the server. The value of each server is also an associative array
 *   containing the following possible keys:
 *   - description: (optional) The human readable description for the server.
 *   - label: (optional) The human readable label for the server. Defaults to
 *     the machine name if none is provided.
 *   - regexp: (optional) A regular expression used to match against the
 *     $_SERVER['SERVER_SOFTWARE'] value.
 *   - rewrite: (optional) A string or an array of strings to use for
 *     constructing the rewrite rules specific to the server.
 */
function hook_js_server_info() {
  $base_path = str_replace('/', '\\/', base_path());
  $endpoint = variable_get('js_endpoint', 'js');

  $header = array(
    '###',
    '### Support for https://www.drupal.org/project/js module.',
    '###',
  );

  // Apache.
  $servers['apache'] = array(
    'label' => 'Apache',
    'description' => t('Add the above lines before any existing rewrite rules inside this site\'s Apache <code>.htaccess</code> file.'),
    'rewrite' => $header,
  );
  $servers['apache']['rewrite'][] = "RewriteCond %{REQUEST_URI} ^$base_path([a-z]{2}\\/)?$endpoint\\/.*";
  $servers['apache']['rewrite'][] = "RewriteRule ^(.*)$ js.php?q=$1 [L,QSA]";
  $servers['apache']['rewrite'][] = "RewriteCond %{QUERY_STRING} (^|&)q=((\\/)?[a-z]{2})?(\\/)?$endpoint\\/.*";
  $servers['apache']['rewrite'][] = "RewriteRule .* js.php [L]";

  return $servers;
}

/**
 * Alter allowed tags used in XSS filtering. Uses filter_xss_admin() defaults.
 *
 * @param array $allowed_tags
 *   An array of allowed HTML element tag names, passed by reference.
 *
 * @see filter_xss_admin()
 */
function hook_js_callback_filter_xss_alter(array &$allowed_tags = array()) {
  $allowed_tags[] = 'button';
}

/**
 * A callback hook.
 *
 * @param mixed ...$args
 *   One or more variables that match the snake cased parameters passed in the
 *   request. This is dynamically processed, so if the variable name defined in
 *   the callback's signature does not match any of the parameters passed in
 *   the request, then it will be ignored and passed to the $data parameter.
 * @param array $data
 *   The array of parameters that were passed in the request, but not
 *   automatically matched from the callback's signature.
 *
 * @return array|int
 *   An array of JSON data or a constant representing an internal menu status:
 *   - JS_MENU_NOT_FOUND
 *   - JS_MENU_ACCESS_DENIED
 *   - JS_MENU_SITE_OFFLINE
 *   - JS_MENU_SITE_ONLINE
 *
 * @see hook_js_info()
 * @see js_callback_process_request()
 * @see js_http_response()
 */
function MODULE_js_callback_CALLBACK($args, $data) {
  $json = array();
  $json['content'] = '<p>My content</p>';
  return $json;
}

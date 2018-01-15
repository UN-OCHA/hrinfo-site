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
 *   - callback arguments: (optional) Internal use. Normally, you won't need
 *     to assign any callback arguments as they will automatically be determined
 *     based on the names of passed parameters and callback function signatures.
 *     If set, these static values will be passed to the callback function
 *     before anything else. To automatically "load" arguments, see the "load
 *     arguments" and "process request" properties below.
 *   - capture: (optional) Captures any printed output from the callback.
 *     Normally a callback should return its content, not print it. By default
 *     this property is enabled and will discard any printed output.
 *     See: hook_js_captured_content_alter().
 *   - access callback: (optional) The function to invoke for determining
 *     access to the callback. If set, the minimum bootstrap level must be
 *     DRUPAL_BOOTSTRAP_SESSION to ensure proper access validation against the
 *     current user. WARNING: If not set, no access checks are performed at all.
 *     Defaults to "user_access" if the below option (access arguments) has
 *     a value.
 *   - access arguments: (optional) Internal use. Normally, you won't need
 *     to assign any callback arguments as they will automatically be determined
 *     based on the names of passed parameters and callback function signatures.
 *     If set, these static values will be passed to the callback function
 *     before anything else. To automatically "load" arguments, see the "load
 *     arguments" and "process request" properties below.
 *   - delivery callback: (optional) The function to call to package the results
 *     of the callback function and send it to the browser. Defaults to
 *     js_deliver_json(). Note that this function is called even if the
 *     access checks fail, so any custom delivery callback function should take
 *     that into account. See js_deliver_json() for an example.
 *   - bootstrap: (optional) The bootstrap level Drupal should boot to,
 *     defaults to DRUPAL_BOOTSTRAP_DATABASE. If an access argument/callback or
 *     tokens are used, defaults to DRUPAL_BOOTSTRAP_SESSION. It is important to
 *     keep in mind that, at a bootstrap level below DRUPAL_BOOTSTRAP_FULL, not
 *     every module is loaded, which will affect which hook implementations are
 *     actually called. This must be taken into consideration when writing a
 *     callback implementation, because API usages triggering any kind of
 *     storage write may result in incomplete/corrupt data to be stored. For
 *     instance, loading an entity when entity cache is cold may result in some
 *     data not being loaded and entity cache being corrupt; saving that entity
 *     in subsequent requests may even lead to data loss, if the cache entry was
 *     not refreshed meanwhile.
 *     Note: by default JS Callback intercepts requests via core's Cache API.
 *     When a cache miss is detected, it will automatically perform a full
 *     bootstrap in an attempt to ensure all modules affecting the data to be
 *     cached are loaded. See "cache" property for more info.
 *     This does not, however, solve the general issue where a complex callback
 *     performs a storage write via an API that allows data to be altered via
 *     hook implementations. In cases like this all dependencies need to be
 *     explicitly loaded.
 *     A temporary solution is to raise the bootstrap level to full. However,
 *     this defeats the entire purpose of using this module.
 *     A more permanent solution is to monitor the execution path of a callback
 *     via the "xhprof" integration and ensure all required dependencies are
 *     added to the callback info.
 *   - cache: (optional) Flag indicating whether a full bootstrap should be
 *     performed when detecting a cache miss. Defaults to TRUE. See "bootstrap"
 *     property for more info.
 *   - includes: (optional) Load additional files from the /includes directory,
 *     without the extension.
 *   - dependencies: (optional) Load additional modules for this callback.
 *   - file: (optional) The file where the callback function is defined.
 *   - path: (optional) The path where the callback function is defined.
 *   - lang: (optional) Boolean to forcefully enable or disable multilingual
 *     support. JS auto-detects the language string in request paths. Set
 *     this option to TRUE to enable translations, if you're not getting the
 *     desired results.
 *   - load arguments: (optional) An associative array of key/value pairs where
 *     parameter name is the key and a callback is the value. The callback will
 *     be passed a single argument, the value of the passed parameter. The JS
 *     module automatically detects any "PARAMETER_load" functions that exist
 *     based on if "process request" is enabled and the function explicitly
 *     specifies that parameter in it's callback function signature. For
 *     example: if one of the parameters passed is "node" and the callback
 *     function signature defines a $node argument, then a "node_load" function
 *     will be invoked (if the function exists). Optionally, to disable the
 *     automatic load callback for a parameter, you can set the callback to
 *     FALSE or to disable all automatic "load arguments" processing you may
 *     set FALSE for the entire "load arguments" property.
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
 *   - token: (optional) Generates a token to prevent CSRF attacks for
 *     authenticated users. When enabled, the minimum bootstrap level will be
 *     DRUPAL_BOOTSTRAP_SESSION to ensure proper token validation against the
 *     authenticated user. If the callback is only accessible to authenticated
 *     users, it is strongly recommended that this is not disabled, otherwise
 *     your site could potentially be susceptible to CSRF attacks. If the
 *     callback needs to support both anonymous and authenticated users, then
 *     this should be disable and the responsibility of checking request
 *     validity falls to the callback itself.
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

  /* Example of a more complex definition:

  function my_module_custom_access_check($node = NULL) {
    // Node did not load or is not the right type.
    if (!isset($node) || $node->type !== 'custom_bundle') {
      return FALSE;
    }
    // Node is a fully loaded, determine access based on field value.
    $field = field_get_items('node', $node, 'field_custom_bool_toggle');
    return !!$field[0]['value'];
  }

  function my_module_custom_callback_function($node, $my_custom_param) {
    // Node is fully loaded, retrieve a custom field value.
    $field = field_get_items('node', $node, 'field_custom_field_text');
    return $field[0]['value'];
  }
   */
  $callbacks['complex'] = array(
    'bootstrap' => DRUPAL_BOOTSTRAP_LANGUAGE,
    'access callback'  => 'my_module_custom_access_check',
    'callback function' => 'my_module_custom_callback_function',
    'dependencies' => array('field', 'node', 'system'),
    'skip init' => TRUE,
    'token' => FALSE,
  );
  return $callbacks;
}

/**
 * Allows modules to alter delivery content with captured (printed) output.
 *
 * In some rare instances, some code uses "printable" functions (print,
 * print_r, echo, var_dump, etc.) that outputs directly to the browser. This
 * causes issues when data is encoded and compressed in the delivery callback
 * (e.g. gzip compresses the data returned from the callback, but is appended
 * with the printed output as well, thus resulting in a decoding error in the
 * browser).
 *
 * Instead of just discarding this captured data, this alter hook allows loaded
 * modules (defined by the callback) a chance to alter the delivery content
 * right before it's sent to the browser; in the event that the captured output
 * is useful for some reason.
 *
 * @param mixed $result
 *   The result value from the callback, passed by reference.
 * @param string $captured
 *   The captured output.
 */
function hook_js_captured_content_alter(&$result, $captured) {
  // Pass the captured output to the JSON array right before delivery.
  if (js_delivery_callback() === 'js_deliver_json') {
    $result['captured'] = filter_xss_admin($captured);
  }
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
function MODULE_js_callback_CALLBACK($args, array $data) {
  $json = array();
  $json['content'] = '<p>My content</p>';
  return $json;
}

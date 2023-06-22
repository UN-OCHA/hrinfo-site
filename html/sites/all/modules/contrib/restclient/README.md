RESTClient
==========

Known Issues
------------

None

Overview
--------

Generic API to make REST calls. Includes methods for GET, POST, PUT, DELETE and INDEX.

The module allows you to make REST based requests to web services. It uses drupal_http_request by default but also supports cURL for more advanced configurations, authentication and improved performance. It also includes a debug mode to monitor REST requests and responses using devel's dpm function. As well there is a basic caching system in the works to reduce duplicate requests. This can be disabled globally or on a per-request basis.

Advantages when using cURL
<ul>
  <li>Supports NTLM authentication</li>
  <li>Support for all cURL library options</li>
  <li>Support for HTTP 1.1</li>
  <li>Improved header data parsing</li>
</ul>

This module doesn't really provide anything out of the box. You should install this if another module depends on it or you wish to build against it.

Full API documentation is in the works and will be posted once complete. We're still working out some of the architecture which may affect the API docs.

If you'd like to see any additional features or support for other cURL options please post those requests in the issue queue!

Notes
1. The cURL options for POST data can be set in the call to restclient_post: $variables['data'] is passed through to the cURL library .
2. Supported language plugins are 'header' and 'replace'.
3. The wscall create and update methods can have overrides using $options['create_method'] and $options['update_method']. These overrides can be appended with $options['accept-type'].
4. Cache time override can be set using $option['cache_default_time'].

Installation
------------

1. Download and install RESTClient module
2. (Optional) To enable cURL support, download and install cURL HTTP REQUEST.
    - At the moment, you need the 7.x-restclient-merge branch of cURL HTTP Request. Once the features stabilize the normal release copy will work just fine.
3. (Optional) To enable OAuth2 clients, download and install oauth2_client.

Configuration
-------------

1. Go to admin/config/services/restclient
2. Select your request library (defaults to Drupal)
3. Set your common REST endpoint (this can be overridden per request. This is only the default value.)

Additional Headers
------------------

RESTClient supports adding additional header data to all requests made. You can set this using variable_set() in your code or by adding to your $conf array in settings.php
No additional processing or validation is done on these header values so ensure the data is safe and correct.
Ex:

    $conf['restclient_additional_headers'] = array(
      'MyCustomHeaderName' => 'MyCustomHeaderValue',
    );
    
    
    variable_set('restclient_additional_headers', array('MyCustomHeaderName' => 'MyCustomHeaderValue'));

OAuth headers can be specified directly without using OAuth2 clients. For convenience, OAuth2 clients can be configured and looked up by name as follows:
  1. Install and enable the oauth2_client module.
  2. Configure RESTClient to enable OAuth2 clients.
  3. Define OAuth2 clients in a module by using hook_oauth2_clients as specified in the documentation for oauth2_client.
  4. On a REST request, specify authentication as follows.
     ['authentication']['type'] = 'oauth2_client'
     ['authentication']['oauth2_client'] = <array>
     The array contains values that are passed through to oauth2_client so it can create the client. Alternatively the array can just contain ['name'] = <client_name> to look up an Oauth2 client that is already defined. See oauth2_client documentation for details.
  5. The format for the Authorization request header depends on the server. If needed, the format can be specified as follows. Note that <format> must include :token as a placeholder for the OAuth token. The default format is 'Bearer :token'.
     ['authentication']['oauth_format'] = <format>

Troubleshooting
===============

RESTClient integrates with Devel to allow you to see the request/response object for any request made through RESTClient. To enable this, go to the configuration for RESTClient and enable debug mode.

There is ample logging available. In the configuration turn on 'Enable watchdog logs' and view the logs at <your-site>/admin/reports/dblog.

By default the REST calls return FALSE when an error occurs. To return the contents of the error response set $variables['error_handling'] to TRUE.

There is a file mode for testing. To enable this, go to the configuration for RESTClient and choose 'Testing Files' as the Active Library. Also if desired, enable 'Capture Test Data' to save test output.

Common Issues
-------------

1. No results from requests.

It's possible SELinux is preventing Apache from connecting to the remote host.  To fix this, allow the following:

     allow httpd_t port_t:tcp_socket name_connect;



Sponsored by <a href="http://coldfrontlabs.ca">Coldfront Labs Inc.</a>

Maintained by Mathew Winstone (<a href="http://drupal.org/user/129088">minorOffense</a>) and David Pascoe-Deslauriers (<a href="http://drupal.org/user/657848">spotzero</a>).

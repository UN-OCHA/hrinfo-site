# High-performance JavaScript Callback Handler
> https://www.drupal.org/project/js

---

1. About
2. Performance
3. Technical
4. Installation
5. Module Integration/API
6. Settings
7. Credit


---

### About

JavaScript callback handler is an interim solution for high-performance server 
requests including (but not limited to) AHAH, AJAX, JSON, XML, etc.

Note: this module does nothing by itself. It requires other modules to leverage
its functionality and APIs.


### Performance

Apache benchmarks speak for itself:

Using `index.php` as usual:

```bash
  ab -n20 -c1 http://example.com/index.php?q=js/mymodule/callback
  Requests per second: 2.24 [#/sec] (mean)
  Time per request:    446.846 [ms] (mean)
```

Using `js.php`:

```bash
  ab -n20 -c1 http://example.com/js.php?q=js/mymodule/callback
  Requests per second: 16.84 [#/sec] (mean)
  Time per request:    59.371 [ms] (mean)
```


### Technical

This module is mainly a conditional replacement for Drupal's `index.php` based
on the default supported Apache `.htaccess` rewrite directives.

With `mod_rewrite` enabled (for "clean urls"), it catches all calls to callback
paths starting with `js/` and passes them to a reduced loader instead of
the default `index.php` file.

Invoking only the explicitly defined dependencies instead of a completely
bootstrapped Drupal instance. It saves lots of processing time and thus speeds
up small Ajax requests.


### Installation

* Install as usual (see https://www.drupal.org/node/895232).
* Enable the module.
* Enabling the module should have automatically copied the `js.php` file bundled
  with this module to the root directory of your Drupal installation (the
  directory where your Drupal `.htaccess` and `index.php` is located). If it did
  not, you will need to copy it manually.
* Goto the configuration page: `admin/config/system/js`.
* Choose the type of server rewrite rules to use.
* Copy the rewrite rules and then follow the instructions on where to paste
  them. If your server is not listed or you have a complex infrastructure setup,
  you will need to ensure that any request starting with `/js` is forwarded to
  the `js.php` file.


### Module Integration/API

Please read the `js.api.php` file and look at the `js_callback_examples`
sub-module for more information.


### Settings

There are a few variables that can be set in an appropriate `settings.php` file:

- `js_endpoint`: Configures the expected URL endpoint:  
  ```php
  $conf['js_endpoint'] = 'js';
  ```
- `js_silence_php_errors`: Prevents custom JS module PHP error and exception
  handlers from being invoked. By default, this variable is not set and the
  JS module will automatically handle any PHP error or exception and display
  them (respecting the site's PHP error display configuration) as an error
  type status message via `drupal_set_message()`. To disable this, use:  
  ```php
  $conf['js_silence_php_errors'] = TRUE;
  ```


### Credit

Project page: https://www.drupal.org/project/js

**7.x-2.x**

Authors:
- Mark Carver (https://www.drupal.org/u/markcarver)

**7.x-1.x**

Authors:
- David Herminghaus (https://www.drupal.org/u/doitdave)
- Michiel Nugter (https://www.drupal.org/u/michielnugter)

Sponsors:
- Synetic (http://www.synetic.nl)

**6.x, 5.x**

Authors:
* Daniel F. Kudwien (https://www.drupal.org/u/sun)
* Stefan M. Kudwien (https://www.drupal.org/u/smk-ka)

Sponsors:
- unleashed mind (http://www.unleashedmind.com/)

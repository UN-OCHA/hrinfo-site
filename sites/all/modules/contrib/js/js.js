(function (window, $, undefined) {

  var version = $.fn.jquery.split('.').map(parseFloat);

  /**
   * Method for executing JS callback requests; wraps $.ajax().
   *
   * @param {object} options
   *   The default option to pass to the $.ajax() method.
   *
   * @return {JsAjax}
   */
  var JsAjax = function (options) {
    var
      JS = window.JS,
      host = window.location.origin,
      base = Drupal.settings.basePath || '/',
      prefix = Drupal.settings.pathPrefix || '',
      theme = Drupal.settings.ajaxPageState && Drupal.settings.ajaxPageState.theme || '';

    this.defaults = options || {};
    this.options = options || {};

    // Redirect page immediately if URL is external.
    if (JS.urlIsExternal(this.options.url)) {
      window.location = this.options.url;
      return undefined;
    }

    // Merge in default options.
    this.options = $.extend(true, {
      type: 'GET',
      dataType: 'json',
      data: {
        // Send the current theme being used so returned results can be rendered
        // using the correct theme (if needed).
        js_theme: theme
      },
      $trigger: this.options.$trigger && $(this.options.$trigger) || $()
    }, this.options);

    // Merge in trigger element data attributes as "data" to be passed.
    if (this.options.$trigger[0]) {
      var data = $.extend({}, this.options.$trigger.data());

      // Remove any bound jQuery events.
      if (version[0] === 1 && version[1] < 8) {
        delete data.events;
      }

      // Handle various jQuery versions what is returned from $.fn.data().
      var jsRegExp = /(js)[_-]?([A-Za-z]+)/;
      var ignoreData = [].concat(this.options.$trigger.data('js-ignore-data') || this.options.jsIgnoreData || []);
      for (var i in data) {
        if (!data.hasOwnProperty(i)) {
          continue;
        }
        var match = i.match(jsRegExp);
        if (match) {
          var key = (match[1] + '_' + match[2]).toLowerCase();
          var value = data[i];
          delete data[i];
          data[key] = value;
        }
        if ($.inArray(i, ignoreData) !== -1) {
          delete data[i];
        }
      }
      this.options.data = $.extend(true, this.options.data, data);
    }

    // Normalize url so it excludes the domain and base path.
    this.options.url = this.options.url && this.options.url.replace(new RegExp('^(' + host + ')?(' + base + ')?(' + prefix + ')?', 'i'), '') || '';

    // Force prefix the URL to use the internal JS module callback path. If
    // requests do not want it to be processed by the JS module, then the
    // normal $.ajax() method should be used instead.
    this.options.url = base + prefix + 'js/' + (this.options.url ? this.options.url : '');

    // Normalize data keys to Drupal variable standards.
    JS.snakeCaseObject(this.options.data);

    // Execute the request using $.ajax().
    this.jqXHR = $.ajax(this.options);

    return this;
  };

  /**
   * Internal AJAX handler.
   *
   * Iterates over each JS.behavior and fires the appropriate method if it
   * exists.
   *
   * @param {string} type
   *   The type of event, should be one of: beforeSend, error, success or
   *   complete.
   * @param {Event} event
   *   The native Event object.
   * @param {XMLHttpRequest} jqXHR
   *   The jQuery XMLHttpRequest object.
   * @param {object} options
   *   The jQuery AJAX options.
   */
  var JsAjaxBehaviors = function (type, event, jqXHR, options) {
    var JS = window.JS;
    // Ensure on JS module requests are processed.
    if (!!options.url.match(new RegExp('^' + Drupal.settings.basePath + Drupal.settings.pathPrefix + (Drupal.settings.jsEndpoint || 'js')))) {
      // Older versions of jQuery do not have jqXHR.responseJSON, we must parse
      // the responseText manually.
      var json = options.dataType === 'json' && jqXHR.responseText && $.parseJSON(jqXHR.responseText) || {};

      // Process our own internal events (so they cannot be overridden).
      switch (type) {
        case 'beforeSend':
          JS.messages.html('');
          this.ajaxing = true;
          this.redirecting = false;
          options.$trigger.removeClass('error').addClass('ajaxing disabled');
          if ($.fn.prop) {
            options.$trigger.prop('disabled', true);
          }
          else {
            options.$trigger.attr('disabled', 'disabled');
          }
          break;

        case 'error':
        case 'success':
          // Response was redirected, pass this response onto the redirect handler.
          if (json.response && json.response.code && json.response.url && $.inArray(json.response.code, [301, 302, 303, 307]) !== -1) {
            // Only redirect requests internally if the origin matches (or forced).
            if (!json.response.force && new RegExp('^' + window.location.origin).test(json.response.url)) {
              this.redirecting = true;
              // Redirects do not process any information, change the type back to
              // GET, remove the data and set the new URL.
              this.defaults.type = 'GET';
              this.defaults.data = {};
              this.defaults.url = json.response.url;
              JS.ajax(this.defaults);
            }
            // Otherwise redirect the entire page.
            else {
              window.location = json.response.url;
            }
            // A redirection has occurred, return immediately.
            return;
          }

          // Merge in any request JS settings.
          if (json.settings) {
            Drupal.settings = $.extend(true, {}, Drupal.settings, json.settings);
          }

          // Parse and display any Drupal messages set.
          if (json.messages) {
            JS.messages
              .prepend(Drupal.theme('statusMessages', json.messages))
              .trigger('loaded');
          }
          break;

        case 'complete':
          options.$trigger.removeClass('ajaxing disabled');
          if ($.fn.prop) {
            options.$trigger.prop('disabled', false);
          }
          else {
            options.$trigger.removeAttr('disabled');
          }
          break;
      }

      // Iterate over AJAX behaviors.
      var args = [event, jqXHR, options, json];
      for (var i in JS.behaviors) {
        if (JS.behaviors.hasOwnProperty(i) && typeof JS.behaviors[i] === 'object') {
          if (typeof JS.behaviors[i][type] !== 'undefined' && typeof JS.behaviors[i][type] === 'function') {
            JS.behaviors[i][type].apply(this, args);
          }
        }
      }

      // Remove the instance.
      if (type === 'complete') {
        this.ajaxing = false;
        delete JS.instances[options._jsInstance];
      }
    }
  };

  /**
   * Instantiate the global JS object.
   */
  window.JS = window.JS || {
    /**
     * Initiates a new instance of JsAjax; wrapper for $.ajax().
     *
     * @param options
     *   The $.ajax() options to use.
     */
    ajax: function (options) {
      var instance;
      options = options || {};
      // Save this instance using a new identifier.
      options._jsInstance = this.instanceCount++;
      instance = this.instances[options._jsInstance] = new JsAjax(options);
      return instance.jqXHR;
    },

    /**
     * Contains the active JsAjax instances.
     * @type {object}
     */
    instances: {},

    /**
     * A counter for uniquely identifying active JsAjax instances.
     * @type {object}
     */
    instanceCount: 0,

    /**
     * Contains event behaviors to be used during active JsAjax instances.
     * @type {object}
     * @see JsAjaxBehaviors
     */
    behaviors: {},

    /**
     * A placeholder. This is initialized on DOM ready.
     * @type {jQuery}
     */
    messages: $(),

    /**
     * The selector used to identify where messages should be placed.
     *
     * The last selector found (in order of the DOM tree) will be used. Themes
     * can override this with a single specific selector if a guaranteed element
     * will be present.
     *
     * @type {string}
     */
    messagesSelector: 'body, #main, #content, #block-system-main, #messages',

    /**
     * Helper method for processing names and values of form elements.
     *
     * @param {Node|jQuery} element
     *   The DOM node or jQuery element. It can can be a single form element or
     *   if a higher element is passes (like a form), then all input elements
     *   found inside it will be added to the data array.
     *
     * @returns {object}
     *   The data to use.
     */
    processFormValues: function (element) {
      var $elements = $(), data = {};
      if ($(element).is(':input')) {
        $elements = $elements.add(element);
      }
      else {
        $elements = $elements.add($(element).find(':input'));
      }
      $elements.each(function () {
        var $input = $(this);
        var name = $input.attr('name') || $input.attr('id') || null;
        var value = $input.is(':checkbox') ? ($input.is(':checked') ? $input.val() : 0) : $input.val();
        if (name) {
          data[name] = value;
        }
      });
      return data;
    },

    /**
     * Converts object keys from jsonLowerCamelCase to drupal_php_snake_case.
     *
     * @param {object} obj
     *   The object to iterate over.
     */
    snakeCaseObject: function (obj) {
      var self = this;

      $.each(obj, function (key, value) {
        // Remove functions entirely.
        if ($.isFunction(value)) {
          value = null;
          delete obj[key];
          return;
        }

        // Type cast key to a string.
        key = (key + '');

        // Snake case the key, if necessary.
        var snakeCaseKey = key.replace(/([A-Z])/g, '_$1').toLowerCase();
        if (snakeCaseKey !== key) {
          delete obj[key];
          key = snakeCaseKey;
        }

        // Sanitize the value, recurse if an object or array.
        value = $.isPlainObject(value) || $.isArray(value) ? self.snakeCaseObject(value) : Drupal.checkPlain(value);

        // Store the value.
        obj[key] = value;
      });

      return obj;
    },

    /**
     * Helper function for determining whether a URL is of same origin.
     *
     * @param {string} url
     *   The URL to test. It can be a FQDN (fully qualified domain name),
     *   relative or empty.
     *
     * @return {bool}
     *
     * @see http://stackoverflow.com/a/6238456
     */
    urlIsExternal: function (url) {
      url = url || '';
      var match = url.match(/^([^:\/?#]+:)?(?:\/\/([^\/?#]*))?([^?#]+)?(\?[^#]*)?(#.*)?/);
      if (match && typeof match[1] === "string" && match[1].length > 0 && match[1].toLowerCase() !== window.location.protocol) return true;
      return (match && typeof match[2] === "string" && match[2].length > 0 && match[2].replace(new RegExp(":("+{"http:":80,"https:":443}[window.location.protocol]+")?$"), "") !== window.location.host);
    }

  };

  /**
   * Register global events.
   */
  $(document)
    // jQuery AJAX events.
    .ajaxSend(function(event, jqXHR, options) {
      var JS = window.JS;
      if (options._jsInstance !== undefined) {
        JsAjaxBehaviors.apply(JS.instances[options._jsInstance], ['beforeSend', event, jqXHR, options]);
      }
    })
    .ajaxError(function(event, jqXHR, options) {
      var JS = window.JS;
      if (options._jsInstance !== undefined) {
        JsAjaxBehaviors.apply(JS.instances[options._jsInstance], ['error', event, jqXHR, options]);
      }
    })
    .ajaxSuccess(function(event, jqXHR, options) {
      var JS = window.JS;
      if (options._jsInstance !== undefined) {
        JsAjaxBehaviors.apply(JS.instances[options._jsInstance], ['success', event, jqXHR, options]);
      }
    })
    .ajaxComplete(function (event, jqXHR, options) {
      var JS = window.JS;
      if (options._jsInstance !== undefined) {
        JsAjaxBehaviors.apply(JS.instances[options._jsInstance], ['complete', event, jqXHR, options]);
      }
    })
    // Attach the messages element when the DOM is ready.
    .ready(function () {
      var JS = window.JS;
      JS.messages = $('<div class="js-messages"></div>').prependTo($(JS.messagesSelector).last());
    });

  /**
   * jQuery plugin for a JS Callback.
   *
   * @param {string|object} module
   *   The module name the callback resides in.
   * @param {string|object} [callback]
   *   The specific callback to invoke.
   * @param {object} [options]
   *   Any additional options to pass to the jQuery.ajax() call.
   *
   * @return {jQuery}
   *   The chainable jQuery object.
   */
  $.fn.jsCallback = function (module, callback, options) {
    var $this = $(this), JS = window.JS;
    options = (typeof module === 'object' && module) || (typeof callback === 'object' && callback) || (typeof options === 'object' && options) || {};
    module = typeof module === 'string' && module || null;
    callback = typeof callback === 'string' && callback || null;
    // Ensure that our default data does not get overridden.
    var data = $.extend(true, {
      js_module: module,
      js_callback: callback,
      js_token: (module && callback && Drupal.settings.js && Drupal.settings.js.tokens && Drupal.settings.js.tokens[module + '-' + callback]) || ''
    }, options.data);
    JS.ajax($.extend(true, {
      type: 'POST',
      data: data,
      $trigger: $this
    }, options));
    return $this;
  };

  /**
   * jQuery plugin for returning the contents of an internal URL.
   *
   * Any URL passed or extracted will be filtered for external sites. It can be
   * relative to the domain's root or absolute. If, however, the URL is
   * considered external the browser will automatically redirect and no AJAX
   * request will be invoked.
   *
   * Below are optional arguments you can pass to this method. If none are
   * passed, then this method will attempt to extract the URL from the element
   * itself. Only "a[href]" elements can be used for URLs. If the element has a
   * "[data-target]" attribute, it will be used to extract the "a[href]" value
   * of that target instead. If the current element is both "a[href]" and
   * "a[data-target]", then the "a[href]" value of the target will be used
   * instead. If no URL can be extracted, then the AJAX call is not invoked.
   *
   * @param {string|object} [url]
   *   If passed argument is a string, this is the internal URL to retrieve.
   *   If passed argument is an object, it will be used as options (see below).
   * @param {object} [options]
   *   Any additional options to pass to the jQuery.ajax() call.
   *
   * @return {jQuery}
   *   The chainable jQuery object.
   */
  $.fn.jsGet = function (url, options) {
    var $this = $(this), JS = window.JS;
    options = (typeof url === 'object' && url) || (typeof options === 'object' && options) || {};
    url = typeof url === 'string' && url || undefined;
    var $target = $($this.data('target'));
    if (!url && ($this.is('a[href]') || $target.length)) {
      url = $target.attr('href') || $this.attr('href') || undefined;
    }
    if (url) {
      JS.ajax($.extend(true, {
        url: url,
        $trigger: $this
      }, options));
    }
    return $this;
  };

  /**
   * jQuery plugin for processing form requests.
   *
   * @param {object} [options]
   *   Any additional options to pass to the jQuery.ajax() call.
   *
   * @return {jQuery}
   *   The chainable jQuery object.
   */
  $.fn.jsForm = function (options) {
    var $form = $(this), JS = window.JS;
    if (!$form.is('form')) {
      return $form;
    }
    options = typeof options === 'object' && options || {};
    var $trigger = $();
    $form.find(':button').bind('click', function () {
      $trigger = $(this);
    });
    $form.bind('submit', function (e) {
      // Prevent the form submission.
      e.preventDefault();

      // Get form values.
      var data = JS.processFormValues($form);

      // Override the module and callback values so we process this internally.
      data['js_module'] = 'js';
      data['js_callback'] = 'form';

      // Override op submitted.
      if ($trigger.is('[name=op]')) {
        data.op = $trigger.val();
      }

      // Send the request.
      JS.ajax($.extend(true, {
        type: $form.attr('method').toUpperCase(),
        url: $form.attr('action'),
        data: data,
        $trigger: $trigger
      }, options));
    });
    return $form;
  };

  /**
   * Core template for theming status messages.
   */
  Drupal.theme.prototype.statusMessages = function (messages) {
    var output = '';
    var status_heading = {
      status: Drupal.t('Status message'),
      error: Drupal.t('Error message'),
      warning: Drupal.t('Warning message')
    };
    for (var type in messages) {
      if (!messages.hasOwnProperty(type)) {
        continue;
      }
      if (messages[type].length > 0) {
        output += "<div class=\"messages " + type + "\">\n";
        if (typeof(status_heading[type]) !== 'undefined') {
          output += '<h2 class="element-invisible">' + status_heading[type] + "</h2>\n";
        }
        if (messages[type].length > 1) {
          output += " <ul>\n";
          for (var i in messages[type]) {
            output += '  <li>' +  messages[type][i] + "</li>\n";
            // Remove the message from the array so it's not processed again.
            delete messages[type][i];
          }
          output += " </ul>\n";
        }
        else {
          output += messages[type][0];
        }
        output += "</div>\n";
      }
    }
    return output;
  };

})(window, window.jQuery);

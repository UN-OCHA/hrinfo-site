(function ($) {

  /**
   * Drupal behavior.
   */
  Drupal.behaviors.jsExample = {
    attach: function (context, settings) {
      var $context = $(context);

      // Stop form execution.
      var $form = $context.find('#js-callback-examples-form');
      $form.once('example', function () {
        $form.bind('submit', function (e) {
          e.preventDefault();
          e.stopPropagation();
        });
        // Make pressing "enter" trigger a click on the nearest callback.
        // @todo Make this attachable somehow?
        $form.find('input[type=text]').bind('keypress', function (e) {
          if (e.keyCode == 13) {
            $(this).closest('[data-js-callback]').trigger('click');
          }
        });
      });

      /**
       * Using #js_callback and $.fn.jsCallback().
       *
       * @see js_callback_examples_js_callback_get_uid()
       */
      $context.find('[data-js-type=callback]').once('js-callback-example', function () {
        var $container = $(this);
        var $callback = $container.find('[data-js-callback]');
        var $values = $container.find(':input');
        var $results = $container.find('.results');
        var $output = $results.find('pre code');

        // Bind click.
        $callback.bind('click', function (e) {
          // Prevent default behavior.
          e.preventDefault();
          e.stopPropagation();

          // Execute the callback.
          $callback.jsCallback({
            data: JS.processFormValues($values),
            beforeSend: function () {
              $output.html('');
            },
            error: function () {
              $output.html('An error occurred!');
            },
            success: function (json) {
              if (json.content) {
                $output.html(json.content);
              }
            },
            complete: function () {
              // Move message right before $text container element.
              // @todo Make this attachable somehow?
              $results.prepend(JS.messages);
            }
          });
        });
      });

      /**
       * Using #js_callback and $.fn.jsGet().
       *
       * @see js_callback_examples_js_callback_get_uid()
       */
      $context.find('[data-js-type=get]').once('js-callback-example', function () {
        var $container = $(this);
        var $links = $container.find('a');
        var $results = $container.find('.results');
        var $output = $results.find('pre code');

        $links.bind('click', function (e) {
          // Prevent default behavior.
          e.preventDefault();
          e.stopPropagation();

          var $link = $(this);
          $link.jsGet({
            beforeSend: function () {
              $output.html('');
            },
            error: function () {
              $output.html('An error occurred!');
            },
            success: function (json) {
              if (json.content) {
                $output.html(json.content.replace(/\n+|\s+/g, ' '));
              }
            },
            complete: function () {
              // Move message right before $text container element.
              // @todo Make this attachable somehow?
              $results.prepend(JS.messages);
            }
          });
        });
      });

    }
  };

})(jQuery);

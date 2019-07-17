/**
 * @file
 * Loads the full calendar.
 */

(function($) {
  Drupal.behaviors.fullCalendarApiCalendar = {
    attach: function(context, settings) {
      if (!settings.fullcalendar_api.calendarSettings) {
        return;
      }
      var $calendarId = settings.fullcalendar_api.calendarId;
      var $calendar = $('#' + $calendarId, context);
      if (!$calendar.length) {
        return;
      }

      var $settings = settings.fullcalendar_api.calendarSettings;
      // Merge in event callbacks.
      $.extend($settings, {
        eventDrop: function(event, delta, revertFunc) {

          // Create a simple object to send to ajax function.
          var $data = {
            id: event.id,
            title: event.title,
            entityType: event.entityType ? event.entityType : null,
            bundle: event.bundle ? event.bundle : null,
            allDay: event.allDay,
            dateField: event.dateField,
            startTime: event.start.unix(),
            endTime: event.end ? event.end.unix() : null
          };

          if (!confirm("Are you sure about this change?")) {
            revertFunc();
          }
          else {
            // Save the entity via AJAX.
            $.ajax({
              method: 'POST',
              url: '//' + window.location.hostname +  settings.basePath + settings.pathPrefix + 'fullcalendar-api/ajax/update/drop/' + event.id,
              data: $data
            }).done(function(response){
              // @todo return success?
              if (response == 'failure') {
                revertFunc();
              }
            });
          }

        }
      });

      // Use the hash parameters, if they exist. Hash is of the form:
      //   <viewName>/<ISO-date>
      //   Ex. month/2015-06
      var origHash = window.location.hash;
      if (origHash.length > 1) {
        var params = origHash.substring(1).split('/');
        // @todo validate
        $.extend($settings, {
          defaultView: params[0],
          defaultDate: params[1]
        });
      }

      // Run any custom actions before attaching the calendar.
      $(document, context).trigger('fullCalendarApiCalendar.preprocess', [$calendar, $settings]);
      
      $calendar.fullCalendar($settings);
    } 
  }
})(jQuery);

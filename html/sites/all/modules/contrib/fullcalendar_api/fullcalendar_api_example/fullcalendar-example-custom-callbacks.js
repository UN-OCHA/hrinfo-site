/**
 * @file
 * Example implementing custom callbacks.
 */

(function($) {
  Drupal.behaviors.FullCalendarApiExample = {
    attach: function(context, settings) {

      $(document, context).bind('fullCalendarApiCalendar.preprocess', function(event, calendar, $settings) {
        $.extend($settings, {
          viewRender: function(view, element) {
            // Runs after the view has been fully rendered, but events have 
            // not yet been rendered.
            // @see http://fullcalendar.io/docs/display/viewRender/
            $(calendar, context).find('.fc-day-header').wrapInner('<h1 />');
          }, // end viewRender
          dayClick: function(date, jsEvent, view) {
            // Runs when an event is clicked.
            // @see http://fullcalendar.io/docs/mouse/dayClick/
            alert('Clicked on: ' + date.format() + '\n' +
              'Coordinates: ' + jsEvent.pageX + ',' + jsEvent.pageY + '\n' +
              'Current view: ' + view.name);
            // change the day's background color just for fun
            $(this).css('background-color', 'red');
          }
        });
      });
    }
  }
})(jQuery);

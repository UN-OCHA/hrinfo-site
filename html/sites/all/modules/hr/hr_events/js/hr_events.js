
(function($) {
  Drupal.behaviors.hrEventsDatePopupValue = {
    attach: function (context, settings) {
      // TODO: only bump date2 when it's before date1.
      $('#edit-field-event-date-und-0-value-datepicker-popup-0', context).on('change', function(){ 
          $('#edit-field-event-date-und-0-value2-datepicker-popup-0').val($(this).val());
      });
      $('#edit-field-event-date-und-0-value-timeEntry-popup-1', context).on('change', function(){ 
          $('#edit-field-event-date-und-0-value2-timeEntry-popup-1').val($(this).val());
      });
    }
  };
})(jQuery);

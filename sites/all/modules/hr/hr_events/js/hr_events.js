
(function($) {
  Drupal.behaviors.hrEventsDatePopupValue = {
    attach: function (context, settings) {
      $('#edit-field-event-date-und-0-value-datepicker-popup-0', context).on('change', function(){ 
          $('#edit-field-event-date-und-0-value2-datepicker-popup-0').val($(this).val());
      });
    }
  };
})(jQuery);
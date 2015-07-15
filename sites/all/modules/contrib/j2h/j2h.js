(function ($) {
  Drupal.behaviors.MYMODULE = {
    attach: function (context, settings) {
      // Your Javascript code goes here
        
        // Filters
        $('#reset').click(function(){ 
            location.href = window.location.href.split('?')[0];
        });
    }
  };
}(jQuery));

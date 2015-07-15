(function($) {
  $(document).ready(function() {
    $("#operations-dropdown").chosen().change(function() {
      document.location.href = $("#operations-dropdown").val();
    });
  });
})(jQuery);

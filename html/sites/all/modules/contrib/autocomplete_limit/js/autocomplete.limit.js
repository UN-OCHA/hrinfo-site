(function($) {

  /**
   * Do nothing if there are no autocomplete fields.
   */
  if (Drupal.ACDB) {
    /**
     * Keep an unmodified copy of the core search callback function.
     */
    Drupal.ACDB.prototype.coreSearch = Drupal.ACDB.prototype.search;

    /**
     * Override the search callback.
     *
     * Prevent autocomplete search from running if the search string is shorter
     * than the limit. Otherwise, call the clone of the original search callback.
     */
    Drupal.ACDB.prototype.search = function (searchString) {
      var limit = parseInt($(this.owner.input).data('limit') || Drupal.settings.autocomplete_limit.limit || 0, 10);

      // Do not search if the string is too short.
      if (limit && searchString.length < limit) {
        return;
      }

      // Call the original core search callback.
      return this.coreSearch(searchString);
    };

    // Good night, and good luck.
  }

})(jQuery);

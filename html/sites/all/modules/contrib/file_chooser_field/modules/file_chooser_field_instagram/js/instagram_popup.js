(function ($) {

  /**
   * Instagram File Picker (popup window).
   */

  // Get child element button.
  // This is the button that tirggered the popup.
  var instaButton = window.opener.document.getElementsByClassName('window-id-' + window.self.name);

  var selected = [];

  // Get button attributes.
  var _max_filesize = $(instaButton).data('max-filesize');
  var _description = $(instaButton).data('description');
  var _cardinality = $(instaButton).data('cardinality');
  var _multiselect = $(instaButton).data('multiselect');
  var _disable_select = false;
  $('a#pick').addClass('disabled');

  // Select photos.
  $('#photos a.photo').on('click', function(e) {
    var _photo_index = $(this).data('index');
    var _limit = (_cardinality > 0) ? _cardinality : 100;
    if (_limit > 1) {
      _multiselect = true;
    }
    if (!isInArray(_photo_index, selected)) {
      if (_multiselect) {
        selected.push(_photo_index);
        $(this).addClass('selected');
      }
      else {
        if (selected.length < _limit) {
          selected.push(_photo_index);
          $(this).addClass('selected');
        }
      }
    }
    else {
      var remove_index = selected.indexOf(_photo_index);
      selected.splice(remove_index, 1);
      $(this).removeClass('selected');
    }
    if (selected.length > 0) {
      var selected_message;
      if (selected.length < _limit) {
        _disable_select = false;
      }
      else {
        _disable_select = true;
      }
      if (selected.length == 1) {
        selected_message = '<strong>' + selected.length + '</strong> file selected';
      }
      else {
        selected_message = '<strong>' + selected.length + '</strong> files selected';
      }
      $('#count').html(selected_message);
      $('a#pick').removeClass('disabled');
    }
    else {
      $('a#pick').addClass('disabled');
      $('#count').html('');
    }
    e.preventDefault();
  });

  // Insert into field.
  $('a#pick').on('click', function(e) {
    if (!$(this).hasClass('disabled')) {
      if (selected.length) {
        var _files = [];
        for (var i = 0; i < selected.length; i++) {
          _files.push($('#photos a[data-index="' + selected[i] + '"]').data('standard-img'));
        }
        $('#files').html(_files.join('|'));
      }
      window.self.close();
    }
    e.preventDefault();
  });

  $('#cancel').on('click', function(e) {
    window.self.close();
    e.preventDefault();
  });

  // Double click.
  $('#photos a.photo').on('dblclick', function(e) {
    if (_disable_select) {
      // Make sure double click works on already selected photo.
      if ($(this).hasClass('selected')) {
        selected = [];
        $(this).trigger('click');
        $('a#pick').trigger('click');
      }
    }
    else {
      selected = [];
      $(this).trigger('click');
      $('a#pick').trigger('click');
    }
  });

  // Check if element is already in array.
  function isInArray(value, array) {
    return array.indexOf(value) > -1;
  }

}(jQuery));

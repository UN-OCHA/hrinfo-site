(function ($) {

  'use strict';

  Drupal.behaviors.hrCoreGuidelines = {
    attach: function (context, settings) {
      // Use class instead of ID because drupal changes
      // form's id in case of validation error....
      function getEntityBundleFromForm(criteria) {
        for (var i = 0, l = criteria.length; i < l; i++) {
          var form = $('form.' + criteria[i][0]);
          if (form.length > 0) {
            return criteria[i][1];
          }
        }
        return '';
      }

      // Get Form ID
      var entityBundle = getEntityBundleFromForm([
        ['node-hr_assessment-form', 'assessments'],
        ['node-hr_document-form', 'documents'],
        ['node-hr_event-form', 'events'],
        ['node-hr_infographic-form', 'mapsinfographics'],
      ]);
      if (entityBundle === '') {
        return;
      }

      var lang = $('html').attr('lang');
      var helpUrl = '/' + lang + '/help/publishing-' + entityBundle;

      // Guidelines already set.
      function setGuidelines() {
        if (document.getElementById('hr-field-guidelines')) {
          return;
        }
        else {
          $('body').append('<div id="hr-field-guidelines"></div>');
          $('#hr-field-guidelines').load(helpUrl + ' .field-guidelines', function() {
            processGuidelines();
          });
        }
      }

      // Add the guidelines to the page with a question mark icon to trigger the display.
      function processGuidelines() {
        // Remove the existing guidelines from the page if any.
        $('.guideline-toggler, .guideline-checkbox, .guideline').remove();

        var labels = $('label, legend');
        var languageField = ['form-language', 'form-langue', 'form-idioma'];
        var titleField = ['form-title', 'form-titre', 'form-titulo', 'form-заголовок'];
        for (var i = 0, l = labels.length; i < l; i++) {
          var label = $(labels[i]);

          // Skip invisible elements.
          if (label.hasClass('element-invisible') || label.parents('.sticky-header').length) {
            continue;
          }

          // Field name.
          var field = 'form-' + label.text()
          .replace(/\s*[()':*+]\s*/g, '')
          .trim()
          .toLowerCase()
          .normalize('NFD')
          .replace(/[\u0300-\u036f]/g, "")
          .replace(/\s*[&]\s*/, ' ')
          .replace(/[_ /]+/g, '-');

          // Skip title and language when they're not the main element.
          if (languageField.indexOf(field) > -1 && label.parents('.form-item-language').length === 0) {
            continue;
          }
          if (titleField.indexOf(field) > -1 && label.parents('.form-item-title').length === 0) {
            continue;
          }

          // Add the guideline to the page.
          if ($( '#hr-field-guidelines .' + field ).length > 0) {
            var text = $( '#hr-field-guidelines .' + field )[0].innerHTML;
            var content = '<label class="guideline-toggler" for="' + field + '-checkbox">?</label>' +
              '<input class="guideline-checkbox" type="checkbox" id="' + field + '-checkbox"/>' +
              '<div class="guideline">' +
              '<div class="guideline-box">' +
              '<label class="guideline-toggler-hide" >×</label>' +
              '<label class="guideline-toggler-hide" for="' + field + '-checkbox">×</label>' +
              '<div class="guideline-content">' +
              '<div>' + text + '</div>' +
              '</div>' +
              '</div>' +
              '</div>';

            var element = $(content);
            // Open links in new tabs.
            element.siblings('.guideline').find('a').attr('target', '_blank');
            if (label[0].tagName === 'LABEL') {
              label.addClass('has-guidelines').after(element);
            }
            else {
              label.addClass('has-guidelines').append(element);
            }
          }
        }
      }

      setGuidelines();
    }
  };

})(jQuery);

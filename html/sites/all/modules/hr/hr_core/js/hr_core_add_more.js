/**
	* @file
	* Custom script for add-more handling for node-forms.
*/

(function ($, Drupal) {

  'use strict';

  Drupal.behaviors.hrCoreAddMore = {
    attach: function (context, settings) {

      /**
       * Create a button element.
       */
      function createButton(value, label, disabled) {
        var button = document.createElement('button');
        button.setAttribute('type', 'button');
        button.setAttribute('value', value);
        button.appendChild(document.createTextNode(label));
        button.disabled = disabled === true;
        return button;
      }

      /**
       * Respond to clicks on 'add' button. Reveal another input and remove
       * button if appropriate.
       */
      function addRow() {
        var next = this.parentElement.getElementsByClassName('hr-add-more');
        // Delete the button if there are no more inputs to add.
        if (next[1] === undefined) {
          this.remove();
        }
        if (next[0] !== undefined) {
          next[0].className = next[0].className.replace('hr-add-more', '');
        }
      }

      /**
       * Mark extra pre-generated fields as 'hr-add-more' so we can hide them.
       * @see _hr_core_render_multiple_input_lines().
       */
      function markFieldsToHide() {
        var fields = Drupal.settings.hr_core.fields;
        if (fields.length > 0) {
          var extraRows, fieldname, table;
          var underscoreRegex = /_/g;
          for (var i = 0, l = fields.length; i < l; i++) {
            fieldname = fields[i].replace(underscoreRegex, '-');
            table = document.getElementById(fieldname + '-values');
            if (table === null) {
              continue;
            }
            if (table.className.indexOf('add-more-processed') !== -1) {
              continue;
            }
            extraRows = table.tBodies[0].children;
            // This is only applied for new forms, so all but the first element
            // can be hidden, hence j=1.
            for (var j = 1, m = extraRows.length; j < m; j++) {
              if (extraRows[j].className.indexOf('hr-add-more') === -1) {
                extraRows[j].className = extraRows[j].className + ' hr-add-more';
              }
            }
            table.className = table.className + ' add-more-processed';
          }
        }
      }

      /**
       * Process 'hr-add-more' class. Hide 'extra' inputs and add button to
       * reveal them.
       */
      function processAddMoreInputs() {
        var extra = document.getElementsByClassName('hr-add-more');
        if (extra.length > 0) {
          for (var i = 0, l = extra.length; i < l; i++) {
            // Put the wrapper outside the table.
            var wrapper = extra[i].parentElement.parentElement.parentElement;
            // We only need one per table.
            if (wrapper.getElementsByClassName('hr-add-button').length === 0) {
              // TODO: get this to work with Drupal.t().
              var addText = {
                en: 'Add another item',
                es: 'Añadir otro elemento',
                fr: 'Ajouter un autre élément',
                ru: 'Добавить ещё'
              };
              var lang = document.getElementsByTagName('html')[0].getAttribute('lang');
              var add = createButton('add', addText[lang]);
              add.className = 'hr-add-button btn btn-default';
              add.addEventListener('click', addRow);
              wrapper.appendChild(add);
            }
          }
        }
      }
      markFieldsToHide();
      processAddMoreInputs();
    }
  };
}(jQuery, Drupal));

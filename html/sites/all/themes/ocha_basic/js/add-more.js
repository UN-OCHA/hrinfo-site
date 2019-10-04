/**
	* @file
	* Custom script for add-more handling for node-forms.
*/

(function ($, Drupal) {
  Drupal.behaviors.addMore = {
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
        console.log('this', this);
        console.log('next', next);
        // Delete the button if there are no more inputs to add.
        if (next[1] === undefined) {
          this.remove();
        }
        if (next[0] !== undefined) {
          var select = next[0].getElementsByTagName('select')[0];
          next[0].className = next[0].className.replace('hr-add-more', '');
          $(select).chosen();
        }
      }

      /**
       * Mark extra pre-generated fields as 'hr-add-more' so we can hide them.
       * @see _hr_document_render_multiple_input_fields().
       */
      var fields = Drupal.settings.hr_documents.fields;
      if (fields.length > 0) {
        var extraRows, fieldname, table;
        var underscoreRegex = /_/g;
        for (var i = 0, l = fields.length; i < l; i++) {
          fieldname = fields[i].replace(underscoreRegex, '-');
          table = document.getElementById(fieldname + '-values');
          extraRows = table.tBodies[0].children;
          // This is only applied for new forms, so all  but the first element
          // can be hidden, hence j=1.
          for (var j = 1, m = extraRows.length; j < m; j++) {
            extraRows[j].className = extraRows[j].className + ' hr-add-more';
          }
        }
      }

      /**
       * Process 'hr-add-more' class. Hide 'extra' inputs and add button to
       * reveal them.
       */
      var extra = document.getElementsByClassName('hr-add-more');
      if (extra.length > 0) {
        for (var i = 0, l = extra.length; i < l; i++) {
          // Better way to do this?
          var wrapper = extra[i].parentElement.parentElement.parentElement;
          console.log('wrapper', wrapper);
          // We only need one per table.
          if (wrapper.getElementsByClassName('hr-add-button').length === 0) {
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
            console.log('wrapper after', wrapper);
          }
        }
      }
    }
  };
}(jQuery, Drupal));

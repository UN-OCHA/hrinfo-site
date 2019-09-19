/**
	* @file
	* Custom scripts for forms.
*/

(function ($, Drupal) {
  Drupal.behaviors.customForms = {
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
          var select = next[0].getElementsByTagName('select')[0];
          next[0].className = next[0].className.replace('hr-add-more', '');
          $(select).chosen();
        }
      }

      /**
       * Process 'hr-add-more' class. Hide 'extra' inputs and add button to
       * reveal them.
       */
      var extra = document.getElementsByClassName('hr-add-more');
      if (extra.length > 0) {
        for (var i = 0, l = extra.length; i < l; i++) {
          var body = extra[i].parentElement;
          // We only need one per table.
          if (body.getElementsByClassName('hr-add-button').length === 0) {
            var add = createButton('add', '+');
            add.className = 'hr-add-button';
            add.addEventListener('click', addRow);
            body.appendChild(add);
          }
        }
      }
    }
  };
}(jQuery, Drupal));

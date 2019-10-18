/**
       * @file
       * Custom script for toggling hidden fields.
*/

(function ($, Drupal) {
  'use strict;'
  Drupal.behaviors.hrDocumentsToggleFields = {
    attach: function (context, settings) {

      var toggleTextShow = {
        en: 'Show more',
        es: 'Ver más',
        fr: 'Afficher plus',
        ru: 'Показать больше'
      };
      var toggleTextHide = {
        en: 'Hide extra fields',
        es: 'Ocultar campos extra',
        fr: 'Masquer les champs supplémentaires',
        ru: 'Скрыть дополнительные'
      };
      var lang = document.getElementsByTagName('html')[0].getAttribute('lang');
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
      function toggleFields() {
        var toggle = this.previousElementSibling;
        if (this.value === 'show') {
          toggle.className = toggle.className.replace('hr-additional-hide', 'hr-additional-show');
          this.value = 'hide';
          this.innerHTML = toggleTextHide[lang];
        }
        else {
          toggle.className = toggle.className.replace('hr-additional-show', 'hr-additional-hide');
          this.value = 'show';
          this.innerHTML = toggleTextShow[lang];
        }
      }

      /**
       * Hide 'extra' inputs and add button to toggle them.
       */
      function prepareToggle() {
        var additional = document.getElementsByClassName('hr-additional')[0];
        if (additional !== undefined && additional.children.length > 0) {
          if (additional.children[0].className.indexOf('hr-additional-hide') === -1) {
            additional.children[0].className += ' hr-additional-hide';
          }
          // We only need one per table.
          if (additional.getElementsByClassName('hr-toggle-button').length === 0) {
            var add = createButton('show', toggleTextShow[lang]);
            add.className = 'hr-toggle-button btn btn-default';
            add.addEventListener('click', toggleFields);
            additional.appendChild(add);
          }
        }
      }
      prepareToggle();
    }
  };
}(jQuery, Drupal));

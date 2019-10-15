/**
       * @file
       * Custom script for toggling hidden fields.
*/

(function ($, Drupal) {
  'use strict;'
  Drupal.behaviors.hrInfographicsToggleFields = {
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
          if (document.documentElement.clientWidth > 1024) {
            toggle.style.display = 'flex';
          }
          else {
            toggle.style.display = 'block';
          }
          this.value = 'hide';
          this.innerHTML = toggleTextHide[lang];
        }
        else {
          toggle.style.display = 'none';
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
          additional.children[0].style.display = 'none';
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

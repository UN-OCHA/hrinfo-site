/**
 * @file
 * Calendar.
 */

(function($) {
  Drupal.behaviors.eventsEvent = {
    attach: function(context, settings) {
      if (!settings.fullcalendar_api.calendarSettings) {
        return;
      }
      var $calendarId = Drupal.settings.fullcalendar_api.calendarId;
      var $calendar = $('#' + $calendarId);
      if (!$calendar.length) {
        return;
      }

      var eventFilters = Drupal.settings.fullcalendar_api.calendarSettings.events.data;

      var $settings = settings.fullcalendar_api.calendarSettings;
      $.extend($settings, {
        'eventRender': function(event, element, view) {
          for (f in eventFilters) {
            if (eventFilters.hasOwnProperty(f) && event.hasOwnProperty(f) && typeof eventFilters[f] != 'undefined' && eventFilters[f] != '' && event[f].indexOf(eventFilters[f]) === -1) {
              return false;
            }
          }
          return true;
        },
        viewRender: function(view) {
          if (view.name === 'upcoming') {
            if ($calendar.fullCalendar('getDate').unix() < moment().unix()) {
              $calendar.fullCalendar('gotoDate', moment());
            }
          }
          else if (view.name === 'past') {
            if ($calendar.fullCalendar('getDate').toISOString() >= moment().format('Y-MM-DD')) {
              $calendar.fullCalendar('gotoDate', moment().add(-1, 'days'));
              window.setTimeout(function () {
                $calendar.fullCalendar('prev');
              }, 250);
            }
          }
        }
      });

      $.extend($settings['views'], {
        'upcoming': {
          'type': 'list',
          'buttonText': 'Upcoming',
          'duration': {
            'days': 90
          },
          'visibleRange': function(currentDate) {
            return {
              start: currentDate.clone(),
              end: currentDate.clone().add(90, 'days')
            };
          },
          'validRange': function(currentDate) {
            return {
              start: currentDate.clone()
            };
          }
        },
        'past': {
          'type': 'listrev',
          'buttonText': 'Past events',
          'duration': {
            'days': 90
          },
          'visibleRange': function(currentDate) {
            return {
              start: currentDate.clone().add(-90, 'days'),
              end: currentDate.clone().add(1, 'days')
            };
          },
          'validRange': function(currentDate) {
            return {
              end: currentDate.clone().add(-1, 'days')
            };
          }
        }
      });

      $calendar.fullCalendar($settings);

      var handleICal = function (e) {
        var url = $settings.base_url + '/ical?';
        url += $.param(eventFilters);
        window.location = url;
      };

      // Redirect to selected option.
      var handleSelect = function (e) {
        if (e.target.value) {
          data = e.target.value;
          parts = data.split(':');

          eventFilters[parts[0]] = parts[1];

          // Don't change the source.
          // $calendar.fullCalendar('getEventSources')[0].data[parts[0]] = parts[1];

          // Trigger rerender.
          $calendar.fullCalendar('rerenderEvents');
        }
      };

      var buildIcalButton = function () {
        var button = document.createElement('button');
        button.innerHTML = Drupal.t('ICAL');
        button.addEventListener('click', handleICal);
        return button;
      }

      var buildPdfButton = function () {
        var button = document.createElement('button');
        button.innerHTML = Drupal.t('PDF');
        button.addEventListener('click', function () {
          // pdf magic here
        });
        return button;
      }

      var buildExportOptions = function () {
        var container = document.createElement('div');
        container.className = 'calendar-export';

        var exportButton = document.createElement('button');
        exportButton.className = 'btn-primary calendar-export__button';
        exportButton.innerHTML = Drupal.t('Export');
        exportButton.id = 'export-dropdown';
        exportButton.setAttribute('data-toggle', 'dropdown');
        exportButton.setAttribute('aria-haspopup', 'true');
        exportButton.setAttribute('aria-expanded', 'false');

        container.appendChild(exportButton);

        var exportOptionsList = document.createElement('ul');
        exportOptionsList.className = 'dropdown-menu';
        exportOptionsList.setAttribute('aria-labelledby', 'export-dropdown');

        var icalButton = buildIcalButton();
        var pdfButton = buildPdfButton();

        var exportListItem = document.createElement('li');
        exportListItem.appendChild(icalButton);
        exportListItem.appendChild(pdfButton);
        exportOptionsList.appendChild(exportListItem);
        container.appendChild(exportOptionsList);
        return container;
      }

      $.getJSON($settings.base_url + '/api/v0/facets', function(facets) {
        var filtersWrapper = document.createElement('div');
        filtersWrapper.className = 'calendar-filters clearfix';

        var filterCount = 0;
        for (var f in facets) {
          var facet = facets[f];
          filterCount++;

          console.log(facet);
          var filter = document.createElement('div');

          if (facet.values.length === 0) {
            continue;
          }

          // Construct label.
          var newLabel = document.createElement('label');
          newLabel.innerText = facet.label;
          newLabel.setAttribute('for', 'filter-' + filterCount);

          // Construct select.
          var newSelect = document.createElement('select');
          newSelect.className += ' chosen-enable';
          newSelect.id = 'filter-' + filterCount;

          // Add empty option.
          var newOption = document.createElement('option');
          newOption.value = f;
          newOption.text = Drupal.t('- Any -');
          newSelect.appendChild(newOption);

          // Add options.
          for (var o in facet.values) {
            var option = facet.values[o];
            var newOption = document.createElement('option');
            newOption.value = f + ':' + o;
            newOption.text = option;
            newSelect.appendChild(newOption);
          }

          // Hide filters.
          filter.className += ' processed block-views';
          filter.appendChild(newLabel);
          filter.appendChild(newSelect);
          filtersWrapper.appendChild(filter);

          if (Drupal.behaviors && Drupal.behaviors.chosen) {
            Drupal.behaviors.chosen.attach(newSelect, Drupal.settings);
            jQuery(newSelect).chosen().change(function(e) {
              handleSelect(e);
            });
          }
        }
        document.querySelector('#block-system-main').insertBefore(filtersWrapper, document.querySelector('#block-system-main').firstChild);

        var exportDiv = buildExportOptions();
        document.querySelector('#block-system-main').insertBefore(exportDiv, document.querySelector('#block-system-main').firstChild);
      });
    }
  }
})(jQuery);

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

      var eventFilters = Drupal.settings.fullcalendar_api.calendarSettings.availableFilters;
      var state = {
        'view': 'month',
        'date': '',
      };

      var updateState = function () {
        $.extend(state, eventFilters);
        var path = '?';
        for (f in state) {
          if (state.hasOwnProperty(f) && typeof state[f] != 'undefined' && state[f] != '') {
            path += f + '=' + state[f] + '&';
          }
        }
        history.replaceState(state, '', path);
      };

      var updateEventFilters = function (filters) {
        eventFilters = filters;
        updateState();
      };

      var $settings = settings.fullcalendar_api.calendarSettings;

      // Needed to fix navigation problem on past events.
      var alreadyTrigger = false;

      $.extend($settings, {
        'eventRender': function(event, element, view) {
          for (f in eventFilters) {
            if (eventFilters.hasOwnProperty(f) && event.hasOwnProperty(f) && typeof eventFilters[f] != 'undefined' && eventFilters[f] != '' && event[f].indexOf(eventFilters[f]) === -1) {
              return false;
            }
          }

          // Add location.
          if (event.location) {
            if (view.name === 'listYear' || view.name === 'upcoming' || view.name === 'past') {
              if (event.locationDetails) {
                element.find('.fc-list-item-title').html(element.find('.fc-list-item-title').html() + '<div class="fc-location-details">' + event.locationDetails + '</div>');
              }
              element.find('.fc-list-item-title').html(element.find('.fc-list-item-title').html() + '<div class="fc-location">' + event.location + '</div>');
            }
            else {
              if (event.locationDetails) {
                element.find('.fc-content').append('<span class="fc-location-details">' + event.locationDetails + '</span>');
              }
              element.find('.fc-content').append('<span class="fc-location">' + event.location + '</span>');
            }
          }

          // Add more details to past events.
          if (view.name === 'past') {
            if (event.description) {
              element.find('.fc-list-item-title').html(element.find('.fc-list-item-title').html() + '<span class="fc-description">' + event.description + '</span>');
            }
            if (event.files && event.files.length > 0) {
              var ul = $('<ul class="ev-files"></ul');
              for (var i = 0; i < event.files.length; i++) {
                ul.append('<li class="ev-doc-' + event.files[i].type_human.toLowerCase().replace(/[^0-9a-z]/gi,'-') + '"><a href="' + event.files[i].uri + '" target="_blank">' + event.files[i].name + '</a></li>');
              }
              element.find('.fc-list-item-title').append(ul);
            }
          }

          return true;
        },
        height: 'auto',
        viewRender: function(view) {
          // Store view.name, view.start and view.end
          state.view = view.name;
          state.date = $calendar.fullCalendar('getDate').toISOString();
          updateState();

          if (view.name === 'upcoming') {
            if ($calendar.fullCalendar('getDate').unix() < moment().add(-1, 'days').unix()) {
              $calendar.fullCalendar('gotoDate', moment());
            }
          }
          else if (view.name === 'past') {
            if (!alreadyTrigger && $calendar.fullCalendar('getDate').toISOString() >= moment().format('Y-MM-DD')) {
              $calendar.fullCalendar('gotoDate', moment().add(0, 'days'));
              alreadyTrigger = true;
              window.setTimeout(function () {
                $calendar.fullCalendar('prev');
                alreadyTrigger = false;
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
          'validRange': function(currentDate) {
            return {
              end: currentDate.clone()
            };
          },
          'visibleRange': function(currentDate) {
            return {
              start: currentDate.clone().add(-90, 'days'),
              end: currentDate.clone()
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
          eventFilters[parts[0]] = parts[1];
          if (typeof parts[1] == 'undefined') {
            eventFilters[parts[0]] = '';
          }
          updateEventFilters(eventFilters);

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

      // Build URL parameters for facets.
      var facetURL = '/api/v0/facets?';
      var forcedFilters = Drupal.settings.fullcalendar_api.calendarSettings.events.data;
      for (f in forcedFilters) {
        if (forcedFilters.hasOwnProperty(f) && typeof forcedFilters[f] != 'undefined' && forcedFilters[f] != '') {
          facetURL += f + '=' + forcedFilters[f] + '&';
        }
      }

      $.getJSON($settings.base_url + facetURL, function(facets) {
        var filtersWrapper = document.createElement('div');
        filtersWrapper.className = 'calendar-filters clearfix';

        var filterCount = 0;
        for (var f in facets) {
          // Skip facets if they are not used.
          if (typeof eventFilters[f] == 'undefined') {
            continue;
          }

          var facet = facets[f];
          filterCount++;

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

        if (typeof Drupal.settings.fullcalendar_api.calendarSettings.hide_export == 'undefined' || !Drupal.settings.fullcalendar_api.calendarSettings.hide_export) {
          var exportDiv = buildExportOptions();
          document.querySelector('#block-system-main').insertBefore(exportDiv, document.querySelector('#block-system-main').firstChild);
        }
      });
    }
  }
})(jQuery);

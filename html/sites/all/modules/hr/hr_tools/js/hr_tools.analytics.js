(function ($) {
  Drupal.behaviors.hr_toolsAnalytics = {
    attach: function (context, settings) {
      var token = Drupal.settings.hr_tools.token;
      var pathFilter = Drupal.settings.hr_tools.pathFilter;
      var viewId = 'ga:112786249';
      var startDate = '30daysAgo';

      document.getElementById('report--start-date').addEventListener('change', function () {
        startDate = document.getElementById('report--start-date').value;
        document.getElementById('report--tile').innerHTML = 'Analytics (last ' + startDate + ' days)';
        startDate = startDate + 'daysAgo';
        queryReports();
      });

      function handleReportingResults(results, headers) {
        var output = [];
        if (!results.code) {
          for( var i = 0, report; report = results.reports[i]; ++i ) {
            if (report.data.rows && report.data.rows.length) {
              var table = ['<table>'];

              if (headers) {
                table.push('<tr><th>');
                table.push(headers.join('</th><th>'));
                table.push('</th></tr>');
              }
              else {
                table.push('<tr><th>', report.columnHeader.dimensions.join('</th><th>').replace('ga:', ''), '</th>');
                for (var i=0, header; header = report.columnHeader.metricHeader.metricHeaderEntries[i]; ++i) {
                  table.push('<th>', header.name.replace('ga:', ''), '</th>');
                }
                table.push('</tr>');
              }

              for (var rowIndex=0, row; row = report.data.rows[rowIndex]; ++rowIndex) {
                for(var dateRangeIndex=0, dateRange; dateRange = row.metrics[dateRangeIndex]; ++dateRangeIndex) {
                  table.push('<tr><td>', row.dimensions.join('</td><td>'), '</td>');
                  table.push('<td>', dateRange.values.join('</td><td>'), '</td></tr>');
                }
              }
              table.push('</table>');

              output.push(table.join(''));
            } else {
              output.push('<p>No rows found.</p>');
            }
          }
          return output;
        } else {
          console.log('There was an error: ' + results.message);
        }
      }

      function queryReports() {
        var topCountries = new gapi.analytics.googleCharts.DataChart({
          'query': {
            'ids': viewId,
            'metrics': 'ga:sessions',
            'dimensions': 'ga:country',
            'start-date': startDate,
            'end-date': 'yesterday',
            'max-results': 6,
            'sort': '-ga:sessions'
          },
          'chart': {
            'container': 'chart-top-countries',
            'type': 'PIE',
            'options': {
              'width': '100%',
              'pieHole': 4/9
            }
          }
        });

        var sessions = new gapi.analytics.googleCharts.DataChart({
          query: {
            'ids': viewId,
            'start-date': startDate,
            'end-date': 'yesterday',
            'metrics': 'ga:sessions,ga:users,ga:uniquePageviews,ga:newUsers',
            'dimensions': 'ga:date'
          },
          chart: {
            'container': 'chart-sessions',
            'type': 'LINE',
            'options': {
              'width': '100%'
            }
          }
        });

        var topLanguages = new gapi.analytics.googleCharts.DataChart({
          query: {
            'ids': viewId,
            'start-date': startDate,
            'end-date': 'yesterday',
            'metrics': 'ga:pageviews',
            'dimensions': 'ga:pagePathLevel1',
            'sort': '-ga:pageviews',
            'max-results': 10
          },
          chart: {
            'container': 'chart-top-languages',
            'type': 'PIE',
            'options': {
              'width': '100%',
              'pieHole': 4/9,
            }
          }
        });

        topCountries.set({'query': {'filters': 'ga:pagePath=@' + pathFilter}}).execute();
        sessions.set({'query': {'filters': 'ga:pagePath=@' + pathFilter}}).execute();
        topLanguages.set({'query': {'filters': 'ga:pagePath=@' + pathFilter}}).execute();

        gapi.client.request({
          path: '/v4/reports:batchGet',
          root: 'https://analyticsreporting.googleapis.com/',
          method: 'POST',
          body: {
            reportRequests: [
              {
                viewId: viewId,
                dateRanges: [
                  {
                    startDate: startDate,
                    endDate: 'yesterday'
                  }
                ],
                metrics: [
                  {expression: 'ga:sessions' },
                  {expression: 'ga:hits' },
                  {expression: 'ga:avgSessionDuration'},
                  {expression: 'ga:percentNewSessions'}
                ],
                dimensionFilterClauses: [{
                  filters: [{
                    dimensionName: "ga:pagePath",
                    operator: "PARTIAL",
                    expressions: [pathFilter]
                  }]
                }]
              }
            ]
          }
        }).then(function (response) {
          document.getElementById('chart-num-visitors').innerText = response.result.reports[0].data.totals[0].values[0];
          document.getElementById('chart-num-hits').innerText = response.result.reports[0].data.totals[0].values[1];
          document.getElementById('chart-num-duration').innerText = parseInt(response.result.reports[0].data.totals[0].values[2], 10).toFixed(2) + 's';
          document.getElementById('chart-num-new').innerText = parseInt(response.result.reports[0].data.totals[0].values[3], 10).toFixed(2) + '%';
        });

        gapi.client.request({
          path: '/v4/reports:batchGet',
          root: 'https://analyticsreporting.googleapis.com/',
          method: 'POST',
          body: {
            reportRequests: [
              {
                viewId: viewId,
                pageSize: 10,
                dateRanges: [
                  {
                    startDate: startDate,
                    endDate: 'yesterday'
                  }
                ],
                metrics: [
                  {expression: 'ga:pageviews'},
                  {expression: 'ga:uniquePageviews'}
                ],
                dimensions: [
                  {name: 'ga:pageTitle'}
                ],
                dimensionFilterClauses: [{
                  filters: [{
                    dimensionName: "ga:pagePath",
                    operator: "PARTIAL",
                    expressions: [pathFilter]
                  }]
                }],
                orderBys: [
                  {"fieldName": "ga:pageviews", "sortOrder": "DESCENDING"}
                ]                }
            ]
          }
        }).then(function (response) {
          document.getElementById('table-top-pages').innerHTML = handleReportingResults(response.result, ['Page', '# views', '# unique views']);
        });
      }

      gapi.analytics.ready(function() {
        gapi.analytics.auth.authorize({
          'serverAuth': {
            'access_token': token
          }
        });
        queryReports();
      });
    }
  }

})(jQuery);

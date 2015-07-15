(function($) {
  $(document).ready(function() {
    // Get Data
    $.getJSON(window.location.protocol + '//' + window.location.host + '/api/v1.0/operations?filter[type]=country&filter[status]=active', function(data) {

      var countriesMap = data.data;

      // Pager loop
      while(data.next) {
        delete data; // Reset data
        $.ajax({
          url: data.next.href,
          async:false
        })
        .done(function(dataPager) {
          data = dataPager;
          countriesMap = countriesMap.concat(data.data);
        });
      }

      $(countriesMap).each(function(i) {
        // Set country code
        if(countriesMap[i].country != null) {
          countriesMap[i].mapCode = countriesMap[i].country.pcode;
        }
        //Format date
        if (countriesMap[i].launch_date != null) {
          var launchDate = new Date(countriesMap[i].launch_date*1000);
          countriesMap[i].launch_date = "Launched: " + launchDate.getDate() + "/" + (1+launchDate.getMonth()) + "/" + launchDate.getFullYear();
        }

        //Click on country
        countriesMap[i].events = {
            click: function(e){
                var url = countriesMap[i].url;
                if (countriesMap[i].homepage != null) {
                  url = countriesMap[i].homepage;
                }
                window.location.href = url;
            }
        };
      });

      // Initiate the chart
      $('#operations_map').highcharts('Map', {
        colors: ['#BC2E3B'],
        chart : {
          backgroundColor : '#E0ECED',
          borderRadius: 0
        },
        title : {
          text : ''
        },
        legend: {
          enabled: false
        },
        plotOptions: {
          map: {
            joinBy: ['iso-a2', 'mapCode'],
            mapData: Highcharts.maps['custom/world'],
            tooltip: {
              headerFormat: '',
              pointFormat: '<b>{point.name}</b><br/>{point.email}<br/>{point.launch_date}'
            }

          }
        },
        series : [{
          data : countriesMap,
          name: ' ',
          states: {
            hover: {
              color: '#DD5763'
            }
          }
        }]
      });
    });
  });
})(jQuery);

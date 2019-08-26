(function($) {
  $(function() {

    var activeProtocol = window.location.protocol;

    // Test base Url
    if ( activeProtocol === 'file' || window.location.host.indexOf('fiddle') >= 0) {
      var baseurl = 'http://dev1.humanitarianresponse.info/'; // Local
    } else {
      var baseurl = activeProtocol + '//' + window.location.host + '/'; // Server
    }

    /**
     * [jsFiddleLink set this to good jsFiddle]
     * @type {String}
     */
    var jsFiddleLink = 'http://jsfiddle.net/guillaumev/32ouwf76/';

    var themeurl = baseurl + 'sites/all/themes/humanitarianresponse/';
    var iconsurl = themeurl + 'assets/images/icons/75/Clusters/';

    //Icons data
    var iconname   = new Array();
    var iconext    = ".png";
    iconname[1]    = "CM" + iconext;
    iconname[2]    = "ER" + iconext;
    iconname[3]    = "E" + iconext;
    iconname[4]    = "ES" + iconext;
    iconname[5]    = "ET" + iconext;
    iconname[6]    = "FS" + iconext;
    iconname[7]    = "H" + iconext;
    iconname[8]    = "L" + iconext;
    iconname[9]    = "N" + iconext;
    iconname[10]   = "P" + iconext;
    iconname[5403] = "CP" + iconext;
    iconname[5404] = "GBV" + iconext;
    iconname[5405] = "HLP" + iconext;
    iconname[5406] = "MA" + iconext;
    iconname[11]   = "W" + iconext;

    //Aor data (aor[id] = parent)
    var aor   = new Array();
    aor[5403] = "10";
    aor[5404] = "10";
    aor[5405] = "10";
    aor[5406] = "10";

    /**
     * map overlay tips
     **/

    $('#close-overlay, #ok-overlay').click( // closing events
      function() {
        var overlay = $(this).parent();
        overlay.animate({
          'opacity': 0
        }, 800, function() {
          overlay.remove();
        });
      });

    var $mapOverlay = $('#clusters-map-overlay').clone(true);

    function appendOverlay($overlay) {
      // append map
      $('#clusters-map').append($overlay);
    }

    // set option btn in burger embed the map
    Highcharts.getOptions().exporting.buttons.contextButton.menuItems.push({
        text: 'Embed this map',
        onclick: function () {
          window.open(jsFiddleLink,'_blank');
        }
    });

    /**
     * @return array of all datas
     **/

    function getPaginateResults(url, callBack) {
      $.ajax({
        url: url,
        async: false
      }).done(function(firstResult) {
        var returnResults = firstResult.data;
        while (firstResult.next) {
          $.ajax({
              url: firstResult.next.href,
              async: false
            })
            .done(function(dataPager) {
              firstResult = dataPager;
              returnResults = returnResults.concat(dataPager.data);
            });
        }
        return callBack(returnResults);
      });
    };

    /**
     * Set allOperations
     **/
    var allOperations;
    getPaginateResults(
      baseurl + '/api/v1.0/operations?filter[type]=country&fields=self,country,id',
      function(res) {
        allOperations = res;
      }
    );

    function updateMap() {

      var filters = new Array();
      if ($("#global-clusters .icon.active").length == 1) {
        filters.push("filter[global_cluster]=" + $("#global-clusters .icon.active").attr('cluster-id'));
      }

      if ($("#types .type.active").length == 0) {
        var activeTypes = $("#types .type");
      } else {
        var activeTypes = $("#types .type.active");
      }

      var urls = new Array();
      $.each(activeTypes, function() {
        urls.push(baseurl + "api/v1.0/bundles?filter[type]=" + $(this).attr('type-id') + "&" + filters.join("&"));
      });

      if($("#global-clusters .sub-icons .icon.active").length == 1) {
        urls.push(baseurl + "api/v1.0/bundles?filter[type]=aor&" + filters.join("&"));
      }

      var countriesMap = new Array();

      $.each(urls, function(i, url) {
        // Get Data
        $.ajax({
            url: url,
            async: false
          })
          .done(function(data) {
            var search = data.data;
            // Pager loop
            while (data.next) {
              delete data; // Reset data
              $.ajax({
                  url: data.next.href,
                  async: false
                })
                .done(function(dataPager) {
                  data = dataPager;
                  search = search.concat(data.data);
                });
            }

            $.each(search, function(i, result) {

              if (result.operation != null) {
                result.operation[0].clustername = result.label + " (" + result.operation[0].label + ")";
              } else {
                return true;
              }

              //Lead agencies
              if(result.lead_agencies != null) {
                result.operation[0].lead_agencies = "<br/>Lead agencies: ";
                $.each(result.lead_agencies, function(i, val) {
                  if(i > 0) { result.operation[0].lead_agencies+= ", "; }
                  result.operation[0].lead_agencies+= val.label + " ";
                });
              } else {
                result.operation[0].lead_agencies = "";
              }
              //Co-leads
              if(result.partners != null) {
                result.operation[0].partners = "<br/>Co-leads: ";
                $.each(result.partners, function(i, val) {
                  if(i > 0) { result.operation[0].partners+= ", "; }
                  result.operation[0].partners+= val.label + " ";
                });
              } else {
                result.operation[0].partners = "";
              }
              //Activation document
              if(result.activation_document != null) {
                // @Modifs here
                result.operation[0].activation_document = "<br/>Activation documents: " + result.activation_document.label;
              } else {
                result.operation[0].activation_document = "";
              }
              //Cluster coordinators
              if(result.cluster_coordinators != null) {
                result.operation[0].cluster_coordinators = "<br/>Cluster coordinators: ";
                $.each(result.cluster_coordinators, function(i, val) {
                  if(i > 0) { result.operation[0].cluster_coordinators+= "- "; }
                  result.operation[0].cluster_coordinators += val.name + " (" + val.email + ") ";
                });
              } else {
                result.operation[0].cluster_coordinators = "";
              }

              //Lead agencies
              if (result.lead_agencies != null) {
                result.operation[0].lead_agencies = "<br/>Lead agencies: ";
                $.each(result.lead_agencies, function(i, val) {
                  if (i > 0) {
                    result.operation[0].lead_agencies += ", ";
                  }
                  result.operation[0].lead_agencies += val.label + " ";
                });
              } else {
                result.operation[0].lead_agencies = "";
              }

              //Co-leads
              if (result.partners != null) {
                result.operation[0].partners = "<br/>Co-leads: ";
                $.each(result.partners, function(i, val) {
                  if (i > 0) {
                    result.operation[0].partners += ", ";
                  }
                  result.operation[0].partners += val.label + " ";
                });
              } else {
                result.operation[0].partners = "";
              }

            //Activation document
            if (result.activation_document != null) {
              result.operation[0].activation_document = "<br/>Activation documents: " + result.activation_document.label;
            } else {
              result.operation[0].activation_document = "";
            }
            //Cluster coordinators
            if (result.cluster_coordinators != null) {
              result.operation[0].cluster_coordinators = "<br/>Cluster coordinators: ";
              $.each(result.cluster_coordinators, function(i, val) {
                if (i > 0) {
                  result.operation[0].cluster_coordinators += "- ";
                }
                result.operation[0].cluster_coordinators += val.name + " (" + val.email + ") ";
              });
            } else {
              result.operation[0].cluster_coordinators = "";
            }

            //Color
            if (result.type == "cluster" || result.type == "aor") {
              result.operation[0].color = '#cc606d';
            }
            
            // add country object
            $.each(allOperations, function(i, data) {
              var country = data.country;
              if (country != null && result.operation[0].id == data.id) {
                result.operation[0].country = country;
              }
            });

            countriesMap = countriesMap.concat(result.operation);
          });
        });
      });

      $(countriesMap).each(function(i) {
        // Set country code
        if (countriesMap[i].country != null) {
          countriesMap[i].mapCode = countriesMap[i].country.pcode;
        }
      });

      initMap(countriesMap);
    }

    /**
     * [initMap Initiate the chartmap]
     * @param  {[obj]} mapData [datas formatted highchat way]
     */
    function initMap(mapData) {
      $('#clusters-map').highcharts('Map', {
        colors: ['#cd8064'],
        chart: {
          backgroundColor: '#E0ECED', // bg map
          borderRadius: 0,
          events: {
            load: function() {
              $("#clusters-map").removeClass('loading');
            }
          }
        },
        title: {
          text: ''
        },
        legend: {
          enabled: false
        },
        plotOptions: {
          map: {
            joinBy: ['iso-a2', 'mapCode'],
            dataLabels: {
              enabled: false,
              format: '{point.label}'
            },
            mapData: Highcharts.maps['custom/world'],
            tooltip: {
              headerFormat: '',
              pointFormat: '<b>{point.clustername}</b>{point.lead_agencies}{point.partners}{point.activation_document}{point.cluster_coordinators}'
            }

          }
        },
        series: [{
          data: mapData,
          name: ' ',
          states: {
            hover: {
              color: '#b45a34'
            }
          }
        }]
      });
    }

    //Define click action
    var $globalClusters = $("#global-clusters");

    $globalClusters.on("mousedown", ".icon", 
      function() {
        $("#clusters-map").addClass('loading');
      }).on("click", ".icon", function() {
        $(".icon.active").removeClass('active');
        $(this).addClass('active');
        updateMap();
      });
    $("#types").on("mousedown", ".type", 
      function() {
        $("#clusters-map").addClass('loading');
      }).on("click", ".type", function() {
        $(this).toggleClass('active');
        updateMap();
      });

    //Get Icon list
    $.getJSON(baseurl + 'api/v1.0/global_clusters', function(data) {
      var global_clusters = data.data;
      var definedClusters = {};
      $.each(global_clusters, function(i, global_cluster) { // Render Parent Cluster
        if (typeof aor[global_cluster.id] == "undefined") {
          $("#global-clusters").append('<div id="cluster-' + global_cluster.id + '" cluster-id="' + global_cluster.id + '" class="icon"><img src="' + iconsurl + iconname[global_cluster.id] + '" alt="' + global_cluster.label + '"/></div>');
        } else {
          definedClusters[global_cluster.id] = global_cluster;
        }
      });

      for (var i in aor) {
        if ($("#cluster-" + aor[i] + "-aor").length == 0) {
          $("#cluster-" + aor[i]).after('<div id="cluster-' + aor[i] + '-aor" class="sub-icons"></div>');
        }
        $("#cluster-" + aor[i] + "-aor").append('<div id="cluster-' + i + '" cluster-id="' + i + '" class="icon"><img src="' + iconsurl + iconname[i] + '" alt="' + definedClusters[i].label + '"/></div>')
      }
    });

    $globalClusters.on('mouseenter', '.icon', function() { // tooltip hover clusters
      var img = $(this).find('img'),
        title = img.attr('alt');
      var tooltip = [
        '<div class="cluster-tooltip">',
        '<p color="red">' + title + '</p>',
        '</div>'
      ].join('');
      img.before(tooltip);
    }).on('mouseleave', '.icon', function() {
      $(this).children().first().fadeOut().remove();
    });

    initMap(false);
    appendOverlay($mapOverlay);
  });
})(jQuery);

(function($) {
Drupal.behaviors.arAssessmentsAssessments = {
  attach: function (context, settings) {
    Assessment = Backbone.Model.extend({
      url: function() {
        return 'https://assessmentregistry.hrinfo.568elmp03.blackmesh.com/en/api/v1.0/assessments/' + this.get('id');
      },
      parse: function(response) {
        if (response.data != undefined) {
          return response.data[0];
        }
        else {
          return response;
        }
      },
      getFromDate: function () {
        var d = this.get('date');
        if (d) {
          var from = new Date(d.from);
          return from.toLocaleDateString();
        }
        else {
          return '';
        }
      },
      getToDate: function () {
        var d = this.get('date');
        if (d) {
          var to = new Date(d.to);
          return to.toLocaleDateString();
        }
        else {
          return '';
        }
      }
      /*getFullName: function() {
        return this.get('nameGiven') + ' ' + this.get('nameFamily');
      },

      getMainOrganizationName: function() {
        var organizations = this.get('organization');
        if (organizations.length > 0 && organizations[0] !== null) {
          return organizations[0].name;
        }
      },
      getLocationName: function() {
        var address = this.get('address');
        if (address.length > 0) {
          return address[0].locality;
        }
      },

      getBundles: function() {
        var bundles = this.get('bundle');
        if (bundles.length > 0) {
          return bundles.join(", ");
        }
      },

      getEmails: function() {
        var emails = this.get('email');
        if (emails.length > 0) {
          var addresses = new Array();
          _.each(emails, function(email) {
            addresses.push(email.address);
          });
          return addresses.join(", ");
        }
      },*/
    });

    AssessmentList = Backbone.Collection.extend({
        model: Assessment,
        params: { },

        url: function() {
          var index = window.location.hash.indexOf('?');
          var url = 'https://assessmentregistry.hrinfo.568elmp03.blackmesh.com/en/api/v1.0/assessments/?';
          if (settings.ar_assessments.bundle != '') {
            url += '&filter[bundles][value]=' + settings.ar_assessments.bundle;
          }
          else {
            url += 'filter[operation][value]=' + settings.ar_assessments.operation_id;
          }
          url += '&fields=id,label,status,bundles,organizations,participating_organizations,locations,report,questionnaire,date&page=' + this.page;
          if (index != -1) {
            var params = window.location.hash.substr(index + 1);
            url += '&' + params;
          }
          return url;
        },
        parse: function(response) {
           this.count = response.count;
           return response.data;
        },
        page: 1,
        count: 0,
    });

    AssessmentView = Backbone.View.extend({
      router: null,

      clear: function() {
        this.$el.empty();
      },

      loading: function() {
        this.hide();
        $('#loading').show();
      },

      finishedLoading: function() {
        $('#loading').hide();
        this.show();
      },

    });

    AssessmentTableView = AssessmentView.extend({

        numItems: 10,
        currentPage: 1,

        initialize: function() {
            this.assessmentsList = new AssessmentList;
            this.assessmentsList.limit = this.numItems;
        },

        loadResults: function() {
          var that = this;
          this.assessmentsList.fetch({
            success: function (assessments) {
              var template = _.template($('#ar_assessments_list').html());
              //var pdf_url = that.assessmentsList.url();
              //pdf_url = pdf_url.replace('&limit=' + that.numItems + '&skip=' + that.assessmentsList.skip, '');
              //var csv_url = pdf_url + '&export=csv';
              //$('#contacts-list-csv').attr('href', csv_url);
              $('#assessments-list-table tbody').append(template({assessments: assessments.models}));
              that.finishedLoading();
            },
          });
        },

        events: {
          'change #protectedRoles': 'filterByProtectedRoles',
          'change #bundles': 'filterByBundles',
          'click #search-button': 'search',
          'keyup #search': 'search',
          'click #back': 'back',
          'autocompleteselect #organizations': 'filterByOrganization',
          'click #key-contact': 'filterByKeyContact',
          'click #verified': 'filterByVerified',
          'change #countries': 'filterByCountry',
          'change #locations': 'filterByLocation',
          'change #offices': 'filterByOffice',
          'change #disasters': 'filterByDisaster',
        },

        page: function(page) {
          this.loading();
          this.currentPage = page;
          this.assessmentsList.page = page;
          this.clear();
          this.loadResults();
        },

        clear: function() {
          $('#assessments-list-table tbody').empty();
        },

        show: function() {
          $('#assessments-list').show();
          //$('#block-hid-profiles-hid-profiles-filters').show();
          //$('.feed-icon').show();
        },

        hide: function() {
          $('#assessments-list').hide();
          //$('#block-hid-profiles-hid-profiles-filters').hide();
          //$('.feed-icon').hide();
        },

        finishedLoading: function() {
          $('#loading').hide();
          this.show();
          $('.current-search-item .facetapi-active').html(this.assessmentsList.count + ' items');
          this.pager();
        },

        pager: function() {
          var nextPage = parseInt(this.currentPage) + 1;
          var previousPage = parseInt(this.currentPage) - 1;
          var count = this.assessmentsList.count;
          var itemsPerPage = this.numItems;
          var paramsString = $.param(this.assessmentsList.params);
          if (paramsString != '') {
            paramsString = '?' + paramsString;
          }
          if (this.currentPage * itemsPerPage < count) {
            $('#next').attr('href', '#table/' + nextPage + paramsString);
          }
          else {
            $('#next').attr('href', '#table/' + this.currentPage + paramsString);
          }
          if (previousPage > 0) {
            $('#previous').attr('href', '#table/' + previousPage + paramsString);
          }
          else {
            $('#previous').attr('href', '#table/' + this.currentPage + paramsString);
          }
        },


        filterByProtectedRoles: function(event) {
          var val = $('#protectedRoles').val();
          if (val != '') {
            this.assessmentsList.params.protectedRoles = val;
          }
          else {
            delete this.assessmentsList.params.protectedRoles;
          }
          this.router.navigateWithParams('table/1', this.assessmentsList.params);
        },

        filterByBundles: function(event) {
          var val = $('#bundles').val();
          if (val != '') {
            if (val.charAt(0) == '#') {
              this.assessmentsList.params.protectedBundles = val.substr(1);
            }
            else {
              this.assessmentsList.params.bundle = val;
            }
          }
          else {
            delete this.assessmentsList.params.bundle;
            delete this.assessmentsList.params.protectedBundles;
          }
          this.router.navigateWithParams('table/1', this.assessmentsList.params);
        },

        filterByOrganization: function(event, ui) {
          var val = ui.item.label;
          if (val != '') {
            this.assessmentsList.params.organization_name = val;
          }
          else {
            delete this.assessmentsList.params.organization_name;
          }
          this.router.navigateWithParams('table/1', this.assessmentsList.params);
        },

        filterByCountry: function(event) {
          var val = $('#countries').val();
          if (val != '') {
            this.assessmentsList.params.address_country = val;
          }
          else {
            delete this.assessmentsList.params.address_country;
          }
          this.router.navigateWithParams('table/1', this.assessmentsList.params);
        },

        filterByLocation: function(event) {
          var val = $('#locations').val();
          if (val != '') {
            this.assessmentsList.params.address_administrative_area = val;
          }
          else {
            delete this.assessmentsList.params.address_administrative_area;
          }
          this.router.navigateWithParams('table/1', this.assessmentsList.params);
        },

        filterByOffice: function(event) {
          var val = $('#offices').val();
          if (val != '') {
            this.assessmentsList.params.office_name = val;
          }
          else {
            delete this.assessmentsList.params.office_name;
          }
          this.router.navigateWithParams('table/1', this.assessmentsList.params);
        },

        filterByDisaster: function(event) {
          var val = $('#disasters').val();
          if (val != '') {
            this.assessmentsList.params.disasters_remote_id = val;
          }
          else {
            delete this.assessmentsList.params.disasters_remote_id;
          }
          this.router.navigateWithParams('table/1', this.assessmentsList.params);
        },

        filterByKeyContact: function(event) {
          if ($('#key-contact').prop('checked') == true) {
            this.assessmentsList.params.keyContact = true;
          }
          else {
            delete this.assessmentsList.params.keyContact;
          }
          this.router.navigateWithParams('table/1', this.assessmentsList.params);
        },

        filterByVerified: function(event) {
          if ($('#verified').prop('checked') == true) {
            this.assessmentsList.params.verified = true;
          }
          else {
            delete this.assessmentsList.params.verified;
          }
          this.router.navigateWithParams('table/1', this.assessmentsList.params);
        },

        search: function(event) {
          if (event.type == 'keyup' && event.keyCode == 13 || event.type == 'click') {
            this.router.navigate('table/1?text='+$('#search').val(), {trigger: true});
          }
        },

        back: function(event) {
          history.back();
        },

    });

    AssessmentItemView = AssessmentView.extend({
      render: function (model) {
        var template = _.template($('#ar_assessments_assessment').html());
        this.$el.html(template({assessment: model}));
      },
      show: function() {
        this.$el.show();
        //$('#block-hid-profiles-hid-profiles-sidebar').show();
      },
      hide: function() {
        this.$el.hide();
        //$('#block-hid-profiles-hid-profiles-sidebar').hide();
      },
    });

    AssessmentRouter = Backbone.Router.extend({
      routes: {
        "assessment/:id" : "assessment",
        "table/:page" : "table",
        "*actions": "defaultRoute",
      },

      tableView: new AssessmentTableView({el: 'body'}),
      assessmentView: new AssessmentItemView({el: '#assessments-view'}),

      initialize: function() {
        this.tableView.router = this;
        this.assessmentView.router = this;
      },

      defaultRoute: function (actions) {
        this.navigate('table/1', {trigger: true});
      },

      table: function(page) {
        this.assessmentView.hide();
        this.tableView.page(page);
      },

      assessment: function(id) {
        this.assessmentView.loading();
        var that = this;
        this.tableView.hide();
        this.assessmentView.clear();
        var assessment = new Assessment({id: id});
        assessment.fetch({
          success: function(assessment) {
            that.assessmentView.clear();
            that.assessmentView.render(assessment);
            that.assessmentView.finishedLoading();
          },
        });
      },

      navigateWithParams: function(url, params) {
        this.navigate(url + '?' + $.param(params), {trigger: true});
      },
    });

    var assessment_router = new AssessmentRouter;

    // Autocomplete for organization
    $('#organizations').autocomplete({
      source: function (request, response) {
        $.ajax({
          url: "/hid/organizations/autocomplete/"+request.term,
          dataType: "json",
          success: function( data ) {
            var orgs = new Array();
            _.each(data, function(element, index) {
              orgs.push({'label': element, 'value': element});
            });
            response( orgs );
          }
        });
      },
    });

    // Chosen configuration
    $('select').chosen({allow_single_deselect: true});


    Backbone.history.start();

  }
}
})(jQuery);

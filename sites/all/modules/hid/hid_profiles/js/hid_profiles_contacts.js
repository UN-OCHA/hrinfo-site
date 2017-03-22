(function($) {
Drupal.behaviors.hidProfilesContacts = {
  attach: function (context, settings) {

    var _sync = Backbone.sync;
    Backbone.sync = function(method, model, options) {

        if (settings.hid_profiles.v2) {
          options.headers = {};
          options.headers.Authorization = 'Bearer ' + settings.hid_profiles.token;
        }

        return _sync.call( this, method, model, options );
    };

    Contact = Backbone.Model.extend({
      url: function() {
        if (settings.hid_profiles.v2) {
          return 'https://api2.dev.humanitarian.id/api/v2/user/' + this.get('_id');
        }
        else {
          return window.location.protocol + '//' + window.location.host + '/hid/proxy?api_path=v0/contact/view&_id='+this.get('_id');
        }
      },
      parse: function(response) {
        if (response.contacts != undefined) {
          return response.contacts[0];
        }
        else {
          return response;
        }
      },
      getFullName: function() {
        if (settings.hid_profiles.v2) {
          return this.get('name');
        }
        else {
          return this.get('nameGiven') + ' ' + this.get('nameFamily');
        }
      },

      getMainOrganizationName: function() {
        if (settings.hid_profiles.v2) {
          var org = this.get('organization');
          if (org) {
            return org.name;
          }
          else {
            return '';
          }
        }
        else {
          var organizations = this.get('organization');
          if (organizations.length > 0 && organizations[0] !== null) {
            return organizations[0].name;
          }
        }
      },
      getLocationName: function() {
        if (settings.hid_profiles.v2) {
          var ops = this.get('operations');
          var names = [];
          _.each(operations, function (operation) {
            names.push(operation.name);
          });
          return names.join(", ");
        }
        else {
          var address = this.get('address');
          if (address.length > 0) {
            return address[0].locality;
          }
        }
      },

      getBundles: function() {
        if (settings.hid_profiles.v2) {
          var bundles = this.get('bundles');
          var names = [];
          _.each(bundles, function (bundle) {
            names.push(bundle.name);
          });
          return names.join(", ");
        }
        else {
          var bundles = this.get('bundle');
          if (bundles.length > 0) {
            return bundles.join(", ");
          }
        }
      },

      getJobTitle: function() {
        if (settings.hid_profiles.v2) {
          return this.get('job_title');
        }
        else {
          return this.get('jobtitle');
        }
      },

      getVerified: function () {
        if (settings.hid_profiles.v2) {
          return this.get('verified');
        }
        else {
          return this.get('_profile').verified;
        }
      },

      getEmails: function() {
        if (settings.hid_profiles.v2) {
          var out = [];
          out.push({address: this.get('email')});
          return out;
        }
        else {
          var emails = this.get('email');
          if (emails.length > 0) {
            var addresses = new Array();
            _.each(emails, function(email) {
              addresses.push(email.address);
            });
            return addresses.join(", ");
          }
        }
      },

      getPhoneNumbers: function() {
        if (settings.hid_profiles.v2) {
          return this.get('phone_numbers');
        }
        else {
          return this.get('phones');
        }
      },

      getWebsites: function() {
        if (settings.hid_profiles.v2) {
          return this.get('websites');
        }
        else {
          return this.get('uri');
        }
      },

      getVoip: function() {
        if (settings.hid_profiles.v2) {
          return this.get('voips');
        }
        else {
          return this.get('voip');
        }
      },
    });

    Lists = Backbone.Collection.extend({
      url: 'https://api2.dev.humanitarian.id/api/v2/list'
    });

    ContactList = Backbone.Collection.extend({
        model: Contact,
        params: { },
        listId: '',

        url: function() {
          var index = window.location.hash.indexOf('?');
          var url = '';
          if (settings.hid_profiles.v2) {
            url = 'https://api2.dev.humanitarian.id/api/v2/user?limit=' + this.limit + '&operations.list=' + this.listId + '&sort=name';
          }
          else {
            url = window.location.protocol + '//' + window.location.host + '/hid/proxy?api_path=v0/contact/view&locationId=hrinfo:' + settings.hid_profiles.operation_id + '&status=1&type=local&limit=' + this.limit + '&skip=' + this.skip;
            if (settings.hid_profiles.bundle != '') {
              url += '&bundle=' + settings.hid_profiles.bundle;
            }
          }
          if (index != -1) {
            var params = window.location.hash.substr(index + 1);
            url += '&' + params;
          }
          return url;
        },
        parse: function(response, options) {
          if (settings.hid_profiles.v2) {
            this.count = options.xhr.getResponseHeader('X-Total-Count');
            return response;
          }
          else {
            this.count = response.count;
            return response.contacts;
          }
        },
        limit: 5,
        skip: 0,
        count: 0,
    });

    ContactView = Backbone.View.extend({
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

    ContactTableView = ContactView.extend({

        numItems: 10,
        currentPage: 1,

        initialize: function() {
            this.contactsList = new ContactList();
            this.contactsList.limit = this.numItems;
            this.lists = new Lists();
        },

        loadResults: function () {
          if (settings.hid_profiles.v2) {
            this.loadResultsV2();
          }
          else {
            this.loadResultsV1();
          }
        },

        loadResultsV1: function() {
          var that = this;
          this.contactsList.fetch({
            success: function (contacts) {
              var template = _.template($('#contacts_list_table_row').html());
              var pdf_url = that.contactsList.url();
              pdf_url = pdf_url.replace('&limit=' + that.numItems + '&skip=' + that.contactsList.skip, '');
              var csv_url = pdf_url + '&export=csv';
              pdf_url = pdf_url + '&export=pdf';
              $('#contacts-list-pdf').attr('href', pdf_url);
              $('#contacts-list-csv').attr('href', csv_url);
              $('#contacts-list-table tbody').append(template({contacts: contacts.models}));
              that.finishedLoading();
            },
          });
        },

        loadResultsV2: function () {
          var that = this;
          this.lists.fetch({
            data: { 'remote_id': settings.hid_profiles.operation_id},
            success: function (lists) {
              that.contactsList.listId = lists.models[0].get('_id');
              that.contactsList.fetch({
                success: function (contacts) {
                  var template = _.template($('#contacts_list_table_row').html());
                  var pdf_url = that.contactsList.url();
                  pdf_url = pdf_url.replace('&limit=' + that.numItems + '&skip=' + that.contactsList.skip, '');
                  var csv_url = pdf_url + '&export=csv';
                  pdf_url = pdf_url + '&export=pdf';
                  $('#contacts-list-pdf').attr('href', pdf_url);
                  $('#contacts-list-csv').attr('href', csv_url);
                  $('#contacts-list-table tbody').append(template({contacts: contacts.models}));
                  that.finishedLoading();
                },
              });
            }
          });
        },

        events: {
          'change #protectedRoles': 'filterByProtectedRoles',
          'change #bundles': 'filterByBundles',
          'click #search-button': 'search',
          'keyup #search': 'search',
          'click #back': 'back',
          'autocompleteselect #organizations': 'filterByOrganization',
          'click #verified': 'filterByVerified',
          'change #countries': 'filterByCountry',
          'change #locations': 'filterByLocation',
          'change #offices': 'filterByOffice',
          'change #disasters': 'filterByDisaster',
        },

        page: function(page) {
          this.loading();
          this.currentPage = page;
          this.clear();
          this.contactsList.skip = this.numItems * (page - 1);
          this.loadResults();
        },

        clear: function() {
          $('#contacts-list-table tbody').empty();
        },

        show: function() {
          $('#contacts-list').show();
          $('#block-hid-profiles-hid-profiles-filters').show();
          $('.feed-icon').show();
        },

        hide: function() {
          $('#contacts-list').hide();
          $('#block-hid-profiles-hid-profiles-filters').hide();
          $('.feed-icon').hide();
        },

        finishedLoading: function() {
          $('#loading').hide();
          this.show();
          $('.current-search-item .facetapi-active').html(this.contactsList.count + ' items');
          this.pager();
        },

        pager: function() {
          var nextPage = parseInt(this.currentPage) + 1;
          var previousPage = parseInt(this.currentPage) - 1;
          var count = this.contactsList.count;
          var itemsPerPage = this.numItems;
          var paramsString = $.param(this.contactsList.params);
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
          if (settings.hid_profiles.v2) {
            if (val !== '') {
              this.contactsList.params['functional_roles.list'] = val;
            }
            else {
              delete this.contactsList.params['functional_roles.list'];
            }
          }
          else {
            if (val !== '') {
              this.contactsList.params.protectedRoles = val;
            }
            else {
              delete this.contactsList.params.protectedRoles;
            }
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByBundles: function(event) {
          var val = $('#bundles').val();
          if (settings.hid_profiles.v2) {
            if (val !== '') {
              this.contactsList.params['bundles.list'] = val;
            }
            else {
              delete this.contactsList.params['bundles.list'];
            }
          }
          else {
            if (val !== '') {
              if (val.charAt(0) == '#') {
                this.contactsList.params.protectedBundles = val.substr(1);
              }
              else {
                this.contactsList.params.bundle = val;
              }
            }
            else {
              delete this.contactsList.params.bundle;
              delete this.contactsList.params.protectedBundles;
            }
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByOrganization: function(event, ui) {
          var val = ui.item.label;
          if (val != '') {
            this.contactsList.params.organization_name = val;
          }
          else {
            delete this.contactsList.params.organization_name;
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByCountry: function(event) {
          var val = $('#countries').val();
          if (settings.hid_profiles.v2) {
            if (val !== '') {
              this.contactsList.params.country = val;
            }
            else {
              delete this.contactsList.params.country;
            }
          }
          else {
            if (val !== '') {
              this.contactsList.params.address_country = val;
            }
            else {
              delete this.contactsList.params.address_country;
            }
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByLocation: function(event) {
          var val = $('#locations').val();
          if (val != '') {
            this.contactsList.params.address_administrative_area = val;
          }
          else {
            delete this.contactsList.params.address_administrative_area;
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByOffice: function(event) {
          var val = $('#offices').val();
          if (settings.hid_profiles.v2) {
            if (val !== '') {
              this.contactsList.params['offices.list'] = val;
            }
            else {
              delete this.contactsList.params['offices.list'];
            }
          }
          else {
            if (val != '') {
              this.contactsList.params.office_name = val;
            }
            else {
              delete this.contactsList.params.office_name;
            }
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByDisaster: function(event) {
          var val = $('#disasters').val();
          if (settings.hid_profiles.v2) {
            if (val !== '') {
              this.contactsList.params['disasters.list'] = val;
            }
            else {
              delete this.contactsList.params['disasters.list'];
            }
          }
          else {
            if (val != '') {
              this.contactsList.params.disasters_remote_id = val;
            }
            else {
              delete this.contactsList.params.disasters_remote_id;
            }
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByVerified: function(event) {
          if ($('#verified').prop('checked') == true) {
            this.contactsList.params.verified = true;
          }
          else {
            delete this.contactsList.params.verified;
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
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

    ContactItemView = ContactView.extend({
      render: function (model) {
        var template = _.template($('#contacts_view').html());
        this.$el.html(template({contact: model}));
      },
      show: function() {
        this.$el.show();
        $('#block-hid-profiles-hid-profiles-sidebar').show();
      },
      hide: function() {
        this.$el.hide();
        $('#block-hid-profiles-hid-profiles-sidebar').hide();
      },
    });

    ContactRouter = Backbone.Router.extend({
      routes: {
        "contact/:id" : "contact",
        "table/:page" : "table",
        "*actions": "defaultRoute",
      },

      tableView: new ContactTableView({el: 'body'}),
      contactView: new ContactItemView({el: '#contacts-view'}),

      initialize: function() {
        this.tableView.router = this;
        this.contactView.router = this;
      },

      defaultRoute: function (actions) {
        this.navigate('table/1', {trigger: true});
      },

      table: function(page) {
        this.contactView.hide();
        this.tableView.page(page);
      },

      contact: function(id) {
        this.contactView.loading();
        var that = this;
        this.tableView.hide();
        this.contactView.clear();
        var contact = new Contact({_id: id});
        contact.fetch({
          success: function(contact) {
            that.contactView.clear();
            that.contactView.render(contact);
            that.contactView.finishedLoading();
          },
        });
      },

      navigateWithParams: function(url, params) {
        this.navigate(url + '?' + $.param(params), {trigger: true});
      },
    });

    var contact_router = new ContactRouter;

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

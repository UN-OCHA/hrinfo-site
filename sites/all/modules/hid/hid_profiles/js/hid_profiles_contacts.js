(function($) {
Drupal.behaviors.hidProfilesContacts = {
  attach: function (context, settings) {

    var _sync = Backbone.sync;
    Backbone.sync = function(method, model, options) {
        options.headers = {};
        options.headers.Authorization = 'Bearer ' + settings.hid_profiles.token;
        return _sync.call( this, method, model, options );
    };

    Contact = Backbone.Model.extend({
      url: function() {
        return settings.hid_profiles.api_endpoint + '/api/v2/user/' + this.get('_id');
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
        return this.get('name');
      },

      getMainOrganizationName: function() {
        var org = this.get('organization');
        if (org) {
          return org.name;
        }
        else {
          return '';
        }
      },
      getLocationName: function() {
        var location = this.get('location');
        var name = '';
        if (location.locality) {
          name += location.locality;
        }
        if (location.region) {
          if (name !== '') {
            name += ', ';
          }
          name += location.region.name;
        }
        if (location.country) {
          if (name !== '') {
            name += ', ';
          }
          name += location.country.name;
        }
        return name;
      },

      getBundles: function() {
        var bundles = this.get('bundles');
        var names = [];
        _.each(bundles, function (bundle) {
          names.push(bundle.name);
        });
        return names.join(", ");
      },

      getJobTitle: function() {
        return this.get('job_title');
      },

      getVerified: function () {
        return this.get('verified');
      },

      getEmail: function() {
        return this.get('email');
      },

      getEmails: function() {
        var out = [];
        out.push({address: this.get('email')});
        return out;
      },

      getPhoneNumbers: function() {
        return this.get('phone_numbers');
      },

      getWebsites: function() {
        var webs = this.get('websites');
        var websites = [];
        _.each(webs, function (web) {
          websites.push(web.uri);
        });
        return websites;
      },

      getVoip: function() {
        return this.get('voips');
      },
    });

    Lists = Backbone.Collection.extend({
      url: settings.hid_profiles.api_endpoint + '/api/v2/list'
    });

    ContactList = Backbone.Collection.extend({
        model: Contact,
        params: { },
        listId: '',

        url: function() {
          var index = window.location.hash.indexOf('?');
          var url = '';
          url = settings.hid_profiles.api_endpoint + '/api/v2/user?limit=' + this.limit + '&offset=' + this.skip + '&sort=name';
          if (settings.hid_profiles.bundle) {
            url = url + '&bundles.list=' + this.listId;
          }
          else {
            if (settings.hid_profiles.disaster) {
              url = url + '&disasters.list=' + this.listId;
            }
            else {
              url = url + '&operations.list=' + this.listId;
            }
          }
          if (index != -1) {
            var params = window.location.hash.substr(index + 1);
            if (params) {
              url += '&' + params;
            }
          }
          return url;
        },
        parse: function(response, options) {
          this.count = options.xhr.getResponseHeader('X-Total-Count');
          return response;
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
          this.loadResultsV2();
        },

        loadResultsV2: function () {
          var that = this;
          var remote_id = settings.hid_profiles.operation_id;
          if (settings.hid_profiles.bundle) {
            remote_id = settings.hid_profiles.bundle_id;
          }
          this.lists.fetch({
            data: { 'remote_id': remote_id },
            success: function (lists) {
              that.contactsList.listId = lists.models[0].get('_id');
              that.contactsList.fetch({
                success: function (contacts) {
                  var template = _.template($('#contacts_list_table_row').html());
                  var pdf_url = that.contactsList.url();
                  pdf_url = pdf_url.replace('limit=' + that.contactsList.limit + '&offset=' + that.contactsList.skip, '');
                  pdf_url = pdf_url.replace('?&', '?');
                  pdf_url = pdf_url + '&access_token=' + settings.hid_profiles.token;
                  var csv_url = pdf_url.replace('user', 'user.csv');
                  pdf_url = pdf_url.replace('user', 'user.pdf');
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
          if (val !== '') {
            this.contactsList.params['functional_roles.list'] = val;
          }
          else {
            delete this.contactsList.params['functional_roles.list'];
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByBundles: function(event) {
          var val = $('#bundles').val();
          if (val !== '') {
            this.contactsList.params['bundles.list'] = val;
          }
          else {
            delete this.contactsList.params['bundles.list'];
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByOrganization: function(event, ui) {
          var val = ui.item.label;
          val = ui.item._id;
          if (val !== '') {
            this.contactsList.params['organizations.list'] = val;
          }
          else {
            delete this.contactsList.params['organizations.list'];
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByCountry: function(event) {
          var val = $('#countries').val();
          if (val !== '') {
            this.contactsList.params.country = val;
          }
          else {
            delete this.contactsList.params.country;
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByLocation: function(event) {
          var val = $('#locations').val();
          if (val !== '') {
            this.contactsList.params['location.region.name'] = val;
          }
          else {
            delete this.contactsList.params['location.region.name'];
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByOffice: function(event) {
          var val = $('#offices').val();
          if (val !== '') {
            this.contactsList.params['offices.list'] = val;
          }
          else {
            delete this.contactsList.params['offices.list'];
          }
          this.router.navigateWithParams('table/1', this.contactsList.params);
        },

        filterByDisaster: function(event) {
          var val = $('#disasters').val();
          if (val !== '') {
            this.contactsList.params['disasters.list'] = val;
          }
          else {
            delete this.contactsList.params['disasters.list'];
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

    var contact_router = new ContactRouter();

    $('#organizations').autocomplete({
      source: function (request, response) {
        $.ajax({
          url: settings.hid_profiles.api_endpoint + "/api/v2/list?type=organization&limit=10&name=" + request.term,
          dataType: "json",
          headers: {
            'Authorization': 'Bearer ' + settings.hid_profiles.token
          },
          success: function( data ) {
            var orgs = [];
            _.each(data, function(element, index) {
              orgs.push({'label': element.name, 'value': element.name, '_id': element._id});
            });
            response( orgs );
          }
        });
      }
    });

    // Chosen configuration
    $('select').chosen({allow_single_deselect: true});


    Backbone.history.start();

  }
}
})(jQuery);

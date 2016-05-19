(function ($) {
  Drupal.behaviors.hdxDatasets = {
    attach: function (context, settings) {
      Dataset = Backbone.Model.extend({
        defaults: {
          title: '',
          url: ''
        }
      });

      DatasetsList = Backbone.Collection.extend({
        model: Dataset,
        params: {},
        search: '',
        url: function () {
          var url = 'https://data.humdata.org/api/3/action/package_search?q=groups:' + this.countryCodes(settings) + '&rows=' + this.limit + '&start=' + this.skip;
          var index = window.location.hash.indexOf('=');
          if (index != -1) {
            var params = window.location.hash.substr(index + 1);
            url += '&fq=' + params;
          }
          return url;
        },

        countryCodes: function(settings) {
          var country_codes = settings.hdx_datasets.country_codes;
          if (country_codes.length === 0) {
            return '';
          }
          if (country_codes.length === 1) {
            return country_codes[0];
          }

          return '(' + country_codes.join(' OR ') + ')';
        },

        parse: function (response) {
          var models = response.result.results ? response.result.results : {};
          this.count = response.result.count;
          var fields = [];
          _.each(models, function (resource) {
            var date = new Date(resource.metadata_modified);
            var month = settings.hdx_datasets.month;
            var monthIndex = date.getMonth();
            var resource_link = "https://data.humdata.org/dataset/" + resource.id;
            fields.push({
              title: '<a href="' + resource_link + '">' + resource.title + '</a>',
              last_modified: date.getDate() + '-' + month[monthIndex + 1] + '-' + date.getFullYear(),
              source: resource.dataset_source
            });
          });
          return fields;
        },

        limit: 10,
        skip: 0,
        count: 0,

      });

      DatasetView = Backbone.View.extend({
        router: null,

        clear: function () {
          this.$el.empty();
        },

        loading: function () {
          this.hide();
          $('#loading').show();
        },

        finishedLoading: function () {
          $('#loading').hide();
          this.show();
        },

      });

      DatasetTableView = DatasetView.extend({
        numItems: 10,
        currentPage: 1,

        initialize: function () {
          this.DatasetsList = new DatasetsList;
          this.DatasetsList.limit = this.numItems;
        },

        loadResults: function () {
          var that = this;
          this.DatasetsList.fetch({
            success: function (fields) {
              var template = _.template($('#hdx_datasets_list_view').html());
              $('#datasets-list-table tbody').append(template({fields: fields.models}));
              that.finishedLoading();
            },
          });
        },

        events: {
          'click #back': 'back',
          'keyup .block-current-search .text-search .search': 'searchByTitle'
        },

        page: function (page) {
          this.loading();
          this.currentPage = page;
          this.clear();
          this.DatasetsList.skip = this.numItems * (page - 1);
          this.loadResults();
        },

        render: function (model) {
          this.loadResults();
        },

        clear: function () {
          $('#datasets-list-table tbody').empty();
        },

        show: function () {
          $('#datasets-list').show();
        },

        hide: function () {
          $('#datasets-list').hide();
        },

        finishedLoading: function () {
          $('#loading').hide();
          this.show();
          $('.block-current-search .current-search-filter .num-items').html(this.DatasetsList.count);
          this.pager();
        },

        pager: function () {
          var nextPage = parseInt(this.currentPage) + 1;
          var previousPage = parseInt(this.currentPage) - 1;
          var count = this.DatasetsList.count;
          var itemsPerPage = this.numItems;
          var paramsString = $.param(this.DatasetsList.params);
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

        searchByTitle: function (event) {
          var param = 'title';
          var val = $('.block-current-search .text-search .search').val();
          this.search('*' + val + '*', param);
        },

        search: function (val, param) {
          if (val != '') {
            this.DatasetsList.params[param] = param + ':' + val;
          }
          else {
            delete this.DatasetsList.params.param;
          }
          this.router.navigateWithParams('table/1', this.DatasetsList.params);
        }

      });

      DatasetsRouter = Backbone.Router.extend({
        routes: {
          "table/:page": "table",
          "*actions": "defaultRoute"
        },

        tableView: new DatasetTableView({el: 'body'}),

        initialize: function () {
          this.tableView.router = this;
        },

        defaultRoute: function (actions) {
          this.navigate('table/1', {trigger: true});
        },

        table: function (page) {
          this.tableView.page(page);
        },

        navigateWithParams: function (url, params) {
          this.navigate(url + '?' + $.param(params), {trigger: true});
        }
      });
      var datasets_router = new DatasetsRouter;

      Backbone.history.start();

    }
  }
})(jQuery);

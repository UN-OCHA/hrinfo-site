(function($) {
Drupal.behaviors.hrJobs = {
  attach: function (context, settings) {

  Job = Backbone.Model.extend({
    defaults: {
      title: '',
      url: '',
    },
  });

  JobsList = Backbone.Collection.extend({

    model: Job,
    params: {},
    url: function() {
      var url = 'http://api.rwlabs.org/v1/jobs?offset=' + this.skip + '&limit=' + this.limit + '&query[fields][]=country&fields[include][]=url&query[value]=' + settings.hr_jobs.operation;
      var index = window.location.hash.indexOf('=');
      if(index != -1) {
        var params = window.location.hash.substr(index + 1);
        url += '&filter[field]=title&filter[value]=' + params;
      }
      return url;
    },

    parse: function(response) {
      this.count = response.count;
      this.totalCount = response.totalCount;

      var models = response.data ? response.data : {};
      return _.map(models, function(model){
        var fields = model.fields,
        title = fields.title,
        url = fields.url;

        return (_.extend({}, fields, {title: title, url: url}));
      }, this);
    },

    limit: 20,
    skip: 0,
    count: 0,

  });

  JobView = Backbone.View.extend({

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

  JobTableView = JobView.extend({

      numItems: 20,
      currentPage: 1,

      initialize: function() {
          this.JobsList = new JobsList;
          this.JobsList.limit = this.numItems;
      },

      loadResults: function() {
        var that = this;
        this.JobsList.fetch({
          success: function (fields) {
            var template = _.template($('#jobs_list_view').html());
            $('#jobs-list-table tbody').append(template({fields: fields.models}));
            that.finishedLoading();
          },
        });
      },

      events: {
        'click #back': 'back',
        'keyup #organizations.form-control': 'searchByTitle',
      },

      page: function(page) {
        this.loading();
        this.currentPage = page;
        this.clear();
        this.JobsList.skip = this.numItems * (page - 1);
        this.loadResults();
      },

      render: function (model){
        this.loadResults();
      },

      clear: function() {
        $('#jobs-list-table tbody').empty();
      },

      show: function() {
        $('#jobs-list').show();
      },

      hide: function() {
        $('#jobs-list').hide();
      },

      finishedLoading: function() {
        $('#loading').hide();
        this.show();
        this.pager();
      },

      pager: function() {
        var nextPage = parseInt(this.currentPage) + 1;
        var previousPage = parseInt(this.currentPage) - 1;
        var count = this.JobsList.count;
        var itemsPerPage = this.numItems;
        var paramsString = $.param(this.JobsList.params);
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

      searchByTitle: function(event) {
        var val = $('#organizations.form-control').val();
          if (val != '' && event.which === 13) {
            this.JobsList.params.title = val;
          }
          else {
            delete this.JobsList.params.title;
          }
          this.router.navigateWithParams('table/1', this.JobsList.params);
        },

    });

    JobsRouter = Backbone.Router.extend({
      routes: {
        "table/:page" : "table",
        "*actions": "defaultRoute",
      },

      tableView: new JobTableView({collection: JobsList, el: 'body'}),

      initialize: function() {
        this.tableView.router = this;
      },

      defaultRoute: function (actions) {
        this.navigate('table/1', {trigger: true});
      },

      table: function(page) {
        this.tableView.page(page);
      },

      navigateWithParams: function(url, params) {
        this.navigate(url + '?' + $.param(params), {trigger: true});
      },
    });

    var jobs_router = new JobsRouter;
    Backbone.history.start();

  }
}
})(jQuery);
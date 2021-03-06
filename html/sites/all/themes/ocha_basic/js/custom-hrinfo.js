/**
	* @file
	* Custom scripts for theme.
*/

(function ($, Drupal) {
  Drupal.behaviors.hrEventsPdfLink = {
    attach: function (context, settings) {
      $('button[data-target').on('click', function () {
        var win = window.open($(this).attr('data-target').replace('xyzzy-', ''), '_blank');
      });
    }
  };

  Drupal.behaviors.customHrinfo = {
    attach: function (context, settings) {

      // Add class to powered by pages so they use new style panels.
      function poweredBy () {
        var poweredByPages = ['ethiopia'];
        var poweredByPagesLength = poweredByPages.length;

        for (var i=0; i < poweredByPagesLength; i++) {
          if (window.location.pathname.indexOf('operations/' + poweredByPages[i]) !== -1) {
            $('html').addClass('powered-by');
          }
        }
      }
      poweredBy();

      // Add class to Colombia pages so they use the Sala Humanitaria logo.
      function salaHumanitariaLogo () {
        if (window.location.pathname.indexOf('operations/colombia') !== -1 || window.location.pathname.indexOf('j2h/contactos') !== -1) {
          $('html').addClass('sala-humanitaria');
        }
      }
      salaHumanitariaLogo();

      //$(document).ready(function() {

        //trigger resize
        $(window).resize();

        //facets
        $("#sidebar-first .block.block-facetapi h4").on("click", function(evt) {
					evt.stopImmediatePropagation();
					evt.preventDefault();
          $(this).toggleClass('opened').next('.block__content').slideToggle('fast');
        });
        if($("#sidebar-first .block.block-current-search .block__content .current-search-item-reset").length > 0) {
          $("#sidebar-first .block.block-current-search .block__content .current-search-item-reset").appendTo('#sidebar-first .block.block-current-search .block__content');
        }

        $("#sidebar-first .block.block-facetapi .facetapi-active").each(function() {
          $(this).closest('.block__content').show().prev("h4").addClass("opened");
          $(this).parent().addClass('redactive');
        });

        //Top 'HR' tab
        $("#hr-space-tab > li > ul:first a").each(function() {
          if($(this).hasClass('active')) {
            $("#hr-space-tab").addClass('white');
          }
        });

        //Table responsive
        $(".table-responsive").each(function() {
          var head = $("th", this);
          var i = 0;
          $("td").each(function() {
            if(i >= head.length) {
              i = 0;
            }
            if($.trim($(this).html()) != "") {
              $(this).attr('data-title',$(head[i]).text());
            }
            i++;
          });
        });

        //Recherche Espace
        if($('#views-exposed-form-hr-search-space').length > 0) {
          var inputsearch = $('#views-exposed-form-hr-search-space #edit-search-api-views-fulltext');
          var html = '';
          html+= '<button type="button" class="cd-search--inline__dropdown-btn" data-toggle="dropdown" aria-expanded="false"><svg class="icon icon--arrow-down"><use xlink:href="#arrow-down"></use></svg></button>';
          html+= '<ul class="dropdown-menu changeSearch"><li rel-action="' + $('#views-exposed-form-hr-search-space').attr('action') + '" class="active"><a href="#">' + inputsearch.attr('placeholder') + '</a></li><li rel-action="/' + $('.cd-language-switcher button').text().trim().toLowerCase() + '/search" class=""><a href="#">' + Drupal.t('Search HR.info') + '</a></li></ul>';

          $("#edit-search-wrapper").prepend(html);

          $('.changeSearch li').click(function(e) {
            e.preventDefault();
            $('.changeSearch li.active').removeClass('active');
            $(this).addClass('active');
            inputsearch.attr('placeholder', $(this).text());
            $("#views-exposed-form-hr-search-space").attr("action", $(this).attr("rel-action"));
          });
        }

        // Make dropdown menus work
        $(".hr-goto-dropdown").on('change', function(evt, params) {
          document.location.href = $(this).val();
        });

      //});

      // $(window).resize(function() {
      //
      // 	//position & largeur submenu
      // 	var ww = $(window).width();
      // 	var mw = $("#block-system-main-menu").width();
      // 	var dif = (ww-mw)/2;
      // 	if($(".container.header #navigation ul.menu li ul").length>0) {
      //
      // 		//largeur
      // 		$(".container.header #navigation ul.menu li ul").css({
      // 			'width': ww+'px',
      // 			'margin-left': '-'+dif+'px',
      // 		});
      //
      //
      // 		//position
      // 		var offparent = $(".container.header #navigation ul.menu li ul").parent().offset().left - dif;
      // 		var ulw = 0;
      //
      // 		$(".container.header #navigation ul.menu li ul li").each(function() {
      // 			ulw+= $(this).width();
      // 		});
      //
      // 		var ml = ulw/2 - $(".container.header #navigation ul.menu li ul").parent().width()/2;
      //
      // 		$(".container.header #navigation ul.menu li ul li:first").css("margin-left", offparent-ml+dif+"px");
      // 	}
      //
      // 	//largeur submenu
      //
      //
      // });

    }
  };
}(jQuery, Drupal));

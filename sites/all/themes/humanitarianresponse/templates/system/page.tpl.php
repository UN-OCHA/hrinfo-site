<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 */
?>
<div id="root">
  <header id="header" class="header hidden-print" role="header">
    <div class="container">
      <div id="top">
        <nav class="navbar navbar-default">
            <!-- Brand and toggle get grouped for better mobile display -->
            <div class="navbar-header top">
              <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                <span class="sr-only">Toggle navigation</span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
              </button>
            </div>

            <div class="collapse navbar-collapse">
              <?php print $hr_favorite_spaces; ?>
              <ul id="hr-space-tab" class="nav nav-tabs navbar-left">
                <li class="dropdown">
                  <a class="dropdown-toggle" data-toggle="dropdown" href="#"> MENU <span class="caret"></span></a>
                  <ul class="dropdown-menu">
                    <?php print render($main_menu_dropdown); ?>
                  </ul>
                </li>
                <?php if ($hr_tabs): ?>
                  <?php $num_hr_tabs = count($hr_tabs); foreach ($hr_tabs as $i => $hr_tab) { ?>
                    <li <?php if ($i == $num_hr_tabs - 1) { print 'class="active"'; } ?>><?php print $hr_tab; ?></li>
                  <?php } ?>
                <?php endif; ?>
              </ul>
              <div class="navbar-right">
                <?php print render($page['top']); ?>
              </div>
            </div><!-- .navbar-collapse -->
        </nav>
      </div><!-- #top -->
    </div><!-- .container -->
    <div class="container-outer header">
    <div class="container header">
      <div id="branding">
          <?php if ($logo): ?>
            <a href="<?php print $front_page; ?>" id="logo">
              <img src="<?php print $logo; ?>" alt="Humanitarianresponse Logo" />
            </a>
          <?php endif; ?>
          <div class="pull-right">
            <div id="header-image"><?php print $og_group_header_image; ?></div>
            <?php print render($page['branding']); ?>
          </div>
      </div>
      <div id="navigation">
        <?php print render($page['navigation']); ?>
      </div><!-- /.navigation -->
    </div> <!-- /.container -->
    </div> <!-- /.container-outer -->
  </header>

  <?php if($is_front): ?>

    <div id="front-banner"></div>

  <?php endif; ?>

  <!-- Logo for printed pages -->
  <div class="visible-print-block pull-right">
    <?php if ($logo): ?>
      <img src="<?php print $logo; ?>" alt="Humanitarianresponse Logo" />
    <?php endif; ?>
  </div>

  <div id="main-wrapper">
    <div id="main" class="main">
      <div class="container">
        <?php if ($messages): ?>
          <div id="messages">
            <?php print $messages; ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($page['sidebar_first'])): ?>
          <aside id="sidebar-first" class="col-md-3 hidden-print" role="complementary">
            <?php print render($page['sidebar_first']); ?>
          </aside>
        <?php endif; ?>
        <div id="content-wrapper" <?php if(!empty($page['sidebar_first'])) print 'class="col-md-9"'; ?>>
          <div id="page-header">
            <?php if ($title): ?>
              <div class="page-header">
                <h1 class="title"><?php print $title; ?></h1>
              </div>
            <?php endif; ?>
            <?php if ($tabs): ?>
              <div class="tabs">
                <?php print render($tabs); ?>
              </div>
            <?php endif; ?>
            <?php if ($action_links): ?>
              <ul class="action-links">
                <?php print render($action_links); ?>
              </ul>
            <?php endif; ?>
          </div>
          <div id="content" class="col-md-12">
            <?php print render($page['content']); ?>
          </div>
        </div><!-- /#content-wrapper -->
      </div><!-- #container -->
    </div> <!-- /#main -->
  </div> <!-- /#main-wrapper -->

  <div id="root_footer"></div>
</div><!-- #root -->

<footer id="footer" class="footer hidden-print" role="footer">
  <div class="container">
    <div id="footer-first" class="col-md-3">
      <p><?php print t('!hr_link is provided by UN OCHA to support humanitarian operations globally', array('!hr_link' => l('HumanitarianResponse.info', '<front>', array('attributes' => array('target' => '_blank'))))); ?> </p><p><?php print l(t('Learn more about HumanitarianResponse.info'), 'about', array('alias' => TRUE)); ?></p><p><?php print l(t('Read our Blog'), 'about/blog', array('alias' => TRUE)); ?></p><p><a href="http://www.unocha.org" target="_blank"><img alt="OCHA logo" src="/sites/all/themes/humanitarianresponse/assets/images/ocha.png"></a></p>
    </div>
    <div id="footer-second" class="col-md-6">
      <div class="col-md-3">
        <div class="column"><a href="http://fts.unocha.org" target="_blank"><div class="footer-logo footer-logos-fts"></div></a></div>
        <div class="column"><a href="http://www.irinnews.org" target="_blank"><div class="footer-logo footer-logos-irin"></div></a></div>
        <div class="column"><a href="http://www.gdacs.org" target="_blank"><div class="footer-logo footer-logos-gdacs"></div></a></div>
        <div class="column"><a href="http://data.hdx.rwlabs.org" target="_blank"><div class="footer-logo footer-logos-hdx"></div></a></div>
      </div>

      <div class="col-md-3">
        <div class="column"><a href="http://www.unocha.org/cerf/" target="_blank"><div class="footer-logo footer-logos-cerf"></div></a></div>
        <div class="column"><a href="http://www.unocha.org/cap/" target="_blank"><div class="footer-logo footer-logos-cap"></div></a></div>
        <div class="column"><a href="http://www.reliefweb.int/" target="_blank"><div class="footer-logo footer-logos-reliefweb"></div></a></div>
        <div class="column"><a href="http://www.insarag.org/" target="_blank"><div class="footer-logo footer-logos-insarag"></div></a></div>
      </div>

      <div class="col-md-3">
        <div class="column"><a href="http://www.humanitarianinfo.org/iasc/" target="_blank"><div class="footer-logo footer-logos-iasc"></div></a></div>
        <div class="column"><a href="http://www.redhum.org" target="_blank"><div class="footer-logo footer-logos-redhum"></div></a></div>
        <div class="column"><a href="http://www.preventionweb.net/" target="_blank"><div class="footer-logo footer-logos-pw"></div></a></div>
      </div>

      <div class="col-md-3">
        <div class="column"><a href="http://www.hewsweb.org" target="_blank"><div class="footer-logo footer-logos-hews"></div></a></div>
        <div class="column"><a href="http://vosocc.unocha.org" target="_blank"><div class="footer-logo footer-logos-vosocc"></div></a></div>
	<div class="column"><a href="http://www.worldhumanitariansummit.org" target="_blank"><div class="footer-logo footer-logos-whs"></div></a></div>
      </div>
    </div>
    <div id = "footer-third" class="col-md-3">
      <i class="fa fa-envelope"></i> <a href="mailto:info@humanitarianresponse.info">info@humanitarianresponse.info</a><br />
      <i class="fa fa-question-circle"></i> <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a><br />
      <i class="fa fa-info-circle"></i> <?php print l('humanitarianresponse.info', '<front>'); ?><br />
      <i class="fa fa-rss-square"></i> <?php print l(t('RSS feed'), 'feed'); ?><br />
      <i class="fa <?php ($follow_us_link_status == 'flag') ? print 'fa-check' : print 'fa-times'; ?>"></i> <a href="<?php print $follow_us_link_href; ?>"><?php print $follow_us_link_title; ?></a>
    </div>
  </div>
</footer>

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
  <header class="cd-hri-header hidden-print" role="banner">
    <div class="cd-hri-global-header">
      <div class="cd-hri-container cd-hri-global-header__inner container">
        <div class="cd-hri-global-header__sites cd-hri-dropdown">
          <button type="button" class="cd-hri-global-header__sites-btn" data-toggle="dropdown" id="cd-hri-related-platforms-toggle">
            <?php print t('Related platforms'); ?>
            <i class="fa fa-caret-down" aria-hidden="true"></i>
          </button>
          <ul class="cd-hri-dropdown-menu dropdown-menu" role="menu" id="cd-hri-related-platforms" aria-hidden="true" aria-labelledby="cd-hri-related-platforms-toggle">
            <li><a href="https://fts.unocha.org/">Financial Tracking Services</a></li>
            <li><a href="https://humdata.org/">Humanitarian Data Exchange</a></li>
            <li><a href="https://humanitarian.id/">Humanitarian ID</a></li>
            <li><a href="https://reliefweb.int/">ReliefWeb</a></li>
          </ul>
        </div>
        <div class="cd-hri-global-header__nav">
          <div class="cd-hri-nav cd-hri-nav--secondary">
            <?php print $hr_favorite_spaces; ?>
            <?php print render($page['top']); ?>
          </div>

        </div>
      </div>
    </div>
    <div class="cd-hri-site-header">
      <div class="cd-hri-container cd-hri-site-header__inner container">
        <a href="<?php print $front_page; ?>" class="cd-hri-site-header__logo">
          <span class="sr-only">Humanitarian Response</span>
        </a>
        <div class="cd-hri-site-header__search">
          <?php print render($page['branding']); ?>
        </div>
        <div class="cd-hri-dropdown">
          <button type="button" id="cd-hri-nav-toggle" class="cd-hri-site-header__nav-toggle" data-toggle="dropdown">
            <span class="cd-hri-site-header__nav-toggle-inner" aria-hidden="true">
            </span>
            <span class="sr-only"><?php print t('Main menu') ?></span>
          </button>
          <nav role="navigation" class="cd-hri-site-header__nav dropdown-menu" aria-labelledby="cd-hri-nav-toggle">
            <ul class="cd-hri-nav cd-hri-nav--primary">
              <?php print render($main_menu_dropdown); ?>
            </ul>
          </nav>
        </div>
      </div>
    </div>
  </header>

  <?php if ($hr_tabs): ?>
    <div class="container">
      <div class="col-sm-12">
        <ul class="breadcrumbs">
          <li class="breadcrumbs-item">
            <a href="<?php print $front_page; ?>">
              <?php print t('Home') ?>
            </a>
          </li>
          <?php $num_hr_tabs = count($hr_tabs); foreach ($hr_tabs as $i => $hr_tab) { ?>
            <li class="breadcrumbs-item <?php if ($i == $num_hr_tabs - 1) { print ' active'; } ?>"><?php print $hr_tab; ?></li>
          <?php } ?>
        </ul>
      </div>
    </div>
  <?php endif; ?>

  <div id="secondary-navigation">
    <div class="container">
      <?php print render($page['navigation']); ?>
    </div>
  </div>

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
        <div class="column"><a href="https://humanitarian.id" target="_blank"><div class="footer-logo footer-logos-hid"></div></a></div>
        <div class="column"><a href="http://www.gdacs.org" target="_blank"><div class="footer-logo footer-logos-gdacs"></div></a></div>
      </div>

      <div class="col-md-3">
        <div class="column"><a href="http://www.unocha.org/cerf/" target="_blank"><div class="footer-logo footer-logos-cerf"></div></a></div>
        <div class="column"><a href="http://www.reliefweb.int/" target="_blank"><div class="footer-logo footer-logos-reliefweb"></div></a></div>
        <div class="column"><a href="http://www.insarag.org/" target="_blank"><div class="footer-logo footer-logos-insarag"></div></a></div>
      </div>

      <div class="col-md-3">
        <div class="column"><a href="https://interagencystandingcommittee.org/" target="_blank"><div class="footer-logo footer-logos-iasc"></div></a></div>
        <div class="column"><a href="http://www.redhum.org" target="_blank"><div class="footer-logo footer-logos-redhum"></div></a></div>
        <div class="column"><a href="http://www.preventionweb.net/" target="_blank"><div class="footer-logo footer-logos-pw"></div></a></div>
      </div>

      <div class="col-md-3">
        <div class="column"><a href="<?php print variable_get('humdata_base_url', 'https://data.humdata.org'); ?>" target="_blank"><div class="footer-logo footer-logos-hdx"></div></a></div>
        <div class="column"><a href="http://vosocc.unocha.org" target="_blank"><div class="footer-logo footer-logos-vosocc"></div></a></div>
        <div class="column"><a href="http://www.worldhumanitariansummit.org" target="_blank"><div class="footer-logo footer-logos-whs"></div></a></div>
      </div>
    </div>
    <div id = "footer-third" class="col-md-3">
      <i class="fa fa-envelope"></i> <a href="mailto:info@humanitarianresponse.info">info@humanitarianresponse.info</a><br />
      <i class="fa fa-question-circle"></i> <a href="mailto:help@humanitarianresponse.info">help@humanitarianresponse.info</a><br />
      <i class="fa fa-info-circle"></i> <?php print l('humanitarianresponse.info', '<front>'); ?><br />
      <i class="fa fa-rss-square"></i> <?php print l(t('RSS feed'), 'feed'); ?><br />
      <i class="fa <?php ($follow_us_link_status == 'flag') ? print 'fa-check' : print 'fa-times'; ?>"></i> <?php print l($follow_us_link_title, $follow_us_link_href, array('attributes' => array('rel' => 'nofollow'))); ?>
    </div>
  </div>
</footer>

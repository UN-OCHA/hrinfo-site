<?php

/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>
<div class="page-wrapper">
  <a href="#main-content" class="skip-link element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>

  <?php include 'cd/cd-header/cd-header.inc'; ?>

  <?php if($messages): ?>
    <div class="cd-container">
      <?php print $messages; ?>
    </div>
  <?php endif; ?>

  <?php if ($hr_tabs): ?>
    <div class="cd-container">
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

<!--  --><?php //if($is_front): ?>
<!--    <div id="front-banner"></div>-->
<!--  --><?php //endif; ?>


  <!-- Logo for printed pages -->
  <div class="cd-container visible-print-block" style="position:relative">
    <?php if ($logo): ?>
      <img src="/<?php print drupal_get_path('theme',$GLOBALS['theme'])?>/img/logos/print-logo.png" alt="Humanitarianresponse Logo" style="position: absolute; right:40px; top: 10px" />
    <?php endif; ?>
  </div>

  <div class="cd-container" id="main-content">
    <div class="block__content">
      <div id="hr-decommissioner-banner">
        <?php print t('This site is archived. Please find the new site - ReliefWeb Response - at <a href="https://response.reliefweb.int/">https://response.reliefweb.int/</a>') ?>
      </div>
    </div>
    <?php if (!empty($page['sidebar_first'])): ?>
      <aside id="sidebar-first" class="col-md-3 hidden-print" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>
    <?php endif; ?>

    <div id="content-wrapper" <?php if(!empty($page['sidebar_first'])) print 'class="col-md-9"'; ?>>
      <div id="page-header">

        <?php if ($title): ?>
          <h1 class="page-heading">
            <?php print $title; ?>
            <?php if ($node_banner_outdated): ?>
              <span class="node-outdated" style="font-size: 14px; color: #232323; float:right; text-align: right">
                (<?php print $node_banner_outdated; ?>)
              </span>
            <?php endif; ?>
          </h1>
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
    </div>

  </div>
</div>

<?php if ($page['footer_soft']): ?>
  <?php print render($page['footer_soft']); ?>
<?php endif; ?>

<?php include 'cd/cd-footer/cd-footer.inc'; ?>

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

  <div class="cd-container" id="main-content">
    <?php if($tabs): ?>
      <?php print render($tabs); ?>
    <?php endif; ?>

    <?php if ($title): ?>
      <h1 class="page-heading"><?php print $title; ?></h1>
    <?php endif; ?>
    <?php print render($page['content']); ?>

    <?php if ($page['sidebar_first']): ?>
      <?php print render($page['sidebar_first']); ?>
    <?php endif; ?>
  </div>
</div>

<?php if ($page['footer_soft']): ?>
  <?php print render($page['footer_soft']); ?>
<?php endif; ?>

<?php include 'cd/cd-footer/cd-footer.inc'; ?>

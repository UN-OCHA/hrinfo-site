<?php

/**
 * @file
 * Default theme implementation to display a region.
 *
 * Available variables:
 * - $content: The content for this region, typically blocks.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - region: The current template type, i.e., "theming hook".
 *   - region-[name]: The name of the region with underscores replaced with
 *     dashes. For example, the page_top region would have a region-page-top
 *     class.
 * - $region: The name of the region variable as defined in the theme's .info
 * file.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 *
 * @see template_preprocess()
 * @see template_preprocess_region()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<section class="cd-soft-footer">
  <div class="cd-container cd-soft-footer__inner">

    <div class="col-md-12 footer-logos">
        <div class="column col-md-1"><a href="http://fts.unocha.org" target="_blank"><div class="footer-logo footer-logo-fts"></div></a></div>
        <div class="column col-md-1"><a href="https://humanitarian.id" target="_blank"><div class="footer-logo footer-logo-hid"></div></a></div>
        <div class="column col-md-1"><a href="http://www.gdacs.org" target="_blank"><div class="footer-logo footer-logo-gdacs"></div></a></div>
        <div class="column col-md-1"><a href="http://www.unocha.org/cerf/" target="_blank"><div class="footer-logo footer-logo-cerf"></div></a></div>
        <div class="column col-md-1"><a href="http://www.reliefweb.int/" target="_blank"><div class="footer-logo footer-logo-reliefweb"></div></a></div>
        <div class="column col-md-1"><a href="http://www.insarag.org/" target="_blank"><div class="footer-logo footer-logos-insarag"></div></a></div>
        <div class="column col-md-1"><a href="https://interagencystandingcommittee.org/" target="_blank"><div class="footer-logo footer-logo-iasc"></div></a></div>
        <div class="column col-md-1"><a href="http://www.redhum.org" target="_blank"><div class="footer-logo footer-logo-redhum"></div></a></div>
        <div class="column col-md-1"><a href="http://www.preventionweb.net/" target="_blank"><div class="footer-logo footer-logo-pw"></div></a></div>
        <div class="column col-md-1"><a href="<?php print variable_get('humdata_base_url', 'https://data.humdata.org'); ?>" target="_blank"><div class="footer-logo footer-logo-hdx"></div></a></div>
        <div class="column col-md-1"><a href="http://vosocc.unocha.org" target="_blank"><div class="footer-logo footer-logo-vosocc"></div></a></div>
        <div class="column col-md-1"><a href="http://agendaforhumanity.org/" target="_blank"><div class="footer-logo footer-logo-pact"></div></a></div>
    </div>

  </div>
</section>

<?php

/**
 * @file
 * Template for displaying contact information from HID.
 */
?>

<article class="hid-contact" itemscope itemtype="https://schema.org/Person">
  <?php
    if (!empty($settings['show_name'])) {
  ?>
    <span itemprop="name">
      <strong>
        <?php empty($url) ? print "$contact->name" : print l("$contact->name", $url); ?>
      </strong>
    </span>
  <?php
    }
    if (!empty($settings['show_organization']) && !empty($contact->organization)) {
  ?>
    <div itemscope itemtype="https://schema.org/Organization">
      <span itemprop="name" > <?php print $contact->organization->name; ?> </span>
    </div>
  <?php
    }
    if (!empty($settings['show_job_title']) && $contact->job_title) {
  ?>
  <div itemprop="jobTitle">
    <span><?php print $contact->job_title; ?></span>
  </div>
  <?php
    }
    if (!empty($settings['show_email'])) {
  ?>
  <div itemprop="email">
    <span><?php print $contact->email; ?></span>
  </div>
  <?php
    }
    if (!empty($settings['show_phone_number']) && !empty($contact->phone_number)) {
    ?>
        <div itemprop="contactPoint" itemscope itemtype="http://schema.org/ContactPoint">
          <span itemprop="telephone"><?php print $contact->phone_number; ?></span>
          (<span itemprop="contactType"><?php print $contact->phone_number_type ?></span>)
        </div>
    <?php
    }
    ?>
</article>

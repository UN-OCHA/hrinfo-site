<?php
  /**
   * @file: template for displaying contact information from HID.
   */
?>

<article class="hid-contact" itemscope itemtype="https://schema.org/Person">
  <span itemprop="name">
    <strong>
      <?php empty($url) ? print "$contact->name" : print l("$contact->name", $url); ?>
    </strong>
  </span>

  <div itemscope itemtype="https://schema.org/Organization">
    <span itemprop="name" > <?php print $contact->organization->name; ?> </span>
  </div>
  <div itemprop="jobTitle">
    <span><?php print $contact->job_title; ?></span>
  </div>
  <div itemprop="email">
    <span><?php print $contact->email; ?></span>
  </div>
  <?php
    if (!empty($contact->phone_number)) {
    ?>
        <div itemprop="contactPoint" itemscope itemtype="http://schema.org/ContactPoint">
          <span itemprop="telephone"><?php print $contact->phone_number; ?></span>
          (<span itemprop="contactType"><?php print $contact->phone_number_type ?></span>)
        </div>
    <?php
    }
    ?>
</article>

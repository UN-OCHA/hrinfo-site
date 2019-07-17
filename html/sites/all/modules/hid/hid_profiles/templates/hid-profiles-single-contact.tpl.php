<?php
  /**
   * @file: template for displaying contact information from HID.
   */
?>

<article class="hid-contact" itemscope itemtype="https://schema.org/Person">
  <span itemprop="name">
    <strong>
      <?php empty($url) ? print l("$contact->nameGiven $contact->nameFamily", $url) : print "$contact->nameGiven $contact->nameFamily"; ?>
    </strong>
  </span>

  <div itemscope itemtype="https://schema.org/Organization">
    <span itemprop="name" > <?php print $contact->organization[0]->{'name'}; ?> </span>
  </div>
  <div itemprop="jobTitle">
    <span><?php print $contact->jobtitle; ?></span>
  </div>
  <div itemprop="email">
    <span><?php print $contact->email[0]->address; ?></span>
  </div>
  <?php
    if (!empty($contact->phone)) {
      foreach ($contact->phone as $phone) {
    ?>
        <div itemprop="contactPoint" itemscope itemtype="http://schema.org/ContactPoint">
          <span itemprop="telephone"><?php print $phone->number; ?></span>
          (<span itemprop="contactType"><?php print $phone->type ?></span>)
        </div>
    <?php
      }
    }
    ?>
</article>

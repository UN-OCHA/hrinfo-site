<?php

/**
 * @file
 * File Chooser Field Instagram Photos template.
 */

?>
<!DOCTYPE HTML>
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
  <title><?php print $title; ?></title>
  <link rel="stylesheet" type="text/css" href="<?php print $module_path; ?>/css/instagram_popup.css">
  <!-- Instagram photo picker created by Minnur Yunusov -->
</head>
<body>

  <?php // #files element is required element ?>
  <div id="files"></div>

  <div class="instagram-picker-wrapper">

    <nav id="bar">
      <div class="container">
        <?php if (!empty($counts)) : ?>
          <span class="counts">
            <span class="posts"><?php print $counts['media']; ?></span>
            <span class="followed_by"><?php print $counts['followed_by']; ?></span>
            <span class="follows"><?php print $counts['follows']; ?></span>
          </span>
        <?php endif; ?>
        <span class="name">
          <?php print $profile['username']; ?>
          <?php if (!empty($profile['full_name'])) : ?>
            (<?php print $profile['full_name']; ?>)
          <?php endif; ?>
        </span>
      </div>
    </nav>

    <div id="photos">
      <?php foreach ($photos as $index => $photo) : ?>
        <a href="#" class="photo" data-index="<?php print $index; ?>" data-standard-img="<?php print $photo['standard_resolution']['url']; ?>"><img width="150" height="150" src="<?php print $photo['thumbnail']['url']; ?>" border="0" /></a>
      <?php endforeach; ?>
    </div>

    <div id="controls">
      <div class="container">
        <span id="count"></span>
        <a href="#" id="pick"><?php print $insert_label; ?></a>
        <a href="#" id="cancel"><?php print $cancel_label; ?></a>
      </div>
    </div>

</div>

<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
<script src="<?php print $module_path; ?>/js/instagram_popup.js?r=<?php print $rand; ?>"></script>

</body>
</html>

<?php

  /**
   * @file
   * Initial template for the dataset list.
   */
?>

<nav class="block-current-search">
  <section class="current-search">
    <div class="current-search-filter">
      <p><?php print t('Filter: <span class="items"><span class="num-items">%items</span> items</span> displayed', array('%items' => 0)) ?></p>
    </div>
    <div class="current-reset-filter">
      <a href="<?php print $reset_filter_link; ?>">
        <i class="reset"></i></a> <span><?php print t('Reset all filters') ?></span>
    </div>
  </section>

  <section class="text-search">
    <div class="input-group">
      <input class="search" name="datasets.title" value="" maxlength="128" type="text" placeholder="Search by title">
    </div>
  </section>
</nav>

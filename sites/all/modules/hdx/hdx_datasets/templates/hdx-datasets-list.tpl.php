<?php
  /**
   * @file
   * Initial template for the dataset list.
   */
?>

<div id="datasets-view">
</div>
<div id="datasets-list">
  <table id="datasets-list-table" class="table table-striped">
    <thead>
      <tr>
        <th><?php print t('Dataset');  ?></th>
        <th><?php print t('Last Updated');  ?></th>
        <th><?php print t('Source');  ?></th>
      </tr>
    <tbody>
    </tbody>
  </table>
  <div class="text-center">
    <ul class="pagination">
      <li class="pager-previous"><a id="previous" href=""><?php print t('Previous') ?></a></li>
      <li class="pager-next"> <a id="next" href=""><?php print t('Next') ?></a></li>
    </ul>
  </div>
</div>
<div id="loading">
  <p class="text-center lead"><i class="fa fa-spinner fa-pulse"></i> <?php print t('Please wait. Data is loading...') ?></p>
</div>

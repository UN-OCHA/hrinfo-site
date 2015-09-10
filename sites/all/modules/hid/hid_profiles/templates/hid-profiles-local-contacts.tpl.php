<?php
  // @TODO: Make the stuff translatable.
?>
<div class="feed-icon text-right"><div class="btn-group">
    <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown">
      <i class="fa fa-download"></i> <span class="caret"></span>
    </button>
    <ul class="dropdown-menu">
      <li><a id="contacts-list-pdf" href="#" target="_blank">PDF</a></li>
      <li><a id="contacts-list-csv" href="#" target="_blank">CSV</a></li>
    </ul>
  </div>
</div>
<div id="contacts-view">
</div>
<div id="contacts-list">
  <table id="contacts-list-table" class="table table-striped">
    <thead>
    <tr>
      <th>Clusters</th>
      <th>Name</th>
      <th>Email</th>
      <th>Job Title</th>
      <th>Organization</th>
      <th>Location</th>
    </tr>
    </thead>
    <tbody>
    </tbody>
  </table>
  <div class="text-center">
    <ul class="pagination">
      <li class="pager-previous"><a id="previous" href="">Previous</a></li>
      <li class="pager-next"> <a id="next" href="">Next</a></li>
    </ul>
  </div>
</div>
<div id="loading"><p class="text-center lead"><i class="fa fa-spinner fa-pulse"></i> Please wait. Data is loading...</p></div>

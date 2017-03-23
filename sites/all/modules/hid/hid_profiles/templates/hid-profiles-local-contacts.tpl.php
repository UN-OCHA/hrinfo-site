<?php
  // @TODO: Make the stuff translatable.
?>
<h2 class="pb-header">Contacts</h2>
<div class="pb-export-button-holder">
  <button type="button" class="pb-btn dropdown-toggle" data-toggle="dropdown">
    Export
  </button>
  <ul class="dropdown-menu">
    <li><a id="contacts-list-pdf" href="#" target="_blank">PDF</a></li>
    <li><a id="contacts-list-csv" href="#" target="_blank">CSV</a></li>
  </ul>
</div>
<div id="contacts-view">
</div>
<div id="contacts-list">
  <table id="contacts-list-table" class="table pb-table">
    <thead>
    <tr>
      <th class="pb-table__th-icon"><span class="sr-only">Verified</span></th>
      <th>Name</th>
      <th>Clusters</th>
      <th>Job Title</th>
      <th>Organization</th>
      <th>Location</th>
      <th>Email</th>
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

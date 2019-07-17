<?php
  // @TODO: Make the stuff translatable.
?>
<h2 class="pb-header">Contacts</h2>
<div class="pb-export-button-holder">
  <button type="button" class="pb-btn dropdown-toggle" data-toggle="dropdown">
    <svg version="1.1" xmlns="http://www.w3.org/2000/svg" width="32" height="32" viewBox="0 0 32 32">
    <path d="M15 16l-3.25-3.25-0.75 0.75 4.5 4.5 4.5-4.5-0.75-0.75-3.25 3.25v-11h-1v11zM17 11h5.4l4.375 7h-6.775v2.002c0 1.1-0.894 1.998-1.997 1.998h-5.005c-1.102 0-1.997-0.895-1.997-1.998v-2.002h-6.775l4.375-7h5.4v-1h-6l-5 8v9h25v-9l-5-8h-6v1zM21 19h6v7h-23v-7h6v1.5c0 1.381 1.115 2.5 2.496 2.5h6.008c1.379 0 2.496-1.11 2.496-2.5v-1.5z"></path>
    </svg>
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
      <th class="pb-table__th-icon"><span class="verified-icon" title="Verified"><i class="sr-only">Verified</i></span></th>
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

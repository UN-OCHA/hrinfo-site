<?php
if (isset($variables['render']) && ($variables['render'] == 'grid' || $variables['render'] == 'html')) {
  include 'j2h_' . $variables['render'] . '.tpl.php';
}

<?php

/**
 * @file
 * Region panel pane template.
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 */
?>
<<?php print $wrapper_element; ?> <?php print $wrapper_attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <<?php print $header_element; ?> <?php print $header_attributes; ?>>
      <<?php print $title_element; ?> <?php print $title_attributes; ?>>
        <?php if ($collapsible): ?>
          <a href="#" data-toggle="collapse" data-target="#<?php print $id; ?>">
            <?php print $title; ?>
          </a>
        <?php else: ?>
          <?php print $title; ?>
        <?php endif; ?>
      </<?php print $title_element; ?>>
    </<?php print $header_element; ?>>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($collapsible): ?>
     <div id="<?php print $id; ?>" class="panel-collapse collapse<?php print (!$collapsed ? ' in' : ''); ?>">
  <?php endif; ?>


  <<?php print $content_element; ?> <?php print $content_attributes; ?>>
    <?php foreach($panes as $pane) : ?>
      <?php print $pane; ?>
    <?php endforeach ?>
  </div>


  <?php if ($collapsible): ?>
    </div>
  <?php endif; ?>
</<?php print $wrapper_element; ?>>

<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $header_classes: An array of header classes keyed by field id.
 * - $header_attributes: An array of header attributes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
    <tr>
      <?php foreach ($pivot_rows as $field => $label): ?>
        <th <?php if (!empty($header_classes[$field])) { print 'class="'. $header_classes[$field] . '" '; } if (!empty($header_attributes[$field])) { print drupal_attributes($header_attributes[$field]);} ?>>
          <?php print $label; ?>
        </th>
      <?php endforeach; ?>
      <?php foreach ($header as $field => $label): ?>
        <th <?php if (!empty($header_classes[$field])) { print 'class="'. $header_classes[$field] . '" '; } if (!empty($header_attributes[$field])) { print drupal_attributes($header_attributes[$field]);} ?>>
          <?php print $label; ?>
        </th>
      <?php endforeach; ?>
    </tr>
    <?php if (!$hide_subheader) : ?>
      <?php if ($vertical) : ?>
        <?php foreach ($subheader as $field => $label): ?>
          <tr>
            <?php foreach ($header as $headerfield => $headerlabel): ?>
              <th <?php if (!empty($header_classes[$field])) { print 'class="'. $header_classes[$field] . '" '; } if (!empty($header_attributes[$field])) { print drupal_attributes($header_attributes[$field]);} ?>>
                <?php print $label; ?>
              </th>
            <?php endforeach; ?>
          </tr>
        <?php endforeach; ?>
      <?php else : ?>
        <tr>
          <?php foreach ($header as $field => $label): ?>
            <?php foreach ($subheader as $field => $label): ?>
              <th <?php if (!empty($header_classes[$field])) { print 'class="'. $header_classes[$field] . '" '; } if (!empty($header_attributes[$field])) { print drupal_attributes($header_attributes[$field]);} ?>>
                <?php print $label; ?>
              </th>
            <?php endforeach; ?>
          <?php endforeach; ?>
        </tr>
      <?php endif; ?>
    <?php endif; ?>
    </thead>
  <?php endif; ?>
  <tbody>
  <?php foreach ($rows as $row_key => $row): ?>
  <tr <?php if (!empty($row_classes[$row_key])) { print 'class="' . implode(' ', $row_classes[$row_key]) .'"';  } ?>>
    <?php foreach ($pivot_rows as $hkey => $label): ?>
      <td <?php if (!empty($row_attributes[$row_key])) { print drupal_attributes($row_attributes[$row_key]);} ?>>
        <?php print empty($row[$hkey]) ? '' : $row[$hkey]; ?>
      </td>
    <?php endforeach; ?>
    <?php if ($vertical) : ?>
      <?php foreach ($subheader as $shkey => $label): ?>
        <?php foreach ($header as $hkey => $label): ?>
          <?php $key = $shkey . ':' . $hkey; ?>
          <td <?php if (!empty($field_classes[$shkey][$row_key])) { print 'class="'. $field_classes[$shkey][$row_key] . '" '; } if (!empty($field_attributes[$shkey][$row_key])) { print drupal_attributes($field_attributes[$shkey][$row_key]);} ?>>
            <?php print empty($row[$key]) ? '' : $row[$key]; ?>
          </td>
        <?php endforeach; ?>
        </tr><tr>
      <?php endforeach; ?>
    <?php else : ?>
      <?php foreach ($header as $hkey => $label): ?>
        <?php if (!empty($aggregate_columns[$hkey])): ?>
          <td><?php print empty($row[$hkey]) ? '' : $row[$hkey]; ?></td>
        <?php else : ?>
          <?php foreach ($subheader as $shkey => $label): ?>
            <?php $key = $shkey . ':' . $hkey; ?>
            <td <?php if (!empty($field_classes[$shkey][$row_key])) { print 'class="'. $field_classes[$shkey][$row_key] . '" '; } if (!empty($field_attributes[$shkey][$row_key])) { print drupal_attributes($field_attributes[$shkey][$row_key]);} ?>>
              <?php print empty($row[$key]) ? '' : $row[$key]; ?>
            </td>
          <?php endforeach; ?>
        <?php endif; ?>
      <?php endforeach; ?>
    <?php endif; ?>
    </tr>
  <?php endforeach; ?>
  </tbody>
</table>

<h1 id="page-title" class="title">
<?php echo $variables['title_block'] ?>
</h1>
<form action="" method="GET">
<div id="j2h_filters">
    <?php
    // Dropdown filters
    foreach($variables['filters'] as $filter) { 
        $id = $filter['id'];
        $value = $filter['value'];
        ?>
        <div class="inline">
            <label for="<?php echo $id ?>">
                <?php echo $filter['label'] ?>
            </label>
            <?php 
            switch ($filter['type']) { 
                case 'dropdown':
                    $options = $filter['options'];
                    ?> 
                    <select id="<?php echo $id ?>" name="<?php echo $id ?>" class="filter">
                    <?php
                        foreach($options as $opt) {
                            $selected = ($value == $opt["value"]) ? 'selected' : '';
                            echo "<option value=".$opt["value"]." $selected>".$opt['text']."</option>";
                        }
                    ?>
                    </select>
                    <?php
                break;        
                case 'text': ?>
                    <input type="text" id="<?php echo $id ?>" name="<?php echo $id ?>" value="<?php echo $value ?>" />
                <?php
            break;
            }
            ?>
        </div>
    <?php
    }
    ?>
    
    <div class="inline">
        <input type="submit" id="search-contacts" name="" value="<?php echo t('Search') ?>" class="form-submit">
        <input type="button" id="reset" name="" value="<?php echo t("Reset") ?>" class="form-submit">
    </div>
</div>
</form>
<div id="j2h_grid">
<table>
<thead>
<tr>
    <?php 
    foreach($variables['titles'] as $title) { ?>
        <th><?php echo $title['text']; ?></th>
    <?php
    }
    ?>
</tr>
</thead>
<?php
foreach($variables['rows'] as $rg) { ?>
    <tr>
    <?php 
    foreach($variables['titles'] as $title) { ?>
        <td><?php echo $rg[$title['index']] ?></td>
    <?php
    }
    ?>
    </tr>    
<?php
}
?>
</table>
</div>

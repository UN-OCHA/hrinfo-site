<?php

/**
 * Highcharts bar stacked template.
 *
 * Note the xAxis catagories should be set. Example:
 *
 * @code
 *   $options->xAxis->categories = array('Apples', 'Oranges', 'Pears', 'Grapes', 'Bananas');
 * @endcode
 */
class FTSHighchartsOptionsBarStacked extends HighchartsOptionsBarStacked {

  public function render() {
    $options = $this->options;
    $data = $this->data();

    // Chart.
    $options->chart = (object)array(
      'renderTo' => 'container',
      'type' => 'bar',
    );

    // xAxis.
    // $options->xAxis->categories = array();

    // yAxis.
    $options->yAxis->min = 0;
    $options->yAxis->title = t('Total');

    // Legend.
    $options->legend = (object)array(
      'backgroundColor' => '#FFFFFF',
      'reversed' => TRUE,
    );

    // Tooltip.
    $options->tooltip->formatter = "function() {
      return ''+
      this.series.name +': '+ this.y +'';
    }";

    // Plot options.
    $options->plotOptions->series->stacking = 'normal';

    // Series.
    $options->series = $data;

    // Diable credits.
    $options->credits->enabled = FALSE;

    return $options;
  }

}

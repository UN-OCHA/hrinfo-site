<?php

/**
 * Interface for exporting to a given file format.
 */
interface TMGMTFileFormatInterface {

  /**
   * Return the file content for the job data.
   *
   * @param $job
   *   The translation job object to be exported.
   * @param array $conditions
   *   (optional) An array containing list of conditions.
   *
   * @return
   *   String with the file content.
   */
  function export(TMGMTJob $job, $conditions = array());

  /**
   * Validates that the given file is valid and can be imported.
   *
   * @todo this function should NOT return a job. We need a import processor
   *   instance instead to deal with the import context.
   *
   * @param string $imported_file
   *   File path to the file to be imported.
   *
   * @return TMGMTJob
   *   Returns the corresponding translation job entity if the import file is
   *   valid, FALSE otherwise.
   */
  public function validateImport($imported_file);

  /**
   * Converts an exported file content back to the translated data.
   *
   * @param string $imported_file
   *   Path to a file or an XML string to import.
   * @param bool $is_file
   *   (optional) Whether $imported_file is the path to a file or not.
   *
   * @return
   *   Translated data array.
   */
  function import($imported_file, $is_file = TRUE);
}

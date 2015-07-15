<?php

/**
 * @file
 * Contains the source plugin interface.
 */

/**
 * Interface for source plugin controllers.
 *
 * @ingroup tmgmt_source
 */
interface TMGMTSourcePluginControllerInterface extends TMGMTPluginBaseInterface {

  /**
   * Returns an array with the data structured for translation.
   *
   * @param TMGMTJobItem $job_item
   *   The job item entity.
   *
   * @see TMGMTJobItem::getData()
   */
  public function getData(TMGMTJobItem $job_item);

  /**
   * Saves a translation.
   *
   * @param TMGMTJobItem $job_item
   *   The job item entity.
   *
   * @return boolean
   *   TRUE if the translation was saved successfully, FALSE otherwise.
   */
  public function saveTranslation(TMGMTJobItem $job_item);

  /**
   * Return a title for this job item.
   *
   * @param TMGMTJobItem $job_item
   *   The job item entity.
   */
  public function getLabel(TMGMTJobItem $job_item);

  /**
   * Returns the Uri for this job item.
   *
   * @param TMGMTJobItem $job_item
   *   The job item entity.
   *
   * @see entity_uri()
   */
  public function getUri(TMGMTJobItem $job_item);

  /**
   * Returns an array of translatable source item types.
   */
  public function getItemTypes();

  /**
   * Returns the label of a source item type.
   *
   * @param $type
   *   The identifier of a source item type.
   */
  public function getItemTypeLabel($type);

  /**
   * Returns the type of a job item.
   *
   * @param TMGMTJobItem $job_item
   *   The job item.
   *
   * @return string
   *   A type that describes the job item.
   */
  public function getType(TMGMTJobItem $job_item);

  /**
   * Gets language code of the job item source.
   *
   * @param TMGMTJobItem $job_item
   *   The job item.
   *
   * @return string
   *   Language code.
   */
  public function getSourceLangCode(TMGMTJobItem $job_item);

  /**
   * Gets existing translation language codes of the job item source.
   *
   * Returns language codes that can be used as the source language for a
   * translation job.
   *
   * @param TMGMTJobItem $job_item
   *   The job item.
   *
   * @return array
   *   Array of language codes.
   */
  public function getExistingLangCodes(TMGMTJobItem $job_item);

}

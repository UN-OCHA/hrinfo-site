<?php

/**
 * @file
 * Definition of StringInterface.
 */

/**
 * Defines the locale string interface.
 */
interface StringInterface {

  /**
   * Gets the string unique identifier.
   *
   * @return int
   *   The string identifier.
   */
  public function getId();

  /**
   * Sets the string unique identifier.
   *
   * @param int $id
   *   The string identifier.
   *
   * @return StringInterface
   *   The called object.
   */
  public function setId($id);

  /**
   * Gets the parent string identifier.
   *
   * @return int
   *   The string identifier.
   */
  public function getParentId();

  /**
   * Sets the parent string identifier.
   *
   * @param int $id
   *   The string identifier.
   *
   * @return StringInterface
   *   The called object.
   */
  public function setParentId($id);

  /**
   * Gets the string version.
   *
   * @return string
   *   Version identifier.
   */
  public function getVersion();

  /**
   * Sets the string version.
   *
   * @param string $version
   *   Version identifier.
   *
   * @return StringInterface
   *   The called object.
   */
  public function setVersion($version);

  /**
   * Gets plain string contained in this object.
   *
   * @return string
   *   The string contained in this object.
   */
  public function getString();

  /**
   * Sets the string contained in this object.
   *
   * @param string $string
   *   String to set as value.
   *
   * @return StringInterface
   *   The called object.
   */
  public function setString($string);

  /**
   * Gets the string storage.
   *
   * @return StringStorageInterface
   *   The storage used for this string.
   */
  public function getStorage();

  /**
   * Sets the string storage.
   *
   * @param StringStorageInterface $storage
   *   The storage to use for this string.
   *
   * @return StringInterface
   *   The called object.
   */
  public function setStorage(StringStorageInterface $storage);

  /**
   * Checks whether the object is not saved to storage yet.
   *
   * @return bool
   *   TRUE if the object exists in the storage, FALSE otherwise.
   */
  public function isNew();

  /**
   * Checks whether the object is a source string.
   *
   * @return bool
   *   TRUE if the object is a source string, FALSE otherwise.
   */
  public function isSource();

  /**
   * Checks whether the object is a translation string.
   *
   * @return bool
   *   TRUE if the object is a translation string, FALSE otherwise.
   */
  public function isTranslation();

  /**
   * Sets an array of values as object properties.
   *
   * @param array $values
   *   Array with values indexed by property name.
   * @param bool $override
   *   (optional) Whether to override already set fields, defaults to TRUE.
   *
   * @return StringInterface
   *   The called object.
   */
  public function setValues(array $values, $override = TRUE);

  /**
   * Gets field values that are set for given field names.
   *
   * @param array $fields
   *   Array of field names.
   *
   * @return array
   *   Array of field values indexed by field name.
   */
  public function getValues(array $fields);

  /**
   * Saves string object to storage.
   *
   * @return StringInterface
   *   The called object.
   *
   * @throws StringStorageException
   *   In case of failures, an exception is thrown.
   */
  public function save();

  /**
   * Deletes string object from storage.
   *
   * @return StringInterface
   *   The called object.
   *
   * @throws StringStorageException
   *   In case of failures, an exception is thrown.
   */
  public function delete();

  /**
   * Get the translation group of this translation.
   *
   * @return string
   *   The textgroup set for the current string
   */
  public function getTextgroup();

  /**
   * Set the translation group of this translation.
   *
   * @param string $textgroup
   *   The text group to set for the given string.
   */
  public function setTextgroup($textgroup);

}

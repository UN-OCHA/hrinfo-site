<?php

/**
 * Provides an interface for a Google tag container manager.
 */
interface ContainerManagerInterface {

  /**
   * Prepares directory for and saves snippet files for a container.
   *
   * @param GTMContainer $container
   *   The container configuration entity.
   *
   * @return bool
   *   Whether the files were saved.
   */
  public function createAssets($container);

  /**
   * Saves JS snippet files based on current settings.
   *
   * @param GTMContainer $container
   *   The container configuration entity.
   *
   * @return bool
   *   Whether the files were saved.
   */
  public function saveSnippets($container);

  /**
   * Adds render array items of page attachments.
   *
   * @param array $page
   *   The page render array.
   */
  public function getScriptAttachments(array &$page);

  /**
   * Adds render array items of page top attachments.
   *
   * @param array $page
   *   The page render array.
   */
  public function getNoScriptAttachments(array &$page);

  /**
   * Prepares directory for and saves snippet files for all containers.
   *
   * @return bool
   *   Whether the files were saved.
   */
  public function createAllAssets();

}

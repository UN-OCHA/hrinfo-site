<?php

/**
 * @file
 * Contains \Drupal\hr_api\Plugin\resource\DataProviderOptimized.
 */

namespace Drupal\hr_api\Plugin\resource;

use Drupal\restful\Plugin\resource\DataProvider\DataProviderEntity;
use Drupal\restful\Plugin\resource\DataProvider\DataProviderInterface;
use Drupal\restful\Http\RequestInterface;
use Drupal\restful\Exception\ForbiddenException;

class DataProviderOptimized  extends DataProviderEntity implements DataProviderInterface {
  /**
   * Overrides DataProviderEntity::getQueryForList().
   *
   * Expose only published nodes.
   */
  public function getQueryForList() {
    $query = parent::getQueryForList();
    if ($this->entityType === 'node') {
      $query->propertyCondition('status', NODE_PUBLISHED);
    }
    return $query;
  }

  /**
   * Overrides DataProviderEntity::getQueryCount().
   *
   * Only count published nodes.
   */
  public function getQueryCount() {
    $query = parent::getQueryCount();
    if ($this->entityType === 'node') {
      $query->propertyCondition('status', NODE_PUBLISHED);
    }
    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function discover($path = NULL) {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function entityPreSave(\EntityDrupalWrapper $wrapper) {
    if ($this->entityType === 'node') {
      $node = $wrapper->value();
      if (!empty($node->nid)) {
        // Node is already saved.
        return;
      }
      node_object_prepare($node);
      $node->uid = $this->getAccount()->uid;
      $node->path['pathauto'] = TRUE;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function create($object) {
    $this->validateBody($object);
    $entity_info = $this->getEntityInfo();
    $bundle_key = $entity_info['entity keys']['bundle'];
    // TODO: figure out how to derive the bundle when posting to a resource with
    // multiple bundles.
    $bundle = reset($this->bundles);
    $values = $bundle_key ? array($bundle_key => $bundle) : array();

    $entity = entity_create($this->entityType, $values);

    /* @var \EntityDrupalWrapper $wrapper */
    $wrapper = entity_metadata_wrapper($this->entityType, $entity);

    $this->setPropertyValues($wrapper, $object, TRUE);

    if ($this->checkEntityAccess('create', $this->entityType, $entity) === FALSE) {
      // User does not have access to create entity.
      throw new ForbiddenException('You do not have access to create a new resource.');
    }

    // The access calls use the request method. Fake the view to be a GET.
    $old_request = $this->getRequest();
    $this->getRequest()->setMethod(RequestInterface::METHOD_GET);
    $output = array($this->view($wrapper->getIdentifier()));
    // Put the original request back to a POST.
    $this->request = $old_request;

    return $output;
  }

  /**
   * {@inheritdoc}
   */
  public function update($identifier, $object, $replace = FALSE) {
    global $language;
    $this->validateBody($object);
    $entity_id = $this->getEntityIdByFieldId($identifier);
    $this->isValidEntity('update', $entity_id);

    /* @var \EntityDrupalWrapper $wrapper */
    $wrapper = entity_metadata_wrapper($this->entityType, $entity_id);
    $handler  = entity_translation_get_handler($this->entityType, $wrapper->value());
    $translations = $handler->getTranslations();
    $languages = array_keys($translations->data);
    if (!in_array($language->language, $languages)) {
      // Create a translation.
      $translation = array(
        'translate' => 0,
        'status' => 1,
        'language' => $language->language,
        'source' => $translations->original,
      );
      $handler->setTranslation($translation);
    }
    $wrapper_translated = $wrapper->language($language->language);

    $this->setPropertyValues($wrapper_translated, $object, $replace);

    // Set the HTTP headers.
    $this->setHttpHeader('Status', 201);

    if (!empty($wrapper_translated->url) && $url = $wrapper_translated->url->value()) {
      $this->setHttpHeader('Location', $url);
    }

    // The access calls use the request method. Fake the view to be a GET.
    $old_request = $this->getRequest();
    $this->getRequest()->setMethod(RequestInterface::METHOD_GET);
    $output = array($this->view($identifier));
    // Put the original request back to a PUT/PATCH.
    $this->request = $old_request;

    return $output;
  }
}

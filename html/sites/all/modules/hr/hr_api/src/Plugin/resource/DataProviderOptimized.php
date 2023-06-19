<?php

namespace Drupal\hr_api\Plugin\resource;

use Drupal\restful\Exception\ForbiddenException;
use Drupal\restful\Exception\UnprocessableEntityException;
use Drupal\restful\Http\RequestInterface;
use Drupal\restful\Plugin\resource\DataProvider\DataProviderEntity;
use Drupal\restful\Plugin\resource\DataProvider\DataProviderInterface;

/**
 * Class definition.
 */
class DataProviderOptimized extends DataProviderEntity implements DataProviderInterface {

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
    // @todo figure out how to derive the bundle when posting to a resource with
    // multiple bundles.
    $bundle = reset($this->bundles);
    $values = $bundle_key ? array($bundle_key => $bundle) : array();

    $entity = entity_create($this->entityType, $values);

    /** @var \EntityDrupalWrapper $wrapper */
    $wrapper = entity_metadata_wrapper($this->entityType, $entity);

    $this->setPropertyValues($wrapper, $object, TRUE);

    if ($this->checkEntityAccess('create', $this->entityType, $entity) === FALSE) {
      // User does not have access to create entity.
      throw new ForbiddenException('You do not have access to create a new resource.');
    }

    // Check that user is allowed to post in operation.
    $user = $this->getAccount();
    $admin = user_role_load_by_name('administrator');
    $editor = user_role_load_by_name('editor');
    if (!user_has_role($admin->rid) && !user_has_role($editor->rid)) {
      foreach ($entity->og_group_ref[LANGUAGE_NONE] as $space) {
        $roles = og_get_user_roles('node', $space['target_id'], $user->uid);
        if (in_array('bundle member', $roles)) {
          $found = FALSE;
          foreach ($entity->field_bundles[LANGUAGE_NONE] as $bundle) {
            $bundle_roles = og_get_user_roles('node', $bundle['target_id'], $user->uid);
            if (in_array('manager', $bundle_roles) || in_array('editor', $bundle_roles) || in_array('contributor', $bundle_roles)) {
              $found = TRUE;
            }
          }
          if (!$found) {
            throw new ForbiddenException('You do not have permission to post in this space');
          }
        }
      }
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

    /** @var \EntityDrupalWrapper $wrapper */
    $wrapper = entity_metadata_wrapper($this->entityType, $entity_id);
    $handler = entity_translation_get_handler($this->entityType, $wrapper->value());
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

  /**
   * Validates an entity's fields before they are saved.
   */
  protected function validateFields($wrapper) {
    try {
      $entity = $wrapper->value();
      if (isset($entity->og_group_ref) && user_access('administer group')) {
        foreach ($entity->og_group_ref[LANGUAGE_NONE] as &$item) {
          $item['field_mode'] = 'admin';
        }
      }
      if (isset($entity->field_bundles) && user_access('administer group')) {
        foreach ($entity->field_bundles[LANGUAGE_NONE] as &$item) {
          $item['field_mode'] = 'admin';
        }
      }
      field_attach_validate($wrapper->type(), $entity);
    }
    catch (\FieldValidationException $e) {
      throw new UnprocessableEntityException($e->getMessage());
    }
  }

}

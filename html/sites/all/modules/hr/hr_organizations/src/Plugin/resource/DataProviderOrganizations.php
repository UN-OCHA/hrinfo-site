<?php

namespace Drupal\hr_organizations\Plugin\resource;

use Drupal\restful\Plugin\resource\DataProvider\DataProviderTaxonomyTerm;
use Drupal\restful\Plugin\resource\DataProvider\DataProviderInterface;
use Drupal\restful\Http\RequestInterface;

/**
 * Class definition.
 */
class DataProviderOrganizations extends DataProviderTaxonomyTerm implements DataProviderInterface {

  /**
   * {@inheritdoc}
   */
  public function discover($path = NULL) {
    return array();
  }

  /**
   * Adds query tags and metadata to the EntityFieldQuery.
   */
  protected function addExtraInfoToQuery($query) {
    parent::addExtraInfoToQuery($query);
    $query->addTag('hr_organizations_acronym');
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

}

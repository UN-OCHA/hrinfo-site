<?php

namespace Drupal\hr_api\Plugin\resource\fields;

use Drupal\restful\Exception\InaccessibleRecordException;
use Drupal\restful\Exception\UnprocessableEntityException;
use Drupal\restful\Http\Request;
use Drupal\restful\Http\RequestInterface;
use Drupal\restful\Plugin\resource\Field\ResourceFieldEntity;
use Drupal\restful\Plugin\resource\Field\ResourceFieldEntityInterface;

/**
 * Class definition.
 */
class ResourceFieldEntityMinimal extends ResourceFieldEntity implements ResourceFieldEntityInterface {

  /**
   * Do something with or to a single value.
   */
  protected function singleValue(\EntityMetadataWrapper $property_wrapper, \EntityDrupalWrapper $wrapper, $account) {
    if ($resource = $this->getResource()) {
      // @todo The resource input data in the field definition has changed.
      // Now it does not need to be keyed by bundle since you don't even need
      // an entity to use the resource based field.
      $embedded_identifier = $this->propertyIdentifier($property_wrapper);
      // Allow embedding entities with ID 0, like the anon user.
      if (empty($embedded_identifier) && $embedded_identifier !== 0) {
        return NULL;
      }
      if (isset($resource['fullView']) && $resource['fullView'] === FALSE) {
        return $embedded_identifier;
      }
      // We support dot notation for the sparse fieldsets. That means that
      // clients can specify the fields to show based on the "fields" query
      // string parameter.
      $parsed_input = array(
        'fields' => implode(',', $this->nestedDottedChildren('fields')),
        'include' => implode(',', $this->nestedDottedChildren('include')),
        'filter' => $this->nestedDottedChildren('filter'),
      );
      $parsed_input['fields'] = 'id,label,self,iso3';
      $request = Request::create('', array_filter($parsed_input), RequestInterface::METHOD_GET);

      // Get a plugin (that can be altered with decorators.
      $embedded_resource = restful()->getResourceManager()->getPluginCopy(sprintf('%s:%d.%d', $resource['name'], $resource['majorVersion'], $resource['minorVersion']));
      // Configure the plugin copy with the sub-request and sub-path.
      $embedded_resource->setPath($embedded_identifier);
      $embedded_resource->setRequest($request);
      $embedded_resource->setAccount($account);
      $metadata = $this->getMetadata($wrapper->getIdentifier());
      $metadata = $metadata ?: array();
      $metadata[] = $this->buildResourceMetadataItem($property_wrapper);
      $this->addMetadata($wrapper->getIdentifier(), $metadata);
      try {
        // Get the contents to embed in place of the reference ID.
        /** @var ResourceFieldCollection $embedded_entity */
        $embedded_entity = $embedded_resource
          ->getDataProvider()
          ->view($embedded_identifier);
      }
      catch (InaccessibleRecordException $e) {
        // If you don't have access to the embedded entity is like not having
        // access to the property.
        return NULL;
      }
      catch (UnprocessableEntityException $e) {
        // If you access a nonexistent embedded entity.
        return NULL;
      }
      // Test if the $embedded_entity meets the filter or not.
      if (empty($parsed_input['filter'])) {
        return $embedded_entity;
      }
      foreach ($parsed_input['filter'] as $filter) {
        // Filters only apply if the target is the current field.
        if (!empty($filter['target']) && $filter['target'] == $this->getPublicName() && !$embedded_entity->evalFilter($filter)) {
          // This filter is not met.
          return NULL;
        }
      }
      return $embedded_entity;
    }

    if ($this->getFormatter()) {
      // Get value from field formatter.
      $value = $this->formatterValue($property_wrapper, $wrapper);
    }
    else {
      // Single value.
      $value = $this->fieldValue($property_wrapper);
    }

    return $value;
  }

}

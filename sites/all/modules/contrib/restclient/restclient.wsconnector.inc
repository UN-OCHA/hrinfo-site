<?php

/**
 * @file
 * Default implementation of wsdata classes
 */



if (class_exists('WsConnector')) {

  class restclient_wsconnector extends WsConnector {

    public function supportsCaching() {
      return TRUE;
    }

    public function getMethods() {
      return array(
        'single' => array(
          'create' => t('RESTful create method (POST)'),
          'read' => t('RESTful read method (GET)'),
          'update' => t('RESTful update method (PUT)'),
          'delete' => t('RESTful delete method (DELETE)'),
          'index' => t('RESTful index method (GET)'),
        ),
        'multiple' => array(
          'action' => t('RESTful action (POST)'),
        ),
      );
    }

    /**
     * Preprocess some options prior to making the web service request
     */
    protected function restclientPrepareWsCall(&$type, &$method, &$arguments, &$options) {
      // Allow the create/update methods to be altered
      if ($type == 'create' and isset($options['create_method'])) {
        $type = $options['create_method'];
      }

      // If the arguments aren't a simple string, we need to get RESTClient to
      // process it into a string
      if (!empty($arguments) and !is_string($arguments)) {
        $options['data'] = $arguments;
        $arguments = NULL;
      }

      if ($type == 'update' and isset($options['update_method'])) {
        $type = $options['update_method'];
      }

      if (isset($options['accept-type'])) {
        $method = "." . $options['accept-type'];
      }

      // Set cache override options to force cache times
      if (isset($this->cacheDefaultTime) and isset($this->cacheDefaultOverride)) {
        $options['cache_default_time'] = $this->cacheDefaultTime;
        $options['cache_default_override'] = $this->cacheDefaultOverride;
      }
    }

    /**
     * Perform a create method request (e.g. POST)
     */
    protected function restclientCreate(&$type, &$method, &$arguments, &$options, $errorHandling) {
      $variables = array('endpoint' => $this->endpoint, 'body' => $arguments) + $options;
      if (empty($arguments)) {
        unset($variables['body']);
      }
      $response = restclient_post($method, $variables);
      if (restclient_response_code($response) != RESTCLIENT_RESPONSE_SUCCESS) {
        if ($errorHandling) {
          // don't cache error responses
          $this->expires = 0;
          return $response;
        }
        else {
          return FALSE;
        }
      }
      else {
        return $response->data;
      }
    }

    /**
     * Perform a read method request (e.g. GET)
     */
    protected function restclientRead(&$type, &$method, &$arguments, &$options, $errorHandling) {
      $response = restclient_get($method, array('endpoint' => $this->endpoint) + $options);
      // @todo add support for more 200 class response codes
      if (restclient_response_code($response) != RESTCLIENT_RESPONSE_SUCCESS) {
        if ($errorHandling) {
          // don't cache error responses
          $this->expires = 0;
          return $response;
        }
        else {
          return FALSE;
        }
      }
      else {
        if (isset($response->expires)) {
          $this->expires = $response->expires;
        }
        return $response->data;
      }
    }

    /**
     * Perform an update method request (e.g. PUT)
     */
    protected function restclientUpdate(&$type, &$method, &$arguments, &$options, $errorHandling) {
      $variables = array('endpoint' => $this->endpoint, 'body' => $arguments) + $options;
      if (empty($arguments)) {
        unset($variables['body']);
      }
      $response = restclient_put($method, $variables);
      if (restclient_response_code($response) != RESTCLIENT_RESPONSE_SUCCESS) {
        if ($errorHandling) {
          // don't cache error responses
          $this->expires = 0;
          return $response;
        }
        else {
          return FALSE;
        }
      }
      else {
        return $response->data;
      }
    }

    /**
     * Perform a delete method request (e.g. DELETE)
     */
    protected function restclientDelete(&$type, &$method, &$arguments, &$options, $errorHandling) {
      $response = restclient_delete($method, array('endpoint' => $this->endpoint) + $options);
      if (restclient_response_code($response) != RESTCLIENT_RESPONSE_SUCCESS) {
        if ($errorHandling) {
          // don't cache error responses
          $this->expires = 0;
          return $response;
        }
        else {
          return FALSE;
        }
      }
      else {
        return $response->data;
      }
    }

    /**
     * Perform a index method request (e.g. GET)
     */
    protected function restclientIndex(&$type, &$method, &$arguments, &$options, $errorHandling) {
      $response = restclient_get($method, array('endpoint' => $this->endpoint) + $options);
      // @todo add support for more 200 class response codes
      if (restclient_response_code($response) != RESTCLIENT_RESPONSE_SUCCESS) {
        if ($errorHandling) {
          // don't cache error responses
          $this->expires = 0;
          return $response;
        }
        else {
          return FALSE;
        }
      }
      else {
        if (isset($response->expires)) {
          $this->expires = $response->expires;
        }
        return $response->data;
      }
    }

    /**
     * Implements WsConnector->wscall().
     */
    public function wscall($type, $method, $arguments, $options) {
      $this->restclientPrepareWsCall($type, $method, $arguments, $options);

      // check speficied error handling behaviour from options
      $errorHandling = array_key_exists('error_handling', $options);

      switch ($type) {
        case 'create':
          return $this->restclientCreate($type, $method, $arguments, $options, $errorHandling);
        case 'read':
          return $this->restclientRead($type, $method, $arguments, $options, $errorHandling);
        case 'update':
          return $this->restclientUpdate($type, $method, $arguments, $options, $errorHandling);
        case 'delete':
          return $this->restclientDelete($type, $method, $arguments, $options, $errorHandling);
        case 'index':
          return $this->restclientIndex($type, $method, $arguments, $options, $errorHandling);
	      default:
          // Make an actionable request (i.e. generic POST)
          if (drupal_substr($type,0,7) == 'action_') {
            $variables = array('endpoint' => $this->endpoint, 'body' => $arguments) + $options;
            if (empty($arguments)) {
              unset($variables['body']);
            }
            $response = restclient_post($method, $variables);
            if (restclient_response_code($response) != RESTCLIENT_RESPONSE_SUCCESS) {
              if ($errorHandling) {
                // don't cache error responses
                $this->expires = 0;
                return $response;
              }
              else {
                return FALSE;
              }
            }
            else {
              return $response->data;
            }
         }
      }
    }

    /**
     * Custom impelementation of update
     *
     * With REST, the ID is part of the URL, so we don't need to included it
     * in the body.
     */
    public function update ($id, $method, $object, $options = array()) {
      $this->expires = 0;
      return $this->wscall('update', $method, $object, $options);
    }

  }
}


<?php

namespace Drupal\hr_api\Plugin\resource;

use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulUsers.
 *
 * @package Drupal\hr_api\Plugin\resource
 *
 * @Resource(
 *   name = "user:1.0",
 *   resource = "user",
 *   label = "User",
 *   description = "Export the User entity.",
 *   authenticationOptional = FALSE,
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   dataProvider = {
 *     "entityType": "user",
 *     "bundles": {
 *       "user"
 *     },
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */
class RestfulUsers extends ResourceCustom implements ResourceInterface {

  /**
   * {@inheritdoc}
   */
  protected function publicFields() {
    $public_fields = parent::publicFields();

    $public_fields['roles'] = array(
      'callback' => array($this, 'getRoles')
    );

    $public_fields['spaces'] = array(
      'property' => 'og_user_node',
      'process_callbacks' => array(array($this, 'getGroupRoles'))
    );

    return $public_fields;
  }

  /**
   * Get roles.
   */
  public function getRoles($di) {
    $wrapper = $di->getWrapper();
    $id = $wrapper->getIdentifier();
    $user = user_load($id);
    return array_values($user->roles);
  }

  /**
   * Get group based roles.
   */
  public function getGroupRoles($values) {
    $return = array();
    if (!empty($values)) {
      foreach ($values as $value) {
        $roles = og_get_user_roles('node', $value, $this->getAccount()->uid);
        $return[$value] = array_values($roles);
      }
    }
    return $return;
  }

  /**
   * {@inheritdoc}
   */
  public function process() {
    $this->convertMeInPath();

    return parent::process();
  }

  /**
   * Replace any instances of 'me' in the $path.
   *
   * Put the authenticated user's UID in place.
   *
   * See Drupal\restful\Plugin\resource\Resource::view()
   */
  public function convertMeInPath() {
    $path = $this->getPath();
    $ids = explode(static::IDS_SEPARATOR, $path);
    if (in_array('me', $ids)) {
      $account = $this->getAccount();

      foreach ($ids as &$id) {
        if ($id === 'me') {
          $id = $account->uid;
        }
      }

      $this->setPath(implode(static::IDS_SEPARATOR, $ids));
    }
  }

}

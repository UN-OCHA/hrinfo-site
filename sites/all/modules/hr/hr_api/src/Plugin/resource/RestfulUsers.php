<?php

/**
 * @file
 * Contains \Drupal\hr_api\Plugin\resource\RestfulUsers.
 */

namespace Drupal\hr_api\Plugin\resource;

use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulUsers
 * @package Drupal\hr_api\Plugin\resource
 *
 * @Resource(
 *   name = "users:1.0",
 *   resource = "users",
 *   label = "Users",
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

    // The mail will be shown only to the own user or privileged users.
    $public_fields['mail'] = array(
      'property' => 'mail',
    );

    return $public_fields;
  }

  /**
   * {@inheritdoc}
   */
  public function process() {
    $this->convertMeInPath();

    return parent::process();
  }

  /**
   * Replace any instances of 'me' in the $path with the authenticated user's
   * UID.
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

<?php

/**
 * @file
 * Contains \Drupal\hr_api\Plugin\resource\RestfulOgMemberships.
 */

namespace Drupal\hr_api\Plugin\resource;

use Drupal\hr_api\Plugin\resource\ResourceCustom;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class RestfulOgMemberships
 * @package Drupal\hr_api\Plugin\resource
 *
 * @Resource(
 *   name = "og_memberhips:1.0",
 *   resource = "og_membership",
 *   label = "OG Membership",
 *   description = "Export the OG Memberships.",
 *   authenticationOptional = TRUE,
 *   authenticationTypes = {
 *     "hid_token"
 *   },
 *   dataProvider = {
 *     "entityType": "og_membership",
 *   },
 *   majorVersion = 1,
 *   minorVersion = 0,
 *   allowOrigin = "*"
 * )
 */
class RestfulOgMemberships extends ResourceCustom implements ResourceInterface {

}

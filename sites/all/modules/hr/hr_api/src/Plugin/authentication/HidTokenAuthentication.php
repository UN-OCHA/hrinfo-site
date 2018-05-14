<?php

/**
 * @file
 * Contains \Drupal\hr_api\Plugin\authentication\TokenAuthentication
 */

namespace Drupal\hr_api\Plugin\authentication;

use Drupal\restful\Http\RequestInterface;
use Drupal\restful\Plugin\authentication\Authentication;
use Drupal\restful_token_auth\Plugin\authentication\TokenAuthentication;
use \Firebase\JWT\JWT;

/**
 * Class HidTokenAuthentication
 * @package Drupal\hr_api\Plugin\authentication
 *
 * @Authentication(
 *   id = "hid_token",
 *   label = "Hid Token based authentication",
 *   description = "Authenticate requests based on the HID token sent in the request.",
 *   options = {
 *     "paramName" = "access_token",
 *   },
 * )
 */
class HidTokenAuthentication extends TokenAuthentication {

  /**
   * {@inheritdoc}
   */
  public function authenticate(RequestInterface $request) {
    // Access token may be on the request, or in the headers.
    if (!$token = $this->extractToken($request)) {
      return NULL;
    }

    // If OAuth token, verify access token
    // If JWT, extract it and try to match it
    $publicKey = '-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAr9cnnM+7iRihKJ+6w3f5
10b7Bj5SJQ/zmisMktIOLzNpKnFatt4rkBSe3RdWcWCercPoblkuSC0EfIjFWFIu
2tHMNg1YS71a1Vq850q0cWL2KD12Z7zgmmKyA1l7lr21wBhKp2DmOHprAhEOhYDk
sZCkIUJxixlw97x6GnL3SzDCvPsaVpZ2byJV4wcT80OKfUgbDopLKfqn1nXp85jP
zqIPu9To7KUlCSjqqQTdPxFbOmnBN1rfENg3257N+jo7l6MRfJDL+6WhH6M7Yxp/
12d12SDToooj7Howeti4Z1YsPA3ZX60e87XoTik0U6Dz+I4SX3p08kZUF7OW68h+
/wIDAQAB
-----END PUBLIC KEY-----';
    try {
      $decoded = JWT::decode($token, $publicKey, array('RS256'));
      $hid = $decoded->id;
      $uid = db_query("SELECT uid FROM {hid_profiles} WHERE cid = :cid", array(':cid' => $hid))->fetchField();
      if (!$uid) {
        $contact = hid_profiles_get_contact($hid);
        $uid = db_query("SELECT uid FROM {hid_profiles} WHERE cid = :cid", array(':cid' => $contact->user_id))->fetchField();
      }

      return user_load($uid);
    }
    catch (\Exception $err) {
      return user_load(0);
    }

    /**
     * Extract the token from the request.
     *
     * @param RequestInterface $request
     *   The request.
     *
     * @return string
     *   The extracted token.
     */
    protected function extractToken(RequestInterface $request) {
      $plugin_definition = $this->getPluginDefinition();
      $authorization = $request->getHeaders()->get('Authorization')->getValueString();
      $token = str_replace('Bearer ', '', $authorization);
      return $token;
    }
  }

}

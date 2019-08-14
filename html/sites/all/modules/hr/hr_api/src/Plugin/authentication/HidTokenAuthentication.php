<?php

namespace Drupal\hr_api\Plugin\authentication;

use Drupal\restful\Http\RequestInterface;
use Drupal\restful\Plugin\authentication\Authentication;
use Drupal\restful_token_auth\Plugin\authentication\TokenAuthentication;
use Firebase\JWT\JWT;

/**
 * Class HidTokenAuthentication.
 *
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
    // Allow OPTIONS requests by default.
    if ($request->getMethod() == 'OPTIONS') {
      return user_load(1);
    }
    // Access token may be on the request, or in the headers.
    if (!$token = $this->extractToken($request)) {
      watchdog('hid_authentication', 'No token found');
      return NULL;
    }

    // If OAuth token, verify access token
    // If JWT, extract it and try to match it.
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
      $data = array(
        'provider' => 'HumanitarianId',
        'identifier' => $decoded->id
      );
      watchdog('hid_authentication', 'Decoded: ' . $decoded->id);
      $identity = _hybridauth_identity_load($data);
      $uid = $identity['uid'];
      watchdog('hid_authentication', 'uid found: ' . $uid);
      if (!$uid) {
        return user_load(0);
      }

      return user_load($uid);
    }
    catch (\Exception $err) {
      watchdog('hid_authentication', 'Unable to decode');
      return user_load(0);
    }
  }

  /**
   * Extract the token from the request.
   *
   * @param \Drupal\restful\Http\RequestInterface $request
   *   The request.
   *
   * @return string
   *   The extracted token.
   */
  protected function extractToken(RequestInterface $request) {
    // Allow OPTIONS requests by default.
    if ($request->getMethod() == 'OPTIONS') {
      return TRUE;
    }
    $plugin_definition = $this->getPluginDefinition();
    $authorization = $request->getHeaders()->get('Authorization')->getValueString();
    watchdog('hid_authentication', 'Token extracted: ' . $authorization);
    if (!empty($authorization)) {
      return str_replace('Bearer ', '', $authorization);
    }
    else {
      return FALSE;
    }
  }

}

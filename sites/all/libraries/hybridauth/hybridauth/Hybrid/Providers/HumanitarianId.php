<?php
/*!
* HybridAuth
* http://hybridauth.sourceforge.net | https://github.com/hybridauth/hybridauth
*  (c) 2009-2011 HybridAuth authors | hybridauth.sourceforge.net/licenses.html
*/

/**
 * Hybrid_Providers_HumanitarianIdb
 */
class Hybrid_Providers_HumanitarianId extends Hybrid_Provider_Model_OAuth2
{
  // default permissions
  public $scope = "";

  /**
   * Adapter initializer
   */
  function initialize() {
    parent::initialize();

    // Provider api end-points
    $this->api->api_base_url  = "https://auth.humanitarian.id/";
    $this->api->authorize_url = "https://auth.humanitarian.id/oauth/authorize";
    $this->api->token_url     = "https://auth.humanitarian.id/oauth/access_token";
    $this->api->curl_header = array('Content-Type: application/x-www-form-urlencoded');
  }

  /**
   * {@inheritdoc}
   */
  function loginBegin() {
      if (is_array($this->scope)) {
          $this->scope = implode(" ", $this->scope);
      }
      if (isset($this->scope)) {
          $extra_params['scope'] = $this->scope;
      }
      if (!isset($this->state)) {
          $this->state = hash("sha256",(uniqid(rand(), TRUE)));
      }
      $this->saveState($this->state);
      $extra_params['state'] = $this->state;
      Hybrid_Auth::redirect($this->api->authorizeUrl($extra_params));
  }

  /**
   * {@inheritdoc}
   */
  function loginFinish() {
    // Fix a strange behavior when some provider call back ha endpoint
    // with /index.php?hauth.done={provider}?{args}...
    // >here we need to parse $_SERVER[QUERY_STRING]
    $request = array();
    if (strrpos($_REQUEST['hauth_done'], '?')) {
      $_REQUEST["hauth_done"] = str_replace("?", "&", $_REQUEST["hauth_done"]);
      parse_str($_REQUEST["hauth_done"], $request);
    }
    else {
      $request = $_REQUEST;
    }

    $error = (array_key_exists('error', $request)) ? $request['error'] : "";

    // check for errors
    if ($error) {
      throw new Exception("Authentication failed! {$this->providerId} returned an error: $error", 5);
    }

    // check that the CSRF state token is the same as the one provided
    $this->checkState();

    // try to authenticate user
    $code = (array_key_exists('code', $request)) ? $request['code'] : "";

    try {
      $this->api->authenticate($code);
    } catch (Exception $e) {
      throw new Exception("User profile request failed! {$this->providerId} returned an error: $e", 6);
    }

    // check if authenticated
    if (!$this->api->access_token) {
      throw new Exception("Authentication failed! {$this->providerId} returned an invalid access token.", 5);
    }

    // store tokens
    $this->token("access_token", $this->api->access_token);
    $this->token("refresh_token", $this->api->refresh_token);
    $this->token("expires_in", $this->api->access_token_expires_in);
    $this->token("expires_at", $this->api->access_token_expires_at);

    // set user connected locally
    $this->setUserConnected();
  }


  /**
   * load the user profile from the IDp api client
  */
  function getUserProfile() {
    $this->api->curl_header = array(
      "Authorization: Bearer {$this->api->access_token}",
    );
    $data = $this->api->post( "account.json" );
    if ( ! isset( $data->id ) ){
      throw new Exception( "User profile request failed! {$this->providerId} returned an invalid response.", 6 );
    }

    $this->user->profile->identifier  = @ $data->sub;
    $this->user->profile->displayName = @ $data->name;
    $this->user->profile->email       = @ $data->email;
    $this->user->profile->firstName   = @ $data->given_name;
    $this->user->profile->lastName    = @ $data->family_name;
    $this->user->profile->emailVerified    = @ $data->email_verified;
    $this->user->profile->locale = @ $data->locale;
    $this->user->profile->zoneinfo = @ $data->zoneinfo;
    $this->user->profile->photoURL = @ $data->picture;

    if( empty($this->user->profile->displayName) ){
      $this->user->profile->displayName = @ $data->sub;
    }

    return $this->user->profile;
  }

  /**
  * Save the given $state in session.
  */
  protected function saveState($state) {
    $session_var_name = 'state_' . $this->api->client_id;
    $_SESSION['HybridAuth']['HumanitarianId'][$session_var_name] = $state;
  }

  /**
  * Read the state from session.
  */
  protected function readState() {
    $session_var_name = 'state_' . $this->api->client_id;
    $state = ( isset($_SESSION['HybridAuth']['HumanitarianId'][$session_var_name])
      ? $_SESSION['HybridAuth']['HumanitarianId'][$session_var_name]
      : NULL );
    unset($_SESSION['HybridAuth']['HumanitarianId'][$session_var_name]);
    return $state;
  }

  /**
  * Check the state in the request against the one saved in session.
  */
  protected function checkState() {
    $state = $this->readState();
    if (!$state || !isset($_REQUEST['state']) || $state != $_REQUEST['state']) {
      throw new UnexpectedValueException('Authentication failed! CSRF state token does not match the one provided.');
    }
  }
}

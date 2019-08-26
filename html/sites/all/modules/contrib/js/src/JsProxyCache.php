<?php

/**
 * JS custom cache handler.
 *
 * This is just a proxy for the actually configured cache backend, that ensures
 * that Drupal is fully bootstrapped if an item cannot be retrieved from cache.
 * By loading all hook implementations this avoids the risk of having incomplete
 * or corrupt cache entries stored during a callback execution.
 */
class JsProxyCache implements DrupalCacheInterface {

  const DEFAULT_BIN_KEY = 'cache_default_class';

  /**
   * The cache bin configuration.
   *
   * @var string[]
   */
  protected static $conf;

  /**
   * Flag indicating whether a full bootstrap may be performed.
   *
   * @var bool
   */
  protected static $fullBootstrapAllowed = FALSE;

  /**
   * The actual cache backend.
   *
   * @var DrupalCacheInterface
   */
  protected $backend;

  /**
   * Sets the cache bin configuration.
   *
   * @param string[] $conf
   *   An associative array of cache backend class names keyed by their cache
   *   bin name.
   */
  public static function setConf(array $conf) {
    static::$conf = $conf;
  }

  /**
   * Sets the flag indicating whether a full bootstrap can be performed.
   *
   * @param bool $allowed
   *   The full bootstrap flag.
   */
  public static function setFullBootstrapAllowed($allowed) {
    static::$fullBootstrapAllowed = $allowed;
  }

  /**
   * Constructs a JS cache handler.
   *
   * @param string $bin
   *   The cache bin name.
   */
  public function __construct($bin) {
    if (isset(static::$conf[static::DEFAULT_BIN_KEY])) {
      $class = isset(static::$conf[$bin]) ? static::$conf[$bin] : static::$conf[static::DEFAULT_BIN_KEY];
      $this->backend = new $class($bin);
    }
    else {
      $message = 'The cache backend configuration for the JS proxy cache handler is invalid: @conf';
      throw new LogicException(format_string($message, array('@conf' => print_r(static::$conf, TRUE))));
    }
  }

  /**
   * {@inheritdoc}
   */
  public function get($cid) {
    $cache = $this->backend->get($cid);
    if (!$cache) {
      $this->doFullBootstrap();
    }
    return $cache;
  }

  /**
   * {@inheritdoc}
   */
  public function getMultiple(&$cids) {
    $cache = $this->backend->getMultiple($cids);
    if ($cids) {
      $this->doFullBootstrap();
    }
    return $cache;
  }

  /**
   * {@inheritdoc}
   */
  public function set($cid, $data, $expire = CACHE_PERMANENT) {
    $this->backend->set($cid, $data, $expire);
  }

  /**
   * {@inheritdoc}
   */
  public function clear($cid = NULL, $wildcard = FALSE) {
    $this->backend->clear($cid, $wildcard);
  }

  /**
   * {@inheritdoc}
   */
  public function isEmpty() {
    return $this->backend->isEmpty();
  }

  /**
   * Fully bootstraps Drupal.
   */
  protected function doFullBootstrap() {
    if (static::$fullBootstrapAllowed) {
      static::setFullBootstrapAllowed(FALSE);
      if (drupal_get_bootstrap_phase() < DRUPAL_BOOTSTRAP_FULL) {
        js_bootstrap(DRUPAL_BOOTSTRAP_FULL);
      }
    }
  }

}

<?php

/**
 * Predis cache backend.
 */
class Redis_Cache_PhpRedis extends Redis_Cache_Base
{
    public function setLastFlushTimeFor($time, $volatile = false)
    {
        $client = $this->getClient();
        $key    = $this->getKey(self::LAST_FLUSH_KEY);

        if ($volatile) {
            $client->hset($key, 'volatile', $time);
        } else {
            $client->hmset($key, array(
                'permanent' => $time,
                'volatile' => $time,
            ));
        }
    }

    public function getLastFlushTime()
    {
        $client = $this->getClient();
        $key    = $this->getKey(self::LAST_FLUSH_KEY);
        $values = $client->hmget($key, array("permanent", "volatile"));

        if (empty($values) || !is_array($values)) {
            $ret = array(0, 0);
        } else {
            if (empty($values['permanent'])) {
                $values['permanent'] = 0;
            }
            if (empty($values['volatile'])) {
                $values['volatile'] = 0;
            }
            $ret = array($values['permanent'], $values['volatile']);
        }

        return $ret;
    }

    public function get($id)
    {
        $client = $this->getClient();
        $key    = $this->getKey($id);
        $values = $client->hgetall($key);

        // Recent versions of PhpRedis will return the Redis instance
        // instead of an empty array when the HGETALL target key does
        // not exists. I see what you did there.
        if (empty($values) || !is_array($values)) {
            return false;
        }

        return $values;
    }

    public function getMultiple(array $idList)
    {
        $client = $this->getClient();

        $ret = array();

        $pipe = $client->multi(Redis::PIPELINE);
        foreach ($idList as $id) {
            $pipe->hgetall($this->getKey($id));
        }
        $replies = $pipe->exec();

        foreach (array_values($idList) as $line => $id) {
            if (!empty($replies[$line]) && is_array($replies[$line])) {
                $ret[$id] = $replies[$line];
            }
        }

        return $ret;
    }

    public function set($id, $data, $ttl = null, $volatile = false)
    {
        // Ensure TTL consistency: if the caller gives us an expiry timestamp
        // in the past the key will expire now and will never be read.
        // Behavior between Predis and PhpRedis seems to change here: when
        // setting a negative expire time, PhpRedis seems to ignore the
        // command and leave the key permanent.
        if (null !== $ttl && $ttl <= 0) {
            return;
        }

        $data['volatile'] = (int)$volatile;

        $client = $this->getClient();
        $key    = $this->getKey($id);

        $pipe = $client->multi(Redis::PIPELINE);
        $pipe->hmset($key, $data);

        if (null !== $ttl) {
            $pipe->expire($key, $ttl);
        }
        $pipe->exec();
    }

    public function delete($id)
    {
        $this->getClient()->del($this->getKey($id));
    }

    public function deleteMultiple(array $idList)
    {
        $client = $this->getClient();

        $pipe = $client->multi(Redis::PIPELINE);
        foreach ($idList as $id) {
            $pipe->del($this->getKey($id));
        }
        // Don't care if something failed.
        $pipe->exec();
    }

    public function deleteByPrefix($prefix)
    {
        $pattern = $this->getKey($prefix . '*');
        if (variable_get('redis_delete_scan_enabled', FALSE) === TRUE) {
            $this->deleteByPrefixUsingScan($pattern);
        }
        else {
            $this->deleteByPrefixUsingKeys(self::EVAL_DELETE_PREFIX, $pattern);
        }
    }

    public function flush()
    {
        $pattern = $this->getKey('*');
        if (variable_get('redis_delete_scan_enabled', FALSE) === TRUE) {
            $this->deleteByPrefixUsingScan($pattern);
        }
        else {
            $this->deleteByPrefixUsingKeys(self::EVAL_DELETE_PREFIX, $pattern);
        }
    }

    public function flushVolatile()
    {
        $pattern = $this->getKey('*');
        if (variable_get('redis_delete_scan_enabled', FALSE) === TRUE) {
            $this->deleteByPrefixUsingScan($pattern, TRUE);
        }
        else {
            $this->deleteByPrefixUsingKeys(self::EVAL_DELETE_VOLATILE, $pattern);
        }
    }

    public function deleteByPrefixUsingKeys($eval_script, $pattern)
    {
        // Skip duplicate runs.
        static $memory = array();
        if (isset($memory[$pattern])) {
            return;
        }
        $memory[$pattern] = 1;

        $client = $this->getClient();
        $ret = $client->eval($eval_script, array($pattern));
        if (1 != $ret) {
            trigger_error(sprintf("EVAL failed: %s", $client->getLastError()), E_USER_ERROR);
        }
    }

    public function deleteByPrefixUsingScan($pattern, $volatile = FALSE)
    {
        // Skip duplicate runs.
        static $memory = array();
        if (isset($memory[$pattern])) {
            return;
        }
        $memory[$pattern] = 1;

        // Initialize Redis client with SCAN and SCAN_RETRY.
        $client = $this->getClient();
        $client->setOption(Redis::OPT_SCAN, Redis::SCAN_RETRY);
        $delete_keys = array();
        $count = variable_get('redis_delete_scan_count');
        if (!is_int($count) || $count <= 0) {
            $count = 100;
        }

        // Find keys using SCAN.
        $iterator = NULL;
        while ($keys = $client->scan($iterator, $pattern, $count)) {
            if ($volatile) {
                foreach ($keys as $i => $k) {
                    if ($client->hget($k, 'volatile') == 1) {
                        $delete_keys[] = $k;
                    }
                }
            }
            else {
                $delete_keys = array_merge($delete_keys, $keys);
            }
        }

        // Delete keys in pipeline mode.
        if (!empty($delete_keys)) {
            $pipe = $client->multi(Redis::PIPELINE);
            $batch_size = variable_get('redis_delete_batch_size', 20);
            do {
              $batch = array_splice($delete_keys, 0, $batch_size);
              $pipe->del($batch);
            } while (!empty($delete_keys));
            $pipe->exec();
        }
    }
}

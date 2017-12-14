<?php

/**
 * @todo
 *   - Deambiguate why we need the namespace only for flush*() operations
 *   - Implement the isEmpty() method by using SCAN or KEYS
 */
abstract class Redis_Cache_Base extends Redis_AbstractBackend
{
    /**
     * Lastest cache flush KEY name
     */
    const LAST_FLUSH_KEY = '_last_flush';

    /**
     * Delete by prefix lua script
     */
    const EVAL_DELETE_PREFIX = <<<EOT
redis.log(redis.LOG_NOTICE, "Delete by prefix requested for '" .. ARGV[1] .. "'.")
local deleted_keys_count = 0

local scan_delete = tonumber(ARGV[2])
if scan_delete == nil then
  scan_delete = 0
end

if scan_delete ~= 0 then
  local server_info = redis.call("INFO", "SERVER")
  local version_string = string.match(server_info, "redis_version:([%d.]*)")
  local version_major, version_minor = 0, 0

  version_major, version_minor = string.match(version_string, "(%d+).(%d+)")
  version_major = tonumber(version_major)
  version_minor = tonumber(version_minor)
  redis.log(redis.LOG_DEBUG, "Non-blocking delete requested. " ..
    "Server version string: " .. version_string)

  if (version_major >= 3 and version_minor >= 2) then
    local scan_count = (ARGV[3] or 100)
    local result, keys, cursor = {}, {}, "0"
    redis.log(redis.LOG_DEBUG, "Using SCAN command to delete. COUNT arg: " ..
      tostring(scan_count) .. ".")
    redis.replicate_commands()
    repeat
      result = redis.call("SCAN", cursor, "MATCH", ARGV[1], "COUNT", scan_count)
      cursor = result[1]
      keys = result[2]
      for _, k in pairs(keys) do
        redis.call("DEL", k)
        deleted_keys_count = deleted_keys_count + 1
      end
    until cursor == "0"
    redis.log(redis.LOG_NOTICE, "Delete by prefix (SCAN) finished for '" ..
      ARGV[1] .. "' (" .. tostring(deleted_keys_count) .. " keys).")
    return 1
  end
  redis.log(redis.LOG_WARNING, "Non-blocking delete requested but not supported by server.")
end

redis.log(redis.LOG_NOTICE, "Using KEYS command to delete.")
local keys = redis.call("KEYS", ARGV[1])
redis.log(redis.LOG_NOTICE, "KEYS command finished.")
for _, k in ipairs(keys) do
    redis.call("DEL", k)
    deleted_keys_count = deleted_keys_count + 1
end
redis.log(redis.LOG_NOTICE, "Delete by prefix (KEYS) finished for '" ..
  ARGV[1] .. "' (" .. tostring(deleted_keys_count) .. " keys).")
return 1
EOT;

    /**
     * Delete volatile by prefix lua script
     */
    const EVAL_DELETE_VOLATILE = <<<EOT
redis.log(redis.LOG_NOTICE, "Delete volatile by prefix requested for '" .. ARGV[1] .. "'.")
local deleted_keys_count = 0

local scan_delete = tonumber(ARGV[2])
if scan_delete == nil then
  scan_delete = 0
end

if scan_delete ~= 0 then
  local server_info = redis.call("INFO", "SERVER")
  local version_string = string.match(server_info, "redis_version:([%d.]*)")
  local version_major, version_minor = 0, 0

  version_major, version_minor = string.match(version_string, "(%d+).(%d+)")
  version_major = tonumber(version_major)
  version_minor = tonumber(version_minor)
  redis.log(redis.LOG_DEBUG, "Non-blocking delete requested. " ..
    "Server version string: " .. version_string)

  if (version_major >= 3 and version_minor >= 2) then
    local scan_count = (ARGV[3] or 100)
    local result, keys, cursor = {}, {}, "0"
    redis.log(redis.LOG_DEBUG, "Using SCAN command to delete. COUNT arg: " ..
      tostring(scan_count) .. ".")
    redis.replicate_commands()
    repeat
      result = redis.call("SCAN", cursor, "MATCH", ARGV[1], "COUNT", scan_count)
      cursor = result[1]
      keys = result[2]
      for _, k in pairs(keys) do
        if "1" == redis.call("HGET", k, "volatile") then
            redis.call("DEL", k)
            deleted_keys_count = deleted_keys_count + 1
        end
      end
    until cursor == "0"
    redis.log(redis.LOG_NOTICE, "Delete volatile by prefix (SCAN) finished for '" ..
      ARGV[1] .. "' (" .. tostring(deleted_keys_count) .. " keys).")
    return 1
  end
  redis.log(redis.LOG_WARNING, "Non-blocking delete requested but not supported by server.")
end

redis.log(redis.LOG_NOTICE, "Using KEYS command to delete.")
local keys = redis.call('KEYS', ARGV[1])
redis.log(redis.LOG_NOTICE, "KEYS command finished.")
for _, k in ipairs(keys) do
    if "1" == redis.call("HGET", k, "volatile") then
        redis.call("DEL", k)
        deleted_keys_count = deleted_keys_count + 1
    end
end
redis.log(redis.LOG_NOTICE, "Delete volatile by prefix (KEYS) finished for '" ..
  ARGV[1] .. "' (" .. tostring(deleted_keys_count) .. " keys).")
return 1
EOT;
}

Creates a report that displays, usage, performance, and other statistics for the
Redis server usage. This module is a good companion to the
Redis module and provides a convenient way to check on the status and
performance of a Redis cache implementation.

The reports contains useful information such as memory usage, CPU load, up-time,
connected clients, and much more. The report delivers updated data each time the
report page is refreshed.

INSTALLATION:
1. Install as you would any Drupal module. Download and enable etc...
2. After enabling the module a Redis Info link is created under the Reports Menu
tree. Or find it by going to: /admin/reports/redis-info.
3. Make sure your user role has the "View site reports" permission. Of course
user/1 will bypass the permission.

TROUBLESHOOTING:
1. Check to make sure redis-server is up and running. The command: redis-cli ping, should
return "PONG" in the terminal.

2. Check to make sure the Redis module is configured properly.

# Humanitarian ID Auth integration module for Drupal

## Requirements

The Oauth Connector contrib module should be patched with the following:
- http://drupal.org/files/issues/oauthconnector-2176907-4-authorized_access.patch
- http://drupal.org/files/issues/oauthconnector-2374353-1-id_token_validation.patch

The PHP-JWT library should be installed to sites/all/libraries/php-jwt from:
https://github.com/firebase/php-jwt

## Configuration

1. Enable this module ("Humanitarian ID Auth Integration").

2. Configure the Oauthconnector instance for Humanitarian ID with the supplied
API endpoints, key, and secret at:
`/admin/structure/oauthconnector/hid_oauth/edit`

3. Ensure the "Connect with Humanitarian ID Oauth" permission under the
"Connector" group of permissions is enabled for *anonymous* users at:
`/admin/people/permissions`

## User Migration Drush Command

The Drush command `hid-auth-migrate-users` migrates Drupal users to the Auth
system by ensuring a user is registered with the Drupal user's email address,
and then links the Auth system user to the Drupal user. This allows users to
reset their password on the Auth system, and then be able to access their
existing account on the Drupal site.

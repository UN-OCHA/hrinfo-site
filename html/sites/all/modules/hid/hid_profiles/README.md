# Humanitarian ID Profiles integration module for Drupal

## Requirements

This module requires the `restclient` module.

For associating Humanitarian ID profiles with Drupal user profiles, this module
depends on the `hid_auth` module.

## Configuration

1. Enable this module ("Humanitarian ID Profiles Integration").

2. Configure the Humanitarian ID Profiles integration module with the supplied
API endpoints, key, and secret at:
`/admin/config/services/hid_profiles`

## Example

After configuring the module, you can use this module's helper functions to
make requests to the Humanitarian ID Profiles API.

For example, see the following sample code for retrieving all active contacts
from the API:

```php

$data = _hid_profiles_get_contacts(array('status' => 1));
$names = '<br/>';
if ($data->status == 'ok' && isset($data->contacts)) {
  foreach ($data->contacts as $contact) {
    $names .= $contact->nameGiven . ' ' . $contact->nameFamily . "<br/>\n";
  }
}
drupal_set_message('names from all active contacts: ' . $names);

```

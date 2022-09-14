# User merge

## Notes for version 2.x

A new interface allows users with the right permissions to choose how each user
property should be merged. This includes the ability to merge fields,
referencing entities, and other entities owned by the selected users. This aims
to provide a more finely tuned merge process, as well as to minimize errors and
information loss.

### General changes

`usermerge.module` provides only the API, and doesn't actually do any merging of
its own. It implements `hook_hook_info()`, so other modules can provide their
own `<module>.usermerge.inc` files. It also provides the `usermerge_do()`
function, which, given two user objects, merges them preserving information from
the "new" account (a behavior similar to version 1, but which takes into account
integration with other modules).

Core-specific functionality (default user properties, fields) is managed in
`usermerge.usermerge.inc`, which also includes support for entities that have a
`uid` column, and basic display support for non-default user properties that
aren't structured like fields (such as `rdf_mapping`).

### Configuration page
The configuration page is located at `admin/config/people/usermerge`, and allows
admins to select which core properties of the user entity should be exposed in
the review table. By default, no properties are exposed.

### Integration with other modules

Immediate integration with other modules is contained in module-specific files in
the `includes` directory.

Modules supported out of the box:

- Entity Reference
- Multiple E-mail
- Profile (code from User merge 1, left untouched)
- Profile 2
- RDF
- Real Name
- User Reference (References)
- User Points

### Self-Serve User Merge

Self-Serve User Merge is a submodule that allows users with the "Merge own
accounts" permission to merge a different account into the currently active one,
by visiting `user/%/edit/merge`. The user will have to enter the e-mail address
and password of the account that will be merged.
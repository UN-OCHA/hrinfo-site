<?php 


$options['sites'] = array (
);
$options['profiles'] = array (
  0 => 'minimal',
  1 => 'standard',
);
$options['packages'] = array (
  'base' => 
  array (
    'modules' => 
    array (
      'forum' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/forum/forum.module',
        'basename' => 'forum.module',
        'name' => 'forum',
        'info' => 
        array (
          'name' => 'Forum',
          'description' => 'Provides discussion forums.',
          'dependencies' => 
          array (
            0 => 'taxonomy',
            1 => 'comment',
          ),
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'forum.test',
          ),
          'configure' => 'admin/structure/forum',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'forum.css',
            ),
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => '7012',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'field_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/field_ui/field_ui.module',
        'basename' => 'field_ui.module',
        'name' => 'field_ui',
        'info' => 
        array (
          'name' => 'Field UI',
          'description' => 'User interface for the Field API.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'field',
          ),
          'files' => 
          array (
            0 => 'field_ui.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'comment' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/comment/comment.module',
        'basename' => 'comment.module',
        'name' => 'comment',
        'info' => 
        array (
          'name' => 'Comment',
          'description' => 'Allows users to comment on and discuss published content.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'text',
          ),
          'files' => 
          array (
            0 => 'comment.module',
            1 => 'comment.test',
          ),
          'configure' => 'admin/content/comment',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'comment.css',
            ),
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => '7009',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'contact' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/contact/contact.module',
        'basename' => 'contact.module',
        'name' => 'contact',
        'info' => 
        array (
          'name' => 'Contact',
          'description' => 'Enables the use of both personal and site-wide contact forms.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'contact.test',
          ),
          'configure' => 'admin/structure/contact',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7003',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'filter' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/filter/filter.module',
        'basename' => 'filter.module',
        'name' => 'filter',
        'info' => 
        array (
          'name' => 'Filter',
          'description' => 'Filters content in preparation for display.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'filter.test',
          ),
          'required' => true,
          'configure' => 'admin/config/content/formats',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7010',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'dblog' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/dblog/dblog.module',
        'basename' => 'dblog.module',
        'name' => 'dblog',
        'info' => 
        array (
          'name' => 'Database logging',
          'description' => 'Logs and records system events to the database.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'dblog.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7002',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'path' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/path/path.module',
        'basename' => 'path.module',
        'name' => 'path',
        'info' => 
        array (
          'name' => 'Path',
          'description' => 'Allows users to rename URLs.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'path.test',
          ),
          'configure' => 'admin/config/search/path',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'locale' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/locale/locale.module',
        'basename' => 'locale.module',
        'name' => 'locale',
        'info' => 
        array (
          'name' => 'Locale',
          'description' => 'Adds language handling functionality and enables the translation of the user interface to languages other than English.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'locale.test',
          ),
          'configure' => 'admin/config/regional/language',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7005',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'system' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/system/system.module',
        'basename' => 'system.module',
        'name' => 'system',
        'info' => 
        array (
          'name' => 'System',
          'description' => 'Handles general site configuration for administrators.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'system.archiver.inc',
            1 => 'system.mail.inc',
            2 => 'system.queue.inc',
            3 => 'system.tar.inc',
            4 => 'system.updater.inc',
            5 => 'system.test',
          ),
          'required' => true,
          'configure' => 'admin/config/system',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7079',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'tracker' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/tracker/tracker.module',
        'basename' => 'tracker.module',
        'name' => 'tracker',
        'info' => 
        array (
          'name' => 'Tracker',
          'description' => 'Enables tracking of recent content for users.',
          'dependencies' => 
          array (
            0 => 'comment',
          ),
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'tracker.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'statistics' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/statistics/statistics.module',
        'basename' => 'statistics.module',
        'name' => 'statistics',
        'info' => 
        array (
          'name' => 'Statistics',
          'description' => 'Logs access statistics for your site.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'statistics.test',
          ),
          'configure' => 'admin/config/system/statistics',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'translation' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/translation/translation.module',
        'basename' => 'translation.module',
        'name' => 'translation',
        'info' => 
        array (
          'name' => 'Content translation',
          'description' => 'Allows content to be translated into different languages.',
          'dependencies' => 
          array (
            0 => 'locale',
          ),
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'translation.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'color' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/color/color.module',
        'basename' => 'color.module',
        'name' => 'color',
        'info' => 
        array (
          'name' => 'Color',
          'description' => 'Allows administrators to change the color scheme of compatible themes.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'color.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'rdf' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/rdf/rdf.module',
        'basename' => 'rdf.module',
        'name' => 'rdf',
        'info' => 
        array (
          'name' => 'RDF',
          'description' => 'Enriches your content with metadata to let other applications (e.g. search engines, aggregators) better understand its relationships and attributes.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'rdf.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'node' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/node/node.module',
        'basename' => 'node.module',
        'name' => 'node',
        'info' => 
        array (
          'name' => 'Node',
          'description' => 'Allows content to be submitted to the site and displayed on pages.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'node.module',
            1 => 'node.test',
          ),
          'required' => true,
          'configure' => 'admin/structure/types',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'node.css',
            ),
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7014',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'search' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/search/search.module',
        'basename' => 'search.module',
        'name' => 'search',
        'info' => 
        array (
          'name' => 'Search',
          'description' => 'Enables site-wide keyword searching.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'search.extender.inc',
            1 => 'search.test',
          ),
          'configure' => 'admin/config/search/settings',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'search.css',
            ),
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'user' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/user/user.module',
        'basename' => 'user.module',
        'name' => 'user',
        'info' => 
        array (
          'name' => 'User',
          'description' => 'Manages the user registration and login system.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'user.module',
            1 => 'user.test',
          ),
          'required' => true,
          'configure' => 'admin/config/people',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'user.css',
            ),
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7018',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'shortcut' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/shortcut/shortcut.module',
        'basename' => 'shortcut.module',
        'name' => 'shortcut',
        'info' => 
        array (
          'name' => 'Shortcut',
          'description' => 'Allows users to manage customizable lists of shortcut links.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'shortcut.test',
          ),
          'configure' => 'admin/config/user-interface/shortcut',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'php' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/php/php.module',
        'basename' => 'php.module',
        'name' => 'php',
        'info' => 
        array (
          'name' => 'PHP filter',
          'description' => 'Allows embedded PHP code/snippets to be evaluated.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'php.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'file' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/file/file.module',
        'basename' => 'file.module',
        'name' => 'file',
        'info' => 
        array (
          'name' => 'File',
          'description' => 'Defines a file field type.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'field',
          ),
          'files' => 
          array (
            0 => 'tests/file.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'image' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/image/image.module',
        'basename' => 'image.module',
        'name' => 'image',
        'info' => 
        array (
          'name' => 'Image',
          'description' => 'Provides image manipulation tools.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'file',
          ),
          'files' => 
          array (
            0 => 'image.test',
          ),
          'configure' => 'admin/config/media/image-styles',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => '7005',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'dashboard' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/dashboard/dashboard.module',
        'basename' => 'dashboard.module',
        'name' => 'dashboard',
        'info' => 
        array (
          'name' => 'Dashboard',
          'description' => 'Provides a dashboard page in the administrative interface for organizing administrative tasks and tracking information within your site.',
          'core' => '7.x',
          'package' => 'Core',
          'version' => '7.36',
          'files' => 
          array (
            0 => 'dashboard.test',
          ),
          'dependencies' => 
          array (
            0 => 'block',
          ),
          'configure' => 'admin/dashboard/customize',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'contextual' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/contextual/contextual.module',
        'basename' => 'contextual.module',
        'name' => 'contextual',
        'info' => 
        array (
          'name' => 'Contextual links',
          'description' => 'Provides contextual links to perform actions related to elements on a page.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'contextual.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'menu' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/menu/menu.module',
        'basename' => 'menu.module',
        'name' => 'menu',
        'info' => 
        array (
          'name' => 'Menu',
          'description' => 'Allows administrators to customize the site navigation menu.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'menu.test',
          ),
          'configure' => 'admin/structure/menu',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7003',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'trigger' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/trigger/trigger.module',
        'basename' => 'trigger.module',
        'name' => 'trigger',
        'info' => 
        array (
          'name' => 'Trigger',
          'description' => 'Enables actions to be fired on certain system events, such as when new content is created.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'trigger.test',
          ),
          'configure' => 'admin/structure/trigger',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7002',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'poll' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/poll/poll.module',
        'basename' => 'poll.module',
        'name' => 'poll',
        'info' => 
        array (
          'name' => 'Poll',
          'description' => 'Allows your site to capture votes on different topics in the form of multiple choice questions.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'poll.test',
          ),
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'poll.css',
            ),
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7004',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'block' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/block/block.module',
        'basename' => 'block.module',
        'name' => 'block',
        'info' => 
        array (
          'name' => 'Block',
          'description' => 'Controls the visual building blocks a page is constructed with. Blocks are boxes of content rendered into an area, or region, of a web page.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'block.test',
          ),
          'configure' => 'admin/structure/block',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7009',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'toolbar' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/toolbar/toolbar.module',
        'basename' => 'toolbar.module',
        'name' => 'toolbar',
        'info' => 
        array (
          'name' => 'Toolbar',
          'description' => 'Provides a toolbar that shows the top-level administration menu items and links from other modules.',
          'core' => '7.x',
          'package' => 'Core',
          'version' => '7.36',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'blog' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/blog/blog.module',
        'basename' => 'blog.module',
        'name' => 'blog',
        'info' => 
        array (
          'name' => 'Blog',
          'description' => 'Enables multi-user blogs.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'blog.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'syslog' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/syslog/syslog.module',
        'basename' => 'syslog.module',
        'name' => 'syslog',
        'info' => 
        array (
          'name' => 'Syslog',
          'description' => 'Logs and records system events to syslog.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'syslog.test',
          ),
          'configure' => 'admin/config/development/logging',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'openid' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/openid/openid.module',
        'basename' => 'openid.module',
        'name' => 'openid',
        'info' => 
        array (
          'name' => 'OpenID',
          'description' => 'Allows users to log into your site using OpenID.',
          'version' => '7.36',
          'package' => 'Core',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'openid.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'update' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/update/update.module',
        'basename' => 'update.module',
        'name' => 'update',
        'info' => 
        array (
          'name' => 'Update manager',
          'description' => 'Checks for available updates, and can securely install or update modules and themes via a web interface.',
          'version' => '7.36',
          'package' => 'Core',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'update.test',
          ),
          'configure' => 'admin/reports/updates/settings',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'book' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/book/book.module',
        'basename' => 'book.module',
        'name' => 'book',
        'info' => 
        array (
          'name' => 'Book',
          'description' => 'Allows users to create and organize related content in an outline.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'book.test',
          ),
          'configure' => 'admin/content/book/settings',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'book.css',
            ),
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'overlay' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/overlay/overlay.module',
        'basename' => 'overlay.module',
        'name' => 'overlay',
        'info' => 
        array (
          'name' => 'Overlay',
          'description' => 'Displays the Drupal administration interface in an overlay.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'aggregator' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/aggregator/aggregator.module',
        'basename' => 'aggregator.module',
        'name' => 'aggregator',
        'info' => 
        array (
          'name' => 'Aggregator',
          'description' => 'Aggregates syndicated content (RSS, RDF, and Atom feeds).',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'aggregator.test',
          ),
          'configure' => 'admin/config/services/aggregator/settings',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'aggregator.css',
            ),
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7004',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'taxonomy' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/taxonomy/taxonomy.module',
        'basename' => 'taxonomy.module',
        'name' => 'taxonomy',
        'info' => 
        array (
          'name' => 'Taxonomy',
          'description' => 'Enables the categorization of content.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'options',
          ),
          'files' => 
          array (
            0 => 'taxonomy.module',
            1 => 'taxonomy.test',
          ),
          'configure' => 'admin/structure/taxonomy',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => '7011',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'list' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/field/modules/list/list.module',
        'basename' => 'list.module',
        'name' => 'list',
        'info' => 
        array (
          'name' => 'List',
          'description' => 'Defines list field types. Use with Options to create selection lists.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'field',
            1 => 'options',
          ),
          'files' => 
          array (
            0 => 'tests/list.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => '7002',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'number' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/field/modules/number/number.module',
        'basename' => 'number.module',
        'name' => 'number',
        'info' => 
        array (
          'name' => 'Number',
          'description' => 'Defines numeric field types.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'field',
          ),
          'files' => 
          array (
            0 => 'number.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'text' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/field/modules/text/text.module',
        'basename' => 'text.module',
        'name' => 'text',
        'info' => 
        array (
          'name' => 'Text',
          'description' => 'Defines simple text field types.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'field',
          ),
          'files' => 
          array (
            0 => 'text.test',
          ),
          'required' => true,
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'field_sql_storage' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/field/modules/field_sql_storage/field_sql_storage.module',
        'basename' => 'field_sql_storage.module',
        'name' => 'field_sql_storage',
        'info' => 
        array (
          'name' => 'Field SQL storage',
          'description' => 'Stores field data in an SQL database.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'field',
          ),
          'files' => 
          array (
            0 => 'field_sql_storage.test',
          ),
          'required' => true,
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => '7002',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'options' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/field/modules/options/options.module',
        'basename' => 'options.module',
        'name' => 'options',
        'info' => 
        array (
          'name' => 'Options',
          'description' => 'Defines selection, check box and radio button widgets for text and numeric fields.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'field',
          ),
          'files' => 
          array (
            0 => 'options.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'field' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/field/field.module',
        'basename' => 'field.module',
        'name' => 'field',
        'info' => 
        array (
          'name' => 'Field',
          'description' => 'Field API to add fields to entities like nodes and users.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'field.module',
            1 => 'field.attach.inc',
            2 => 'field.info.class.inc',
            3 => 'tests/field.test',
          ),
          'dependencies' => 
          array (
            0 => 'field_sql_storage',
          ),
          'required' => true,
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'theme/field.css',
            ),
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
        ),
        'schema_version' => '7003',
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'simpletest' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/simpletest/simpletest.module',
        'basename' => 'simpletest.module',
        'name' => 'simpletest',
        'info' => 
        array (
          'name' => 'Testing',
          'description' => 'Provides a framework for unit and functional testing.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'simpletest.test',
            1 => 'drupal_web_test_case.php',
            2 => 'tests/actions.test',
            3 => 'tests/ajax.test',
            4 => 'tests/batch.test',
            5 => 'tests/bootstrap.test',
            6 => 'tests/cache.test',
            7 => 'tests/common.test',
            8 => 'tests/database_test.test',
            9 => 'tests/entity_crud.test',
            10 => 'tests/entity_crud_hook_test.test',
            11 => 'tests/entity_query.test',
            12 => 'tests/error.test',
            13 => 'tests/file.test',
            14 => 'tests/filetransfer.test',
            15 => 'tests/form.test',
            16 => 'tests/graph.test',
            17 => 'tests/image.test',
            18 => 'tests/lock.test',
            19 => 'tests/mail.test',
            20 => 'tests/menu.test',
            21 => 'tests/module.test',
            22 => 'tests/pager.test',
            23 => 'tests/password.test',
            24 => 'tests/path.test',
            25 => 'tests/registry.test',
            26 => 'tests/schema.test',
            27 => 'tests/session.test',
            28 => 'tests/tablesort.test',
            29 => 'tests/theme.test',
            30 => 'tests/unicode.test',
            31 => 'tests/update.test',
            32 => 'tests/xmlrpc.test',
            33 => 'tests/upgrade/upgrade.test',
            34 => 'tests/upgrade/upgrade.comment.test',
            35 => 'tests/upgrade/upgrade.filter.test',
            36 => 'tests/upgrade/upgrade.forum.test',
            37 => 'tests/upgrade/upgrade.locale.test',
            38 => 'tests/upgrade/upgrade.menu.test',
            39 => 'tests/upgrade/upgrade.node.test',
            40 => 'tests/upgrade/upgrade.taxonomy.test',
            41 => 'tests/upgrade/upgrade.trigger.test',
            42 => 'tests/upgrade/upgrade.translatable.test',
            43 => 'tests/upgrade/upgrade.upload.test',
            44 => 'tests/upgrade/upgrade.user.test',
            45 => 'tests/upgrade/update.aggregator.test',
            46 => 'tests/upgrade/update.trigger.test',
            47 => 'tests/upgrade/update.field.test',
            48 => 'tests/upgrade/update.user.test',
          ),
          'configure' => 'admin/config/development/testing/settings',
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'help' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/modules/help/help.module',
        'basename' => 'help.module',
        'name' => 'help',
        'info' => 
        array (
          'name' => 'Help',
          'description' => 'Manages the display of online help.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'help.test',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'drupal',
        'version' => '7.36',
      ),
    ),
    'themes' => 
    array (
      'bartik' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/themes/bartik/bartik.info',
        'basename' => 'bartik.info',
        'name' => 'Bartik',
        'info' => 
        array (
          'name' => 'Bartik',
          'description' => 'A flexible, recolorable theme with many regions.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'css/layout.css',
              1 => 'css/style.css',
              2 => 'css/colors.css',
            ),
            'print' => 
            array (
              0 => 'css/print.css',
            ),
          ),
          'regions' => 
          array (
            'header' => 'Header',
            'help' => 'Help',
            'page_top' => 'Page top',
            'page_bottom' => 'Page bottom',
            'highlighted' => 'Highlighted',
            'featured' => 'Featured',
            'content' => 'Content',
            'sidebar_first' => 'Sidebar first',
            'sidebar_second' => 'Sidebar second',
            'triptych_first' => 'Triptych first',
            'triptych_middle' => 'Triptych middle',
            'triptych_last' => 'Triptych last',
            'footer_firstcolumn' => 'Footer first column',
            'footer_secondcolumn' => 'Footer second column',
            'footer_thirdcolumn' => 'Footer third column',
            'footer_fourthcolumn' => 'Footer fourth column',
            'footer' => 'Footer',
          ),
          'settings' => 
          array (
            'shortcut_module_link' => '0',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
        ),
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'garland' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/themes/garland/garland.info',
        'basename' => 'garland.info',
        'name' => 'Garland',
        'info' => 
        array (
          'name' => 'Garland',
          'description' => 'A multi-column theme which can be configured to modify colors and switch between fixed and fluid width layouts.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'style.css',
            ),
            'print' => 
            array (
              0 => 'print.css',
            ),
          ),
          'settings' => 
          array (
            'garland_width' => 'fluid',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
        ),
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'stark' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/themes/stark/stark.info',
        'basename' => 'stark.info',
        'name' => 'Stark',
        'info' => 
        array (
          'name' => 'Stark',
          'description' => 'This theme demonstrates Drupal\'s default HTML markup and CSS styles. To learn how to build your own theme and override Drupal\'s default code, see the <a href="http://drupal.org/theme-guide">Theming Guide</a>.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'layout.css',
            ),
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
        ),
        'project' => 'drupal',
        'version' => '7.36',
      ),
      'seven' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/themes/seven/seven.info',
        'basename' => 'seven.info',
        'name' => 'Seven',
        'info' => 
        array (
          'name' => 'Seven',
          'description' => 'A simple one-column, tableless, fluid width administration theme.',
          'package' => 'Core',
          'version' => '7.36',
          'core' => '7.x',
          'stylesheets' => 
          array (
            'screen' => 
            array (
              0 => 'reset.css',
              1 => 'style.css',
            ),
          ),
          'settings' => 
          array (
            'shortcut_module_link' => '1',
          ),
          'regions' => 
          array (
            'content' => 'Content',
            'help' => 'Help',
            'page_top' => 'Page top',
            'page_bottom' => 'Page bottom',
            'sidebar_first' => 'First sidebar',
          ),
          'regions_hidden' => 
          array (
            0 => 'sidebar_first',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
        ),
        'project' => 'drupal',
        'version' => '7.36',
      ),
    ),
    'platforms' => 
    array (
      'drupal' => 
      array (
        'short_name' => 'drupal',
        'version' => '7.36',
        'description' => 'This platform is running Drupal 7.36',
      ),
    ),
    'profiles' => 
    array (
      'minimal' => 
      array (
        'name' => 'minimal',
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/profiles/minimal/minimal.profile',
        'project' => 'drupal',
        'info' => 
        array (
          'name' => 'Minimal',
          'description' => 'Start with only a few modules enabled.',
          'version' => '7.36',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'block',
            1 => 'dblog',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
          'languages' => 
          array (
            0 => 'en',
          ),
        ),
        'version' => '7.36',
      ),
      'standard' => 
      array (
        'name' => 'standard',
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/profiles/standard/standard.profile',
        'project' => 'drupal',
        'info' => 
        array (
          'name' => 'Standard',
          'description' => 'Install with commonly used features pre-configured.',
          'version' => '7.36',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'block',
            1 => 'color',
            2 => 'comment',
            3 => 'contextual',
            4 => 'dashboard',
            5 => 'help',
            6 => 'image',
            7 => 'list',
            8 => 'menu',
            9 => 'number',
            10 => 'options',
            11 => 'path',
            12 => 'taxonomy',
            13 => 'dblog',
            14 => 'search',
            15 => 'shortcut',
            16 => 'toolbar',
            17 => 'overlay',
            18 => 'field_ui',
            19 => 'file',
            20 => 'rdf',
          ),
          'project' => 'drupal',
          'datestamp' => '1427943826',
          'php' => '5.2.4',
          'languages' => 
          array (
            0 => 'en',
          ),
          'old_short_name' => 'default',
        ),
        'version' => '7.36',
      ),
    ),
  ),
  'sites-all' => 
  array (
    'modules' => 
    array (
      'hid_auth' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hid/hid_auth/hid_auth.module',
        'basename' => 'hid_auth.module',
        'name' => 'hid_auth',
        'info' => 
        array (
          'name' => 'Humanitarian ID Auth Integration',
          'core' => '7.x',
          'package' => 'Humanitarian ID',
          'version' => '7.x-1.0',
          'project' => 'hid_auth',
          'dependencies' => 
          array (
            0 => 'connector',
            1 => 'oauthconnector',
            2 => 'restclient',
          ),
          'description' => '',
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'hid_auth',
        'version' => '7.x-1.0',
      ),
      'hid_profiles' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hid/hid_profiles/hid_profiles.module',
        'basename' => 'hid_profiles.module',
        'name' => 'hid_profiles',
        'info' => 
        array (
          'name' => 'Humanitarian ID Profiles Integration',
          'description' => 'Provides support for Drupal to use the Humanitarian ID Profiles API web service.',
          'core' => '7.x',
          'package' => 'Humanitarian ID',
          'version' => '7.x-1.0',
          'dependencies' => 
          array (
            0 => 'context',
            1 => 'ctools',
            2 => 'features',
            3 => 'restclient',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'hid_contacts',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => '7.x-1.0',
      ),
      'hr_notifications' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_notifications/hr_notifications.module',
        'basename' => 'hr_notifications.module',
        'name' => 'hr_notifications',
        'info' => 
        array (
          'name' => 'Notifications',
          'description' => 'Notifications feature for HR 2.x',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'entity',
            2 => 'features',
            3 => 'flag',
            4 => 'list',
            5 => 'og_context',
            6 => 'rules',
            7 => 'text',
            8 => 'views',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'field_base' => 
            array (
              0 => 'field_mailchimp_api_key',
              1 => 'field_mailchimp_list',
            ),
            'flag' => 
            array (
              0 => 'hr_follow',
              1 => 'hr_reliefweb',
            ),
            'rules_config' => 
            array (
              0 => 'rules_hr_submit_to_reliefweb',
            ),
            'user_permission' => 
            array (
              0 => 'flag hr_follow',
              1 => 'flag hr_reliefweb',
              2 => 'unflag hr_follow',
              3 => 'unflag hr_reliefweb',
            ),
            'views_view' => 
            array (
              0 => 'hr_follows',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_contacts' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_contacts/hr_contacts.module',
        'basename' => 'hr_contacts.module',
        'name' => 'hr_contacts',
        'info' => 
        array (
          'name' => 'Contacts',
          'description' => 'Contacts content type',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'auto_entitylabel',
            1 => 'context',
            2 => 'current_search',
            3 => 'entity',
            4 => 'entityreference',
            5 => 'field_permissions',
            6 => 'hr_bundles',
            7 => 'hr_disasters',
            8 => 'hr_offices',
            9 => 'hr_themes',
            10 => 'hr_users',
            11 => 'inline_entity_form',
            12 => 'list',
            13 => 'openlayers_views',
            14 => 'panels_bootstrap_styles',
            15 => 'taxonomy',
            16 => 'text',
            17 => 'views',
            18 => 'views_content',
            19 => 'views_data_export',
            20 => 'views_pdf',
            21 => 'visualization',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'hr_contacts_space',
              1 => 'hr_contacts_space_graphs',
              2 => 'hr_contacts_space_list',
              3 => 'hr_contacts_space_map',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'feeds:feeds_importer_default:1',
              2 => 'feeds_tamper:feeds_tamper_default:2',
              3 => 'openlayers:openlayers_maps:1',
              4 => 'page_manager:pages_default:1',
              5 => 'panelizer:panelizer:1',
              6 => 'strongarm:strongarm:1',
              7 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_contacts',
              1 => 'hr_contacts_1x',
              2 => 'hr_functional_roles',
            ),
            'feeds_tamper' => 
            array (
              0 => 'hr_contacts-clusters_sectors-explode',
              1 => 'hr_contacts-coordination_hubs-explode',
              2 => 'hr_contacts-disasters-explode',
              3 => 'hr_contacts-organization-explode',
              4 => 'hr_contacts-phones-explode',
              5 => 'hr_contacts-themes-explode',
              6 => 'hr_contacts_1x-clusters-explode',
              7 => 'hr_contacts_1x-coordination_hub-explode',
              8 => 'hr_contacts_1x-disasters-explode',
              9 => 'hr_contacts_1x-organization-explode',
              10 => 'hr_contacts_1x-telephones-explode',
              11 => 'hr_contacts_1x-theme_s_-explode',
            ),
            'field_base' => 
            array (
              0 => 'field_contact_information',
              1 => 'field_contacts',
              2 => 'field_functional_roles',
              3 => 'field_opt_out',
              4 => 'field_responder_in',
            ),
            'field_instance' => 
            array (
              0 => 'fieldable_panels_pane-hr_contacts-field_contacts',
              1 => 'fieldable_panels_pane-hr_contacts-title_field',
              2 => 'node-hr_contact-field_bundles',
              3 => 'node-hr_contact-field_coordination_hubs',
              4 => 'node-hr_contact-field_disasters',
              5 => 'node-hr_contact-field_email',
              6 => 'node-hr_contact-field_emails',
              7 => 'node-hr_contact-field_first_name',
              8 => 'node-hr_contact-field_functional_roles',
              9 => 'node-hr_contact-field_job_title_other',
              10 => 'node-hr_contact-field_last_name',
              11 => 'node-hr_contact-field_location',
              12 => 'node-hr_contact-field_locations',
              13 => 'node-hr_contact-field_opt_out',
              14 => 'node-hr_contact-field_organizations',
              15 => 'node-hr_contact-field_organizations_other',
              16 => 'node-hr_contact-field_phones',
              17 => 'node-hr_contact-field_skype_id',
              18 => 'node-hr_contact-field_social_media',
              19 => 'node-hr_contact-field_themes',
              20 => 'node-hr_contact-og_group_ref',
              21 => 'og_membership-hr_responder-field_contact_information',
              22 => 'taxonomy_term-hr_functional_role-name_field',
              23 => 'user-user-field_responder_in',
            ),
            'node' => 
            array (
              0 => 'hr_contact',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_operation:access authoring options of hr_contact content',
              1 => 'node:hr_operation:access publishing options of hr_contact content',
              2 => 'node:hr_operation:access revisions options of hr_contact content',
              3 => 'node:hr_operation:create hr_contact content',
              4 => 'node:hr_operation:delete any hr_contact content',
              5 => 'node:hr_operation:delete own hr_contact content',
              6 => 'node:hr_operation:update any hr_contact content',
              7 => 'node:hr_operation:update own hr_contact content',
              8 => 'node:hr_operation:view any unpublished hr_contact content',
              9 => 'node:hr_bundle:create hr_contact content',
              10 => 'node:hr_bundle:delete any hr_contact content',
              11 => 'node:hr_bundle:delete own hr_contact content',
              12 => 'node:hr_bundle:update any hr_contact content',
              13 => 'node:hr_bundle:update own hr_contact content',
            ),
            'og_membership_type' => 
            array (
              0 => 'hr_responder',
            ),
            'openlayers_maps' => 
            array (
              0 => 'hr_contacts',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_contact:default:default',
              1 => 'node:hr_contact:default:search_result',
              2 => 'node:hr_contact:default:teaser',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_functional_role',
            ),
            'user_permission' => 
            array (
              0 => 'create field_functional_roles',
              1 => 'create fieldable hr_contacts',
              2 => 'delete fieldable hr_contacts',
              3 => 'edit field_functional_roles',
              4 => 'edit fieldable hr_contacts',
              5 => 'edit own field_functional_roles',
              6 => 'view field_functional_roles',
              7 => 'view own field_functional_roles',
            ),
            'variable' => 
            array (
              0 => 'auto_entitylabel_node_hr_contact',
              1 => 'auto_entitylabel_pattern_node_hr_contact',
              2 => 'auto_entitylabel_php_node_hr_contact',
              3 => 'field_bundle_settings_node__hr_contact',
              4 => 'language_content_type_hr_contact',
              5 => 'menu_options_hr_contact',
              6 => 'menu_parent_hr_contact',
              7 => 'node_options_hr_contact',
              8 => 'node_preview_hr_contact',
              9 => 'node_submitted_hr_contact',
              10 => 'panelizer_defaults_node_hr_contact',
              11 => 'panelizer_node:hr_contact_allowed_layouts_default',
              12 => 'panelizer_node:hr_contact_allowed_types_default',
              13 => 'panelizer_node:hr_contact_default',
              14 => 'pathauto_node_hr_contact_pattern',
              15 => 'publishcontent_hr_contact',
            ),
            'views_view' => 
            array (
              0 => 'hr_contacts',
              1 => 'hr_contacts_graphs',
              2 => 'hr_contacts_panes',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'ctools' => 'ctools',
              'email' => 'email',
              'features' => 'features',
              'feeds' => 'feeds',
              'feeds_tamper' => 'feeds_tamper',
              'fieldable_panels_panes' => 'fieldable_panels_panes',
              'hr_core' => 'hr_core',
              'hr_operations' => 'hr_operations',
              'link' => 'link',
              'link_icons' => 'link_icons',
              'og' => 'og',
              'og_moderation' => 'og_moderation',
              'og_ui' => 'og_ui',
              'openlayers' => 'openlayers',
              'options' => 'options',
              'panelizer' => 'panelizer',
              'phone' => 'phone',
              'shs' => 'shs',
              'strongarm' => 'strongarm',
            ),
            'field_base' => 
            array (
              'field_email' => 'field_email',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_spaces' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_spaces/hr_spaces.module',
        'basename' => 'hr_spaces.module',
        'name' => 'hr_spaces',
        'info' => 
        array (
          'name' => 'Spaces',
          'description' => 'Content type for generic spaces',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'feeds',
            1 => 'hr_core',
            2 => 'hr_notifications',
            3 => 'hr_users',
            4 => 'link_icons',
            5 => 'media',
            6 => 'og_access',
            7 => 'og_features',
            8 => 'og_role_delegate',
            9 => 'taxonomy',
            10 => 'views_content',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'feeds:feeds_importer_default:1',
              1 => 'panelizer:panelizer:1',
              2 => 'strongarm:strongarm:1',
              3 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_space_categories',
              1 => 'hr_spaces',
            ),
            'field_base' => 
            array (
              0 => 'field_space_category',
              1 => 'field_space_type',
            ),
            'field_instance' => 
            array (
              0 => 'node-hr_space-body',
              1 => 'node-hr_space-field_email',
              2 => 'node-hr_space-field_image',
              3 => 'node-hr_space-field_mailchimp_api_key',
              4 => 'node-hr_space-field_mailchimp_list',
              5 => 'node-hr_space-field_organizations',
              6 => 'node-hr_space-field_social_media',
              7 => 'node-hr_space-field_space_category',
              8 => 'node-hr_space-field_space_type',
              9 => 'node-hr_space-field_users',
              10 => 'node-hr_space-field_website',
              11 => 'node-hr_space-group_access',
              12 => 'node-hr_space-group_group',
              13 => 'node-hr_space-og_roles_permissions',
              14 => 'node-hr_space-title_field',
              15 => 'taxonomy_term-hr_space_category-name_field',
            ),
            'node' => 
            array (
              0 => 'hr_space',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_space:add user',
              1 => 'node:hr_space:administer og menu',
              2 => 'node:hr_space:administer panelizer og_group content',
              3 => 'node:hr_space:approve and deny subscription',
              4 => 'node:hr_space:assign editor role',
              5 => 'node:hr_space:assign manager role',
              6 => 'node:hr_space:assign contributor role',
              7 => 'node:hr_space:edit group features',
              8 => 'node:hr_space:manage members',
              9 => 'node:hr_space:subscribe',
              10 => 'node:hr_space:subscribe without approval',
              11 => 'node:hr_space:update group',
              12 => 'node:hr_space:publish any content',
              13 => 'node:hr_space:unpublish any content',
            ),
            'og_features_role' => 
            array (
              0 => 'node:hr_space:editor',
              1 => 'node:hr_space:manager',
              2 => 'node:hr_space:contributor',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_space:default:default',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_space_category',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_hide_translation_links_hr_space',
              1 => 'entity_translation_node_metadata_hr_space',
              2 => 'entity_translation_settings_node__hr_space',
              3 => 'field_bundle_settings_node__hr_space',
              4 => 'language_content_type_hr_space',
              5 => 'menu_options_hr_space',
              6 => 'menu_parent_hr_space',
              7 => 'node_options_hr_space',
              8 => 'node_preview_hr_space',
              9 => 'node_submitted_hr_space',
              10 => 'og_features_settings_node_hr_space',
              11 => 'panelizer_defaults_node_hr_space',
              12 => 'panelizer_node:hr_space_allowed_layouts_default',
              13 => 'panelizer_node:hr_space_allowed_types',
              14 => 'panelizer_node:hr_space_allowed_types_default',
              15 => 'panelizer_node:hr_space_default',
            ),
            'views_view' => 
            array (
              0 => 'hr_spaces',
            ),
          ),
          'features_exclude' => 
          array (
            'field_base' => 
            array (
              'group_group' => 'group_group',
            ),
            'dependencies' => 
            array (
              'hr_spaces' => 'hr_spaces',
              'views' => 'views',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_wysiwyg' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_wysiwyg/hr_wysiwyg.module',
        'basename' => 'hr_wysiwyg.module',
        'name' => 'hr_wysiwyg',
        'info' => 
        array (
          'name' => 'WYSIWYG',
          'description' => 'Provides the WYSIWYG editor',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'features',
            2 => 'filter',
            3 => 'image_resize_filter',
            4 => 'linkit',
            5 => 'media_wysiwyg',
            6 => 'strongarm',
            7 => 'token_filter',
            8 => 'wysiwyg',
            9 => 'wysiwyg_filter',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'linkit:linkit_profiles:1',
              1 => 'strongarm:strongarm:1',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'filter' => 
            array (
              0 => 'full_html',
              1 => 'panopoly_html_text',
              2 => 'panopoly_wysiwyg_text',
              3 => 'hr_wysiwyg_trusted',
            ),
            'linkit_profiles' => 
            array (
              0 => 'content_editors',
            ),
            'user_permission' => 
            array (
              0 => 'use text format full_html',
              1 => 'use text format panopoly_html_text',
              2 => 'use text format panopoly_wysiwyg_text',
              3 => 'use text format hr_wysiwyg_trusted',
            ),
            'wysiwyg' => 
            array (
              0 => 'panopoly_html_text',
              1 => 'panopoly_wysiwyg_text',
              2 => 'hr_wysiwyg_trusted',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_assessments' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_assessments/hr_assessments.module',
        'basename' => 'hr_assessments.module',
        'name' => 'hr_assessments',
        'info' => 
        array (
          'name' => 'Assessments',
          'description' => 'Provides the Assessment content type',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'conditional_fields',
            1 => 'context',
            2 => 'ctools',
            3 => 'current_search',
            4 => 'date',
            5 => 'entity',
            6 => 'entityreference',
            7 => 'features',
            8 => 'feeds_tamper',
            9 => 'field_collection',
            10 => 'file',
            11 => 'hr_bundles',
            12 => 'hr_core',
            13 => 'hr_disasters',
            14 => 'hr_locations',
            15 => 'hr_operations',
            16 => 'hr_organizations',
            17 => 'hr_themes',
            18 => 'hr_users',
            19 => 'link',
            20 => 'list',
            21 => 'media',
            22 => 'og',
            23 => 'og_moderation',
            24 => 'og_ui',
            25 => 'openlayers_views',
            26 => 'options',
            27 => 'panelizer',
            28 => 'shs',
            29 => 'strongarm',
            30 => 'taxonomy',
            31 => 'text',
            32 => 'views',
            33 => 'views_data_export',
          ),
          'features' => 
          array (
            'conditional_fields' => 
            array (
              0 => 'field_collection_item:field_asst_data',
              1 => 'field_collection_item:field_asst_questionnaire',
              2 => 'field_collection_item:field_asst_report',
            ),
            'context' => 
            array (
              0 => 'hr_assessments_space',
              1 => 'hr_assessments_space_map',
              2 => 'hr_assessments_space_table',
              3 => 'hr_assessments_global',
              4 => 'hr_assessments_global_table',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'feeds:feeds_importer_default:1',
              2 => 'feeds_tamper:feeds_tamper_default:2',
              3 => 'panelizer:panelizer:1',
              4 => 'strongarm:strongarm:1',
              5 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_geographic_levels',
              1 => 'hr_population_types',
            ),
            'feeds_tamper' => 
            array (
              0 => 'hr_geographic_levels-spaces-explode',
            ),
            'field_base' => 
            array (
              0 => 'field_admin_level',
              1 => 'field_assessments',
              2 => 'field_asst_accessibility',
              3 => 'field_asst_collection_method',
              4 => 'field_asst_data',
              5 => 'field_asst_date',
              6 => 'field_asst_file',
              7 => 'field_asst_file_rest',
              8 => 'field_asst_freq',
              9 => 'field_asst_instructions',
              10 => 'field_asst_key_findings',
              11 => 'field_asst_methodology',
              12 => 'field_asst_other_location',
              13 => 'field_asst_questionnaire',
              14 => 'field_asst_report',
              15 => 'field_asst_sample_size',
              16 => 'field_asst_status',
              17 => 'field_asst_subject',
              18 => 'field_asst_unit',
              19 => 'field_asst_url',
              20 => 'field_asst_url_rest',
              21 => 'field_geographic_level',
              22 => 'field_organizations2',
              23 => 'field_population_types',
            ),
            'field_instance' => 
            array (
              0 => 'field_collection_item-field_asst_data-field_asst_accessibility',
              1 => 'field_collection_item-field_asst_data-field_asst_file',
              2 => 'field_collection_item-field_asst_data-field_asst_file_rest',
              3 => 'field_collection_item-field_asst_data-field_asst_instructions',
              4 => 'field_collection_item-field_asst_data-field_asst_url',
              5 => 'field_collection_item-field_asst_data-field_asst_url_rest',
              6 => 'field_collection_item-field_asst_questionnaire-field_asst_accessibility',
              7 => 'field_collection_item-field_asst_questionnaire-field_asst_file',
              8 => 'field_collection_item-field_asst_questionnaire-field_asst_file_rest',
              9 => 'field_collection_item-field_asst_questionnaire-field_asst_instructions',
              10 => 'field_collection_item-field_asst_questionnaire-field_asst_url',
              11 => 'field_collection_item-field_asst_questionnaire-field_asst_url_rest',
              12 => 'field_collection_item-field_asst_report-field_asst_accessibility',
              13 => 'field_collection_item-field_asst_report-field_asst_file',
              14 => 'field_collection_item-field_asst_report-field_asst_file_rest',
              15 => 'field_collection_item-field_asst_report-field_asst_instructions',
              16 => 'field_collection_item-field_asst_report-field_asst_url',
              17 => 'field_collection_item-field_asst_report-field_asst_url_rest',
              18 => 'fieldable_panels_pane-hr_assessments-field_assessments',
              19 => 'fieldable_panels_pane-hr_assessments-title_field',
              20 => 'node-hr_assessment-field_asst_collection_method',
              21 => 'node-hr_assessment-field_asst_data',
              22 => 'node-hr_assessment-field_asst_date',
              23 => 'node-hr_assessment-field_asst_freq',
              24 => 'node-hr_assessment-field_asst_key_findings',
              25 => 'node-hr_assessment-field_asst_methodology',
              26 => 'node-hr_assessment-field_asst_other_location',
              27 => 'node-hr_assessment-field_asst_questionnaire',
              28 => 'node-hr_assessment-field_asst_report',
              29 => 'node-hr_assessment-field_asst_sample_size',
              30 => 'node-hr_assessment-field_asst_status',
              31 => 'node-hr_assessment-field_asst_subject',
              32 => 'node-hr_assessment-field_asst_unit',
              33 => 'node-hr_assessment-field_bundles',
              34 => 'node-hr_assessment-field_disasters',
              35 => 'node-hr_assessment-field_geographic_level',
              36 => 'node-hr_assessment-field_locations',
              37 => 'node-hr_assessment-field_organizations',
              38 => 'node-hr_assessment-field_organizations2',
              39 => 'node-hr_assessment-field_population_types',
              40 => 'node-hr_assessment-field_related_content',
              41 => 'node-hr_assessment-field_themes',
              42 => 'node-hr_assessment-field_users_ref',
              43 => 'node-hr_assessment-group_content_access',
              44 => 'node-hr_assessment-og_group_ref',
              45 => 'node-hr_assessment-title_field',
              46 => 'node-hr_geographic_level-field_admin_level',
              47 => 'node-hr_geographic_level-og_group_ref',
              48 => 'node-hr_geographic_level-title_field',
              49 => 'taxonomy_term-hr_population_type-name_field',
            ),
            'node' => 
            array (
              0 => 'hr_assessment',
              1 => 'hr_geographic_level',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_bundle:access authoring options of hr_assessment content',
              1 => 'node:hr_bundle:access authoring options of hr_geographic_level content',
              2 => 'node:hr_bundle:access publishing options of hr_assessment content',
              3 => 'node:hr_bundle:access publishing options of hr_geographic_level content',
              4 => 'node:hr_bundle:access revisions options of hr_assessment content',
              5 => 'node:hr_bundle:access revisions options of hr_geographic_level content',
              6 => 'node:hr_bundle:create hr_assessment content',
              7 => 'node:hr_bundle:create hr_geographic_level content',
              8 => 'node:hr_bundle:delete any hr_assessment content',
              9 => 'node:hr_bundle:delete any hr_geographic_level content',
              10 => 'node:hr_bundle:delete own hr_assessment content',
              11 => 'node:hr_bundle:delete own hr_geographic_level content',
              12 => 'node:hr_bundle:update any hr_assessment content',
              13 => 'node:hr_bundle:update any hr_geographic_level content',
              14 => 'node:hr_bundle:update own hr_assessment content',
              15 => 'node:hr_bundle:update own hr_geographic_level content',
              16 => 'node:hr_bundle:view any unpublished hr_assessment content',
              17 => 'node:hr_bundle:view any unpublished hr_geographic_level content',
              18 => 'node:hr_operation:access authoring options of hr_assessment content',
              19 => 'node:hr_operation:access authoring options of hr_geographic_level content',
              20 => 'node:hr_operation:access publishing options of hr_assessment content',
              21 => 'node:hr_operation:access publishing options of hr_geographic_level content',
              22 => 'node:hr_operation:access revisions options of hr_assessment content',
              23 => 'node:hr_operation:access revisions options of hr_geographic_level content',
              24 => 'node:hr_operation:create hr_assessment content',
              25 => 'node:hr_operation:create hr_geographic_level content',
              26 => 'node:hr_operation:delete any hr_assessment content',
              27 => 'node:hr_operation:delete any hr_geographic_level content',
              28 => 'node:hr_operation:delete own hr_assessment content',
              29 => 'node:hr_operation:delete own hr_geographic_level content',
              30 => 'node:hr_operation:update any hr_assessment content',
              31 => 'node:hr_operation:update any hr_geographic_level content',
              32 => 'node:hr_operation:update own hr_assessment content',
              33 => 'node:hr_operation:update own hr_geographic_level content',
              34 => 'node:hr_operation:view any unpublished hr_assessment content',
              35 => 'node:hr_operation:view any unpublished hr_geographic_level content',
              36 => 'node:hr_sector:access authoring options of hr_assessment content',
              37 => 'node:hr_sector:access authoring options of hr_geographic_level content',
              38 => 'node:hr_sector:access publishing options of hr_assessment content',
              39 => 'node:hr_sector:access publishing options of hr_geographic_level content',
              40 => 'node:hr_sector:access revisions options of hr_assessment content',
              41 => 'node:hr_sector:access revisions options of hr_geographic_level content',
              42 => 'node:hr_sector:create hr_assessment content',
              43 => 'node:hr_sector:create hr_geographic_level content',
              44 => 'node:hr_sector:delete any hr_assessment content',
              45 => 'node:hr_sector:delete any hr_geographic_level content',
              46 => 'node:hr_sector:delete own hr_assessment content',
              47 => 'node:hr_sector:delete own hr_geographic_level content',
              48 => 'node:hr_sector:update any hr_assessment content',
              49 => 'node:hr_sector:update any hr_geographic_level content',
              50 => 'node:hr_sector:update own hr_assessment content',
              51 => 'node:hr_sector:update own hr_geographic_level content',
              52 => 'node:hr_sector:view any unpublished hr_assessment content',
              53 => 'node:hr_sector:view any unpublished hr_geographic_level content',
              54 => 'node:hr_space:access authoring options of hr_assessment content',
              55 => 'node:hr_space:access authoring options of hr_geographic_level content',
              56 => 'node:hr_space:access publishing options of hr_assessment content',
              57 => 'node:hr_space:access publishing options of hr_geographic_level content',
              58 => 'node:hr_space:access revisions options of hr_assessment content',
              59 => 'node:hr_space:access revisions options of hr_geographic_level content',
              60 => 'node:hr_space:create hr_assessment content',
              61 => 'node:hr_space:create hr_geographic_level content',
              62 => 'node:hr_space:delete any hr_assessment content',
              63 => 'node:hr_space:delete any hr_geographic_level content',
              64 => 'node:hr_space:delete own hr_assessment content',
              65 => 'node:hr_space:delete own hr_geographic_level content',
              66 => 'node:hr_space:update any hr_assessment content',
              67 => 'node:hr_space:update any hr_geographic_level content',
              68 => 'node:hr_space:update own hr_assessment content',
              69 => 'node:hr_space:update own hr_geographic_level content',
              70 => 'node:hr_space:view any unpublished hr_assessment content',
              71 => 'node:hr_space:view any unpublished hr_geographic_level content',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_assessment:default:default',
              1 => 'node:hr_assessment:default:search_result',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_population_type',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_settings_node__hr_assessment',
              1 => 'entity_translation_settings_node__hr_geographic_level',
              2 => 'field_bundle_settings_node__hr_assessment',
              3 => 'field_bundle_settings_node__hr_geographic_level',
              4 => 'language_content_type_hr_assessment',
              5 => 'language_content_type_hr_geographic_level',
              6 => 'menu_options_hr_assessment',
              7 => 'menu_options_hr_geographic_level',
              8 => 'menu_parent_hr_assessment',
              9 => 'menu_parent_hr_geographic_level',
              10 => 'node_options_hr_assessment',
              11 => 'node_options_hr_geographic_level',
              12 => 'node_preview_hr_assessment',
              13 => 'node_preview_hr_geographic_level',
              14 => 'node_submitted_hr_assessment',
              15 => 'node_submitted_hr_geographic_level',
              16 => 'panelizer_defaults_node_hr_assessment',
              17 => 'panelizer_defaults_node_hr_geographic_level',
              18 => 'panelizer_node:hr_assessment_allowed_layouts_default',
              19 => 'panelizer_node:hr_assessment_default',
              20 => 'pathauto_node_hr_assessment_pattern',
              21 => 'pathauto_node_hr_geographic_level_pattern',
              22 => 'publishcontent_hr_assessment',
            ),
            'views_view' => 
            array (
              0 => 'hr_assessments',
              1 => 'hr_assessments_panes',
              2 => 'hr_geographic_levels',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'feeds' => 'feeds',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_infographics' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_infographics/hr_infographics.module',
        'basename' => 'hr_infographics.module',
        'name' => 'hr_infographics',
        'info' => 
        array (
          'name' => 'Infographics',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'date',
            1 => 'entityreference',
            2 => 'feeds_tamper',
            3 => 'field_collection',
            4 => 'fieldable_panels_panes',
            5 => 'hr_documents',
            6 => 'link',
            7 => 'og_moderation',
            8 => 'og_ui',
            9 => 'panelizer',
            10 => 'shs',
            11 => 'strongarm',
            12 => 'views',
            13 => 'views_content',
            14 => 'views_data_export',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'hr_infographics_global',
              1 => 'hr_infographics_global_table',
              2 => 'hr_infographics_space',
              3 => 'hr_infographics_space_table',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'feeds:feeds_importer_default:1',
              2 => 'feeds_tamper:feeds_tamper_default:2',
              3 => 'panelizer:panelizer:1',
              4 => 'strongarm:strongarm:1',
              5 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_infographic_types',
              1 => 'hr_infographics',
            ),
            'feeds_tamper' => 
            array (
              0 => 'hr_infographics-clusters_sectors-explode',
              1 => 'hr_infographics-coordination_hubs-explode',
              2 => 'hr_infographics-disasters-explode',
              3 => 'hr_infographics-fundings-explode',
              4 => 'hr_infographics-locations-explode',
              5 => 'hr_infographics-organization-explode',
              6 => 'hr_infographics-sectors-explode',
              7 => 'hr_infographics-spaces-explode',
              8 => 'hr_infographics-themes-explode',
            ),
            'field_base' => 
            array (
              0 => 'field_data_sources',
              1 => 'field_infographic_type',
              2 => 'field_infographics',
            ),
            'field_instance' => 
            array (
              0 => 'fieldable_panels_pane-hr_infographics-field_infographics',
              1 => 'node-hr_infographic-body',
              2 => 'node-hr_infographic-field_bundles',
              3 => 'node-hr_infographic-field_coordination_hubs',
              4 => 'node-hr_infographic-field_data_sources',
              5 => 'node-hr_infographic-field_disasters',
              6 => 'node-hr_infographic-field_files_collection',
              7 => 'node-hr_infographic-field_fundings',
              8 => 'node-hr_infographic-field_infographic_type',
              9 => 'node-hr_infographic-field_locations',
              10 => 'node-hr_infographic-field_organizations',
              11 => 'node-hr_infographic-field_publication_date',
              12 => 'node-hr_infographic-field_related_content',
              13 => 'node-hr_infographic-field_sectors',
              14 => 'node-hr_infographic-field_themes',
              15 => 'node-hr_infographic-group_content_access',
              16 => 'node-hr_infographic-og_group_ref',
              17 => 'node-hr_infographic-title_field',
              18 => 'taxonomy_term-hr_infographic_type-field_acronym',
              19 => 'taxonomy_term-hr_infographic_type-name_field',
            ),
            'node' => 
            array (
              0 => 'hr_infographic',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_bundle:access authoring options of hr_infographic content',
              1 => 'node:hr_bundle:access publishing options of hr_infographic content',
              2 => 'node:hr_bundle:access revisions options of hr_infographic content',
              3 => 'node:hr_bundle:create hr_infographic content',
              4 => 'node:hr_bundle:delete any hr_infographic content',
              5 => 'node:hr_bundle:delete own hr_infographic content',
              6 => 'node:hr_bundle:update any hr_infographic content',
              7 => 'node:hr_bundle:update own hr_infographic content',
              8 => 'node:hr_bundle:view any unpublished hr_infographic content',
              9 => 'node:hr_operation:access authoring options of hr_infographic content',
              10 => 'node:hr_operation:access publishing options of hr_infographic content',
              11 => 'node:hr_operation:access revisions options of hr_infographic content',
              12 => 'node:hr_operation:create hr_infographic content',
              13 => 'node:hr_operation:delete any hr_infographic content',
              14 => 'node:hr_operation:delete own hr_infographic content',
              15 => 'node:hr_operation:update any hr_infographic content',
              16 => 'node:hr_operation:update own hr_infographic content',
              17 => 'node:hr_operation:view any unpublished hr_infographic content',
              18 => 'node:hr_sector:access authoring options of hr_infographic content',
              19 => 'node:hr_sector:access publishing options of hr_infographic content',
              20 => 'node:hr_sector:access revisions options of hr_infographic content',
              21 => 'node:hr_sector:create hr_infographic content',
              22 => 'node:hr_sector:delete any hr_infographic content',
              23 => 'node:hr_sector:delete own hr_infographic content',
              24 => 'node:hr_sector:update any hr_infographic content',
              25 => 'node:hr_sector:update own hr_infographic content',
              26 => 'node:hr_sector:view any unpublished hr_infographic content',
              27 => 'node:hr_space:access authoring options of hr_infographic content',
              28 => 'node:hr_space:access publishing options of hr_infographic content',
              29 => 'node:hr_space:access revisions options of hr_infographic content',
              30 => 'node:hr_space:create hr_infographic content',
              31 => 'node:hr_space:delete any hr_infographic content',
              32 => 'node:hr_space:delete own hr_infographic content',
              33 => 'node:hr_space:update any hr_infographic content',
              34 => 'node:hr_space:update own hr_infographic content',
              35 => 'node:hr_space:view any unpublished hr_infographic content',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_infographic:default:default',
              1 => 'node:hr_infographic:default:search_result',
              2 => 'node:hr_infographic:default:teaser',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_infographic_type',
            ),
            'user_permission' => 
            array (
              0 => 'create fieldable hr_infographics',
              1 => 'delete fieldable hr_infographics',
              2 => 'edit fieldable hr_infographics',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_settings_node__hr_infographic',
              1 => 'field_bundle_settings_node__hr_infographic',
              2 => 'language_content_type_hr_infographic',
              3 => 'menu_options_hr_infographic',
              4 => 'menu_parent_hr_infographic',
              5 => 'node_options_hr_infographic',
              6 => 'node_preview_hr_infographic',
              7 => 'node_submitted_hr_infographic',
              8 => 'panelizer_defaults_node_hr_infographic',
              9 => 'panelizer_node:hr_infographic_allowed_layouts_default',
              10 => 'panelizer_node:hr_infographic_default',
              11 => 'pathauto_node_hr_infographic_pattern',
              12 => 'publishcontent_hr_infographic',
            ),
            'views_view' => 
            array (
              0 => 'hr_infographics',
              1 => 'hr_infographics_panes',
              2 => 'hr_infographics_types',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'features' => 'features',
              'hr_core' => 'hr_core',
              'taxonomy' => 'taxonomy',
            ),
          ),
          'description' => '',
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_events' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_events/hr_events.module',
        'basename' => 'hr_events.module',
        'name' => 'hr_events',
        'info' => 
        array (
          'name' => 'Events',
          'description' => 'Provides the Event content type',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'addressfield',
            1 => 'calendar',
            2 => 'context',
            3 => 'ctools',
            4 => 'current_search',
            5 => 'date',
            6 => 'date_all_day',
            7 => 'date_ical',
            8 => 'date_popup',
            9 => 'date_repeat',
            10 => 'date_repeat_field',
            11 => 'date_views',
            12 => 'email',
            13 => 'entity',
            14 => 'entityreference',
            15 => 'features',
            16 => 'feeds',
            17 => 'field_collection',
            18 => 'hr_bundles',
            19 => 'hr_core',
            20 => 'hr_disasters',
            21 => 'hr_fundings',
            22 => 'hr_locations',
            23 => 'hr_offices',
            24 => 'hr_organizations',
            25 => 'hr_sectors',
            26 => 'hr_spaces',
            27 => 'hr_themes',
            28 => 'hr_users',
            29 => 'link',
            30 => 'list',
            31 => 'og',
            32 => 'og_moderation',
            33 => 'og_ui',
            34 => 'options',
            35 => 'panelizer',
            36 => 'phone',
            37 => 'radix_layouts',
            38 => 'shs',
            39 => 'strongarm',
            40 => 'taxonomy',
            41 => 'text',
            42 => 'views',
            43 => 'views_content',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'hr_events_global',
              1 => 'hr_events_space_list',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'feeds:feeds_importer_default:1',
              2 => 'page_manager:pages_default:1',
              3 => 'panelizer:panelizer:1',
              4 => 'strongarm:strongarm:1',
              5 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_event_categories',
              1 => 'hr_events',
            ),
            'field_base' => 
            array (
              0 => 'field_event_agenda',
              1 => 'field_event_category',
              2 => 'field_event_date',
              3 => 'field_event_meeting_minutes',
              4 => 'field_funding_methods',
            ),
            'field_instance' => 
            array (
              0 => 'node-hr_event-body',
              1 => 'node-hr_event-field_address',
              2 => 'node-hr_event-field_bundles',
              3 => 'node-hr_event-field_coordination_hubs',
              4 => 'node-hr_event-field_disasters',
              5 => 'node-hr_event-field_event_agenda',
              6 => 'node-hr_event-field_event_category',
              7 => 'node-hr_event-field_event_date',
              8 => 'node-hr_event-field_event_meeting_minutes',
              9 => 'node-hr_event-field_funding_methods',
              10 => 'node-hr_event-field_fundings',
              11 => 'node-hr_event-field_location',
              12 => 'node-hr_event-field_organizations',
              13 => 'node-hr_event-field_related_content',
              14 => 'node-hr_event-field_sectors',
              15 => 'node-hr_event-field_themes',
              16 => 'node-hr_event-field_users_ref',
              17 => 'node-hr_event-group_content_access',
              18 => 'node-hr_event-og_group_ref',
              19 => 'node-hr_event-title_field',
              20 => 'taxonomy_term-hr_event_category-name_field',
            ),
            'node' => 
            array (
              0 => 'hr_event',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_bundle:access authoring options of hr_event content',
              1 => 'node:hr_bundle:access publishing options of hr_event content',
              2 => 'node:hr_bundle:access revisions options of hr_event content',
              3 => 'node:hr_bundle:create hr_event content',
              4 => 'node:hr_bundle:delete any hr_event content',
              5 => 'node:hr_bundle:delete own hr_event content',
              6 => 'node:hr_bundle:update any hr_event content',
              7 => 'node:hr_bundle:update own hr_event content',
              8 => 'node:hr_bundle:view any unpublished hr_event content',
              9 => 'node:hr_operation:access authoring options of hr_event content',
              10 => 'node:hr_operation:access publishing options of hr_event content',
              11 => 'node:hr_operation:access revisions options of hr_event content',
              12 => 'node:hr_operation:create hr_event content',
              13 => 'node:hr_operation:delete any hr_event content',
              14 => 'node:hr_operation:delete own hr_event content',
              15 => 'node:hr_operation:update any hr_event content',
              16 => 'node:hr_operation:update own hr_event content',
              17 => 'node:hr_operation:view any unpublished hr_event content',
              18 => 'node:hr_sector:access authoring options of hr_event content',
              19 => 'node:hr_sector:access publishing options of hr_event content',
              20 => 'node:hr_sector:access revisions options of hr_event content',
              21 => 'node:hr_sector:create hr_event content',
              22 => 'node:hr_sector:delete any hr_event content',
              23 => 'node:hr_sector:delete own hr_event content',
              24 => 'node:hr_sector:update any hr_event content',
              25 => 'node:hr_sector:update own hr_event content',
              26 => 'node:hr_sector:view any unpublished hr_event content',
              27 => 'node:hr_space:access authoring options of hr_event content',
              28 => 'node:hr_space:access publishing options of hr_event content',
              29 => 'node:hr_space:access revisions options of hr_event content',
              30 => 'node:hr_space:create hr_event content',
              31 => 'node:hr_space:delete any hr_event content',
              32 => 'node:hr_space:delete own hr_event content',
              33 => 'node:hr_space:update any hr_event content',
              34 => 'node:hr_space:update own hr_event content',
              35 => 'node:hr_space:view any unpublished hr_event content',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_event:default:default',
              1 => 'node:hr_event:default:search_result',
              2 => 'node:hr_event:default:teaser',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_event_category',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_settings_node__hr_event',
              1 => 'field_bundle_settings_node__hr_event',
              2 => 'language_content_type_hr_event',
              3 => 'menu_options_hr_event',
              4 => 'menu_parent_hr_event',
              5 => 'node_options_hr_event',
              6 => 'node_preview_hr_event',
              7 => 'node_submitted_hr_event',
              8 => 'panelizer_defaults_node_hr_event',
              9 => 'pathauto_node_hr_event_pattern',
              10 => 'publishcontent_hr_event',
            ),
            'views_view' => 
            array (
              0 => 'hr_event_categories',
              1 => 'hr_events',
              2 => 'hr_events_calendar',
              3 => 'hr_events_panes',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'hr_operations' => 'hr_operations',
              'page_manager' => 'page_manager',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_job_titles' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_job_titles/hr_job_titles.module',
        'basename' => 'hr_job_titles.module',
        'name' => 'hr_job_titles',
        'info' => 
        array (
          'name' => 'Job Titles',
          'description' => 'Job Title taxonomy and fields',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'entityreference',
            2 => 'features',
            3 => 'feeds',
            4 => 'hr_core',
            5 => 'taxonomy',
            6 => 'text',
          ),
          'features' => 
          array (
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'field_base' => 
            array (
              0 => 'field_job_title_other',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_offices' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_offices/hr_offices.module',
        'basename' => 'hr_offices.module',
        'name' => 'hr_offices',
        'info' => 
        array (
          'name' => 'Offices',
          'description' => 'Defines the Office content type',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'addressfield',
            1 => 'ctools',
            2 => 'email',
            3 => 'entityreference',
            4 => 'features',
            5 => 'feeds',
            6 => 'feeds_tamper',
            7 => 'hr_core',
            8 => 'hr_locations',
            9 => 'hr_operations',
            10 => 'hr_organizations',
            11 => 'list',
            12 => 'og',
            13 => 'og_moderation',
            14 => 'og_ui',
            15 => 'options',
            16 => 'panelizer',
            17 => 'phone',
            18 => 'shs',
            19 => 'strongarm',
            20 => 'views',
            21 => 'views_data_export',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'feeds:feeds_importer_default:1',
              1 => 'feeds_tamper:feeds_tamper_default:2',
              2 => 'panelizer:panelizer:1',
              3 => 'strongarm:strongarm:1',
              4 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_offices',
            ),
            'feeds_tamper' => 
            array (
              0 => 'hr_offices-organization-explode',
              1 => 'hr_offices-spaces-explode',
            ),
            'field_base' => 
            array (
              0 => 'field_coordination_hubs',
              1 => 'field_is_coordination_hub',
            ),
            'field_instance' => 
            array (
              0 => 'node-hr_office-field_address',
              1 => 'node-hr_office-field_email',
              2 => 'node-hr_office-field_is_coordination_hub',
              3 => 'node-hr_office-field_location',
              4 => 'node-hr_office-field_organizations',
              5 => 'node-hr_office-field_phones',
              6 => 'node-hr_office-og_group_ref',
              7 => 'node-hr_office-title_field',
            ),
            'node' => 
            array (
              0 => 'hr_office',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_operation:access authoring options of hr_office content',
              1 => 'node:hr_operation:access publishing options of hr_office content',
              2 => 'node:hr_operation:access revisions options of hr_office content',
              3 => 'node:hr_operation:create hr_office content',
              4 => 'node:hr_operation:delete any hr_office content',
              5 => 'node:hr_operation:delete own hr_office content',
              6 => 'node:hr_operation:update any hr_office content',
              7 => 'node:hr_operation:update own hr_office content',
              8 => 'node:hr_operation:view any unpublished hr_office content',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_office:default:default',
              1 => 'node:hr_office:default:search_result',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_settings_node__hr_office',
              1 => 'field_bundle_settings_node__hr_office',
              2 => 'language_content_type_hr_office',
              3 => 'menu_options_hr_office',
              4 => 'menu_parent_hr_office',
              5 => 'node_options_hr_office',
              6 => 'node_preview_hr_office',
              7 => 'node_submitted_hr_office',
              8 => 'panelizer_defaults_node_hr_office',
              9 => 'panelizer_node:hr_office_allowed_layouts_default',
              10 => 'panelizer_node:hr_office_allowed_types_default',
              11 => 'panelizer_node:hr_office_default',
              12 => 'pathauto_node_hr_office_pattern',
            ),
            'views_view' => 
            array (
              0 => 'hr_offices',
              1 => 'hr_offices_panes',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_operations' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_operations/hr_operations.module',
        'basename' => 'hr_operations.module',
        'name' => 'hr_operations',
        'info' => 
        array (
          'name' => 'Operations',
          'description' => 'Operation content type',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'bean_pane',
            1 => 'chosen',
            2 => 'date',
            3 => 'feeds',
            4 => 'feeds_et',
            5 => 'fts_visualization',
            6 => 'hr_core',
            7 => 'hr_notifications',
            8 => 'hr_users',
            9 => 'link_icons',
            10 => 'og_access',
            11 => 'og_features',
            12 => 'og_role_delegate',
            13 => 'openlayers_views',
            14 => 'publishcontent',
            15 => 'shs',
            16 => 'views_content',
            17 => 'views_geojson',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'feeds:feeds_importer_default:1',
              1 => 'openlayers:openlayers_maps:1',
              2 => 'page_manager:pages_default:1',
              3 => 'panelizer:panelizer:1',
              4 => 'strongarm:strongarm:1',
              5 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_operations',
            ),
            'field_base' => 
            array (
              0 => 'field_cluster_configuration',
              1 => 'field_country',
              2 => 'field_hid_access',
              3 => 'field_launch_date',
              4 => 'field_operation_region',
              5 => 'field_operation_status',
              6 => 'field_operation_type',
            ),
            'field_instance' => 
            array (
              0 => 'node-hr_operation-body',
              1 => 'node-hr_operation-field_cluster_configuration',
              2 => 'node-hr_operation-field_country',
              3 => 'node-hr_operation-field_email',
              4 => 'node-hr_operation-field_hid_access',
              5 => 'node-hr_operation-field_launch_date',
              6 => 'node-hr_operation-field_mailchimp_api_key',
              7 => 'node-hr_operation-field_mailchimp_list',
              8 => 'node-hr_operation-field_operation_region',
              9 => 'node-hr_operation-field_operation_status',
              10 => 'node-hr_operation-field_operation_type',
              11 => 'node-hr_operation-field_organizations',
              12 => 'node-hr_operation-field_social_media',
              13 => 'node-hr_operation-field_users',
              14 => 'node-hr_operation-field_website',
              15 => 'node-hr_operation-group_access',
              16 => 'node-hr_operation-group_group',
              17 => 'node-hr_operation-title_field',
            ),
            'node' => 
            array (
              0 => 'hr_operation',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_operation:add user',
              1 => 'node:hr_operation:administer og menu',
              2 => 'node:hr_operation:administer panelizer og_group content',
              3 => 'node:hr_operation:approve and deny subscription',
              4 => 'node:hr_operation:assign contributor role',
              5 => 'node:hr_operation:assign editor role',
              6 => 'node:hr_operation:assign manager role',
              7 => 'node:hr_operation:edit group features',
              8 => 'node:hr_operation:manage members',
              9 => 'node:hr_operation:publish any content',
              10 => 'node:hr_operation:subscribe without approval',
              11 => 'node:hr_operation:unpublish any content',
              12 => 'node:hr_operation:update group',
            ),
            'og_features_role' => 
            array (
              0 => 'node:hr_operation:bundle member',
              1 => 'node:hr_operation:contributor',
              2 => 'node:hr_operation:editor',
              3 => 'node:hr_operation:manager',
            ),
            'openlayers_maps' => 
            array (
              0 => 'hr_operations',
            ),
            'page_manager_pages' => 
            array (
              0 => 'hr_operations',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_operation:default:default',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_hide_translation_links_hr_operation',
              1 => 'entity_translation_node_metadata_hr_operation',
              2 => 'entity_translation_settings_node__hr_operation',
              3 => 'field_bundle_settings_node__hr_operation',
              4 => 'language_content_type_hr_operation',
              5 => 'menu_options_hr_operation',
              6 => 'menu_parent_hr_operation',
              7 => 'node_options_hr_operation',
              8 => 'node_preview_hr_operation',
              9 => 'node_submitted_hr_operation',
              10 => 'og_features_settings_node_hr_operation',
              11 => 'panelizer_defaults_node_hr_operation',
              12 => 'panelizer_node:hr_operation_allowed_layouts_default',
              13 => 'panelizer_node:hr_operation_allowed_types',
              14 => 'panelizer_node:hr_operation_allowed_types_default',
              15 => 'panelizer_node:hr_operation_default',
              16 => 'pathauto_node_hr_operation_pattern',
            ),
            'views_view' => 
            array (
              0 => 'hr_operations',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'hr_operations' => 'hr_operations',
              'views' => 'views',
            ),
            'field_base' => 
            array (
              'group_group' => 'group_group',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_stats' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_stats/hr_stats.module',
        'basename' => 'hr_stats.module',
        'name' => 'hr_stats',
        'info' => 
        array (
          'name' => 'Statistics',
          'description' => 'Adds piwik reports to the HumanitarianResponse platform',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'features',
          ),
          'dependencies ' => 
          array (
            0 => 'og_variables',
          ),
          'features' => 
          array (
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_operation:access piwik reports',
              1 => 'node:hr_sector:access piwik reports',
              2 => 'node:hr_space:access piwik reports',
              3 => 'node:hr_disaster:access piwik reports',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_translations' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_translations/hr_translations.module',
        'basename' => 'hr_translations.module',
        'name' => 'hr_translations',
        'info' => 
        array (
          'name' => 'Translations',
          'description' => 'Translator role and dependencies',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'entity_translation',
            1 => 'role_export',
            2 => 'hr_users',
            3 => 'i18n_string',
            4 => 'tmgmt_entity_ui',
            5 => 'tmgmt_local',
          ),
          'features' => 
          array (
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'user_permission' => 
            array (
              0 => 'provide translation services',
              1 => 'translate admin strings',
              2 => 'translate fieldable_panels_pane entities',
              3 => 'translate interface',
              4 => 'translate node entities',
              5 => 'translate user-defined strings',
            ),
            'user_role' => 
            array (
              0 => 'translator',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'role_export' => 'role_export',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_bookmarks' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_bookmarks/hr_bookmarks.module',
        'basename' => 'hr_bookmarks.module',
        'name' => 'hr_bookmarks',
        'info' => 
        array (
          'name' => 'Bookmarks',
          'description' => 'Bookmark content and spaces',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'features',
            1 => 'flag',
            2 => 'hr_core',
            3 => 'hr_operations',
            4 => 'hr_sectors',
            5 => 'hr_spaces',
          ),
          'features' => 
          array (
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'flag' => 
            array (
              0 => 'hr_favorite_space',
            ),
            'user_permission' => 
            array (
              0 => 'flag hr_favorite_space',
              1 => 'unflag hr_favorite_space',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_users' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_users/hr_users.module',
        'basename' => 'hr_users.module',
        'name' => 'hr_users',
        'info' => 
        array (
          'name' => 'Users',
          'description' => 'User accounts and their profiles',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'conditional_fields',
            1 => 'ctools',
            2 => 'email',
            3 => 'email_registration',
            4 => 'entity',
            5 => 'entity_token',
            6 => 'entityreference',
            7 => 'features',
            8 => 'field_collection',
            9 => 'honeypot',
            10 => 'hr_core',
            11 => 'hr_job_titles',
            12 => 'hr_locations',
            13 => 'hr_organizations',
            14 => 'hr_sectors',
            15 => 'hr_themes',
            16 => 'image',
            17 => 'link',
            18 => 'link_icons',
            19 => 'list',
            20 => 'node',
            21 => 'og',
            22 => 'openlayers',
            23 => 'openlayers_views',
            24 => 'options',
            25 => 'page_manager',
            26 => 'panelizer',
            27 => 'phone',
            28 => 'profile2',
            29 => 'profile2_page',
            30 => 'realname',
            31 => 'role_export',
            32 => 'shs',
            33 => 'strongarm',
            34 => 'text',
            35 => 'user',
            36 => 'views',
            37 => 'views_content',
            38 => 'views_data_export',
          ),
          'features' => 
          array (
            'conditional_fields' => 
            array (
              0 => 'field_collection_item:field_users_ref',
            ),
            'ctools' => 
            array (
              0 => 'openlayers:openlayers_maps:1',
              1 => 'page_manager:pages_default:1',
              2 => 'panelizer:panelizer:1',
              3 => 'strongarm:strongarm:1',
              4 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'field_base' => 
            array (
              0 => 'field_first_name',
              1 => 'field_last_name',
              2 => 'field_skype_id',
              3 => 'field_user',
              4 => 'field_users',
              5 => 'field_users_ref',
              6 => 'field_users_ref_checkbox',
              7 => 'field_users_ref_name',
            ),
            'field_instance' => 
            array (
              0 => 'field_collection_item-field_users_ref-field_email',
              1 => 'field_collection_item-field_users_ref-field_phones',
              2 => 'field_collection_item-field_users_ref-field_user',
              3 => 'field_collection_item-field_users_ref-field_users_ref_checkbox',
              4 => 'field_collection_item-field_users_ref-field_users_ref_name',
              5 => 'profile2-main-field_emails',
              6 => 'profile2-main-field_first_name',
              7 => 'profile2-main-field_job_title_other',
              8 => 'profile2-main-field_last_name',
              9 => 'profile2-main-field_location',
              10 => 'profile2-main-field_organizations',
              11 => 'profile2-main-field_organizations_other',
              12 => 'profile2-main-field_phones',
              13 => 'profile2-main-field_sectors',
              14 => 'profile2-main-field_skype_id',
              15 => 'profile2-main-field_social_media',
              16 => 'profile2-main-field_themes',
            ),
            'image' => 
            array (
              0 => 'hr_user_thumbnail',
            ),
            'openlayers_maps' => 
            array (
              0 => 'hr_people',
            ),
            'page_manager_pages' => 
            array (
              0 => 'hr_user_check_ins',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'user:user:default:default',
              1 => 'user:user:default:teaser',
            ),
            'profile2_type' => 
            array (
              0 => 'main',
            ),
            'user_permission' => 
            array (
              0 => 'access user profiles',
              1 => 'administer group',
              2 => 'administer profile types',
              3 => 'administer profiles',
              4 => 'bypass node access',
              5 => 'delete revisions',
              6 => 'edit any main profile',
              7 => 'edit own main profile',
              8 => 'revert revisions',
              9 => 'view any main profile',
              10 => 'view own main profile',
              11 => 'view revisions',
            ),
            'user_role' => 
            array (
              0 => 'contributor',
              1 => 'editor',
              2 => 'trusted',
            ),
            'variable' => 
            array (
              0 => 'auto_entitylabel_pattern_profile2_main',
              1 => 'auto_entitylabel_profile2_main',
              2 => 'honeypot_form_user_register_form',
              3 => 'panelizer_defaults_user_user',
              4 => 'realname_pattern',
              5 => 'user_picture_default',
              6 => 'user_picture_dimensions',
              7 => 'user_picture_file_size',
              8 => 'user_picture_guidelines',
              9 => 'user_picture_path',
              10 => 'user_picture_style',
              11 => 'user_pictures',
              12 => 'user_register',
            ),
            'views_view' => 
            array (
              0 => 'hr_user_content',
              1 => 'hr_user_memberships',
              2 => 'hr_users',
            ),
          ),
          'features_exclude' => 
          array (
            'field_base' => 
            array (
              'field_phones' => 'field_phones',
              'field_emails' => 'field_emails',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_sectors' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_sectors/hr_sectors.module',
        'basename' => 'hr_sectors.module',
        'name' => 'hr_sectors',
        'info' => 
        array (
          'name' => 'Sectors',
          'description' => 'Content type for official sectors',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'email',
            2 => 'entityreference',
            3 => 'features',
            4 => 'feeds',
            5 => 'feeds_et',
            6 => 'hr_core',
            7 => 'hr_notifications',
            8 => 'image',
            9 => 'link',
            10 => 'link_icons',
            11 => 'list',
            12 => 'media',
            13 => 'og',
            14 => 'og_access',
            15 => 'og_features',
            16 => 'og_menu',
            17 => 'og_role_delegate',
            18 => 'og_ui',
            19 => 'options',
            20 => 'panelizer',
            21 => 'pathauto',
            22 => 'radix_layouts',
            23 => 'strongarm',
            24 => 'taxonomy',
            25 => 'text',
            26 => 'views',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'feeds:feeds_importer_default:1',
              1 => 'panelizer:panelizer:1',
              2 => 'strongarm:strongarm:1',
              3 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_sectors',
            ),
            'field_base' => 
            array (
              0 => 'field_sector',
              1 => 'field_sector_type',
              2 => 'field_sectors',
            ),
            'field_instance' => 
            array (
              0 => 'node-hr_sector-body',
              1 => 'node-hr_sector-field_acronym',
              2 => 'node-hr_sector-field_email',
              3 => 'node-hr_sector-field_image',
              4 => 'node-hr_sector-field_mailchimp_api_key',
              5 => 'node-hr_sector-field_mailchimp_list',
              6 => 'node-hr_sector-field_sector_type',
              7 => 'node-hr_sector-field_social_media',
              8 => 'node-hr_sector-field_website',
              9 => 'node-hr_sector-group_access',
              10 => 'node-hr_sector-group_group',
              11 => 'node-hr_sector-title_field',
            ),
            'node' => 
            array (
              0 => 'hr_sector',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_sector:add user',
              1 => 'node:hr_sector:administer og menu',
              2 => 'node:hr_sector:administer panelizer og_group content',
              3 => 'node:hr_sector:approve and deny subscription',
              4 => 'node:hr_sector:assign contributor role',
              5 => 'node:hr_sector:assign editor role',
              6 => 'node:hr_sector:assign manager role',
              7 => 'node:hr_sector:edit group features',
              8 => 'node:hr_sector:manage members',
              9 => 'node:hr_sector:publish any content',
              10 => 'node:hr_sector:subscribe',
              11 => 'node:hr_sector:subscribe without approval',
              12 => 'node:hr_sector:unpublish any content',
              13 => 'node:hr_sector:update group',
            ),
            'og_features_role' => 
            array (
              0 => 'node:hr_sector:contributor',
              1 => 'node:hr_sector:editor',
              2 => 'node:hr_sector:manager',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_sector:default:default',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_hide_translation_links_hr_sector',
              1 => 'entity_translation_node_metadata_hr_sector',
              2 => 'entity_translation_settings_node__hr_sector',
              3 => 'field_bundle_settings_node__hr_sector',
              4 => 'language_content_type_hr_sector',
              5 => 'menu_options_hr_sector',
              6 => 'menu_parent_hr_sector',
              7 => 'node_options_hr_sector',
              8 => 'node_preview_hr_sector',
              9 => 'node_submitted_hr_sector',
              10 => 'og_features_settings_node_hr_sector',
              11 => 'panelizer_defaults_node_hr_sector',
              12 => 'panelizer_node:hr_sector_allowed_layouts_default',
              13 => 'panelizer_node:hr_sector_allowed_types',
              14 => 'panelizer_node:hr_sector_allowed_types_default',
              15 => 'panelizer_node:hr_sector_default',
              16 => 'pathauto_node_hr_sector_pattern',
            ),
            'views_view' => 
            array (
              0 => 'hr_sectors',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'hr_sectors' => 'hr_sectors',
            ),
            'field_base' => 
            array (
              'group_group' => 'group_group',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_themes' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_themes/hr_themes.module',
        'basename' => 'hr_themes.module',
        'name' => 'hr_themes',
        'info' => 
        array (
          'name' => 'Themes',
          'description' => 'Provides the themes taxonomy',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'entityreference',
            1 => 'feeds',
            2 => 'hr_core',
            3 => 'taxonomy',
            4 => 'views',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'feeds:feeds_importer_default:1',
              1 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_themes',
            ),
            'field_base' => 
            array (
              0 => 'field_themes',
            ),
            'field_instance' => 
            array (
              0 => 'taxonomy_term-hr_theme-description_field',
              1 => 'taxonomy_term-hr_theme-field_acronym',
              2 => 'taxonomy_term-hr_theme-name_field',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_theme',
            ),
            'views_view' => 
            array (
              0 => 'hr_themes',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_datasets' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_datasets/hr_datasets.module',
        'basename' => 'hr_datasets.module',
        'name' => 'hr_datasets',
        'info' => 
        array (
          'name' => 'Datasets',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'context',
            1 => 'ctools',
            2 => 'current_search',
            3 => 'hr_locations',
            4 => 'hr_operations',
            5 => 'languagefield',
            6 => 'og_context',
            7 => 'og_moderation',
            8 => 'og_ui',
            9 => 'panels_bootstrap_styles',
            10 => 'search_api_views',
            11 => 'strongarm',
            12 => 'views',
            13 => 'views_data_export',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'hr_data',
              1 => 'hr_datasets_space',
              2 => 'hr_datasets_space_table',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'feeds:feeds_importer_default:1',
              2 => 'panelizer:panelizer:1',
              3 => 'strongarm:strongarm:1',
              4 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_dataset_categories',
              1 => 'hr_dataset_types',
            ),
            'field_base' => 
            array (
              0 => 'field_dataset_categories',
              1 => 'field_dataset_types',
              2 => 'field_ds_abstract',
              3 => 'field_ds_datasources',
              4 => 'field_ds_date',
              5 => 'field_ds_files',
              6 => 'field_ds_instructions',
              7 => 'field_ds_recent_changes',
              8 => 'field_ds_summary',
              9 => 'field_languages',
              10 => 'field_terms_of_use',
            ),
            'field_instance' => 
            array (
              0 => 'node-hr_dataset-field_dataset_categories',
              1 => 'node-hr_dataset-field_dataset_types',
              2 => 'node-hr_dataset-field_ds_abstract',
              3 => 'node-hr_dataset-field_ds_datasources',
              4 => 'node-hr_dataset-field_ds_date',
              5 => 'node-hr_dataset-field_ds_files',
              6 => 'node-hr_dataset-field_ds_instructions',
              7 => 'node-hr_dataset-field_ds_recent_changes',
              8 => 'node-hr_dataset-field_ds_summary',
              9 => 'node-hr_dataset-field_email',
              10 => 'node-hr_dataset-field_languages',
              11 => 'node-hr_dataset-field_locations',
              12 => 'node-hr_dataset-field_terms_of_use',
              13 => 'node-hr_dataset-og_group_ref',
              14 => 'node-hr_dataset-title_field',
              15 => 'taxonomy_term-hr_dataset_category-name_field',
              16 => 'taxonomy_term-hr_dataset_type-name_field',
            ),
            'node' => 
            array (
              0 => 'hr_dataset',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_operation:access authoring options of hr_dataset content',
              1 => 'node:hr_operation:access publishing options of hr_dataset content',
              2 => 'node:hr_operation:access revisions options of hr_dataset content',
              3 => 'node:hr_operation:create hr_dataset content',
              4 => 'node:hr_operation:delete any hr_dataset content',
              5 => 'node:hr_operation:delete own hr_dataset content',
              6 => 'node:hr_operation:update any hr_dataset content',
              7 => 'node:hr_operation:update own hr_dataset content',
              8 => 'node:hr_operation:view any unpublished hr_dataset content',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_dataset:default:default',
              1 => 'node:hr_dataset:default:search_result',
              2 => 'node:hr_dataset:default:teaser',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_dataset_category',
              1 => 'hr_dataset_type',
            ),
            'variable' => 
            array (
              0 => 'auto_entitylabel_node_hr_dataset',
              1 => 'auto_entitylabel_pattern_node_hr_dataset',
              2 => 'auto_entitylabel_php_node_hr_dataset',
              3 => 'entity_translation_settings_node__hr_dataset',
              4 => 'field_bundle_settings_node__hr_dataset',
              5 => 'language_content_type_hr_dataset',
              6 => 'menu_options_hr_dataset',
              7 => 'menu_parent_hr_dataset',
              8 => 'node_options_hr_dataset',
              9 => 'node_preview_hr_dataset',
              10 => 'node_submitted_hr_dataset',
              11 => 'panelizer_defaults_node_hr_dataset',
              12 => 'panelizer_node:hr_dataset_allowed_layouts_default',
              13 => 'panelizer_node:hr_dataset_allowed_types_default',
              14 => 'panelizer_node:hr_dataset_default',
              15 => 'pathauto_node_hr_dataset_pattern',
            ),
            'views_view' => 
            array (
              0 => 'hr_datasets',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'panelizer' => 'panelizer',
              'entity' => 'entity',
            ),
          ),
          'description' => '',
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_layout' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_layout/hr_layout.module',
        'basename' => 'hr_layout.module',
        'name' => 'hr_layout',
        'info' => 
        array (
          'name' => 'Layout',
          'description' => 'Puts the layout of the site in place',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'bean',
            1 => 'bean_pane',
            2 => 'context_og',
            3 => 'ctools',
            4 => 'entityreference_autocomplete',
            5 => 'fts_visualization',
            6 => 'hr_assessments',
            7 => 'hr_bookmarks',
            8 => 'hr_contacts',
            9 => 'hr_datasets',
            10 => 'hr_discussions',
            11 => 'hr_events',
            12 => 'hr_help',
            13 => 'hr_indicators',
            14 => 'hr_infographics',
            15 => 'hr_news',
            16 => 'hr_tools',
            17 => 'og_menu_single',
            18 => 'page_manager',
            19 => 'special_menu_items',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'hr_nodes',
              1 => 'hr_space_links',
              2 => 'hr_space_menu',
              3 => 'outside_space',
              4 => 'sitewide',
              5 => 'within_space',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'page_manager:pages_default:1',
              2 => 'strongarm:strongarm:1',
              3 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'field_instance' => 
            array (
              0 => 'fieldable_panels_pane-fieldable_panels_pane-description_field',
              1 => 'fieldable_panels_pane-fieldable_panels_pane-title_field',
            ),
            'page_manager_pages' => 
            array (
              0 => 'hr_clusters',
              1 => 'hr_coordination',
              2 => 'hr_home',
              3 => 'hr_programme_cycle',
            ),
            'user_permission' => 
            array (
              0 => 'create any fts_visualization bean',
              1 => 'delete any fts_visualization bean',
              2 => 'edit any fts_visualization bean',
              3 => 'view any fts_visualization bean',
              4 => 'create fieldable fieldable_panels_pane',
              5 => 'edit fieldable fieldable_panels_pane',
              6 => 'delete fieldable fieldable_panels_pane',
            ),
            'variable' => 
            array (
              0 => 'site_frontpage',
            ),
            'views_view' => 
            array (
              0 => 'hr_latest',
              1 => 'hr_space',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'views' => 'views',
              'og_context' => 'og_context',
            ),
            'menu_custom' => 
            array (
              'main-menu' => 'main-menu',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_documents' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_documents/hr_documents.module',
        'basename' => 'hr_documents.module',
        'name' => 'hr_documents',
        'info' => 
        array (
          'name' => 'Documents',
          'description' => 'Provides the Document content type',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'context',
            1 => 'current_search',
            2 => 'entityreference',
            3 => 'entityreference_filter',
            4 => 'hr_bundles',
            5 => 'hr_disasters',
            6 => 'hr_fundings',
            7 => 'hr_offices',
            8 => 'hr_spaces',
            9 => 'hr_themes',
            10 => 'languagefield',
            11 => 'panels_bootstrap_styles',
            12 => 'pdfpreview',
            13 => 'search_api_sorts',
            14 => 'views',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'hr_documents_space',
              1 => 'hr_documents_space_table',
              2 => 'hr_documents_global',
              3 => 'hr_documents_global_table',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'feeds:feeds_importer_default:1',
              2 => 'feeds_tamper:feeds_tamper_default:2',
              3 => 'file_entity:file_default_displays:1',
              4 => 'page_manager:pages_default:1',
              5 => 'panelizer:panelizer:1',
              6 => 'strongarm:strongarm:1',
              7 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_document_types',
              1 => 'hr_documents',
            ),
            'feeds_tamper' => 
            array (
              0 => 'hr_documents-clusters_sectors-explode',
              1 => 'hr_documents-coordination_hubs-explode',
              2 => 'hr_documents-disasters-explode',
              3 => 'hr_documents-fundings-explode',
              4 => 'hr_documents-locations-explode',
              5 => 'hr_documents-organization-explode',
              6 => 'hr_documents-sectors-explode',
              7 => 'hr_documents-spaces-explode',
              8 => 'hr_documents-themes-explode',
            ),
            'field_base' => 
            array (
              0 => 'field_document_type',
              1 => 'field_documents',
              2 => 'field_file',
              3 => 'field_files_collection',
              4 => 'field_language',
              5 => 'field_publication_date',
            ),
            'field_instance' => 
            array (
              0 => 'field_collection_item-field_files_collection-field_file',
              1 => 'field_collection_item-field_files_collection-field_language',
              2 => 'fieldable_panels_pane-hr_documents-field_documents',
              3 => 'node-hr_document-body',
              4 => 'node-hr_document-field_bundles',
              5 => 'node-hr_document-field_coordination_hubs',
              6 => 'node-hr_document-field_disasters',
              7 => 'node-hr_document-field_document_type',
              8 => 'node-hr_document-field_files_collection',
              9 => 'node-hr_document-field_fundings',
              10 => 'node-hr_document-field_locations',
              11 => 'node-hr_document-field_organizations',
              12 => 'node-hr_document-field_publication_date',
              13 => 'node-hr_document-field_related_content',
              14 => 'node-hr_document-field_sectors',
              15 => 'node-hr_document-field_themes',
              16 => 'node-hr_document-group_content_access',
              17 => 'node-hr_document-og_group_ref',
              18 => 'node-hr_document-title_field',
              19 => 'taxonomy_term-hr_document_type-description_field',
              20 => 'taxonomy_term-hr_document_type-field_acronym',
              21 => 'taxonomy_term-hr_document_type-name_field',
            ),
            'file_display' => 
            array (
              0 => 'document__default__file_field_file_download_link',
              1 => 'document__default__file_field_file_table',
              2 => 'document__default__file_field_file_url_plain',
              3 => 'document__default__file_field_media_large_icon',
              4 => 'document__default__file_field_pdfpreview',
              5 => 'document__default__media_vimeo_image',
              6 => 'document__default__media_vimeo_video',
              7 => 'document__preview__file_field_file_download_link',
              8 => 'document__preview__file_field_file_table',
              9 => 'document__preview__file_field_file_url_plain',
              10 => 'document__preview__file_field_pdfpreview',
              11 => 'document__preview__media_vimeo_image',
              12 => 'document__preview__media_vimeo_video',
            ),
            'node' => 
            array (
              0 => 'hr_document',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_bundle:access authoring options of hr_document content',
              1 => 'node:hr_bundle:access publishing options of hr_document content',
              2 => 'node:hr_bundle:access revisions options of hr_document content',
              3 => 'node:hr_bundle:create hr_document content',
              4 => 'node:hr_bundle:delete any hr_document content',
              5 => 'node:hr_bundle:delete own hr_document content',
              6 => 'node:hr_bundle:update any hr_document content',
              7 => 'node:hr_bundle:update own hr_document content',
              8 => 'node:hr_bundle:view any unpublished hr_document content',
              9 => 'node:hr_operation:access authoring options of hr_document content',
              10 => 'node:hr_operation:access publishing options of hr_document content',
              11 => 'node:hr_operation:access revisions options of hr_document content',
              12 => 'node:hr_operation:create hr_document content',
              13 => 'node:hr_operation:delete any hr_document content',
              14 => 'node:hr_operation:delete own hr_document content',
              15 => 'node:hr_operation:update any hr_document content',
              16 => 'node:hr_operation:update own hr_document content',
              17 => 'node:hr_operation:view any unpublished hr_document content',
              18 => 'node:hr_sector:access authoring options of hr_document content',
              19 => 'node:hr_sector:access publishing options of hr_document content',
              20 => 'node:hr_sector:access revisions options of hr_document content',
              21 => 'node:hr_sector:create hr_document content',
              22 => 'node:hr_sector:delete any hr_document content',
              23 => 'node:hr_sector:delete own hr_document content',
              24 => 'node:hr_sector:update any hr_document content',
              25 => 'node:hr_sector:update own hr_document content',
              26 => 'node:hr_sector:view any unpublished hr_document content',
              27 => 'node:hr_space:access authoring options of hr_document content',
              28 => 'node:hr_space:access publishing options of hr_document content',
              29 => 'node:hr_space:access revisions options of hr_document content',
              30 => 'node:hr_space:create hr_document content',
              31 => 'node:hr_space:delete any hr_document content',
              32 => 'node:hr_space:delete own hr_document content',
              33 => 'node:hr_space:update any hr_document content',
              34 => 'node:hr_space:update own hr_document content',
              35 => 'node:hr_space:view any unpublished hr_document content',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_document:default:default',
              1 => 'node:hr_document:default:search_result',
              2 => 'node:hr_document:default:teaser',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_document_type',
            ),
            'user_permission' => 
            array (
              0 => 'create fieldable hr_documents',
              1 => 'delete fieldable hr_documents',
              2 => 'edit fieldable hr_documents',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_settings_node__hr_document',
              1 => 'field_bundle_settings_node__hr_document',
              2 => 'language_content_type_hr_document',
              3 => 'menu_options_hr_document',
              4 => 'menu_parent_hr_document',
              5 => 'node_options_hr_document',
              6 => 'node_preview_hr_document',
              7 => 'node_submitted_hr_document',
              8 => 'panelizer_defaults_node_hr_document',
              9 => 'pathauto_node_hr_document_pattern',
              10 => 'publishcontent_hr_document',
            ),
            'views_view' => 
            array (
              0 => 'hr_document_types',
              1 => 'hr_documents',
              2 => 'hr_documents_panes',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_tools' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_tools/hr_tools.module',
        'basename' => 'hr_tools.module',
        'name' => 'hr_tools',
        'info' => 
        array (
          'name' => 'Tools',
          'description' => 'Tool content type',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'entityreference',
            2 => 'features',
            3 => 'feeds',
            4 => 'file',
            5 => 'hr_core',
            6 => 'link',
            7 => 'media',
            8 => 'og',
            9 => 'og_ui',
            10 => 'options',
            11 => 'strongarm',
            12 => 'taxonomy',
            13 => 'text',
            14 => 'views',
            15 => 'views_content',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'feeds:feeds_importer_default:1',
              1 => 'panelizer:panelizer:1',
              2 => 'strongarm:strongarm:1',
              3 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_toolbox_categories',
            ),
            'field_base' => 
            array (
              0 => 'field_toolbox_cat_type',
              1 => 'field_toolbox_categories',
              2 => 'field_toolbox_item_type',
            ),
            'field_instance' => 
            array (
              0 => 'node-hr_toolbox_category-field_toolbox_cat_type',
              1 => 'node-hr_toolbox_category-og_group_ref',
              2 => 'node-hr_toolbox_category-title_field',
              3 => 'node-hr_toolbox_item-body',
              4 => 'node-hr_toolbox_item-field_files',
              5 => 'node-hr_toolbox_item-field_image',
              6 => 'node-hr_toolbox_item-field_links',
              7 => 'node-hr_toolbox_item-field_toolbox_categories',
              8 => 'node-hr_toolbox_item-field_toolbox_item_type',
              9 => 'node-hr_toolbox_item-og_group_ref',
              10 => 'node-hr_toolbox_item-title_field',
            ),
            'node' => 
            array (
              0 => 'hr_toolbox_category',
              1 => 'hr_toolbox_item',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_toolbox_category:default',
              1 => 'node:hr_toolbox_category:default:default',
              2 => 'node:hr_toolbox_item:default:default',
              3 => 'node:hr_toolbox_item:default:search_result',
            ),
            'variable' => 
            array (
              0 => 'field_bundle_settings_node__hr_toolbox_category',
              1 => 'field_bundle_settings_node__hr_toolbox_item',
              2 => 'language_content_type_hr_toolbox_category',
              3 => 'language_content_type_hr_toolbox_item',
              4 => 'menu_options_hr_toolbox_category',
              5 => 'menu_options_hr_toolbox_item',
              6 => 'menu_parent_hr_toolbox_category',
              7 => 'menu_parent_hr_toolbox_item',
              8 => 'node_options_hr_toolbox_category',
              9 => 'node_options_hr_toolbox_item',
              10 => 'node_preview_hr_toolbox_category',
              11 => 'node_preview_hr_toolbox_item',
              12 => 'node_submitted_hr_toolbox_category',
              13 => 'node_submitted_hr_toolbox_item',
              14 => 'panelizer_defaults_node_hr_toolbox_category',
              15 => 'panelizer_defaults_node_hr_toolbox_item',
              16 => 'panelizer_node:hr_toolbox_item_allowed_layouts_default',
              17 => 'panelizer_node:hr_toolbox_item_allowed_types_default',
              18 => 'panelizer_node:hr_toolbox_item_default',
              19 => 'pathauto_node_hr_toolbox_category_pattern',
              20 => 'pathauto_node_hr_toolbox_item_pattern',
            ),
            'views_view' => 
            array (
              0 => 'hr_toolbox_panes',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'list' => 'list',
              'panelizer' => 'panelizer',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_help' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_help/hr_help.module',
        'basename' => 'hr_help.module',
        'name' => 'hr_help',
        'info' => 
        array (
          'name' => 'Help',
          'description' => 'Help features of Humanitarianresponse 2.x',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'bootstrap_tour',
            1 => 'ctools',
          ),
          'features' => 
          array (
            'bootstrap_tour' => 
            array (
              0 => 'adding_content',
              1 => 'anatomy_of_a_space',
              2 => 'edit_tab',
              3 => 'i_can_not_login',
              4 => 'inside_a_space',
              5 => 'introduction',
              6 => 'managing_a_space',
              7 => 'registering_on_humanitarianresponse',
              8 => 'space_functionalities',
            ),
            'ctools' => 
            array (
              0 => 'bootstrap_tour:bootstrap_tour_tour:1',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_core' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_core/hr_core.module',
        'basename' => 'hr_core.module',
        'name' => 'hr_core',
        'info' => 
        array (
          'name' => 'Core',
          'description' => 'Core features for Humanitarianresponse',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'addressfield',
            1 => 'ctools',
            2 => 'diff',
            3 => 'email',
            4 => 'entity_translation',
            5 => 'entityreference',
            6 => 'features',
            7 => 'field_ui',
            8 => 'fieldable_panels_panes',
            9 => 'file',
            10 => 'file_entity',
            11 => 'image',
            12 => 'imagemagick',
            13 => 'jquery_update',
            14 => 'link',
            15 => 'linkit',
            16 => 'list',
            17 => 'locale',
            18 => 'node',
            19 => 'og_menu',
            20 => 'openlayers',
            21 => 'panelizer',
            22 => 'panels',
            23 => 'panels_ipe',
            24 => 'panels_mini',
            25 => 'path_alias_xt',
            26 => 'pathauto',
            27 => 'phone',
            28 => 'publishcontent',
            29 => 'radix_layouts',
            30 => 'redirect',
            31 => 'role_export',
            32 => 'strongarm',
            33 => 'text',
            34 => 'title',
            35 => 'toolbar',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'openlayers:openlayers_styles:1',
              1 => 'page_manager:pages_default:1',
              2 => 'panels_mini:panels_default:1',
              3 => 'strongarm:strongarm:1',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'field_base' => 
            array (
              0 => 'body',
              1 => 'description_field',
              2 => 'field_acronym',
              3 => 'field_address',
              4 => 'field_email',
              5 => 'field_emails',
              6 => 'field_files',
              7 => 'field_image',
              8 => 'field_links',
              9 => 'field_phones',
              10 => 'field_related_content',
              11 => 'field_social_media',
              12 => 'field_website',
              13 => 'group_access',
              14 => 'group_content_access',
              15 => 'group_group',
              16 => 'name_field',
              17 => 'og_group_ref',
              18 => 'og_roles_permissions',
              19 => 'title_field',
            ),
            'language' => 
            array (
              0 => 'es',
              1 => 'fr',
            ),
            'openlayers_styles' => 
            array (
              0 => 'hr_default',
            ),
            'panels_mini' => 
            array (
              0 => 'hr_node_links',
            ),
            'user_permission' => 
            array (
              0 => 'administer panels styles',
              1 => 'change layouts in place editing',
              2 => 'create files',
              3 => 'use panels in place editing',
              4 => 'view own files',
              5 => 'view own private files',
              6 => 'view own unpublished content',
            ),
            'user_role' => 
            array (
              0 => 'administrator',
            ),
            'variable' => 
            array (
              0 => 'admin_theme',
              1 => 'chosen_minimum_multiple',
              2 => 'chosen_minimum_single',
              3 => 'date_default_timezone',
              4 => 'date_first_day',
              5 => 'date_format_hr_1',
              6 => 'date_format_hr_2',
              7 => 'empty_timezone_message',
              8 => 'entity_translation_entity_types',
              9 => 'features_default_export_path',
              10 => 'file_private_path',
              11 => 'image_toolkit',
              12 => 'imagemagick_convert',
              13 => 'jquery_update_jquery_version',
              14 => 'language_negotiation_language',
              15 => 'language_negotiation_language_content',
              16 => 'language_negotiation_language_url',
              17 => 'og_menu_create_by_default',
              18 => 'panels_page_allowed_layouts',
              19 => 'panels_page_default',
              20 => 'site_default_country',
              21 => 'theme_default',
              22 => 'user_admin_role',
              23 => 'user_default_timezone',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_fundings' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_fundings/hr_fundings.module',
        'basename' => 'hr_fundings.module',
        'name' => 'hr_fundings',
        'info' => 
        array (
          'name' => 'Fundings',
          'description' => 'Provides the Funding method content type',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'entityreference',
            2 => 'features',
            3 => 'feeds',
            4 => 'feeds_tamper',
            5 => 'fts',
            6 => 'hr_core',
            7 => 'hr_operations',
            8 => 'list',
            9 => 'number',
            10 => 'og',
            11 => 'og_moderation',
            12 => 'og_ui',
            13 => 'options',
            14 => 'panelizer',
            15 => 'strongarm',
            16 => 'taxonomy',
            17 => 'text',
            18 => 'views',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'feeds:feeds_importer_default:1',
              1 => 'feeds_tamper:feeds_tamper_default:2',
              2 => 'panelizer:panelizer:1',
              3 => 'strongarm:strongarm:1',
              4 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_funding_methods',
              1 => 'hr_funding_types',
            ),
            'feeds_tamper' => 
            array (
              0 => 'hr_funding_methods-spaces-explode',
            ),
            'field_base' => 
            array (
              0 => 'field_appeal_id',
              1 => 'field_funding_type',
              2 => 'field_fundings',
            ),
            'field_instance' => 
            array (
              0 => 'node-hr_funding-body',
              1 => 'node-hr_funding-field_acronym',
              2 => 'node-hr_funding-field_appeal_id',
              3 => 'node-hr_funding-field_funding_type',
              4 => 'node-hr_funding-group_content_access',
              5 => 'node-hr_funding-og_group_ref',
              6 => 'node-hr_funding-title_field',
              7 => 'node-hr_funding_method-body',
              8 => 'node-hr_funding_method-field_funding_type',
              9 => 'node-hr_funding_method-og_group_ref',
              10 => 'node-hr_funding_method-title_field',
              11 => 'taxonomy_term-hr_funding_type-name_field',
            ),
            'node' => 
            array (
              0 => 'hr_funding',
              1 => 'hr_funding_method',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_operation:access authoring options of hr_funding_method content',
              1 => 'node:hr_operation:access publishing options of hr_funding_method content',
              2 => 'node:hr_operation:access revisions options of hr_funding_method content',
              3 => 'node:hr_operation:administer panelizer node hr_funding_method content',
              4 => 'node:hr_operation:create hr_funding_method content',
              5 => 'node:hr_operation:delete any hr_funding_method content',
              6 => 'node:hr_operation:delete own hr_funding_method content',
              7 => 'node:hr_operation:update any hr_funding_method content',
              8 => 'node:hr_operation:update own hr_funding_method content',
              9 => 'node:hr_operation:view any unpublished hr_funding_method content',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_funding:default:default',
              1 => 'node:hr_funding:default:search_result',
              2 => 'node:hr_funding_method:default:default',
              3 => 'node:hr_funding_method:default:search_result',
              4 => 'node:hr_funding_method:default:teaser',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_funding_type',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_settings_node__hr_funding_method',
              1 => 'field_bundle_settings_node__hr_funding',
              2 => 'field_bundle_settings_node__hr_funding_method',
              3 => 'language_content_type_hr_funding',
              4 => 'language_content_type_hr_funding_method',
              5 => 'menu_options_hr_funding',
              6 => 'menu_options_hr_funding_method',
              7 => 'menu_parent_hr_funding',
              8 => 'menu_parent_hr_funding_method',
              9 => 'node_options_hr_funding',
              10 => 'node_options_hr_funding_method',
              11 => 'node_preview_hr_funding',
              12 => 'node_preview_hr_funding_method',
              13 => 'node_submitted_hr_funding',
              14 => 'node_submitted_hr_funding_method',
              15 => 'panelizer_defaults_node_hr_funding_method',
              16 => 'panelizer_node:hr_funding_allowed_layouts_default',
              17 => 'panelizer_node:hr_funding_allowed_types_default',
              18 => 'panelizer_node:hr_funding_default',
              19 => 'panelizer_node:hr_funding_method_allowed_layouts_default',
              20 => 'panelizer_node:hr_funding_method_default',
              21 => 'pathauto_node_hr_funding_method_pattern',
              22 => 'pathauto_node_hr_funding_pattern',
            ),
            'views_view' => 
            array (
              0 => 'hr_fundings_panes',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_news' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_news/hr_news.module',
        'basename' => 'hr_news.module',
        'name' => 'hr_news',
        'info' => 
        array (
          'name' => 'News',
          'description' => 'Provides the News content type',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'context',
            1 => 'ctools',
            2 => 'current_search',
            3 => 'entity',
            4 => 'entityreference',
            5 => 'features',
            6 => 'feeds',
            7 => 'feeds_tamper',
            8 => 'hr_bundles',
            9 => 'hr_disasters',
            10 => 'hr_fundings',
            11 => 'hr_offices',
            12 => 'hr_operations',
            13 => 'hr_sectors',
            14 => 'hr_spaces',
            15 => 'hr_themes',
            16 => 'image',
            17 => 'link',
            18 => 'list',
            19 => 'media',
            20 => 'og_moderation',
            21 => 'options',
            22 => 'page_manager',
            23 => 'panelizer',
            24 => 'radix_layouts',
            25 => 'shs',
            26 => 'strongarm',
            27 => 'text',
            28 => 'views',
            29 => 'views_content',
          ),
          'ependencies' => 
          array (
            0 => 'og',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'hr_news_global',
              1 => 'hr_news_space',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'feeds:feeds_importer_default:1',
              2 => 'feeds_tamper:feeds_tamper_default:2',
              3 => 'page_manager:pages_default:1',
              4 => 'panelizer:panelizer:1',
              5 => 'strongarm:strongarm:1',
              6 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_news',
            ),
            'feeds_tamper' => 
            array (
              0 => 'hr_news-clusters_sectors-explode',
              1 => 'hr_news-coordination_hubs-explode',
              2 => 'hr_news-disasters-explode',
              3 => 'hr_news-fundings-explode',
              4 => 'hr_news-locations-explode',
              5 => 'hr_news-organization-explode',
              6 => 'hr_news-sectors-explode',
              7 => 'hr_news-themes-explode',
            ),
            'field_instance' => 
            array (
              0 => 'node-hr_news-body',
              1 => 'node-hr_news-field_bundles',
              2 => 'node-hr_news-field_coordination_hubs',
              3 => 'node-hr_news-field_disasters',
              4 => 'node-hr_news-field_fundings',
              5 => 'node-hr_news-field_image',
              6 => 'node-hr_news-field_locations',
              7 => 'node-hr_news-field_organizations',
              8 => 'node-hr_news-field_related_content',
              9 => 'node-hr_news-field_sectors',
              10 => 'node-hr_news-field_themes',
              11 => 'node-hr_news-group_content_access',
              12 => 'node-hr_news-og_group_ref',
              13 => 'node-hr_news-title_field',
            ),
            'node' => 
            array (
              0 => 'hr_news',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_bundle:access authoring options of hr_news content',
              1 => 'node:hr_bundle:access publishing options of hr_news content',
              2 => 'node:hr_bundle:access revisions options of hr_news content',
              3 => 'node:hr_bundle:create hr_news content',
              4 => 'node:hr_bundle:delete any hr_news content',
              5 => 'node:hr_bundle:delete own hr_news content',
              6 => 'node:hr_bundle:update any hr_news content',
              7 => 'node:hr_bundle:update own hr_news content',
              8 => 'node:hr_bundle:view any unpublished hr_news content',
              9 => 'node:hr_operation:access authoring options of hr_news content',
              10 => 'node:hr_operation:access publishing options of hr_news content',
              11 => 'node:hr_operation:access revisions options of hr_news content',
              12 => 'node:hr_operation:create hr_news content',
              13 => 'node:hr_operation:delete any hr_news content',
              14 => 'node:hr_operation:delete own hr_news content',
              15 => 'node:hr_operation:update any hr_news content',
              16 => 'node:hr_operation:update own hr_news content',
              17 => 'node:hr_operation:view any unpublished hr_news content',
              18 => 'node:hr_sector:access authoring options of hr_news content',
              19 => 'node:hr_sector:access publishing options of hr_news content',
              20 => 'node:hr_sector:access revisions options of hr_news content',
              21 => 'node:hr_sector:create hr_news content',
              22 => 'node:hr_sector:delete any hr_news content',
              23 => 'node:hr_sector:delete own hr_news content',
              24 => 'node:hr_sector:update any hr_news content',
              25 => 'node:hr_sector:update own hr_news content',
              26 => 'node:hr_sector:view any unpublished hr_news content',
              27 => 'node:hr_space:access authoring options of hr_news content',
              28 => 'node:hr_space:access publishing options of hr_news content',
              29 => 'node:hr_space:access revisions options of hr_news content',
              30 => 'node:hr_space:create hr_news content',
              31 => 'node:hr_space:delete any hr_news content',
              32 => 'node:hr_space:delete own hr_news content',
              33 => 'node:hr_space:update any hr_news content',
              34 => 'node:hr_space:update own hr_news content',
              35 => 'node:hr_space:view any unpublished hr_news content',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_news:default:default',
              1 => 'node:hr_news:default:search_result',
              2 => 'node:hr_news:default:teaser',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_settings_node__hr_news',
              1 => 'field_bundle_settings_node__hr_news',
              2 => 'language_content_type_hr_news',
              3 => 'menu_options_hr_news',
              4 => 'menu_parent_hr_news',
              5 => 'node_options_hr_news',
              6 => 'node_preview_hr_news',
              7 => 'node_submitted_hr_news',
              8 => 'panelizer_defaults_node_hr_news',
              9 => 'pathauto_node_hr_news_pattern',
              10 => 'publishcontent_hr_news',
            ),
            'views_view' => 
            array (
              0 => 'hr_news',
              1 => 'hr_news_panes',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_search' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_search/hr_search.module',
        'basename' => 'hr_search.module',
        'name' => 'hr_search',
        'info' => 
        array (
          'name' => 'Search',
          'description' => 'Provides the Solr search index',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'context',
            1 => 'ctools',
            2 => 'current_search',
            3 => 'entity',
            4 => 'facetapi',
            5 => 'facetapi_pretty_paths',
            6 => 'features',
            7 => 'search_api',
            8 => 'search_api_facetapi',
            9 => 'search_api_solr',
            10 => 'search_api_sorts',
            11 => 'search_api_sorts_widget',
            12 => 'search_api_views',
            13 => 'strongarm',
            14 => 'views',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'hr_search',
              1 => 'hr_search_space',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'current_search:current_search:1',
              2 => 'facetapi:facetapi_defaults:1',
              3 => 'strongarm:strongarm:1',
              4 => 'views:views_default:3.0',
            ),
            'current_search' => 
            array (
              0 => 'hr_current_search',
            ),
            'facetapi' => 
            array (
              0 => 'search_api@default_node_index::field_asst_date:value',
              1 => 'search_api@default_node_index::field_asst_status',
              2 => 'search_api@default_node_index::field_bundles',
              3 => 'search_api@default_node_index::field_bundles:field_sector',
              4 => 'search_api@default_node_index::field_coordination_hubs',
              5 => 'search_api@default_node_index::field_dataset_categories',
              6 => 'search_api@default_node_index::field_dataset_types',
              7 => 'search_api@default_node_index::field_disaster_status',
              8 => 'search_api@default_node_index::field_disasters',
              9 => 'search_api@default_node_index::field_document_type',
              10 => 'search_api@default_node_index::field_event_category',
              11 => 'search_api@default_node_index::field_functional_roles',
              12 => 'search_api@default_node_index::field_fundings',
              13 => 'search_api@default_node_index::field_geographic_level',
              14 => 'search_api@default_node_index::field_glide_type',
              15 => 'search_api@default_node_index::field_ind_cross_tagging',
              16 => 'search_api@default_node_index::field_ind_domain',
              17 => 'search_api@default_node_index::field_ind_key',
              18 => 'search_api@default_node_index::field_ind_standards',
              19 => 'search_api@default_node_index::field_ind_types',
              20 => 'search_api@default_node_index::field_infographic_type',
              21 => 'search_api@default_node_index::field_languages:safe_value',
              22 => 'search_api@default_node_index::field_location',
              23 => 'search_api@default_node_index::field_locations',
              24 => 'search_api@default_node_index::field_organizations',
              25 => 'search_api@default_node_index::field_organizations2',
              26 => 'search_api@default_node_index::field_population_types',
              27 => 'search_api@default_node_index::field_publication_date',
              28 => 'search_api@default_node_index::field_sector',
              29 => 'search_api@default_node_index::field_sectors',
              30 => 'search_api@default_node_index::field_themes',
              31 => 'search_api@default_node_index::og_group_ref',
              32 => 'search_api@default_node_index::type',
              33 => 'search_api@default_node_index:block:field_asst_date:value',
              34 => 'search_api@default_node_index:block:field_asst_status',
              35 => 'search_api@default_node_index:block:field_bundles',
              36 => 'search_api@default_node_index:block:field_bundles:field_sector',
              37 => 'search_api@default_node_index:block:field_coordination_hubs',
              38 => 'search_api@default_node_index:block:field_dataset_categories',
              39 => 'search_api@default_node_index:block:field_dataset_types',
              40 => 'search_api@default_node_index:block:field_disaster_status',
              41 => 'search_api@default_node_index:block:field_disasters',
              42 => 'search_api@default_node_index:block:field_document_type',
              43 => 'search_api@default_node_index:block:field_event_category',
              44 => 'search_api@default_node_index:block:field_functional_roles',
              45 => 'search_api@default_node_index:block:field_funding_methods',
              46 => 'search_api@default_node_index:block:field_funding_types',
              47 => 'search_api@default_node_index:block:field_fundings',
              48 => 'search_api@default_node_index:block:field_geographic_level',
              49 => 'search_api@default_node_index:block:field_glide_type',
              50 => 'search_api@default_node_index:block:field_ind_cross_tagging',
              51 => 'search_api@default_node_index:block:field_ind_domain',
              52 => 'search_api@default_node_index:block:field_ind_key',
              53 => 'search_api@default_node_index:block:field_ind_standards',
              54 => 'search_api@default_node_index:block:field_ind_types',
              55 => 'search_api@default_node_index:block:field_infographic_type',
              56 => 'search_api@default_node_index:block:field_languages:safe_value',
              57 => 'search_api@default_node_index:block:field_location',
              58 => 'search_api@default_node_index:block:field_locations',
              59 => 'search_api@default_node_index:block:field_organizations',
              60 => 'search_api@default_node_index:block:field_organizations2',
              61 => 'search_api@default_node_index:block:field_population_types',
              62 => 'search_api@default_node_index:block:field_publication_date',
              63 => 'search_api@default_node_index:block:field_sector',
              64 => 'search_api@default_node_index:block:field_sectors',
              65 => 'search_api@default_node_index:block:field_themes',
              66 => 'search_api@default_node_index:block:og_group_ref',
              67 => 'search_api@default_node_index:block:type',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'search_api_index' => 
            array (
              0 => 'default_node_index',
            ),
            'search_api_server' => 
            array (
              0 => 'hr_solr',
            ),
            'search_api_sort' => 
            array (
              0 => 'default_node_index__changed',
              1 => 'default_node_index__created',
              2 => 'default_node_index__field_asst_date:value',
              3 => 'default_node_index__field_ds_date',
              4 => 'default_node_index__field_first_name',
              5 => 'default_node_index__field_last_name',
              6 => 'default_node_index__field_publication_date',
            ),
            'user_permission' => 
            array (
              0 => 'use search_api_sorts',
            ),
            'variable' => 
            array (
              0 => 'facetapi_pretty_paths_searcher_search_api@default_node_index',
              1 => 'facetapi_pretty_paths_searcher_search_api@default_node_index_options',
            ),
            'views_view' => 
            array (
              0 => 'hr_search',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_webforms' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_webforms/hr_webforms.module',
        'basename' => 'hr_webforms.module',
        'name' => 'hr_webforms',
        'info' => 
        array (
          'name' => 'Webforms',
          'description' => 'Provides webforms to space managers',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'features',
            2 => 'honeypot',
            3 => 'hr_core',
            4 => 'hr_operations',
            5 => 'hr_sectors',
            6 => 'hr_spaces',
            7 => 'og',
            8 => 'og_moderation',
            9 => 'og_ui',
            10 => 'panelizer',
            11 => 'strongarm',
            12 => 'webform',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'panelizer:panelizer:1',
              1 => 'strongarm:strongarm:1',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'field_instance' => 
            array (
              0 => 'node-webform-og_group_ref',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_operation:access authoring options of webform content',
              1 => 'node:hr_operation:access publishing options of webform content',
              2 => 'node:hr_operation:access revisions options of webform content',
              3 => 'node:hr_operation:create webform content',
              4 => 'node:hr_operation:delete any webform content',
              5 => 'node:hr_operation:delete own webform content',
              6 => 'node:hr_operation:update any webform content',
              7 => 'node:hr_operation:update own webform content',
              8 => 'node:hr_operation:view any unpublished webform content',
              9 => 'node:hr_sector:access authoring options of webform content',
              10 => 'node:hr_sector:access publishing options of webform content',
              11 => 'node:hr_sector:access revisions options of webform content',
              12 => 'node:hr_sector:create webform content',
              13 => 'node:hr_sector:delete any webform content',
              14 => 'node:hr_sector:delete own webform content',
              15 => 'node:hr_sector:update any webform content',
              16 => 'node:hr_sector:update own webform content',
              17 => 'node:hr_sector:view any unpublished webform content',
              18 => 'node:hr_space:access authoring options of webform content',
              19 => 'node:hr_space:access publishing options of webform content',
              20 => 'node:hr_space:access revisions options of webform content',
              21 => 'node:hr_space:create webform content',
              22 => 'node:hr_space:delete any webform content',
              23 => 'node:hr_space:delete own webform content',
              24 => 'node:hr_space:update any webform content',
              25 => 'node:hr_space:update own webform content',
              26 => 'node:hr_space:view any unpublished webform content',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:webform:default:default',
            ),
            'variable' => 
            array (
              0 => 'honeypot_form_webforms',
              1 => 'node_options_webform',
              2 => 'node_preview_webform',
              3 => 'node_submitted_webform',
              4 => 'panelizer_defaults_node_webform',
              5 => 'panelizer_node:webform_allowed_layouts_default',
              6 => 'panelizer_node:webform_allowed_types_default',
              7 => 'pathauto_node_webform_pattern',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_locations' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_locations/hr_locations.module',
        'basename' => 'hr_locations.module',
        'name' => 'hr_locations',
        'info' => 
        array (
          'name' => 'Locations',
          'description' => 'Locations taxonomy',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'entityreference',
            2 => 'features',
            3 => 'feeds',
            4 => 'field_validation',
            5 => 'geofield',
            6 => 'geofield_postgis',
            7 => 'hr_core',
            8 => 'number',
            9 => 'shs',
            10 => 'spatial_import',
            11 => 'strongarm',
            12 => 'taxonomy',
            13 => 'text',
            14 => 'views',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'feeds:feeds_importer_default:1',
              1 => 'field_validation:default_field_validation_rules:2',
              2 => 'strongarm:strongarm:1',
              3 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_locations',
              1 => 'hr_locations_shp',
            ),
            'field_base' => 
            array (
              0 => 'field_geofield',
              1 => 'field_iso3',
              2 => 'field_loc_admin_level',
              3 => 'field_local_pcode',
              4 => 'field_location',
              5 => 'field_locations',
              6 => 'field_pcode',
            ),
            'field_instance' => 
            array (
              0 => 'taxonomy_term-hr_location-description_field',
              1 => 'taxonomy_term-hr_location-field_geofield',
              2 => 'taxonomy_term-hr_location-field_iso3',
              3 => 'taxonomy_term-hr_location-field_loc_admin_level',
              4 => 'taxonomy_term-hr_location-field_local_pcode',
              5 => 'taxonomy_term-hr_location-field_pcode',
              6 => 'taxonomy_term-hr_location-name_field',
            ),
            'field_validation_rule' => 
            array (
              0 => 'hr_locations_pcode_unique',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_location',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_settings_taxonomy_term__hr_location',
            ),
            'views_view' => 
            array (
              0 => 'hr_locations',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_migrate' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_migrate/hr_migrate.module',
        'basename' => 'hr_migrate.module',
        'name' => 'hr_migrate',
        'info' => 
        array (
          'name' => 'Migrate',
          'description' => 'Migrate content from Humanitarianresponse 1.x to Humanitarianresponse 2.x',
          'package' => 'Humanitarianresponse',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'migrate',
            1 => 'migrate_d2d',
            2 => 'migrate_extras',
          ),
          'files' => 
          array (
            0 => 'hr_migrate.migrate.inc',
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_discussions' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_discussions/hr_discussions.module',
        'basename' => 'hr_discussions.module',
        'name' => 'hr_discussions',
        'info' => 
        array (
          'name' => 'Discussions',
          'description' => 'Forum like functionality for Humanitarianresponse',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'comment',
            1 => 'comment_og',
            2 => 'ctools',
            3 => 'features',
            4 => 'file',
            5 => 'hr_core',
            6 => 'hr_operations',
            7 => 'list',
            8 => 'og',
            9 => 'og_moderation',
            10 => 'og_ui',
            11 => 'options',
            12 => 'panelizer',
            13 => 'strongarm',
            14 => 'text',
            15 => 'views',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'panelizer:panelizer:1',
              1 => 'strongarm:strongarm:1',
              2 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'field_instance' => 
            array (
              0 => 'comment-comment_node_hr_discussion-field_files',
              1 => 'node-hr_discussion-body',
              2 => 'node-hr_discussion-field_files',
              3 => 'node-hr_discussion-group_content_access',
              4 => 'node-hr_discussion-og_group_ref',
            ),
            'node' => 
            array (
              0 => 'hr_discussion',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_bundle:access authoring options of hr_discussion content',
              1 => 'node:hr_bundle:access publishing options of hr_discussion content',
              2 => 'node:hr_bundle:access revisions options of hr_discussion content',
              3 => 'node:hr_bundle:approve comment_node_hr_discussion',
              4 => 'node:hr_bundle:create hr_discussion content',
              5 => 'node:hr_bundle:delete any hr_discussion content',
              6 => 'node:hr_bundle:delete comment_node_hr_discussion',
              7 => 'node:hr_bundle:delete own hr_discussion content',
              8 => 'node:hr_bundle:edit comment_node_hr_discussion',
              9 => 'node:hr_bundle:edit own comment_node_hr_discussion',
              10 => 'node:hr_bundle:post comment_node_hr_discussion',
              11 => 'node:hr_bundle:update any hr_discussion content',
              12 => 'node:hr_bundle:update own hr_discussion content',
              13 => 'node:hr_bundle:view any unpublished hr_discussion content',
              14 => 'node:hr_disaster:access authoring options of hr_discussion content',
              15 => 'node:hr_disaster:access publishing options of hr_discussion content',
              16 => 'node:hr_disaster:access revisions options of hr_discussion content',
              17 => 'node:hr_disaster:create hr_discussion content',
              18 => 'node:hr_disaster:delete any hr_discussion content',
              19 => 'node:hr_disaster:delete own hr_discussion content',
              20 => 'node:hr_disaster:update any hr_discussion content',
              21 => 'node:hr_disaster:update own hr_discussion content',
              22 => 'node:hr_disaster:view any unpublished hr_discussion content',
              23 => 'node:hr_operation:access authoring options of hr_discussion content',
              24 => 'node:hr_operation:access publishing options of hr_discussion content',
              25 => 'node:hr_operation:approve comment_node_hr_discussion',
              26 => 'node:hr_operation:create hr_discussion content',
              27 => 'node:hr_operation:delete any hr_discussion content',
              28 => 'node:hr_operation:delete comment_node_hr_discussion',
              29 => 'node:hr_operation:edit comment_node_hr_discussion',
              30 => 'node:hr_operation:edit own comment_node_hr_discussion',
              31 => 'node:hr_operation:post comment_node_hr_discussion',
              32 => 'node:hr_operation:update any hr_discussion content',
              33 => 'node:hr_operation:update own hr_discussion content',
              34 => 'node:hr_operation:view any unpublished hr_discussion content',
              35 => 'node:hr_sector:access authoring options of hr_discussion content',
              36 => 'node:hr_sector:access publishing options of hr_discussion content',
              37 => 'node:hr_sector:access revisions options of hr_discussion content',
              38 => 'node:hr_sector:approve comment_node_hr_discussion',
              39 => 'node:hr_sector:create hr_discussion content',
              40 => 'node:hr_sector:delete any hr_discussion content',
              41 => 'node:hr_sector:delete comment_node_hr_discussion',
              42 => 'node:hr_sector:delete own hr_discussion content',
              43 => 'node:hr_sector:edit comment_node_hr_discussion',
              44 => 'node:hr_sector:edit own comment_node_hr_discussion',
              45 => 'node:hr_sector:post comment_node_hr_discussion',
              46 => 'node:hr_sector:update any hr_discussion content',
              47 => 'node:hr_sector:update own hr_discussion content',
              48 => 'node:hr_sector:view any unpublished hr_discussion content',
              49 => 'node:hr_space:access authoring options of hr_discussion content',
              50 => 'node:hr_space:access publishing options of hr_discussion content',
              51 => 'node:hr_space:access revisions options of hr_discussion content',
              52 => 'node:hr_space:approve comment_node_hr_discussion',
              53 => 'node:hr_space:create hr_discussion content',
              54 => 'node:hr_space:delete any hr_discussion content',
              55 => 'node:hr_space:delete comment_node_hr_discussion',
              56 => 'node:hr_space:delete own hr_discussion content',
              57 => 'node:hr_space:edit comment_node_hr_discussion',
              58 => 'node:hr_space:edit own comment_node_hr_discussion',
              59 => 'node:hr_space:post comment_node_hr_discussion',
              60 => 'node:hr_space:update any hr_discussion content',
              61 => 'node:hr_space:update own hr_discussion content',
              62 => 'node:hr_space:view any unpublished hr_discussion content',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_discussion:default:default',
              1 => 'node:hr_discussion:default:search_result',
              2 => 'node:hr_discussion:default:teaser',
            ),
            'user_permission' => 
            array (
              0 => 'access comments',
              1 => 'edit own comments',
              2 => 'post comments',
              3 => 'skip comment approval',
            ),
            'variable' => 
            array (
              0 => 'comment_anonymous_hr_discussion',
              1 => 'comment_default_mode_hr_discussion',
              2 => 'comment_default_per_page_hr_discussion',
              3 => 'comment_form_location_hr_discussion',
              4 => 'comment_hr_discussion',
              5 => 'comment_preview_hr_discussion',
              6 => 'comment_subject_field_hr_discussion',
              7 => 'field_bundle_settings_node__hr_discussion',
              8 => 'language_content_type_hr_discussion',
              9 => 'menu_options_hr_discussion',
              10 => 'menu_parent_hr_discussion',
              11 => 'node_options_hr_discussion',
              12 => 'node_preview_hr_discussion',
              13 => 'node_submitted_hr_discussion',
              14 => 'pathauto_node_hr_discussion_pattern',
            ),
            'views_view' => 
            array (
              0 => 'hr_discussions',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_indicators' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_indicators/hr_indicators.module',
        'basename' => 'hr_indicators.module',
        'name' => 'hr_indicators',
        'info' => 
        array (
          'name' => 'Indicators',
          'description' => 'Indicator content type',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'context',
            1 => 'current_search',
            2 => 'field_validation',
            3 => 'hr_sectors',
            4 => 'page_manager',
            5 => 'panelizer',
            6 => 'radix_layouts',
            7 => 'shs',
            8 => 'text',
            9 => 'views',
            10 => 'views_content',
            11 => 'views_data_export',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'hr_indicators',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'feeds:feeds_importer_default:1',
              2 => 'feeds_tamper:feeds_tamper_default:2',
              3 => 'field_validation:default_field_validation_rules:2',
              4 => 'page_manager:pages_default:1',
              5 => 'panelizer:panelizer:1',
              6 => 'strongarm:strongarm:1',
              7 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_indicator_domains',
              1 => 'hr_indicator_standards',
              2 => 'hr_indicator_types',
              3 => 'hr_indicator_units',
              4 => 'hr_indicators',
            ),
            'feeds_tamper' => 
            array (
              0 => 'hr_indicators-sector_cross-tagging-explode',
            ),
            'field_base' => 
            array (
              0 => 'field_ind_code',
              1 => 'field_ind_comments',
              2 => 'field_ind_cross_tagging',
              3 => 'field_ind_data_sources',
              4 => 'field_ind_denominator',
              5 => 'field_ind_disaggregation',
              6 => 'field_ind_domain',
              7 => 'field_ind_general_guidance',
              8 => 'field_ind_guidance_baseline',
              9 => 'field_ind_guidance_phases',
              10 => 'field_ind_key',
              11 => 'field_ind_numerator',
              12 => 'field_ind_phase_applicability',
              13 => 'field_ind_response',
              14 => 'field_ind_standards',
              15 => 'field_ind_threshold',
              16 => 'field_ind_types',
              17 => 'field_ind_unit',
              18 => 'field_ind_unit_desc',
            ),
            'field_instance' => 
            array (
              0 => 'node-hr_indicator-body',
              1 => 'node-hr_indicator-field_ind_code',
              2 => 'node-hr_indicator-field_ind_comments',
              3 => 'node-hr_indicator-field_ind_cross_tagging',
              4 => 'node-hr_indicator-field_ind_data_sources',
              5 => 'node-hr_indicator-field_ind_denominator',
              6 => 'node-hr_indicator-field_ind_disaggregation',
              7 => 'node-hr_indicator-field_ind_domain',
              8 => 'node-hr_indicator-field_ind_general_guidance',
              9 => 'node-hr_indicator-field_ind_guidance_baseline',
              10 => 'node-hr_indicator-field_ind_guidance_phases',
              11 => 'node-hr_indicator-field_ind_key',
              12 => 'node-hr_indicator-field_ind_numerator',
              13 => 'node-hr_indicator-field_ind_phase_applicability',
              14 => 'node-hr_indicator-field_ind_response',
              15 => 'node-hr_indicator-field_ind_standards',
              16 => 'node-hr_indicator-field_ind_threshold',
              17 => 'node-hr_indicator-field_ind_types',
              18 => 'node-hr_indicator-field_ind_unit',
              19 => 'node-hr_indicator-field_ind_unit_desc',
              20 => 'node-hr_indicator-field_sectors',
              21 => 'node-hr_indicator-og_group_ref',
              22 => 'node-hr_indicator-title_field',
              23 => 'taxonomy_term-hr_indicator_domain-name_field',
              24 => 'taxonomy_term-hr_indicator_standard-name_field',
              25 => 'taxonomy_term-hr_indicator_type-name_field',
              26 => 'taxonomy_term-hr_indicator_unit-name_field',
            ),
            'field_validation_rule' => 
            array (
              0 => 'hr_indicators_code_unique',
            ),
            'node' => 
            array (
              0 => 'hr_indicator',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_indicator:default:default',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_indicator_domain',
              1 => 'hr_indicator_standard',
              2 => 'hr_indicator_type',
              3 => 'hr_indicator_unit',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_settings_node__hr_indicator',
              1 => 'field_bundle_settings_node__hr_indicator',
              2 => 'language_content_type_hr_indicator',
              3 => 'menu_options_hr_indicator',
              4 => 'menu_parent_hr_indicator',
              5 => 'node_options_hr_indicator',
              6 => 'node_preview_hr_indicator',
              7 => 'node_submitted_hr_indicator',
              8 => 'panelizer_defaults_node_hr_indicator',
              9 => 'panelizer_node:hr_indicator_allowed_layouts_default',
              10 => 'panelizer_node:hr_indicator_default',
              11 => 'pathauto_node_hr_indicator_pattern',
            ),
            'views_view' => 
            array (
              0 => 'hr_indicators',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'ctools' => 'ctools',
              'entityreference' => 'entityreference',
              'features' => 'features',
              'feeds' => 'feeds',
              'hr_core' => 'hr_core',
              'list' => 'list',
              'og' => 'og',
              'options' => 'options',
              'strongarm' => 'strongarm',
              'taxonomy' => 'taxonomy',
              'feeds_tamper' => 'feeds_tamper',
            ),
            'field_instance' => 
            array (
              'node-hr_indicator-field_sector' => 'node-hr_indicator-field_sector',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_api' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_api/hr_api.module',
        'basename' => 'hr_api.module',
        'name' => 'hr_api',
        'info' => 
        array (
          'name' => 'API',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'hr_locations',
            1 => 'hr_organizations',
            2 => 'hr_themes',
            3 => 'restful',
            4 => 'strongarm',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'strongarm:strongarm:1',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'variable' => 
            array (
              0 => 'restful_default_output_formatter',
              1 => 'restful_enable_users_resource',
              2 => 'restful_enable_user_login_resource',
            ),
          ),
          'description' => '',
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_pages' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_pages/hr_pages.module',
        'basename' => 'hr_pages.module',
        'name' => 'hr_pages',
        'info' => 
        array (
          'name' => 'Pages',
          'description' => 'Static space pages',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'entityreference',
            2 => 'entityreference_prepopulate',
            3 => 'features',
            4 => 'hr_bundles',
            5 => 'hr_core',
            6 => 'hr_operations',
            7 => 'hr_sectors',
            8 => 'hr_spaces',
            9 => 'list',
            10 => 'og',
            11 => 'og_moderation',
            12 => 'og_ui',
            13 => 'options',
            14 => 'panelizer',
            15 => 'pathauto',
            16 => 'radix_layouts',
            17 => 'strongarm',
            18 => 'text',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'panelizer:panelizer:1',
              1 => 'strongarm:strongarm:1',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'field_instance' => 
            array (
              0 => 'node-hr_page-body',
              1 => 'node-hr_page-field_bundles',
              2 => 'node-hr_page-group_content_access',
              3 => 'node-hr_page-og_group_ref',
              4 => 'node-hr_page-title_field',
            ),
            'node' => 
            array (
              0 => 'hr_page',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_bundle:access authoring options of hr_page content',
              1 => 'node:hr_bundle:access publishing options of hr_page content',
              2 => 'node:hr_bundle:access revisions options of hr_page content',
              3 => 'node:hr_bundle:administer panelizer node hr_page content',
              4 => 'node:hr_bundle:create hr_page content',
              5 => 'node:hr_bundle:delete any hr_page content',
              6 => 'node:hr_bundle:delete own hr_page content',
              7 => 'node:hr_bundle:update any hr_page content',
              8 => 'node:hr_bundle:update own hr_page content',
              9 => 'node:hr_bundle:view any unpublished hr_page content',
              10 => 'node:hr_operation:access authoring options of hr_page content',
              11 => 'node:hr_operation:access publishing options of hr_page content',
              12 => 'node:hr_operation:access revisions options of hr_page content',
              13 => 'node:hr_operation:administer panelizer node hr_page content',
              14 => 'node:hr_operation:create hr_page content',
              15 => 'node:hr_operation:delete any hr_page content',
              16 => 'node:hr_operation:delete own hr_page content',
              17 => 'node:hr_operation:update any hr_page content',
              18 => 'node:hr_operation:update own hr_page content',
              19 => 'node:hr_operation:view any unpublished hr_page content',
              20 => 'node:hr_sector:access authoring options of hr_page content',
              21 => 'node:hr_sector:access publishing options of hr_page content',
              22 => 'node:hr_sector:access revisions options of hr_page content',
              23 => 'node:hr_sector:administer panelizer node hr_page content',
              24 => 'node:hr_sector:create hr_page content',
              25 => 'node:hr_sector:delete any hr_page content',
              26 => 'node:hr_sector:delete own hr_page content',
              27 => 'node:hr_sector:update any hr_page content',
              28 => 'node:hr_sector:update own hr_page content',
              29 => 'node:hr_sector:view any unpublished hr_page content',
              30 => 'node:hr_space:access authoring options of hr_page content',
              31 => 'node:hr_space:access publishing options of hr_page content',
              32 => 'node:hr_space:access revisions options of hr_page content',
              33 => 'node:hr_space:administer panelizer node hr_page content',
              34 => 'node:hr_space:create hr_page content',
              35 => 'node:hr_space:delete any hr_page content',
              36 => 'node:hr_space:delete own hr_page content',
              37 => 'node:hr_space:update any hr_page content',
              38 => 'node:hr_space:update own hr_page content',
              39 => 'node:hr_space:view any unpublished hr_page content',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_page:default:default',
              1 => 'node:hr_page:default:search_result',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_hide_translation_links_hr_page',
              1 => 'entity_translation_node_metadata_hr_page',
              2 => 'entity_translation_settings_node__hr_page',
              3 => 'field_bundle_settings_node__hr_page',
              4 => 'language_content_type_hr_page',
              5 => 'menu_options_hr_page',
              6 => 'menu_parent_hr_page',
              7 => 'node_options_hr_page',
              8 => 'node_preview_hr_page',
              9 => 'node_submitted_hr_page',
              10 => 'panelizer_defaults_node_hr_page',
              11 => 'panelizer_node:hr_page_allowed_layouts_default',
              12 => 'panelizer_node:hr_page_allowed_types',
              13 => 'panelizer_node:hr_page_allowed_types_default',
              14 => 'panelizer_node:hr_page_default',
              15 => 'pathauto_node_hr_page_pattern',
              16 => 'publishcontent_hr_page',
            ),
          ),
          'features_exclude' => 
          array (
            'og_features_role' => 
            array (
              'node:hr_bundle:manager' => 'node:hr_bundle:manager',
              'node:hr_bundle:editor' => 'node:hr_bundle:editor',
              'node:hr_operation:manager' => 'node:hr_operation:manager',
              'node:hr_operation:editor' => 'node:hr_operation:editor',
              'node:hr_sector:manager' => 'node:hr_sector:manager',
              'node:hr_sector:editor' => 'node:hr_sector:editor',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_organizations' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_organizations/hr_organizations.module',
        'basename' => 'hr_organizations.module',
        'name' => 'hr_organizations',
        'info' => 
        array (
          'name' => 'Organizations',
          'description' => 'Organization and organization type taxonomies',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'chosen',
            1 => 'ctools',
            2 => 'entityreference',
            3 => 'features',
            4 => 'feeds',
            5 => 'hr_core',
            6 => 'link',
            7 => 'number',
            8 => 'options',
            9 => 'strongarm',
            10 => 'taxonomy',
            11 => 'text',
            12 => 'views',
            13 => 'views_data_export',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'feeds:feeds_importer_default:1',
              1 => 'strongarm:strongarm:1',
              2 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_organization_types',
              1 => 'hr_organizations',
            ),
            'field_base' => 
            array (
              0 => 'field_organization_fts',
              1 => 'field_organization_type',
              2 => 'field_organizations',
              3 => 'field_organizations_other',
            ),
            'field_instance' => 
            array (
              0 => 'taxonomy_term-hr_organization-description_field',
              1 => 'taxonomy_term-hr_organization-field_acronym',
              2 => 'taxonomy_term-hr_organization-field_organization_fts',
              3 => 'taxonomy_term-hr_organization-field_organization_type',
              4 => 'taxonomy_term-hr_organization-field_website',
              5 => 'taxonomy_term-hr_organization-name_field',
              6 => 'taxonomy_term-hr_organization_type-description_field',
              7 => 'taxonomy_term-hr_organization_type-name_field',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_organization',
              1 => 'hr_organization_type',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_settings_taxonomy_term__hr_organization',
              1 => 'entity_translation_settings_taxonomy_term__hr_organization_type',
            ),
            'views_view' => 
            array (
              0 => 'hr_organizations',
            ),
          ),
          'features_exclude' => 
          array (
            'field_base' => 
            array (
              'field_acronym' => 'field_acronym',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_bundles' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_bundles/hr_bundles.module',
        'basename' => 'hr_bundles.module',
        'name' => 'hr_bundles',
        'info' => 
        array (
          'name' => 'Bundles',
          'description' => 'Clusters, sectors and working groups',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'conditional_fields',
            1 => 'ctools',
            2 => 'email',
            3 => 'entityreference',
            4 => 'features',
            5 => 'feeds',
            6 => 'feeds_tamper',
            7 => 'field_collection',
            8 => 'hr_organizations',
            9 => 'hr_sectors',
            10 => 'link',
            11 => 'link_icons',
            12 => 'list',
            13 => 'number',
            14 => 'og',
            15 => 'og_menu',
            16 => 'og_role_delegate',
            17 => 'og_ui',
            18 => 'options',
            19 => 'page_manager',
            20 => 'panelizer',
            21 => 'radix_layouts',
            22 => 'strongarm',
            23 => 'text',
            24 => 'views',
            25 => 'views_content',
            26 => 'views_geojson',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'hr_bundles_pages',
            ),
            'conditional_fields' => 
            array (
              0 => 'node:hr_bundle',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'feeds:feeds_importer_default:1',
              2 => 'feeds_tamper:feeds_tamper_default:2',
              3 => 'openlayers:openlayers_layers:1',
              4 => 'openlayers:openlayers_maps:1',
              5 => 'page_manager:pages_default:1',
              6 => 'panelizer:panelizer:1',
              7 => 'strongarm:strongarm:1',
              8 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_bundles',
            ),
            'feeds_tamper' => 
            array (
              0 => 'hr_bundles-lead_agencies-explode',
              1 => 'hr_bundles-partners-explode',
            ),
            'field_base' => 
            array (
              0 => 'field_activation_document',
              1 => 'field_bundle_hid_access',
              2 => 'field_bundle_type',
              3 => 'field_bundles',
              4 => 'field_cluster_coordinator',
              5 => 'field_cluster_coordinator_name',
              6 => 'field_cluster_coordinators',
              7 => 'field_government_participation',
              8 => 'field_inter_cluster',
              9 => 'field_ngo_participation',
              10 => 'field_parent_cluster',
              11 => 'field_partners',
            ),
            'field_instance' => 
            array (
              0 => 'field_collection_item-field_cluster_coordinators-field_cluster_coordinator',
              1 => 'field_collection_item-field_cluster_coordinators-field_cluster_coordinator_name',
              2 => 'field_collection_item-field_cluster_coordinators-field_email',
              3 => 'node-hr_bundle-body',
              4 => 'node-hr_bundle-field_activation_document',
              5 => 'node-hr_bundle-field_bundle_hid_access',
              6 => 'node-hr_bundle-field_bundle_type',
              7 => 'node-hr_bundle-field_cluster_coordinators',
              8 => 'node-hr_bundle-field_email',
              9 => 'node-hr_bundle-field_government_participation',
              10 => 'node-hr_bundle-field_inter_cluster',
              11 => 'node-hr_bundle-field_mailchimp_api_key',
              12 => 'node-hr_bundle-field_mailchimp_list',
              13 => 'node-hr_bundle-field_ngo_participation',
              14 => 'node-hr_bundle-field_organizations',
              15 => 'node-hr_bundle-field_parent_cluster',
              16 => 'node-hr_bundle-field_partners',
              17 => 'node-hr_bundle-field_sector',
              18 => 'node-hr_bundle-field_social_media',
              19 => 'node-hr_bundle-field_website',
              20 => 'node-hr_bundle-group_access',
              21 => 'node-hr_bundle-group_group',
              22 => 'node-hr_bundle-og_group_ref',
              23 => 'node-hr_bundle-title_field',
            ),
            'node' => 
            array (
              0 => 'hr_bundle',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_bundle:add user',
              1 => 'node:hr_bundle:administer og menu',
              2 => 'node:hr_bundle:administer panelizer og_group content',
              3 => 'node:hr_bundle:approve and deny subscription',
              4 => 'node:hr_bundle:assign editor role',
              5 => 'node:hr_bundle:assign manager role',
              6 => 'node:hr_bundle:assign contributor role',
              7 => 'node:hr_bundle:create hr_contact content',
              8 => 'node:hr_bundle:delete any hr_contact content',
              9 => 'node:hr_bundle:delete own hr_contact content',
              10 => 'node:hr_bundle:manage members',
              11 => 'node:hr_bundle:update any hr_contact content',
              12 => 'node:hr_bundle:update group',
              13 => 'node:hr_bundle:update own hr_contact content',
              14 => 'node:hr_operation:create hr_bundle content',
              15 => 'node:hr_operation:delete any hr_bundle content',
              16 => 'node:hr_operation:delete own hr_bundle content',
              17 => 'node:hr_operation:update any hr_bundle content',
              18 => 'node:hr_operation:update own hr_bundle content',
              19 => 'node:hr_bundle:publish any content',
              20 => 'node:hr_bundle:unpublish any content',
            ),
            'og_features_role' => 
            array (
              0 => 'node:hr_bundle:editor',
              1 => 'node:hr_bundle:manager',
              2 => 'node:hr_bundle:contributor',
            ),
            'openlayers_layers' => 
            array (
              0 => 'hr_bundles_cccm',
              1 => 'hr_bundles_education',
              2 => 'hr_bundles_er',
              3 => 'hr_bundles_es',
              4 => 'hr_bundles_et',
              5 => 'hr_bundles_fs',
              6 => 'hr_bundles_h',
              7 => 'hr_bundles_l',
              8 => 'hr_bundles_n',
              9 => 'hr_bundles_p',
              10 => 'hr_bundles_wash',
            ),
            'page_manager_pages' => 
            array (
              0 => 'hr_bundles',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_bundle:default:default',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_hide_translation_links_hr_bundle',
              1 => 'entity_translation_node_metadata_hr_bundle',
              2 => 'entity_translation_settings_node__hr_bundle',
              3 => 'field_bundle_settings_node__hr_bundle',
              4 => 'language_content_type_hr_bundle',
              5 => 'menu_options_hr_bundle',
              6 => 'menu_parent_hr_bundle',
              7 => 'node_options_hr_bundle',
              8 => 'node_preview_hr_bundle',
              9 => 'node_submitted_hr_bundle',
              10 => 'og_context_negotiation_group_context',
              11 => 'og_context_providers_weight_group_context',
              12 => 'og_features_settings_node_hr_bundle',
              13 => 'og_menu_enable_hr_bundle',
              14 => 'og_menu_single_group__node__hr_bundle_hr_bundle',
              15 => 'og_menu_single_group_content__node__hr_bundle_hr_bundle',
              16 => 'panelizer_defaults_node_hr_bundle',
              17 => 'panelizer_node:hr_bundle_allowed_layouts_default',
              18 => 'panelizer_node:hr_bundle_allowed_types',
              19 => 'panelizer_node:hr_bundle_allowed_types_default',
              20 => 'panelizer_node:hr_bundle_default',
              21 => 'pathauto_node_hr_bundle_pattern',
            ),
            'views_view' => 
            array (
              0 => 'hr_bundles',
            ),
          ),
          'features_exclude' => 
          array (
            'field_base' => 
            array (
              'group_group' => 'group_group',
              'og_group_ref' => 'og_group_ref',
            ),
            'dependencies' => 
            array (
              'hr_bundles' => 'hr_bundles',
              'hr_operations' => 'hr_operations',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'hr_disasters' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/hr/hr_disasters/hr_disasters.module',
        'basename' => 'hr_disasters.module',
        'name' => 'hr_disasters',
        'info' => 
        array (
          'name' => 'Disasters',
          'description' => 'Provides the Disaster content type',
          'core' => '7.x',
          'package' => 'Humanitarianresponse',
          'dependencies' => 
          array (
            0 => 'context',
            1 => 'ctools',
            2 => 'current_search',
            3 => 'entity',
            4 => 'entityreference',
            5 => 'facetapi',
            6 => 'hr_operations',
            7 => 'number',
            8 => 'og_moderation',
            9 => 'og_ui',
            10 => 'taxonomy',
            11 => 'views',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'hr_disasters',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'feeds:feeds_importer_default:1',
              2 => 'panelizer:panelizer:1',
              3 => 'strongarm:strongarm:1',
              4 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'hr_glide_types',
            ),
            'field_base' => 
            array (
              0 => 'field_disaster_status',
              1 => 'field_disasters',
              2 => 'field_glide_number',
              3 => 'field_glide_type',
              4 => 'field_reliefweb_id',
            ),
            'field_instance' => 
            array (
              0 => 'node-hr_disaster-body',
              1 => 'node-hr_disaster-field_disaster_status',
              2 => 'node-hr_disaster-field_glide_number',
              3 => 'node-hr_disaster-field_glide_type',
              4 => 'node-hr_disaster-field_reliefweb_id',
              5 => 'node-hr_disaster-group_access',
              6 => 'node-hr_disaster-group_group',
              7 => 'node-hr_disaster-og_group_ref',
              8 => 'node-hr_disaster-title_field',
              9 => 'taxonomy_term-hr_glide_type-description_field',
              10 => 'taxonomy_term-hr_glide_type-field_acronym',
              11 => 'taxonomy_term-hr_glide_type-name_field',
            ),
            'node' => 
            array (
              0 => 'hr_disaster',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_disaster:administer og menu',
              1 => 'node:hr_disaster:administer panelizer og_group content',
              2 => 'node:hr_disaster:edit group features',
              3 => 'node:hr_disaster:update group',
              4 => 'node:hr_operation:access authoring options of hr_disaster content',
              5 => 'node:hr_operation:access publishing options of hr_disaster content',
              6 => 'node:hr_operation:access revisions options of hr_disaster content',
              7 => 'node:hr_operation:create hr_disaster content',
              8 => 'node:hr_operation:delete any hr_disaster content',
              9 => 'node:hr_operation:delete own hr_disaster content',
              10 => 'node:hr_operation:update any hr_disaster content',
              11 => 'node:hr_operation:update own hr_disaster content',
              12 => 'node:hr_operation:view any unpublished hr_disaster content',
            ),
            'og_features_role' => 
            array (
              0 => 'node:hr_disaster:manager',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:hr_disaster:default:default',
              1 => 'node:hr_disaster:default:search_result',
            ),
            'taxonomy' => 
            array (
              0 => 'hr_glide_type',
            ),
            'variable' => 
            array (
              0 => 'entity_translation_settings_node__hr_disaster',
              1 => 'field_bundle_settings_node__hr_disaster',
              2 => 'language_content_type_hr_disaster',
              3 => 'menu_options_hr_disaster',
              4 => 'menu_parent_hr_disaster',
              5 => 'node_options_hr_disaster',
              6 => 'node_preview_hr_disaster',
              7 => 'node_submitted_hr_disaster',
              8 => 'og_features_settings_node_hr_disaster',
              9 => 'panelizer_defaults_node_hr_disaster',
              10 => 'pathauto_node_hr_disaster_pattern',
            ),
            'views_view' => 
            array (
              0 => 'hr_disasters',
              1 => 'hr_disasters_panes',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'transliteration' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/transliteration/transliteration.module',
        'basename' => 'transliteration.module',
        'name' => 'transliteration',
        'info' => 
        array (
          'name' => 'Transliteration',
          'description' => 'Converts non-latin text to US-ASCII and sanitizes file names.',
          'core' => '7.x',
          'configure' => 'admin/config/media/file-system',
          'version' => '7.x-3.2',
          'project' => 'transliteration',
          'datestamp' => '1395079444',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7300',
        'project' => 'transliteration',
        'version' => '7.x-3.2',
      ),
      'field_validation_extras' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/field_validation/field_validation_extras/field_validation_extras.module',
        'basename' => 'field_validation_extras.module',
        'name' => 'field_validation_extras',
        'info' => 
        array (
          'name' => 'Field validation extras',
          'description' => 'Extra validators for Field validation 7.x-2.x.',
          'package' => 'Fields',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'field_validation',
          ),
          'version' => '7.x-2.4',
          'project' => 'field_validation',
          'datestamp' => '1390724605',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'field_validation',
        'version' => '7.x-2.4',
      ),
      'property_validation' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/field_validation/property_validation/property_validation.module',
        'basename' => 'property_validation.module',
        'name' => 'property_validation',
        'info' => 
        array (
          'name' => 'Property Validation',
          'description' => 'Add validation rules to properties.',
          'package' => 'Fields',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'field',
            1 => 'ctools',
            2 => 'entity',
          ),
          'files' => 
          array (
            0 => 'property_validation_validator.inc',
          ),
          'version' => '7.x-2.4',
          'project' => 'field_validation',
          'datestamp' => '1390724605',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'field_validation',
        'version' => '7.x-2.4',
      ),
      'field_validation' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/field_validation/field_validation.module',
        'basename' => 'field_validation.module',
        'name' => 'field_validation',
        'info' => 
        array (
          'name' => 'Field Validation',
          'description' => 'Add validation rules to fields.',
          'package' => 'Fields',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'field',
            1 => 'ctools',
          ),
          'files' => 
          array (
            0 => 'field_validation_validator.inc',
          ),
          'version' => '7.x-2.4',
          'project' => 'field_validation',
          'datestamp' => '1390724605',
          'php' => '5.2.4',
        ),
        'schema_version' => '7005',
        'project' => 'field_validation',
        'version' => '7.x-2.4',
      ),
      'field_validation_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/field_validation/field_validation_ui.module',
        'basename' => 'field_validation_ui.module',
        'name' => 'field_validation_ui',
        'info' => 
        array (
          'name' => 'Field Validation UI',
          'description' => 'UI for Field Validation.',
          'package' => 'Fields',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'field_validation',
            1 => 'ctools',
          ),
          'version' => '7.x-2.4',
          'project' => 'field_validation',
          'datestamp' => '1390724605',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'field_validation',
        'version' => '7.x-2.4',
      ),
      'pathauto' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/pathauto/pathauto.module',
        'basename' => 'pathauto.module',
        'name' => 'pathauto',
        'info' => 
        array (
          'name' => 'Pathauto',
          'description' => 'Provides a mechanism for modules to automatically generate aliases for the content they manage.',
          'dependencies' => 
          array (
            0 => 'path',
            1 => 'token',
          ),
          'core' => '7.x',
          'files' => 
          array (
            0 => 'pathauto.test',
          ),
          'configure' => 'admin/config/search/path/patterns',
          'recommends' => 
          array (
            0 => 'redirect',
          ),
          'version' => '7.x-1.2',
          'project' => 'pathauto',
          'datestamp' => '1344525185',
          'php' => '5.2.4',
        ),
        'schema_version' => '7005',
        'project' => 'pathauto',
        'version' => '7.x-1.2',
      ),
      'bootstrap_tour' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/bootstrap_tour/bootstrap_tour.module',
        'basename' => 'bootstrap_tour.module',
        'name' => 'bootstrap_tour',
        'info' => 
        array (
          'name' => 'Bootstrap tour',
          'description' => 'Provides Bootstrap-based tours to guide users through navigations of the site',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'jquery_update',
            1 => 'ctools',
          ),
          'version' => '7.x-1.0-beta9',
          'project' => 'bootstrap_tour',
          'datestamp' => '1407772728',
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'bootstrap_tour',
        'version' => '7.x-1.0-beta9',
      ),
      'views_content_cache' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/views_content_cache/views_content_cache.module',
        'basename' => 'views_content_cache.module',
        'name' => 'views_content_cache',
        'info' => 
        array (
          'name' => 'Views Content Cache',
          'description' => 'Provides a views cache plugin based on content type changes.',
          'package' => 'Views',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'views',
            1 => 'ctools',
          ),
          'files' => 
          array (
            0 => 'plugins/views_content_cache/base.inc',
            1 => 'plugins/views_content_cache/comment.inc',
            2 => 'plugins/views_content_cache/node.inc',
            3 => 'plugins/views_content_cache/node_only.inc',
            4 => 'plugins/views_content_cache/og.inc',
            5 => 'plugins/views_content_cache/votingapi.inc',
            6 => 'views/views_content_cache_plugin_cache.inc',
            7 => 'tests/views_content_cache.test',
          ),
          'version' => '7.x-3.0-alpha3',
          'project' => 'views_content_cache',
          'datestamp' => '1383658110',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'views_content_cache',
        'version' => '7.x-3.0-alpha3',
      ),
      'spatial_import' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/spatial_import/spatial_import.module',
        'basename' => 'spatial_import.module',
        'name' => 'spatial_import',
        'info' => 
        array (
          'name' => 'Spatial Import',
          'description' => 'Import spatial data with Table Wizard or Feeds',
          'package' => 'Geo Spatial Tools',
          'core' => '7.x',
          'dependencies' => 
          array (
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'context_og' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/context_og/context_og.module',
        'basename' => 'context_og.module',
        'name' => 'context_og',
        'info' => 
        array (
          'name' => 'Context OG',
          'description' => 'Provides Organic Groups conditions and reactions for the Context module.',
          'package' => 'Context',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'og',
            1 => 'og_context',
            2 => 'ctools',
            3 => 'context',
          ),
          'version' => '7.x-2.1',
          'project' => 'context_og',
          'datestamp' => '1355739999',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'context_og',
        'version' => '7.x-2.1',
      ),
      'migrate_d2d_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/migrate_d2d/migrate_d2d_ui/migrate_d2d_ui.module',
        'basename' => 'migrate_d2d_ui.module',
        'name' => 'migrate_d2d_ui',
        'info' => 
        array (
          'name' => 'Drupal-to-Drupal migration UI',
          'description' => 'Support for migrating external Drupal sites into the current site',
          'package' => 'Migration',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'migrate_d2d',
            1 => 'migrate_ui',
          ),
          'files' => 
          array (
            0 => 'migrate_d2d_ui.migrate.inc',
          ),
          'version' => '7.x-2.1',
          'project' => 'migrate_d2d',
          'datestamp' => '1423523588',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'migrate_d2d',
        'version' => '7.x-2.1',
      ),
      'migrate_d2d' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/migrate_d2d/migrate_d2d.module',
        'basename' => 'migrate_d2d.module',
        'name' => 'migrate_d2d',
        'info' => 
        array (
          'name' => 'Drupal-to-Drupal migration',
          'description' => 'Migration from one Drupal site to another',
          'package' => 'Migration',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'migrate (>=7.x-2.7)',
          ),
          'files' => 
          array (
            0 => 'migrate_d2d.migrate.inc',
            1 => 'block_custom.inc',
            2 => 'comment.inc',
            3 => 'entity.inc',
            4 => 'file.inc',
            5 => 'menu.inc',
            6 => 'menu_links.inc',
            7 => 'node.inc',
            8 => 'role.inc',
            9 => 'taxonomy.inc',
            10 => 'user.inc',
            11 => 'd5/d5.inc',
            12 => 'd5/block_custom.inc',
            13 => 'd5/comment.inc',
            14 => 'd5/file.inc',
            15 => 'd5/node.inc',
            16 => 'd5/role.inc',
            17 => 'd5/taxonomy.inc',
            18 => 'd5/user.inc',
            19 => 'd6/d6.inc',
            20 => 'd6/block_custom.inc',
            21 => 'd6/comment.inc',
            22 => 'd6/entity.inc',
            23 => 'd6/file.inc',
            24 => 'd6/menu.inc',
            25 => 'd6/menu_links.inc',
            26 => 'd6/node.inc',
            27 => 'd6/role.inc',
            28 => 'd6/taxonomy.inc',
            29 => 'd6/user.inc',
            30 => 'd7/d7.inc',
            31 => 'd7/comment.inc',
            32 => 'd7/file.inc',
            33 => 'd7/node.inc',
            34 => 'd7/role.inc',
            35 => 'd7/taxonomy.inc',
            36 => 'd7/user.inc',
          ),
          'version' => '7.x-2.1',
          'project' => 'migrate_d2d',
          'datestamp' => '1423523588',
          'php' => '5.2.4',
        ),
        'schema_version' => '7201',
        'project' => 'migrate_d2d',
        'version' => '7.x-2.1',
      ),
      'bean_usage' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/bean/bean_usage/bean_usage.module',
        'basename' => 'bean_usage.module',
        'name' => 'bean_usage',
        'info' => 
        array (
          'name' => 'Bean Usage',
          'description' => 'View Bean (Block Entities) Usage',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'bean',
            1 => 'blockreference',
          ),
          'package' => 'Bean',
          'version' => '7.x-1.9',
          'project' => 'bean',
          'datestamp' => '1425439382',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'bean',
        'version' => '7.x-1.9',
      ),
      'bean_admin_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/bean/bean_admin_ui/bean_admin_ui.module',
        'basename' => 'bean_admin_ui.module',
        'name' => 'bean_admin_ui',
        'info' => 
        array (
          'name' => 'Bean Admin UI',
          'description' => 'Add the ability to create Block Types in the UI',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'bean_admin_ui.module',
            1 => 'plugins/BeanCustom.class.php',
          ),
          'dependencies' => 
          array (
            0 => 'bean',
          ),
          'configure' => 'admin/structure/block-types',
          'package' => 'Bean',
          'version' => '7.x-1.9',
          'project' => 'bean',
          'datestamp' => '1425439382',
          'php' => '5.2.4',
        ),
        'schema_version' => '7003',
        'project' => 'bean',
        'version' => '7.x-1.9',
      ),
      'bean_entitycache' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/bean/bean_entitycache/bean_entitycache.module',
        'basename' => 'bean_entitycache.module',
        'name' => 'bean_entitycache',
        'info' => 
        array (
          'name' => 'Bean - Entitycache',
          'description' => 'Integrates the Bean module with the Entitycache module',
          'core' => '7.x',
          'package' => 'Performance and scalability',
          'files' => 
          array (
            0 => 'includes/bean_entitycache.core.inc',
          ),
          'dependencies' => 
          array (
            0 => 'bean',
            1 => 'entitycache',
          ),
          'version' => '7.x-1.9',
          'project' => 'bean',
          'datestamp' => '1425439382',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'bean',
        'version' => '7.x-1.9',
      ),
      'bean_uuid' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/bean/bean_uuid/bean_uuid.module',
        'basename' => 'bean_uuid.module',
        'name' => 'bean_uuid',
        'info' => 
        array (
          'name' => 'Bean UUID',
          'description' => 'Allow deploying bean blocks through Deploy and UUID modules.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'bean',
            1 => 'uuid',
          ),
          'package' => 'Bean',
          'version' => '7.x-1.9',
          'project' => 'bean',
          'datestamp' => '1425439382',
          'php' => '5.2.4',
        ),
        'schema_version' => '7201',
        'project' => 'bean',
        'version' => '7.x-1.9',
      ),
      'bean' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/bean/bean.module',
        'basename' => 'bean.module',
        'name' => 'bean',
        'info' => 
        array (
          'name' => 'Bean',
          'description' => 'Create Bean (Block Entities)',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'includes/bean.core.inc',
            1 => 'includes/bean.info.inc',
            2 => 'plugins/BeanPlugin.class.php',
            3 => 'plugins/BeanDefault.class.php',
            4 => 'includes/translation.handler.bean.inc',
            5 => 'includes/bean.inline_entity_form.inc',
            6 => 'views/views_handler_filter_bean_type.inc',
            7 => 'views/views_handler_field_bean_type.inc',
            8 => 'views/views_handler_field_bean_edit_link.inc',
            9 => 'views/views_handler_field_bean_delete_link.inc',
            10 => 'views/views_handler_field_bean_operations.inc',
            11 => 'bean.test',
          ),
          'dependencies' => 
          array (
            0 => 'entity (>=7.x-1.0)',
            1 => 'ctools',
          ),
          'package' => 'Bean',
          'version' => '7.x-1.9',
          'project' => 'bean',
          'datestamp' => '1425439382',
          'php' => '5.2.4',
        ),
        'schema_version' => '7013',
        'project' => 'bean',
        'version' => '7.x-1.9',
      ),
      'file_entity' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/file_entity/file_entity.module',
        'basename' => 'file_entity.module',
        'name' => 'file_entity',
        'info' => 
        array (
          'name' => 'File entity',
          'description' => 'Extends Drupal file entities to be fieldable and viewable.',
          'package' => 'Media',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'field',
            1 => 'file',
            2 => 'ctools',
            3 => 'system (>=7.9)',
          ),
          'files' => 
          array (
            0 => 'views/views_handler_argument_file_type.inc',
            1 => 'views/views_handler_field_file_rendered.inc',
            2 => 'views/views_handler_field_file_type.inc',
            3 => 'views/views_handler_filter_file_type.inc',
            4 => 'views/views_handler_filter_schema_type.inc',
            5 => 'views/views_handler_field_file_filename.inc',
            6 => 'views/views_handler_field_file_link.inc',
            7 => 'views/views_handler_field_file_link_edit.inc',
            8 => 'views/views_handler_field_file_link_delete.inc',
            9 => 'views/views_handler_field_file_link_download.inc',
            10 => 'views/views_handler_field_file_link_usage.inc',
            11 => 'views/views_plugin_row_file_rss.inc',
            12 => 'views/views_plugin_row_file_view.inc',
            13 => 'file_entity.test',
          ),
          'configure' => 'admin/config/media/file-settings',
          'version' => '7.x-2.0-beta1',
          'project' => 'file_entity',
          'datestamp' => '1412420930',
          'php' => '5.2.4',
        ),
        'schema_version' => '7215',
        'project' => 'file_entity',
        'version' => '7.x-2.0-beta1',
      ),
      'redirect' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/redirect/redirect.module',
        'basename' => 'redirect.module',
        'name' => 'redirect',
        'info' => 
        array (
          'name' => 'Redirect',
          'description' => 'Allows users to redirect from old URLs to new URLs.',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'redirect.module',
            1 => 'redirect.admin.inc',
            2 => 'redirect.install',
            3 => 'redirect.test',
            4 => 'views/redirect.views.inc',
            5 => 'views/redirect_handler_filter_redirect_type.inc',
            6 => 'views/redirect_handler_field_redirect_source.inc',
            7 => 'views/redirect_handler_field_redirect_redirect.inc',
            8 => 'views/redirect_handler_field_redirect_operations.inc',
            9 => 'views/redirect_handler_field_redirect_link_edit.inc',
            10 => 'views/redirect_handler_field_redirect_link_delete.inc',
          ),
          'configure' => 'admin/config/search/redirect/settings',
          'version' => '7.x-1.0-rc1',
          'project' => 'redirect',
          'datestamp' => '1347989995',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'redirect',
        'version' => '7.x-1.0-rc1',
      ),
      'search_api_sorts_widget' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/search_api_sorts_widget/search_api_sorts_widget.module',
        'basename' => 'search_api_sorts_widget.module',
        'name' => 'search_api_sorts_widget',
        'info' => 
        array (
          'name' => 'Search API Sorts Widget',
          'description' => 'Provides a form widget for the Search API Sorts module.',
          'dependencies' => 
          array (
            0 => 'block',
            1 => 'search_api_sorts',
          ),
          'core' => '7.x',
          'package' => 'Search',
          'version' => '7.x-1.x-dev',
          'project' => 'search_api_sorts_widget',
          'datestamp' => '1404146630',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'search_api_sorts_widget',
        'version' => '7.x-1.x-dev',
      ),
      'jquery_update' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/jquery_update/jquery_update.module',
        'basename' => 'jquery_update.module',
        'name' => 'jquery_update',
        'info' => 
        array (
          'name' => 'jQuery Update',
          'description' => 'Update jQuery and jQuery UI to a more recent version.',
          'package' => 'User interface',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'jquery_update.module',
            1 => 'jquery_update.install',
          ),
          'configure' => 'admin/config/development/jquery_update',
          'version' => '7.x-2.5',
          'project' => 'jquery_update',
          'datestamp' => '1422221882',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'jquery_update',
        'version' => '7.x-2.5',
      ),
      'search_api_solr' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/search_api_solr/search_api_solr.module',
        'basename' => 'search_api_solr.module',
        'name' => 'search_api_solr',
        'info' => 
        array (
          'name' => 'Solr search',
          'description' => 'Offers an implementation of the Search API that uses an Apache Solr server for indexing content.',
          'dependencies' => 
          array (
            0 => 'search_api',
          ),
          'core' => '7.x',
          'package' => 'Search',
          'files' => 
          array (
            0 => 'includes/document.inc',
            1 => 'includes/service.inc',
            2 => 'includes/solr_connection.inc',
            3 => 'includes/solr_connection.interface.inc',
            4 => 'includes/solr_field.inc',
            5 => 'includes/spellcheck.inc',
          ),
          'version' => '7.x-1.6',
          'project' => 'search_api_solr',
          'datestamp' => '1410186051',
          'php' => '5.2.4',
        ),
        'schema_version' => '7102',
        'project' => 'search_api_solr',
        'version' => '7.x-1.6',
      ),
      'link' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/link/link.module',
        'basename' => 'link.module',
        'name' => 'link',
        'info' => 
        array (
          'name' => 'Link',
          'description' => 'Defines simple link field types.',
          'core' => '7.x',
          'package' => 'Fields',
          'files' => 
          array (
            0 => 'link.module',
            1 => 'link.migrate.inc',
            2 => 'tests/link.test',
            3 => 'tests/link.attribute.test',
            4 => 'tests/link.crud.test',
            5 => 'tests/link.crud_browser.test',
            6 => 'tests/link.token.test',
            7 => 'tests/link.validate.test',
            8 => 'views/link_views_handler_argument_target.inc',
            9 => 'views/link_views_handler_filter_protocol.inc',
          ),
          'version' => '7.x-1.3',
          'project' => 'link',
          'datestamp' => '1413924830',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'link',
        'version' => '7.x-1.3',
      ),
      'restclient' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/restclient/restclient.module',
        'basename' => 'restclient.module',
        'name' => 'restclient',
        'info' => 
        array (
          'name' => 'REST Client',
          'description' => 'Enables a standard REST API to connect to RESTful services',
          'core' => '7.x',
          'package' => 'Web Services',
          'dependencies' => 
          array (
            0 => 'chr',
          ),
          'files' => 
          array (
            0 => 'restclient.test',
            1 => 'restclient.wsconnector.inc',
          ),
          'configure' => 'admin/config/services/restclient',
          'version' => '7.x-2.0-beta3',
          'project' => 'restclient',
          'datestamp' => '1399320228',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'restclient',
        'version' => '7.x-2.0-beta3',
      ),
      'i18n_translation' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_translation/i18n_translation.module',
        'basename' => 'i18n_translation.module',
        'name' => 'i18n_translation',
        'info' => 
        array (
          'name' => 'Translation sets',
          'description' => 'Simple translation sets API for generic objects',
          'dependencies' => 
          array (
            0 => 'i18n',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'i18n_translation.inc',
          ),
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_redirect' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_redirect/i18n_redirect.module',
        'basename' => 'i18n_redirect.module',
        'name' => 'i18n_redirect',
        'info' => 
        array (
          'name' => 'Translation redirect',
          'description' => 'Redirect to translated page when available. SEO for multilingual sites.',
          'dependencies' => 
          array (
            0 => 'i18n',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_node' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_node/i18n_node.module',
        'basename' => 'i18n_node.module',
        'name' => 'i18n_node',
        'info' => 
        array (
          'name' => 'Multilingual content',
          'description' => 'Extended node options for multilingual content',
          'dependencies' => 
          array (
            0 => 'translation',
            1 => 'i18n',
            2 => 'i18n_string',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'configure' => 'admin/config/regional/i18n/node',
          'files' => 
          array (
            0 => 'i18n_node.test',
            1 => 'i18n_node.variable.inc',
          ),
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_user' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_user/i18n_user.module',
        'basename' => 'i18n_user.module',
        'name' => 'i18n_user',
        'info' => 
        array (
          'name' => 'User mail translation',
          'description' => 'Translate emails sent from the User module.',
          'core' => '7.x',
          'package' => 'Multilingual - Internationalization',
          'dependencies' => 
          array (
            0 => 'i18n_variable',
          ),
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_sync' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_sync/i18n_sync.module',
        'basename' => 'i18n_sync.module',
        'name' => 'i18n_sync',
        'info' => 
        array (
          'name' => 'Synchronize translations',
          'description' => 'Synchronizes taxonomy and fields accross translations of the same content.',
          'dependencies' => 
          array (
            0 => 'i18n',
            1 => 'translation',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'i18n_sync.module',
            1 => 'i18n_sync.install',
            2 => 'i18n_sync.module.inc',
            3 => 'i18n_sync.node.inc',
            4 => 'i18n_sync.test',
          ),
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_string' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_string/i18n_string.module',
        'basename' => 'i18n_string.module',
        'name' => 'i18n_string',
        'info' => 
        array (
          'name' => 'String translation',
          'description' => 'Provides support for translation of user defined strings.',
          'dependencies' => 
          array (
            0 => 'locale',
            1 => 'i18n',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'i18n_string.admin.inc',
            1 => 'i18n_string.inc',
            2 => 'i18n_string.test',
          ),
          'configure' => 'admin/config/regional/i18n/strings',
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => '7002',
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_block' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_block/i18n_block.module',
        'basename' => 'i18n_block.module',
        'name' => 'i18n_block',
        'info' => 
        array (
          'name' => 'Block languages',
          'description' => 'Enables language selector for blocks and optional block translation.',
          'dependencies' => 
          array (
            0 => 'block',
            1 => 'i18n_string',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'i18n_block.inc',
            1 => 'i18n_block.test',
          ),
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_variable' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_variable/i18n_variable.module',
        'basename' => 'i18n_variable.module',
        'name' => 'i18n_variable',
        'info' => 
        array (
          'name' => 'Variable translation',
          'description' => 'Multilingual variables that switch language depending on page language.',
          'dependencies' => 
          array (
            0 => 'i18n',
            1 => 'variable_store (7.x-2.x)',
            2 => 'variable_realm (7.x-2.x)',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'configure' => 'admin/config/regional/i18n/variable',
          'files' => 
          array (
            0 => 'i18n_variable.class.inc',
            1 => 'i18n_variable.test',
          ),
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => '7004',
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_taxonomy' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_taxonomy/i18n_taxonomy.module',
        'basename' => 'i18n_taxonomy.module',
        'name' => 'i18n_taxonomy',
        'info' => 
        array (
          'name' => 'Taxonomy translation',
          'description' => 'Enables multilingual taxonomy.',
          'dependencies' => 
          array (
            0 => 'taxonomy',
            1 => 'i18n_string',
            2 => 'i18n_translation',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'i18n_taxonomy.inc',
            1 => 'i18n_taxonomy.pages.inc',
            2 => 'i18n_taxonomy.admin.inc',
            3 => 'i18n_taxonomy.test',
          ),
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => '7004',
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_menu' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_menu/i18n_menu.module',
        'basename' => 'i18n_menu.module',
        'name' => 'i18n_menu',
        'info' => 
        array (
          'name' => 'Menu translation',
          'description' => 'Supports translatable custom menu items.',
          'dependencies' => 
          array (
            0 => 'i18n',
            1 => 'menu',
            2 => 'i18n_string',
            3 => 'i18n_translation',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'i18n_menu.inc',
            1 => 'i18n_menu.test',
          ),
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_select' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_select/i18n_select.module',
        'basename' => 'i18n_select.module',
        'name' => 'i18n_select',
        'info' => 
        array (
          'name' => 'Multilingual select',
          'description' => 'API module for multilingual content selection',
          'dependencies' => 
          array (
            0 => 'i18n',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'configure' => 'admin/config/regional/i18n/select',
          'files' => 
          array (
            0 => 'i18n_select.test',
          ),
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_contact' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_contact/i18n_contact.module',
        'basename' => 'i18n_contact.module',
        'name' => 'i18n_contact',
        'info' => 
        array (
          'name' => 'Contact translation',
          'description' => 'Makes contact categories and replies available for translation.',
          'dependencies' => 
          array (
            0 => 'contact',
            1 => 'i18n_string',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_field' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_field/i18n_field.module',
        'basename' => 'i18n_field.module',
        'name' => 'i18n_field',
        'info' => 
        array (
          'name' => 'Field translation',
          'description' => 'Translate field properties',
          'dependencies' => 
          array (
            0 => 'field',
            1 => 'i18n_string',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'i18n_field.inc',
            1 => 'i18n_field.test',
          ),
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_forum' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_forum/i18n_forum.module',
        'basename' => 'i18n_forum.module',
        'name' => 'i18n_forum',
        'info' => 
        array (
          'name' => 'Multilingual forum',
          'description' => 'Enables multilingual forum, translates names and containers.',
          'dependencies' => 
          array (
            0 => 'forum',
            1 => 'i18n_taxonomy',
            2 => 'i18n_node',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'i18n_forum.test',
          ),
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n_path' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n_path/i18n_path.module',
        'basename' => 'i18n_path.module',
        'name' => 'i18n_path',
        'info' => 
        array (
          'name' => 'Path translation',
          'description' => 'Define translations for generic paths',
          'dependencies' => 
          array (
            0 => 'i18n_translation',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'i18n_path.inc',
            1 => 'i18n_path.test',
          ),
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'i18n' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/i18n/i18n.module',
        'basename' => 'i18n.module',
        'name' => 'i18n',
        'info' => 
        array (
          'name' => 'Internationalization',
          'description' => 'Extends Drupal support for multilingual features.',
          'dependencies' => 
          array (
            0 => 'locale',
            1 => 'variable',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'i18n_object.inc',
            1 => 'i18n.test',
          ),
          'configure' => 'admin/config/regional/i18n',
          'version' => '7.x-1.12',
          'project' => 'i18n',
          'datestamp' => '1422286982',
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'i18n',
        'version' => '7.x-1.12',
      ),
      'search_api_sorts' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/search_api_sorts/search_api_sorts.module',
        'basename' => 'search_api_sorts.module',
        'name' => 'search_api_sorts',
        'info' => 
        array (
          'name' => 'Search sorts',
          'description' => 'Create sort options for search queries executed via the Search API.',
          'dependencies' => 
          array (
            0 => 'search_api',
            1 => 'block',
          ),
          'core' => '7.x',
          'package' => 'Search',
          'files' => 
          array (
            0 => 'search_api_sorts.entity.inc',
          ),
          'version' => '7.x-1.5',
          'project' => 'search_api_sorts',
          'datestamp' => '1392554916',
          'php' => '5.2.4',
        ),
        'schema_version' => '7205',
        'project' => 'search_api_sorts',
        'version' => '7.x-1.5',
      ),
      'token_tweaks' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/token_tweaks/token_tweaks.module',
        'basename' => 'token_tweaks.module',
        'name' => 'token_tweaks',
        'info' => 
        array (
          'name' => 'Token tweaks',
          'description' => 'Allows administrators to disable token types or tokens to improve performance using the token tree.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'token',
          ),
          'configure' => 'admin/config/system/tokens',
          'version' => '7.x-1.x-dev',
          'project' => 'token_tweaks',
          'datestamp' => '1390855428',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'token_tweaks',
        'version' => '7.x-1.x-dev',
      ),
      'fts_visualization' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/fts/fts_visualization.module',
        'basename' => 'fts_visualization.module',
        'name' => 'fts_visualization',
        'info' => 
        array (
          'name' => 'FTS Visualization',
          'description' => 'Integrates the FTS API with the Visualization module.',
          'core' => '7.x',
          'package' => 'FTS',
          'dependencies' => 
          array (
            0 => 'fts',
            1 => 'visualization',
            2 => 'bean',
          ),
          'version' => '7.x-1.2',
          'project' => 'fts',
          'datestamp' => '1423734324',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'fts',
        'version' => '7.x-1.2',
      ),
      'fts_highcharts' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/fts/fts_highcharts.module',
        'basename' => 'fts_highcharts.module',
        'name' => 'fts_highcharts',
        'info' => 
        array (
          'name' => 'FTS Highcharts (Deprecated)',
          'description' => 'Integrates the FTS API with the Highcharts library.',
          'core' => '7.x',
          'package' => 'FTS',
          'dependencies' => 
          array (
            0 => 'fts',
            1 => 'highcharts',
            2 => 'bean',
          ),
          'version' => '7.x-1.2',
          'project' => 'fts',
          'datestamp' => '1423734324',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'fts',
        'version' => '7.x-1.2',
      ),
      'fts' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/fts/fts.module',
        'basename' => 'fts.module',
        'name' => 'fts',
        'info' => 
        array (
          'name' => 'FTS API',
          'description' => 'Provides an API that can be used to make calls to the Financial Tracking Service system.',
          'core' => '7.x',
          'package' => 'FTS',
          'files' => 
          array (
            0 => 'tests/fts.test',
          ),
          'version' => '7.x-1.2',
          'project' => 'fts',
          'datestamp' => '1423734324',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'fts',
        'version' => '7.x-1.2',
      ),
      'special_menu_items' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/special_menu_items/special_menu_items.module',
        'basename' => 'special_menu_items.module',
        'name' => 'special_menu_items',
        'info' => 
        array (
          'name' => 'Special menu items',
          'description' => 'Allow users to add placeholder and/or separator menu items.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'menu',
          ),
          'configure' => 'admin/config/system/special_menu_items',
          'version' => '7.x-2.0',
          'project' => 'special_menu_items',
          'datestamp' => '1346788411',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'special_menu_items',
        'version' => '7.x-2.0',
      ),
      'panels_bootstrap_styles' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/panels_bootstrap_styles/panels_bootstrap_styles.module',
        'basename' => 'panels_bootstrap_styles.module',
        'name' => 'panels_bootstrap_styles',
        'info' => 
        array (
          'name' => 'Panels Bootstrap Styles',
          'description' => 'Pane & region styles for panels module using the Twitter Bootstrap css framework.',
          'package' => 'Panels',
          'dependencies' => 
          array (
            0 => 'panels',
          ),
          'core' => '7.x',
          'version' => '7.x-1.0-alpha1',
          'project' => 'panels_bootstrap_styles',
          'datestamp' => '1384640194',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'panels_bootstrap_styles',
        'version' => '7.x-1.0-alpha1',
      ),
      'twitter_pane' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/twitter_pane/twitter_pane.module',
        'basename' => 'twitter_pane.module',
        'name' => 'twitter_pane',
        'info' => 
        array (
          'name' => 'Twitter Pane',
          'description' => 'Provides a configurable pane for a Twitter widget feed.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'panels',
          ),
          'version' => '7.x-1.x-dev',
          'project' => 'twitter_pane',
          'datestamp' => '1429267897',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'twitter_pane',
        'version' => '7.x-1.x-dev',
      ),
      'email_registration' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/email_registration/email_registration.module',
        'basename' => 'email_registration.module',
        'name' => 'email_registration',
        'info' => 
        array (
          'name' => 'Email Registration',
          'description' => 'Allows users to register with an e-mail address as their username.',
          'files' => 
          array (
            0 => 'email_registration.test',
          ),
          'core' => '7.x',
          'version' => '7.x-1.2',
          'project' => 'email_registration',
          'datestamp' => '1398265775',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'email_registration',
        'version' => '7.x-1.2',
      ),
      'webform' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/webform/webform.module',
        'basename' => 'webform.module',
        'name' => 'webform',
        'info' => 
        array (
          'name' => 'Webform',
          'description' => 'Enables the creation of forms and questionnaires.',
          'core' => '7.x',
          'package' => 'Webform',
          'configure' => 'admin/config/content/webform',
          'php' => '5.3',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'views',
          ),
          'test_dependencies' => 
          array (
            0 => 'token',
          ),
          'files' => 
          array (
            0 => 'includes/webform.webformconditionals.inc',
            1 => 'includes/exporters/webform_exporter_delimited.inc',
            2 => 'includes/exporters/webform_exporter_excel_delimited.inc',
            3 => 'includes/exporters/webform_exporter_excel_xlsx.inc',
            4 => 'includes/exporters/webform_exporter.inc',
            5 => 'views/webform_handler_field_form_body.inc',
            6 => 'views/webform_handler_field_is_draft.inc',
            7 => 'views/webform_handler_field_node_link_edit.inc',
            8 => 'views/webform_handler_field_node_link_results.inc',
            9 => 'views/webform_handler_field_submission_count.inc',
            10 => 'views/webform_handler_field_submission_data.inc',
            11 => 'views/webform_handler_field_submission_link.inc',
            12 => 'views/webform_handler_field_webform_status.inc',
            13 => 'views/webform_handler_filter_is_draft.inc',
            14 => 'views/webform_handler_filter_submission_data.inc',
            15 => 'views/webform_handler_filter_webform_status.inc',
            16 => 'views/webform_handler_area_result_pager.inc',
            17 => 'views/webform_plugin_row_submission_view.inc',
            18 => 'views/webform_handler_relationship_submission_data.inc',
            19 => 'views/webform.views.inc',
            20 => 'tests/components.test',
            21 => 'tests/conditionals.test',
            22 => 'tests/permissions.test',
            23 => 'tests/submission.test',
            24 => 'tests/webform.test',
          ),
          'version' => '7.x-4.7',
          'project' => 'webform',
          'datestamp' => '1427387585',
        ),
        'schema_version' => '7422',
        'project' => 'webform',
        'version' => '7.x-4.7',
      ),
      'taxonomy_manager' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/taxonomy_manager/taxonomy_manager.module',
        'basename' => 'taxonomy_manager.module',
        'name' => 'taxonomy_manager',
        'info' => 
        array (
          'name' => 'Taxonomy Manager',
          'description' => 'Tool for administrating taxonomy terms.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'taxonomy',
          ),
          'files' => 
          array (
            0 => 'taxonomy_manager.admin.inc',
          ),
          'configure' => 'admin/config/user-interface/taxonomy-manager-settings',
          'package' => 'Taxonomy',
          'version' => '7.x-1.0',
          'project' => 'taxonomy_manager',
          'datestamp' => '1369041918',
          'php' => '5.2.4',
        ),
        'schema_version' => '7002',
        'project' => 'taxonomy_manager',
        'version' => '7.x-1.0',
      ),
      'oauth2_common' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/oauthconnector/modules/oauth2/oauth2_common.module',
        'basename' => 'oauth2_common.module',
        'name' => 'oauth2_common',
        'info' => 
        array (
          'name' => 'OAuth2',
          'description' => 'Extends OAuth functionality with Oauth2',
          'package' => 'OAuth',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'lib/DrupalOAuth2Client.inc',
          ),
          'version' => '7.x-1.0-beta2',
          'project' => 'oauthconnector',
          'datestamp' => '1369926362',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'oauthconnector',
        'version' => '7.x-1.0-beta2',
      ),
      'oauthconnector' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/oauthconnector/oauthconnector.module',
        'basename' => 'oauthconnector.module',
        'name' => 'oauthconnector',
        'info' => 
        array (
          'name' => 'OAuth Connector',
          'description' => 'OAuth support for the Connector module',
          'core' => '7.x',
          'package' => 'Connector',
          'dependencies' => 
          array (
            0 => 'connector',
            1 => 'oauth_common',
            2 => 'oauth2_common',
            3 => 'http_client',
            4 => 'http_client_oauth',
            5 => 'ctools',
          ),
          'version' => '7.x-1.0-beta2',
          'project' => 'oauthconnector',
          'datestamp' => '1369926362',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'oauthconnector',
        'version' => '7.x-1.0-beta2',
      ),
      'piwik' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/piwik/piwik.module',
        'basename' => 'piwik.module',
        'name' => 'piwik',
        'info' => 
        array (
          'name' => 'Piwik Web Analytics',
          'description' => 'Adds Piwik javascript tracking code to all your site\'s pages.',
          'core' => '7.x',
          'package' => 'Statistics',
          'configure' => 'admin/config/system/piwik',
          'files' => 
          array (
            0 => 'piwik.test',
          ),
          'test_dependencies' => 
          array (
            0 => 'token',
          ),
          'version' => '7.x-2.7',
          'project' => 'piwik',
          'datestamp' => '1417276085',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7205',
        'project' => 'piwik',
        'version' => '7.x-2.7',
      ),
      'multisite_redirect' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/multisite_redirect/multisite_redirect.module',
        'basename' => 'multisite_redirect.module',
        'name' => 'multisite_redirect',
        'info' => 
        array (
          'name' => 'Multisite Redirect',
          'description' => 'Provides the system for creating URL redirect rules across multiple domains in a multisite install.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'redirect',
          ),
          'configure' => 'admin/config/search/multisite-redirect',
          'version' => '7.x-1.0',
          'project' => 'multisite_redirect',
          'datestamp' => '1422548582',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'multisite_redirect',
        'version' => '7.x-1.0',
      ),
      'panelizer' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/panelizer/panelizer.module',
        'basename' => 'panelizer.module',
        'name' => 'panelizer',
        'info' => 
        array (
          'name' => 'Panelizer',
          'description' => 'Allow any node type to have custom panel displays, similar to the panel node type.',
          'package' => 'Panels',
          'dependencies' => 
          array (
            0 => 'panels',
            1 => 'ctools',
            2 => 'page_manager',
          ),
          'core' => '7.x',
          'configure' => 'admin/config/content/panelizer',
          'files' => 
          array (
            0 => 'plugins/views/panelizer_handler_field_link.inc',
            1 => 'plugins/views/panelizer_handler_panelizer_status.inc',
            2 => 'plugins/views/panelizer_handler_filter_panelizer_status.inc',
            3 => 'plugins/views/panelizer_plugin_row_panelizer_node_view.inc',
          ),
          'version' => '7.x-3.1',
          'project' => 'panelizer',
          'datestamp' => '1360785942',
          'php' => '5.2.4',
        ),
        'schema_version' => '7110',
        'project' => 'panelizer',
        'version' => '7.x-3.1',
      ),
      'diff' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/diff/diff.module',
        'basename' => 'diff.module',
        'name' => 'diff',
        'info' => 
        array (
          'name' => 'Diff',
          'description' => 'Show differences between content revisions.',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'DiffEngine.php',
          ),
          'version' => '7.x-3.2',
          'project' => 'diff',
          'datestamp' => '1352784357',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7305',
        'project' => 'diff',
        'version' => '7.x-3.2',
      ),
      'views_data_export' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/views_data_export/views_data_export.module',
        'basename' => 'views_data_export.module',
        'name' => 'views_data_export',
        'info' => 
        array (
          'name' => 'Views Data Export',
          'description' => 'Plugin to export views data into various file formats',
          'package' => 'Views',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'views',
          ),
          'files' => 
          array (
            0 => 'plugins/views_data_export_plugin_display_export.inc',
            1 => 'plugins/views_data_export_plugin_style_export.inc',
            2 => 'plugins/views_data_export_plugin_style_export_csv.inc',
            3 => 'plugins/views_data_export_plugin_style_export_xml.inc',
            4 => 'tests/base.test',
            5 => 'tests/csv_export.test',
            6 => 'tests/doc_export.test',
            7 => 'tests/txt_export.test',
            8 => 'tests/xls_export.test',
            9 => 'tests/xml_export.test',
          ),
          'version' => '7.x-3.0-beta8',
          'project' => 'views_data_export',
          'datestamp' => '1409118835',
          'php' => '5.2.4',
        ),
        'schema_version' => '7301',
        'project' => 'views_data_export',
        'version' => '7.x-3.0-beta8',
      ),
      'token_filter' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/token_filter/token_filter.module',
        'basename' => 'token_filter.module',
        'name' => 'token_filter',
        'info' => 
        array (
          'name' => 'Token Filter',
          'description' => 'Allows token values to be used as filters',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'token',
          ),
          'version' => '7.x-1.1',
          'project' => 'token_filter',
          'datestamp' => '1325700944',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'token_filter',
        'version' => '7.x-1.1',
      ),
      'inline_entity_form' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/inline_entity_form/inline_entity_form.module',
        'basename' => 'inline_entity_form.module',
        'name' => 'inline_entity_form',
        'info' => 
        array (
          'name' => 'Inline Entity Form',
          'description' => 'Provides a widget for inline management (creation, modification, removal) of referenced entities. ',
          'package' => 'Fields',
          'dependencies' => 
          array (
            0 => 'entity',
            1 => 'system (>7.14)',
          ),
          'core' => '7.x',
          'files' => 
          array (
            0 => 'includes/entity.inline_entity_form.inc',
            1 => 'includes/node.inline_entity_form.inc',
            2 => 'includes/taxonomy_term.inline_entity_form.inc',
            3 => 'includes/commerce_product.inline_entity_form.inc',
            4 => 'includes/commerce_line_item.inline_entity_form.inc',
          ),
          'version' => '7.x-1.5',
          'project' => 'inline_entity_form',
          'datestamp' => '1389971831',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'inline_entity_form',
        'version' => '7.x-1.5',
      ),
      'imagemagick_advanced' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/imagemagick/imagemagick_advanced/imagemagick_advanced.module',
        'basename' => 'imagemagick_advanced.module',
        'name' => 'imagemagick_advanced',
        'info' => 
        array (
          'name' => 'ImageMagick Advanced',
          'description' => 'Provides advanced ImageMagick effects and options.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'imagemagick',
          ),
          'version' => '7.x-1.0',
          'project' => 'imagemagick',
          'datestamp' => '1362244511',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'imagemagick',
        'version' => '7.x-1.0',
      ),
      'imagemagick' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/imagemagick/imagemagick.module',
        'basename' => 'imagemagick.module',
        'name' => 'imagemagick',
        'info' => 
        array (
          'name' => 'ImageMagick',
          'description' => 'Provides ImageMagick integration.',
          'core' => '7.x',
          'configure' => 'admin/config/media/image-toolkit',
          'version' => '7.x-1.0',
          'project' => 'imagemagick',
          'datestamp' => '1362244511',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'imagemagick',
        'version' => '7.x-1.0',
      ),
      'date_ical' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/date_ical/date_ical.module',
        'basename' => 'date_ical.module',
        'name' => 'date_ical',
        'info' => 
        array (
          'name' => 'Date iCal',
          'description' => 'Enables export of iCal feeds using Views, and import of iCal feeds using Feeds.',
          'package' => 'Date/Time',
          'php' => '5.3',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'views (>=7.x-3.5)',
            1 => 'date_views',
            2 => 'entity',
            3 => 'libraries (>=7.x-2.0)',
            4 => 'date',
            5 => 'date_api',
          ),
          'files' => 
          array (
            0 => 'includes/date_ical_plugin_row_ical_entity.inc',
            1 => 'includes/date_ical_plugin_row_ical_fields.inc',
            2 => 'includes/date_ical_plugin_style_ical_feed.inc',
            3 => 'includes/DateiCalFeedsParser.inc',
          ),
          'version' => '7.x-3.3',
          'project' => 'date_ical',
          'datestamp' => '1412727230',
        ),
        'schema_version' => '7300',
        'project' => 'date_ical',
        'version' => '7.x-3.3',
      ),
      'email' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/email/email.module',
        'basename' => 'email.module',
        'name' => 'email',
        'info' => 
        array (
          'name' => 'Email',
          'description' => 'Defines an email field type.',
          'core' => '7.x',
          'package' => 'Fields',
          'files' => 
          array (
            0 => 'email.migrate.inc',
          ),
          'version' => '7.x-1.3',
          'project' => 'email',
          'datestamp' => '1397134155',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'email',
        'version' => '7.x-1.3',
      ),
      'current_search' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/facetapi/contrib/current_search/current_search.module',
        'basename' => 'current_search.module',
        'name' => 'current_search',
        'info' => 
        array (
          'name' => 'Current Search Blocks',
          'description' => 'Provides an interface for creating blocks containing information about the current search.',
          'dependencies' => 
          array (
            0 => 'facetapi',
          ),
          'package' => 'Search Toolkit',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'plugins/current_search/item.inc',
            1 => 'plugins/current_search/item_active.inc',
            2 => 'plugins/current_search/item_group.inc',
            3 => 'plugins/current_search/item_text.inc',
            4 => 'tests/current_search.test',
          ),
          'configure' => 'admin/config/search/current_search',
          'version' => '7.x-1.5',
          'project' => 'facetapi',
          'datestamp' => '1405685332',
          'php' => '5.2.4',
        ),
        'schema_version' => '7101',
        'project' => 'facetapi',
        'version' => '7.x-1.5',
      ),
      'facetapi' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/facetapi/facetapi.module',
        'basename' => 'facetapi.module',
        'name' => 'facetapi',
        'info' => 
        array (
          'name' => 'Facet API',
          'description' => 'An abstracted facet API that can be used by various search backends.',
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          'package' => 'Search Toolkit',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'plugins/facetapi/adapter.inc',
            1 => 'plugins/facetapi/dependency.inc',
            2 => 'plugins/facetapi/dependency_bundle.inc',
            3 => 'plugins/facetapi/dependency_role.inc',
            4 => 'plugins/facetapi/empty_behavior.inc',
            5 => 'plugins/facetapi/empty_behavior_text.inc',
            6 => 'plugins/facetapi/filter.inc',
            7 => 'plugins/facetapi/query_type.inc',
            8 => 'plugins/facetapi/url_processor.inc',
            9 => 'plugins/facetapi/url_processor_standard.inc',
            10 => 'plugins/facetapi/widget.inc',
            11 => 'plugins/facetapi/widget_links.inc',
            12 => 'tests/facetapi_test.plugins.inc',
            13 => 'tests/facetapi.test',
          ),
          'version' => '7.x-1.5',
          'project' => 'facetapi',
          'datestamp' => '1405685332',
          'php' => '5.2.4',
        ),
        'schema_version' => '7103',
        'project' => 'facetapi',
        'version' => '7.x-1.5',
      ),
      'cors' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/cors/cors.module',
        'basename' => 'cors.module',
        'name' => 'cors',
        'info' => 
        array (
          'name' => 'CORS',
          'description' => 'Allows Cross-origin resource sharing.',
          'package' => 'Other',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'cors.module',
          ),
          'configure' => 'admin/config/services/cors',
          'version' => '7.x-1.3',
          'project' => 'cors',
          'datestamp' => '1395477558',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'cors',
        'version' => '7.x-1.3',
      ),
      'realname' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/realname/realname.module',
        'basename' => 'realname.module',
        'name' => 'realname',
        'info' => 
        array (
          'name' => 'Real name',
          'description' => 'Provides token-based name displays for users.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'token',
          ),
          'files' => 
          array (
            0 => 'realname.module',
            1 => 'realname.admin.inc',
            2 => 'realname.pages.inc',
            3 => 'realname.tokens.inc',
            4 => 'realname.test',
            5 => 'realname.install',
          ),
          'configure' => 'admin/config/people/realname',
          'version' => '7.x-1.2',
          'project' => 'realname',
          'datestamp' => '1393160306',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'realname',
        'version' => '7.x-1.2',
      ),
      'rest_server' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/services/servers/rest_server/rest_server.module',
        'basename' => 'rest_server.module',
        'name' => 'rest_server',
        'info' => 
        array (
          'name' => 'REST Server',
          'description' => 'Provides an REST server.',
          'package' => 'Services - servers',
          'files' => 
          array (
            0 => 'rest_server.module',
            1 => 'includes/RESTServer.inc',
            2 => 'includes/ServicesContentTypeNegotiator.inc',
            3 => 'includes/ServicesRESTServerFactory.inc',
            4 => 'includes/ServicesContext.inc',
            5 => 'includes/ServicesParser.inc',
            6 => 'includes/ServicesFormatter.inc',
            7 => 'tests/ServicesRESTServerTests.test',
            8 => 'tests/rest_server_mock_classes.inc',
            9 => 'lib/bencode.php',
            10 => 'lib/mimeparse.php',
          ),
          'dependencies' => 
          array (
            0 => 'services',
            1 => 'libraries (>=2.x)',
          ),
          'core' => '7.x',
          'version' => '7.x-3.12',
          'project' => 'services',
          'datestamp' => '1429118524',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'services',
        'version' => '7.x-3.12',
      ),
      'xmlrpc_server' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/services/servers/xmlrpc_server/xmlrpc_server.module',
        'basename' => 'xmlrpc_server.module',
        'name' => 'xmlrpc_server',
        'info' => 
        array (
          'name' => 'XMLRPC Server',
          'description' => 'Provides a XMLRPC server.',
          'package' => 'Services - servers',
          'files' => 
          array (
            0 => 'xmlrpc_server.module',
          ),
          'dependencies' => 
          array (
            0 => 'services',
          ),
          'core' => '7.x',
          'version' => '7.x-3.12',
          'project' => 'services',
          'datestamp' => '1429118524',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'services',
        'version' => '7.x-3.12',
      ),
      'services_oauth' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/services/auth/services_oauth/services_oauth.module',
        'basename' => 'services_oauth.module',
        'name' => 'services_oauth',
        'info' => 
        array (
          'name' => 'OAuth Authentication',
          'description' => 'Provides OAuth authentication for the services module',
          'package' => 'Services - authentication',
          'dependencies' => 
          array (
            0 => 'services',
            1 => 'oauth_common',
          ),
          'core' => '7.x',
          'php' => '5.2',
          'version' => '7.x-3.12',
          'project' => 'services',
          'datestamp' => '1429118524',
        ),
        'schema_version' => '6200',
        'project' => 'services',
        'version' => '7.x-3.12',
      ),
      'services' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/services/services.module',
        'basename' => 'services.module',
        'name' => 'services',
        'info' => 
        array (
          'name' => 'Services',
          'description' => 'Provide an API for creating web services.',
          'package' => 'Services',
          'core' => '7.x',
          'php' => '5.x',
          'configure' => 'admin/structure/services',
          'files' => 
          array (
            0 => 'includes/services.runtime.inc',
            1 => 'tests/functional/NoAuthEndpointTestRunner.test',
            2 => 'tests/functional/ServicesResourceNodeTests.test',
            3 => 'tests/functional/ServicesResourceUserTests.test',
            4 => 'tests/functional/ServicesResourceSystemTests.test',
            5 => 'tests/functional/ServicesResourceCommentTests.test',
            6 => 'tests/functional/ServicesResourceTaxonomyTests.test',
            7 => 'tests/functional/ServicesResourceFileTests.test',
            8 => 'tests/functional/ServicesResourceDisabledTests.test',
            9 => 'tests/functional/ServicesEndpointTests.test',
            10 => 'tests/functional/ServicesParserTests.test',
            11 => 'tests/functional/ServicesAliasTests.test',
            12 => 'tests/functional/ServicesXMLRPCTests.test',
            13 => 'tests/functional/ServicesVersionTests.test',
            14 => 'tests/functional/ServicesArgumentsTests.test',
            15 => 'tests/functional/ServicesSecurityTests.test',
            16 => 'tests/unit/ServicesSpycLibraryTests.test',
            17 => 'tests/ui/ServicesUITests.test',
            18 => 'tests/services.test',
          ),
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          'version' => '7.x-3.12',
          'project' => 'services',
          'datestamp' => '1429118524',
        ),
        'schema_version' => '7402',
        'project' => 'services',
        'version' => '7.x-3.12',
      ),
      'pdfpreview' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/pdfpreview/pdfpreview.module',
        'basename' => 'pdfpreview.module',
        'name' => 'pdfpreview',
        'info' => 
        array (
          'name' => 'PDF Preview',
          'description' => 'Show a snapshot of the first page of pdf files attached to nodes.',
          'package' => 'Media',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'imagemagick',
            1 => 'image',
          ),
          'version' => '7.x-2.1+19-dev',
          'project' => 'pdfpreview',
          'datestamp' => '1428001083',
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'pdfpreview',
        'version' => '7.x-2.1+19-dev',
      ),
      'geofield_map' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/geofield/modules/geofield_map/geofield_map.module',
        'basename' => 'geofield_map.module',
        'name' => 'geofield_map',
        'info' => 
        array (
          'name' => 'Geofield Map',
          'description' => 'Provides a basic mapping interface for Geofields.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'geofield',
          ),
          'files' => 
          array (
            0 => 'includes/geofield_map.views.inc',
            1 => 'includes/geofield_map_plugin_style_map.inc',
          ),
          'version' => '7.x-2.3',
          'project' => 'geofield',
          'datestamp' => '1411337638',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'geofield',
        'version' => '7.x-2.3',
      ),
      'geofield' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/geofield/geofield.module',
        'basename' => 'geofield.module',
        'name' => 'geofield',
        'info' => 
        array (
          'name' => 'Geofield',
          'description' => 'Stores geographic and location data (points, lines, and polygons).',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'geophp (>=1.7)',
            1 => 'ctools',
          ),
          'package' => 'Fields',
          'files' => 
          array (
            0 => 'geofield.module',
            1 => 'geofield.install',
            2 => 'geofield.elements.inc',
            3 => 'geofield.widgets.inc',
            4 => 'geofield.formatters.inc',
            5 => 'geofield.openlayers.inc',
            6 => 'geofield.feeds.inc',
            7 => 'tests/geofield.test',
            8 => 'views/geofield.views.inc',
            9 => 'views/handlers/geofield_handler_sort.inc',
            10 => 'views/handlers/geofield_handler_field.inc',
            11 => 'views/handlers/geofield_handler_filter.inc',
            12 => 'views/handlers/geofield_handler_argument_proximity.inc',
            13 => 'views/proximity_plugins/geofieldProximityBase.inc',
            14 => 'views/proximity_plugins/geofieldProximityManual.inc',
            15 => 'views/proximity_plugins/geofieldProximityGeocoder.inc',
            16 => 'views/proximity_plugins/geofieldProximityEntityURL.inc',
            17 => 'views/proximity_plugins/geofieldProximityOtherGeofield.inc',
            18 => 'views/proximity_plugins/geofieldProximityCurrentUser.inc',
            19 => 'views/proximity_plugins/geofieldProximityExposedFilter.inc',
            20 => 'views/proximity_plugins/geofieldProximityContextualFilter.inc',
          ),
          'version' => '7.x-2.3',
          'project' => 'geofield',
          'datestamp' => '1411337638',
          'php' => '5.2.4',
        ),
        'schema_version' => '7202',
        'project' => 'geofield',
        'version' => '7.x-2.3',
      ),
      'calendar' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/calendar/calendar.module',
        'basename' => 'calendar.module',
        'name' => 'calendar',
        'info' => 
        array (
          'name' => 'Calendar',
          'description' => 'Views plugin to display views containing dates as Calendars.',
          'dependencies' => 
          array (
            0 => 'views',
            1 => 'date_api',
            2 => 'date_views',
          ),
          'package' => 'Date/Time',
          'core' => '7.x',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'css/calendar_multiday.css',
            ),
          ),
          'files' => 
          array (
            0 => 'calendar.install',
            1 => 'calendar.module',
            2 => 'includes/calendar.views.inc',
            3 => 'includes/calendar_plugin_style.inc',
            4 => 'includes/calendar_plugin_row.inc',
            5 => 'includes/calendar.views_template.inc',
            6 => 'theme/theme.inc',
            7 => 'theme/calendar-style.tpl.php',
          ),
          'version' => '7.x-3.5',
          'project' => 'calendar',
          'datestamp' => '1413299943',
          'php' => '5.2.4',
        ),
        'schema_version' => '7002',
        'project' => 'calendar',
        'version' => '7.x-3.5',
      ),
      'context_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/context/context_ui/context_ui.module',
        'basename' => 'context_ui.module',
        'name' => 'context_ui',
        'info' => 
        array (
          'name' => 'Context UI',
          'description' => 'Provides a simple UI for settings up a site structure using Context.',
          'dependencies' => 
          array (
            0 => 'context',
          ),
          'package' => 'Context',
          'core' => '7.x',
          'configure' => 'admin/structure/context',
          'files' => 
          array (
            0 => 'context.module',
            1 => 'tests/context_ui.test',
          ),
          'version' => '7.x-3.6',
          'project' => 'context',
          'datestamp' => '1420573188',
          'php' => '5.2.4',
        ),
        'schema_version' => '6004',
        'project' => 'context',
        'version' => '7.x-3.6',
      ),
      'context_layouts' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/context/context_layouts/context_layouts.module',
        'basename' => 'context_layouts.module',
        'name' => 'context_layouts',
        'info' => 
        array (
          'name' => 'Context layouts',
          'description' => 'Allow theme layer to provide multiple region layouts and integrate with context.',
          'dependencies' => 
          array (
            0 => 'context',
          ),
          'package' => 'Context',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'plugins/context_layouts_reaction_block.inc',
          ),
          'version' => '7.x-3.6',
          'project' => 'context',
          'datestamp' => '1420573188',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'context',
        'version' => '7.x-3.6',
      ),
      'context' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/context/context.module',
        'basename' => 'context.module',
        'name' => 'context',
        'info' => 
        array (
          'name' => 'Context',
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          'description' => 'Provide modules with a cache that lasts for a single page request.',
          'package' => 'Context',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'tests/context.test',
            1 => 'tests/context.conditions.test',
            2 => 'tests/context.reactions.test',
          ),
          'version' => '7.x-3.6',
          'project' => 'context',
          'datestamp' => '1420573188',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'context',
        'version' => '7.x-3.6',
      ),
      'geophp' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/geophp/geophp.module',
        'basename' => 'geophp.module',
        'name' => 'geophp',
        'info' => 
        array (
          'name' => 'geoPHP',
          'description' => 'Wraps the geoPHP library: advanced geometry operations in PHP',
          'core' => '7.x',
          'version' => '7.x-1.7',
          'project' => 'geophp',
          'datestamp' => '1352084822',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'geophp',
        'version' => '7.x-1.7',
      ),
      'masquerade' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/masquerade/masquerade.module',
        'basename' => 'masquerade.module',
        'name' => 'masquerade',
        'info' => 
        array (
          'name' => 'Masquerade',
          'description' => 'This module allows permitted users to masquerade as other users.',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'masquerade.test',
          ),
          'configure' => 'admin/config/people/masquerade',
          'version' => '7.x-1.0-rc7',
          'project' => 'masquerade',
          'datestamp' => '1394333639',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'masquerade',
        'version' => '7.x-1.0-rc7',
      ),
      'restful_example' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/restful/modules/restful_example/restful_example.module',
        'basename' => 'restful_example.module',
        'name' => 'restful_example',
        'info' => 
        array (
          'name' => 'RESTful example',
          'description' => 'Example module for the RESTful module.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'restful',
          ),
          'version' => '7.x-1.0',
          'project' => 'restful',
          'datestamp' => '1429031056',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'restful',
        'version' => '7.x-1.0',
      ),
      'restful_angular_example' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/restful/modules/restful_angular_example/restful_angular_example.module',
        'basename' => 'restful_angular_example.module',
        'name' => 'restful_angular_example',
        'info' => 
        array (
          'name' => 'RESTful AngularJs example',
          'description' => 'Example module for the RESTful AngularJs module.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'entity_validator',
            1 => 'entity_validator_example',
            2 => 'jquery_update',
            3 => 'restful',
            4 => 'restful_example',
          ),
          'version' => '7.x-1.0',
          'project' => 'restful',
          'datestamp' => '1429031056',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'restful',
        'version' => '7.x-1.0',
      ),
      'restful_token_auth' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/restful/modules/restful_token_auth/restful_token_auth.module',
        'basename' => 'restful_token_auth.module',
        'name' => 'restful_token_auth',
        'info' => 
        array (
          'name' => 'RESTful token authentication',
          'description' => 'Authenticate a REST call using a token.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'restful',
            1 => 'entityreference',
          ),
          'configure' => 'admin/config/services/restful/token-auth',
          'files' => 
          array (
            0 => 'includes/RestfulTokenAuth.php',
            1 => 'includes/RestfulTokenAuthController.php',
            2 => 'includes/RestfulTokenAuthenticationBase.php',
            3 => 'tests/RestfulTokenAuthenticationTestCase.test',
          ),
          'version' => '7.x-1.0',
          'project' => 'restful',
          'datestamp' => '1429031056',
          'php' => '5.2.4',
        ),
        'schema_version' => '7100',
        'project' => 'restful',
        'version' => '7.x-1.0',
      ),
      'restful' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/restful/restful.module',
        'basename' => 'restful.module',
        'name' => 'restful',
        'info' => 
        array (
          'name' => 'RESTful',
          'description' => 'Turn Drupal to a RESTful server, following best practices.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'entity',
          ),
          'configure' => 'admin/config/services/restful',
          'files' => 
          array (
            0 => 'plugins/authentication/RestfulAuthenticationBase.php',
            1 => 'plugins/authentication/RestfulAuthenticationInterface.php',
            2 => 'plugins/authentication/RestfulAuthenticationManager.php',
            3 => 'plugins/formatter/RestfulFormatterBase.php',
            4 => 'plugins/formatter/RestfulFormatterInterface.php',
            5 => 'plugins/rate_limit/RestfulRateLimitBase.php',
            6 => 'plugins/rate_limit/RestfulRateLimitInterface.php',
            7 => 'plugins/rate_limit/RestfulRateLimitManager.php',
            8 => 'plugins/restful/RestfulBase.php',
            9 => 'plugins/restful/RestfulDataProviderCToolsPlugins.php',
            10 => 'plugins/restful/RestfulDataProviderCToolsPluginsInterface.php',
            11 => 'plugins/restful/RestfulDataProviderDbQuery.php',
            12 => 'plugins/restful/RestfulDataProviderDbQueryInterface.php',
            13 => 'plugins/restful/RestfulDataProviderEFQ.php',
            14 => 'plugins/restful/RestfulDataProviderEFQInterface.php',
            15 => 'plugins/restful/RestfulDataProviderVariable.php',
            16 => 'plugins/restful/RestfulDataProviderVariableInterface.php',
            17 => 'plugins/restful/RestfulDataProviderInterface.php',
            18 => 'plugins/restful/RestfulEntityBase.php',
            19 => 'plugins/restful/RestfulEntityBaseMultipleBundles.php',
            20 => 'plugins/restful/RestfulEntityBaseNode.php',
            21 => 'plugins/restful/RestfulEntityBaseTaxonomyTerm.php',
            22 => 'plugins/restful/RestfulEntityBaseUser.php',
            23 => 'plugins/restful/RestfulEntityInterface.php',
            24 => 'plugins/restful/RestfulFilesUpload.php',
            25 => 'plugins/restful/RestfulInterface.php',
            26 => 'includes/RestfulEntityViewMode.php',
            27 => 'includes/RestfulManager.php',
            28 => 'includes/RestfulPluginBase.php',
            29 => 'includes/RestfulPluginInterface.php',
            30 => 'includes/RestfulRateLimit.php',
            31 => 'includes/RestfulStaticCacheController.php',
            32 => 'includes/RestfulStaticCacheControllerInterface.php',
            33 => 'exceptions/RestfulBadRequestException.php',
            34 => 'exceptions/RestfulException.php',
            35 => 'exceptions/RestfulForbiddenException.php',
            36 => 'exceptions/RestfulFloodException.php',
            37 => 'exceptions/RestfulNotFoundException.php',
            38 => 'exceptions/RestfulNotImplementedException.php',
            39 => 'exceptions/RestfulServerConfigurationException.php',
            40 => 'exceptions/RestfulGoneException.php',
            41 => 'exceptions/RestfulServiceUnavailable.php',
            42 => 'exceptions/RestfulUnauthorizedException.php',
            43 => 'exceptions/RestfulUnsupportedMediaTypeException.php',
            44 => 'exceptions/RestfulUnprocessableEntityException.php',
            45 => 'tests/RestfulAuthenticationTestCase.test',
            46 => 'tests/RestfulAutoCompleteTestCase.test',
            47 => 'tests/RestfulCreateEntityTestCase.test',
            48 => 'tests/RestfulCreateNodeTestCase.test',
            49 => 'tests/RestfulCreateTaxonomyTermTestCase.test',
            50 => 'tests/RestfulCsrfTokenTestCase.test',
            51 => 'tests/RestfulCurlBaseTestCase.test',
            52 => 'tests/RestfulDataProviderCToolsPluginsTestCase.test',
            53 => 'tests/RestfulDbQueryTestCase.test',
            54 => 'tests/RestfulVariableTestCase.test',
            55 => 'tests/RestfulDiscoveryTestCase.test',
            56 => 'tests/RestfulEntityAndPropertyAccessTestCase.test',
            57 => 'tests/RestfulEntityUserAccessTestCase.test',
            58 => 'tests/RestfulEntityValidatorTestCase.test',
            59 => 'tests/RestfulExceptionHandleTestCase.test',
            60 => 'tests/RestfulGetHandlersTestCase.test',
            61 => 'tests/RestfulHalJsonTestCase.test',
            62 => 'tests/RestfulHookMenuTestCase.test',
            63 => 'tests/RestfulListEntityMultipleBundlesTestCase.test',
            64 => 'tests/RestfulListTestCase.test',
            65 => 'tests/RestfulPassThroughTestCase.test',
            66 => 'tests/RestfulRateLimitTestCase.test',
            67 => 'tests/RestfulReferenceTestCase.test',
            68 => 'tests/RestfulRenderCacheTestCase.test',
            69 => 'tests/RestfulSimpleJsonTestCase.test',
            70 => 'tests/RestfulUpdateEntityTestCase.test',
            71 => 'tests/RestfulSubResourcesCreateEntityTestCase.test',
            72 => 'tests/RestfulUpdateEntityCurlTestCase.test',
            73 => 'tests/RestfulUserLoginCookieTestCase.test',
            74 => 'tests/RestfulViewEntityMultiLingualTestCase.test',
            75 => 'tests/RestfulViewEntityTestCase.test',
            76 => 'tests/RestfulViewModeAndFormatterTestCase.test',
          ),
          'version' => '7.x-1.0',
          'project' => 'restful',
          'datestamp' => '1429031056',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'restful',
        'version' => '7.x-1.0',
      ),
      'conditional_fields' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/conditional_fields/conditional_fields.module',
        'basename' => 'conditional_fields.module',
        'name' => 'conditional_fields',
        'info' => 
        array (
          'name' => 'Conditional Fields',
          'description' => 'Define dependencies between fields based on their states and values.',
          'core' => '7.x',
          'package' => 'Fields',
          'dependencies' => 
          array (
            0 => 'system (>=7.14)',
            1 => 'field',
          ),
          'configure' => 'admin/structure/dependencies',
          'version' => '7.x-3.0-alpha1+15-dev',
          'project' => 'conditional_fields',
          'datestamp' => '1424367579',
          'php' => '5.2.4',
        ),
        'schema_version' => '7002',
        'project' => 'conditional_fields',
        'version' => '7.x-3.0-alpha1+15-dev',
      ),
      'usermerge_self' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/usermerge/usermerge_self/usermerge_self.module',
        'basename' => 'usermerge_self.module',
        'name' => 'usermerge_self',
        'info' => 
        array (
          'name' => 'Self-Serve User Merge',
          'description' => 'Allows users to merge two accounts.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'usermerge',
          ),
          'version' => '7.x-2.8',
          'project' => 'usermerge',
          'datestamp' => '1409042329',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'usermerge',
        'version' => '7.x-2.8',
      ),
      'usermerge' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/usermerge/usermerge.module',
        'basename' => 'usermerge.module',
        'name' => 'usermerge',
        'info' => 
        array (
          'name' => 'User Merge',
          'description' => 'Provides an advanced mechanism to merge user accounts together.',
          'core' => '7.x',
          'configure' => 'admin/config/people/usermerge',
          'version' => '7.x-2.8',
          'project' => 'usermerge',
          'datestamp' => '1409042329',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'usermerge',
        'version' => '7.x-2.8',
      ),
      'varnish' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/varnish/varnish.module',
        'basename' => 'varnish.module',
        'name' => 'varnish',
        'info' => 
        array (
          'name' => 'Varnish',
          'description' => 'Provides integration with the Varnish HTTP accelerator.',
          'core' => '7.x',
          'configure' => 'admin/config/development/varnish',
          'package' => 'Caching',
          'files' => 
          array (
            0 => 'varnish.admin.inc',
            1 => 'varnish.cache.inc',
            2 => 'varnish.test',
          ),
          'version' => '7.x-1.0-beta3',
          'project' => 'varnish',
          'datestamp' => '1410442429',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'varnish',
        'version' => '7.x-1.0-beta3',
      ),
      'media_vimeo' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/media_vimeo/media_vimeo.module',
        'basename' => 'media_vimeo.module',
        'name' => 'media_vimeo',
        'info' => 
        array (
          'name' => 'Media: Vimeo',
          'description' => 'Adds Vimeo as a supported media provider.',
          'package' => 'Media',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'media_internet',
          ),
          'files' => 
          array (
            0 => 'includes/MediaVimeoStreamWrapper.inc',
            1 => 'includes/MediaInternetVimeoHandler.inc',
          ),
          'version' => '7.x-2.0',
          'project' => 'media_vimeo',
          'datestamp' => '1395824043',
          'php' => '5.2.4',
        ),
        'schema_version' => '7201',
        'project' => 'media_vimeo',
        'version' => '7.x-2.0',
      ),
      'chosen' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/chosen/chosen.module',
        'basename' => 'chosen.module',
        'name' => 'chosen',
        'info' => 
        array (
          'name' => 'Chosen',
          'description' => 'Makes select elements more user-friendly using <a href="http://harvesthq.github.com/chosen/">Chosen</a>.',
          'package' => 'User interface',
          'configure' => 'admin/config/user-interface/chosen',
          'core' => '7.x',
          'version' => '7.x-2.0-beta4',
          'project' => 'chosen',
          'datestamp' => '1394256505',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7203',
        'project' => 'chosen',
        'version' => '7.x-2.0-beta4',
      ),
      'actions_permissions' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/views_bulk_operations/actions_permissions.module',
        'basename' => 'actions_permissions.module',
        'name' => 'actions_permissions',
        'info' => 
        array (
          'name' => 'Actions permissions (VBO)',
          'description' => 'Provides permission-based access control for actions. Used by Views Bulk Operations.',
          'package' => 'Administration',
          'core' => '7.x',
          'version' => '7.x-3.2',
          'project' => 'views_bulk_operations',
          'datestamp' => '1387798183',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'views_bulk_operations',
        'version' => '7.x-3.2',
      ),
      'views_bulk_operations' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/views_bulk_operations/views_bulk_operations.module',
        'basename' => 'views_bulk_operations.module',
        'name' => 'views_bulk_operations',
        'info' => 
        array (
          'name' => 'Views Bulk Operations',
          'description' => 'Provides a way of selecting multiple rows and applying operations to them.',
          'dependencies' => 
          array (
            0 => 'entity',
            1 => 'views',
          ),
          'package' => 'Views',
          'core' => '7.x',
          'php' => '5.2.9',
          'files' => 
          array (
            0 => 'plugins/operation_types/base.class.php',
            1 => 'views/views_bulk_operations_handler_field_operations.inc',
          ),
          'version' => '7.x-3.2',
          'project' => 'views_bulk_operations',
          'datestamp' => '1387798183',
        ),
        'schema_version' => 0,
        'project' => 'views_bulk_operations',
        'version' => '7.x-3.2',
      ),
      'advagg_bundler' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/advagg/advagg_bundler/advagg_bundler.module',
        'basename' => 'advagg_bundler.module',
        'name' => 'advagg_bundler',
        'info' => 
        array (
          'name' => 'AdvAgg Bundler',
          'description' => 'Provides intelligent bundling of CSS and JS files by grouping files that belong together.',
          'package' => 'Advanced CSS/JS Aggregation',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'advagg',
          ),
          'configure' => 'admin/config/development/performance/advagg/bundler',
          'version' => '7.x-2.8',
          'project' => 'advagg',
          'datestamp' => '1429049283',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'advagg',
        'version' => '7.x-2.8',
      ),
      'advagg_mod' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/advagg/advagg_mod/advagg_mod.module',
        'basename' => 'advagg_mod.module',
        'name' => 'advagg_mod',
        'info' => 
        array (
          'name' => 'AdvAgg Modifier',
          'description' => 'Allows one to alter the CSS and JS array.',
          'package' => 'Advanced CSS/JS Aggregation',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'advagg',
          ),
          'configure' => 'admin/config/development/performance/advagg/mod',
          'version' => '7.x-2.8',
          'project' => 'advagg',
          'datestamp' => '1429049283',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'advagg',
        'version' => '7.x-2.8',
      ),
      'advagg_css_compress' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/advagg/advagg_css_compress/advagg_css_compress.module',
        'basename' => 'advagg_css_compress.module',
        'name' => 'advagg_css_compress',
        'info' => 
        array (
          'name' => 'AdvAgg Compress CSS',
          'description' => 'Compress CSS with a 3rd party compressor, YUI currently.',
          'package' => 'Advanced CSS/JS Aggregation',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'advagg',
          ),
          'configure' => 'admin/config/development/performance/advagg/css-compress',
          'version' => '7.x-2.8',
          'project' => 'advagg',
          'datestamp' => '1429049283',
          'php' => '5.2.4',
        ),
        'schema_version' => '7201',
        'project' => 'advagg',
        'version' => '7.x-2.8',
      ),
      'advagg_js_compress' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/advagg/advagg_js_compress/advagg_js_compress.module',
        'basename' => 'advagg_js_compress.module',
        'name' => 'advagg_js_compress',
        'info' => 
        array (
          'name' => 'AdvAgg Compress Javascript',
          'description' => 'Compress Javascript with a 3rd party compressor; JSMin+, JSMin c ext, JShrink, & JSqueeze currently.',
          'package' => 'Advanced CSS/JS Aggregation',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'advagg',
          ),
          'configure' => 'admin/config/development/performance/advagg/js-compress',
          'version' => '7.x-2.8',
          'project' => 'advagg',
          'datestamp' => '1429049283',
          'php' => '5.2.4',
        ),
        'schema_version' => '7202',
        'project' => 'advagg',
        'version' => '7.x-2.8',
      ),
      'advagg_css_cdn' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/advagg/advagg_css_cdn/advagg_css_cdn.module',
        'basename' => 'advagg_css_cdn.module',
        'name' => 'advagg_css_cdn',
        'info' => 
        array (
          'name' => 'AdvAgg CDN CSS',
          'description' => 'Use a shared CDN for CSS libraries, Google Libraries API currently.',
          'package' => 'Advanced CSS/JS Aggregation',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'advagg',
          ),
          'version' => '7.x-2.8',
          'project' => 'advagg',
          'datestamp' => '1429049283',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'advagg',
        'version' => '7.x-2.8',
      ),
      'advagg_validator' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/advagg/advagg_validator/advagg_validator.module',
        'basename' => 'advagg_validator.module',
        'name' => 'advagg_validator',
        'info' => 
        array (
          'name' => 'AdvAgg CSS/JS Validator',
          'description' => 'Validate the CSS & JS files used in Aggregation for syntax errors.',
          'package' => 'Advanced CSS/JS Aggregation',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'advagg',
          ),
          'configure' => 'admin/config/development/performance/advagg/validator',
          'version' => '7.x-2.8',
          'project' => 'advagg',
          'datestamp' => '1429049283',
          'php' => '5.2.4',
        ),
        'schema_version' => '7201',
        'project' => 'advagg',
        'version' => '7.x-2.8',
      ),
      'advagg_js_cdn' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/advagg/advagg_js_cdn/advagg_js_cdn.module',
        'basename' => 'advagg_js_cdn.module',
        'name' => 'advagg_js_cdn',
        'info' => 
        array (
          'name' => 'AdvAgg CDN Javascript',
          'description' => 'Use a shared CDN for javascript libraries, Google Libraries API currently.',
          'package' => 'Advanced CSS/JS Aggregation',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'advagg',
          ),
          'version' => '7.x-2.8',
          'project' => 'advagg',
          'datestamp' => '1429049283',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'advagg',
        'version' => '7.x-2.8',
      ),
      'advagg' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/advagg/advagg.module',
        'basename' => 'advagg.module',
        'name' => 'advagg',
        'info' => 
        array (
          'name' => 'Advanced CSS/JS Aggregation',
          'description' => 'Aggregates multiple CSS/JS files in a way that prevents 404 from happening when accessing a CSS or JS file.',
          'package' => 'Advanced CSS/JS Aggregation',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'tests/advagg.test',
          ),
          'configure' => 'admin/config/development/performance/advagg',
          'version' => '7.x-2.8',
          'project' => 'advagg',
          'datestamp' => '1429049283',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7206',
        'project' => 'advagg',
        'version' => '7.x-2.8',
      ),
      'chr' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/chr/chr.module',
        'basename' => 'chr.module',
        'name' => 'chr',
        'info' => 
        array (
          'name' => 'cURL HTTP Request',
          'description' => 'Alternative implementation of drupal_http_request() with proxy support using cURL.',
          'core' => '7.x',
          'configure' => 'admin/config/services/chr',
          'version' => '7.x-1.6',
          'project' => 'chr',
          'datestamp' => '1382914226',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'chr',
        'version' => '7.x-1.6',
      ),
      'term_merge' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/term_merge/term_merge.module',
        'basename' => 'term_merge.module',
        'name' => 'term_merge',
        'info' => 
        array (
          'name' => 'Term Merge',
          'description' => 'This module allows you to merge multiple terms into one, while updating all fields referring to those terms to refer to the replacement term instead.',
          'package' => 'Taxonomy',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'term_merge.test',
          ),
          'dependencies' => 
          array (
            0 => 'taxonomy',
            1 => 'entity',
          ),
          'version' => '7.x-1.2',
          'project' => 'term_merge',
          'datestamp' => '1421194982',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'term_merge',
        'version' => '7.x-1.2',
      ),
      'tmgmt_language_combination' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/tmgmt/translators/tmgmt_local/skills/tmgmt_language_combination.module',
        'basename' => 'tmgmt_language_combination.module',
        'name' => 'tmgmt_language_combination',
        'info' => 
        array (
          'name' => 'Translation Language capabilities',
          'description' => 'Provides a field that allows users to select language combinations.',
          'package' => 'Translation Management',
          'core' => '7.x',
          'version' => '7.x-1.0-rc1',
          'project' => 'tmgmt',
          'datestamp' => '1393965810',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'tmgmt',
        'version' => '7.x-1.0-rc1',
      ),
      'tmgmt_local' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/tmgmt/translators/tmgmt_local/tmgmt_local.module',
        'basename' => 'tmgmt_local.module',
        'name' => 'tmgmt_local',
        'info' => 
        array (
          'name' => 'Local Translator',
          'description' => 'Allows local users to provide translation services.',
          'package' => 'Translation Management',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'tmgmt',
            1 => 'tmgmt_language_combination',
          ),
          'configure' => 'admin/config/regional/tmgmt_translator',
          'files' => 
          array (
            0 => 'controller/tmgmt_local.controller.task.inc',
            1 => 'controller/tmgmt_local.controller.task_item.inc',
            2 => 'entity/tmgmt_local.entity.task.inc',
            3 => 'entity/tmgmt_local.entity.task_item.inc',
            4 => 'includes/tmgmt_local.info.inc',
            5 => 'includes/tmgmt_local.plugin.inc',
            6 => 'includes/tmgmt_local.plugin.ui.inc',
            7 => 'controller/tmgmt_local.ui_controller.task.inc',
            8 => 'controller/tmgmt_local.ui_controller.task_item.inc',
            9 => 'tmgmt_local.test',
            10 => 'views/tmgmt_local.views.inc',
            11 => 'views/handlers/tmgmt_local_task_handler_field_job_item_count.inc',
            12 => 'views/handlers/tmgmt_local_task_handler_field_loop_count.inc',
            13 => 'views/handlers/tmgmt_local_task_handler_field_operations.inc',
            14 => 'views/handlers/tmgmt_local_task_handler_field_progress.inc',
            15 => 'views/handlers/tmgmt_local_task_handler_field_item_operations.inc',
            16 => 'views/handlers/tmgmt_local_task_handler_field_wordcount.inc',
            17 => 'views/handlers/tmgmt_local_task_handler_filter_eligible.inc',
          ),
          'version' => '7.x-1.0-rc1',
          'project' => 'tmgmt',
          'datestamp' => '1393965810',
          'php' => '5.2.4',
        ),
        'schema_version' => '7002',
        'project' => 'tmgmt',
        'version' => '7.x-1.0-rc1',
      ),
      'tmgmt_file' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/tmgmt/translators/file/tmgmt_file.module',
        'basename' => 'tmgmt_file.module',
        'name' => 'tmgmt_file',
        'info' => 
        array (
          'name' => 'Export / Import File',
          'description' => 'A translator which allows you to export source data into a file and import the translated in return.',
          'package' => 'Translation Management',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'tmgmt',
          ),
          'configure' => 'admin/config/regional/tmgmt_translator',
          'files' => 
          array (
            0 => 'tmgmt_file.plugin.inc',
            1 => 'tmgmt_file.ui.inc',
            2 => 'tmgmt_file.format.interface.inc',
            3 => 'tmgmt_file.format.xliff.inc',
            4 => 'tmgmt_file.format.html.inc',
            5 => 'tmgmt_file.recursive_iterator.inc',
            6 => 'tmgmt_file.test',
          ),
          'version' => '7.x-1.0-rc1',
          'project' => 'tmgmt',
          'datestamp' => '1393965810',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'tmgmt',
        'version' => '7.x-1.0-rc1',
      ),
      'tmgmt_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/tmgmt/ui/tmgmt_ui.module',
        'basename' => 'tmgmt_ui.module',
        'name' => 'tmgmt_ui',
        'info' => 
        array (
          'name' => 'Translation Management UI',
          'description' => 'User interface.',
          'package' => 'Translation Management',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'tmgmt',
            1 => 'views_bulk_operations',
            2 => 'rules',
          ),
          'files' => 
          array (
            0 => 'includes/tmgmt_ui.controller.job.inc',
            1 => 'includes/tmgmt_ui.controller.job_item.inc',
            2 => 'includes/tmgmt_ui.controller.translator.inc',
            3 => 'includes/tmgmt_ui.cart.inc',
            4 => 'tmgmt_ui.test',
          ),
          'version' => '7.x-1.0-rc1',
          'project' => 'tmgmt',
          'datestamp' => '1393965810',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'tmgmt',
        'version' => '7.x-1.0-rc1',
      ),
      'tmgmt_locale' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/tmgmt/sources/locale/tmgmt_locale.module',
        'basename' => 'tmgmt_locale.module',
        'name' => 'tmgmt_locale',
        'info' => 
        array (
          'name' => 'Locales Source',
          'description' => 'Locales source plugin for the Translation Management system.',
          'package' => 'Translation Management',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'tmgmt',
            1 => 'locale',
          ),
          'files' => 
          array (
            0 => 'tmgmt_locale.plugin.inc',
            1 => 'tmgmt_locale.test',
            2 => 'tmgmt_locale.ui.inc',
            3 => 'tmgmt_locale.ui.test',
          ),
          'version' => '7.x-1.0-rc1',
          'project' => 'tmgmt',
          'datestamp' => '1393965810',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'tmgmt',
        'version' => '7.x-1.0-rc1',
      ),
      'tmgmt_i18n_string' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/tmgmt/sources/i18n_string/tmgmt_i18n_string.module',
        'basename' => 'tmgmt_i18n_string.module',
        'name' => 'tmgmt_i18n_string',
        'info' => 
        array (
          'name' => 'i18n String Source',
          'description' => 'i18n String source plugin for the Translation Management system.',
          'package' => 'Translation Management',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'tmgmt_ui',
            1 => 'i18n_string',
            2 => 'variable',
          ),
          '# List variable as a dependency so that it gets picked up testbot.
# See http://drupal.org/node/1440484
dependencies' => 
          array (
            0 => 'i18n',
          ),
          'files' => 
          array (
            0 => 'tmgmt_i18n_string.plugin.inc',
            1 => 'tmgmt_i18n_string.test',
            2 => 'tmgmt_i18n_string.ui.inc',
          ),
          'version' => '7.x-1.0-rc1',
          'project' => 'tmgmt',
          'datestamp' => '1393965810',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'tmgmt',
        'version' => '7.x-1.0-rc1',
      ),
      'tmgmt_entity_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/tmgmt/sources/entity/ui/tmgmt_entity_ui.module',
        'basename' => 'tmgmt_entity_ui.module',
        'name' => 'tmgmt_entity_ui',
        'info' => 
        array (
          'name' => 'Entity Source User Interface',
          'description' => 'User Interface for the entity translation source plugin.',
          'package' => 'Translation Management',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'tmgmt_entity',
            1 => 'tmgmt_ui',
            2 => 'views_bulk_operations',
          ),
          'files' => 
          array (
            0 => 'tmgmt_entity_ui.test',
            1 => 'tmgmt_entity_ui.list.test',
            2 => 'tmgmt_entity_ui.ui.inc',
          ),
          'version' => '7.x-1.0-rc1',
          'project' => 'tmgmt',
          'datestamp' => '1393965810',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'tmgmt',
        'version' => '7.x-1.0-rc1',
      ),
      'tmgmt_entity' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/tmgmt/sources/entity/tmgmt_entity.module',
        'basename' => 'tmgmt_entity.module',
        'name' => 'tmgmt_entity',
        'info' => 
        array (
          'name' => 'Entity Source',
          'description' => 'Entity source plugin for the Translation Management system.',
          'package' => 'Translation Management',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'tmgmt',
            1 => 'tmgmt_field',
            2 => 'entity',
            3 => 'entity_translation',
          ),
          'test_dependencies' => 
          array (
            0 => 'pathauto',
            1 => 'file_entity',
          ),
          'files' => 
          array (
            0 => 'tmgmt_entity.source.test',
            1 => 'tmgmt_entity.pathauto.test',
            2 => 'tmgmt_entity.suggestions.test',
            3 => 'tmgmt_entity.plugin.inc',
            4 => 'tmgmt_entity.ui.inc',
          ),
          'version' => '7.x-1.0-rc1',
          'project' => 'tmgmt',
          'datestamp' => '1393965810',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'tmgmt',
        'version' => '7.x-1.0-rc1',
      ),
      'tmgmt_node_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/tmgmt/sources/node/ui/tmgmt_node_ui.module',
        'basename' => 'tmgmt_node_ui.module',
        'name' => 'tmgmt_node_ui',
        'info' => 
        array (
          'name' => 'Content Source User Interface',
          'description' => 'User Interface for the content translation source plugin.',
          'package' => 'Translation Management',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'tmgmt_node',
            1 => 'tmgmt_ui',
            2 => 'views_bulk_operations',
          ),
          'files' => 
          array (
            0 => 'tmgmt_node_ui.test',
            1 => 'tmgmt_node_ui.overview.test',
            2 => 'views/tmgmt_node_ui_handler_filter_node_translatable_types.inc',
            3 => 'views/tmgmt_node_ui_handler_field_jobs.inc',
          ),
          'version' => '7.x-1.0-rc1',
          'project' => 'tmgmt',
          'datestamp' => '1393965810',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'tmgmt',
        'version' => '7.x-1.0-rc1',
      ),
      'tmgmt_node' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/tmgmt/sources/node/tmgmt_node.module',
        'basename' => 'tmgmt_node.module',
        'name' => 'tmgmt_node',
        'info' => 
        array (
          'name' => 'Content Source',
          'description' => 'Content Translation source plugin for the Translation Management system.',
          'package' => 'Translation Management',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'tmgmt',
            1 => 'tmgmt_field',
            2 => 'translation',
          ),
          'files' => 
          array (
            0 => 'tmgmt_node.plugin.inc',
            1 => 'tmgmt_node.ui.inc',
            2 => 'tmgmt_node.test',
            3 => 'views/tmgmt_node.views.inc',
            4 => 'views/handlers/tmgmt_node_handler_field_translation_language_status.inc',
            5 => 'views/handlers/tmgmt_node_handler_field_translation_language_status_single.inc',
            6 => 'views/handlers/tmgmt_node_handler_filter_node_translatable_types.inc',
            7 => 'views/handlers/tmgmt_node_handler_filter_missing_translation.inc',
          ),
          'version' => '7.x-1.0-rc1',
          'project' => 'tmgmt',
          'datestamp' => '1393965810',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'tmgmt',
        'version' => '7.x-1.0-rc1',
      ),
      'tmgmt_field' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/tmgmt/sources/field/tmgmt_field.module',
        'basename' => 'tmgmt_field.module',
        'name' => 'tmgmt_field',
        'info' => 
        array (
          'name' => 'Translation Management Field',
          'description' => 'Implements some hooks on behalf of the core Field modules that are required in the Translation Management module.',
          'package' => 'Translation Management',
          'core' => '7.x',
          'version' => '7.x-1.0-rc1',
          'project' => 'tmgmt',
          'datestamp' => '1393965810',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'tmgmt',
        'version' => '7.x-1.0-rc1',
      ),
      'tmgmt' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/tmgmt/tmgmt.module',
        'basename' => 'tmgmt.module',
        'name' => 'tmgmt',
        'info' => 
        array (
          'name' => 'Translation Management Core',
          'description' => 'Core functionality for the Translation Management Suite.',
          'package' => 'Translation Management',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'entity',
            1 => 'locale',
            2 => 'views',
          ),
          'simplytest_dependencies' => 
          array (
            0 => 'tmgmt_demo',
          ),
          'files' => 
          array (
            0 => 'includes/tmgmt.exception.inc',
            1 => 'controller/tmgmt.controller.job.inc',
            2 => 'controller/tmgmt.controller.job_item.inc',
            3 => 'controller/tmgmt.controller.remote.inc',
            4 => 'controller/tmgmt.controller.translator.inc',
            5 => 'entity/tmgmt.entity.job.inc',
            6 => 'entity/tmgmt.entity.job_item.inc',
            7 => 'entity/tmgmt.entity.message.inc',
            8 => 'entity/tmgmt.entity.remote.inc',
            9 => 'entity/tmgmt.entity.translator.inc',
            10 => 'plugin/tmgmt.plugin.base.inc',
            11 => 'plugin/tmgmt.plugin.interface.base.inc',
            12 => 'plugin/tmgmt.plugin.interface.reject.inc',
            13 => 'plugin/tmgmt.plugin.interface.source.inc',
            14 => 'plugin/tmgmt.plugin.interface.translator.inc',
            15 => 'plugin/tmgmt.plugin.source.inc',
            16 => 'plugin/tmgmt.plugin.translator.inc',
            17 => 'plugin/tmgmt.ui.interface.source.inc',
            18 => 'plugin/tmgmt.ui.interface.translator.inc',
            19 => 'plugin/tmgmt.ui.source.inc',
            20 => 'plugin/tmgmt.ui.translator.inc',
            21 => 'includes/tmgmt.info.inc',
            22 => 'tests/tmgmt.base.test',
            23 => 'tests/tmgmt.base.entity.test',
            24 => 'tests/tmgmt.crud.test',
            25 => 'tests/tmgmt.plugin.test',
            26 => 'tests/tmgmt.helper.test',
            27 => 'tests/tmgmt.upgrade.alpha1.test',
            28 => 'views/tmgmt.views.inc',
            29 => 'views/handlers/tmgmt_handler_field_tmgmt_entity_label.inc',
            30 => 'views/handlers/tmgmt_handler_field_tmgmt_job_item_type.inc',
            31 => 'views/handlers/tmgmt_handler_field_tmgmt_translator.inc',
            32 => 'views/handlers/tmgmt_handler_field_tmgmt_job_operations.inc',
            33 => 'views/handlers/tmgmt_handler_field_tmgmt_progress.inc',
            34 => 'views/handlers/tmgmt_handler_field_tmgmt_wordcount.inc',
            35 => 'views/handlers/tmgmt_handler_field_tmgmt_message_message.inc',
            36 => 'views/handlers/tmgmt_handler_field_tmgmt_job_item_operations.inc',
            37 => 'views/handlers/tmgmt_handler_field_tmgmt_job_item_count.inc',
            38 => 'views/plugins/tmgmt_views_job_access.inc',
          ),
          'version' => '7.x-1.0-rc1',
          'project' => 'tmgmt',
          'datestamp' => '1393965810',
          'php' => '5.2.4',
        ),
        'schema_version' => '7014',
        'project' => 'tmgmt',
        'version' => '7.x-1.0-rc1',
      ),
      'defaultconfig' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/defaultconfig/defaultconfig.module',
        'basename' => 'defaultconfig.module',
        'name' => 'defaultconfig',
        'info' => 
        array (
          'name' => 'Default config',
          'description' => 'Use features as default configuration without having to deal with overriden features.',
          'core' => '7.x',
          'package' => 'configuration',
          'dependencies' => 
          array (
            0 => 'features',
          ),
          'version' => '7.x-1.0-alpha9',
          'project' => 'defaultconfig',
          'datestamp' => '1352143559',
          'php' => '5.2.4',
        ),
        'schema_version' => '7101',
        'project' => 'defaultconfig',
        'version' => '7.x-1.0-alpha9',
      ),
      'entityreference_filter' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/entityreference_filter/entityreference_filter.module',
        'basename' => 'entityreference_filter.module',
        'name' => 'entityreference_filter',
        'info' => 
        array (
          'name' => 'Views Reference Filter',
          'description' => 'Provides views-based filter for entity reference and entity id fields in views.',
          'core' => '7.x',
          'package' => 'Views',
          'dependencies' => 
          array (
            0 => 'entityreference',
            1 => 'views',
          ),
          'files' => 
          array (
            0 => 'views/entityreference_filter_view_result.inc',
          ),
          'version' => '7.x-1.5',
          'project' => 'entityreference_filter',
          'datestamp' => '1425989686',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'entityreference_filter',
        'version' => '7.x-1.5',
      ),
      'entity_token' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/entity/entity_token.module',
        'basename' => 'entity_token.module',
        'name' => 'entity_token',
        'info' => 
        array (
          'name' => 'Entity tokens',
          'description' => 'Provides token replacements for all properties that have no tokens and are known to the entity API.',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'entity_token.tokens.inc',
            1 => 'entity_token.module',
          ),
          'dependencies' => 
          array (
            0 => 'entity',
          ),
          'version' => '7.x-1.6',
          'project' => 'entity',
          'datestamp' => '1424876582',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'entity',
        'version' => '7.x-1.6',
      ),
      'entity' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/entity/entity.module',
        'basename' => 'entity.module',
        'name' => 'entity',
        'info' => 
        array (
          'name' => 'Entity API',
          'description' => 'Enables modules to work with any entity type and to provide entities.',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'entity.features.inc',
            1 => 'entity.i18n.inc',
            2 => 'entity.info.inc',
            3 => 'entity.rules.inc',
            4 => 'entity.test',
            5 => 'includes/entity.inc',
            6 => 'includes/entity.controller.inc',
            7 => 'includes/entity.ui.inc',
            8 => 'includes/entity.wrapper.inc',
            9 => 'views/entity.views.inc',
            10 => 'views/handlers/entity_views_field_handler_helper.inc',
            11 => 'views/handlers/entity_views_handler_area_entity.inc',
            12 => 'views/handlers/entity_views_handler_field_boolean.inc',
            13 => 'views/handlers/entity_views_handler_field_date.inc',
            14 => 'views/handlers/entity_views_handler_field_duration.inc',
            15 => 'views/handlers/entity_views_handler_field_entity.inc',
            16 => 'views/handlers/entity_views_handler_field_field.inc',
            17 => 'views/handlers/entity_views_handler_field_numeric.inc',
            18 => 'views/handlers/entity_views_handler_field_options.inc',
            19 => 'views/handlers/entity_views_handler_field_text.inc',
            20 => 'views/handlers/entity_views_handler_field_uri.inc',
            21 => 'views/handlers/entity_views_handler_relationship_by_bundle.inc',
            22 => 'views/handlers/entity_views_handler_relationship.inc',
            23 => 'views/plugins/entity_views_plugin_row_entity_view.inc',
          ),
          'version' => '7.x-1.6',
          'project' => 'entity',
          'datestamp' => '1424876582',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7003',
        'project' => 'entity',
        'version' => '7.x-1.6',
      ),
      'wysiwyg' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/wysiwyg/wysiwyg.module',
        'basename' => 'wysiwyg.module',
        'name' => 'wysiwyg',
        'info' => 
        array (
          'name' => 'Wysiwyg',
          'description' => 'Allows to edit content with client-side editors.',
          'package' => 'User interface',
          'core' => '7.x',
          'configure' => 'admin/config/content/wysiwyg',
          'files' => 
          array (
            0 => 'wysiwyg.module',
            1 => 'tests/wysiwyg.test',
          ),
          'version' => '7.x-2.2+54-dev',
          'project' => 'wysiwyg',
          'datestamp' => '1413622431',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7202',
        'project' => 'wysiwyg',
        'version' => '7.x-2.2+54-dev',
      ),
      'flag_bookmark' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/flag/flag_bookmark/flag_bookmark.module',
        'basename' => 'flag_bookmark.module',
        'name' => 'flag_bookmark',
        'info' => 
        array (
          'name' => 'Flag Bookmark',
          'description' => 'Provides an example bookmark flag and supporting views.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'flag',
          ),
          'package' => 'Flags',
          'version' => '7.x-3.6',
          'project' => 'flag',
          'datestamp' => '1425327793',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'flag',
        'version' => '7.x-3.6',
      ),
      'flag_actions' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/flag/flag_actions.module',
        'basename' => 'flag_actions.module',
        'name' => 'flag_actions',
        'info' => 
        array (
          'name' => 'Flag actions',
          'description' => 'Execute actions on Flag events.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'flag',
          ),
          'package' => 'Flags',
          'configure' => 'admin/structure/flags/actions',
          'files' => 
          array (
            0 => 'flag.install',
            1 => 'flag_actions.module',
          ),
          'version' => '7.x-3.6',
          'project' => 'flag',
          'datestamp' => '1425327793',
          'php' => '5.2.4',
        ),
        'schema_version' => '6200',
        'project' => 'flag',
        'version' => '7.x-3.6',
      ),
      'flag' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/flag/flag.module',
        'basename' => 'flag.module',
        'name' => 'flag',
        'info' => 
        array (
          'name' => 'Flag',
          'description' => 'Create customized flags that users can set on entities.',
          'core' => '7.x',
          'package' => 'Flags',
          'configure' => 'admin/structure/flags',
          'test_dependencies' => 
          array (
            0 => 'token',
            1 => 'rules',
          ),
          'files' => 
          array (
            0 => 'includes/flag/flag_flag.inc',
            1 => 'includes/flag/flag_entity.inc',
            2 => 'includes/flag/flag_node.inc',
            3 => 'includes/flag/flag_comment.inc',
            4 => 'includes/flag/flag_user.inc',
            5 => 'includes/flag.cookie_storage.inc',
            6 => 'includes/flag.entity.inc',
            7 => 'flag.rules.inc',
            8 => 'includes/views/flag_handler_argument_entity_id.inc',
            9 => 'includes/views/flag_handler_field_ops.inc',
            10 => 'includes/views/flag_handler_field_flagged.inc',
            11 => 'includes/views/flag_handler_filter_flagged.inc',
            12 => 'includes/views/flag_handler_sort_flagged.inc',
            13 => 'includes/views/flag_handler_relationships.inc',
            14 => 'includes/views/flag_plugin_argument_validate_flaggability.inc',
            15 => 'tests/flag.test',
          ),
          'version' => '7.x-3.6',
          'project' => 'flag',
          'datestamp' => '1425327793',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7306',
        'project' => 'flag',
        'version' => '7.x-3.6',
      ),
      'feeds_tamper_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/feeds_tamper/feeds_tamper_ui/feeds_tamper_ui.module',
        'basename' => 'feeds_tamper_ui.module',
        'name' => 'feeds_tamper_ui',
        'info' => 
        array (
          'name' => 'Feeds Tamper Admin UI',
          'description' => 'Administrative UI for Feeds Tamper module.',
          'package' => 'Feeds',
          'dependencies' => 
          array (
            0 => 'feeds_tamper',
            1 => 'feeds_ui',
          ),
          'files' => 
          array (
            0 => 'tests/feeds_tamper_ui.test',
          ),
          'core' => '7.x',
          'version' => '7.x-1.0',
          'project' => 'feeds_tamper',
          'datestamp' => '1405301333',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'feeds_tamper',
        'version' => '7.x-1.0',
      ),
      'feeds_tamper' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/feeds_tamper/feeds_tamper.module',
        'basename' => 'feeds_tamper.module',
        'name' => 'feeds_tamper',
        'info' => 
        array (
          'name' => 'Feeds Tamper',
          'description' => 'Modify feeds data before it gets saved.',
          'package' => 'Feeds',
          'dependencies' => 
          array (
            0 => 'feeds',
          ),
          'files' => 
          array (
            0 => 'tests/feeds_tamper.test',
            1 => 'tests/feeds_tamper_plugins.test',
            2 => 'tests/feeds_tamper_efq_finder.test',
          ),
          'core' => '7.x',
          'version' => '7.x-1.0',
          'project' => 'feeds_tamper',
          'datestamp' => '1405301333',
          'php' => '5.2.4',
        ),
        'schema_version' => '7004',
        'project' => 'feeds_tamper',
        'version' => '7.x-1.0',
      ),
      'rules_scheduler' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/rules/rules_scheduler/rules_scheduler.module',
        'basename' => 'rules_scheduler.module',
        'name' => 'rules_scheduler',
        'info' => 
        array (
          'name' => 'Rules Scheduler',
          'description' => 'Schedule the execution of Rules components using actions.',
          'dependencies' => 
          array (
            0 => 'rules',
          ),
          'package' => 'Rules',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'rules_scheduler.admin.inc',
            1 => 'rules_scheduler.module',
            2 => 'rules_scheduler.install',
            3 => 'rules_scheduler.rules.inc',
            4 => 'rules_scheduler.test',
            5 => 'includes/rules_scheduler.handler.inc',
            6 => 'includes/rules_scheduler.views_default.inc',
            7 => 'includes/rules_scheduler.views.inc',
            8 => 'includes/rules_scheduler_views_filter.inc',
          ),
          'version' => '7.x-2.9',
          'project' => 'rules',
          'datestamp' => '1426527210',
          'php' => '5.2.4',
        ),
        'schema_version' => '7204',
        'project' => 'rules',
        'version' => '7.x-2.9',
      ),
      'rules_admin' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/rules/rules_admin/rules_admin.module',
        'basename' => 'rules_admin.module',
        'name' => 'rules_admin',
        'info' => 
        array (
          'name' => 'Rules UI',
          'description' => 'Administrative interface for managing rules.',
          'package' => 'Rules',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'rules_admin.module',
            1 => 'rules_admin.inc',
          ),
          'dependencies' => 
          array (
            0 => 'rules',
          ),
          'version' => '7.x-2.9',
          'project' => 'rules',
          'datestamp' => '1426527210',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'rules',
        'version' => '7.x-2.9',
      ),
      'rules_i18n' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/rules/rules_i18n/rules_i18n.module',
        'basename' => 'rules_i18n.module',
        'name' => 'rules_i18n',
        'info' => 
        array (
          'name' => 'Rules translation',
          'description' => 'Allows translating rules.',
          'dependencies' => 
          array (
            0 => 'rules',
            1 => 'i18n_string',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'rules_i18n.i18n.inc',
            1 => 'rules_i18n.rules.inc',
            2 => 'rules_i18n.test',
          ),
          'version' => '7.x-2.9',
          'project' => 'rules',
          'datestamp' => '1426527210',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'rules',
        'version' => '7.x-2.9',
      ),
      'rules' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/rules/rules.module',
        'basename' => 'rules.module',
        'name' => 'rules',
        'info' => 
        array (
          'name' => 'Rules',
          'description' => 'React on events and conditionally evaluate actions.',
          'package' => 'Rules',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'rules.features.inc',
            1 => 'tests/rules.test',
            2 => 'includes/faces.inc',
            3 => 'includes/rules.core.inc',
            4 => 'includes/rules.event.inc',
            5 => 'includes/rules.processor.inc',
            6 => 'includes/rules.plugins.inc',
            7 => 'includes/rules.state.inc',
            8 => 'includes/rules.dispatcher.inc',
            9 => 'modules/node.eval.inc',
            10 => 'modules/php.eval.inc',
            11 => 'modules/rules_core.eval.inc',
            12 => 'modules/system.eval.inc',
            13 => 'ui/ui.controller.inc',
            14 => 'ui/ui.core.inc',
            15 => 'ui/ui.data.inc',
            16 => 'ui/ui.plugins.inc',
          ),
          'dependencies' => 
          array (
            0 => 'entity_token',
            1 => 'entity',
          ),
          'version' => '7.x-2.9',
          'project' => 'rules',
          'datestamp' => '1426527210',
          'php' => '5.2.4',
        ),
        'schema_version' => '7214',
        'project' => 'rules',
        'version' => '7.x-2.9',
      ),
      'title' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/title/title.module',
        'basename' => 'title.module',
        'name' => 'title',
        'info' => 
        array (
          'name' => 'Title',
          'description' => 'Replaces entity legacy fields with regular fields.',
          'core' => '7.x',
          'package' => 'Fields',
          'configure' => 'admin/config/content/title',
          'dependencies' => 
          array (
            0 => 'system (>7.14)',
          ),
          'files' => 
          array (
            0 => 'title.module',
            1 => 'views/views_handler_title_field.inc',
            2 => 'tests/title.test',
          ),
          'version' => '7.x-1.0-alpha7',
          'project' => 'title',
          'datestamp' => '1363626024',
          'php' => '5.2.4',
        ),
        'schema_version' => '7002',
        'project' => 'title',
        'version' => '7.x-1.0-alpha7',
      ),
      'search_api_saved_searches_i18n' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/search_api_saved_searches/search_api_saved_searches_i18n/search_api_saved_searches_i18n.module',
        'basename' => 'search_api_saved_searches_i18n.module',
        'name' => 'search_api_saved_searches_i18n',
        'info' => 
        array (
          'name' => 'Search API saved searches translation',
          'description' => 'Translate Search API saved searches settings.',
          'dependencies' => 
          array (
            0 => 'search_api_saved_searches',
            1 => 'i18n_string',
          ),
          'core' => '7.x',
          'package' => 'Multilingual - Internationalization',
          'files' => 
          array (
            0 => 'search_api_saved_searches_i18n.controller.inc',
            1 => 'search_api_saved_searches_i18n.string_wrapper.inc',
          ),
          'version' => '7.x-1.3',
          'project' => 'search_api_saved_searches',
          'datestamp' => '1400922530',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'search_api_saved_searches',
        'version' => '7.x-1.3',
      ),
      'search_api_saved_searches' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/search_api_saved_searches/search_api_saved_searches.module',
        'basename' => 'search_api_saved_searches.module',
        'name' => 'search_api_saved_searches',
        'info' => 
        array (
          'name' => 'Search API saved searches',
          'description' => 'Offers users the ability to save executed searches and receive notifications about new results.',
          'dependencies' => 
          array (
            0 => 'search_api',
          ),
          'core' => '7.x',
          'package' => 'Search',
          'files' => 
          array (
            0 => 'search_api_saved_searches.search_entity.inc',
            1 => 'search_api_saved_searches.settings_entity.inc',
            2 => 'views/handler_field_saved_search_interval.inc',
            3 => 'views/handler_field_saved_search_link.inc',
            4 => 'views/handler_field_saved_search_name.inc',
          ),
          'version' => '7.x-1.3',
          'project' => 'search_api_saved_searches',
          'datestamp' => '1400922530',
          'php' => '5.2.4',
        ),
        'schema_version' => '7101',
        'project' => 'search_api_saved_searches',
        'version' => '7.x-1.3',
      ),
      'geofield_postgis' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/geofield_postgis/geofield_postgis.module',
        'basename' => 'geofield_postgis.module',
        'name' => 'geofield_postgis',
        'info' => 
        array (
          'name' => 'Geofield PostGIS',
          'description' => 'Provides a PostGIS backend plugin for geofield',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'geofield',
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'bean_pane' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/bean_pane/bean_pane.module',
        'basename' => 'bean_pane.module',
        'name' => 'bean_pane',
        'info' => 
        array (
          'name' => 'Bean Pane',
          'description' => 'Create and edit bean content with Panels.',
          'core' => '7.x',
          'package' => 'Bean',
          'dependencies' => 
          array (
            0 => 'bean',
            1 => 'ctools',
            2 => 'panels',
          ),
          'version' => '7.x-1.0',
          'project' => 'bean_pane',
          'datestamp' => '1390494218',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'bean_pane',
        'version' => '7.x-1.0',
      ),
      'oauth_common_providerui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/oauth/oauth_common_providerui.module',
        'basename' => 'oauth_common_providerui.module',
        'name' => 'oauth_common_providerui',
        'info' => 
        array (
          'name' => 'OAuth Provider UI',
          'description' => 'Provides a UI for when OAuth is acting as a provider.',
          'package' => 'OAuth',
          'dependencies' => 
          array (
            0 => 'oauth_common',
          ),
          'core' => '7.x',
          'version' => '7.x-3.2',
          'project' => 'oauth',
          'datestamp' => '1390561406',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'oauth',
        'version' => '7.x-3.2',
      ),
      'oauth_common' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/oauth/oauth_common.module',
        'basename' => 'oauth_common.module',
        'name' => 'oauth_common',
        'info' => 
        array (
          'name' => 'OAuth',
          'description' => 'Provides OAuth functionality',
          'configure' => 'admin/config/services/oauth',
          'package' => 'OAuth',
          'recommends' => 
          array (
            0 => 'ctools',
          ),
          'suggests' => 
          array (
            0 => 'inputstream',
          ),
          'core' => '7.x',
          'files' => 
          array (
            0 => 'lib/OAuth.php',
            1 => 'includes/DrupalOAuthServer.inc',
            2 => 'includes/DrupalOAuthDataStore.inc',
            3 => 'includes/DrupalOAuthRequest.inc',
            4 => 'includes/DrupalOAuthToken.inc',
            5 => 'includes/DrupalOAuthConsumer.inc',
            6 => 'includes/DrupalOAuthClient.inc',
            7 => 'includes/OAuthSignatureMethod_HMAC.inc',
          ),
          'version' => '7.x-3.2',
          'project' => 'oauth',
          'datestamp' => '1390561406',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'oauth',
        'version' => '7.x-3.2',
      ),
      'entityreference_prepopulate' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/entityreference_prepopulate/entityreference_prepopulate.module',
        'basename' => 'entityreference_prepopulate.module',
        'name' => 'entityreference_prepopulate',
        'info' => 
        array (
          'name' => 'Entity reference prepopulate',
          'description' => 'Prepopulate entity reference values from URL.',
          'core' => '7.x',
          'package' => 'Fields',
          'dependencies' => 
          array (
            0 => 'entityreference',
          ),
          'files' => 
          array (
            0 => 'entityreference_prepopulate.test',
          ),
          'version' => '7.x-1.5',
          'project' => 'entityreference_prepopulate',
          'datestamp' => '1392845305',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'entityreference_prepopulate',
        'version' => '7.x-1.5',
      ),
      'og_role_delegate' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og_role_delegate/og_role_delegate.module',
        'basename' => 'og_role_delegate.module',
        'name' => 'og_role_delegate',
        'info' => 
        array (
          'name' => 'Organic groups Role Delegate',
          'description' => 'Allow to choose which roles a group administrator can give to other members',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'og_ui',
          ),
          'version' => '7.x-1.0-beta2',
          'project' => 'og_role_delegate',
          'datestamp' => '1383055289',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'og_role_delegate',
        'version' => '7.x-1.0-beta2',
      ),
      'entityreference_behavior_example' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/entityreference/examples/entityreference_behavior_example/entityreference_behavior_example.module',
        'basename' => 'entityreference_behavior_example.module',
        'name' => 'entityreference_behavior_example',
        'info' => 
        array (
          'name' => 'Entity Reference Behavior Example',
          'description' => 'Provides some example code for implementing Entity Reference behaviors.',
          'core' => '7.x',
          'package' => 'Fields',
          'dependencies' => 
          array (
            0 => 'entityreference',
          ),
          'version' => '7.x-1.1',
          'project' => 'entityreference',
          'datestamp' => '1384973110',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'entityreference',
        'version' => '7.x-1.1',
      ),
      'entityreference' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/entityreference/entityreference.module',
        'basename' => 'entityreference.module',
        'name' => 'entityreference',
        'info' => 
        array (
          'name' => 'Entity Reference',
          'description' => 'Provides a field that can reference other entities.',
          'core' => '7.x',
          'package' => 'Fields',
          'dependencies' => 
          array (
            0 => 'entity',
            1 => 'ctools',
          ),
          'files' => 
          array (
            0 => 'entityreference.migrate.inc',
            1 => 'plugins/selection/abstract.inc',
            2 => 'plugins/selection/views.inc',
            3 => 'plugins/behavior/abstract.inc',
            4 => 'views/entityreference_plugin_display.inc',
            5 => 'views/entityreference_plugin_style.inc',
            6 => 'views/entityreference_plugin_row_fields.inc',
            7 => 'tests/entityreference.handlers.test',
            8 => 'tests/entityreference.taxonomy.test',
            9 => 'tests/entityreference.admin.test',
            10 => 'tests/entityreference.feeds.test',
          ),
          'version' => '7.x-1.1',
          'project' => 'entityreference',
          'datestamp' => '1384973110',
          'php' => '5.2.4',
        ),
        'schema_version' => '7002',
        'project' => 'entityreference',
        'version' => '7.x-1.1',
      ),
      'styleguide_palette' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/styleguide/styleguide_palette/styleguide_palette.module',
        'basename' => 'styleguide_palette.module',
        'name' => 'styleguide_palette',
        'info' => 
        array (
          'name' => 'Style guide palette',
          'description' => 'Stores and displays color palettes.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'styleguide',
          ),
          'configure' => 'admin/config/user-interface/styleguide-palette',
          'files' => 
          array (
            0 => 'styleguide_palette.test',
          ),
          'version' => '7.x-1.1',
          'project' => 'styleguide',
          'datestamp' => '1367467219',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'styleguide',
        'version' => '7.x-1.1',
      ),
      'styleguide' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/styleguide/styleguide.module',
        'basename' => 'styleguide.module',
        'name' => 'styleguide',
        'info' => 
        array (
          'name' => 'Style guide',
          'description' => 'Generates a theme style guide for proofing common elements.',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'styleguide.module',
            1 => 'styleguide.styleguide.inc',
          ),
          'version' => '7.x-1.1',
          'project' => 'styleguide',
          'datestamp' => '1367467219',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'styleguide',
        'version' => '7.x-1.1',
      ),
      'l10n_update' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/l10n_update/l10n_update.module',
        'basename' => 'l10n_update.module',
        'name' => 'l10n_update',
        'info' => 
        array (
          'name' => 'Localization update',
          'description' => 'Provides automatic downloads and updates for translations.',
          'dependencies' => 
          array (
            0 => 'locale',
          ),
          'core' => '7.x',
          'package' => 'Multilingual',
          'files' => 
          array (
            0 => 'includes/gettext/PoHeader.php',
            1 => 'includes/gettext/PoItem.php',
            2 => 'includes/gettext/PoMemoryWriter.php',
            3 => 'includes/gettext/PoMetadataInterface.php',
            4 => 'includes/gettext/PoReaderInterface.php',
            5 => 'includes/gettext/PoStreamInterface.php',
            6 => 'includes/gettext/PoStreamReader.php',
            7 => 'includes/gettext/PoStreamWriter.php',
            8 => 'includes/gettext/PoWriterInterface.php',
            9 => 'includes/locale/Gettext.php',
            10 => 'includes/locale/PoDatabaseReader.php',
            11 => 'includes/locale/PoDatabaseWriter.php',
            12 => 'includes/locale/SourceString.php',
            13 => 'includes/locale/StringBase.php',
            14 => 'includes/locale/StringDatabaseStorage.php',
            15 => 'includes/locale/StringInterface.php',
            16 => 'includes/locale/StringStorageException.php',
            17 => 'includes/locale/StringStorageInterface.php',
            18 => 'includes/locale/TranslationString.php',
            19 => 'includes/locale/TranslationsStreamWrapper.php',
            20 => 'tests/L10nUpdateCronTest.test',
            21 => 'tests/L10nUpdateInterfaceTest.test',
            22 => 'tests/L10nUpdateTest.test',
            23 => 'tests/L10nUpdateTestBase.test',
          ),
          'version' => '7.x-2.0',
          'project' => 'l10n_update',
          'datestamp' => '1415625781',
          'php' => '5.2.4',
        ),
        'schema_version' => '7201',
        'project' => 'l10n_update',
        'version' => '7.x-2.0',
      ),
      'wysiwyg_filter' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/wysiwyg_filter/wysiwyg_filter.module',
        'basename' => 'wysiwyg_filter.module',
        'name' => 'wysiwyg_filter',
        'info' => 
        array (
          'name' => 'WYSIWYG Filter',
          'description' => 'Provides an input filter that allows site administrators configure which HTML elements, attributes and style properties are allowed.',
          'package' => 'Input filters',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'wysiwyg_filter.admin.inc',
            1 => 'wysiwyg_filter.inc',
            2 => 'wysiwyg_filter.install',
            3 => 'wysiwyg_filter.module',
            4 => 'wysiwyg_filter.pages.inc',
          ),
          'version' => '7.x-1.6-rc2',
          'project' => 'wysiwyg_filter',
          'datestamp' => '1310326321',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'wysiwyg_filter',
        'version' => '7.x-1.6-rc2',
      ),
      'feeds_news' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/feeds/feeds_news/feeds_news.module',
        'basename' => 'feeds_news.module',
        'name' => 'feeds_news',
        'info' => 
        array (
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'features',
            1 => 'feeds',
            2 => 'views',
          ),
          'description' => 'A news aggregator built with feeds, creates nodes from imported feed items. With OPML import.',
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'feeds:feeds_importer_default:1',
              1 => 'views:views_default:3.0',
            ),
            'feeds_importer' => 
            array (
              0 => 'feed',
              1 => 'opml',
            ),
            'field' => 
            array (
              0 => 'node-feed_item-field_feed_item_description',
            ),
            'node' => 
            array (
              0 => 'feed',
              1 => 'feed_item',
            ),
            'views_view' => 
            array (
              0 => 'feeds_defaults_feed_items',
            ),
          ),
          'files' => 
          array (
            0 => 'feeds_news.module',
            1 => 'feeds_news.test',
          ),
          'name' => 'Feeds News',
          'package' => 'Feeds',
          'php' => '5.2.4',
          'version' => '7.x-2.0-alpha8',
          'project' => 'feeds',
          'datestamp' => '1366671911',
        ),
        'schema_version' => 0,
        'project' => 'feeds',
        'version' => '7.x-2.0-alpha8',
      ),
      'feeds_import' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/feeds/feeds_import/feeds_import.module',
        'basename' => 'feeds_import.module',
        'name' => 'feeds_import',
        'info' => 
        array (
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'feeds',
          ),
          'description' => 'An example of a node importer and a user importer.',
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'feeds:feeds_importer_default:1',
            ),
            'feeds_importer' => 
            array (
              0 => 'node',
              1 => 'user',
            ),
          ),
          'files' => 
          array (
            0 => 'feeds_import.test',
          ),
          'name' => 'Feeds Import',
          'package' => 'Feeds',
          'php' => '5.2.4',
          'version' => '7.x-2.0-alpha8',
          'project' => 'feeds',
          'datestamp' => '1366671911',
        ),
        'schema_version' => 0,
        'project' => 'feeds',
        'version' => '7.x-2.0-alpha8',
      ),
      'feeds_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/feeds/feeds_ui/feeds_ui.module',
        'basename' => 'feeds_ui.module',
        'name' => 'feeds_ui',
        'info' => 
        array (
          'name' => 'Feeds Admin UI',
          'description' => 'Administrative UI for Feeds module.',
          'package' => 'Feeds',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'feeds',
          ),
          'configure' => 'admin/structure/feeds',
          'files' => 
          array (
            0 => 'feeds_ui.test',
          ),
          'version' => '7.x-2.0-alpha8',
          'project' => 'feeds',
          'datestamp' => '1366671911',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'feeds',
        'version' => '7.x-2.0-alpha8',
      ),
      'feeds' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/feeds/feeds.module',
        'basename' => 'feeds.module',
        'name' => 'feeds',
        'info' => 
        array (
          'name' => 'Feeds',
          'description' => 'Aggregates RSS/Atom/RDF feeds, imports CSV files and more.',
          'package' => 'Feeds',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'job_scheduler',
          ),
          'files' => 
          array (
            0 => 'includes/FeedsConfigurable.inc',
            1 => 'includes/FeedsImporter.inc',
            2 => 'includes/FeedsSource.inc',
            3 => 'libraries/ParserCSV.inc',
            4 => 'libraries/http_request.inc',
            5 => 'libraries/PuSHSubscriber.inc',
            6 => 'plugins/FeedsCSVParser.inc',
            7 => 'plugins/FeedsEntityProcessor.inc',
            8 => 'plugins/FeedsFetcher.inc',
            9 => 'plugins/FeedsFileFetcher.inc',
            10 => 'plugins/FeedsHTTPFetcher.inc',
            11 => 'plugins/FeedsNodeProcessor.inc',
            12 => 'plugins/FeedsOPMLParser.inc',
            13 => 'plugins/FeedsParser.inc',
            14 => 'plugins/FeedsPlugin.inc',
            15 => 'plugins/FeedsProcessor.inc',
            16 => 'plugins/FeedsSimplePieParser.inc',
            17 => 'plugins/FeedsSitemapParser.inc',
            18 => 'plugins/FeedsSyndicationParser.inc',
            19 => 'plugins/FeedsTermProcessor.inc',
            20 => 'plugins/FeedsUserProcessor.inc',
            21 => 'tests/feeds.test',
            22 => 'tests/feeds_date_time.test',
            23 => 'tests/feeds_mapper_date.test',
            24 => 'tests/feeds_mapper_date_multiple.test',
            25 => 'tests/feeds_mapper_field.test',
            26 => 'tests/feeds_mapper_file.test',
            27 => 'tests/feeds_mapper_path.test',
            28 => 'tests/feeds_mapper_profile.test',
            29 => 'tests/feeds_mapper.test',
            30 => 'tests/feeds_mapper_config.test',
            31 => 'tests/feeds_fetcher_file.test',
            32 => 'tests/feeds_processor_node.test',
            33 => 'tests/feeds_processor_term.test',
            34 => 'tests/feeds_processor_user.test',
            35 => 'tests/feeds_scheduler.test',
            36 => 'tests/feeds_mapper_link.test',
            37 => 'tests/feeds_mapper_taxonomy.test',
            38 => 'tests/parser_csv.test',
            39 => 'views/feeds_views_handler_argument_importer_id.inc',
            40 => 'views/feeds_views_handler_field_importer_name.inc',
            41 => 'views/feeds_views_handler_field_log_message.inc',
            42 => 'views/feeds_views_handler_field_severity.inc',
            43 => 'views/feeds_views_handler_field_source.inc',
            44 => 'views/feeds_views_handler_filter_severity.inc',
          ),
          'version' => '7.x-2.0-alpha8',
          'project' => 'feeds',
          'datestamp' => '1366671911',
          'php' => '5.2.4',
        ),
        'schema_version' => '7208',
        'project' => 'feeds',
        'version' => '7.x-2.0-alpha8',
      ),
      'languagefield' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/languagefield/languagefield.module',
        'basename' => 'languagefield.module',
        'name' => 'languagefield',
        'info' => 
        array (
          'name' => 'Language Field',
          'description' => 'Defines a simple language field.',
          'package' => 'Fields',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'options',
          ),
          'files' => 
          array (
            0 => 'languagefield.migrate.inc',
          ),
          'version' => '7.x-1.3',
          'project' => 'languagefield',
          'datestamp' => '1420021391',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'languagefield',
        'version' => '7.x-1.3',
      ),
      'og_example' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og/og_example/og_example.module',
        'basename' => 'og_example.module',
        'name' => 'og_example',
        'info' => 
        array (
          'name' => 'OG example',
          'description' => 'Example module to show Organic groups configuration that can be used as building block.',
          'core' => '7.x',
          'package' => 'Features',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'entityreference_prepopulate',
            2 => 'features',
            3 => 'list',
            4 => 'message_notify',
            5 => 'og',
            6 => 'og_ui',
            7 => 'page_manager',
            8 => 'panels',
            9 => 'rules',
            10 => 'views_content',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'page_manager:pages_default:1',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'field_base' => 
            array (
              0 => 'body',
              1 => 'field_node_reference',
              2 => 'group_group',
              3 => 'og_group_ref',
            ),
            'field_instance' => 
            array (
              0 => 'message-og_new_content-field_node_reference',
              1 => 'node-group-body',
              2 => 'node-group-group_group',
              3 => 'node-post-body',
              4 => 'node-post-og_group_ref',
            ),
            'message_type' => 
            array (
              0 => 'og_new_content',
            ),
            'node' => 
            array (
              0 => 'group',
              1 => 'post',
            ),
            'page_manager_handlers' => 
            array (
              0 => 'node_view_panel_context',
            ),
            'rules_config' => 
            array (
              0 => 'rules_og_new_content_message',
            ),
          ),
          'version' => '7.x-2.7',
          'project' => 'og',
          'datestamp' => '1399486728',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'og',
        'version' => '7.x-2.7',
      ),
      'og_field_access' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og/og_field_access/og_field_access.module',
        'basename' => 'og_field_access.module',
        'name' => 'og_field_access',
        'info' => 
        array (
          'name' => 'Organic groups field access',
          'description' => 'Provide field access based on group.',
          'package' => 'Organic groups',
          'dependencies' => 
          array (
            0 => 'og',
          ),
          'core' => '7.x',
          'files' => 
          array (
            0 => 'og_field_access.module',
            1 => 'og_field_access.test',
          ),
          'version' => '7.x-2.7',
          'project' => 'og',
          'datestamp' => '1399486728',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'og',
        'version' => '7.x-2.7',
      ),
      'og_register' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og/og_register/og_register.module',
        'basename' => 'og_register.module',
        'name' => 'og_register',
        'info' => 
        array (
          'name' => 'Organic groups register',
          'description' => 'Allow subscribing to groups during the user registration.',
          'package' => 'Organic groups',
          'dependencies' => 
          array (
            0 => 'og',
          ),
          'core' => '7.x',
          'files' => 
          array (
            0 => 'og_register.module',
            1 => 'og_register.install',
          ),
          'version' => '7.x-2.7',
          'project' => 'og',
          'datestamp' => '1399486728',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'og',
        'version' => '7.x-2.7',
      ),
      'og_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og/og_ui/og_ui.module',
        'basename' => 'og_ui.module',
        'name' => 'og_ui',
        'info' => 
        array (
          'name' => 'Organic groups UI',
          'description' => 'Organic groups UI.',
          'package' => 'Organic groups',
          'dependencies' => 
          array (
            0 => 'og',
            1 => 'views_bulk_operations',
          ),
          'core' => '7.x',
          'version' => '7.x-2.7',
          'files' => 
          array (
            0 => 'og_ui.test',
            1 => 'includes/views/handlers/og_ui_handler_area_og_membership_overview.inc',
            2 => 'includes/migrate/7000/add_field.inc',
            3 => 'includes/migrate/7000/populate_field.inc',
            4 => 'includes/migrate/7000/set_roles.inc',
          ),
          'configure' => 'admin/config/group',
          'project' => 'og',
          'datestamp' => '1399486728',
          'php' => '5.2.4',
        ),
        'schema_version' => '7200',
        'project' => 'og',
        'version' => '7.x-2.7',
      ),
      'og_access' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og/og_access/og_access.module',
        'basename' => 'og_access.module',
        'name' => 'og_access',
        'info' => 
        array (
          'name' => 'Organic groups access control',
          'description' => 'Enable access control for private and public groups and group content.',
          'package' => 'Organic groups',
          'dependencies' => 
          array (
            0 => 'og',
          ),
          'core' => '7.x',
          'version' => '7.x-2.7',
          'files' => 
          array (
            0 => 'og_access.module',
            1 => 'og_access.install',
            2 => 'og_access.test',
          ),
          'project' => 'og',
          'datestamp' => '1399486728',
          'php' => '5.2.4',
        ),
        'schema_version' => '7200',
        'project' => 'og',
        'version' => '7.x-2.7',
      ),
      'og_context' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og/og_context/og_context.module',
        'basename' => 'og_context.module',
        'name' => 'og_context',
        'info' => 
        array (
          'name' => 'Organic groups context',
          'description' => 'Get a group from a viewed page.',
          'package' => 'Organic groups',
          'dependencies' => 
          array (
            0 => 'og',
          ),
          'core' => '7.x',
          'files' => 
          array (
            0 => 'og_context.module',
            1 => 'og_context.install',
            2 => 'includes/views/handlers/og_context_plugin_argument_default_group_context.inc',
            3 => 'includes/views/handlers/og_context_plugin_access_og_perm.inc',
          ),
          'version' => '7.x-2.7',
          'project' => 'og',
          'datestamp' => '1399486728',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'og',
        'version' => '7.x-2.7',
      ),
      'og' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og/og.module',
        'basename' => 'og.module',
        'name' => 'og',
        'info' => 
        array (
          'name' => 'Organic groups',
          'description' => 'API to allow associating content with groups.',
          'package' => 'Organic groups',
          'dependencies' => 
          array (
            0 => 'options',
            1 => 'list',
            2 => 'text',
            3 => 'entity',
            4 => 'entityreference',
          ),
          'core' => '7.x',
          'files' => 
          array (
            0 => 'og.info.inc',
            1 => 'includes/og.admin.inc',
            2 => 'includes/og.exception.inc',
            3 => 'includes/og.membership.inc',
            4 => 'includes/og.membership_type.inc',
            5 => 'includes/views/og.views.inc',
            6 => 'og.test',
            7 => 'includes/views/handlers/og_plugin_argument_validate_group.inc',
            8 => 'includes/views/handlers/og_plugin_argument_default_user_groups.inc',
            9 => 'includes/views/handlers/og_handler_field_group_member_count.inc',
            10 => 'includes/views/handlers/og_handler_field_group_audience_state.inc',
            11 => 'includes/views/handlers/og_handler_field_prerender_list.inc',
            12 => 'includes/views/handlers/og_handler_field_user_roles.inc',
            13 => 'includes/views/handlers/og_handler_field_group_permissions.inc',
            14 => 'includes/views/handlers/og_handler_field_og_membership_link_edit.inc',
            15 => 'includes/views/handlers/og_handler_field_og_membership_link_delete.inc',
            16 => 'includes/views/handlers/og_handler_filter_group_audience_state.inc',
            17 => 'includes/views/handlers/og_handler_filter_user_roles.inc',
            18 => 'includes/views/handlers/og_handler_relationship.inc',
            19 => 'includes/migrate/plugins/destinations/og_membership.inc',
            20 => 'includes/migrate/7000/og_add_fields.inc',
            21 => 'includes/migrate/7000/og_content.inc',
            22 => 'includes/migrate/7000/og_group.inc',
            23 => 'includes/migrate/7000/og_user.inc',
            24 => 'includes/migrate/7000/og_ogur_roles.migrate.inc',
            25 => 'includes/migrate/7000/og_ogur.migrate.inc',
            26 => 'includes/migrate/og.migrate.inc',
            27 => 'includes/migrate/7200/og_og_membership.migrate.inc',
            28 => 'includes/migrate/7200/og_roles.migrate.inc',
            29 => 'includes/migrate/7200/og_user_roles.migrate.inc',
          ),
          'version' => '7.x-2.7',
          'project' => 'og',
          'datestamp' => '1399486728',
          'php' => '5.2.4',
        ),
        'schema_version' => '7205',
        'project' => 'og',
        'version' => '7.x-2.7',
      ),
      'media_youtube' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/media_youtube/media_youtube.module',
        'basename' => 'media_youtube.module',
        'name' => 'media_youtube',
        'info' => 
        array (
          'name' => 'Media: YouTube',
          'description' => 'Adds YouTube as a supported media provider.',
          'package' => 'Media',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'media_internet',
          ),
          'files' => 
          array (
            0 => 'includes/MediaYouTubeStreamWrapper.inc',
            1 => 'includes/MediaInternetYouTubeHandler.inc',
            2 => 'includes/MediaYouTubeBrowser.inc',
          ),
          'version' => '7.x-2.0-rc5',
          'project' => 'media_youtube',
          'datestamp' => '1427094782',
          'php' => '5.2.4',
        ),
        'schema_version' => '7204',
        'project' => 'media_youtube',
        'version' => '7.x-2.0-rc5',
      ),
      'addressfield' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/addressfield/addressfield.module',
        'basename' => 'addressfield.module',
        'name' => 'addressfield',
        'info' => 
        array (
          'name' => 'Address Field',
          'description' => 'Manage a flexible address field, implementing the xNAL standard.',
          'core' => '7.x',
          'package' => 'Fields',
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          'files' => 
          array (
            0 => 'addressfield.migrate.inc',
            1 => 'views/addressfield_views_handler_field_country.inc',
            2 => 'views/addressfield_views_handler_filter_country.inc',
          ),
          'version' => '7.x-1.0',
          'project' => 'addressfield',
          'datestamp' => '1421426885',
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'addressfield',
        'version' => '7.x-1.0',
      ),
      'role_export' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/role_export/role_export.module',
        'basename' => 'role_export.module',
        'name' => 'role_export',
        'info' => 
        array (
          'name' => 'Role Export',
          'description' => 'Exportable user roles with role machine names.',
          'core' => '7.x',
          'version' => '7.x-1.0',
          'project' => 'role_export',
          'datestamp' => '1327037146',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'role_export',
        'version' => '7.x-1.0',
      ),
      'phone_country_locator' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/phone/phone_country_locator/phone_country_locator.module',
        'basename' => 'phone_country_locator.module',
        'name' => 'phone_country_locator',
        'info' => 
        array (
          'name' => 'Phone Country Locator',
          'description' => 'Sets the Phone Number country code based on user IP address',
          'core' => '7.x',
          'package' => 'Fields',
          'dependencies' => 
          array (
            0 => 'phone',
            1 => 'ip2country',
          ),
          'version' => '7.x-2.x-dev',
          'project' => 'phone',
          'datestamp' => '1429267925',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'phone',
        'version' => '7.x-2.x-dev',
      ),
      'phone_cck_convert' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/phone/phone_cck_convert/phone_cck_convert.module',
        'basename' => 'phone_cck_convert.module',
        'name' => 'phone_cck_convert',
        'info' => 
        array (
          'name' => 'CCK Phone Converter',
          'description' => 'Converts all fields using cck_phone-7.x-1.x into phone-7.x-2.x fields.',
          'core' => '7.x',
          'package' => 'Fields',
          'dependencies' => 
          array (
            0 => 'phone',
            1 => 'cck_phone',
          ),
          'version' => '7.x-2.x-dev',
          'project' => 'phone',
          'datestamp' => '1429267925',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'phone',
        'version' => '7.x-2.x-dev',
      ),
      'phone' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/phone/phone.module',
        'basename' => 'phone.module',
        'name' => 'phone',
        'info' => 
        array (
          'name' => 'Phone',
          'description' => 'The phone module lets administrators use a phone number field type and provides a validated FAPI phone element.',
          'package' => 'Fields',
          'dependencies' => 
          array (
            0 => 'field',
            1 => 'libraries (>=2.x)',
          ),
          'files' => 
          array (
            0 => 'phone.migrate.inc',
            1 => 'phone.content_migrate.inc',
          ),
          'core' => '7.x',
          'php' => '5.3',
          'version' => '7.x-2.x-dev',
          'project' => 'phone',
          'datestamp' => '1429267925',
        ),
        'schema_version' => '7200',
        'project' => 'phone',
        'version' => '7.x-2.x-dev',
      ),
      'auto_entitylabel' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/auto_entitylabel/auto_entitylabel.module',
        'basename' => 'auto_entitylabel.module',
        'name' => 'auto_entitylabel',
        'info' => 
        array (
          'name' => 'Automatic Entity Labels',
          'description' => 'Allows hiding of entity label fields and automatic label creation.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'entity',
          ),
          'version' => '7.x-1.3',
          'project' => 'auto_entitylabel',
          'datestamp' => '1419756181',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'auto_entitylabel',
        'version' => '7.x-1.3',
      ),
      'entity_translation_upgrade' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/entity_translation/entity_translation_upgrade/entity_translation_upgrade.module',
        'basename' => 'entity_translation_upgrade.module',
        'name' => 'entity_translation_upgrade',
        'info' => 
        array (
          'name' => 'Entity Translation Upgrade',
          'description' => 'Provides an upgrade path from node-based translation to field-based translation.',
          'package' => 'Multilingual - Entity Translation',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'entity_translation',
          ),
          'version' => '7.x-1.0-beta4',
          'project' => 'entity_translation',
          'datestamp' => '1421971088',
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'entity_translation',
        'version' => '7.x-1.0-beta4',
      ),
      'entity_translation_i18n_menu' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/entity_translation/entity_translation_i18n_menu/entity_translation_i18n_menu.module',
        'basename' => 'entity_translation_i18n_menu.module',
        'name' => 'entity_translation_i18n_menu',
        'info' => 
        array (
          'name' => 'Entity Translation Menu',
          'description' => 'Allows menu items to be translated on the entity form.',
          'package' => 'Multilingual - Entity Translation',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'entity_translation',
            1 => 'i18n',
            2 => 'i18n_menu',
          ),
          'files' => 
          array (
            0 => 'entity_translation_i18n_menu.test',
          ),
          'version' => '7.x-1.0-beta4',
          'project' => 'entity_translation',
          'datestamp' => '1421971088',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'entity_translation',
        'version' => '7.x-1.0-beta4',
      ),
      'entity_translation' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/entity_translation/entity_translation.module',
        'basename' => 'entity_translation.module',
        'name' => 'entity_translation',
        'info' => 
        array (
          'name' => 'Entity Translation',
          'description' => 'Allows entities to be translated into different languages.',
          'package' => 'Multilingual - Entity Translation',
          'core' => '7.x',
          'configure' => 'admin/config/regional/entity_translation',
          'dependencies' => 
          array (
            0 => 'locale (>7.14)',
          ),
          'files' => 
          array (
            0 => 'includes/translation.handler_factory.inc',
            1 => 'includes/translation.handler.inc',
            2 => 'includes/translation.handler.comment.inc',
            3 => 'includes/translation.handler.node.inc',
            4 => 'includes/translation.handler.taxonomy_term.inc',
            5 => 'includes/translation.handler.user.inc',
            6 => 'tests/entity_translation.test',
            7 => 'views/entity_translation_handler_relationship.inc',
            8 => 'views/entity_translation_handler_field_translate_link.inc',
            9 => 'views/entity_translation_handler_field_label.inc',
            10 => 'views/entity_translation_handler_filter_entity_type.inc',
            11 => 'views/entity_translation_handler_filter_language.inc',
            12 => 'views/entity_translation_handler_filter_translation_exists.inc',
            13 => 'views/entity_translation_handler_field_field.inc',
          ),
          'version' => '7.x-1.0-beta4',
          'project' => 'entity_translation',
          'datestamp' => '1421971088',
          'php' => '5.2.4',
        ),
        'schema_version' => '7007',
        'project' => 'entity_translation',
        'version' => '7.x-1.0-beta4',
      ),
      'search_api_facetapi' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/search_api/contrib/search_api_facetapi/search_api_facetapi.module',
        'basename' => 'search_api_facetapi.module',
        'name' => 'search_api_facetapi',
        'info' => 
        array (
          'name' => 'Search facets',
          'description' => 'Integrate the Search API with the Facet API to provide facetted searches.',
          'dependencies' => 
          array (
            0 => 'search_api',
            1 => 'facetapi',
          ),
          'core' => '7.x',
          'package' => 'Search',
          'files' => 
          array (
            0 => 'plugins/facetapi/adapter.inc',
            1 => 'plugins/facetapi/query_type_term.inc',
            2 => 'plugins/facetapi/query_type_date.inc',
          ),
          'version' => '7.x-1.14',
          'project' => 'search_api',
          'datestamp' => '1419580682',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'search_api',
        'version' => '7.x-1.14',
      ),
      'search_api_views' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/search_api/contrib/search_api_views/search_api_views.module',
        'basename' => 'search_api_views.module',
        'name' => 'search_api_views',
        'info' => 
        array (
          'name' => 'Search views',
          'description' => 'Integrates the Search API with Views, enabling users to create views with searches as filters or arguments.',
          'dependencies' => 
          array (
            0 => 'search_api',
            1 => 'views',
          ),
          'core' => '7.x',
          'package' => 'Search',
          'files' => 
          array (
            0 => 'includes/display_facet_block.inc',
            1 => 'includes/handler_argument.inc',
            2 => 'includes/handler_argument_fulltext.inc',
            3 => 'includes/handler_argument_more_like_this.inc',
            4 => 'includes/handler_argument_string.inc',
            5 => 'includes/handler_argument_date.inc',
            6 => 'includes/handler_argument_taxonomy_term.inc',
            7 => 'includes/handler_filter.inc',
            8 => 'includes/handler_filter_boolean.inc',
            9 => 'includes/handler_filter_date.inc',
            10 => 'includes/handler_filter_entity.inc',
            11 => 'includes/handler_filter_fulltext.inc',
            12 => 'includes/handler_filter_language.inc',
            13 => 'includes/handler_filter_options.inc',
            14 => 'includes/handler_filter_taxonomy_term.inc',
            15 => 'includes/handler_filter_text.inc',
            16 => 'includes/handler_filter_user.inc',
            17 => 'includes/handler_sort.inc',
            18 => 'includes/plugin_cache.inc',
            19 => 'includes/plugin_content_cache.inc',
            20 => 'includes/query.inc',
          ),
          'version' => '7.x-1.14',
          'project' => 'search_api',
          'datestamp' => '1419580682',
          'php' => '5.2.4',
        ),
        'schema_version' => '7102',
        'project' => 'search_api',
        'version' => '7.x-1.14',
      ),
      'search_api' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/search_api/search_api.module',
        'basename' => 'search_api.module',
        'name' => 'search_api',
        'info' => 
        array (
          'name' => 'Search API',
          'description' => 'Provides a generic API for modules offering search capabilites.',
          'dependencies' => 
          array (
            0 => 'entity',
          ),
          'core' => '7.x',
          'package' => 'Search',
          'files' => 
          array (
            0 => 'search_api.test',
            1 => 'includes/callback.inc',
            2 => 'includes/callback_add_aggregation.inc',
            3 => 'includes/callback_add_hierarchy.inc',
            4 => 'includes/callback_add_url.inc',
            5 => 'includes/callback_add_viewed_entity.inc',
            6 => 'includes/callback_bundle_filter.inc',
            7 => 'includes/callback_comment_access.inc',
            8 => 'includes/callback_language_control.inc',
            9 => 'includes/callback_node_access.inc',
            10 => 'includes/callback_node_status.inc',
            11 => 'includes/callback_role_filter.inc',
            12 => 'includes/datasource.inc',
            13 => 'includes/datasource_entity.inc',
            14 => 'includes/datasource_external.inc',
            15 => 'includes/exception.inc',
            16 => 'includes/index_entity.inc',
            17 => 'includes/processor.inc',
            18 => 'includes/processor_highlight.inc',
            19 => 'includes/processor_html_filter.inc',
            20 => 'includes/processor_ignore_case.inc',
            21 => 'includes/processor_stopwords.inc',
            22 => 'includes/processor_tokenizer.inc',
            23 => 'includes/processor_transliteration.inc',
            24 => 'includes/query.inc',
            25 => 'includes/server_entity.inc',
            26 => 'includes/service.inc',
          ),
          'configure' => 'admin/config/search/search_api',
          'version' => '7.x-1.14',
          'project' => 'search_api',
          'datestamp' => '1419580682',
          'php' => '5.2.4',
        ),
        'schema_version' => '7117',
        'project' => 'search_api',
        'version' => '7.x-1.14',
      ),
      'shs' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/shs/shs.module',
        'basename' => 'shs.module',
        'name' => 'shs',
        'info' => 
        array (
          'name' => 'Simple hierarchical select',
          'core' => '7.x',
          'description' => 'Creates a simple hierarchical select widget for taxonomy fields.',
          'dependencies' => 
          array (
            0 => 'taxonomy',
          ),
          'files' => 
          array (
            0 => 'includes/handlers/shs_handler_filter_entityreference.inc',
            1 => 'includes/handlers/shs_handler_filter_term_node_tid.inc',
            2 => 'includes/handlers/shs_handler_filter_term_node_tid_depth.inc',
          ),
          'version' => '7.x-1.6+56-dev',
          'project' => 'shs',
          'datestamp' => '1424346194',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'shs',
        'version' => '7.x-1.6+56-dev',
      ),
      'migrate_extras_profile2' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/migrate_extras/migrate_extras_examples/migrate_extras_profile2/migrate_extras_profile2.module',
        'basename' => 'migrate_extras_profile2.module',
        'name' => 'migrate_extras_profile2',
        'info' => 
        array (
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'migrate_extras',
            1 => 'profile2',
          ),
          'description' => 'Examples of migrating into Profile2 entities',
          'files' => 
          array (
            0 => 'migrate_extras_profile2.migrate.inc',
          ),
          'name' => 'Migrate Extras Profile2 Example',
          'package' => 'Migrate Examples',
          'version' => '7.x-2.5',
          'project' => 'migrate_extras',
          'datestamp' => '1352299013',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'migrate_extras',
        'version' => '7.x-2.5',
      ),
      'migrate_extras_pathauto' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/migrate_extras/migrate_extras_examples/migrate_extras_pathauto/migrate_extras_pathauto.module',
        'basename' => 'migrate_extras_pathauto.module',
        'name' => 'migrate_extras_pathauto',
        'info' => 
        array (
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'features',
            1 => 'migrate_extras',
            2 => 'pathauto',
          ),
          'description' => 'Examples of migrating with the Pathauto module',
          'features' => 
          array (
            'field' => 
            array (
              0 => 'node-migrate_example_pathauto-body',
            ),
            'node' => 
            array (
              0 => 'migrate_example_pathauto',
            ),
          ),
          'files' => 
          array (
            0 => 'migrate_extras_pathauto.migrate.inc',
          ),
          'name' => 'Migrate Extras Pathauto Example',
          'package' => 'Migrate Examples',
          'project' => 'migrate_extras',
          'version' => '7.x-2.5',
          'datestamp' => '1352299013',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'migrate_extras',
        'version' => '7.x-2.5',
      ),
      'migrate_extras_media' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/migrate_extras/migrate_extras_examples/migrate_extras_media/migrate_extras_media.module',
        'basename' => 'migrate_extras_media.module',
        'name' => 'migrate_extras_media',
        'info' => 
        array (
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'features',
            1 => 'file',
            2 => 'media',
            3 => 'media_youtube',
            4 => 'migrate',
            5 => 'migrate_extras',
          ),
          'description' => 'Examples for migrating Media',
          'features' => 
          array (
            'field' => 
            array (
              0 => 'node-migrate_extras_media_example-body',
              1 => 'node-migrate_extras_media_example-field_document',
              2 => 'node-migrate_extras_media_example-field_media_image',
              3 => 'node-migrate_extras_media_example-field_youtube_video',
            ),
            'node' => 
            array (
              0 => 'migrate_extras_media_example',
            ),
          ),
          'files' => 
          array (
            0 => 'migrate_extras_media.migrate.inc',
          ),
          'name' => 'Migrate Extras Media',
          'package' => 'Migrate Examples',
          'version' => '7.x-2.5',
          'project' => 'migrate_extras',
          'datestamp' => '1352299013',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'migrate_extras',
        'version' => '7.x-2.5',
      ),
      'migrate_extras' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/migrate_extras/migrate_extras.module',
        'basename' => 'migrate_extras.module',
        'name' => 'migrate_extras',
        'info' => 
        array (
          'name' => 'Migrate Extras',
          'description' => 'Adds migrate module integration with contrib modules and other miscellaneous tweaks.',
          'core' => '7.x',
          'package' => 'Development',
          'dependencies' => 
          array (
            0 => 'migrate',
          ),
          'files' => 
          array (
            0 => 'addressfield.inc',
            1 => 'cck_phone.inc',
            2 => 'entity_api.inc',
            3 => 'flag.inc',
            4 => 'geofield.inc',
            5 => 'interval.inc',
            6 => 'media.inc',
            7 => 'name.inc',
            8 => 'pathauto.inc',
            9 => 'privatemsg.inc',
            10 => 'profile2.inc',
            11 => 'rules.inc',
            12 => 'user_relationships.inc',
            13 => 'votingapi.inc',
            14 => 'webform.inc',
            15 => 'tests/pathauto.test',
          ),
          'version' => '7.x-2.5',
          'project' => 'migrate_extras',
          'datestamp' => '1352299013',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'migrate_extras',
        'version' => '7.x-2.5',
      ),
      'link_icons' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/link_icons_formatter/link_icons.module',
        'basename' => 'link_icons.module',
        'name' => 'link_icons',
        'info' => 
        array (
          'name' => 'Link Icons formatter',
          'description' => 'Field formatter for Link field to show icon based on referred service.',
          'dependencies' => 
          array (
            0 => 'link',
          ),
          'package' => 'Fields',
          'core' => '7.x',
          'version' => 'unknown',
          'project' => 'link_icons_formatter',
          'datestamp' => '1429267953',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'link_icons_formatter',
        'version' => 'unknown',
      ),
      'mollom' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/mollom/mollom.module',
        'basename' => 'mollom.module',
        'name' => 'mollom',
        'info' => 
        array (
          'name' => 'Mollom',
          'description' => 'Automatically moderates user-submitted content and protects your site from spam and profanity.',
          'core' => '7.x',
          'configure' => 'admin/config/content/mollom',
          'test_dependencies' => 
          array (
            0 => 'ctools',
          ),
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'mollom.css',
            ),
          ),
          'files' => 
          array (
            0 => 'includes/mollom.class.inc',
            1 => 'mollom.drupal.inc',
            2 => 'tests/mollom.test',
            3 => 'tests/mollom.class.test',
          ),
          'version' => '7.x-2.13',
          'project' => 'mollom',
          'datestamp' => '1418648294',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7213',
        'project' => 'mollom',
        'version' => '7.x-2.13',
      ),
      'views_export' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/views/views_export/views_export.module',
        'basename' => 'views_export.module',
        'name' => 'views_export',
        'info' => 
        array (
          'dependencies' => 
          array (
          ),
          'description' => '',
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'views' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/views/views.module',
        'basename' => 'views.module',
        'name' => 'views',
        'info' => 
        array (
          'name' => 'Views',
          'description' => 'Create customized lists and queries from your database.',
          'package' => 'Views',
          'core' => '7.x',
          'php' => '5.2',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'css/views.css',
            ),
          ),
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          'files' => 
          array (
            0 => 'handlers/views_handler_area.inc',
            1 => 'handlers/views_handler_area_messages.inc',
            2 => 'handlers/views_handler_area_result.inc',
            3 => 'handlers/views_handler_area_text.inc',
            4 => 'handlers/views_handler_area_text_custom.inc',
            5 => 'handlers/views_handler_area_view.inc',
            6 => 'handlers/views_handler_argument.inc',
            7 => 'handlers/views_handler_argument_date.inc',
            8 => 'handlers/views_handler_argument_formula.inc',
            9 => 'handlers/views_handler_argument_many_to_one.inc',
            10 => 'handlers/views_handler_argument_null.inc',
            11 => 'handlers/views_handler_argument_numeric.inc',
            12 => 'handlers/views_handler_argument_string.inc',
            13 => 'handlers/views_handler_argument_group_by_numeric.inc',
            14 => 'handlers/views_handler_field.inc',
            15 => 'handlers/views_handler_field_counter.inc',
            16 => 'handlers/views_handler_field_boolean.inc',
            17 => 'handlers/views_handler_field_contextual_links.inc',
            18 => 'handlers/views_handler_field_custom.inc',
            19 => 'handlers/views_handler_field_date.inc',
            20 => 'handlers/views_handler_field_entity.inc',
            21 => 'handlers/views_handler_field_markup.inc',
            22 => 'handlers/views_handler_field_math.inc',
            23 => 'handlers/views_handler_field_numeric.inc',
            24 => 'handlers/views_handler_field_prerender_list.inc',
            25 => 'handlers/views_handler_field_time_interval.inc',
            26 => 'handlers/views_handler_field_serialized.inc',
            27 => 'handlers/views_handler_field_machine_name.inc',
            28 => 'handlers/views_handler_field_url.inc',
            29 => 'handlers/views_handler_filter.inc',
            30 => 'handlers/views_handler_filter_boolean_operator.inc',
            31 => 'handlers/views_handler_filter_boolean_operator_string.inc',
            32 => 'handlers/views_handler_filter_combine.inc',
            33 => 'handlers/views_handler_filter_date.inc',
            34 => 'handlers/views_handler_filter_equality.inc',
            35 => 'handlers/views_handler_filter_entity_bundle.inc',
            36 => 'handlers/views_handler_filter_group_by_numeric.inc',
            37 => 'handlers/views_handler_filter_in_operator.inc',
            38 => 'handlers/views_handler_filter_many_to_one.inc',
            39 => 'handlers/views_handler_filter_numeric.inc',
            40 => 'handlers/views_handler_filter_string.inc',
            41 => 'handlers/views_handler_filter_fields_compare.inc',
            42 => 'handlers/views_handler_relationship.inc',
            43 => 'handlers/views_handler_relationship_groupwise_max.inc',
            44 => 'handlers/views_handler_sort.inc',
            45 => 'handlers/views_handler_sort_date.inc',
            46 => 'handlers/views_handler_sort_formula.inc',
            47 => 'handlers/views_handler_sort_group_by_numeric.inc',
            48 => 'handlers/views_handler_sort_menu_hierarchy.inc',
            49 => 'handlers/views_handler_sort_random.inc',
            50 => 'includes/base.inc',
            51 => 'includes/handlers.inc',
            52 => 'includes/plugins.inc',
            53 => 'includes/view.inc',
            54 => 'modules/aggregator/views_handler_argument_aggregator_fid.inc',
            55 => 'modules/aggregator/views_handler_argument_aggregator_iid.inc',
            56 => 'modules/aggregator/views_handler_argument_aggregator_category_cid.inc',
            57 => 'modules/aggregator/views_handler_field_aggregator_title_link.inc',
            58 => 'modules/aggregator/views_handler_field_aggregator_category.inc',
            59 => 'modules/aggregator/views_handler_field_aggregator_item_description.inc',
            60 => 'modules/aggregator/views_handler_field_aggregator_xss.inc',
            61 => 'modules/aggregator/views_handler_filter_aggregator_category_cid.inc',
            62 => 'modules/aggregator/views_plugin_row_aggregator_rss.inc',
            63 => 'modules/book/views_plugin_argument_default_book_root.inc',
            64 => 'modules/comment/views_handler_argument_comment_user_uid.inc',
            65 => 'modules/comment/views_handler_field_comment.inc',
            66 => 'modules/comment/views_handler_field_comment_depth.inc',
            67 => 'modules/comment/views_handler_field_comment_link.inc',
            68 => 'modules/comment/views_handler_field_comment_link_approve.inc',
            69 => 'modules/comment/views_handler_field_comment_link_delete.inc',
            70 => 'modules/comment/views_handler_field_comment_link_edit.inc',
            71 => 'modules/comment/views_handler_field_comment_link_reply.inc',
            72 => 'modules/comment/views_handler_field_comment_node_link.inc',
            73 => 'modules/comment/views_handler_field_comment_username.inc',
            74 => 'modules/comment/views_handler_field_ncs_last_comment_name.inc',
            75 => 'modules/comment/views_handler_field_ncs_last_updated.inc',
            76 => 'modules/comment/views_handler_field_node_comment.inc',
            77 => 'modules/comment/views_handler_field_node_new_comments.inc',
            78 => 'modules/comment/views_handler_field_last_comment_timestamp.inc',
            79 => 'modules/comment/views_handler_filter_comment_user_uid.inc',
            80 => 'modules/comment/views_handler_filter_ncs_last_updated.inc',
            81 => 'modules/comment/views_handler_filter_node_comment.inc',
            82 => 'modules/comment/views_handler_sort_comment_thread.inc',
            83 => 'modules/comment/views_handler_sort_ncs_last_comment_name.inc',
            84 => 'modules/comment/views_handler_sort_ncs_last_updated.inc',
            85 => 'modules/comment/views_plugin_row_comment_rss.inc',
            86 => 'modules/comment/views_plugin_row_comment_view.inc',
            87 => 'modules/contact/views_handler_field_contact_link.inc',
            88 => 'modules/field/views_handler_field_field.inc',
            89 => 'modules/field/views_handler_relationship_entity_reverse.inc',
            90 => 'modules/field/views_handler_argument_field_list.inc',
            91 => 'modules/field/views_handler_filter_field_list_boolean.inc',
            92 => 'modules/field/views_handler_argument_field_list_string.inc',
            93 => 'modules/field/views_handler_filter_field_list.inc',
            94 => 'modules/filter/views_handler_field_filter_format_name.inc',
            95 => 'modules/locale/views_handler_field_node_language.inc',
            96 => 'modules/locale/views_handler_filter_node_language.inc',
            97 => 'modules/locale/views_handler_argument_locale_group.inc',
            98 => 'modules/locale/views_handler_argument_locale_language.inc',
            99 => 'modules/locale/views_handler_field_locale_group.inc',
            100 => 'modules/locale/views_handler_field_locale_language.inc',
            101 => 'modules/locale/views_handler_field_locale_link_edit.inc',
            102 => 'modules/locale/views_handler_filter_locale_group.inc',
            103 => 'modules/locale/views_handler_filter_locale_language.inc',
            104 => 'modules/locale/views_handler_filter_locale_version.inc',
            105 => 'modules/node/views_handler_argument_dates_various.inc',
            106 => 'modules/node/views_handler_argument_node_language.inc',
            107 => 'modules/node/views_handler_argument_node_nid.inc',
            108 => 'modules/node/views_handler_argument_node_type.inc',
            109 => 'modules/node/views_handler_argument_node_vid.inc',
            110 => 'modules/node/views_handler_argument_node_uid_revision.inc',
            111 => 'modules/node/views_handler_field_history_user_timestamp.inc',
            112 => 'modules/node/views_handler_field_node.inc',
            113 => 'modules/node/views_handler_field_node_link.inc',
            114 => 'modules/node/views_handler_field_node_link_delete.inc',
            115 => 'modules/node/views_handler_field_node_link_edit.inc',
            116 => 'modules/node/views_handler_field_node_revision.inc',
            117 => 'modules/node/views_handler_field_node_revision_link.inc',
            118 => 'modules/node/views_handler_field_node_revision_link_delete.inc',
            119 => 'modules/node/views_handler_field_node_revision_link_revert.inc',
            120 => 'modules/node/views_handler_field_node_path.inc',
            121 => 'modules/node/views_handler_field_node_type.inc',
            122 => 'modules/node/views_handler_filter_history_user_timestamp.inc',
            123 => 'modules/node/views_handler_filter_node_access.inc',
            124 => 'modules/node/views_handler_filter_node_status.inc',
            125 => 'modules/node/views_handler_filter_node_type.inc',
            126 => 'modules/node/views_handler_filter_node_uid_revision.inc',
            127 => 'modules/node/views_plugin_argument_default_node.inc',
            128 => 'modules/node/views_plugin_argument_validate_node.inc',
            129 => 'modules/node/views_plugin_row_node_rss.inc',
            130 => 'modules/node/views_plugin_row_node_view.inc',
            131 => 'modules/profile/views_handler_field_profile_date.inc',
            132 => 'modules/profile/views_handler_field_profile_list.inc',
            133 => 'modules/profile/views_handler_filter_profile_selection.inc',
            134 => 'modules/search/views_handler_argument_search.inc',
            135 => 'modules/search/views_handler_field_search_score.inc',
            136 => 'modules/search/views_handler_filter_search.inc',
            137 => 'modules/search/views_handler_sort_search_score.inc',
            138 => 'modules/search/views_plugin_row_search_view.inc',
            139 => 'modules/statistics/views_handler_field_accesslog_path.inc',
            140 => 'modules/system/views_handler_argument_file_fid.inc',
            141 => 'modules/system/views_handler_field_file.inc',
            142 => 'modules/system/views_handler_field_file_extension.inc',
            143 => 'modules/system/views_handler_field_file_filemime.inc',
            144 => 'modules/system/views_handler_field_file_uri.inc',
            145 => 'modules/system/views_handler_field_file_status.inc',
            146 => 'modules/system/views_handler_filter_file_status.inc',
            147 => 'modules/taxonomy/views_handler_argument_taxonomy.inc',
            148 => 'modules/taxonomy/views_handler_argument_term_node_tid.inc',
            149 => 'modules/taxonomy/views_handler_argument_term_node_tid_depth.inc',
            150 => 'modules/taxonomy/views_handler_argument_term_node_tid_depth_modifier.inc',
            151 => 'modules/taxonomy/views_handler_argument_vocabulary_vid.inc',
            152 => 'modules/taxonomy/views_handler_argument_vocabulary_machine_name.inc',
            153 => 'modules/taxonomy/views_handler_field_taxonomy.inc',
            154 => 'modules/taxonomy/views_handler_field_term_node_tid.inc',
            155 => 'modules/taxonomy/views_handler_field_term_link_edit.inc',
            156 => 'modules/taxonomy/views_handler_filter_term_node_tid.inc',
            157 => 'modules/taxonomy/views_handler_filter_term_node_tid_depth.inc',
            158 => 'modules/taxonomy/views_handler_filter_vocabulary_vid.inc',
            159 => 'modules/taxonomy/views_handler_filter_vocabulary_machine_name.inc',
            160 => 'modules/taxonomy/views_handler_relationship_node_term_data.inc',
            161 => 'modules/taxonomy/views_plugin_argument_validate_taxonomy_term.inc',
            162 => 'modules/taxonomy/views_plugin_argument_default_taxonomy_tid.inc',
            163 => 'modules/tracker/views_handler_argument_tracker_comment_user_uid.inc',
            164 => 'modules/tracker/views_handler_filter_tracker_comment_user_uid.inc',
            165 => 'modules/tracker/views_handler_filter_tracker_boolean_operator.inc',
            166 => 'modules/system/views_handler_filter_system_type.inc',
            167 => 'modules/translation/views_handler_argument_node_tnid.inc',
            168 => 'modules/translation/views_handler_field_node_link_translate.inc',
            169 => 'modules/translation/views_handler_field_node_translation_link.inc',
            170 => 'modules/translation/views_handler_filter_node_tnid.inc',
            171 => 'modules/translation/views_handler_filter_node_tnid_child.inc',
            172 => 'modules/translation/views_handler_relationship_translation.inc',
            173 => 'modules/user/views_handler_argument_user_uid.inc',
            174 => 'modules/user/views_handler_argument_users_roles_rid.inc',
            175 => 'modules/user/views_handler_field_user.inc',
            176 => 'modules/user/views_handler_field_user_language.inc',
            177 => 'modules/user/views_handler_field_user_link.inc',
            178 => 'modules/user/views_handler_field_user_link_cancel.inc',
            179 => 'modules/user/views_handler_field_user_link_edit.inc',
            180 => 'modules/user/views_handler_field_user_mail.inc',
            181 => 'modules/user/views_handler_field_user_name.inc',
            182 => 'modules/user/views_handler_field_user_permissions.inc',
            183 => 'modules/user/views_handler_field_user_picture.inc',
            184 => 'modules/user/views_handler_field_user_roles.inc',
            185 => 'modules/user/views_handler_filter_user_current.inc',
            186 => 'modules/user/views_handler_filter_user_name.inc',
            187 => 'modules/user/views_handler_filter_user_permissions.inc',
            188 => 'modules/user/views_handler_filter_user_roles.inc',
            189 => 'modules/user/views_plugin_argument_default_current_user.inc',
            190 => 'modules/user/views_plugin_argument_default_user.inc',
            191 => 'modules/user/views_plugin_argument_validate_user.inc',
            192 => 'modules/user/views_plugin_row_user_view.inc',
            193 => 'plugins/views_plugin_access.inc',
            194 => 'plugins/views_plugin_access_none.inc',
            195 => 'plugins/views_plugin_access_perm.inc',
            196 => 'plugins/views_plugin_access_role.inc',
            197 => 'plugins/views_plugin_argument_default.inc',
            198 => 'plugins/views_plugin_argument_default_php.inc',
            199 => 'plugins/views_plugin_argument_default_fixed.inc',
            200 => 'plugins/views_plugin_argument_default_raw.inc',
            201 => 'plugins/views_plugin_argument_validate.inc',
            202 => 'plugins/views_plugin_argument_validate_numeric.inc',
            203 => 'plugins/views_plugin_argument_validate_php.inc',
            204 => 'plugins/views_plugin_cache.inc',
            205 => 'plugins/views_plugin_cache_none.inc',
            206 => 'plugins/views_plugin_cache_time.inc',
            207 => 'plugins/views_plugin_display.inc',
            208 => 'plugins/views_plugin_display_attachment.inc',
            209 => 'plugins/views_plugin_display_block.inc',
            210 => 'plugins/views_plugin_display_default.inc',
            211 => 'plugins/views_plugin_display_embed.inc',
            212 => 'plugins/views_plugin_display_extender.inc',
            213 => 'plugins/views_plugin_display_feed.inc',
            214 => 'plugins/views_plugin_display_page.inc',
            215 => 'plugins/views_plugin_exposed_form_basic.inc',
            216 => 'plugins/views_plugin_exposed_form.inc',
            217 => 'plugins/views_plugin_exposed_form_input_required.inc',
            218 => 'plugins/views_plugin_localization_core.inc',
            219 => 'plugins/views_plugin_localization.inc',
            220 => 'plugins/views_plugin_localization_none.inc',
            221 => 'plugins/views_plugin_pager.inc',
            222 => 'plugins/views_plugin_pager_full.inc',
            223 => 'plugins/views_plugin_pager_mini.inc',
            224 => 'plugins/views_plugin_pager_none.inc',
            225 => 'plugins/views_plugin_pager_some.inc',
            226 => 'plugins/views_plugin_query.inc',
            227 => 'plugins/views_plugin_query_default.inc',
            228 => 'plugins/views_plugin_row.inc',
            229 => 'plugins/views_plugin_row_fields.inc',
            230 => 'plugins/views_plugin_row_rss_fields.inc',
            231 => 'plugins/views_plugin_style.inc',
            232 => 'plugins/views_plugin_style_default.inc',
            233 => 'plugins/views_plugin_style_grid.inc',
            234 => 'plugins/views_plugin_style_list.inc',
            235 => 'plugins/views_plugin_style_jump_menu.inc',
            236 => 'plugins/views_plugin_style_mapping.inc',
            237 => 'plugins/views_plugin_style_rss.inc',
            238 => 'plugins/views_plugin_style_summary.inc',
            239 => 'plugins/views_plugin_style_summary_jump_menu.inc',
            240 => 'plugins/views_plugin_style_summary_unformatted.inc',
            241 => 'plugins/views_plugin_style_table.inc',
            242 => 'tests/handlers/views_handlers.test',
            243 => 'tests/handlers/views_handler_area_text.test',
            244 => 'tests/handlers/views_handler_argument_null.test',
            245 => 'tests/handlers/views_handler_argument_string.test',
            246 => 'tests/handlers/views_handler_field.test',
            247 => 'tests/handlers/views_handler_field_boolean.test',
            248 => 'tests/handlers/views_handler_field_custom.test',
            249 => 'tests/handlers/views_handler_field_counter.test',
            250 => 'tests/handlers/views_handler_field_date.test',
            251 => 'tests/handlers/views_handler_field_file_extension.test',
            252 => 'tests/handlers/views_handler_field_file_size.test',
            253 => 'tests/handlers/views_handler_field_math.test',
            254 => 'tests/handlers/views_handler_field_url.test',
            255 => 'tests/handlers/views_handler_field_xss.test',
            256 => 'tests/handlers/views_handler_filter_combine.test',
            257 => 'tests/handlers/views_handler_filter_date.test',
            258 => 'tests/handlers/views_handler_filter_equality.test',
            259 => 'tests/handlers/views_handler_filter_in_operator.test',
            260 => 'tests/handlers/views_handler_filter_numeric.test',
            261 => 'tests/handlers/views_handler_filter_string.test',
            262 => 'tests/handlers/views_handler_sort_random.test',
            263 => 'tests/handlers/views_handler_sort_date.test',
            264 => 'tests/handlers/views_handler_sort.test',
            265 => 'tests/test_handlers/views_test_area_access.inc',
            266 => 'tests/test_plugins/views_test_plugin_access_test_dynamic.inc',
            267 => 'tests/test_plugins/views_test_plugin_access_test_static.inc',
            268 => 'tests/test_plugins/views_test_plugin_style_test_mapping.inc',
            269 => 'tests/plugins/views_plugin_display.test',
            270 => 'tests/styles/views_plugin_style_jump_menu.test',
            271 => 'tests/styles/views_plugin_style.test',
            272 => 'tests/styles/views_plugin_style_base.test',
            273 => 'tests/styles/views_plugin_style_mapping.test',
            274 => 'tests/styles/views_plugin_style_unformatted.test',
            275 => 'tests/views_access.test',
            276 => 'tests/views_analyze.test',
            277 => 'tests/views_basic.test',
            278 => 'tests/views_argument_default.test',
            279 => 'tests/views_argument_validator.test',
            280 => 'tests/views_exposed_form.test',
            281 => 'tests/field/views_fieldapi.test',
            282 => 'tests/views_glossary.test',
            283 => 'tests/views_groupby.test',
            284 => 'tests/views_handlers.test',
            285 => 'tests/views_module.test',
            286 => 'tests/views_pager.test',
            287 => 'tests/views_plugin_localization_test.inc',
            288 => 'tests/views_translatable.test',
            289 => 'tests/views_query.test',
            290 => 'tests/views_upgrade.test',
            291 => 'tests/views_test.views_default.inc',
            292 => 'tests/comment/views_handler_argument_comment_user_uid.test',
            293 => 'tests/comment/views_handler_filter_comment_user_uid.test',
            294 => 'tests/node/views_node_revision_relations.test',
            295 => 'tests/taxonomy/views_handler_relationship_node_term_data.test',
            296 => 'tests/user/views_handler_field_user_name.test',
            297 => 'tests/user/views_user_argument_default.test',
            298 => 'tests/user/views_user_argument_validate.test',
            299 => 'tests/user/views_user.test',
            300 => 'tests/views_cache.test',
            301 => 'tests/views_view.test',
            302 => 'tests/views_ui.test',
          ),
          'version' => '7.x-3.10',
          'project' => 'views',
          'datestamp' => '1423648085',
        ),
        'schema_version' => '7301',
        'project' => 'views',
        'version' => '7.x-3.10',
      ),
      'views_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/views/views_ui.module',
        'basename' => 'views_ui.module',
        'name' => 'views_ui',
        'info' => 
        array (
          'name' => 'Views UI',
          'description' => 'Administrative interface to views. Without this module, you cannot create or edit your views.',
          'package' => 'Views',
          'core' => '7.x',
          'configure' => 'admin/structure/views',
          'dependencies' => 
          array (
            0 => 'views',
          ),
          'files' => 
          array (
            0 => 'views_ui.module',
            1 => 'plugins/views_wizard/views_ui_base_views_wizard.class.php',
          ),
          'version' => '7.x-3.10',
          'project' => 'views',
          'datestamp' => '1423648085',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'views',
        'version' => '7.x-3.10',
      ),
      'feeds_et' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/feeds_et/feeds_et.module',
        'basename' => 'feeds_et.module',
        'name' => 'feeds_et',
        'info' => 
        array (
          'name' => 'Feeds: Entity Translation',
          'description' => 'Adds support for importing translations via Entity Translation.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'feeds',
            1 => 'entity_translation',
          ),
          'package' => 'Feeds',
          'files' => 
          array (
            0 => 'FeedsYoutubeParser.inc',
          ),
          'version' => '7.x-1.x-dev',
          'project' => 'feeds_et',
          'datestamp' => '1380578314',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'feeds_et',
        'version' => '7.x-1.x-dev',
      ),
      'xmlsitemap_menu' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/xmlsitemap/xmlsitemap_menu/xmlsitemap_menu.module',
        'basename' => 'xmlsitemap_menu.module',
        'name' => 'xmlsitemap_menu',
        'info' => 
        array (
          'name' => 'XML sitemap menu',
          'description' => 'Adds menu item links to the sitemap.',
          'package' => 'XML sitemap',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'xmlsitemap',
            1 => 'menu',
          ),
          'files' => 
          array (
            0 => 'xmlsitemap_menu.module',
            1 => 'xmlsitemap_menu.install',
            2 => 'xmlsitemap_menu.test',
          ),
          'version' => '7.x-2.2',
          'project' => 'xmlsitemap',
          'datestamp' => '1422607989',
          'php' => '5.2.4',
        ),
        'schema_version' => '6201',
        'project' => 'xmlsitemap',
        'version' => '7.x-2.2',
      ),
      'xmlsitemap_engines' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/xmlsitemap/xmlsitemap_engines/xmlsitemap_engines.module',
        'basename' => 'xmlsitemap_engines.module',
        'name' => 'xmlsitemap_engines',
        'info' => 
        array (
          'name' => 'XML sitemap engines',
          'description' => 'Submit the sitemap to search engines.',
          'package' => 'XML sitemap',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'xmlsitemap',
          ),
          'files' => 
          array (
            0 => 'xmlsitemap_engines.module',
            1 => 'xmlsitemap_engines.admin.inc',
            2 => 'xmlsitemap_engines.install',
            3 => 'tests/xmlsitemap_engines.test',
          ),
          'recommends' => 
          array (
            0 => 'site_verify',
          ),
          'configure' => 'admin/config/search/xmlsitemap/engines',
          'version' => '7.x-2.2',
          'project' => 'xmlsitemap',
          'datestamp' => '1422607989',
          'php' => '5.2.4',
        ),
        'schema_version' => '6202',
        'project' => 'xmlsitemap',
        'version' => '7.x-2.2',
      ),
      'xmlsitemap_custom' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/xmlsitemap/xmlsitemap_custom/xmlsitemap_custom.module',
        'basename' => 'xmlsitemap_custom.module',
        'name' => 'xmlsitemap_custom',
        'info' => 
        array (
          'name' => 'XML sitemap custom',
          'description' => 'Adds user configurable links to the sitemap.',
          'package' => 'XML sitemap',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'xmlsitemap',
          ),
          'files' => 
          array (
            0 => 'xmlsitemap_custom.module',
            1 => 'xmlsitemap_custom.admin.inc',
            2 => 'xmlsitemap_custom.install',
            3 => 'xmlsitemap_custom.test',
          ),
          'configure' => 'admin/config/search/xmlsitemap/custom',
          'version' => '7.x-2.2',
          'project' => 'xmlsitemap',
          'datestamp' => '1422607989',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'xmlsitemap',
        'version' => '7.x-2.2',
      ),
      'xmlsitemap_i18n' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/xmlsitemap/xmlsitemap_i18n/xmlsitemap_i18n.module',
        'basename' => 'xmlsitemap_i18n.module',
        'name' => 'xmlsitemap_i18n',
        'info' => 
        array (
          'name' => 'XML sitemap internationalization',
          'description' => 'Enables multilingual XML sitemaps.',
          'package' => 'XML sitemap',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'xmlsitemap',
            1 => 'i18n',
          ),
          'files' => 
          array (
            0 => 'xmlsitemap_i18n.module',
            1 => 'xmlsitemap_i18n.test',
          ),
          'version' => '7.x-2.2',
          'project' => 'xmlsitemap',
          'datestamp' => '1422607989',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'xmlsitemap',
        'version' => '7.x-2.2',
      ),
      'xmlsitemap_user' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/xmlsitemap/xmlsitemap_user/xmlsitemap_user.module',
        'basename' => 'xmlsitemap_user.module',
        'name' => 'xmlsitemap_user',
        'info' => 
        array (
          'name' => 'XML sitemap user',
          'description' => 'Adds user profile links to the sitemap.',
          'package' => 'XML sitemap',
          'dependencies' => 
          array (
            0 => 'xmlsitemap',
          ),
          'core' => '7.x',
          'files' => 
          array (
            0 => 'xmlsitemap_user.module',
            1 => 'xmlsitemap_user.install',
            2 => 'xmlsitemap_user.test',
          ),
          'version' => '7.x-2.2',
          'project' => 'xmlsitemap',
          'datestamp' => '1422607989',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'xmlsitemap',
        'version' => '7.x-2.2',
      ),
      'xmlsitemap_taxonomy' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/xmlsitemap/xmlsitemap_taxonomy/xmlsitemap_taxonomy.module',
        'basename' => 'xmlsitemap_taxonomy.module',
        'name' => 'xmlsitemap_taxonomy',
        'info' => 
        array (
          'name' => 'XML sitemap taxonomy',
          'description' => 'Add taxonomy term links to the sitemap.',
          'package' => 'XML sitemap',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'xmlsitemap',
            1 => 'taxonomy',
          ),
          'files' => 
          array (
            0 => 'xmlsitemap_taxonomy.module',
            1 => 'xmlsitemap_taxonomy.install',
            2 => 'xmlsitemap_taxonomy.test',
          ),
          'version' => '7.x-2.2',
          'project' => 'xmlsitemap',
          'datestamp' => '1422607989',
          'php' => '5.2.4',
        ),
        'schema_version' => '7200',
        'project' => 'xmlsitemap',
        'version' => '7.x-2.2',
      ),
      'xmlsitemap_node' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/xmlsitemap/xmlsitemap_node/xmlsitemap_node.module',
        'basename' => 'xmlsitemap_node.module',
        'name' => 'xmlsitemap_node',
        'info' => 
        array (
          'name' => 'XML sitemap node',
          'description' => 'Adds content links to the sitemap.',
          'package' => 'XML sitemap',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'xmlsitemap',
          ),
          'files' => 
          array (
            0 => 'xmlsitemap_node.module',
            1 => 'xmlsitemap_node.install',
            2 => 'xmlsitemap_node.test',
          ),
          'version' => '7.x-2.2',
          'project' => 'xmlsitemap',
          'datestamp' => '1422607989',
          'php' => '5.2.4',
        ),
        'schema_version' => '6201',
        'project' => 'xmlsitemap',
        'version' => '7.x-2.2',
      ),
      'xmlsitemap' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/xmlsitemap/xmlsitemap.module',
        'basename' => 'xmlsitemap.module',
        'name' => 'xmlsitemap',
        'info' => 
        array (
          'name' => 'XML sitemap',
          'description' => 'Creates an XML sitemap conforming to the <a href="http://sitemaps.org/">sitemaps.org protocol</a>.',
          'package' => 'XML sitemap',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'xmlsitemap.module',
            1 => 'xmlsitemap.inc',
            2 => 'xmlsitemap.admin.inc',
            3 => 'xmlsitemap.drush.inc',
            4 => 'xmlsitemap.generate.inc',
            5 => 'xmlsitemap.xmlsitemap.inc',
            6 => 'xmlsitemap.pages.inc',
            7 => 'xmlsitemap.install',
            8 => 'xmlsitemap.test',
          ),
          'recommends' => 
          array (
            0 => 'robotstxt',
          ),
          'configure' => 'admin/config/search/xmlsitemap',
          'version' => '7.x-2.2',
          'project' => 'xmlsitemap',
          'datestamp' => '1422607989',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7203',
        'project' => 'xmlsitemap',
        'version' => '7.x-2.2',
      ),
      'token' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/token/token.module',
        'basename' => 'token.module',
        'name' => 'token',
        'info' => 
        array (
          'name' => 'Token',
          'description' => 'Provides a user interface for the Token API and some missing core tokens.',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'token.test',
          ),
          'version' => '7.x-1.6',
          'project' => 'token',
          'datestamp' => '1425149060',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'token',
        'version' => '7.x-1.6',
      ),
      'date_repeat' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/date/date_repeat/date_repeat.module',
        'basename' => 'date_repeat.module',
        'name' => 'date_repeat',
        'info' => 
        array (
          'name' => 'Date Repeat API',
          'description' => 'A Date Repeat API to calculate repeating dates and times from iCal rules.',
          'dependencies' => 
          array (
            0 => 'date_api',
          ),
          'package' => 'Date/Time',
          'core' => '7.x',
          'php' => '5.2',
          'files' => 
          array (
            0 => 'tests/date_repeat.test',
            1 => 'tests/date_repeat_form.test',
          ),
          'version' => '7.x-2.8',
          'project' => 'date',
          'datestamp' => '1406653438',
        ),
        'schema_version' => 0,
        'project' => 'date',
        'version' => '7.x-2.8',
      ),
      'date_all_day' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/date/date_all_day/date_all_day.module',
        'basename' => 'date_all_day.module',
        'name' => 'date_all_day',
        'info' => 
        array (
          'name' => 'Date All Day',
          'description' => 'Adds \'All Day\' functionality to date fields, including an \'All Day\' theme and \'All Day\' checkboxes for the Date select and Date popup widgets.',
          'dependencies' => 
          array (
            0 => 'date_api',
            1 => 'date',
          ),
          'package' => 'Date/Time',
          'core' => '7.x',
          'version' => '7.x-2.8',
          'project' => 'date',
          'datestamp' => '1406653438',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'date',
        'version' => '7.x-2.8',
      ),
      'date_context' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/date/date_context/date_context.module',
        'basename' => 'date_context.module',
        'name' => 'date_context',
        'info' => 
        array (
          'name' => 'Date Context',
          'description' => 'Adds an option to the Context module to set a context condition based on the value of a date field.',
          'package' => 'Date/Time',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'date',
            1 => 'context',
          ),
          'files' => 
          array (
            0 => 'date_context.module',
            1 => 'plugins/date_context_date_condition.inc',
          ),
          'version' => '7.x-2.8',
          'project' => 'date',
          'datestamp' => '1406653438',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'date',
        'version' => '7.x-2.8',
      ),
      'date_tools' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/date/date_tools/date_tools.module',
        'basename' => 'date_tools.module',
        'name' => 'date_tools',
        'info' => 
        array (
          'name' => 'Date Tools',
          'description' => 'Tools to import and auto-create dates and calendars.',
          'dependencies' => 
          array (
            0 => 'date',
          ),
          'package' => 'Date/Time',
          'core' => '7.x',
          'configure' => 'admin/config/date/tools',
          'files' => 
          array (
            0 => 'tests/date_tools.test',
          ),
          'version' => '7.x-2.8',
          'project' => 'date',
          'datestamp' => '1406653438',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'date',
        'version' => '7.x-2.8',
      ),
      'date_views' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/date/date_views/date_views.module',
        'basename' => 'date_views.module',
        'name' => 'date_views',
        'info' => 
        array (
          'name' => 'Date Views',
          'description' => 'Views integration for date fields and date functionality.',
          'package' => 'Date/Time',
          'dependencies' => 
          array (
            0 => 'date_api',
            1 => 'views',
          ),
          'core' => '7.x',
          'php' => '5.2',
          'files' => 
          array (
            0 => 'includes/date_views_argument_handler.inc',
            1 => 'includes/date_views_argument_handler_simple.inc',
            2 => 'includes/date_views_filter_handler.inc',
            3 => 'includes/date_views_filter_handler_simple.inc',
            4 => 'includes/date_views.views.inc',
            5 => 'includes/date_views_plugin_pager.inc',
          ),
          'version' => '7.x-2.8',
          'project' => 'date',
          'datestamp' => '1406653438',
        ),
        'schema_version' => 0,
        'project' => 'date',
        'version' => '7.x-2.8',
      ),
      'date_popup' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/date/date_popup/date_popup.module',
        'basename' => 'date_popup.module',
        'name' => 'date_popup',
        'info' => 
        array (
          'name' => 'Date Popup',
          'description' => 'Enables jquery popup calendars and time entry widgets for selecting dates and times.',
          'dependencies' => 
          array (
            0 => 'date_api',
          ),
          'package' => 'Date/Time',
          'core' => '7.x',
          'configure' => 'admin/config/date/date_popup',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'themes/datepicker.1.7.css',
            ),
          ),
          'version' => '7.x-2.8',
          'project' => 'date',
          'datestamp' => '1406653438',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'date',
        'version' => '7.x-2.8',
      ),
      'date_migrate_example' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/date/date_migrate/date_migrate_example/date_migrate_example.module',
        'basename' => 'date_migrate_example.module',
        'name' => 'date_migrate_example',
        'info' => 
        array (
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'date',
            1 => 'date_repeat',
            2 => 'date_repeat_field',
            3 => 'features',
            4 => 'migrate',
          ),
          'description' => 'Examples of migrating with the Date module',
          'features' => 
          array (
            'field' => 
            array (
              0 => 'node-date_migrate_example-body',
              1 => 'node-date_migrate_example-field_date',
              2 => 'node-date_migrate_example-field_date_range',
              3 => 'node-date_migrate_example-field_date_repeat',
              4 => 'node-date_migrate_example-field_datestamp',
              5 => 'node-date_migrate_example-field_datestamp_range',
              6 => 'node-date_migrate_example-field_datetime',
              7 => 'node-date_migrate_example-field_datetime_range',
            ),
            'node' => 
            array (
              0 => 'date_migrate_example',
            ),
          ),
          'files' => 
          array (
            0 => 'date_migrate_example.migrate.inc',
          ),
          'name' => 'Date Migration Example',
          'package' => 'Features',
          'project' => 'date',
          'version' => '7.x-2.8',
          'datestamp' => '1406653438',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'date',
        'version' => '7.x-2.8',
      ),
      'date_repeat_field' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/date/date_repeat_field/date_repeat_field.module',
        'basename' => 'date_repeat_field.module',
        'name' => 'date_repeat_field',
        'info' => 
        array (
          'name' => 'Date Repeat Field',
          'description' => 'Creates the option of Repeating date fields and manages Date fields that use the Date Repeat API.',
          'dependencies' => 
          array (
            0 => 'date_api',
            1 => 'date',
            2 => 'date_repeat',
          ),
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'date_repeat_field.css',
            ),
          ),
          'package' => 'Date/Time',
          'core' => '7.x',
          'version' => '7.x-2.8',
          'project' => 'date',
          'datestamp' => '1406653438',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'date',
        'version' => '7.x-2.8',
      ),
      'date_api' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/date/date_api/date_api.module',
        'basename' => 'date_api.module',
        'name' => 'date_api',
        'info' => 
        array (
          'name' => 'Date API',
          'description' => 'A Date API that can be used by other modules.',
          'package' => 'Date/Time',
          'core' => '7.x',
          'php' => '5.2',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'date.css',
            ),
          ),
          'files' => 
          array (
            0 => 'date_api.module',
            1 => 'date_api_sql.inc',
          ),
          'version' => '7.x-2.8',
          'project' => 'date',
          'datestamp' => '1406653438',
          'dependencies' => 
          array (
          ),
        ),
        'schema_version' => '7001',
        'project' => 'date',
        'version' => '7.x-2.8',
      ),
      'date' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/date/date.module',
        'basename' => 'date.module',
        'name' => 'date',
        'info' => 
        array (
          'name' => 'Date',
          'description' => 'Makes date/time fields available.',
          'dependencies' => 
          array (
            0 => 'date_api',
          ),
          'package' => 'Date/Time',
          'core' => '7.x',
          'php' => '5.2',
          'files' => 
          array (
            0 => 'date.migrate.inc',
            1 => 'tests/date_api.test',
            2 => 'tests/date.test',
            3 => 'tests/date_field.test',
            4 => 'tests/date_migrate.test',
            5 => 'tests/date_validation.test',
            6 => 'tests/date_timezone.test',
          ),
          'version' => '7.x-2.8',
          'project' => 'date',
          'datestamp' => '1406653438',
        ),
        'schema_version' => '7005',
        'project' => 'date',
        'version' => '7.x-2.8',
      ),
      'language_cookie' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/language_cookie/language_cookie.module',
        'basename' => 'language_cookie.module',
        'name' => 'language_cookie',
        'info' => 
        array (
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'locale',
          ),
          'description' => 'Allows usage of cookies to remember the user\'s last language.',
          'name' => 'Language Cookie',
          'package' => 'Multilingual - Internationalization',
          'project' => 'language_cookie',
          'configure' => 'admin/config/regional/language/configure/cookie',
          'version' => '7.x-1.8',
          'datestamp' => '1386236019',
          'php' => '5.2.4',
        ),
        'schema_version' => '7170',
        'project' => 'language_cookie',
        'version' => '7.x-1.8',
      ),
      'xhprof_mongodb' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/xhprof/modules/xhprof_mongodb/xhprof_mongodb.module',
        'basename' => 'xhprof_mongodb.module',
        'name' => 'xhprof_mongodb',
        'info' => 
        array (
          'name' => 'XHProf MongoDB',
          'description' => 'UI for xhprof runs.',
          'package' => 'Development',
          'dependencies' => 
          array (
            0 => 'mongodb',
          ),
          'core' => '7.x',
          'files' => 
          array (
            0 => 'MongodbXHProfRuns.inc',
          ),
          'version' => '7.x-1.0-beta3',
          'project' => 'xhprof',
          'datestamp' => '1397947728',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'xhprof',
        'version' => '7.x-1.0-beta3',
      ),
      'xhprof' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/xhprof/xhprof.module',
        'basename' => 'xhprof.module',
        'name' => 'xhprof',
        'info' => 
        array (
          'name' => 'xhprof',
          'description' => 'Provides code profiling with XHProf integration.',
          'package' => 'Development',
          'core' => '7.x',
          'configure' => 'admin/config/development/xhprof',
          'files' => 
          array (
            0 => 'XHProfRunsInterface.inc',
            1 => 'XHProfRunsFile.inc',
          ),
          'version' => '7.x-1.0-beta3',
          'project' => 'xhprof',
          'datestamp' => '1397947728',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'xhprof',
        'version' => '7.x-1.0-beta3',
      ),
      'path_alias_xt' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/path_alias_xt/path_alias_xt.module',
        'basename' => 'path_alias_xt.module',
        'name' => 'path_alias_xt',
        'info' => 
        array (
          'name' => 'Extended Path Aliases',
          'description' => 'Automatically extend path aliases to include tabs, like <em>about-us/edit</em> for <em>node/123/edit</em>. Allow these aliases to be entered in page specification wild-cards, <em>about-us*</em>, e.g for block visibility.',
          'core' => '7.x',
          'configure' => 'admin/config/system/path_alias_xt',
          'version' => '7.x-1.2',
          'project' => 'path_alias_xt',
          'datestamp' => '1394573307',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7100',
        'project' => 'path_alias_xt',
        'version' => '7.x-1.2',
      ),
      'views_pivot' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/views_pivot/views_pivot.module',
        'basename' => 'views_pivot.module',
        'name' => 'views_pivot',
        'info' => 
        array (
          'name' => 'Pivot Tables for Views',
          'description' => 'Allows to output the result of a view as a pivot table.',
          'dependencies' => 
          array (
            0 => 'views',
          ),
          'package' => 'Views',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'views_plugin_style_pivot.inc',
          ),
          'version' => '7.x-1.0',
          'project' => 'views_pivot',
          'datestamp' => '1393834406',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'views_pivot',
        'version' => '7.x-1.0',
      ),
      'og_features' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og_features/og_features.module',
        'basename' => 'og_features.module',
        'name' => 'og_features',
        'info' => 
        array (
          'name' => 'Organic groups features',
          'description' => 'Turn features on and off within groups.',
          'package' => 'Organic groups',
          'dependencies' => 
          array (
            0 => 'og',
            1 => 'og_context',
            2 => 'og_ui',
          ),
          'core' => '7.x',
          'version' => '7.x-2.0-beta4',
          'project' => 'og_features',
          'datestamp' => '1386170013',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'og_features',
        'version' => '7.x-2.0-beta4',
      ),
      'ctools_plugin_example' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/ctools/ctools_plugin_example/ctools_plugin_example.module',
        'basename' => 'ctools_plugin_example.module',
        'name' => 'ctools_plugin_example',
        'info' => 
        array (
          'name' => 'Chaos Tools (CTools) Plugin Example',
          'description' => 'Shows how an external module can provide ctools plugins (for Panels, etc.).',
          'package' => 'Chaos tool suite',
          'version' => '7.x-1.7',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'panels',
            2 => 'page_manager',
            3 => 'advanced_help',
          ),
          'core' => '7.x',
          'project' => 'ctools',
          'datestamp' => '1426696183',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'ctools',
        'version' => '7.x-1.7',
      ),
      'ctools_access_ruleset' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/ctools/ctools_access_ruleset/ctools_access_ruleset.module',
        'basename' => 'ctools_access_ruleset.module',
        'name' => 'ctools_access_ruleset',
        'info' => 
        array (
          'name' => 'Custom rulesets',
          'description' => 'Create custom, exportable, reusable access rulesets for applications like Panels.',
          'core' => '7.x',
          'package' => 'Chaos tool suite',
          'version' => '7.x-1.7',
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          'project' => 'ctools',
          'datestamp' => '1426696183',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'ctools',
        'version' => '7.x-1.7',
      ),
      'views_content' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/ctools/views_content/views_content.module',
        'basename' => 'views_content.module',
        'name' => 'views_content',
        'info' => 
        array (
          'name' => 'Views content panes',
          'description' => 'Allows Views content to be used in Panels, Dashboard and other modules which use the CTools Content API.',
          'package' => 'Chaos tool suite',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'views',
          ),
          'core' => '7.x',
          'version' => '7.x-1.7',
          'files' => 
          array (
            0 => 'plugins/views/views_content_plugin_display_ctools_context.inc',
            1 => 'plugins/views/views_content_plugin_display_panel_pane.inc',
            2 => 'plugins/views/views_content_plugin_style_ctools_context.inc',
          ),
          'project' => 'ctools',
          'datestamp' => '1426696183',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'ctools',
        'version' => '7.x-1.7',
      ),
      'page_manager' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/ctools/page_manager/page_manager.module',
        'basename' => 'page_manager.module',
        'name' => 'page_manager',
        'info' => 
        array (
          'name' => 'Page manager',
          'description' => 'Provides a UI and API to manage pages within the site.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          'package' => 'Chaos tool suite',
          'version' => '7.x-1.7',
          'project' => 'ctools',
          'datestamp' => '1426696183',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'ctools',
        'version' => '7.x-1.7',
      ),
      'stylizer' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/ctools/stylizer/stylizer.module',
        'basename' => 'stylizer.module',
        'name' => 'stylizer',
        'info' => 
        array (
          'name' => 'Stylizer',
          'description' => 'Create custom styles for applications such as Panels.',
          'core' => '7.x',
          'package' => 'Chaos tool suite',
          'version' => '7.x-1.7',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'color',
          ),
          'project' => 'ctools',
          'datestamp' => '1426696183',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'ctools',
        'version' => '7.x-1.7',
      ),
      'ctools_custom_content' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/ctools/ctools_custom_content/ctools_custom_content.module',
        'basename' => 'ctools_custom_content.module',
        'name' => 'ctools_custom_content',
        'info' => 
        array (
          'name' => 'Custom content panes',
          'description' => 'Create custom, exportable, reusable content panes for applications like Panels.',
          'core' => '7.x',
          'package' => 'Chaos tool suite',
          'version' => '7.x-1.7',
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          'project' => 'ctools',
          'datestamp' => '1426696183',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'ctools',
        'version' => '7.x-1.7',
      ),
      'term_depth' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/ctools/term_depth/term_depth.module',
        'basename' => 'term_depth.module',
        'name' => 'term_depth',
        'info' => 
        array (
          'name' => 'Term Depth access',
          'description' => 'Controls access to context based upon term depth',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          'package' => 'Chaos tool suite',
          'version' => '7.x-1.7',
          'project' => 'ctools',
          'datestamp' => '1426696183',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'ctools',
        'version' => '7.x-1.7',
      ),
      'bulk_export' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/ctools/bulk_export/bulk_export.module',
        'basename' => 'bulk_export.module',
        'name' => 'bulk_export',
        'info' => 
        array (
          'name' => 'Bulk Export',
          'description' => 'Performs bulk exporting of data objects known about by Chaos tools.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          'package' => 'Chaos tool suite',
          'version' => '7.x-1.7',
          'project' => 'ctools',
          'datestamp' => '1426696183',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'ctools',
        'version' => '7.x-1.7',
      ),
      'ctools_ajax_sample' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/ctools/ctools_ajax_sample/ctools_ajax_sample.module',
        'basename' => 'ctools_ajax_sample.module',
        'name' => 'ctools_ajax_sample',
        'info' => 
        array (
          'name' => 'Chaos Tools (CTools) AJAX Example',
          'description' => 'Shows how to use the power of Chaos AJAX.',
          'package' => 'Chaos tool suite',
          'version' => '7.x-1.7',
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          'core' => '7.x',
          'project' => 'ctools',
          'datestamp' => '1426696183',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'ctools',
        'version' => '7.x-1.7',
      ),
      'ctools' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/ctools/ctools.module',
        'basename' => 'ctools.module',
        'name' => 'ctools',
        'info' => 
        array (
          'name' => 'Chaos tools',
          'description' => 'A library of helpful tools by Merlin of Chaos.',
          'core' => '7.x',
          'package' => 'Chaos tool suite',
          'version' => '7.x-1.7',
          'files' => 
          array (
            0 => 'includes/context.inc',
            1 => 'includes/css-cache.inc',
            2 => 'includes/math-expr.inc',
            3 => 'includes/stylizer.inc',
            4 => 'tests/css_cache.test',
          ),
          'project' => 'ctools',
          'datestamp' => '1426696183',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'ctools',
        'version' => '7.x-1.7',
      ),
      'comment_og' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/comment_og/comment_og.module',
        'basename' => 'comment_og.module',
        'name' => 'comment_og',
        'info' => 
        array (
          'name' => 'Organic Groups Comment',
          'description' => 'Allows comments to be posted to organic group posts with respect to membership and permissions',
          'dependencies' => 
          array (
            0 => 'og',
            1 => 'og_context',
            2 => 'comment',
          ),
          'package' => 'Organic groups',
          'version' => '7.x-1.0',
          'core' => '7.x',
          'project' => 'comment_og',
          'datestamp' => '1340037680',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'comment_og',
        'version' => '7.x-1.0',
      ),
      'og_menu_single' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og_menu_single/og_menu_single.module',
        'basename' => 'og_menu_single.module',
        'name' => 'og_menu_single',
        'info' => 
        array (
          'name' => 'OG Menu Single',
          'description' => 'Provides a single custom menu per organic group',
          'dependencies' => 
          array (
            0 => 'menu',
            1 => 'og (2.x)',
            2 => 'og_context',
          ),
          'package' => 'Organic groups',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'tests/og_menu_singleBase.test',
          ),
          'version' => '7.x-1.0-beta2',
          'project' => 'og_menu_single',
          'datestamp' => '1415382781',
          'php' => '5.2.4',
        ),
        'schema_version' => '7102',
        'project' => 'og_menu_single',
        'version' => '7.x-1.0-beta2',
      ),
      'display_cache' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/display_cache/display_cache.module',
        'basename' => 'display_cache.module',
        'name' => 'display_cache',
        'info' => 
        array (
          'name' => 'Display Cache',
          'description' => 'Provides views and panels plugins to display rendered entities from cache.',
          'package' => 'Performance',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'entity',
          ),
          'version' => '7.x-1.0',
          'project' => 'display_cache',
          'datestamp' => '1399555728',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'display_cache',
        'version' => '7.x-1.0',
      ),
      'entityreference_autocomplete' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/entityreference_autocomplete/entityreference_autocomplete.module',
        'basename' => 'entityreference_autocomplete.module',
        'name' => 'entityreference_autocomplete',
        'info' => 
        array (
          'name' => 'Entity Reference Autocomplete',
          'description' => 'A Form API element type to reference arbitrary entities through an autocomplete textfield',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'entity',
          ),
          'version' => '7.x-1.8',
          'project' => 'entityreference_autocomplete',
          'datestamp' => '1414230230',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'entityreference_autocomplete',
        'version' => '7.x-1.8',
      ),
      'og_variables' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og_variables/og_variables.module',
        'basename' => 'og_variables.module',
        'name' => 'og_variables',
        'info' => 
        array (
          'name' => 'OG Variables',
          'description' => 'Allows for per group variables',
          'package' => 'Organic Groups',
          'core' => '7.x',
          'php' => '5.1',
          'dependencies' => 
          array (
            0 => 'variable_store (7.x-2.x)',
            1 => 'variable_realm (7.x-2.x)',
            2 => 'og_ui',
            3 => 'og_context',
            4 => 'entity',
          ),
          'files' => 
          array (
            0 => 'og_variables.class.inc',
          ),
          'version' => '7.x-1.0-beta2',
          'project' => 'og_variables',
          'datestamp' => '1420006381',
        ),
        'schema_version' => 0,
        'project' => 'og_variables',
        'version' => '7.x-1.0-beta2',
      ),
      'fieldable_panels_panes' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/fieldable_panels_panes/fieldable_panels_panes.module',
        'basename' => 'fieldable_panels_panes.module',
        'name' => 'fieldable_panels_panes',
        'info' => 
        array (
          'name' => 'Fieldable Panels Panes',
          'description' => 'Allow the creation of fieldable panels pane entities.',
          'package' => 'Panels',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'panels',
            1 => 'views',
          ),
          'files' => 
          array (
            0 => 'includes/PanelsPaneController.class.php',
            1 => 'includes/translation.handler.fieldable_panels_pane.inc',
            2 => 'plugins/views/fieldable_panels_panes_handler_argument_bundle.inc',
            3 => 'plugins/views/fieldable_panels_panes_handler_field_bundle.inc',
            4 => 'plugins/views/fieldable_panels_panes_handler_field_delete_entity.inc',
            5 => 'plugins/views/fieldable_panels_panes_handler_field_edit_entity.inc',
            6 => 'plugins/views/fieldable_panels_panes_handler_field_view_entity.inc',
            7 => 'plugins/views/fieldable_panels_panes_handler_filter_bundle.inc',
            8 => 'plugins/views/fieldable_panels_panes_handler_field_delete_revision.inc',
            9 => 'plugins/views/fieldable_panels_panes_handler_field_edit_revision.inc',
            10 => 'plugins/views/fieldable_panels_panes_handler_field_view_revision.inc',
            11 => 'plugins/views/fieldable_panels_panes_handler_field_is_current.inc',
            12 => 'plugins/views/fieldable_panels_panes_handler_field_make_current.inc',
          ),
          'version' => '7.x-1.5',
          'project' => 'fieldable_panels_panes',
          'datestamp' => '1377539790',
          'php' => '5.2.4',
        ),
        'schema_version' => '7107',
        'project' => 'fieldable_panels_panes',
        'version' => '7.x-1.5',
      ),
      'j2h' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/j2h/j2h.module',
        'basename' => 'j2h.module',
        'name' => 'j2h',
        'info' => 
        array (
          'name' => 'Json 2 human',
          'description' => 'Get external data (generated by API\'s) and show that in tables, lists or raw html',
          'package' => 'Humanitarian Response',
          'core' => '7.x',
          'scripts' => 
          array (
            0 => 'j2h.js',
          ),
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'j2h.css',
            ),
          ),
          'dependencies' => 
          array (
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'visualization' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/visualization/visualization.module',
        'basename' => 'visualization.module',
        'name' => 'visualization',
        'info' => 
        array (
          'name' => 'Visualization',
          'description' => 'Provides a theming hook and display plugin for Views that provides charting capabilities.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          ': Interface for plugins
files' => 
          array (
            0 => 'includes/interfaces.inc',
          ),
          'files' => 
          array (
            0 => 'includes/views/visualization_plugin_style.inc',
          ),
          'scripts' => 
          array (
            0 => 'js/visualization.js',
          ),
          'configure' => 'admin/config/system/visualization',
          'version' => '7.x-1.0-beta1',
          'project' => 'visualization',
          'datestamp' => '1427407684',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'visualization',
        'version' => '7.x-1.0-beta1',
      ),
      'og_moderation' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og_moderation/og_moderation.module',
        'basename' => 'og_moderation.module',
        'name' => 'og_moderation',
        'info' => 
        array (
          'name' => 'Organic groups moderation',
          'description' => 'Enable access control for publishing options and revision of group content.',
          'core' => '7.x',
          'package' => 'Organic groups',
          'dependencies' => 
          array (
            0 => 'og',
          ),
          'version' => '7.x-2.3',
          'project' => 'og_moderation',
          'datestamp' => '1396518250',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'og_moderation',
        'version' => '7.x-2.3',
      ),
      'job_scheduler_trigger' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/job_scheduler/modules/job_scheduler_trigger/job_scheduler_trigger.module',
        'basename' => 'job_scheduler_trigger.module',
        'name' => 'job_scheduler_trigger',
        'info' => 
        array (
          'name' => 'Job Scheduler Trigger',
          'description' => 'Creates scheduler triggers that fire up at certain days, times',
          'core' => '7.x',
          'php' => '5.2',
          'dependencies' => 
          array (
            0 => 'job_scheduler',
          ),
          'version' => '7.x-2.0-alpha3',
          'project' => 'job_scheduler',
          'datestamp' => '1336466457',
        ),
        'schema_version' => 0,
        'project' => 'job_scheduler',
        'version' => '7.x-2.0-alpha3',
      ),
      'job_scheduler' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/job_scheduler/job_scheduler.module',
        'basename' => 'job_scheduler.module',
        'name' => 'job_scheduler',
        'info' => 
        array (
          'name' => 'Job Scheduler',
          'description' => 'Scheduler API',
          'files' => 
          array (
            0 => 'job_scheduler.module',
            1 => 'job_scheduler.install',
            2 => 'JobScheduler.inc',
            3 => 'JobSchedulerCronTab.inc',
          ),
          'core' => '7.x',
          'php' => '5.2',
          'version' => '7.x-2.0-alpha3',
          'project' => 'job_scheduler',
          'datestamp' => '1336466457',
          'dependencies' => 
          array (
          ),
        ),
        'schema_version' => '7101',
        'project' => 'job_scheduler',
        'version' => '7.x-2.0-alpha3',
      ),
      'variable_views' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/variable/variable_views/variable_views.module',
        'basename' => 'variable_views.module',
        'name' => 'variable_views',
        'info' => 
        array (
          'name' => 'Variable views',
          'description' => 'Provides views integration for variable, included a default variable argument.',
          'dependencies' => 
          array (
            0 => 'variable',
            1 => 'views',
          ),
          'package' => 'Variable',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'includes/views_plugin_argument_default_variable.inc',
            1 => 'includes/views_handler_field_variable_title.inc',
            2 => 'includes/views_handler_field_variable_value.inc',
          ),
          'version' => '7.x-2.5',
          'project' => 'variable',
          'datestamp' => '1398250128',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'variable',
        'version' => '7.x-2.5',
      ),
      'variable_store' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/variable/variable_store/variable_store.module',
        'basename' => 'variable_store.module',
        'name' => 'variable_store',
        'info' => 
        array (
          'name' => 'Variable store',
          'description' => 'Database storage for variable realms. This is an API module.',
          'dependencies' => 
          array (
            0 => 'variable',
          ),
          'package' => 'Variable',
          'core' => '7.x',
          'version' => '7.x-2.5',
          'files' => 
          array (
            0 => 'variable_store.class.inc',
            1 => 'variable_store.test',
          ),
          'project' => 'variable',
          'datestamp' => '1398250128',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'variable',
        'version' => '7.x-2.5',
      ),
      'variable_example' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/variable/variable_example/variable_example.module',
        'basename' => 'variable_example.module',
        'name' => 'variable_example',
        'info' => 
        array (
          'name' => 'Variable example',
          'description' => 'An example module showing how to use the Variable API and providing some variables.',
          'dependencies' => 
          array (
            0 => 'variable',
            1 => 'variable_store',
          ),
          'package' => 'Example modules',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'variable_example.variable.inc',
          ),
          'version' => '7.x-2.5',
          'project' => 'variable',
          'datestamp' => '1398250128',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'variable',
        'version' => '7.x-2.5',
      ),
      'variable_admin' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/variable/variable_admin/variable_admin.module',
        'basename' => 'variable_admin.module',
        'name' => 'variable_admin',
        'info' => 
        array (
          'name' => 'Variable admin',
          'description' => 'Variable Administration UI',
          'dependencies' => 
          array (
            0 => 'variable',
          ),
          'package' => 'Variable',
          'core' => '7.x',
          'version' => '7.x-2.5',
          'project' => 'variable',
          'datestamp' => '1398250128',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'variable',
        'version' => '7.x-2.5',
      ),
      'variable_realm' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/variable/variable_realm/variable_realm.module',
        'basename' => 'variable_realm.module',
        'name' => 'variable_realm',
        'info' => 
        array (
          'name' => 'Variable realm',
          'description' => 'API to use variable realms from different modules',
          'dependencies' => 
          array (
            0 => 'variable',
          ),
          'package' => 'Variable',
          'core' => '7.x',
          'version' => '7.x-2.5',
          'files' => 
          array (
            0 => 'variable_realm.class.inc',
            1 => 'variable_realm_union.class.inc',
          ),
          'project' => 'variable',
          'datestamp' => '1398250128',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'variable',
        'version' => '7.x-2.5',
      ),
      'variable' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/variable/variable.module',
        'basename' => 'variable.module',
        'name' => 'variable',
        'info' => 
        array (
          'name' => 'Variable',
          'description' => 'Variable Information and basic variable API',
          'package' => 'Variable',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'includes/forum.variable.inc',
            1 => 'includes/locale.variable.inc',
            2 => 'includes/menu.variable.inc',
            3 => 'includes/node.variable.inc',
            4 => 'includes/system.variable.inc',
            5 => 'includes/taxonomy.variable.inc',
            6 => 'includes/translation.variable.inc',
            7 => 'includes/user.variable.inc',
            8 => 'variable.test',
          ),
          'version' => '7.x-2.5',
          'project' => 'variable',
          'datestamp' => '1398250128',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'variable',
        'version' => '7.x-2.5',
      ),
      'proj4js' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/proj4js/proj4js.module',
        'basename' => 'proj4js.module',
        'name' => 'proj4js',
        'info' => 
        array (
          'name' => 'Proj4JS',
          'description' => 'Proj4JS library loader.',
          'version' => '7.x-1.2',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'libraries',
          ),
          'project' => 'proj4js',
          'datestamp' => '1363209312',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'proj4js',
        'version' => '7.x-1.2',
      ),
      'views_geojson' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/views_geojson/views_geojson.module',
        'basename' => 'views_geojson.module',
        'name' => 'views_geojson',
        'info' => 
        array (
          'name' => 'GeoJSON',
          'description' => 'Provides a Views feed style for GeoJSON output.',
          'package' => 'Views',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'views/views_plugin_style_geojson.inc',
            1 => 'views/views_geojson_bbox_argument.inc',
            2 => 'views/views_plugin_argument_default_bboxquery.inc',
          ),
          'dependencies' => 
          array (
            0 => 'views',
            1 => 'geophp',
          ),
          'version' => '7.x-1.0-beta1',
          'project' => 'views_geojson',
          'datestamp' => '1425111782',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'views_geojson',
        'version' => '7.x-1.0-beta1',
      ),
      'lazy_panelizer' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/lazy_panelizer/lazy_panelizer.module',
        'basename' => 'lazy_panelizer.module',
        'name' => 'lazy_panelizer',
        'info' => 
        array (
          'name' => 'Lazy Panelizer',
          'description' => 'Improves panels performance by lazy loading panels.',
          'package' => 'Panels',
          'dependencies' => 
          array (
            0 => 'panels',
            1 => 'ctools',
            2 => 'page_manager',
          ),
          'core' => '7.x',
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'http_client_oauth' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/http_client/http_client_oauth.module',
        'basename' => 'http_client_oauth.module',
        'name' => 'http_client_oauth',
        'info' => 
        array (
          'name' => 'Http Client OAuth',
          'description' => 'Provides a OAuth authentication mechanism for the Http Client',
          'dependencies' => 
          array (
            0 => 'oauth_common',
            1 => 'http_client',
          ),
          'files' => 
          array (
            0 => 'includes/HttpClientOAuth.inc',
          ),
          'package' => 'Services - clients',
          'core' => '7.x',
          'version' => '7.x-2.4',
          'project' => 'http_client',
          'datestamp' => '1345646840',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'http_client',
        'version' => '7.x-2.4',
      ),
      'http_client' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/http_client/http_client.module',
        'basename' => 'http_client.module',
        'name' => 'http_client',
        'info' => 
        array (
          'name' => 'Http Client',
          'description' => 'Provides a Http client for use with the services Http server',
          'files' => 
          array (
            0 => 'includes/HttpClient.inc',
            1 => 'includes/HttpClientXMLFormatter.inc',
            2 => 'includes/HttpClientCurlDelegate.inc',
          ),
          'package' => 'Services - clients',
          'core' => '7.x',
          'version' => '7.x-2.4',
          'project' => 'http_client',
          'datestamp' => '1345646840',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'http_client',
        'version' => '7.x-2.4',
      ),
      'connector_action_default_register_form' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/connector/modules/connector_action_default_register_form/connector_action_default_register_form.module',
        'basename' => 'connector_action_default_register_form.module',
        'name' => 'connector_action_default_register_form',
        'info' => 
        array (
          'name' => 'Connector Action Default Register Form',
          'description' => 'Adepts the default action for new accounts.',
          'core' => '7.x',
          'package' => 'Connector Action',
          'dependencies' => 
          array (
            0 => 'connector',
          ),
          'version' => '7.x-1.0-beta2',
          'project' => 'connector',
          'datestamp' => '1361736072',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'connector',
        'version' => '7.x-1.0-beta2',
      ),
      'connector' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/connector/connector.module',
        'basename' => 'connector.module',
        'name' => 'connector',
        'info' => 
        array (
          'name' => 'Connector',
          'description' => 'Provides base functionality for one-click login with eg. Facebook Connect and Twitter Connect',
          'core' => '7.x',
          'package' => 'Connector',
          'version' => '7.x-1.0-beta2',
          'project' => 'connector',
          'datestamp' => '1361736072',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'connector',
        'version' => '7.x-1.0-beta2',
      ),
      'features' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/features/features.module',
        'basename' => 'features.module',
        'name' => 'features',
        'info' => 
        array (
          'name' => 'Features',
          'description' => 'Provides feature management for Drupal.',
          'core' => '7.x',
          'package' => 'Features',
          'files' => 
          array (
            0 => 'tests/features.test',
          ),
          'configure' => 'admin/structure/features/settings',
          'version' => '7.x-2.5',
          'project' => 'features',
          'datestamp' => '1428944073',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '6101',
        'project' => 'features',
        'version' => '7.x-2.5',
      ),
      'image_resize_filter' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/image_resize_filter/image_resize_filter.module',
        'basename' => 'image_resize_filter.module',
        'name' => 'image_resize_filter',
        'info' => 
        array (
          'name' => 'Image resize filter',
          'description' => 'Filter to automatically scale images to their height and width dimensions.',
          'core' => '7.x',
          'package' => 'Input filters',
          'configure' => 'admin/config/content/formats',
          'version' => '7.x-1.14',
          'project' => 'image_resize_filter',
          'datestamp' => '1392161952',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'image_resize_filter',
        'version' => '7.x-1.14',
      ),
      'panels_bootstrap_layouts' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/panels_bootstrap_layouts/panels_bootstrap_layouts.module',
        'basename' => 'panels_bootstrap_layouts.module',
        'name' => 'panels_bootstrap_layouts',
        'info' => 
        array (
          'name' => 'Panels Bootstrap Layouts',
          'description' => 'Panel\'s layouts using twitter bootstrap layout system as base.',
          'package' => 'Panels',
          'dependencies' => 
          array (
            0 => 'panels',
          ),
          'core' => '7.x',
          'version' => '7.x-3.0+12-dev',
          'project' => 'panels_bootstrap_layouts',
          'datestamp' => '1428934685',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'panels_bootstrap_layouts',
        'version' => '7.x-3.0+12-dev',
      ),
      'libraries' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/libraries/libraries.module',
        'basename' => 'libraries.module',
        'name' => 'libraries',
        'info' => 
        array (
          'name' => 'Libraries',
          'description' => 'Allows version-dependent and shared usage of external libraries.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'system (>=7.11)',
          ),
          'files' => 
          array (
            0 => 'tests/libraries.test',
          ),
          'version' => '7.x-2.2',
          'project' => 'libraries',
          'datestamp' => '1391965716',
          'php' => '5.2.4',
        ),
        'schema_version' => '7200',
        'project' => 'libraries',
        'version' => '7.x-2.2',
      ),
      'smtp' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/smtp/smtp.module',
        'basename' => 'smtp.module',
        'name' => 'smtp',
        'info' => 
        array (
          'name' => 'SMTP Authentication Support',
          'description' => 'Allow for site emails to be sent through an SMTP server of your choice.',
          'core' => '7.x',
          'package' => 'Mail',
          'configure' => 'admin/config/system/smtp',
          'files' => 
          array (
            0 => 'smtp.mail.inc',
            1 => 'smtp.phpmailer.inc',
            2 => 'smtp.transport.inc',
          ),
          'version' => '7.x-1.2',
          'project' => 'smtp',
          'datestamp' => '1420662781',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7100',
        'project' => 'smtp',
        'version' => '7.x-1.2',
      ),
      'linkit' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/linkit/linkit.module',
        'basename' => 'linkit.module',
        'name' => 'linkit',
        'info' => 
        array (
          'name' => 'Linkit',
          'description' => 'Provides an easy interface for inserting links to internal content, files and external pages by providing autocomplete search for several WYSIWYG-editors.',
          'core' => '7.x',
          'configure' => 'admin/config/content/linkit',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'entity',
          ),
          'files' => 
          array (
            0 => 'plugins/plugin.class.php',
            1 => 'plugins/linkit_plugins/linkit-plugin-entity.class.php',
          ),
          'version' => '7.x-2.6',
          'project' => 'linkit',
          'datestamp' => '1362862214',
          'php' => '5.2.4',
        ),
        'schema_version' => '7203',
        'project' => 'linkit',
        'version' => '7.x-2.6',
      ),
      'facetapi_pretty_paths' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/facetapi_pretty_paths/facetapi_pretty_paths.module',
        'basename' => 'facetapi_pretty_paths.module',
        'name' => 'facetapi_pretty_paths',
        'info' => 
        array (
          'name' => 'Facet API Pretty Paths',
          'core' => '7.x',
          'description' => 'Enables pretty paths for searches with Facet API.',
          'dependencies' => 
          array (
            0 => 'facetapi',
          ),
          'package' => 'Search Toolkit',
          'files' => 
          array (
            0 => 'plugins/facetapi/url_processor_pretty_paths.inc',
            1 => 'plugins/base_path_provider/facetapi_pretty_paths_base_path_provider.inc',
            2 => 'plugins/base_path_provider/facetapi_pretty_paths_adapter_base_path_provider.inc',
            3 => 'plugins/base_path_provider/facetapi_pretty_paths_default_base_path_provider.inc',
            4 => 'plugins/coders/facetapi_pretty_paths_coder_default.inc',
            5 => 'plugins/coders/facetapi_pretty_paths_coder_taxonomy.inc',
            6 => 'plugins/coders/facetapi_pretty_paths_coder_taxonomy_pathauto.inc',
          ),
          'version' => '7.x-1.4',
          'project' => 'facetapi_pretty_paths',
          'datestamp' => '1427560985',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'facetapi_pretty_paths',
        'version' => '7.x-1.4',
      ),
      'i18n_panels' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/panels/i18n_panels/i18n_panels.module',
        'basename' => 'i18n_panels.module',
        'name' => 'i18n_panels',
        'info' => 
        array (
          'name' => 'Panels translation',
          'description' => 'Supports translatable panels items.',
          'dependencies' => 
          array (
            0 => 'i18n',
            1 => 'panels',
            2 => 'i18n_string',
            3 => 'i18n_translation',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'version' => '7.x-3.5',
          'project' => 'panels',
          'datestamp' => '1422472985',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'panels',
        'version' => '7.x-3.5',
      ),
      'panels_node' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/panels/panels_node/panels_node.module',
        'basename' => 'panels_node.module',
        'name' => 'panels_node',
        'info' => 
        array (
          'name' => 'Panel nodes',
          'description' => 'Create nodes that are divided into areas with selectable content.',
          'package' => 'Panels',
          'version' => '7.x-3.5',
          'dependencies' => 
          array (
            0 => 'panels',
          ),
          'configure' => 'admin/structure/panels',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'panels_node.module',
          ),
          'project' => 'panels',
          'datestamp' => '1422472985',
          'php' => '5.2.4',
        ),
        'schema_version' => '6001',
        'project' => 'panels',
        'version' => '7.x-3.5',
      ),
      'panels_ipe' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/panels/panels_ipe/panels_ipe.module',
        'basename' => 'panels_ipe.module',
        'name' => 'panels_ipe',
        'info' => 
        array (
          'name' => 'Panels In-Place Editor',
          'description' => 'Provide a UI for managing some Panels directly on the frontend, instead of having to use the backend.',
          'package' => 'Panels',
          'version' => '7.x-3.5',
          'dependencies' => 
          array (
            0 => 'panels',
          ),
          'core' => '7.x',
          'configure' => 'admin/structure/panels',
          'files' => 
          array (
            0 => 'panels_ipe.module',
          ),
          'project' => 'panels',
          'datestamp' => '1422472985',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'panels',
        'version' => '7.x-3.5',
      ),
      'panels_mini' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/panels/panels_mini/panels_mini.module',
        'basename' => 'panels_mini.module',
        'name' => 'panels_mini',
        'info' => 
        array (
          'name' => 'Mini panels',
          'description' => 'Create mini panels that can be used as blocks by Drupal and panes by other panel modules.',
          'package' => 'Panels',
          'version' => '7.x-3.5',
          'dependencies' => 
          array (
            0 => 'panels',
          ),
          'core' => '7.x',
          'files' => 
          array (
            0 => 'plugins/export_ui/panels_mini_ui.class.php',
          ),
          'project' => 'panels',
          'datestamp' => '1422472985',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'panels',
        'version' => '7.x-3.5',
      ),
      'panels' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/panels/panels.module',
        'basename' => 'panels.module',
        'name' => 'panels',
        'info' => 
        array (
          'name' => 'Panels',
          'description' => 'Core Panels display functions; provides no external UI, at least one other Panels module should be enabled.',
          'core' => '7.x',
          'package' => 'Panels',
          'version' => '7.x-3.5',
          'configure' => 'admin/structure/panels',
          'dependencies' => 
          array (
            0 => 'ctools (>1.5)',
          ),
          'files' => 
          array (
            0 => 'panels.module',
            1 => 'includes/common.inc',
            2 => 'includes/legacy.inc',
            3 => 'includes/plugins.inc',
            4 => 'plugins/views/panels_views_plugin_row_fields.inc',
          ),
          'project' => 'panels',
          'datestamp' => '1422472985',
          'php' => '5.2.4',
        ),
        'schema_version' => '7303',
        'project' => 'panels',
        'version' => '7.x-3.5',
      ),
      'admin_views' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/admin_views/admin_views.module',
        'basename' => 'admin_views.module',
        'name' => 'admin_views',
        'info' => 
        array (
          'name' => 'Administration views',
          'description' => 'Replaces all system object management pages in Drupal core with real views.',
          'package' => 'Administration',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'views',
            1 => 'views_bulk_operations (>=7.x-3.2)',
          ),
          'files' => 
          array (
            0 => 'plugins/views_plugin_display_system.inc',
            1 => 'plugins/views_plugin_access_menu.inc',
            2 => 'tests/admin_views.test',
          ),
          'version' => '7.x-1.4',
          'project' => 'admin_views',
          'datestamp' => '1424423598',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'admin_views',
        'version' => '7.x-1.4',
      ),
      'context_disable_context' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/context_disable_context/context_disable_context.module',
        'basename' => 'context_disable_context.module',
        'name' => 'context_disable_context',
        'info' => 
        array (
          'name' => 'Context disable context reaction',
          'dependencies' => 
          array (
            0 => 'context',
          ),
          'description' => 'Disable certain contexts by another context.',
          'package' => 'Context',
          'core' => '7.x',
          'version' => '7.x-3.0',
          'project' => 'context_disable_context',
          'datestamp' => '1349787369',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'context_disable_context',
        'version' => '7.x-3.0',
      ),
      'views_view_field' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/views_pdf/modules/views_view_field/views_view_field.module',
        'basename' => 'views_view_field.module',
        'name' => 'views_view_field',
        'info' => 
        array (
          'name' => 'Views Field',
          'description' => 'Views plugin to include a view as a field.',
          'dependencies' => 
          array (
            0 => 'views',
          ),
          'package' => 'Views',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'views_view_field_handler_include_view.inc',
          ),
          'version' => '7.x-1.4',
          'project' => 'views_pdf',
          'datestamp' => '1414683531',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'views_pdf',
        'version' => '7.x-1.4',
      ),
      'views_append' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/views_pdf/modules/views_append/views_append.module',
        'basename' => 'views_append.module',
        'name' => 'views_append',
        'info' => 
        array (
          'name' => 'Append View',
          'description' => 'Views plugin to include (download) a view as a field.',
          'dependencies' => 
          array (
            0 => 'views',
          ),
          'package' => 'Views',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'views_append_handler_append_view.inc',
          ),
          'version' => '7.x-1.4',
          'project' => 'views_pdf',
          'datestamp' => '1414683531',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'views_pdf',
        'version' => '7.x-1.4',
      ),
      'views_pdf' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/views_pdf/views_pdf.module',
        'basename' => 'views_pdf.module',
        'name' => 'views_pdf',
        'info' => 
        array (
          'name' => 'Views PDF Display',
          'description' => 'Views plugin to export a view as a PDF file.',
          'dependencies' => 
          array (
            0 => 'views',
            1 => 'jquery_update',
            2 => 'php',
          ),
          'package' => 'Views',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'views_pdf_plugin_display.inc',
            1 => 'views_pdf_plugin_style_table.inc',
            2 => 'views_pdf_plugin_style_unformatted.inc',
            3 => 'views_pdf_plugin_row_fields.inc',
            4 => 'field_plugins/views_pdf_handler_page_number.inc',
            5 => 'field_plugins/views_pdf_handler_page_break.inc',
          ),
          'version' => '7.x-1.4',
          'project' => 'views_pdf',
          'datestamp' => '1414683531',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'views_pdf',
        'version' => '7.x-1.4',
      ),
      'strongarm' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/strongarm/strongarm.module',
        'basename' => 'strongarm.module',
        'name' => 'strongarm',
        'info' => 
        array (
          'name' => 'Strongarm',
          'description' => 'Enforces variable values defined by modules that need settings set to operate properly.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'ctools',
          ),
          'files' => 
          array (
            0 => 'strongarm.admin.inc',
            1 => 'strongarm.install',
            2 => 'strongarm.module',
          ),
          'version' => '7.x-2.0',
          'project' => 'strongarm',
          'datestamp' => '1339604214',
          'php' => '5.2.4',
        ),
        'schema_version' => '7201',
        'project' => 'strongarm',
        'version' => '7.x-2.0',
      ),
      'linkchecker' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/linkchecker/linkchecker.module',
        'basename' => 'linkchecker.module',
        'name' => 'linkchecker',
        'info' => 
        array (
          'name' => 'Link checker',
          'description' => 'Periodically checks for broken links in node types, blocks and fields and reports the results.',
          'configure' => 'admin/config/content/linkchecker',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'linkchecker.drush.inc',
            1 => 'linkchecker.test',
          ),
          'version' => '7.x-1.2',
          'project' => 'linkchecker',
          'datestamp' => '1402132428',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7011',
        'project' => 'linkchecker',
        'version' => '7.x-1.2',
      ),
      'migrate_example_baseball' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/migrate/migrate_example_baseball/migrate_example_baseball.module',
        'basename' => 'migrate_example_baseball.module',
        'name' => 'migrate_example_baseball',
        'info' => 
        array (
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'features',
            1 => 'migrate',
            2 => 'number',
          ),
          'description' => 'Import baseball box scores.',
          'features' => 
          array (
            'field' => 
            array (
              0 => 'node-migrate_example_baseball-body',
              1 => 'node-migrate_example_baseball-field_attendance',
              2 => 'node-migrate_example_baseball-field_duration',
              3 => 'node-migrate_example_baseball-field_home_batters',
              4 => 'node-migrate_example_baseball-field_home_game_number',
              5 => 'node-migrate_example_baseball-field_home_pitcher',
              6 => 'node-migrate_example_baseball-field_home_score',
              7 => 'node-migrate_example_baseball-field_home_team',
              8 => 'node-migrate_example_baseball-field_outs',
              9 => 'node-migrate_example_baseball-field_park',
              10 => 'node-migrate_example_baseball-field_start_date',
              11 => 'node-migrate_example_baseball-field_visiting_batters',
              12 => 'node-migrate_example_baseball-field_visiting_pitcher',
              13 => 'node-migrate_example_baseball-field_visiting_score',
              14 => 'node-migrate_example_baseball-field_visiting_team',
            ),
            'node' => 
            array (
              0 => 'migrate_example_baseball',
            ),
          ),
          'files' => 
          array (
            0 => 'migrate_example_baseball.migrate.inc',
          ),
          'name' => 'migrate_example_baseball',
          'package' => 'Migration',
          'php' => '5.2.4',
          'version' => '7.x-2.7',
          'project' => 'migrate',
          'datestamp' => '1423521491',
        ),
        'schema_version' => '7201',
        'project' => 'migrate',
        'version' => '7.x-2.7',
      ),
      'migrate_example_oracle' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/migrate/migrate_example/migrate_example_oracle/migrate_example_oracle.module',
        'basename' => 'migrate_example_oracle.module',
        'name' => 'migrate_example_oracle',
        'info' => 
        array (
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'features',
            1 => 'image',
            2 => 'migrate',
          ),
          'description' => 'Content type supporting example of Oracle migration',
          'features' => 
          array (
            'field' => 
            array (
              0 => 'node-migrate_example_oracle-body',
              1 => 'node-migrate_example_oracle-field_mainimage',
            ),
            'node' => 
            array (
              0 => 'migrate_example_oracle',
            ),
          ),
          'files' => 
          array (
            0 => 'migrate_example_oracle.migrate.inc',
          ),
          'name' => 'Migrate example - Oracle',
          'package' => 'Migration',
          'project' => 'migrate',
          'version' => '7.x-2.7',
          'datestamp' => '1423521491',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'migrate',
        'version' => '7.x-2.7',
      ),
      'migrate_example' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/migrate/migrate_example/migrate_example.module',
        'basename' => 'migrate_example.module',
        'name' => 'migrate_example',
        'info' => 
        array (
          'name' => 'Migrate Example',
          'description' => 'Example migration data.',
          'package' => 'Migration',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'taxonomy',
            1 => 'image',
            2 => 'comment',
            3 => 'migrate',
            4 => 'list',
            5 => 'number',
          ),
          'files' => 
          array (
            0 => 'beer.inc',
            1 => 'wine.inc',
          ),
          'version' => '7.x-2.7',
          'project' => 'migrate',
          'datestamp' => '1423521491',
          'php' => '5.2.4',
        ),
        'schema_version' => '7007',
        'project' => 'migrate',
        'version' => '7.x-2.7',
      ),
      'migrate_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/migrate/migrate_ui/migrate_ui.module',
        'basename' => 'migrate_ui.module',
        'name' => 'migrate_ui',
        'info' => 
        array (
          'name' => 'Migrate UI',
          'description' => 'UI for managing migration processes',
          'package' => 'Migration',
          'configure' => 'admin/content/migrate/configure',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'migrate',
          ),
          'files' => 
          array (
            0 => 'migrate_ui.wizard.inc',
          ),
          'version' => '7.x-2.7',
          'project' => 'migrate',
          'datestamp' => '1423521491',
          'php' => '5.2.4',
        ),
        'schema_version' => '7202',
        'project' => 'migrate',
        'version' => '7.x-2.7',
      ),
      'migrate' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/migrate/migrate.module',
        'basename' => 'migrate.module',
        'name' => 'migrate',
        'info' => 
        array (
          'name' => 'Migrate',
          'description' => 'Import content from external sources',
          'package' => 'Migration',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'includes/base.inc',
            1 => 'includes/field_mapping.inc',
            2 => 'includes/migration.inc',
            3 => 'includes/destination.inc',
            4 => 'includes/exception.inc',
            5 => 'includes/group.inc',
            6 => 'includes/handler.inc',
            7 => 'includes/map.inc',
            8 => 'includes/source.inc',
            9 => 'includes/team.inc',
            10 => 'migrate.mail.inc',
            11 => 'plugins/destinations/block_custom.inc',
            12 => 'plugins/destinations/entity.inc',
            13 => 'plugins/destinations/term.inc',
            14 => 'plugins/destinations/user.inc',
            15 => 'plugins/destinations/node.inc',
            16 => 'plugins/destinations/comment.inc',
            17 => 'plugins/destinations/file.inc',
            18 => 'plugins/destinations/path.inc',
            19 => 'plugins/destinations/fields.inc',
            20 => 'plugins/destinations/poll.inc',
            21 => 'plugins/destinations/table.inc',
            22 => 'plugins/destinations/table_copy.inc',
            23 => 'plugins/destinations/menu.inc',
            24 => 'plugins/destinations/menu_links.inc',
            25 => 'plugins/destinations/statistics.inc',
            26 => 'plugins/destinations/variable.inc',
            27 => 'plugins/sources/csv.inc',
            28 => 'plugins/sources/db2.inc',
            29 => 'plugins/sources/files.inc',
            30 => 'plugins/sources/json.inc',
            31 => 'plugins/sources/list.inc',
            32 => 'plugins/sources/mongodb.inc',
            33 => 'plugins/sources/multiitems.inc',
            34 => 'plugins/sources/sql.inc',
            35 => 'plugins/sources/sqlmap.inc',
            36 => 'plugins/sources/mssql.inc',
            37 => 'plugins/sources/oracle.inc',
            38 => 'plugins/sources/spreadsheet.inc',
            39 => 'plugins/sources/xml.inc',
            40 => 'tests/import/options.test',
            41 => 'tests/plugins/destinations/comment.test',
            42 => 'tests/plugins/destinations/node.test',
            43 => 'tests/plugins/destinations/table.test',
            44 => 'tests/plugins/destinations/term.test',
            45 => 'tests/plugins/destinations/user.test',
            46 => 'tests/plugins/sources/xml.test',
          ),
          'version' => '7.x-2.7',
          'project' => 'migrate',
          'datestamp' => '1423521491',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7207',
        'project' => 'migrate',
        'version' => '7.x-2.7',
      ),
      'memcache_admin' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/memcache/memcache_admin/memcache_admin.module',
        'basename' => 'memcache_admin.module',
        'name' => 'memcache_admin',
        'info' => 
        array (
          'name' => 'Memcache Admin',
          'description' => 'Adds a User Interface to monitor the Memcache for this site.',
          'core' => '7.x',
          'package' => 'Performance and scalability',
          'configure' => 'admin/config/system/memcache',
          'version' => '7.x-1.5',
          'project' => 'memcache',
          'datestamp' => '1422088394',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'memcache',
        'version' => '7.x-1.5',
      ),
      'memcache' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/memcache/memcache.module',
        'basename' => 'memcache.module',
        'name' => 'memcache',
        'info' => 
        array (
          'name' => 'Memcache',
          'description' => 'High performance integration with memcache.',
          'package' => 'Performance and scalability',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'memcache.inc',
            1 => 'tests/memcache.test',
            2 => 'tests/memcache-session.test',
            3 => 'tests/memcache-lock.test',
          ),
          'version' => '7.x-1.5',
          'project' => 'memcache',
          'datestamp' => '1422088394',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'memcache',
        'version' => '7.x-1.5',
      ),
      'openlayers_ui' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/openlayers/modules/openlayers_ui/openlayers_ui.module',
        'basename' => 'openlayers_ui.module',
        'name' => 'openlayers_ui',
        'info' => 
        array (
          'name' => 'OpenLayers UI',
          'description' => 'Provides a user interface to manage OpenLayers maps.',
          'core' => '7.x',
          'package' => 'OpenLayers',
          'dependencies' => 
          array (
            0 => 'openlayers',
          ),
          'configure' => 'admin/structure/openlayers',
          'files' => 
          array (
            0 => 'openlayers_ui.module',
          ),
          'version' => '7.x-2.0-beta11+19-dev',
          'project' => 'openlayers',
          'datestamp' => '1425586389',
          'php' => '5.2.4',
        ),
        'schema_version' => '7201',
        'project' => 'openlayers',
        'version' => '7.x-2.0-beta11+19-dev',
      ),
      'openlayers_views' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/openlayers/modules/openlayers_views/openlayers_views.module',
        'basename' => 'openlayers_views.module',
        'name' => 'openlayers_views',
        'info' => 
        array (
          'name' => 'OpenLayers Views',
          'description' => 'Provides OpenLayers Views plugins.',
          'core' => '7.x',
          'package' => 'OpenLayers',
          'dependencies' => 
          array (
            0 => 'openlayers',
            1 => 'views',
            2 => 'geophp',
          ),
          'files' => 
          array (
            0 => 'openlayers_views.module',
            1 => 'views/openlayers_views.views.inc',
            2 => 'views/openlayers_views_style_map.inc',
            3 => 'views/openlayers_views_style_data.inc',
            4 => 'views/openlayers_views_style_data_image.inc',
            5 => 'views/openlayers_views_plugin_display_openlayers.inc',
            6 => 'views/openlayers_views_plugin_row_point.inc',
            7 => 'views/openlayers_views_plugin_row_bounding_box.inc',
            8 => 'views/openlayers_views_plugin_row_geometry.inc',
            9 => 'plugins/layer_types/openlayers_views_vector.inc',
            10 => 'plugins/layer_types/openlayers_views_image.inc',
          ),
          'version' => '7.x-2.0-beta11+19-dev',
          'project' => 'openlayers',
          'datestamp' => '1425586389',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'openlayers',
        'version' => '7.x-2.0-beta11+19-dev',
      ),
      'openlayers_test_example_feature' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/openlayers/tests/features/openlayers_test_example_feature/openlayers_test_example_feature.module',
        'basename' => 'openlayers_test_example_feature.module',
        'name' => 'openlayers_test_example_feature',
        'info' => 
        array (
          'name' => 'OpenLayers Test Example Feature',
          'description' => 'Feature to hold OpenLayers configuration example.',
          'core' => '7.x',
          'package' => 'OpenLayers',
          'php' => '5.2.4',
          'version' => '7.x-2.0-beta11+19-dev',
          'project' => 'openlayers',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'features',
            2 => 'field_sql_storage',
            3 => 'geofield',
            4 => 'node',
            5 => 'openlayers',
            6 => 'text',
            7 => 'views',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'openlayers:openlayers_maps:1',
              1 => 'views:views_default:3.0',
            ),
            'field' => 
            array (
              0 => 'node-openlayers_example_content-body',
              1 => 'node-openlayers_example_content-field_openlayers_example_input',
            ),
            'node' => 
            array (
              0 => 'openlayers_example_content',
            ),
            'openlayers_maps' => 
            array (
              0 => 'openlayers_test_openlayers_example_map',
            ),
            'views_view' => 
            array (
              0 => 'openlayers_example_data_overlay',
              1 => 'openlayers_example_map_display_view',
            ),
          ),
          'project status url' => 'http://drupal.org/project/openlayers',
          'datestamp' => '1425586389',
        ),
        'schema_version' => 0,
        'project' => 'openlayers',
        'version' => '7.x-2.0-beta11+19-dev',
      ),
      'openlayers' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/openlayers/openlayers.module',
        'basename' => 'openlayers.module',
        'name' => 'openlayers',
        'info' => 
        array (
          'name' => 'OpenLayers',
          'description' => 'OpenLayers base API module',
          'core' => '7.x',
          'package' => 'OpenLayers',
          'dependencies' => 
          array (
            0 => 'libraries (>=2.1)',
            1 => 'proj4js',
            2 => 'ctools',
            3 => 'file',
            4 => 'image',
          ),
          'files' => 
          array (
            0 => 'openlayers.module',
            1 => 'plugins/layer_types/openlayers_layer_type_bing.inc',
            2 => 'plugins/layer_types/openlayers_layer_type_cloudmade.inc',
            3 => 'plugins/layer_types/openlayers_layer_type_dummy.inc',
            4 => 'plugins/layer_types/openlayers_layer_type_geojson.inc',
            5 => 'plugins/layer_types/openlayers_layer_type_google.inc',
            6 => 'plugins/layer_types/openlayers_layer_type_gpx.inc',
            7 => 'plugins/layer_types/openlayers_layer_type_image.inc',
            8 => 'plugins/layer_types/openlayers_layer_type_kml.inc',
            9 => 'plugins/layer_types/openlayers_layer_type_maptiler.inc',
            10 => 'plugins/layer_types/openlayers_layer_type_osm.inc',
            11 => 'plugins/layer_types/openlayers_layer_type_pointgrid.inc',
            12 => 'plugins/layer_types/openlayers_layer_type_raw.inc',
            13 => 'plugins/layer_types/openlayers_layer_type_tms.inc',
            14 => 'plugins/layer_types/openlayers_layer_type_wms.inc',
            15 => 'plugins/layer_types/openlayers_layer_type_wmts.inc',
            16 => 'plugins/layer_types/openlayers_layer_type_xyz.inc',
          ),
          'version' => '7.x-2.0-beta11+19-dev',
          'project' => 'openlayers',
          'datestamp' => '1425586389',
          'php' => '5.2.4',
        ),
        'schema_version' => '7209',
        'project' => 'openlayers',
        'version' => '7.x-2.0-beta11+19-dev',
      ),
      'og_menu_default_links' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og_menu/contrib/og_menu_default_links/og_menu_default_links.module',
        'basename' => 'og_menu_default_links.module',
        'name' => 'og_menu_default_links',
        'info' => 
        array (
          'name' => 'OG Menu Default Links',
          'description' => 'Allows creation of default links when adding new groups (menus)',
          'files' => 
          array (
            0 => 'og_menu_default_links.module',
          ),
          'dependencies' => 
          array (
            0 => 'og_menu',
            1 => 'token',
          ),
          'configure' => 'admin/config/group/og_menu/default-links',
          'package' => 'Organic groups',
          'core' => '7.x',
          'version' => '7.x-3.0',
          'project' => 'og_menu',
          'datestamp' => '1418163415',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'og_menu',
        'version' => '7.x-3.0',
      ),
      'og_menu' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/og_menu/og_menu.module',
        'basename' => 'og_menu.module',
        'name' => 'og_menu',
        'info' => 
        array (
          'name' => 'OG Menu',
          'description' => 'Allow group creators and site admins to edit their own group menu.',
          'files' => 
          array (
            0 => 'og_menu.module',
          ),
          'dependencies' => 
          array (
            0 => 'menu',
            1 => 'og (2.x)',
            2 => 'og_ui',
            3 => 'og_context',
          ),
          'configure' => 'admin/config/group/og_menu',
          'package' => 'Organic groups',
          'core' => '7.x',
          'version' => '7.x-3.0',
          'project' => 'og_menu',
          'datestamp' => '1418163415',
          'php' => '5.2.4',
        ),
        'schema_version' => '7304',
        'project' => 'og_menu',
        'version' => '7.x-3.0',
      ),
      'profile2_page' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/profile2/contrib/profile2_page.module',
        'basename' => 'profile2_page.module',
        'name' => 'profile2_page',
        'info' => 
        array (
          'name' => 'Profile2 pages',
          'description' => 'Adds separate pages for viewing and editing profiles.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'profile2',
          ),
          'version' => '7.x-1.3+11-dev',
          'project' => 'profile2',
          'datestamp' => '1424344685',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'profile2',
        'version' => '7.x-1.3+11-dev',
      ),
      'profile2_og_access' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/profile2/contrib/profile2_og_access.module',
        'basename' => 'profile2_og_access.module',
        'name' => 'profile2_og_access',
        'info' => 
        array (
          'name' => 'Profile2 group access',
          'description' => 'Adds Organic groups permissions to control profile access on the group level.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'profile2',
            1 => 'og',
          ),
          'package' => 'Organic groups',
          'version' => '7.x-1.3+11-dev',
          'project' => 'profile2',
          'datestamp' => '1424344685',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'profile2',
        'version' => '7.x-1.3+11-dev',
      ),
      'profile2_i18n' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/profile2/contrib/profile2_i18n.module',
        'basename' => 'profile2_i18n.module',
        'name' => 'profile2_i18n',
        'info' => 
        array (
          'name' => 'Profile2 translation',
          'description' => 'Translate profile2 types.',
          'dependencies' => 
          array (
            0 => 'profile2',
            1 => 'i18n_string',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'version' => '7.x-1.3+11-dev',
          'project' => 'profile2',
          'datestamp' => '1424344685',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'profile2',
        'version' => '7.x-1.3+11-dev',
      ),
      'profile2' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/profile2/profile2.module',
        'basename' => 'profile2.module',
        'name' => 'profile2',
        'info' => 
        array (
          'name' => 'Profile2',
          'description' => 'Supports configurable user profiles.',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'profile2.admin.inc',
            1 => 'profile2.info.inc',
            2 => 'profile2.test',
          ),
          'dependencies' => 
          array (
            0 => 'entity',
          ),
          'configure' => 'admin/structure/profiles',
          'version' => '7.x-1.3+11-dev',
          'project' => 'profile2',
          'datestamp' => '1424344685',
          'php' => '5.2.4',
        ),
        'schema_version' => '7102',
        'project' => 'profile2',
        'version' => '7.x-1.3+11-dev',
      ),
      'media_wysiwyg_view_mode' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/media/modules/media_wysiwyg_view_mode/media_wysiwyg_view_mode.module',
        'basename' => 'media_wysiwyg_view_mode.module',
        'name' => 'media_wysiwyg_view_mode',
        'info' => 
        array (
          'name' => 'Media WYSIWYG View Mode',
          'description' => 'Enables files inside of the WYSIWYG editor to be displayed using a separate view mode.',
          'package' => 'Media',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'media_wysiwyg',
          ),
          'configure' => 'admin/config/media/wysiwyg-view-mode',
          'files' => 
          array (
            0 => 'media_wysiwyg_view_mode.test',
          ),
          'version' => '7.x-2.0-alpha4',
          'project' => 'media',
          'datestamp' => '1412422430',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'media',
        'version' => '7.x-2.0-alpha4',
      ),
      'mediafield' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/media/modules/mediafield/mediafield.module',
        'basename' => 'mediafield.module',
        'name' => 'mediafield',
        'info' => 
        array (
          'name' => 'Media Field',
          'description' => 'Provides a field type that stores media-specific data. <em>Deprecated by the core File field type.</em>',
          'package' => 'Media',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'media',
          ),
          'version' => '7.x-2.0-alpha4',
          'project' => 'media',
          'datestamp' => '1412422430',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'media',
        'version' => '7.x-2.0-alpha4',
      ),
      'media_bulk_upload' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/media/modules/media_bulk_upload/media_bulk_upload.module',
        'basename' => 'media_bulk_upload.module',
        'name' => 'media_bulk_upload',
        'info' => 
        array (
          'name' => 'Media Bulk Upload',
          'description' => 'Adds support for uploading multiple files at a time.',
          'package' => 'Media',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'media',
            1 => 'multiform',
            2 => 'plupload',
          ),
          'files' => 
          array (
            0 => 'includes/MediaBrowserBulkUpload.inc',
          ),
          'version' => '7.x-2.0-alpha4',
          'project' => 'media',
          'datestamp' => '1412422430',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'media',
        'version' => '7.x-2.0-alpha4',
      ),
      'media_internet' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/media/modules/media_internet/media_internet.module',
        'basename' => 'media_internet.module',
        'name' => 'media_internet',
        'info' => 
        array (
          'name' => 'Media Internet Sources',
          'description' => 'Provides an API for accessing media on various internet services',
          'package' => 'Media',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'media',
          ),
          'files' => 
          array (
            0 => 'includes/MediaBrowserInternet.inc',
            1 => 'includes/MediaInternetBaseHandler.inc',
            2 => 'includes/MediaInternetFileHandler.inc',
            3 => 'includes/MediaInternetNoHandlerException.inc',
            4 => 'includes/MediaInternetValidationException.inc',
            5 => 'tests/media_internet.test',
          ),
          'version' => '7.x-2.0-alpha4',
          'project' => 'media',
          'datestamp' => '1412422430',
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'media',
        'version' => '7.x-2.0-alpha4',
      ),
      'media_wysiwyg' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/media/modules/media_wysiwyg/media_wysiwyg.module',
        'basename' => 'media_wysiwyg.module',
        'name' => 'media_wysiwyg',
        'info' => 
        array (
          'name' => 'Media WYSIWYG',
          'description' => 'Adds support for embedding media using client-side WYSIWYG editors.',
          'package' => 'Media',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'media',
          ),
          'test_dependencies' => 
          array (
            0 => 'ckeditor',
            1 => 'token',
            2 => 'wysiwyg',
          ),
          'files' => 
          array (
            0 => 'media_wysiwyg.test',
            1 => 'tests/media_wysiwyg.file_usage.test',
            2 => 'tests/media_wysiwyg.macro.test',
          ),
          'configure' => 'admin/config/media/browser',
          'version' => '7.x-2.0-alpha4',
          'project' => 'media',
          'datestamp' => '1412422430',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'media',
        'version' => '7.x-2.0-alpha4',
      ),
      'media' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/media/media.module',
        'basename' => 'media.module',
        'name' => 'media',
        'info' => 
        array (
          'name' => 'Media',
          'description' => 'Provides the core Media API',
          'package' => 'Media',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'file_entity',
            1 => 'image',
            2 => 'views',
          ),
          'test_dependencies' => 
          array (
            0 => 'token',
          ),
          'files' => 
          array (
            0 => 'includes/MediaReadOnlyStreamWrapper.inc',
            1 => 'includes/MediaBrowserPluginInterface.inc',
            2 => 'includes/MediaBrowserPlugin.inc',
            3 => 'includes/MediaBrowserUpload.inc',
            4 => 'includes/MediaBrowserView.inc',
            5 => 'includes/MediaEntityTranslationHandler.inc',
            6 => 'includes/media_views_plugin_display_media_browser.inc',
            7 => 'includes/media_views_plugin_style_media_browser.inc',
            8 => 'tests/media.test',
          ),
          'configure' => 'admin/config/media/browser',
          'version' => '7.x-2.0-alpha4',
          'project' => 'media',
          'datestamp' => '1412422430',
          'php' => '5.2.4',
        ),
        'schema_version' => '7226',
        'project' => 'media',
        'version' => '7.x-2.0-alpha4',
      ),
      'radix_layouts' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/radix_layouts/radix_layouts.module',
        'basename' => 'radix_layouts.module',
        'name' => 'radix_layouts',
        'info' => 
        array (
          'name' => 'Radix Layouts',
          'description' => 'Responsive panels layouts set to work with Panopoly and the Radix theme',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'panels',
          ),
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'radix_layouts.css',
            ),
          ),
          'version' => '7.x-3.3',
          'project' => 'radix_layouts',
          'datestamp' => '1416259385',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'radix_layouts',
        'version' => '7.x-3.3',
      ),
      'httprl' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/httprl/httprl.module',
        'basename' => 'httprl.module',
        'name' => 'httprl',
        'info' => 
        array (
          'name' => 'HTTP Parallel Request Library',
          'description' => 'Send http requests out in parallel in a blocking or non-blocking manner.',
          'package' => 'Performance and scalability',
          'core' => '7.x',
          'version' => '7.x-1.14',
          'project' => 'httprl',
          'datestamp' => '1388542110',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'httprl',
        'version' => '7.x-1.14',
      ),
      'honeypot' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/honeypot/honeypot.module',
        'basename' => 'honeypot.module',
        'name' => 'honeypot',
        'info' => 
        array (
          'name' => 'Honeypot',
          'description' => 'Mitigates spam form submissions using the honeypot method.',
          'core' => '7.x',
          'configure' => 'admin/config/content/honeypot',
          'package' => 'Spam control',
          'files' => 
          array (
            0 => 'honeypot.test',
          ),
          'version' => '7.x-1.17',
          'project' => 'honeypot',
          'datestamp' => '1401478128',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7003',
        'project' => 'honeypot',
        'version' => '7.x-1.17',
      ),
      'securelogin' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/securelogin/securelogin.module',
        'basename' => 'securelogin.module',
        'name' => 'securelogin',
        'info' => 
        array (
          'name' => 'Secure Login',
          'description' => 'Enables user login and other forms to be submitted securely via HTTPS and enforces secure authenticated sessions.',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'securelogin.admin.inc',
            1 => 'securelogin.install',
            2 => 'securelogin.module',
          ),
          'configure' => 'admin/config/people/securelogin',
          'version' => '7.x-1.5',
          'project' => 'securelogin',
          'datestamp' => '1420710788',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7000',
        'project' => 'securelogin',
        'version' => '7.x-1.5',
      ),
      'save_draft' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/save_draft/save_draft.module',
        'basename' => 'save_draft.module',
        'name' => 'save_draft',
        'info' => 
        array (
          'name' => 'Save Draft',
          'description' => 'Adds a \'Save as Draft\' button to content types',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'save_draft.module',
            1 => 'save_draft.test',
          ),
          'version' => '7.x-1.4',
          'project' => 'save_draft',
          'datestamp' => '1303860116',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'save_draft',
        'version' => '7.x-1.4',
      ),
      'services_entityreference' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/services_entity/modules/services_entityreference/services_entityreference.module',
        'basename' => 'services_entityreference.module',
        'name' => 'services_entityreference',
        'info' => 
        array (
          'name' => 'Services Entity Reference',
          'description' => 'Automatically create relationships based on entity reference fields.',
          'package' => 'Services',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'services_entity',
          ),
          'version' => '7.x-2.0-alpha8',
          'project' => 'services_entity',
          'datestamp' => '1407747229',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'services_entity',
        'version' => '7.x-2.0-alpha8',
      ),
      'services_entity' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/services_entity/services_entity.module',
        'basename' => 'services_entity.module',
        'name' => 'services_entity',
        'info' => 
        array (
          'name' => 'Services Entity',
          'description' => 'Exposes entities to the Service API.',
          'package' => 'Services',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'services',
            1 => 'entity',
          ),
          'files' => 
          array (
            0 => 'tests/services_entity.test',
            1 => 'plugins/services_entity_interface.inc',
            2 => 'plugins/services_entity_abstract.inc',
            3 => 'plugins/services_entity_resource.inc',
            4 => 'plugins/services_entity_resource_clean.inc',
          ),
          'configure' => 'admin/config/services/services-entity',
          'version' => '7.x-2.0-alpha8',
          'project' => 'services_entity',
          'datestamp' => '1407747229',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'services_entity',
        'version' => '7.x-2.0-alpha8',
      ),
      'panels_content_cache' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/panels_content_cache/panels_content_cache.module',
        'basename' => 'panels_content_cache.module',
        'name' => 'panels_content_cache',
        'info' => 
        array (
          'name' => 'Panels Content Cache',
          'core' => '7.x',
          'package' => 'Panels',
          'description' => 'A content based caching plugin for panels. Allows panel caches to be expired based on content creation / updates.',
          'dependencies' => 
          array (
            0 => 'panels (>=3.4)',
          ),
          'version' => '7.x-1.2',
          'project' => 'panels_content_cache',
          'datestamp' => '1419347945',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'panels_content_cache',
        'version' => '7.x-1.2',
      ),
      'publishcontent' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/publishcontent/publishcontent.module',
        'basename' => 'publishcontent.module',
        'name' => 'publishcontent',
        'info' => 
        array (
          'name' => 'Publish Content',
          'description' => 'Adds a \'Publish\' or \'Unpublish\' link on the node edit/view pages, and a \'Publish Link\' field if the Views module is enabled.',
          'core' => '7.x',
          'configure' => 'admin/config/content/publishcontent',
          'files' => 
          array (
            0 => 'publishcontent_views_handler_field_node_link.inc',
            1 => 'tests/publishcontent.test',
          ),
          'version' => '7.x-1.3',
          'project' => 'publishcontent',
          'datestamp' => '1393372405',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'publishcontent',
        'version' => '7.x-1.3',
      ),
      'field_permissions' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/field_permissions/field_permissions.module',
        'basename' => 'field_permissions.module',
        'name' => 'field_permissions',
        'info' => 
        array (
          'name' => 'Field Permissions',
          'description' => 'Set field-level permissions to create, update or view fields.',
          'package' => 'Fields',
          'core' => '7.x',
          'files' => 
          array (
            0 => 'field_permissions.module',
            1 => 'field_permissions.admin.inc',
            2 => 'field_permissions.test',
          ),
          'configure' => 'admin/reports/fields/permissions',
          'version' => '7.x-1.0-beta2',
          'project' => 'field_permissions',
          'datestamp' => '1327510549',
          'dependencies' => 
          array (
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => '7001',
        'project' => 'field_permissions',
        'version' => '7.x-1.0-beta2',
      ),
      'field_collection' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/field_collection/field_collection.module',
        'basename' => 'field_collection.module',
        'name' => 'field_collection',
        'info' => 
        array (
          'name' => 'Field collection',
          'description' => 'Provides a field collection field, to which any number of fields can be attached.',
          'core' => '7.x',
          'dependencies' => 
          array (
            0 => 'entity',
          ),
          'files' => 
          array (
            0 => 'field_collection.test',
            1 => 'field_collection.info.inc',
            2 => 'views/field_collection_handler_relationship.inc',
            3 => 'field_collection.migrate.inc',
          ),
          'configure' => 'admin/structure/field-collections',
          'package' => 'Fields',
          'version' => '7.x-1.0-beta8',
          'project' => 'field_collection',
          'datestamp' => '1415122384',
          'php' => '5.2.4',
        ),
        'schema_version' => '7006',
        'project' => 'field_collection',
        'version' => '7.x-1.0-beta8',
      ),
      'facetapi_i18n' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/contrib/facetapi_i18n/facetapi_i18n.module',
        'basename' => 'facetapi_i18n.module',
        'name' => 'facetapi_i18n',
        'info' => 
        array (
          'name' => 'Facet API Translation',
          'description' => 'Integrates Facet API with the i18n module to translate custom strings and mapped facet values.',
          'dependencies' => 
          array (
            0 => 'i18n_string',
            1 => 'facetapi',
          ),
          'package' => 'Multilingual - Internationalization',
          'core' => '7.x',
          'version' => '7.x-1.0-beta2+2-dev',
          'project' => 'facetapi_i18n',
          'datestamp' => '1429267979',
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'facetapi_i18n',
        'version' => '7.x-1.0-beta2+2-dev',
      ),
      'acc_search' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/access/acc_search/acc_search.module',
        'basename' => 'acc_search.module',
        'name' => 'acc_search',
        'info' => 
        array (
          'name' => 'Access Search',
          'description' => 'Solr Search for Access',
          'core' => '7.x',
          'package' => 'Humanitarian Access',
          'dependencies' => 
          array (
            0 => 'ctools',
            1 => 'current_search',
            2 => 'entity',
            3 => 'facetapi',
            4 => 'search_api',
          ),
          'features' => 
          array (
            'ctools' => 
            array (
              0 => 'current_search:current_search:1',
              1 => 'facetapi:facetapi_defaults:1',
            ),
            'current_search' => 
            array (
              0 => 'acc_current_search',
            ),
            'facetapi' => 
            array (
              0 => 'search_api@acc_search::field_acc_date:value',
              1 => 'search_api@acc_search::field_acc_type',
              2 => 'search_api@acc_search:block:created',
              3 => 'search_api@acc_search:block:field_acc_application_types',
              4 => 'search_api@acc_search:block:field_acc_date:value',
              5 => 'search_api@acc_search:block:field_acc_geo_location_dest',
              6 => 'search_api@acc_search:block:field_acc_impacts:field_acc_impact_type',
              7 => 'search_api@acc_search:block:field_acc_impacts:field_acc_impact_value',
              8 => 'search_api@acc_search:block:field_acc_submission_status',
              9 => 'search_api@acc_search:block:field_acc_submitted_by',
              10 => 'search_api@acc_search:block:field_acc_submitted_by_org_type',
              11 => 'search_api@acc_search:block:field_acc_type',
              12 => 'search_api@acc_search:block:field_affected_organization_type',
              13 => 'search_api@acc_search:block:field_affected_organizations',
              14 => 'search_api@acc_search:block:field_bundles',
              15 => 'search_api@acc_search:block:field_date_app:value',
              16 => 'search_api@acc_search:block:field_if_denied_by_whom_',
              17 => 'search_api@acc_search:block:field_locations',
              18 => 'search_api@acc_search:block:field_nationality',
              19 => 'search_api@acc_search:block:field_responsible_actors',
              20 => 'search_api@acc_search:block:field_responsible_organization_t',
              21 => 'search_api@acc_search:block:field_submitted_to',
              22 => 'search_api@acc_search:block:field_type_of_affectee',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'search_api_index' => 
            array (
              0 => 'acc_search',
            ),
          ),
          'project path' => 'sites/all/modules/access',
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => '',
        'version' => NULL,
      ),
      'acc_users' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/access/acc_users/acc_users.module',
        'basename' => 'acc_users.module',
        'name' => 'acc_users',
        'info' => 
        array (
          'name' => 'Access Users',
          'description' => 'Provide OG Roles under Operations Group and Drupal Roles',
          'core' => '7.x',
          'package' => 'Humanitarian Access',
          'project' => 'acc_users',
          'dependencies' => 
          array (
            0 => 'features',
            1 => 'role_export',
            2 => 'og_access',
            3 => 'og_features',
            4 => 'og_role_delegate',
          ),
          'features' => 
          array (
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'og_features_role' => 
            array (
              0 => 'node:hr_operation:access-editor',
              1 => 'node:hr_operation:access-manager',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'role_export' => 'role_export',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'acc_users',
        'version' => NULL,
      ),
      'acc_applications' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/access/acc_applications/acc_applications.module',
        'basename' => 'acc_applications.module',
        'name' => 'acc_applications',
        'info' => 
        array (
          'name' => 'Access Applications',
          'description' => 'Humanitarian Access Applications Content Type, Views, Context, Map',
          'core' => '7.x',
          'package' => 'Humanitarian Access',
          'version' => '7.x-2.0',
          'project' => 'acc_applications',
          'dependencies' => 
          array (
            0 => 'acc_incidents',
            1 => 'context',
            2 => 'ctools',
            3 => 'date',
            4 => 'entity',
            5 => 'entityreference',
            6 => 'features',
            7 => 'feeds',
            8 => 'feeds_tamper',
            9 => 'field_collection',
            10 => 'file',
            11 => 'hr_core',
            12 => 'hr_locations',
            13 => 'hr_sectors',
            14 => 'list',
            15 => 'number',
            16 => 'og',
            17 => 'og_context',
            18 => 'og_ui',
            19 => 'openlayers_views',
            20 => 'options',
            21 => 'shs',
            22 => 'strongarm',
            23 => 'taxonomy',
            24 => 'text',
            25 => 'views',
            26 => 'views_data_export',
            27 => 'visualization',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'acc_applications',
              1 => 'acc_applications_imp_reports',
              2 => 'acc_applications_map',
              3 => 'acc_applications_reports',
              4 => 'acc_applications_table',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'feeds:feeds_importer_default:1',
              2 => 'feeds_tamper:feeds_tamper_default:2',
              3 => 'openlayers:openlayers_maps:1',
              4 => 'panelizer:panelizer:1',
              5 => 'strongarm:strongarm:1',
              6 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'acc_submission_status',
              1 => 'csv_acc_application',
              2 => 'csv_acc_application_types',
            ),
            'feeds_tamper' => 
            array (
              0 => 'csv_acc_application-impact_value-explode',
              1 => 'csv_acc_application-nationality_of_traveler-explode',
              2 => 'csv_acc_application-nationality_of_traveler-strtotime',
              3 => 'csv_acc_application-organization_type-explode',
              4 => 'csv_acc_application-sectors-explode',
              5 => 'csv_acc_application-submitted_by-explode',
              6 => 'csv_acc_application-type_of_impact-explode',
            ),
            'field_base' => 
            array (
              0 => 'field_acc_application_types',
              1 => 'field_acc_geo_location_dest',
              2 => 'field_acc_submission_status',
              3 => 'field_acc_submitted_by',
              4 => 'field_acc_submitted_by_org_type',
              5 => 'field_how_many_days',
              6 => 'field_if_denied_by_whom_',
              7 => 'field_nationality',
              8 => 'field_submitted_to',
            ),
            'field_instance' => 
            array (
              0 => 'node-acc_application-body',
              1 => 'node-acc_application-field_acc_application_types',
              2 => 'node-acc_application-field_acc_attach_file',
              3 => 'node-acc_application-field_acc_date',
              4 => 'node-acc_application-field_acc_geo_location_dest',
              5 => 'node-acc_application-field_acc_impacts',
              6 => 'node-acc_application-field_acc_submission_status',
              7 => 'node-acc_application-field_acc_submitted_by',
              8 => 'node-acc_application-field_acc_submitted_by_org_type',
              9 => 'node-acc_application-field_bundles',
              10 => 'node-acc_application-field_how_many_days',
              11 => 'node-acc_application-field_if_denied_by_whom_',
              12 => 'node-acc_application-field_locations',
              13 => 'node-acc_application-field_nationality',
              14 => 'node-acc_application-field_submitted_to',
              15 => 'node-acc_application-og_group_ref',
            ),
            'node' => 
            array (
              0 => 'acc_application',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_bundle:access authoring options of acc_application content',
              1 => 'node:hr_bundle:access publishing options of acc_application content',
              2 => 'node:hr_bundle:access revisions options of acc_application content',
              3 => 'node:hr_bundle:administer panelizer node acc_application defaults',
              4 => 'node:hr_bundle:create acc_application content',
              5 => 'node:hr_bundle:delete any acc_application content',
              6 => 'node:hr_bundle:delete own acc_application content',
              7 => 'node:hr_bundle:update any acc_application content',
              8 => 'node:hr_bundle:update own acc_application content',
              9 => 'node:hr_bundle:view any unpublished acc_application content',
              10 => 'node:hr_operation:access authoring options of acc_application content',
              11 => 'node:hr_operation:access publishing options of acc_application content',
              12 => 'node:hr_operation:access revisions options of acc_application content',
              13 => 'node:hr_operation:administer panelizer node acc_application defaults',
              14 => 'node:hr_operation:create acc_application content',
              15 => 'node:hr_operation:delete any acc_application content',
              16 => 'node:hr_operation:delete own acc_application content',
              17 => 'node:hr_operation:update any acc_application content',
              18 => 'node:hr_operation:update own acc_application content',
              19 => 'node:hr_operation:view any unpublished acc_application content',
              20 => 'node:hr_sector:access authoring options of acc_application content',
              21 => 'node:hr_sector:access publishing options of acc_application content',
              22 => 'node:hr_sector:access revisions options of acc_application content',
              23 => 'node:hr_sector:administer panelizer node acc_application defaults',
              24 => 'node:hr_sector:create acc_application content',
              25 => 'node:hr_sector:delete any acc_application content',
              26 => 'node:hr_sector:delete own acc_application content',
              27 => 'node:hr_sector:update any acc_application content',
              28 => 'node:hr_sector:update own acc_application content',
              29 => 'node:hr_sector:view any unpublished acc_application content',
              30 => 'node:hr_space:access authoring options of acc_application content',
              31 => 'node:hr_space:access publishing options of acc_application content',
              32 => 'node:hr_space:access revisions options of acc_application content',
              33 => 'node:hr_space:administer panelizer node acc_application defaults',
              34 => 'node:hr_space:create acc_application content',
              35 => 'node:hr_space:delete any acc_application content',
              36 => 'node:hr_space:delete own acc_application content',
              37 => 'node:hr_space:update any acc_application content',
              38 => 'node:hr_space:update own acc_application content',
              39 => 'node:hr_space:view any unpublished acc_application content',
            ),
            'openlayers_maps' => 
            array (
              0 => 'acc_applications',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:acc_application:default:default',
            ),
            'taxonomy' => 
            array (
              0 => 'acc_application_submission_status',
              1 => 'acc_application_types',
            ),
            'variable' => 
            array (
              0 => 'auto_entitylabel_node_acc_application',
              1 => 'auto_entitylabel_pattern_node_acc_application',
              2 => 'auto_entitylabel_php_node_acc_application',
              3 => 'field_bundle_settings_node__acc_application',
              4 => 'language_content_type_acc_application',
              5 => 'menu_options_acc_application',
              6 => 'menu_parent_acc_application',
              7 => 'node_options_acc_application',
              8 => 'node_preview_acc_application',
              9 => 'node_submitted_acc_application',
              10 => 'panelizer_defaults_node_acc_application',
              11 => 'panelizer_defaults_taxonomy_term_acc_application_submission_status',
              12 => 'panelizer_defaults_taxonomy_term_acc_application_types',
              13 => 'pathauto_node_acc_application_pattern',
            ),
            'views_view' => 
            array (
              0 => 'acc_application_repots',
              1 => 'acc_applications',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'acc_users' => 'acc_users',
              'facetapi' => 'facetapi',
              'hr_operations' => 'hr_operations',
              'og_moderation' => 'og_moderation',
              'openlayers' => 'openlayers',
              'panelizer' => 'panelizer',
              'search_api' => 'search_api',
            ),
          ),
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'acc_applications',
        'version' => '7.x-2.0',
      ),
      'acc_incidents' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/modules/access/acc_incidents/acc_incidents.module',
        'basename' => 'acc_incidents.module',
        'name' => 'acc_incidents',
        'info' => 
        array (
          'name' => 'Access Incidents',
          'description' => 'Humanitarian Access Incidents component',
          'core' => '7.x',
          'package' => 'Humanitarian Access',
          'project' => 'acc_incidents',
          'dependencies' => 
          array (
            0 => 'acc_search',
            1 => 'acc_users',
            2 => 'context',
            3 => 'current_search',
            4 => 'entityreference_filter',
            5 => 'feeds_tamper',
            6 => 'field_collection',
            7 => 'hr_bundles',
            8 => 'hr_locations',
            9 => 'hr_operations',
            10 => 'hr_organizations',
            11 => 'hr_spaces',
            12 => 'og_context',
            13 => 'og_moderation',
            14 => 'og_ui',
            15 => 'visualization',
          ),
          'features' => 
          array (
            'context' => 
            array (
              0 => 'acc_incidents',
              1 => 'acc_incidents_graphs',
              2 => 'acc_incidents_map',
              3 => 'acc_incidents_table',
            ),
            'ctools' => 
            array (
              0 => 'context:context:3',
              1 => 'facetapi:facetapi_defaults:1',
              2 => 'feeds:feeds_importer_default:1',
              3 => 'feeds_tamper:feeds_tamper_default:2',
              4 => 'openlayers:openlayers_maps:1',
              5 => 'panelizer:panelizer:1',
              6 => 'strongarm:strongarm:1',
              7 => 'views:views_default:3.0',
            ),
            'features_api' => 
            array (
              0 => 'api:2',
            ),
            'feeds_importer' => 
            array (
              0 => 'acc_csv_impact',
              1 => 'acc_csv_incident',
              2 => 'acc_csv_responsible_actor',
              3 => 'acc_csv_types',
            ),
            'feeds_tamper' => 
            array (
              0 => 'acc_csv_incident-affected_organization_type-explode',
              1 => 'acc_csv_incident-affected_organizations-explode',
              2 => 'acc_csv_incident-impact_value-explode',
              3 => 'acc_csv_incident-responsible_actors-explode',
              4 => 'acc_csv_incident-responsible_actors_type-explode',
              5 => 'acc_csv_incident-type_of_affectee-explode',
              6 => 'acc_csv_incident-type_of_impact-explode',
            ),
            'field_base' => 
            array (
              0 => 'field_acc_attach_file',
              1 => 'field_acc_date',
              2 => 'field_acc_impact_type',
              3 => 'field_acc_impact_value',
              4 => 'field_acc_impacts',
              5 => 'field_acc_type',
              6 => 'field_affected_organization_type',
              7 => 'field_affected_organizations',
              8 => 'field_responsible_actors',
              9 => 'field_responsible_organization_t',
              10 => 'field_type_of_affectee',
            ),
            'field_instance' => 
            array (
              0 => 'field_collection_item-field_acc_impacts-field_acc_impact_type',
              1 => 'field_collection_item-field_acc_impacts-field_acc_impact_value',
              2 => 'node-acc_incident-body',
              3 => 'node-acc_incident-field_acc_attach_file',
              4 => 'node-acc_incident-field_acc_date',
              5 => 'node-acc_incident-field_acc_impacts',
              6 => 'node-acc_incident-field_acc_type',
              7 => 'node-acc_incident-field_affected_organization_type',
              8 => 'node-acc_incident-field_affected_organizations',
              9 => 'node-acc_incident-field_locations',
              10 => 'node-acc_incident-field_responsible_actors',
              11 => 'node-acc_incident-field_responsible_organization_t',
              12 => 'node-acc_incident-field_type_of_affectee',
              13 => 'node-acc_incident-og_group_ref',
              14 => 'taxonomy_term-acc_impact_types-name_field',
              15 => 'taxonomy_term-acc_incident_types-name_field',
              16 => 'taxonomy_term-acc_responsible_actors-field_organization_type',
              17 => 'taxonomy_term-acc_responsible_actors-name_field',
              18 => 'taxonomy_term-acc_type_of_aid_workers-name_field',
            ),
            'node' => 
            array (
              0 => 'acc_incident',
            ),
            'og_features_permission' => 
            array (
              0 => 'node:hr_bundle:access authoring options of acc_incident content',
              1 => 'node:hr_bundle:access publishing options of acc_incident content',
              2 => 'node:hr_bundle:access revisions options of acc_incident content',
              3 => 'node:hr_bundle:administer panelizer node acc_incident defaults',
              4 => 'node:hr_bundle:create acc_incident content',
              5 => 'node:hr_bundle:delete any acc_incident content',
              6 => 'node:hr_bundle:delete own acc_incident content',
              7 => 'node:hr_bundle:update any acc_incident content',
              8 => 'node:hr_bundle:update own acc_incident content',
              9 => 'node:hr_bundle:view any unpublished acc_incident content',
              10 => 'node:hr_operation:access authoring options of acc_incident content',
              11 => 'node:hr_operation:access publishing options of acc_incident content',
              12 => 'node:hr_operation:access revisions options of acc_incident content',
              13 => 'node:hr_operation:administer panelizer node acc_incident defaults',
              14 => 'node:hr_operation:create acc_incident content',
              15 => 'node:hr_operation:delete any acc_incident content',
              16 => 'node:hr_operation:delete own acc_incident content',
              17 => 'node:hr_operation:update any acc_incident content',
              18 => 'node:hr_operation:update own acc_incident content',
              19 => 'node:hr_operation:view any unpublished acc_incident content',
              20 => 'node:hr_sector:access authoring options of acc_incident content',
              21 => 'node:hr_sector:access publishing options of acc_incident content',
              22 => 'node:hr_sector:access revisions options of acc_incident content',
              23 => 'node:hr_sector:administer panelizer node acc_incident defaults',
              24 => 'node:hr_sector:create acc_incident content',
              25 => 'node:hr_sector:delete any acc_incident content',
              26 => 'node:hr_sector:delete own acc_incident content',
              27 => 'node:hr_sector:update any acc_incident content',
              28 => 'node:hr_sector:update own acc_incident content',
              29 => 'node:hr_sector:view any unpublished acc_incident content',
              30 => 'node:hr_space:access authoring options of acc_incident content',
              31 => 'node:hr_space:access publishing options of acc_incident content',
              32 => 'node:hr_space:access revisions options of acc_incident content',
              33 => 'node:hr_space:administer panelizer node acc_incident defaults',
              34 => 'node:hr_space:create acc_incident content',
              35 => 'node:hr_space:delete any acc_incident content',
              36 => 'node:hr_space:delete own acc_incident content',
              37 => 'node:hr_space:update any acc_incident content',
              38 => 'node:hr_space:update own acc_incident content',
              39 => 'node:hr_space:view any unpublished acc_incident content',
            ),
            'openlayers_maps' => 
            array (
              0 => 'acc_incidents',
            ),
            'panelizer_defaults' => 
            array (
              0 => 'node:acc_incident:default:default',
            ),
            'taxonomy' => 
            array (
              0 => 'acc_impact_types',
              1 => 'acc_incident_types',
              2 => 'acc_responsible_actors',
              3 => 'acc_type_of_aid_workers',
            ),
            'variable' => 
            array (
              0 => 'auto_entitylabel_node_acc_incident',
              1 => 'auto_entitylabel_pattern_node_acc_incident',
              2 => 'auto_entitylabel_php_node_acc_incident',
              3 => 'field_bundle_settings_node__acc_incident',
              4 => 'language_content_type_acc_incident',
              5 => 'menu_options_acc_incident',
              6 => 'menu_parent_acc_incident',
              7 => 'node_options_acc_incident',
              8 => 'node_preview_acc_incident',
              9 => 'node_submitted_acc_incident',
              10 => 'panelizer_defaults_node_acc_incident',
              11 => 'panelizer_node:acc_incident_allowed_layouts',
              12 => 'panelizer_node:acc_incident_allowed_layouts_default',
              13 => 'panelizer_node:acc_incident_allowed_types_default',
              14 => 'panelizer_node:acc_incident_default',
              15 => 'pathauto_node_acc_incident_pattern',
            ),
            'views_view' => 
            array (
              0 => 'acc_incident_graphs',
              1 => 'acc_incidents',
            ),
          ),
          'features_exclude' => 
          array (
            'dependencies' => 
            array (
              'entity' => 'entity',
              'openlayers_views' => 'openlayers_views',
              'views' => 'views',
              'views_data_export' => 'views_data_export',
            ),
            'field_instance' => 
            array (
              'node-acc_incident-field_sectors' => 'node-acc_incident-field_sectors',
            ),
            'og_features_role' => 
            array (
              'node:hr_operation:access-manager' => 'node:hr_operation:access-manager',
              'node:hr_operation:access-editor' => 'node:hr_operation:access-editor',
            ),
          ),
          'version' => NULL,
          'php' => '5.2.4',
        ),
        'schema_version' => 0,
        'project' => 'acc_incidents',
        'version' => NULL,
      ),
    ),
    'themes' => 
    array (
      'default' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/themes/radix/kits/default/default.info',
        'basename' => 'default.info',
        'name' => '{{Name}}',
        'info' => 
        array (
          'name' => '{{Name}}',
          'description' => '{{Description}}',
          'screenshot' => 'screenshot.png',
          'core' => '7.x',
          'base theme' => 'radix',
          'hidden' => 'true',
          'regions' => 
          array (
            'content' => 'Content',
          ),
          'plugins' => 
          array (
            'panels' => 
            array (
              'layouts' => 'panels/layouts',
              'styles' => 'panels/styles',
            ),
          ),
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'assets/stylesheets/screen.css',
            ),
            'print' => 
            array (
              0 => 'assets/stylesheets/print.css',
            ),
          ),
          'stylesheets-conditional' => 
          array (
            'IE 7' => 
            array (
              'all' => 
              array (
                0 => 'assets/stylesheets/ie7.css',
              ),
            ),
            'IE 8' => 
            array (
              'all' => 
              array (
                0 => 'assets/stylesheets/ie8.css',
              ),
            ),
          ),
          'scripts' => 
          array (
            0 => 'assets/javascripts/script.js',
          ),
          'version' => '7.x-3.0-alpha4',
          'project' => 'radix',
          'datestamp' => '1398941032',
        ),
        'project' => 'radix',
        'version' => '7.x-3.0-alpha4',
      ),
      'radix' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/themes/radix/radix.info',
        'basename' => 'radix.info',
        'name' => 'Radix',
        'info' => 
        array (
          'name' => 'Radix',
          'description' => 'A Drupal theme with Bootstrap and Sass.',
          'screenshot' => 'screenshot.png',
          'core' => '7.x',
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'assets/stylesheets/radix-style.css',
              1 => 'assets/stylesheets/radix-livestyle.css',
            ),
            'print' => 
            array (
              0 => 'assets/stylesheets/radix-print.css',
            ),
          ),
          'stylesheets-conditional' => 
          array (
            'IE 7' => 
            array (
              'all' => 
              array (
                0 => 'assets/stylesheets/radix-ie7.css',
              ),
            ),
            'IE 8' => 
            array (
              'all' => 
              array (
                0 => 'assets/stylesheets/radix-ie8.css',
              ),
            ),
          ),
          'scripts' => 
          array (
            0 => 'assets/javascripts/modernizr.js',
            1 => 'assets/javascripts/radix-script.js',
          ),
          'regions' => 
          array (
            'content' => 'Content',
          ),
          'features' => 
          array (
            0 => 'logo',
            1 => 'name',
            2 => 'favicon',
          ),
          'version' => '7.x-3.0-alpha4',
          'project' => 'radix',
          'datestamp' => '1398941032',
        ),
        'project' => 'radix',
        'version' => '7.x-3.0-alpha4',
      ),
      'humanitarianresponse' => 
      array (
        'filename' => '/var/aegir/platforms/humanitarianresponse-7.x-2.x-17042015/sites/all/themes/humanitarianresponse/humanitarianresponse.info',
        'basename' => 'humanitarianresponse.info',
        'name' => 'Humanitarianresponse',
        'info' => 
        array (
          'name' => 'Humanitarianresponse',
          'description' => 'A theme based on Radix.',
          'screenshot' => 'screenshot.png',
          'core' => '7.x',
          'base theme' => 'radix',
          'regions' => 
          array (
            'top' => 'Top',
            'branding' => 'Branding',
            'navigation' => 'Navigation',
            'content' => 'Content',
            'sidebar_first' => 'Sidebar First',
            'footer' => 'Footer',
          ),
          'plugins' => 
          array (
            'panels' => 
            array (
              'layouts' => 'panels/layouts',
              'styles' => 'panels/styles',
            ),
          ),
          'stylesheets' => 
          array (
            'all' => 
            array (
              0 => 'assets/stylesheets/screen.css',
            ),
            'print' => 
            array (
              0 => 'assets/stylesheets/print.css',
            ),
          ),
          'stylesheets-conditional' => 
          array (
            'IE 7' => 
            array (
              'all' => 
              array (
                0 => 'assets/stylesheets/ie7.css',
              ),
            ),
            'IE 8' => 
            array (
              'all' => 
              array (
                0 => 'assets/stylesheets/ie8.css',
              ),
            ),
          ),
          'scripts' => 
          array (
            0 => 'assets/javascripts/script.js',
            1 => 'assets/javascripts/respond.min.js',
            2 => 'assets/javascripts/highcharts.js',
          ),
          'version' => '7.x-3.x-dev',
          'project' => 'radix',
          'datestamp' => '1390376007',
        ),
        'project' => 'radix',
        'version' => '7.x-3.x-dev',
      ),
    ),
  ),
  'profiles' => 
  array (
    'minimal' => 
    array (
      'modules' => 
      array (
      ),
      'themes' => 
      array (
      ),
    ),
    'standard' => 
    array (
      'modules' => 
      array (
      ),
      'themes' => 
      array (
      ),
    ),
  ),
);
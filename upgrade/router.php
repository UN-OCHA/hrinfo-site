<?php

/**
 * @file
 * Router script for the built-in PHP web server.
 *
 * Usage:
 * php -S localhost:8080 -t hrinfo.docksal.site/ router.php
 *
 * @see http://php.net/manual/en/features.commandline.webserver.php
 */

$langcodes = [
  'en',
  'es',
  'fr',
  'ru',
];

$url = parse_url($_SERVER['REQUEST_URI']);
$path = $url['path'];

// Remove language prefix.
$exploded = explode('/', $path);
if (in_array($exploded[1], $langcodes)) {
  unset($exploded[1]);
  $path = implode('/', $exploded);
}

// Check existing file.
$file = __DIR__ . '/hrinfo.docksal.site' . $path;
if (file_exists($file)) {
  // Serve the requested resource as-is.
  return FALSE;
}

// Check with html extension.
if (file_exists($file . '.html')) {
  header('Location: ' . $path . '.html');
  return TRUE;
}

// Check alias table.
$aliases = file_get_contents('./alias.tsv');
preg_match('~' . ltrim($path, '/') . '\t(.*)~', $aliases, $matches);
if (!empty($matches)) {
  $file = __DIR__ . '/hrinfo.docksal.site/' . rtrim($matches[1]) . '.html';
  if (file_exists($file)) {
    header('Location: /' . rtrim($matches[1]) . '.html');
    return TRUE;
  }
}

return FALSE;

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

$full_path = $path;

$has_query = FALSE;
if (strpos($url['query'], 'page=') !== FALSE) {
  $has_query = TRUE;
  $full_path .= '?' . $url['query'];
}

// Check existing file.
$file = __DIR__ . '/hrinfo.docksal.site' . $full_path;
if (file_exists($file)) {
  if ($has_query) {
    readfile($file);
    return TRUE;
  }
  // Serve the requested resource as-is.
  return FALSE;
}

// Check with html extension.
if (file_exists($file . '.html')) {
  header('Location: ' . $full_path . '.html');
  return TRUE;
}

// Check alias table.
$aliases = file_get_contents('./alias.tsv');
preg_match('~' . ltrim($path, '/') . '\t(.*)~', $aliases, $matches);
if (!empty($matches)) {
  $new_path = rtrim($matches[1]);
  if ($has_query) {
    $new_path .= '?' . $url['query'];
  }

  $file = __DIR__ . '/hrinfo.docksal.site/' . $new_path . '.html';
  if (file_exists($file)) {
    header('Location: /' . $new_path . '.html');
    return TRUE;
  }
}
else {
  // Check document river.
  if (strpos($path, '/documents') !== FALSE) {
    $path = str_replace('/documents', '', $path);
    preg_match('~' . ltrim($path, '/') . '\t(.*)~', $aliases, $matches);
    if (!empty($matches)) {
      $new_path = rtrim($matches[1]) . '/documents';
      if ($has_query) {
        $new_path .= '?' . $url['query'];
      }

      $file = __DIR__ . '/hrinfo.docksal.site/' . $new_path . '.html';
      if (file_exists($file)) {
        header('Location: /' . $new_path . '.html');
        return TRUE;
      }

      // Without query string.
      if ($has_query) {
        $new_path = rtrim($matches[1]) . '/documents';
        $file = __DIR__ . '/hrinfo.docksal.site/' . $new_path . '.html';
        if (file_exists($file)) {
          header('Location: /' . $new_path . '.html');
          return TRUE;
        }
      }
    }
  }

  // Check infographics river.
  if (strpos($path, '/infographics') !== FALSE) {
    $path = str_replace('/infographics', '', $path);
    preg_match('~' . ltrim($path, '/') . '\t(.*)~', $aliases, $matches);
    if (!empty($matches)) {
      $new_path = rtrim($matches[1]) . '/infographics';
      if ($has_query) {
        $new_path .= '?' . $url['query'];
      }

      $file = __DIR__ . '/hrinfo.docksal.site/' . $new_path . '.html';
      if (file_exists($file)) {
        header('Location: /' . $new_path . '.html');
        return TRUE;
      }

      // Without query string.
      if ($has_query) {
        $new_path = rtrim($matches[1]) . '/infographics';
        $file = __DIR__ . '/hrinfo.docksal.site/' . $new_path . '.html';
        if (file_exists($file)) {
          header('Location: /' . $new_path . '.html');
          return TRUE;
        }
      }
    }
  }
}

// Check path without query string.
if ($has_query) {
  // Check existing file.
  $file = __DIR__ . '/hrinfo.docksal.site' . $path;
  if (file_exists($file)) {
    if ($has_query) {
      readfile($file);
      return TRUE;
    }
    // Serve the requested resource as-is.
    return FALSE;
  }

  // Check with html extension.
  if (file_exists($file . '.html')) {
    header('Location: ' . $path . '.html');
    return TRUE;
  }
}

// echo print_r([
//   'path' => $path,
//   'new_path' => $new_path,
// ], TRUE);
// return TRUE;

// http://localhost:8080/en/operations/afghanistan/nutrition/documents?page=2

header('Location: /404.html');
return TRUE;

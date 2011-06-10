<?php
/**
 * @file
 * This file contains page callbacks for menu_magic.module.
 */

/**
 * Page callback for the 'magic/%' wildcard page.
 */
function menu_magic_extra($wildcard) {
  // If the wildcard in the URL contains a number, try to load a node by ID.
  if (is_numeric($wildcard)) {
    if ($node = node_load($wildcard)) {
      $content = node_view($node);
    }
  }

  // If the wildcard in the URL is a string, try to load a user account by name.
  elseif (is_string($wildcard)) {
    if ($account = user_load_by_name($wildcard)) {
      $content = user_view($account);
    }
  }

  // See if we managed to load anything. Return the content if we did, and
  // generate a 404 error if we didn't. Drupal handles building the 404 page
  // for us.
  if (isset($content)) {
    return $content;
  }
  else {
    drupal_not_found();
  }
}

<?php
/**
 * @file
 * This file contains page callbacks for menu_magic.module.
 */

/**
 * Page callback for the 'user/%/magic tab.
 */
function menu_magic_user_tab($wildcard) {
  if (is_numeric($wildcard) && ($account = user_load($wildcard))) {
    if ($image = _magic_get_picture($account->name)) {
      return $image;
    }
    else {
      return array(
        '#type'   => 'markup',
        '#markup' => t("Sorry, we couldn't find anything awesome."),
      );
    }
  }
  else {
    return drupal_not_found();
  }
}

/**
 * Internal helper function that returns the top Google Image Search result
 * for a string, as a renderable Drupal element.
 */
function _magic_get_picture($username) {
  $google = 'https://ajax.googleapis.com/ajax/services/search/images?v=1.0&q=';
  $result = drupal_http_request($google . urlencode($username));

  if ($result->code == 200) {
    $response = json_decode($result->data);

    if (!empty($response->responseData->results)) {
      $key = array_rand($response->responseData->results);
      $result = $response->responseData->results[$key];
      $image = array(
        '#theme' => 'image',
        '#path' => $result->unescapedUrl,
        '#title' => $result->titleNoFormatting,
        '#alt' => t('Image from @source', array('@source' => $result->visibleUrl)),
      );
      return $image;
    }
  }
}
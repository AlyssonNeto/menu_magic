<?php
/**
 * @file
 * This file contains page callbacks for menu_magic.module.
 */

/**
 * Page callback for the basic 'magic' page.
 */
function menu_magic_basic() {
  $content = array();
  
  // This is a very, very simple page element. It will appear on the page,
  // but other modules can't customize it and themes can't override its markup.
  $content['raw_markup'] = array(
    '#type' => 'markup',
    '#markup' => '<p>Truly, this is magical!</p>',
  );

  // This markup element uses the theme() function so its output can be
  // customized by other themes, and the t() function so its text can be
  // translated into other languages.
  $variables = array(
    'path'  => 'http://is.gd/pgd0oV',
    'alt'   => t('Picture of magic'),
    'title' => t('Yes, this is magic all right!'),
  );
  $content['themed_data'] = array(
    '#type'   => 'markup',
    '#markup' => theme('image', $variables),
  );
  
  // This is 'renderable' element. Its data is rendered into markup by Drupal
  // after the page is fully built, giving other modules a chance to tweak it
  // if needed.
  $content['renderable_element'] = array(
    '#type'   => 'markup',
    '#theme'  => 'item_list',
    '#title'  => t("How do we know it's magic?"),
    '#items'  => array(
      t("Is it made of wood?"),
      t("Does it sink in water?"),
      t("Does it weigh the same as a duck?"),
    ),
  );
  
  return $content;
}

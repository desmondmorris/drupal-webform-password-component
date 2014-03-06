<?php

/**
 * @file
 * Webform password component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_password() {
  return array(
    'name' => '',
    'form_key' => NULL,
    'pid' => 0,
    'weight' => 0,
    'value' => '',
    'extra' => array(),
  );
}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_password($component) {
  $form = array();

  $form['extra']['password'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#required' => TRUE,
    '#element_validate' => array('_webform_edit_password_validate'),
  );
  return $form;
}

/**
 * Element validate callback for the password comonent settings field.
 *
 * Encrypts password value for safe db storage
 */
function _webform_edit_password_validate($element, &$form_state) {
  $password = $form_state['values']['extra']['password'];
  form_set_value($element, sha1($password), $form_state);
}


/**
 * Implements _webform_render_component().
 */
function _webform_render_password($component, $value = NULL, $filter = TRUE) {
  $node = isset($component['nid']) ? node_load($component['nid']) : NULL;

  $element = array(
    '#type' => 'password',
    '#title' => $filter ? _webform_filter_xss($component['name']) : $component['name'],
    '#title_display' => 'before',
    '#required' => TRUE,
    '#weight' => $component['weight'],
    '#theme_wrappers' => array('webform_element'),
    '#element_validate'  => array('_webform_validate_password')
  );

  return $element;
}

/**
 * Element validate callback for the password component field.
 */
function _webform_validate_password($element, &$form_state) {
  $password = sha1($element['#value']);

  if ($password != $element['#webform_component']['extra']['password']) {
    form_error($element, t('Incorrect password'));
  }
  else {
    form_set_value($element, $password, $form_state);
  }
}

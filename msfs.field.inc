<?php

/**
 * Implements hook_field_info().
 */
function msfs_field_info()
{
  return [
    'msfs_file' => array(
      'label' => t('MSFS File'),
      'description' => t('Store file on remote servers'),
      'default_widget' => 'msfs_file_widget',
      'default_formatter' => 'msfs_file_formatter',
    ),
  ];
}

/**
 * Implements hook_field_schema().
 */
function msfs_field_schema($field)
{
  $columns = array(
    'msfs_file_id' => array('type' => 'int', 'length' => 10, 'not null' => FALSE),
  );
  return array('columns' => $columns);
}

/**
 * Implements hook_field_widget_info().
 */
function msfs_field_widget_info()
{
  return [
    'msfs_file_widget' => array(
      'label' => t('MSFS file default'),
      'field types' => array('msfs_file'),
      'settings' => array(),
    ),
  ];
}

/**
 * Implements hook_field_widget_error().
 */
function msfs_field_widget_error($element, $error, $form, &$form_state)
{
  switch ($error['error']) {
    case 'msfs_file_invalid':
      form_error($element, $error['message']);
      break;
  }
}

/**
 * Implements hook_field_widget_form().
 */
function msfs_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element)
{
  $field_name = $field['field_name'];
  switch ($instance['widget']['type']) {
    case 'msfs_file_widget':
      $element['msfs_file_upload'] = [
        '#name' => 'files[' . $element['#field_name'] . ']',
        '#type' => 'file',
        '#title' => $element['#title'],
        '#description' => t('Choose a file'),
        '#size' => 22,
        '#required' => $element['#required'],
      ];
      if (!empty($element['#entity']->{$field_name}['und'][0]['msfs_file_id'])) {
        $msfs_file_id = $element['#entity']->{$field_name}['und'][0]['msfs_file_id'];
        $file = msfs_load_file($msfs_file_id);
        $markup = '<div>';
        if ($file['raw']['type'] == 'image') {
          $markup .= '<img src="'.$file['url'].'" width="100px"><br>';
        }
        $markup .= '<a href="'.$file['url'].'" target="_blank">'.$file['raw']['filename'].'</a>';
        $markup .= '</div>';
        $element['msfs_file_upload_view'] = [
          '#type' => 'markup',
          '#markup' => $markup,
        ];
      }
      break;
  }

  return $element;
}

/**
 * Implements hook_field_attach_submit().
 */
function msfs_field_attach_submit($entity_type, $entity, $form, &$form_state)
{
  // crap code to save values. TODO: remove this shit and write normal submit after reading documentation :-)

}

/**
 * Implements hook_form_alter().
 */
function msfs_form_alter(&$form, &$form_state, $form_id)
{
  $form['#submit'][] = '_msfs_field_submit';
}

function _msfs_field_submit($form, &$form_state) {
  $b = 1;
  foreach ($form as $item) {
    if (is_array($item)) {
      if (!empty($item[LANGUAGE_NONE]['#field_name'])) {
        foreach ($item[LANGUAGE_NONE] as $item) {
          if (isset($item['msfs_file_upload'])) {
            $field_name = $item['#field_name'];
            if (!empty($_FILES['files']['name'][$field_name])) {
              // upload file and get id of uploaded file
              if ($msfs_id = msfs_save_upload_file($field_name)) {
                $entity = &$form['#entity'];
                $entity->{$field_name}[LANGUAGE_NONE][0]['msfs_file_id'] = $msfs_id;
                entity_save($form['#entity_type'], $entity);
              }
            }
          }
        }
      }
    }
  }
}

/**
 * Implements hook_field_is_empty().
 */
function msfs_field_is_empty($item, $field)
{
  $empty = empty($_FILES['files']['name'][$field['field_name']]);
  return $empty;
}

/**
 * Implements hook_field_formatter_info().
 */
function msfs_field_formatter_info()
{
  return [
    'msfs_file_formatter' => array(
      'label' => t('MSFS file default'),
      'field types' => array('msfs_file'),
    ),
  ];
}

/**
 * Implements hook_field_formatter_view().
 */
function msfs_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display)
{
  $element = array();

  switch ($display['type']) {
    case 'msfs_file_formatter':
//      file_field_formatter_view()
      $b = 1;
      break;
  }

  return $element;
}

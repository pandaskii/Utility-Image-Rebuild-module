<?php

/**
 * @file
 * Utility Image Rebuild Batch functions.
 */

/**
 * Runs the batch process for one entity.
 */
function _utility_image_rebuild_batch_process_entity($table, $field_name, $id, &$context) {
  $file = file_load($id);
  $file_object = $file;
  $file_object->filename = drupal_basename($file->uri);
  $file_object->filemime = file_get_mimetype($file->uri);
  $info = image_get_info($file->uri);
  if (is_array($info)) {
    // Update the filename and filemine information.
    file_save($file_object);
    // Update the file demensions.
    db_update($table)->fields(array(
      $field_name . '_width' => $info['width'],
      $field_name . '_height' => $info['height']
    ))->condition($field_name . '_fid', $id)->execute();
  }
  // Update batch progress information.
  if (!isset($context['results']['processed'])) {
    $context['results']['processed'] = 0;
  }
  $context['results']['processed']++;
  $context['message'] = 'We are processing with file with fid - ' . $id;
}

/**
 * Batch process finished callback.
 */
function _utility_image_rebuild_batch_finished($success, $results, $operations) {
  if ($success) {
    $message = 'The images have been rebuilt by Utility Tool - Image Rebuild.';
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE)
    ));
  }
  drupal_set_message($message);
}

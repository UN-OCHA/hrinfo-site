<?php

/**
 * @file
 * Contains the job UI controller.
 */

/**
 * Entity UI controller for the Job Entity.
 */
class TMGMTJobUIController extends EntityDefaultUIController {

  /**
   * Translation job that is a duplicate of an aborted job.
   *
   * @var TMGMTJob
   */
  private $jobToResubmit = NULL;

  /**
   * {@inheritdoc}
   */
  public function hook_menu() {
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%entity_object';
    $items[$this->path . '/' . $wildcard] = array(
      'title callback' => 'entity_label',
      'title arguments' => array($this->entityType, $id_count),
      'page callback' => 'tmgmt_ui_job_view',
      'page arguments' => array($id_count),
      'load arguments' => array($this->entityType),
      'access callback' => 'entity_access',
      'access arguments' => array('view', $this->entityType, $id_count),
      'file' => $this->entityInfo['admin ui']['file'],
      'file path' => $this->entityInfo['admin ui']['file path'],
    );
    $items[$this->path . '/' . $wildcard . '/delete'] = array(
      'page callback' => 'drupal_get_form',
      'page arguments' => array($this->entityType . '_operation_form', $this->entityType, $id_count, $id_count + 1),
      'load arguments' => array($this->entityType),
      'access callback' => 'entity_access',
      'access arguments' => array('delete', $this->entityType, $id_count),
      'type' => MENU_CALLBACK,
    );
    $items[$this->path . '/' . $wildcard . '/abort'] = array(
      'page callback' => 'drupal_get_form',
      'page arguments' => array($this->entityType . '_operation_form', $this->entityType, $id_count, $id_count + 1),
      'load arguments' => array($this->entityType),
      'access callback' => 'entity_access',
      'access arguments' => array('abort', $this->entityType, $id_count),
      'type' => MENU_CALLBACK,
    );
    $items[$this->path . '/' . $wildcard . '/resubmit'] = array(
      'page callback' => 'drupal_get_form',
      'page arguments' => array($this->entityType . '_operation_form', $this->entityType, $id_count, $id_count + 1),
      'load arguments' => array($this->entityType),
      'access callback' => 'entity_access',
      'access arguments' => array('resubmit', $this->entityType, $id_count),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }

  /**
   * {@inheritdoc}
   */
  public function operationForm($form, &$form_state, $entity, $op) {
    switch ($op) {
      case 'delete':
        $confirm_question = t('Are you sure you want to delete the translation job %label?', array('%label' => $entity->label()));
        return confirm_form($form, $confirm_question, $this->path);
      case 'abort':
        return confirm_form($form, t('Abort this job?'), 'admin/tmgmt/jobs/' . $entity->tjid,
          t('This will send a request to the translator to abort the job. After the action the job translation process will be aborted and only remaining action will be resubmitting it.'));
      case 'resubmit':
        return confirm_form($form, t('Resubmit as a new job?'), 'admin/tmgmt/jobs/' . $entity->tjid,
          t('This creates a new job with the same items which can then be submitted again. In case the sources meanwhile changed, the new job will reflect the update.'));
    }
    drupal_not_found();
    exit;
  }

  /**
   * {@inheritdoc}
   */
  public function applyOperation($op, $entity) {
    switch ($op) {
      case 'delete':
        $entity->delete();
        return t('Deleted the translation job %label.', array('%label' => $entity->label()));
      case 'abort':
        if (!$entity->abortTranslation()) {
          // This is the case when a translator does not support the abort operation.
          // It would make more sense to not display the button for the action,
          // however we do not know if the translator is able to abort a job until
          // we trigger the action.
          foreach ($entity->getMessagesSince() as $message) {
            if ($message->type == 'debug') {
              continue;
            }
            if ($text = $message->getMessage()) {
              // We want to persist also the type therefore we will set the
              // messages directly and not return them.
              drupal_set_message(filter_xss($text), $message->type);
            }
          }
        }
        break;
      case 'resubmit':
        $this->jobToResubmit = $entity->cloneAsUnprocessed();
        $this->jobToResubmit->uid = $GLOBALS['user']->uid;
        $this->jobToResubmit->save();
        /** @var TMGMTJobItem $item */
        foreach ($entity->getItems() as $item) {
          $item_to_resubmit = $item->cloneAsActive();
          $this->jobToResubmit->addExistingItem($item_to_resubmit);
        }

        $entity->addMessage('Job has been duplicated as a new job <a href="@url">#@id</a>.',
          array('@url' => url('admin/tmgmt/jobs/' . $this->jobToResubmit->tjid), '@id' => $this->jobToResubmit->tjid));
        $this->jobToResubmit->addMessage('This job is a duplicate of the previously aborted job <a href="@url">#@id</a>',
          array('@url' => url('admin/tmgmt/jobs/' . $entity->tjid), '@id' => $entity->tjid));

        return t('The aborted job has been duplicated. You can resubmit it now.');
    }
    return FALSE;
  }

  /**
   * Operation form submit callback.
   */
  public function operationFormSubmit($form, &$form_state) {
    parent::operationFormSubmit($form, $form_state);
    if ($form_state['op'] == 'resubmit') {
      $form_state['redirect'] = $this->path . '/' . $this->jobToResubmit->tjid;
    }
  }

}

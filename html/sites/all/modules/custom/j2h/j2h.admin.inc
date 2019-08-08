<?php
/**
* @file
* Callbacks de administración del módulo j2h.
*/

/**
* Define el formulario de opciones de configuración.
*/
function j2h_configuracion() {  
    $form['j2h_api_url'] = array(
        '#title' => 'API url',
        '#type' => 'textfield',
        '#default_value' => variable_get('j2h_api_url', 'http://'),
    );

    $form['j2h_block_vars'] = array(
        '#title' => t('Block variables per page'),
        '#description' => t('Specify block variables by using their paths. Enter one path per line. front is the front page, i.e: <front>:mod1_api, shelter:mod2_api'),
        '#type' => 'textarea',
        '#default_value' => variable_get('j2h_block_vars', ''),
    );

    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save configuration'),
    );

    $form['#submit'][] = 'j2h_configuracion_submit';  

    return $form;
}

/**
* Valida el formulario de opciones de configuración.
*/
function j2h_configuracion_validate($form, &$form_state) {
    if (trim($form_state['values']['j2h_api_url']) == '') {
        form_set_error('j2h_api_url', 'La url no puede ser vacía.');
    }
}

/**
* Procesa el envío del formulario de opciones de configuración.
*/
function j2h_configuracion_submit($form, $form_state) {

    variable_set('j2h_api_url', $form_state['values']['j2h_api_url']);
    variable_set('j2h_block_vars', $form_state['values']['j2h_block_vars']);

    drupal_set_message(t("The configuration has been saved"));
}

?>

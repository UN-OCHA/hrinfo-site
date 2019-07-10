<?php
/**
 * @file
 * Base class for migrating variables into Drupal.
 */

/*
 * Base class for all variables migrations - handles commonalities across
 * all supported source Drupal versions.
 */
abstract class DrupalVariableMigration extends DrupalMigration {

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Create our three main objects - source, destination, and map
    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->destination = new MigrateDestinationVariable();

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'name' => array(
          'description' => 'The name of the variable.',
          'type' => 'varchar',
          'length' => 128,
          'not null' => TRUE,
          'default' => '',
        ),
      ),
      MigrateDestinationVariable::getKeySchema()
    );

    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('value', 'value')->callbacks('unserialize');
  }

  /**
   * Query for the variable data.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('variable', 'v')
             ->fields('v');
    return $query;
  }
}

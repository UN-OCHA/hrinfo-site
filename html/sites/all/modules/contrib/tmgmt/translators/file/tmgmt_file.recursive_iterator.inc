<?php
/**
 * @file
 * Contains RecursiveDOMIterator.
 */

/**
 * Class used to iterate through DOMDocument.
 */
class RecursiveDOMIterator implements RecursiveIterator {
  /**
   * Current position in DOMNodeList.
   *
   * @var int
   */
  protected $position;

  /**
   * The DOMNodeList with all children to iterate over.
   *
   * @var DOMNodeList
   */
  protected $nodeList;

  /**
   * Constructor.
   *
   * @param DOMNode $domNode
   *   DOMNode to iterate over.
   */
  public function __construct(DOMNode $domNode) {
    $this->position = 0;
    $this->nodeList = $domNode->childNodes;
  }

  /**
   * Returns the current DOMNode.
   *
   * @return DOMNode
   *   Current DOMNode object.
   */
  public function current() {
    return $this->nodeList->item($this->position);
  }

  /**
   * Returns an iterator for the current iterator entry.
   *
   * @return RecursiveDOMIterator
   *   Iterator with children elements.
   */
  public function getChildren() {
    return new self($this->current());
  }

  /**
   * Checks if current element has children.
   *
   * @return bool
   *   Has children.
   */
  public function hasChildren() {
    return $this->current()->hasChildNodes();
  }

  /**
   * Returns the current position.
   *
   * @return int
   *   Current position
   */
  public function key() {
    return $this->position;
  }

  /**
   * Moves the current position to the next element.
   */
  public function next() {
    $this->position++;
  }

  /**
   * Rewind the Iterator to the first element.
   */
  public function rewind() {
    $this->position = 0;
  }

  /**
   * Checks if current position is valid.
   *
   * @return bool
   *   Is valid.
   */
  public function valid() {
    return $this->position < $this->nodeList->length;
  }
}

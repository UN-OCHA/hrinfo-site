/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
/**
 * True if the custom elements polyfill is in use.
 */
const isCEPolyfill = typeof window !== 'undefined' &&
    window.customElements != null &&
    window.customElements.polyfillWrapFlushCallback !==
        undefined;
/**
 * Removes nodes, starting from `start` (inclusive) to `end` (exclusive), from
 * `container`.
 */
const removeNodes = (container, start, end = null) => {
    while (start !== end) {
        const n = start.nextSibling;
        container.removeChild(start);
        start = n;
    }
};

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
/**
 * An expression marker with embedded unique key to avoid collision with
 * possible text in templates.
 */
const marker = `{{lit-${String(Math.random()).slice(2)}}}`;
/**
 * An expression marker used text-positions, multi-binding attributes, and
 * attributes with markup-like text values.
 */
const nodeMarker = `<!--${marker}-->`;
const markerRegex = new RegExp(`${marker}|${nodeMarker}`);
/**
 * Suffix appended to all bound attribute names.
 */
const boundAttributeSuffix = '$lit$';
/**
 * An updatable Template that tracks the location of dynamic parts.
 */
class Template {
    constructor(result, element) {
        this.parts = [];
        this.element = element;
        const nodesToRemove = [];
        const stack = [];
        // Edge needs all 4 parameters present; IE11 needs 3rd parameter to be null
        const walker = document.createTreeWalker(element.content, 133 /* NodeFilter.SHOW_{ELEMENT|COMMENT|TEXT} */, null, false);
        // Keeps track of the last index associated with a part. We try to delete
        // unnecessary nodes, but we never want to associate two different parts
        // to the same index. They must have a constant node between.
        let lastPartIndex = 0;
        let index = -1;
        let partIndex = 0;
        const { strings, values: { length } } = result;
        while (partIndex < length) {
            const node = walker.nextNode();
            if (node === null) {
                // We've exhausted the content inside a nested template element.
                // Because we still have parts (the outer for-loop), we know:
                // - There is a template in the stack
                // - The walker will find a nextNode outside the template
                walker.currentNode = stack.pop();
                continue;
            }
            index++;
            if (node.nodeType === 1 /* Node.ELEMENT_NODE */) {
                if (node.hasAttributes()) {
                    const attributes = node.attributes;
                    const { length } = attributes;
                    // Per
                    // https://developer.mozilla.org/en-US/docs/Web/API/NamedNodeMap,
                    // attributes are not guaranteed to be returned in document order.
                    // In particular, Edge/IE can return them out of order, so we cannot
                    // assume a correspondence between part index and attribute index.
                    let count = 0;
                    for (let i = 0; i < length; i++) {
                        if (endsWith(attributes[i].name, boundAttributeSuffix)) {
                            count++;
                        }
                    }
                    while (count-- > 0) {
                        // Get the template literal section leading up to the first
                        // expression in this attribute
                        const stringForPart = strings[partIndex];
                        // Find the attribute name
                        const name = lastAttributeNameRegex.exec(stringForPart)[2];
                        // Find the corresponding attribute
                        // All bound attributes have had a suffix added in
                        // TemplateResult#getHTML to opt out of special attribute
                        // handling. To look up the attribute value we also need to add
                        // the suffix.
                        const attributeLookupName = name.toLowerCase() + boundAttributeSuffix;
                        const attributeValue = node.getAttribute(attributeLookupName);
                        node.removeAttribute(attributeLookupName);
                        const statics = attributeValue.split(markerRegex);
                        this.parts.push({ type: 'attribute', index, name, strings: statics });
                        partIndex += statics.length - 1;
                    }
                }
                if (node.tagName === 'TEMPLATE') {
                    stack.push(node);
                    walker.currentNode = node.content;
                }
            }
            else if (node.nodeType === 3 /* Node.TEXT_NODE */) {
                const data = node.data;
                if (data.indexOf(marker) >= 0) {
                    const parent = node.parentNode;
                    const strings = data.split(markerRegex);
                    const lastIndex = strings.length - 1;
                    // Generate a new text node for each literal section
                    // These nodes are also used as the markers for node parts
                    for (let i = 0; i < lastIndex; i++) {
                        let insert;
                        let s = strings[i];
                        if (s === '') {
                            insert = createMarker();
                        }
                        else {
                            const match = lastAttributeNameRegex.exec(s);
                            if (match !== null && endsWith(match[2], boundAttributeSuffix)) {
                                s = s.slice(0, match.index) + match[1] +
                                    match[2].slice(0, -boundAttributeSuffix.length) + match[3];
                            }
                            insert = document.createTextNode(s);
                        }
                        parent.insertBefore(insert, node);
                        this.parts.push({ type: 'node', index: ++index });
                    }
                    // If there's no text, we must insert a comment to mark our place.
                    // Else, we can trust it will stick around after cloning.
                    if (strings[lastIndex] === '') {
                        parent.insertBefore(createMarker(), node);
                        nodesToRemove.push(node);
                    }
                    else {
                        node.data = strings[lastIndex];
                    }
                    // We have a part for each match found
                    partIndex += lastIndex;
                }
            }
            else if (node.nodeType === 8 /* Node.COMMENT_NODE */) {
                if (node.data === marker) {
                    const parent = node.parentNode;
                    // Add a new marker node to be the startNode of the Part if any of
                    // the following are true:
                    //  * We don't have a previousSibling
                    //  * The previousSibling is already the start of a previous part
                    if (node.previousSibling === null || index === lastPartIndex) {
                        index++;
                        parent.insertBefore(createMarker(), node);
                    }
                    lastPartIndex = index;
                    this.parts.push({ type: 'node', index });
                    // If we don't have a nextSibling, keep this node so we have an end.
                    // Else, we can remove it to save future costs.
                    if (node.nextSibling === null) {
                        node.data = '';
                    }
                    else {
                        nodesToRemove.push(node);
                        index--;
                    }
                    partIndex++;
                }
                else {
                    let i = -1;
                    while ((i = node.data.indexOf(marker, i + 1)) !== -1) {
                        // Comment node has a binding marker inside, make an inactive part
                        // The binding won't work, but subsequent bindings will
                        // TODO (justinfagnani): consider whether it's even worth it to
                        // make bindings in comments work
                        this.parts.push({ type: 'node', index: -1 });
                        partIndex++;
                    }
                }
            }
        }
        // Remove text binding nodes after the walk to not disturb the TreeWalker
        for (const n of nodesToRemove) {
            n.parentNode.removeChild(n);
        }
    }
}
const endsWith = (str, suffix) => {
    const index = str.length - suffix.length;
    return index >= 0 && str.slice(index) === suffix;
};
const isTemplatePartActive = (part) => part.index !== -1;
// Allows `document.createComment('')` to be renamed for a
// small manual size-savings.
const createMarker = () => document.createComment('');
/**
 * This regex extracts the attribute name preceding an attribute-position
 * expression. It does this by matching the syntax allowed for attributes
 * against the string literal directly preceding the expression, assuming that
 * the expression is in an attribute-value position.
 *
 * See attributes in the HTML spec:
 * https://www.w3.org/TR/html5/syntax.html#elements-attributes
 *
 * " \x09\x0a\x0c\x0d" are HTML space characters:
 * https://www.w3.org/TR/html5/infrastructure.html#space-characters
 *
 * "\0-\x1F\x7F-\x9F" are Unicode control characters, which includes every
 * space character except " ".
 *
 * So an attribute is:
 *  * The name: any character except a control character, space character, ('),
 *    ("), ">", "=", or "/"
 *  * Followed by zero or more space characters
 *  * Followed by "="
 *  * Followed by zero or more space characters
 *  * Followed by:
 *    * Any character except space, ('), ("), "<", ">", "=", (`), or
 *    * (") then any non-("), or
 *    * (') then any non-(')
 */
const lastAttributeNameRegex =
// eslint-disable-next-line no-control-regex
/([ \x09\x0a\x0c\x0d])([^\0-\x1F\x7F-\x9F "'>=/]+)([ \x09\x0a\x0c\x0d]*=[ \x09\x0a\x0c\x0d]*(?:[^ \x09\x0a\x0c\x0d"'`<>=]*|"[^"]*|'[^']*))$/;

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
const walkerNodeFilter = 133 /* NodeFilter.SHOW_{ELEMENT|COMMENT|TEXT} */;
/**
 * Removes the list of nodes from a Template safely. In addition to removing
 * nodes from the Template, the Template part indices are updated to match
 * the mutated Template DOM.
 *
 * As the template is walked the removal state is tracked and
 * part indices are adjusted as needed.
 *
 * div
 *   div#1 (remove) <-- start removing (removing node is div#1)
 *     div
 *       div#2 (remove)  <-- continue removing (removing node is still div#1)
 *         div
 * div <-- stop removing since previous sibling is the removing node (div#1,
 * removed 4 nodes)
 */
function removeNodesFromTemplate(template, nodesToRemove) {
    const { element: { content }, parts } = template;
    const walker = document.createTreeWalker(content, walkerNodeFilter, null, false);
    let partIndex = nextActiveIndexInTemplateParts(parts);
    let part = parts[partIndex];
    let nodeIndex = -1;
    let removeCount = 0;
    const nodesToRemoveInTemplate = [];
    let currentRemovingNode = null;
    while (walker.nextNode()) {
        nodeIndex++;
        const node = walker.currentNode;
        // End removal if stepped past the removing node
        if (node.previousSibling === currentRemovingNode) {
            currentRemovingNode = null;
        }
        // A node to remove was found in the template
        if (nodesToRemove.has(node)) {
            nodesToRemoveInTemplate.push(node);
            // Track node we're removing
            if (currentRemovingNode === null) {
                currentRemovingNode = node;
            }
        }
        // When removing, increment count by which to adjust subsequent part indices
        if (currentRemovingNode !== null) {
            removeCount++;
        }
        while (part !== undefined && part.index === nodeIndex) {
            // If part is in a removed node deactivate it by setting index to -1 or
            // adjust the index as needed.
            part.index = currentRemovingNode !== null ? -1 : part.index - removeCount;
            // go to the next active part.
            partIndex = nextActiveIndexInTemplateParts(parts, partIndex);
            part = parts[partIndex];
        }
    }
    nodesToRemoveInTemplate.forEach((n) => n.parentNode.removeChild(n));
}
const countNodes = (node) => {
    let count = (node.nodeType === 11 /* Node.DOCUMENT_FRAGMENT_NODE */) ? 0 : 1;
    const walker = document.createTreeWalker(node, walkerNodeFilter, null, false);
    while (walker.nextNode()) {
        count++;
    }
    return count;
};
const nextActiveIndexInTemplateParts = (parts, startIndex = -1) => {
    for (let i = startIndex + 1; i < parts.length; i++) {
        const part = parts[i];
        if (isTemplatePartActive(part)) {
            return i;
        }
    }
    return -1;
};
/**
 * Inserts the given node into the Template, optionally before the given
 * refNode. In addition to inserting the node into the Template, the Template
 * part indices are updated to match the mutated Template DOM.
 */
function insertNodeIntoTemplate(template, node, refNode = null) {
    const { element: { content }, parts } = template;
    // If there's no refNode, then put node at end of template.
    // No part indices need to be shifted in this case.
    if (refNode === null || refNode === undefined) {
        content.appendChild(node);
        return;
    }
    const walker = document.createTreeWalker(content, walkerNodeFilter, null, false);
    let partIndex = nextActiveIndexInTemplateParts(parts);
    let insertCount = 0;
    let walkerIndex = -1;
    while (walker.nextNode()) {
        walkerIndex++;
        const walkerNode = walker.currentNode;
        if (walkerNode === refNode) {
            insertCount = countNodes(node);
            refNode.parentNode.insertBefore(node, refNode);
        }
        while (partIndex !== -1 && parts[partIndex].index === walkerIndex) {
            // If we've inserted the node, simply adjust all subsequent parts
            if (insertCount > 0) {
                while (partIndex !== -1) {
                    parts[partIndex].index += insertCount;
                    partIndex = nextActiveIndexInTemplateParts(parts, partIndex);
                }
                return;
            }
            partIndex = nextActiveIndexInTemplateParts(parts, partIndex);
        }
    }
}

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
const directives = new WeakMap();
const isDirective = (o) => {
    return typeof o === 'function' && directives.has(o);
};

/**
 * @license
 * Copyright (c) 2018 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
/**
 * A sentinel value that signals that a value was handled by a directive and
 * should not be written to the DOM.
 */
const noChange = {};
/**
 * A sentinel value that signals a NodePart to fully clear its content.
 */
const nothing = {};

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
/**
 * An instance of a `Template` that can be attached to the DOM and updated
 * with new values.
 */
class TemplateInstance {
    constructor(template, processor, options) {
        this.__parts = [];
        this.template = template;
        this.processor = processor;
        this.options = options;
    }
    update(values) {
        let i = 0;
        for (const part of this.__parts) {
            if (part !== undefined) {
                part.setValue(values[i]);
            }
            i++;
        }
        for (const part of this.__parts) {
            if (part !== undefined) {
                part.commit();
            }
        }
    }
    _clone() {
        // There are a number of steps in the lifecycle of a template instance's
        // DOM fragment:
        //  1. Clone - create the instance fragment
        //  2. Adopt - adopt into the main document
        //  3. Process - find part markers and create parts
        //  4. Upgrade - upgrade custom elements
        //  5. Update - set node, attribute, property, etc., values
        //  6. Connect - connect to the document. Optional and outside of this
        //     method.
        //
        // We have a few constraints on the ordering of these steps:
        //  * We need to upgrade before updating, so that property values will pass
        //    through any property setters.
        //  * We would like to process before upgrading so that we're sure that the
        //    cloned fragment is inert and not disturbed by self-modifying DOM.
        //  * We want custom elements to upgrade even in disconnected fragments.
        //
        // Given these constraints, with full custom elements support we would
        // prefer the order: Clone, Process, Adopt, Upgrade, Update, Connect
        //
        // But Safari does not implement CustomElementRegistry#upgrade, so we
        // can not implement that order and still have upgrade-before-update and
        // upgrade disconnected fragments. So we instead sacrifice the
        // process-before-upgrade constraint, since in Custom Elements v1 elements
        // must not modify their light DOM in the constructor. We still have issues
        // when co-existing with CEv0 elements like Polymer 1, and with polyfills
        // that don't strictly adhere to the no-modification rule because shadow
        // DOM, which may be created in the constructor, is emulated by being placed
        // in the light DOM.
        //
        // The resulting order is on native is: Clone, Adopt, Upgrade, Process,
        // Update, Connect. document.importNode() performs Clone, Adopt, and Upgrade
        // in one step.
        //
        // The Custom Elements v1 polyfill supports upgrade(), so the order when
        // polyfilled is the more ideal: Clone, Process, Adopt, Upgrade, Update,
        // Connect.
        const fragment = isCEPolyfill ?
            this.template.element.content.cloneNode(true) :
            document.importNode(this.template.element.content, true);
        const stack = [];
        const parts = this.template.parts;
        // Edge needs all 4 parameters present; IE11 needs 3rd parameter to be null
        const walker = document.createTreeWalker(fragment, 133 /* NodeFilter.SHOW_{ELEMENT|COMMENT|TEXT} */, null, false);
        let partIndex = 0;
        let nodeIndex = 0;
        let part;
        let node = walker.nextNode();
        // Loop through all the nodes and parts of a template
        while (partIndex < parts.length) {
            part = parts[partIndex];
            if (!isTemplatePartActive(part)) {
                this.__parts.push(undefined);
                partIndex++;
                continue;
            }
            // Progress the tree walker until we find our next part's node.
            // Note that multiple parts may share the same node (attribute parts
            // on a single element), so this loop may not run at all.
            while (nodeIndex < part.index) {
                nodeIndex++;
                if (node.nodeName === 'TEMPLATE') {
                    stack.push(node);
                    walker.currentNode = node.content;
                }
                if ((node = walker.nextNode()) === null) {
                    // We've exhausted the content inside a nested template element.
                    // Because we still have parts (the outer for-loop), we know:
                    // - There is a template in the stack
                    // - The walker will find a nextNode outside the template
                    walker.currentNode = stack.pop();
                    node = walker.nextNode();
                }
            }
            // We've arrived at our part's node.
            if (part.type === 'node') {
                const part = this.processor.handleTextExpression(this.options);
                part.insertAfterNode(node.previousSibling);
                this.__parts.push(part);
            }
            else {
                this.__parts.push(...this.processor.handleAttributeExpressions(node, part.name, part.strings, this.options));
            }
            partIndex++;
        }
        if (isCEPolyfill) {
            document.adoptNode(fragment);
            customElements.upgrade(fragment);
        }
        return fragment;
    }
}

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
const commentMarker = ` ${marker} `;
/**
 * The return type of `html`, which holds a Template and the values from
 * interpolated expressions.
 */
class TemplateResult {
    constructor(strings, values, type, processor) {
        this.strings = strings;
        this.values = values;
        this.type = type;
        this.processor = processor;
    }
    /**
     * Returns a string of HTML used to create a `<template>` element.
     */
    getHTML() {
        const l = this.strings.length - 1;
        let html = '';
        let isCommentBinding = false;
        for (let i = 0; i < l; i++) {
            const s = this.strings[i];
            // For each binding we want to determine the kind of marker to insert
            // into the template source before it's parsed by the browser's HTML
            // parser. The marker type is based on whether the expression is in an
            // attribute, text, or comment position.
            //   * For node-position bindings we insert a comment with the marker
            //     sentinel as its text content, like <!--{{lit-guid}}-->.
            //   * For attribute bindings we insert just the marker sentinel for the
            //     first binding, so that we support unquoted attribute bindings.
            //     Subsequent bindings can use a comment marker because multi-binding
            //     attributes must be quoted.
            //   * For comment bindings we insert just the marker sentinel so we don't
            //     close the comment.
            //
            // The following code scans the template source, but is *not* an HTML
            // parser. We don't need to track the tree structure of the HTML, only
            // whether a binding is inside a comment, and if not, if it appears to be
            // the first binding in an attribute.
            const commentOpen = s.lastIndexOf('<!--');
            // We're in comment position if we have a comment open with no following
            // comment close. Because <-- can appear in an attribute value there can
            // be false positives.
            isCommentBinding = (commentOpen > -1 || isCommentBinding) &&
                s.indexOf('-->', commentOpen + 1) === -1;
            // Check to see if we have an attribute-like sequence preceding the
            // expression. This can match "name=value" like structures in text,
            // comments, and attribute values, so there can be false-positives.
            const attributeMatch = lastAttributeNameRegex.exec(s);
            if (attributeMatch === null) {
                // We're only in this branch if we don't have a attribute-like
                // preceding sequence. For comments, this guards against unusual
                // attribute values like <div foo="<!--${'bar'}">. Cases like
                // <!-- foo=${'bar'}--> are handled correctly in the attribute branch
                // below.
                html += s + (isCommentBinding ? commentMarker : nodeMarker);
            }
            else {
                // For attributes we use just a marker sentinel, and also append a
                // $lit$ suffix to the name to opt-out of attribute-specific parsing
                // that IE and Edge do for style and certain SVG attributes.
                html += s.substr(0, attributeMatch.index) + attributeMatch[1] +
                    attributeMatch[2] + boundAttributeSuffix + attributeMatch[3] +
                    marker;
            }
        }
        html += this.strings[l];
        return html;
    }
    getTemplateElement() {
        const template = document.createElement('template');
        template.innerHTML = this.getHTML();
        return template;
    }
}

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
const isPrimitive = (value) => {
    return (value === null ||
        !(typeof value === 'object' || typeof value === 'function'));
};
const isIterable = (value) => {
    return Array.isArray(value) ||
        // eslint-disable-next-line @typescript-eslint/no-explicit-any
        !!(value && value[Symbol.iterator]);
};
/**
 * Writes attribute values to the DOM for a group of AttributeParts bound to a
 * single attribute. The value is only set once even if there are multiple parts
 * for an attribute.
 */
class AttributeCommitter {
    constructor(element, name, strings) {
        this.dirty = true;
        this.element = element;
        this.name = name;
        this.strings = strings;
        this.parts = [];
        for (let i = 0; i < strings.length - 1; i++) {
            this.parts[i] = this._createPart();
        }
    }
    /**
     * Creates a single part. Override this to create a differnt type of part.
     */
    _createPart() {
        return new AttributePart(this);
    }
    _getValue() {
        const strings = this.strings;
        const l = strings.length - 1;
        let text = '';
        for (let i = 0; i < l; i++) {
            text += strings[i];
            const part = this.parts[i];
            if (part !== undefined) {
                const v = part.value;
                if (isPrimitive(v) || !isIterable(v)) {
                    text += typeof v === 'string' ? v : String(v);
                }
                else {
                    for (const t of v) {
                        text += typeof t === 'string' ? t : String(t);
                    }
                }
            }
        }
        text += strings[l];
        return text;
    }
    commit() {
        if (this.dirty) {
            this.dirty = false;
            this.element.setAttribute(this.name, this._getValue());
        }
    }
}
/**
 * A Part that controls all or part of an attribute value.
 */
class AttributePart {
    constructor(committer) {
        this.value = undefined;
        this.committer = committer;
    }
    setValue(value) {
        if (value !== noChange && (!isPrimitive(value) || value !== this.value)) {
            this.value = value;
            // If the value is a not a directive, dirty the committer so that it'll
            // call setAttribute. If the value is a directive, it'll dirty the
            // committer if it calls setValue().
            if (!isDirective(value)) {
                this.committer.dirty = true;
            }
        }
    }
    commit() {
        while (isDirective(this.value)) {
            const directive = this.value;
            this.value = noChange;
            directive(this);
        }
        if (this.value === noChange) {
            return;
        }
        this.committer.commit();
    }
}
/**
 * A Part that controls a location within a Node tree. Like a Range, NodePart
 * has start and end locations and can set and update the Nodes between those
 * locations.
 *
 * NodeParts support several value types: primitives, Nodes, TemplateResults,
 * as well as arrays and iterables of those types.
 */
class NodePart {
    constructor(options) {
        this.value = undefined;
        this.__pendingValue = undefined;
        this.options = options;
    }
    /**
     * Appends this part into a container.
     *
     * This part must be empty, as its contents are not automatically moved.
     */
    appendInto(container) {
        this.startNode = container.appendChild(createMarker());
        this.endNode = container.appendChild(createMarker());
    }
    /**
     * Inserts this part after the `ref` node (between `ref` and `ref`'s next
     * sibling). Both `ref` and its next sibling must be static, unchanging nodes
     * such as those that appear in a literal section of a template.
     *
     * This part must be empty, as its contents are not automatically moved.
     */
    insertAfterNode(ref) {
        this.startNode = ref;
        this.endNode = ref.nextSibling;
    }
    /**
     * Appends this part into a parent part.
     *
     * This part must be empty, as its contents are not automatically moved.
     */
    appendIntoPart(part) {
        part.__insert(this.startNode = createMarker());
        part.__insert(this.endNode = createMarker());
    }
    /**
     * Inserts this part after the `ref` part.
     *
     * This part must be empty, as its contents are not automatically moved.
     */
    insertAfterPart(ref) {
        ref.__insert(this.startNode = createMarker());
        this.endNode = ref.endNode;
        ref.endNode = this.startNode;
    }
    setValue(value) {
        this.__pendingValue = value;
    }
    commit() {
        if (this.startNode.parentNode === null) {
            return;
        }
        while (isDirective(this.__pendingValue)) {
            const directive = this.__pendingValue;
            this.__pendingValue = noChange;
            directive(this);
        }
        const value = this.__pendingValue;
        if (value === noChange) {
            return;
        }
        if (isPrimitive(value)) {
            if (value !== this.value) {
                this.__commitText(value);
            }
        }
        else if (value instanceof TemplateResult) {
            this.__commitTemplateResult(value);
        }
        else if (value instanceof Node) {
            this.__commitNode(value);
        }
        else if (isIterable(value)) {
            this.__commitIterable(value);
        }
        else if (value === nothing) {
            this.value = nothing;
            this.clear();
        }
        else {
            // Fallback, will render the string representation
            this.__commitText(value);
        }
    }
    __insert(node) {
        this.endNode.parentNode.insertBefore(node, this.endNode);
    }
    __commitNode(value) {
        if (this.value === value) {
            return;
        }
        this.clear();
        this.__insert(value);
        this.value = value;
    }
    __commitText(value) {
        const node = this.startNode.nextSibling;
        value = value == null ? '' : value;
        // If `value` isn't already a string, we explicitly convert it here in case
        // it can't be implicitly converted - i.e. it's a symbol.
        const valueAsString = typeof value === 'string' ? value : String(value);
        if (node === this.endNode.previousSibling &&
            node.nodeType === 3 /* Node.TEXT_NODE */) {
            // If we only have a single text node between the markers, we can just
            // set its value, rather than replacing it.
            // TODO(justinfagnani): Can we just check if this.value is primitive?
            node.data = valueAsString;
        }
        else {
            this.__commitNode(document.createTextNode(valueAsString));
        }
        this.value = value;
    }
    __commitTemplateResult(value) {
        const template = this.options.templateFactory(value);
        if (this.value instanceof TemplateInstance &&
            this.value.template === template) {
            this.value.update(value.values);
        }
        else {
            // Make sure we propagate the template processor from the TemplateResult
            // so that we use its syntax extension, etc. The template factory comes
            // from the render function options so that it can control template
            // caching and preprocessing.
            const instance = new TemplateInstance(template, value.processor, this.options);
            const fragment = instance._clone();
            instance.update(value.values);
            this.__commitNode(fragment);
            this.value = instance;
        }
    }
    __commitIterable(value) {
        // For an Iterable, we create a new InstancePart per item, then set its
        // value to the item. This is a little bit of overhead for every item in
        // an Iterable, but it lets us recurse easily and efficiently update Arrays
        // of TemplateResults that will be commonly returned from expressions like:
        // array.map((i) => html`${i}`), by reusing existing TemplateInstances.
        // If _value is an array, then the previous render was of an
        // iterable and _value will contain the NodeParts from the previous
        // render. If _value is not an array, clear this part and make a new
        // array for NodeParts.
        if (!Array.isArray(this.value)) {
            this.value = [];
            this.clear();
        }
        // Lets us keep track of how many items we stamped so we can clear leftover
        // items from a previous render
        const itemParts = this.value;
        let partIndex = 0;
        let itemPart;
        for (const item of value) {
            // Try to reuse an existing part
            itemPart = itemParts[partIndex];
            // If no existing part, create a new one
            if (itemPart === undefined) {
                itemPart = new NodePart(this.options);
                itemParts.push(itemPart);
                if (partIndex === 0) {
                    itemPart.appendIntoPart(this);
                }
                else {
                    itemPart.insertAfterPart(itemParts[partIndex - 1]);
                }
            }
            itemPart.setValue(item);
            itemPart.commit();
            partIndex++;
        }
        if (partIndex < itemParts.length) {
            // Truncate the parts array so _value reflects the current state
            itemParts.length = partIndex;
            this.clear(itemPart && itemPart.endNode);
        }
    }
    clear(startNode = this.startNode) {
        removeNodes(this.startNode.parentNode, startNode.nextSibling, this.endNode);
    }
}
/**
 * Implements a boolean attribute, roughly as defined in the HTML
 * specification.
 *
 * If the value is truthy, then the attribute is present with a value of
 * ''. If the value is falsey, the attribute is removed.
 */
class BooleanAttributePart {
    constructor(element, name, strings) {
        this.value = undefined;
        this.__pendingValue = undefined;
        if (strings.length !== 2 || strings[0] !== '' || strings[1] !== '') {
            throw new Error('Boolean attributes can only contain a single expression');
        }
        this.element = element;
        this.name = name;
        this.strings = strings;
    }
    setValue(value) {
        this.__pendingValue = value;
    }
    commit() {
        while (isDirective(this.__pendingValue)) {
            const directive = this.__pendingValue;
            this.__pendingValue = noChange;
            directive(this);
        }
        if (this.__pendingValue === noChange) {
            return;
        }
        const value = !!this.__pendingValue;
        if (this.value !== value) {
            if (value) {
                this.element.setAttribute(this.name, '');
            }
            else {
                this.element.removeAttribute(this.name);
            }
            this.value = value;
        }
        this.__pendingValue = noChange;
    }
}
/**
 * Sets attribute values for PropertyParts, so that the value is only set once
 * even if there are multiple parts for a property.
 *
 * If an expression controls the whole property value, then the value is simply
 * assigned to the property under control. If there are string literals or
 * multiple expressions, then the strings are expressions are interpolated into
 * a string first.
 */
class PropertyCommitter extends AttributeCommitter {
    constructor(element, name, strings) {
        super(element, name, strings);
        this.single =
            (strings.length === 2 && strings[0] === '' && strings[1] === '');
    }
    _createPart() {
        return new PropertyPart(this);
    }
    _getValue() {
        if (this.single) {
            return this.parts[0].value;
        }
        return super._getValue();
    }
    commit() {
        if (this.dirty) {
            this.dirty = false;
            // eslint-disable-next-line @typescript-eslint/no-explicit-any
            this.element[this.name] = this._getValue();
        }
    }
}
class PropertyPart extends AttributePart {
}
// Detect event listener options support. If the `capture` property is read
// from the options object, then options are supported. If not, then the third
// argument to add/removeEventListener is interpreted as the boolean capture
// value so we should only pass the `capture` property.
let eventOptionsSupported = false;
// Wrap into an IIFE because MS Edge <= v41 does not support having try/catch
// blocks right into the body of a module
(() => {
    try {
        const options = {
            get capture() {
                eventOptionsSupported = true;
                return false;
            }
        };
        // eslint-disable-next-line @typescript-eslint/no-explicit-any
        window.addEventListener('test', options, options);
        // eslint-disable-next-line @typescript-eslint/no-explicit-any
        window.removeEventListener('test', options, options);
    }
    catch (_e) {
        // event options not supported
    }
})();
class EventPart {
    constructor(element, eventName, eventContext) {
        this.value = undefined;
        this.__pendingValue = undefined;
        this.element = element;
        this.eventName = eventName;
        this.eventContext = eventContext;
        this.__boundHandleEvent = (e) => this.handleEvent(e);
    }
    setValue(value) {
        this.__pendingValue = value;
    }
    commit() {
        while (isDirective(this.__pendingValue)) {
            const directive = this.__pendingValue;
            this.__pendingValue = noChange;
            directive(this);
        }
        if (this.__pendingValue === noChange) {
            return;
        }
        const newListener = this.__pendingValue;
        const oldListener = this.value;
        const shouldRemoveListener = newListener == null ||
            oldListener != null &&
                (newListener.capture !== oldListener.capture ||
                    newListener.once !== oldListener.once ||
                    newListener.passive !== oldListener.passive);
        const shouldAddListener = newListener != null && (oldListener == null || shouldRemoveListener);
        if (shouldRemoveListener) {
            this.element.removeEventListener(this.eventName, this.__boundHandleEvent, this.__options);
        }
        if (shouldAddListener) {
            this.__options = getOptions(newListener);
            this.element.addEventListener(this.eventName, this.__boundHandleEvent, this.__options);
        }
        this.value = newListener;
        this.__pendingValue = noChange;
    }
    handleEvent(event) {
        if (typeof this.value === 'function') {
            this.value.call(this.eventContext || this.element, event);
        }
        else {
            this.value.handleEvent(event);
        }
    }
}
// We copy options because of the inconsistent behavior of browsers when reading
// the third argument of add/removeEventListener. IE11 doesn't support options
// at all. Chrome 41 only reads `capture` if the argument is an object.
const getOptions = (o) => o &&
    (eventOptionsSupported ?
        { capture: o.capture, passive: o.passive, once: o.once } :
        o.capture);

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
/**
 * The default TemplateFactory which caches Templates keyed on
 * result.type and result.strings.
 */
function templateFactory(result) {
    let templateCache = templateCaches.get(result.type);
    if (templateCache === undefined) {
        templateCache = {
            stringsArray: new WeakMap(),
            keyString: new Map()
        };
        templateCaches.set(result.type, templateCache);
    }
    let template = templateCache.stringsArray.get(result.strings);
    if (template !== undefined) {
        return template;
    }
    // If the TemplateStringsArray is new, generate a key from the strings
    // This key is shared between all templates with identical content
    const key = result.strings.join(marker);
    // Check if we already have a Template for this key
    template = templateCache.keyString.get(key);
    if (template === undefined) {
        // If we have not seen this key before, create a new Template
        template = new Template(result, result.getTemplateElement());
        // Cache the Template for this key
        templateCache.keyString.set(key, template);
    }
    // Cache all future queries for this TemplateStringsArray
    templateCache.stringsArray.set(result.strings, template);
    return template;
}
const templateCaches = new Map();

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
const parts = new WeakMap();
/**
 * Renders a template result or other value to a container.
 *
 * To update a container with new values, reevaluate the template literal and
 * call `render` with the new result.
 *
 * @param result Any value renderable by NodePart - typically a TemplateResult
 *     created by evaluating a template tag like `html` or `svg`.
 * @param container A DOM parent to render to. The entire contents are either
 *     replaced, or efficiently updated if the same result type was previous
 *     rendered there.
 * @param options RenderOptions for the entire render tree rendered to this
 *     container. Render options must *not* change between renders to the same
 *     container, as those changes will not effect previously rendered DOM.
 */
const render = (result, container, options) => {
    let part = parts.get(container);
    if (part === undefined) {
        removeNodes(container, container.firstChild);
        parts.set(container, part = new NodePart(Object.assign({ templateFactory }, options)));
        part.appendInto(container);
    }
    part.setValue(result);
    part.commit();
};

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
/**
 * Creates Parts when a template is instantiated.
 */
class DefaultTemplateProcessor {
    /**
     * Create parts for an attribute-position binding, given the event, attribute
     * name, and string literals.
     *
     * @param element The element containing the binding
     * @param name  The attribute name
     * @param strings The string literals. There are always at least two strings,
     *   event for fully-controlled bindings with a single expression.
     */
    handleAttributeExpressions(element, name, strings, options) {
        const prefix = name[0];
        if (prefix === '.') {
            const committer = new PropertyCommitter(element, name.slice(1), strings);
            return committer.parts;
        }
        if (prefix === '@') {
            return [new EventPart(element, name.slice(1), options.eventContext)];
        }
        if (prefix === '?') {
            return [new BooleanAttributePart(element, name.slice(1), strings)];
        }
        const committer = new AttributeCommitter(element, name, strings);
        return committer.parts;
    }
    /**
     * Create parts for a text-position binding.
     * @param templateFactory
     */
    handleTextExpression(options) {
        return new NodePart(options);
    }
}
const defaultTemplateProcessor = new DefaultTemplateProcessor();

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
// IMPORTANT: do not change the property name or the assignment expression.
// This line will be used in regexes to search for lit-html usage.
// TODO(justinfagnani): inject version number at build time
if (typeof window !== 'undefined') {
    (window['litHtmlVersions'] || (window['litHtmlVersions'] = [])).push('1.2.1');
}
/**
 * Interprets a template literal as an HTML template that can efficiently
 * render to and update a container.
 */
const html = (strings, ...values) => new TemplateResult(strings, values, 'html', defaultTemplateProcessor);

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
// Get a key to lookup in `templateCaches`.
const getTemplateCacheKey = (type, scopeName) => `${type}--${scopeName}`;
let compatibleShadyCSSVersion = true;
if (typeof window.ShadyCSS === 'undefined') {
    compatibleShadyCSSVersion = false;
}
else if (typeof window.ShadyCSS.prepareTemplateDom === 'undefined') {
    console.warn(`Incompatible ShadyCSS version detected. ` +
        `Please update to at least @webcomponents/webcomponentsjs@2.0.2 and ` +
        `@webcomponents/shadycss@1.3.1.`);
    compatibleShadyCSSVersion = false;
}
/**
 * Template factory which scopes template DOM using ShadyCSS.
 * @param scopeName {string}
 */
const shadyTemplateFactory = (scopeName) => (result) => {
    const cacheKey = getTemplateCacheKey(result.type, scopeName);
    let templateCache = templateCaches.get(cacheKey);
    if (templateCache === undefined) {
        templateCache = {
            stringsArray: new WeakMap(),
            keyString: new Map()
        };
        templateCaches.set(cacheKey, templateCache);
    }
    let template = templateCache.stringsArray.get(result.strings);
    if (template !== undefined) {
        return template;
    }
    const key = result.strings.join(marker);
    template = templateCache.keyString.get(key);
    if (template === undefined) {
        const element = result.getTemplateElement();
        if (compatibleShadyCSSVersion) {
            window.ShadyCSS.prepareTemplateDom(element, scopeName);
        }
        template = new Template(result, element);
        templateCache.keyString.set(key, template);
    }
    templateCache.stringsArray.set(result.strings, template);
    return template;
};
const TEMPLATE_TYPES = ['html', 'svg'];
/**
 * Removes all style elements from Templates for the given scopeName.
 */
const removeStylesFromLitTemplates = (scopeName) => {
    TEMPLATE_TYPES.forEach((type) => {
        const templates = templateCaches.get(getTemplateCacheKey(type, scopeName));
        if (templates !== undefined) {
            templates.keyString.forEach((template) => {
                const { element: { content } } = template;
                // IE 11 doesn't support the iterable param Set constructor
                const styles = new Set();
                Array.from(content.querySelectorAll('style')).forEach((s) => {
                    styles.add(s);
                });
                removeNodesFromTemplate(template, styles);
            });
        }
    });
};
const shadyRenderSet = new Set();
/**
 * For the given scope name, ensures that ShadyCSS style scoping is performed.
 * This is done just once per scope name so the fragment and template cannot
 * be modified.
 * (1) extracts styles from the rendered fragment and hands them to ShadyCSS
 * to be scoped and appended to the document
 * (2) removes style elements from all lit-html Templates for this scope name.
 *
 * Note, <style> elements can only be placed into templates for the
 * initial rendering of the scope. If <style> elements are included in templates
 * dynamically rendered to the scope (after the first scope render), they will
 * not be scoped and the <style> will be left in the template and rendered
 * output.
 */
const prepareTemplateStyles = (scopeName, renderedDOM, template) => {
    shadyRenderSet.add(scopeName);
    // If `renderedDOM` is stamped from a Template, then we need to edit that
    // Template's underlying template element. Otherwise, we create one here
    // to give to ShadyCSS, which still requires one while scoping.
    const templateElement = !!template ? template.element : document.createElement('template');
    // Move styles out of rendered DOM and store.
    const styles = renderedDOM.querySelectorAll('style');
    const { length } = styles;
    // If there are no styles, skip unnecessary work
    if (length === 0) {
        // Ensure prepareTemplateStyles is called to support adding
        // styles via `prepareAdoptedCssText` since that requires that
        // `prepareTemplateStyles` is called.
        //
        // ShadyCSS will only update styles containing @apply in the template
        // given to `prepareTemplateStyles`. If no lit Template was given,
        // ShadyCSS will not be able to update uses of @apply in any relevant
        // template. However, this is not a problem because we only create the
        // template for the purpose of supporting `prepareAdoptedCssText`,
        // which doesn't support @apply at all.
        window.ShadyCSS.prepareTemplateStyles(templateElement, scopeName);
        return;
    }
    const condensedStyle = document.createElement('style');
    // Collect styles into a single style. This helps us make sure ShadyCSS
    // manipulations will not prevent us from being able to fix up template
    // part indices.
    // NOTE: collecting styles is inefficient for browsers but ShadyCSS
    // currently does this anyway. When it does not, this should be changed.
    for (let i = 0; i < length; i++) {
        const style = styles[i];
        style.parentNode.removeChild(style);
        condensedStyle.textContent += style.textContent;
    }
    // Remove styles from nested templates in this scope.
    removeStylesFromLitTemplates(scopeName);
    // And then put the condensed style into the "root" template passed in as
    // `template`.
    const content = templateElement.content;
    if (!!template) {
        insertNodeIntoTemplate(template, condensedStyle, content.firstChild);
    }
    else {
        content.insertBefore(condensedStyle, content.firstChild);
    }
    // Note, it's important that ShadyCSS gets the template that `lit-html`
    // will actually render so that it can update the style inside when
    // needed (e.g. @apply native Shadow DOM case).
    window.ShadyCSS.prepareTemplateStyles(templateElement, scopeName);
    const style = content.querySelector('style');
    if (window.ShadyCSS.nativeShadow && style !== null) {
        // When in native Shadow DOM, ensure the style created by ShadyCSS is
        // included in initially rendered output (`renderedDOM`).
        renderedDOM.insertBefore(style.cloneNode(true), renderedDOM.firstChild);
    }
    else if (!!template) {
        // When no style is left in the template, parts will be broken as a
        // result. To fix this, we put back the style node ShadyCSS removed
        // and then tell lit to remove that node from the template.
        // There can be no style in the template in 2 cases (1) when Shady DOM
        // is in use, ShadyCSS removes all styles, (2) when native Shadow DOM
        // is in use ShadyCSS removes the style if it contains no content.
        // NOTE, ShadyCSS creates its own style so we can safely add/remove
        // `condensedStyle` here.
        content.insertBefore(condensedStyle, content.firstChild);
        const removes = new Set();
        removes.add(condensedStyle);
        removeNodesFromTemplate(template, removes);
    }
};
/**
 * Extension to the standard `render` method which supports rendering
 * to ShadowRoots when the ShadyDOM (https://github.com/webcomponents/shadydom)
 * and ShadyCSS (https://github.com/webcomponents/shadycss) polyfills are used
 * or when the webcomponentsjs
 * (https://github.com/webcomponents/webcomponentsjs) polyfill is used.
 *
 * Adds a `scopeName` option which is used to scope element DOM and stylesheets
 * when native ShadowDOM is unavailable. The `scopeName` will be added to
 * the class attribute of all rendered DOM. In addition, any style elements will
 * be automatically re-written with this `scopeName` selector and moved out
 * of the rendered DOM and into the document `<head>`.
 *
 * It is common to use this render method in conjunction with a custom element
 * which renders a shadowRoot. When this is done, typically the element's
 * `localName` should be used as the `scopeName`.
 *
 * In addition to DOM scoping, ShadyCSS also supports a basic shim for css
 * custom properties (needed only on older browsers like IE11) and a shim for
 * a deprecated feature called `@apply` that supports applying a set of css
 * custom properties to a given location.
 *
 * Usage considerations:
 *
 * * Part values in `<style>` elements are only applied the first time a given
 * `scopeName` renders. Subsequent changes to parts in style elements will have
 * no effect. Because of this, parts in style elements should only be used for
 * values that will never change, for example parts that set scope-wide theme
 * values or parts which render shared style elements.
 *
 * * Note, due to a limitation of the ShadyDOM polyfill, rendering in a
 * custom element's `constructor` is not supported. Instead rendering should
 * either done asynchronously, for example at microtask timing (for example
 * `Promise.resolve()`), or be deferred until the first time the element's
 * `connectedCallback` runs.
 *
 * Usage considerations when using shimmed custom properties or `@apply`:
 *
 * * Whenever any dynamic changes are made which affect
 * css custom properties, `ShadyCSS.styleElement(element)` must be called
 * to update the element. There are two cases when this is needed:
 * (1) the element is connected to a new parent, (2) a class is added to the
 * element that causes it to match different custom properties.
 * To address the first case when rendering a custom element, `styleElement`
 * should be called in the element's `connectedCallback`.
 *
 * * Shimmed custom properties may only be defined either for an entire
 * shadowRoot (for example, in a `:host` rule) or via a rule that directly
 * matches an element with a shadowRoot. In other words, instead of flowing from
 * parent to child as do native css custom properties, shimmed custom properties
 * flow only from shadowRoots to nested shadowRoots.
 *
 * * When using `@apply` mixing css shorthand property names with
 * non-shorthand names (for example `border` and `border-width`) is not
 * supported.
 */
const render$1 = (result, container, options) => {
    if (!options || typeof options !== 'object' || !options.scopeName) {
        throw new Error('The `scopeName` option is required.');
    }
    const scopeName = options.scopeName;
    const hasRendered = parts.has(container);
    const needsScoping = compatibleShadyCSSVersion &&
        container.nodeType === 11 /* Node.DOCUMENT_FRAGMENT_NODE */ &&
        !!container.host;
    // Handle first render to a scope specially...
    const firstScopeRender = needsScoping && !shadyRenderSet.has(scopeName);
    // On first scope render, render into a fragment; this cannot be a single
    // fragment that is reused since nested renders can occur synchronously.
    const renderContainer = firstScopeRender ? document.createDocumentFragment() : container;
    render(result, renderContainer, Object.assign({ templateFactory: shadyTemplateFactory(scopeName) }, options));
    // When performing first scope render,
    // (1) We've rendered into a fragment so that there's a chance to
    // `prepareTemplateStyles` before sub-elements hit the DOM
    // (which might cause them to render based on a common pattern of
    // rendering in a custom element's `connectedCallback`);
    // (2) Scope the template with ShadyCSS one time only for this scope.
    // (3) Render the fragment into the container and make sure the
    // container knows its `part` is the one we just rendered. This ensures
    // DOM will be re-used on subsequent renders.
    if (firstScopeRender) {
        const part = parts.get(renderContainer);
        parts.delete(renderContainer);
        // ShadyCSS might have style sheets (e.g. from `prepareAdoptedCssText`)
        // that should apply to `renderContainer` even if the rendered value is
        // not a TemplateInstance. However, it will only insert scoped styles
        // into the document if `prepareTemplateStyles` has already been called
        // for the given scope name.
        const template = part.value instanceof TemplateInstance ?
            part.value.template :
            undefined;
        prepareTemplateStyles(scopeName, renderContainer, template);
        removeNodes(container, container.firstChild);
        container.appendChild(renderContainer);
        parts.set(container, part);
    }
    // After elements have hit the DOM, update styling if this is the
    // initial render to this container.
    // This is needed whenever dynamic changes are made so it would be
    // safest to do every render; however, this would regress performance
    // so we leave it up to the user to call `ShadyCSS.styleElement`
    // for dynamic changes.
    if (!hasRendered && needsScoping) {
        window.ShadyCSS.styleElement(container.host);
    }
};

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
var _a;
/**
 * When using Closure Compiler, JSCompiler_renameProperty(property, object) is
 * replaced at compile time by the munged name for object[property]. We cannot
 * alias this function, so we have to use a small shim that has the same
 * behavior when not compiling.
 */
window.JSCompiler_renameProperty =
    (prop, _obj) => prop;
const defaultConverter = {
    toAttribute(value, type) {
        switch (type) {
            case Boolean:
                return value ? '' : null;
            case Object:
            case Array:
                // if the value is `null` or `undefined` pass this through
                // to allow removing/no change behavior.
                return value == null ? value : JSON.stringify(value);
        }
        return value;
    },
    fromAttribute(value, type) {
        switch (type) {
            case Boolean:
                return value !== null;
            case Number:
                return value === null ? null : Number(value);
            case Object:
            case Array:
                return JSON.parse(value);
        }
        return value;
    }
};
/**
 * Change function that returns true if `value` is different from `oldValue`.
 * This method is used as the default for a property's `hasChanged` function.
 */
const notEqual = (value, old) => {
    // This ensures (old==NaN, value==NaN) always returns false
    return old !== value && (old === old || value === value);
};
const defaultPropertyDeclaration = {
    attribute: true,
    type: String,
    converter: defaultConverter,
    reflect: false,
    hasChanged: notEqual
};
const STATE_HAS_UPDATED = 1;
const STATE_UPDATE_REQUESTED = 1 << 2;
const STATE_IS_REFLECTING_TO_ATTRIBUTE = 1 << 3;
const STATE_IS_REFLECTING_TO_PROPERTY = 1 << 4;
/**
 * The Closure JS Compiler doesn't currently have good support for static
 * property semantics where "this" is dynamic (e.g.
 * https://github.com/google/closure-compiler/issues/3177 and others) so we use
 * this hack to bypass any rewriting by the compiler.
 */
const finalized = 'finalized';
/**
 * Base element class which manages element properties and attributes. When
 * properties change, the `update` method is asynchronously called. This method
 * should be supplied by subclassers to render updates as desired.
 */
class UpdatingElement extends HTMLElement {
    constructor() {
        super();
        this._updateState = 0;
        this._instanceProperties = undefined;
        // Initialize to an unresolved Promise so we can make sure the element has
        // connected before first update.
        this._updatePromise = new Promise((res) => this._enableUpdatingResolver = res);
        /**
         * Map with keys for any properties that have changed since the last
         * update cycle with previous values.
         */
        this._changedProperties = new Map();
        /**
         * Map with keys of properties that should be reflected when updated.
         */
        this._reflectingProperties = undefined;
        this.initialize();
    }
    /**
     * Returns a list of attributes corresponding to the registered properties.
     * @nocollapse
     */
    static get observedAttributes() {
        // note: piggy backing on this to ensure we're finalized.
        this.finalize();
        const attributes = [];
        // Use forEach so this works even if for/of loops are compiled to for loops
        // expecting arrays
        this._classProperties.forEach((v, p) => {
            const attr = this._attributeNameForProperty(p, v);
            if (attr !== undefined) {
                this._attributeToPropertyMap.set(attr, p);
                attributes.push(attr);
            }
        });
        return attributes;
    }
    /**
     * Ensures the private `_classProperties` property metadata is created.
     * In addition to `finalize` this is also called in `createProperty` to
     * ensure the `@property` decorator can add property metadata.
     */
    /** @nocollapse */
    static _ensureClassProperties() {
        // ensure private storage for property declarations.
        if (!this.hasOwnProperty(JSCompiler_renameProperty('_classProperties', this))) {
            this._classProperties = new Map();
            // NOTE: Workaround IE11 not supporting Map constructor argument.
            const superProperties = Object.getPrototypeOf(this)._classProperties;
            if (superProperties !== undefined) {
                superProperties.forEach((v, k) => this._classProperties.set(k, v));
            }
        }
    }
    /**
     * Creates a property accessor on the element prototype if one does not exist
     * and stores a PropertyDeclaration for the property with the given options.
     * The property setter calls the property's `hasChanged` property option
     * or uses a strict identity check to determine whether or not to request
     * an update.
     *
     * This method may be overridden to customize properties; however,
     * when doing so, it's important to call `super.createProperty` to ensure
     * the property is setup correctly. This method calls
     * `getPropertyDescriptor` internally to get a descriptor to install.
     * To customize what properties do when they are get or set, override
     * `getPropertyDescriptor`. To customize the options for a property,
     * implement `createProperty` like this:
     *
     * static createProperty(name, options) {
     *   options = Object.assign(options, {myOption: true});
     *   super.createProperty(name, options);
     * }
     *
     * @nocollapse
     */
    static createProperty(name, options = defaultPropertyDeclaration) {
        // Note, since this can be called by the `@property` decorator which
        // is called before `finalize`, we ensure storage exists for property
        // metadata.
        this._ensureClassProperties();
        this._classProperties.set(name, options);
        // Do not generate an accessor if the prototype already has one, since
        // it would be lost otherwise and that would never be the user's intention;
        // Instead, we expect users to call `requestUpdate` themselves from
        // user-defined accessors. Note that if the super has an accessor we will
        // still overwrite it
        if (options.noAccessor || this.prototype.hasOwnProperty(name)) {
            return;
        }
        const key = typeof name === 'symbol' ? Symbol() : `__${name}`;
        const descriptor = this.getPropertyDescriptor(name, key, options);
        if (descriptor !== undefined) {
            Object.defineProperty(this.prototype, name, descriptor);
        }
    }
    /**
     * Returns a property descriptor to be defined on the given named property.
     * If no descriptor is returned, the property will not become an accessor.
     * For example,
     *
     *   class MyElement extends LitElement {
     *     static getPropertyDescriptor(name, key, options) {
     *       const defaultDescriptor =
     *           super.getPropertyDescriptor(name, key, options);
     *       const setter = defaultDescriptor.set;
     *       return {
     *         get: defaultDescriptor.get,
     *         set(value) {
     *           setter.call(this, value);
     *           // custom action.
     *         },
     *         configurable: true,
     *         enumerable: true
     *       }
     *     }
     *   }
     *
     * @nocollapse
     */
    static getPropertyDescriptor(name, key, _options) {
        return {
            // tslint:disable-next-line:no-any no symbol in index
            get() {
                return this[key];
            },
            set(value) {
                const oldValue = this[name];
                this[key] = value;
                this._requestUpdate(name, oldValue);
            },
            configurable: true,
            enumerable: true
        };
    }
    /**
     * Returns the property options associated with the given property.
     * These options are defined with a PropertyDeclaration via the `properties`
     * object or the `@property` decorator and are registered in
     * `createProperty(...)`.
     *
     * Note, this method should be considered "final" and not overridden. To
     * customize the options for a given property, override `createProperty`.
     *
     * @nocollapse
     * @final
     */
    static getPropertyOptions(name) {
        return this._classProperties && this._classProperties.get(name) ||
            defaultPropertyDeclaration;
    }
    /**
     * Creates property accessors for registered properties and ensures
     * any superclasses are also finalized.
     * @nocollapse
     */
    static finalize() {
        // finalize any superclasses
        const superCtor = Object.getPrototypeOf(this);
        if (!superCtor.hasOwnProperty(finalized)) {
            superCtor.finalize();
        }
        this[finalized] = true;
        this._ensureClassProperties();
        // initialize Map populated in observedAttributes
        this._attributeToPropertyMap = new Map();
        // make any properties
        // Note, only process "own" properties since this element will inherit
        // any properties defined on the superClass, and finalization ensures
        // the entire prototype chain is finalized.
        if (this.hasOwnProperty(JSCompiler_renameProperty('properties', this))) {
            const props = this.properties;
            // support symbols in properties (IE11 does not support this)
            const propKeys = [
                ...Object.getOwnPropertyNames(props),
                ...(typeof Object.getOwnPropertySymbols === 'function') ?
                    Object.getOwnPropertySymbols(props) :
                    []
            ];
            // This for/of is ok because propKeys is an array
            for (const p of propKeys) {
                // note, use of `any` is due to TypeSript lack of support for symbol in
                // index types
                // tslint:disable-next-line:no-any no symbol in index
                this.createProperty(p, props[p]);
            }
        }
    }
    /**
     * Returns the property name for the given attribute `name`.
     * @nocollapse
     */
    static _attributeNameForProperty(name, options) {
        const attribute = options.attribute;
        return attribute === false ?
            undefined :
            (typeof attribute === 'string' ?
                attribute :
                (typeof name === 'string' ? name.toLowerCase() : undefined));
    }
    /**
     * Returns true if a property should request an update.
     * Called when a property value is set and uses the `hasChanged`
     * option for the property if present or a strict identity check.
     * @nocollapse
     */
    static _valueHasChanged(value, old, hasChanged = notEqual) {
        return hasChanged(value, old);
    }
    /**
     * Returns the property value for the given attribute value.
     * Called via the `attributeChangedCallback` and uses the property's
     * `converter` or `converter.fromAttribute` property option.
     * @nocollapse
     */
    static _propertyValueFromAttribute(value, options) {
        const type = options.type;
        const converter = options.converter || defaultConverter;
        const fromAttribute = (typeof converter === 'function' ? converter : converter.fromAttribute);
        return fromAttribute ? fromAttribute(value, type) : value;
    }
    /**
     * Returns the attribute value for the given property value. If this
     * returns undefined, the property will *not* be reflected to an attribute.
     * If this returns null, the attribute will be removed, otherwise the
     * attribute will be set to the value.
     * This uses the property's `reflect` and `type.toAttribute` property options.
     * @nocollapse
     */
    static _propertyValueToAttribute(value, options) {
        if (options.reflect === undefined) {
            return;
        }
        const type = options.type;
        const converter = options.converter;
        const toAttribute = converter && converter.toAttribute ||
            defaultConverter.toAttribute;
        return toAttribute(value, type);
    }
    /**
     * Performs element initialization. By default captures any pre-set values for
     * registered properties.
     */
    initialize() {
        this._saveInstanceProperties();
        // ensures first update will be caught by an early access of
        // `updateComplete`
        this._requestUpdate();
    }
    /**
     * Fixes any properties set on the instance before upgrade time.
     * Otherwise these would shadow the accessor and break these properties.
     * The properties are stored in a Map which is played back after the
     * constructor runs. Note, on very old versions of Safari (<=9) or Chrome
     * (<=41), properties created for native platform properties like (`id` or
     * `name`) may not have default values set in the element constructor. On
     * these browsers native properties appear on instances and therefore their
     * default value will overwrite any element default (e.g. if the element sets
     * this.id = 'id' in the constructor, the 'id' will become '' since this is
     * the native platform default).
     */
    _saveInstanceProperties() {
        // Use forEach so this works even if for/of loops are compiled to for loops
        // expecting arrays
        this.constructor
            ._classProperties.forEach((_v, p) => {
            if (this.hasOwnProperty(p)) {
                const value = this[p];
                delete this[p];
                if (!this._instanceProperties) {
                    this._instanceProperties = new Map();
                }
                this._instanceProperties.set(p, value);
            }
        });
    }
    /**
     * Applies previously saved instance properties.
     */
    _applyInstanceProperties() {
        // Use forEach so this works even if for/of loops are compiled to for loops
        // expecting arrays
        // tslint:disable-next-line:no-any
        this._instanceProperties.forEach((v, p) => this[p] = v);
        this._instanceProperties = undefined;
    }
    connectedCallback() {
        // Ensure first connection completes an update. Updates cannot complete
        // before connection.
        this.enableUpdating();
    }
    enableUpdating() {
        if (this._enableUpdatingResolver !== undefined) {
            this._enableUpdatingResolver();
            this._enableUpdatingResolver = undefined;
        }
    }
    /**
     * Allows for `super.disconnectedCallback()` in extensions while
     * reserving the possibility of making non-breaking feature additions
     * when disconnecting at some point in the future.
     */
    disconnectedCallback() {
    }
    /**
     * Synchronizes property values when attributes change.
     */
    attributeChangedCallback(name, old, value) {
        if (old !== value) {
            this._attributeToProperty(name, value);
        }
    }
    _propertyToAttribute(name, value, options = defaultPropertyDeclaration) {
        const ctor = this.constructor;
        const attr = ctor._attributeNameForProperty(name, options);
        if (attr !== undefined) {
            const attrValue = ctor._propertyValueToAttribute(value, options);
            // an undefined value does not change the attribute.
            if (attrValue === undefined) {
                return;
            }
            // Track if the property is being reflected to avoid
            // setting the property again via `attributeChangedCallback`. Note:
            // 1. this takes advantage of the fact that the callback is synchronous.
            // 2. will behave incorrectly if multiple attributes are in the reaction
            // stack at time of calling. However, since we process attributes
            // in `update` this should not be possible (or an extreme corner case
            // that we'd like to discover).
            // mark state reflecting
            this._updateState = this._updateState | STATE_IS_REFLECTING_TO_ATTRIBUTE;
            if (attrValue == null) {
                this.removeAttribute(attr);
            }
            else {
                this.setAttribute(attr, attrValue);
            }
            // mark state not reflecting
            this._updateState = this._updateState & ~STATE_IS_REFLECTING_TO_ATTRIBUTE;
        }
    }
    _attributeToProperty(name, value) {
        // Use tracking info to avoid deserializing attribute value if it was
        // just set from a property setter.
        if (this._updateState & STATE_IS_REFLECTING_TO_ATTRIBUTE) {
            return;
        }
        const ctor = this.constructor;
        // Note, hint this as an `AttributeMap` so closure clearly understands
        // the type; it has issues with tracking types through statics
        // tslint:disable-next-line:no-unnecessary-type-assertion
        const propName = ctor._attributeToPropertyMap.get(name);
        if (propName !== undefined) {
            const options = ctor.getPropertyOptions(propName);
            // mark state reflecting
            this._updateState = this._updateState | STATE_IS_REFLECTING_TO_PROPERTY;
            this[propName] =
                // tslint:disable-next-line:no-any
                ctor._propertyValueFromAttribute(value, options);
            // mark state not reflecting
            this._updateState = this._updateState & ~STATE_IS_REFLECTING_TO_PROPERTY;
        }
    }
    /**
     * This private version of `requestUpdate` does not access or return the
     * `updateComplete` promise. This promise can be overridden and is therefore
     * not free to access.
     */
    _requestUpdate(name, oldValue) {
        let shouldRequestUpdate = true;
        // If we have a property key, perform property update steps.
        if (name !== undefined) {
            const ctor = this.constructor;
            const options = ctor.getPropertyOptions(name);
            if (ctor._valueHasChanged(this[name], oldValue, options.hasChanged)) {
                if (!this._changedProperties.has(name)) {
                    this._changedProperties.set(name, oldValue);
                }
                // Add to reflecting properties set.
                // Note, it's important that every change has a chance to add the
                // property to `_reflectingProperties`. This ensures setting
                // attribute + property reflects correctly.
                if (options.reflect === true &&
                    !(this._updateState & STATE_IS_REFLECTING_TO_PROPERTY)) {
                    if (this._reflectingProperties === undefined) {
                        this._reflectingProperties = new Map();
                    }
                    this._reflectingProperties.set(name, options);
                }
            }
            else {
                // Abort the request if the property should not be considered changed.
                shouldRequestUpdate = false;
            }
        }
        if (!this._hasRequestedUpdate && shouldRequestUpdate) {
            this._updatePromise = this._enqueueUpdate();
        }
    }
    /**
     * Requests an update which is processed asynchronously. This should
     * be called when an element should update based on some state not triggered
     * by setting a property. In this case, pass no arguments. It should also be
     * called when manually implementing a property setter. In this case, pass the
     * property `name` and `oldValue` to ensure that any configured property
     * options are honored. Returns the `updateComplete` Promise which is resolved
     * when the update completes.
     *
     * @param name {PropertyKey} (optional) name of requesting property
     * @param oldValue {any} (optional) old value of requesting property
     * @returns {Promise} A Promise that is resolved when the update completes.
     */
    requestUpdate(name, oldValue) {
        this._requestUpdate(name, oldValue);
        return this.updateComplete;
    }
    /**
     * Sets up the element to asynchronously update.
     */
    async _enqueueUpdate() {
        this._updateState = this._updateState | STATE_UPDATE_REQUESTED;
        try {
            // Ensure any previous update has resolved before updating.
            // This `await` also ensures that property changes are batched.
            await this._updatePromise;
        }
        catch (e) {
            // Ignore any previous errors. We only care that the previous cycle is
            // done. Any error should have been handled in the previous update.
        }
        const result = this.performUpdate();
        // If `performUpdate` returns a Promise, we await it. This is done to
        // enable coordinating updates with a scheduler. Note, the result is
        // checked to avoid delaying an additional microtask unless we need to.
        if (result != null) {
            await result;
        }
        return !this._hasRequestedUpdate;
    }
    get _hasRequestedUpdate() {
        return (this._updateState & STATE_UPDATE_REQUESTED);
    }
    get hasUpdated() {
        return (this._updateState & STATE_HAS_UPDATED);
    }
    /**
     * Performs an element update. Note, if an exception is thrown during the
     * update, `firstUpdated` and `updated` will not be called.
     *
     * You can override this method to change the timing of updates. If this
     * method is overridden, `super.performUpdate()` must be called.
     *
     * For instance, to schedule updates to occur just before the next frame:
     *
     * ```
     * protected async performUpdate(): Promise<unknown> {
     *   await new Promise((resolve) => requestAnimationFrame(() => resolve()));
     *   super.performUpdate();
     * }
     * ```
     */
    performUpdate() {
        // Mixin instance properties once, if they exist.
        if (this._instanceProperties) {
            this._applyInstanceProperties();
        }
        let shouldUpdate = false;
        const changedProperties = this._changedProperties;
        try {
            shouldUpdate = this.shouldUpdate(changedProperties);
            if (shouldUpdate) {
                this.update(changedProperties);
            }
            else {
                this._markUpdated();
            }
        }
        catch (e) {
            // Prevent `firstUpdated` and `updated` from running when there's an
            // update exception.
            shouldUpdate = false;
            // Ensure element can accept additional updates after an exception.
            this._markUpdated();
            throw e;
        }
        if (shouldUpdate) {
            if (!(this._updateState & STATE_HAS_UPDATED)) {
                this._updateState = this._updateState | STATE_HAS_UPDATED;
                this.firstUpdated(changedProperties);
            }
            this.updated(changedProperties);
        }
    }
    _markUpdated() {
        this._changedProperties = new Map();
        this._updateState = this._updateState & ~STATE_UPDATE_REQUESTED;
    }
    /**
     * Returns a Promise that resolves when the element has completed updating.
     * The Promise value is a boolean that is `true` if the element completed the
     * update without triggering another update. The Promise result is `false` if
     * a property was set inside `updated()`. If the Promise is rejected, an
     * exception was thrown during the update.
     *
     * To await additional asynchronous work, override the `_getUpdateComplete`
     * method. For example, it is sometimes useful to await a rendered element
     * before fulfilling this Promise. To do this, first await
     * `super._getUpdateComplete()`, then any subsequent state.
     *
     * @returns {Promise} The Promise returns a boolean that indicates if the
     * update resolved without triggering another update.
     */
    get updateComplete() {
        return this._getUpdateComplete();
    }
    /**
     * Override point for the `updateComplete` promise.
     *
     * It is not safe to override the `updateComplete` getter directly due to a
     * limitation in TypeScript which means it is not possible to call a
     * superclass getter (e.g. `super.updateComplete.then(...)`) when the target
     * language is ES5 (https://github.com/microsoft/TypeScript/issues/338).
     * This method should be overridden instead. For example:
     *
     *   class MyElement extends LitElement {
     *     async _getUpdateComplete() {
     *       await super._getUpdateComplete();
     *       await this._myChild.updateComplete;
     *     }
     *   }
     */
    _getUpdateComplete() {
        return this._updatePromise;
    }
    /**
     * Controls whether or not `update` should be called when the element requests
     * an update. By default, this method always returns `true`, but this can be
     * customized to control when to update.
     *
     * @param _changedProperties Map of changed properties with old values
     */
    shouldUpdate(_changedProperties) {
        return true;
    }
    /**
     * Updates the element. This method reflects property values to attributes.
     * It can be overridden to render and keep updated element DOM.
     * Setting properties inside this method will *not* trigger
     * another update.
     *
     * @param _changedProperties Map of changed properties with old values
     */
    update(_changedProperties) {
        if (this._reflectingProperties !== undefined &&
            this._reflectingProperties.size > 0) {
            // Use forEach so this works even if for/of loops are compiled to for
            // loops expecting arrays
            this._reflectingProperties.forEach((v, k) => this._propertyToAttribute(k, this[k], v));
            this._reflectingProperties = undefined;
        }
        this._markUpdated();
    }
    /**
     * Invoked whenever the element is updated. Implement to perform
     * post-updating tasks via DOM APIs, for example, focusing an element.
     *
     * Setting properties inside this method will trigger the element to update
     * again after this update cycle completes.
     *
     * @param _changedProperties Map of changed properties with old values
     */
    updated(_changedProperties) {
    }
    /**
     * Invoked when the element is first updated. Implement to perform one time
     * work on the element after update.
     *
     * Setting properties inside this method will trigger the element to update
     * again after this update cycle completes.
     *
     * @param _changedProperties Map of changed properties with old values
     */
    firstUpdated(_changedProperties) {
    }
}
_a = finalized;
/**
 * Marks class as having finished creating properties.
 */
UpdatingElement[_a] = true;

/**
@license
Copyright (c) 2019 The Polymer Project Authors. All rights reserved.
This code may only be used under the BSD style license found at
http://polymer.github.io/LICENSE.txt The complete set of authors may be found at
http://polymer.github.io/AUTHORS.txt The complete set of contributors may be
found at http://polymer.github.io/CONTRIBUTORS.txt Code distributed by Google as
part of the polymer project is also subject to an additional IP rights grant
found at http://polymer.github.io/PATENTS.txt
*/
const supportsAdoptingStyleSheets = ('adoptedStyleSheets' in Document.prototype) &&
    ('replace' in CSSStyleSheet.prototype);
const constructionToken = Symbol();
class CSSResult {
    constructor(cssText, safeToken) {
        if (safeToken !== constructionToken) {
            throw new Error('CSSResult is not constructable. Use `unsafeCSS` or `css` instead.');
        }
        this.cssText = cssText;
    }
    // Note, this is a getter so that it's lazy. In practice, this means
    // stylesheets are not created until the first element instance is made.
    get styleSheet() {
        if (this._styleSheet === undefined) {
            // Note, if `adoptedStyleSheets` is supported then we assume CSSStyleSheet
            // is constructable.
            if (supportsAdoptingStyleSheets) {
                this._styleSheet = new CSSStyleSheet();
                this._styleSheet.replaceSync(this.cssText);
            }
            else {
                this._styleSheet = null;
            }
        }
        return this._styleSheet;
    }
    toString() {
        return this.cssText;
    }
}
const textFromCSSResult = (value) => {
    if (value instanceof CSSResult) {
        return value.cssText;
    }
    else if (typeof value === 'number') {
        return value;
    }
    else {
        throw new Error(`Value passed to 'css' function must be a 'css' function result: ${value}. Use 'unsafeCSS' to pass non-literal values, but
            take care to ensure page security.`);
    }
};
/**
 * Template tag which which can be used with LitElement's `style` property to
 * set element styles. For security reasons, only literal string values may be
 * used. To incorporate non-literal values `unsafeCSS` may be used inside a
 * template string part.
 */
const css = (strings, ...values) => {
    const cssText = values.reduce((acc, v, idx) => acc + textFromCSSResult(v) + strings[idx + 1], strings[0]);
    return new CSSResult(cssText, constructionToken);
};

/**
 * @license
 * Copyright (c) 2017 The Polymer Project Authors. All rights reserved.
 * This code may only be used under the BSD style license found at
 * http://polymer.github.io/LICENSE.txt
 * The complete set of authors may be found at
 * http://polymer.github.io/AUTHORS.txt
 * The complete set of contributors may be found at
 * http://polymer.github.io/CONTRIBUTORS.txt
 * Code distributed by Google as part of the polymer project is also
 * subject to an additional IP rights grant found at
 * http://polymer.github.io/PATENTS.txt
 */
// IMPORTANT: do not change the property name or the assignment expression.
// This line will be used in regexes to search for LitElement usage.
// TODO(justinfagnani): inject version number at build time
(window['litElementVersions'] || (window['litElementVersions'] = []))
    .push('2.3.1');
/**
 * Sentinal value used to avoid calling lit-html's render function when
 * subclasses do not implement `render`
 */
const renderNotImplemented = {};
class LitElement extends UpdatingElement {
    /**
     * Return the array of styles to apply to the element.
     * Override this method to integrate into a style management system.
     *
     * @nocollapse
     */
    static getStyles() {
        return this.styles;
    }
    /** @nocollapse */
    static _getUniqueStyles() {
        // Only gather styles once per class
        if (this.hasOwnProperty(JSCompiler_renameProperty('_styles', this))) {
            return;
        }
        // Take care not to call `this.getStyles()` multiple times since this
        // generates new CSSResults each time.
        // TODO(sorvell): Since we do not cache CSSResults by input, any
        // shared styles will generate new stylesheet objects, which is wasteful.
        // This should be addressed when a browser ships constructable
        // stylesheets.
        const userStyles = this.getStyles();
        if (userStyles === undefined) {
            this._styles = [];
        }
        else if (Array.isArray(userStyles)) {
            // De-duplicate styles preserving the _last_ instance in the set.
            // This is a performance optimization to avoid duplicated styles that can
            // occur especially when composing via subclassing.
            // The last item is kept to try to preserve the cascade order with the
            // assumption that it's most important that last added styles override
            // previous styles.
            const addStyles = (styles, set) => styles.reduceRight((set, s) =>
            // Note: On IE set.add() does not return the set
            Array.isArray(s) ? addStyles(s, set) : (set.add(s), set), set);
            // Array.from does not work on Set in IE, otherwise return
            // Array.from(addStyles(userStyles, new Set<CSSResult>())).reverse()
            const set = addStyles(userStyles, new Set());
            const styles = [];
            set.forEach((v) => styles.unshift(v));
            this._styles = styles;
        }
        else {
            this._styles = [userStyles];
        }
    }
    /**
     * Performs element initialization. By default this calls `createRenderRoot`
     * to create the element `renderRoot` node and captures any pre-set values for
     * registered properties.
     */
    initialize() {
        super.initialize();
        this.constructor._getUniqueStyles();
        this.renderRoot =
            this.createRenderRoot();
        // Note, if renderRoot is not a shadowRoot, styles would/could apply to the
        // element's getRootNode(). While this could be done, we're choosing not to
        // support this now since it would require different logic around de-duping.
        if (window.ShadowRoot && this.renderRoot instanceof window.ShadowRoot) {
            this.adoptStyles();
        }
    }
    /**
     * Returns the node into which the element should render and by default
     * creates and returns an open shadowRoot. Implement to customize where the
     * element's DOM is rendered. For example, to render into the element's
     * childNodes, return `this`.
     * @returns {Element|DocumentFragment} Returns a node into which to render.
     */
    createRenderRoot() {
        return this.attachShadow({ mode: 'open' });
    }
    /**
     * Applies styling to the element shadowRoot using the `static get styles`
     * property. Styling will apply using `shadowRoot.adoptedStyleSheets` where
     * available and will fallback otherwise. When Shadow DOM is polyfilled,
     * ShadyCSS scopes styles and adds them to the document. When Shadow DOM
     * is available but `adoptedStyleSheets` is not, styles are appended to the
     * end of the `shadowRoot` to [mimic spec
     * behavior](https://wicg.github.io/construct-stylesheets/#using-constructed-stylesheets).
     */
    adoptStyles() {
        const styles = this.constructor._styles;
        if (styles.length === 0) {
            return;
        }
        // There are three separate cases here based on Shadow DOM support.
        // (1) shadowRoot polyfilled: use ShadyCSS
        // (2) shadowRoot.adoptedStyleSheets available: use it.
        // (3) shadowRoot.adoptedStyleSheets polyfilled: append styles after
        // rendering
        if (window.ShadyCSS !== undefined && !window.ShadyCSS.nativeShadow) {
            window.ShadyCSS.ScopingShim.prepareAdoptedCssText(styles.map((s) => s.cssText), this.localName);
        }
        else if (supportsAdoptingStyleSheets) {
            this.renderRoot.adoptedStyleSheets =
                styles.map((s) => s.styleSheet);
        }
        else {
            // This must be done after rendering so the actual style insertion is done
            // in `update`.
            this._needsShimAdoptedStyleSheets = true;
        }
    }
    connectedCallback() {
        super.connectedCallback();
        // Note, first update/render handles styleElement so we only call this if
        // connected after first update.
        if (this.hasUpdated && window.ShadyCSS !== undefined) {
            window.ShadyCSS.styleElement(this);
        }
    }
    /**
     * Updates the element. This method reflects property values to attributes
     * and calls `render` to render DOM via lit-html. Setting properties inside
     * this method will *not* trigger another update.
     * @param _changedProperties Map of changed properties with old values
     */
    update(changedProperties) {
        // Setting properties in `render` should not trigger an update. Since
        // updates are allowed after super.update, it's important to call `render`
        // before that.
        const templateResult = this.render();
        super.update(changedProperties);
        // If render is not implemented by the component, don't call lit-html render
        if (templateResult !== renderNotImplemented) {
            this.constructor
                .render(templateResult, this.renderRoot, { scopeName: this.localName, eventContext: this });
        }
        // When native Shadow DOM is used but adoptedStyles are not supported,
        // insert styling after rendering to ensure adoptedStyles have highest
        // priority.
        if (this._needsShimAdoptedStyleSheets) {
            this._needsShimAdoptedStyleSheets = false;
            this.constructor._styles.forEach((s) => {
                const style = document.createElement('style');
                style.textContent = s.cssText;
                this.renderRoot.appendChild(style);
            });
        }
    }
    /**
     * Invoked on each update to perform rendering tasks. This method may return
     * any value renderable by lit-html's NodePart - typically a TemplateResult.
     * Setting properties inside this method will *not* trigger the element to
     * update.
     */
    render() {
        return renderNotImplemented;
    }
}
/**
 * Ensure this class is marked as `finalized` as an optimization ensuring
 * it will not needlessly try to `finalize`.
 *
 * Note this property name is a string to prevent breaking Closure JS Compiler
 * optimizations. See updating-element.ts for more information.
 */
LitElement['finalized'] = true;
/**
 * Render method used to render the value to the element's DOM.
 * @param result The value to render.
 * @param container Node into which to render.
 * @param options Element name.
 * @nocollapse
 */
LitElement.render = render$1;

// From https://github.com/hivabkbk/high-select

(function () {
  const KEYCODES = {
    ENTER: 13,
    ESC: 27,
    ARROW_LEFT: 37,
    ARROW_UP: 38,
    ARROW_RIGHT: 39,
    ARROW_DOWN: 40,
    HOME: 36,
    END: 35
  };

  const isKeyPrintable = (keyCode) => {
    return (keyCode > 47 && keyCode < 58) || keyCode == 32 || (keyCode > 64 && keyCode < 91) || (keyCode > 95 && keyCode < 112) || (keyCode > 185 && keyCode < 193) || (keyCode > 218 && keyCode < 223);
  };

  const template = document.createElement('template');
  template.innerHTML = `
        <style>
            :host {
                display: inline-block;
                position: relative;
                user-select: none;
                outline-width: 0px;
                text-align: justify;
            }

            #caller {
                display: flex;
                padding: var(--caller-padding, 3px 6px);
                background: var(--caller-background, #fff);
                color: var(--caller-color, inherit);
                white-space: nowrap;
                box-shadow: var(--caller-shadow, 0px 0px 2px #666, inset 0px 0px 5px 0px #eee);
                border-radius: var(--caller-border-radius, 3px);
                height: inherit;
                width: inherit;
                align-items: center;
            }
            #caller :first-child{
                position: relative;
                width: inherit;
                overflow-x: hidden;
            }
            :host([disabled]) #caller {
                color: var(--caller-disabled-color, #aaa);
                background: var(--caller-disabled-background, #eee);
            }
            :host(:not([disabled])) #caller:hover{
                cursor: var(--caller-hover-cursor, pointer);
                background: var(--caller-hover-background, #fcfcfc);
                color: var(--caller-hover-color, #000);
            }
            :host(:not([disabled]):focus) #caller{
                outline: var(--caller-focus-outline, rgb(229, 151, 0) auto 1px);
            }

            :host([arrow]) #arrow {
                line-height: 20px;
                font-size: var(--arrow-font-size, 18px);
                margin: var(--arrow-margin, 0px 3px);
                color: var(--arrow-color, #000);
            }
            :host([arrow]):host([expanded]) #arrow > span {
                transform: rotate(-90deg);
                left: 0px;
                top: 0px;
            }
            :host([arrow]) #arrow > span {
                position: relative;
                display: block;
                top: 0px;
                left: 3.5px;
                transform: rotate(90deg);
            }
            :host([animated]) #arrow > span {
                transition: transform var(--animated-time, 0.15s) linear;
            }
            :host(:not([arrow])) #arrow {
                display: none;
            }

            #bigot {
				max-height: var(--bigot-max-height, auto);
				overflow-y: auto;
                position: fixed;
                box-shadow: var(--bigot-shadow, 0px 0px 6px #ccc);
                background: var(--bigot-background, #fff);
                border: var(--bigot-border, 1px solid #ccc);
                z-index: var(--bigot-zIndex, 3);
                transition: visibility 0s linear var(--animated-time, 0.15s), opacity var(--animated-time, 0.15s) linear;
            }
            :host([animated]):host(:not([expanded])) #bigot {
                visibility: hidden;
                opacity: 0;
            }
            :host([animated]):host([expanded]) #bigot {
                visibility: visible;
                opacity: 1;
                transition-delay: 0s;
            }

            #holder {
                overflow-y: auto;
            }

            :host(:not([search])) #search{
                display: none;
            }
            #search {
                line-height: normal;
            }
            #search input[type=text]{
                outline: var(--input-outline, 0px solid #aaa);
                margin: var(--input-margin, 0px);
                width: var(--input-width, 98%);
                border-width: var(--input-border-width, 0px 0px 1px 0px);
                border-color: var(--input-border-color, #ccc);
                border-style: var(--input-border-style, solid);
                font: var(--input-font, 12pt arial);
                padding: var(--input-padding, 2px 1%);
                color: var(--input-color, #000);
                background: var(--input-background, #fff);
            }

            ::slotted(high-option), high-option{
                display: block;
                cursor: pointer;
                padding: var(--option-padding, 3px 6px);
                border: var(--option-border, none);
                border-bottom: var(--option-border-bottom, none);
                border-top: var(--option-border-top, none);
                border-left: var(--option-border-left, none);
                border-right: var(--option-border-right, none);
                height: auto;
                line-height: normal;
				transition: all 0.1s linear;
            }

			::slotted(high-option:last-child), high-option:last-child{
				border: var(--option-last-border, none);
                border-bottom: var(--option-last-border-bottom, none);
                border-top: var(--option-last-border-top, none);
                border-left: var(--option-last-border-left, none);
                border-right: var(--option-last-border-right, none);
			}
            ::slotted(high-option:hover) {
                background: var(--option-hover-background, #fff);
                color: var(--option-hover-color, #000);
            }
            ::slotted(high-option[hidden]){
                display: none;
            }
            ::slotted([disabled]){
                background: var(--option-disabled-background, #f9f9f9);
                color: var(--option-disabled-color, #ddd);
            }
            ::slotted(:not([considered])):hover {
                background: rgba(238, 238, 238, 0.767);

            }
            ::slotted(high-option[considered]){
                background: var(--option-active-background, #0080ff);
                color: var(--option-active-color, #000);
            }
            ::slotted(high-option[selected]){
                background: var(--option-selected-background, #eee);
                color: var(--option-selected-color, #000);
            }

            :host-context(.dark){
                color: #e5c070;
            }

            :host-context(.dark) #caller{
                background: #282c34;
                box-shadow: 0px 0px 2px #000, inset 0px 0px 5px 0px #21252b;
            }

            :host-context(.dark:not([disabled])) #caller:hover{
                background: #21252b;
                color: #e5c070;
            }

            :host-context(.dark[arrow]) #arrow {
                color: #e5c070;
            }

            :host-context(.dark) #bigot {
                box-shadow: 0px 0px 6px #000;
                background: #282c34;
                border: 1px solid #000;
            }
            :host-context(.dark) #search input[type=text]{
                border-color: #666;
                background: #282c34;
                color: #e5c070;
            }
            :host-context(.dark) ::slotted([disabled]){
                background: #32363e; color: #4e5562;
            }:host-context(.dark) ::slotted(high-option[considered]){
                background: #e5c070; color: #282c34;
            }:host-context(.dark) ::slotted(high-option[selected]:not([considered])){
                background: #373c44; color: #89bd55;
            }
        </style>
        <div id="caller">
            <span id="chosen"></span> <span id="arrow"><span>&#8250;</span></span>
        </div>
        <section id="bigot">
            <div id="search">
                <input type="text" spellcheck="false" tabindex="-1">
            </div>
            <div id="holder">
                <slot name="option" maxlength="20"></slot>
            </div>
        </section>
    `;

  class HighSelect extends HTMLElement {
    static get observedAttributes() {
      return ['expanded', 'disabled'];
    }

    set value(value) {
      if (typeof value === "string" || typeof value === "number") {
        const options = this._allValidOptions();
        for (let option of options) {
          if (option.value == value) {
            option.selected = true;
            return;
          }
        }
      }
    }

    get value() {
      return this._selectedOption ? this._selectedOption.value : '';
    }

    set expanded(value) {
      Boolean(value) ? this.setAttribute('expanded', '') : this.removeAttribute('expanded');
    }

    get expanded() {
      return this.hasAttribute('expanded');
    }

    set disabled(value) {
      Boolean(value) ? this.setAttribute('disabled', '') : this.removeAttribute('disabled');
    }

    get disabled() {
      return this.hasAttribute('disabled');
    }

    constructor() {
      super();
      this._onSlotChange = this._onSlotChange.bind(this);
      this._onCallerClick = this._onCallerClick.bind(this);
      this._onKeyUp = this._onKeyUp.bind(this);
      this.attachShadow({
        mode: 'open'
      });
      this.shadowRoot.appendChild(template.content.cloneNode(true));

      this._optionSlot = this.shadowRoot.querySelector("slot[name=option]");
      this.caller = this.shadowRoot.querySelector("#caller");
      this.chosen = this.caller.firstElementChild;
      this.arrowElm = this.caller.children[1];
      this.bigot = this.shadowRoot.querySelector("#bigot");
      this.searchElm = this.bigot.firstElementChild;
      this.input = this.searchElm.firstElementChild;
      this.holder = this.bigot.children[1];
      this._animated = this.hasAttribute('animated');

      this._optionSlot.addEventListener('slotchange', this._onSlotChange);
      this.caller.addEventListener('click', this._onCallerClick);
      this.input.addEventListener('keyup', this._onKeyUp);
      document.addEventListener('scroll', function () {
        if (this.expanded) {
          this.expanded = false;
          this.focus();
        }
      }.bind(this));

      if (!this._animated) {
        this._setHidden(true);
      }
    }

    connectedCallback() {
      this.addEventListener('blur', this._onBlur);
      this.addEventListener('mousedown', this._onMouseDown);
      this.addEventListener('mouseup', this._onMouseUp);
      this.addEventListener('keydown', this._onKeyDown);
      customElements.whenDefined("high-option").then(_ => {
        this._initializing();
      });
    }

    disconnectedCallback() {
      this.caller.removeEventListener('click', this._onCallerClick);
      this.input.removeEventListener('keyup', this._onKeyUp);
      this.removeEventListener('blur', this._onBlur);
      this.removeEventListener('mousedown', this._onMouseDown);
      this.removeEventListener('mouseup', this._onMouseUp);
      this.removeEventListener('keydown', this._onKeyDown);
    }

    attributeChangedCallback() {
      this.expanded ? this._expand() : this._collapse();
      if (this.disabled) {
        this.blur();
        this.setAttribute('tabindex', '-1');
      } else {
        this.setAttribute('tabindex', 0);
      }
    }

    _onSlotChange() {
      this._initializing();
    }

    _onCallerClick() {
      this._toggle();
    }

    _onMouseDown(event) {
      let option = event.target.closest('high-option');
      if (this._isValidAndEnabled(option)) {
        option.considered = true;
      }
    }

    _onMouseUp(event) {
      const option = event.target.closest('high-option');
      if (this._isValidAndEnabled(option)) {
        this._select(option);
        this.expanded = false;
      }
    }

    _onKeyDown(event) {
      let option;
      switch (event.keyCode) {
        case KEYCODES.HOME:
          event.preventDefault();
          option = this._firstOption();
          if (option)
            this.expanded ? option.considered = true : this._select(option);
          break;
        case KEYCODES.ARROW_UP:
          event.preventDefault();
          option = this._previousOption();
          if (option)
            this.expanded ? option.considered = true : this._select(option);
          break;
        case KEYCODES.ARROW_DOWN:
          event.preventDefault();
          option = this._nextOption();
          if (option)
            this.expanded ? option.considered = true : this._select(option);
          break;
        case KEYCODES.END:
          event.preventDefault();
          option = this._lastOption();
          if (option)
            this.expanded ? option.considered = true : this._select(option);
          break;
        case KEYCODES.ESC:
          event.preventDefault();
          this.expanded = false;
          this.focus();
          break;
        case KEYCODES.ENTER:
          event.preventDefault();
          if (this.expanded) {
            if (this._consideredOption) {
              this._select(this._consideredOption);
              this.expanded = false;
              this.focus();
            }
          } else {
            this.expanded = true;
          }
          break;
        default:
          if (!this.expanded) {
            if (isKeyPrintable(event.keyCode)) {
              this.input.focus();
              this.expanded = true;
            }
          }
          break;
      }
    }

    _onKeyUp(event) {
      if (event.target.value !== this._searchContent) {
        this._searching(event.target.value.trim().toLowerCase());

        this._searchContent = event.target.value;
      }
    }

    _onBlur() {
      this.expanded = false;
    }

    _hasSelected() {
      const options = this._allValidOptions();
      for (let option of options) {
        if (option.selected) {
          this._transcend(option);
          return true;
        }
      }
      return false;
    }

    _initializing() {
      const allOptions = this._allOptions();
      if (!this._selectedOption && allOptions.length && !this._hasSelected()) this._firstOption().selected = true;
      if (!this.hasAttribute('tabindex')) this.setAttribute('tabindex', '0');
      this.options = allOptions;
    }

    _expand() {
      this._setHidden(false);
      this._attachBigotToCaller();
      this.input.focus();
      if (this._selectedOption)
        this._selectedOption.scrollIntoView({
          block: "center"
        });
    }

    _collapse() {
      this._setHidden(true);
      this._releaseBigot();
      if (this._consideredOption) {
        this._consideredOption.considered = false;
        this._consideredOption = null;
      }
      this._resetSearch();
    }

    _setHidden(value) {
      if (!this._animated) {
        this.bigot.hidden = value;
      }
    }

    _toggle() {
      this.expanded = !this.expanded;
    }

    _select(option) {
      if (this._isValidAndEnabled(option) && option !== this._selectedOption) {
        option.selected = true;
        this._createChangeEvent();
      }
    }

    _transcend(option) {
      if (this._isValidAndEnabled(option) && this._selectedOption !== option) {
        if (this._selectedOption) this._selectedOption.selected = false;
        this._selectedOption = option;
        this.chosen.innerHTML = option.content;
      }
    }

    _consider(option) {
      if (this._isValidOption(option) && this._consideredOption !== option) {
        if (this._consideredOption) this._consideredOption.considered = false;
        this._consideredOption = option;
        option.scrollIntoView({
          block: "nearest"
        });
      }
    }

    _searching(content) {
      let notFoundRecords, notFoundInContent, option;
      for (option of this.options) {
        if (this._isValidOption(option))
          notFoundRecords = option.record.toLowerCase().indexOf(content) === -1;
        notFoundInContent = option.innerText.toLowerCase().indexOf(content) === -1;
        option.hidden = notFoundInContent && notFoundRecords;
      }

      if (!this._isValidAndEnabledAndVisible(this._consideredOption) && !this._isValidAndEnabledAndVisible(this._selectedOption)) {
        const firstOption = this._firstOption();
        if (firstOption) firstOption.considered = true;
      }
    }

    _resetSearch() {
      if (this.input.value) {
        this.input.value = '';
        this._searchContent = '';
        for (let option of this.options) {
          option.hidden = false;
        }
      }
    }


    _isValidOption(option) {
      return option instanceof HighOption && option.tagName.toLowerCase() === 'high-option';
    }

    _isValidAndEnabled(option) {
      return this._isValidOption(option) && !option.disabled;
    }

    _isValidAndEnabledAndVisible(option) {
      return this._isValidAndEnabled(option) && !option.hidden;
    }


    _allOptions() {
      return Array.from(this.children);
    }

    _allValidOptions() {
      return Array.from(this.querySelectorAll('high-option:not([hidden]):not([disabled])'));
    }

    _firstOption() {
      return this.querySelector("high-option:not([disabled]):not([hidden])");
    }

    _nextOption() {
      const currentOption = this._consideredOption || this._selectedOption;
      if (this._isValidAndEnabled(currentOption) && !currentOption.hidden) {
        let nextOption = currentOption.nextElementSibling;
        while (true) {
          if (!nextOption) break;
          if (!nextOption.hidden && this._isValidAndEnabled(nextOption)) return nextOption;
          nextOption = nextOption.nextElementSibling;
        }
      } else
        return this._firstOption();
    }

    _previousOption() {
      const currentOption = this._consideredOption || this._selectedOption;
      if (this._isValidAndEnabled(currentOption) && !currentOption.hidden) {
        let previousOption = currentOption.previousElementSibling;
        while (true) {
          if (!previousOption) break;
          if (!previousOption.hidden && this._isValidAndEnabled(previousOption)) return previousOption;
          previousOption = previousOption.previousElementSibling;
        }
      } else
        return this._lastOption();
    }

    _lastOption() {
      const options = this._allValidOptions();
      return Object.values(options)[options.length - 1];
    }


    // helpers
    _attachBigotToCaller() {
      const callerSizeAndPosition = this.caller.getBoundingClientRect();
      const bigotSizeAndPosition = this.bigot.getBoundingClientRect();
      const topSpace = callerSizeAndPosition.top;
      const bottomSpace = window.innerHeight - callerSizeAndPosition.bottom;
      const newBigotTop = topSpace + callerSizeAndPosition.height;
      const newBigotBottom = bottomSpace + callerSizeAndPosition.height;

      this.bigot.style.minWidth = callerSizeAndPosition.width + "px";

      if (bottomSpace < bigotSizeAndPosition.height) {
        // is there enough space from top
        if (topSpace > bottomSpace) {
          // show select on the top
          this.bigot.style.bottom = newBigotBottom + "px";

          if (topSpace < bigotSizeAndPosition.height)
            this.holder.style.maxHeight = topSpace - this.searchElm.clientHeight - 10 + "px";
        } else {
          // show select on the bottom
          this.bigot.style.top = newBigotTop + "px";
          this.holder.style.maxHeight = bottomSpace - this.searchElm.clientHeight - 10 + "px";
        }
      } else {
        this.bigot.style.top = newBigotTop + "px";
      }

      if (bigotSizeAndPosition.right > window.innerWidth)
        this.bigot.style.right = "0px";

      if (bigotSizeAndPosition.left < 0)
        this.bigot.style.left = '0px';
    }

    _releaseBigot() {
      this.holder.style.maxHeight = 'none';
      this.bigot.style.top = 'auto';
      this.bigot.style.bottom = 'auto';
      this.bigot.style.left = 'auto';
      this.bigot.style.right = 'auto';
    }

    _createChangeEvent() {
      const event = new CustomEvent('change', {
        target: this,
        bubbles: true
      });
      this.dispatchEvent(event);
    }
  }
  customElements.define('high-select', HighSelect);


  class HighOption extends HTMLElement {
    static get observedAttributes() {
      return ['selected', 'considered', 'disabled'];
    }

    set selected(value) {
      Boolean(value) ? this.setAttribute('selected', '') : this.removeAttribute('selected');
    }

    get selected() {
      return this.hasAttribute('selected');
    }

    set considered(value) {
      Boolean(value) ? this.setAttribute('considered', '') : this.removeAttribute('considered');
    }

    get considered() {
      return this.hasAttribute('considered');
    }

    set disabled(value) {
      Boolean(value) ? this.setAttribute('disabled', '') : this.removeAttribute('disabled');
    }

    get disabled() {
      return this.hasAttribute('disabled');
    }

    set value(value) {
      value ? this.setAttribute('value', value) : this.removeAttribute('value');
    }

    get value() {
      if (this.hasAttribute('value')) {
        return this.getAttribute('value');
      } else {
        const innerText = this.innerText.trim().toLowerCase();
        return innerText ? innerText : this.title;
      }
    }

    set title(value) {
      value ? this.setAttribute('title', value) : this.removeAttribute('title');
    }

    get title() {
      return this.hasAttribute('title') ? this.getAttribute('title') : '';
    }

    set record(value) {
      value ? this.setAttribute('record', value) : this.removeAttribute('record');
    }

    get record() {
      return this.hasAttribute('record') ? this.getAttribute('record') : this.title;
    }

    set slot(value) {
      this.setAttribute('slot', 'option');
    }

    get slot() {
      return this.hasAttribute('slot') ? this.getAttribute('slot') : '';
    }

    get content() {
      return this.title ? this.title : this.innerHTML;
    }

    constructor() {
      super();
    }

    connectedCallback() {
      if (this.slot !== 'option') this.slot = '';
      this._upgradeProperty('selected');
      this._upgradeProperty('considered');
      this._upgradeProperty('disabled');
    }

    attributeChangedCallback() {
      const validAndEnable = this._haveValidParent() && !this.disabled;
      if (this.selected && validAndEnable)
        this.parentNode._transcend(this);

      if (this.considered && validAndEnable)
        this.parentNode._consider(this);

      if (this.disabled) {
        this.selected = false;
        this.considered = false;
      }
    }

    _upgradeProperty(prop) {
      if (this.hasOwnProperty(prop)) {
        let value = this[prop];
        delete this[prop];
        this[prop] = value;
      }
    }

    _haveValidParent() {
      if (this.parentNode && this.parentNode.tagName)
        return this.parentNode.tagName.toLowerCase() === 'high-select';
      else
        return false;
    }
  }
  customElements.define('high-option', HighOption);
})();

const typography = css`
  :host {
    font-size: var(--cd-font-size-base);
    font-family: var(--cd-font);
    color: var(--cd-dark-grey);
    line-height: 1.5;
  }
`;

const buttonStyles = css`
  a {
    color: var(--cd-dark-blue);
   }

  a:hover,
  a:focus {
    color: var(--cd-ocha-blue);
    text-decoration: none;
  }

  .cd-button {
    -webkit-appearance: none;
    border-radius: 0;
    box-shadow: none;
    border: 0;
    padding: 0.5rem 1rem;
    font-size: 1rem;
    transition: background 0.3s ease;
    width: auto;
  }

  .cd-button--small {
    padding: 0.25rem 0.5rem;
    font-size: 0.8rem;
    font-weight: 400;
  }

  .cd-button--icon {
    display: flex;
    align-items: center;
    justify-content: space-between;
  }

  .cd-button:hover,
  .cd-button:focus {
    background-color: rbga(0, 0 ,0, 0.1);
  }

  .cd-button:focus {
    outline: 3px solid var(--cd-ocha-blue);
  }

  .cd-button--style {
    background: var(--cd-ocha-blue);
    color: var(--cd-white);
  }

  .cd-button--style:hover,
  .cd-button--style:focus {
    background: var(--cd-dark-blue);
    color: var(--cd-white);
  }

  .cd-button--bold {
    font-weight: bold;
  }

  .cd-button--uppercase {
    text-transform: uppercase;
  }

  /* Some buttons have SVG icons */
  .cd-button--icon svg {
    fill: var(--cd-white);
    width: 2rem;
    height: 2rem;
    /* Icon before */
    padding: 0 0.5rem 0 0;
  }

  .cd-button--icon span + svg {
    /* Icon after */
    padding: 0 0 0 0.5rem;
  }

  .cd-button--icon:hover svg,
  .cd-button--icon:focus svg {
    fill: var(--cd-white);
  }

  .cd-button--export {
    background: var(--cd-mid-grey);
    color: var(--cd-white);
  }

  .cd-button--export:hover,
  .cd-button--export:focus {
    background: var(--cd-dark-grey);
  }
`;

const dropdownStyles = css`
  .dropdown {
    min-width: 10em;
  }

  .cd-filter {
    margin-bottom: 1rem;
  }

  .cd-filter__form {
    display: block;
    background: var(--cd-light-grey);
    padding: 1rem;
  }

  .cd-filter__form form{
    margin-bottom: 0;
  }

  .cd-filter__form label {
    display: block;
    margin: 0 0 0.25rem;
  }

  .cd-filter__group {
    margin: 0 0 1rem;
  }

  .cd-filter__form select {
    width: 100%;
    max-width: 100%;
  }

  .cd-filter__form .cd-button {
    text-transform: unset;
    font-weight: normal;
  }

  @media (min-width: 768px) {
    .cd-filter {
      margin-bottom: 2rem;
    }

    .cd-filter__form form {
      display: flex;
      flex-wrap: wrap;
      align-items: flex-start;
    }

    .cd-filter__group {
      padding-right: 1rem;
    }

    .cd-filter__form .cd-button {
      align-self: flex-end;
      margin-bottom: 1rem;
    }

    /* Quantity queries */
    /* https://alistapart.com/article/quantity-queries-for-css */

    /* If one element */
    .cd-filter__group:only-of-type,
    /* If two elements */
    .cd-filter__group:nth-last-child(2):first-child,
    .cd-filter__group:nth-last-child(2):first-child ~ .cd-filter__group,
    .cd-filter__group:nth-last-child(2):first-child ~ .cd-export,
    /* If three elements */
    .cd-filter__group:nth-last-child(3):first-child,
    .cd-filter__group:nth-last-child(3):first-child ~ .cd-filter__group,
    .cd-filter__group:nth-last-child(3):first-child ~ .cd-export {
      flex: 1 0 33%;
      max-width: 33%;
    }

    .cd-filter__group:nth-last-child(2):first-child ~ .cd-filter__group:last-child,
    .cd-filter__group:nth-last-child(3):first-child ~ .cd-filter__group:last-child {
      padding-right: 0;
    }

    /* If four elements */
    .cd-filter__group:nth-last-child(4):first-child,
    .cd-filter__group:nth-last-child(4):first-child ~ .cd-filter__group,
    .cd-filter__group:nth-last-child(4):first-child ~ .cd-export {
      flex: 1 0 25%;
      max-width: 25%;
    }

    .cd-filter__group:nth-last-child(4):first-child ~ .cd-filter__group:last-child {
      padding-right: 0;
    }

    /* If five elements */
    .cd-filter__group:nth-last-child(5):first-child,
    .cd-filter__group:nth-last-child(5):first-child ~ .cd-filter__group,
    .cd-filter__group:nth-last-child(5):first-child ~ .cd-export {
      flex: 1 0 20%;
      max-width: 20%;
    }

    .cd-filter__group:nth-last-child(5):first-child ~ .cd-filter__group:last-child {
      padding-right: 0;
    }
  }
`;

const tableStyles = css`
 .cd-table {
    margin: 0 auto 3rem;
    border-collapse: collapse;
    width: 100%;
  }

  .cd-table th,
  .cd-table td {
    padding: 0.5rem;
    text-align: left;
  }

  .cd-table th {
    color: var(--cd-ocha-blue);
    border-bottom: 1px solid white;
    background: var(--cd-site-bg-color);
  }

  .cd-table a {
    word-break: break-word;
  }

  @media (min-width: 576px) {
    .cd-table th[data-sort-type="numeric"],
    .cd-table .cd-table--amount,
    .cd-table .cd-table--amount-total {
      text-align: right;
    }
  }

  .cd-table tfoot {
    font-weight: bold;
  }

  /* Row numbers */
  .cd-table--row-numbers {
    counter-reset: rowNumber;
  }

  .cd-table--row-numbers tbody tr {
    counter-increment: rowNumber;
  }

  .cd-table--row-numbers tbody tr td.cd-table--row-num:first-child::before {
    content: counter(rowNumber);
    min-width: 1em;
    margin-right: 0.5em;
    font-weight: normal;
  }

  /* Striping */
  .cd-table--striped tr:nth-child(odd) {
    background: white;
  }

  .cd-table--striped tr:nth-child(even) {
    background: var(--cd-light-grey);
  }

  @media (max-width: 575px) {
    /* Force table to not be like tables anymore */
    .cd-table--responsive,
    .cd-table--responsive thead,
    .cd-table--responsive tbody,
    .cd-table--responsive tfoot,
    .cd-table--responsive th,
    .cd-table--responsive td,
    .cd-table--responsive tr {
      display: block;
    }

    /* Hide table headers (but not display: none;, for accessibility) */
    .cd-table--responsive thead tr {
      position: absolute;
      top: -9999px;
      left: -9999px;
    }

    .cd-table--responsive tr {
      border-bottom: 1px solid var(--cd-light-grey);
      padding: 0 !important;
    }

    .cd-table--responsive td {
      /* Behave  like a "row" */
      border: none;
      border-bottom: 1px solid var(--cd-site-bg-color);
      position: relative;
      padding: 0.5rem;
      padding-left: 40% !important;
      min-height: 2rem; /* label should wrap */
      white-space: normal !important;
      text-align: left;
    }

    .cd-table--responsive td:before {
      position: absolute;
      top: 0.5rem;
      left: 0.5rem;
      width: 35%;
      padding-right: 1rem;
      text-align: left;
      font-weight: bold;
      font-size: 0.85rem;
      color: var(--cd-ocha-blue);
      /* Label the data */
      content: attr(data-content);
    }

    .cd-table--responsive tfoot td {
      border-bottom: 0 none;
    }

    .cd-table--row-numbers tbody tr td.cd-table--row-num {
      height: 3rem;
    }

    .cd-table--row-numbers tbody tr td.cd-table--row-num::before {
      font-weight: bold;
      font-size: 1.5rem;
    }
  }

  .cd-list {
    margin: 0;
    padding: 0 0 1rem;
    list-style: none;
  }

  .cd-list li {
    padding-bottom: 1rem;
    margin-bottom: 1rem;
    border-bottom: 1px solid var(--cd-site-bg-color);
  }

  .cd-list li p:last-child {
    margin-bottom: 0;
  }

  .cd-list__title {
    margin: 0 0 0.5rem;
  }
`;

const paginationStyles = css`
  .cd-pager {
    clear: both;
    text-align: center;
    padding: 0.5rem;
  }

  @supports (display: grid) {
    .cd-pager {
      display: flex;
      flex-wrap: wrap;
      justify-content: center;
    }
  }

  @supports (display: grid) {
    .cd-pager__item {
      display: flex;
      align-self: baseline;
    }
  }

  .cd-pager__item {
    padding: 0.5rem 0.75rem;
   }

  .cd-pager button {
    display: block;
    background-color: white;
    border: 1px solid var(--cd-site-bg-color);
    border-radius: 0.25rem;
   }

  .cd-pager button:hover,
  .cd-pager button:focus {
    color: white;
    background-color: var(--cd-dark-blue);
    border-color: var(--cd-dark-blue);
  }
`;

class OchaAssessmentsBase extends LitElement {
  constructor() {
    super();
    this.data = void 0;
    this.facets = void 0;
    this.pager = void 0;
    this.hasMultiplePages = false;
    this.resetUrl = null;
  }

  static get styles() {
    return [
      css`
        :host {
          display: block;
          border: 1px solid black;
          --cd-ocha-blue:#026cb6;
          --cd-dark-blue:#025995;
          --cd-bright-blue:#80cbff;
          --cd-highlight-red:#eb5c6d;
          --cd-white:#fff;
          --cd-light-grey:#f2f2f2;
          --cd-mid-grey:#595959;
          --cd-dark-grey:#4a4a4a;
          --cd-black:#000;
          --cd-site-bg-color:#e6ecf1;
          --cd-site-bg-color--light:#ebf0f4;
          --cd-font: helvetica, arial, sans-serif;
          --cd-font-size-base: 16px;
        }`,
      typography,
      buttonStyles,
      dropdownStyles
    ]
  }

  static get properties() {
    return {
      baseurl: {
        type: String
      },
      src: {
        type: String
      },
      componenturl: {
        type: String
      },
      basicAuth: {
        type: String
      },
      errorMessage: {
        type: String
      },
      // @var Array
      disabledFilters: {
        type: Array
      },
      data: {
        type: Array
      }
    };
  }

  setDisabledFilters() {
    this.disabledFilters = [];

    const url = new URL(this.src);
    url.searchParams.forEach((value, name) => {
      if (name.indexOf('f[') === 0) {
        const parts = value.split(':');
        this.disabledFilters.push(parts[0]);
      }
    });
  }

  updated(changedProperties) {
    changedProperties.forEach((oldValue, propName) => {
      if (propName == 'src' && typeof oldValue != 'undefined') {
        this.data = void 0;
        this.fetchData();
      }
    });
  }

  resetData() {
    this.src = this.resetUrl;
  }

  changeSrc(event) {
    if (event.currentTarget.value === '') {
      this.src = this.resetUrl;
    }
    else {
      this.activeFilters.push(event.currentTarget.value);

      const url = new URL(this.resetUrl);
      this.activeFilters.forEach(function (filter) {
        url.searchParams.append('f[]', filter);
      });

      this.src = url.toString();
    }
  }

  buildFacets() {
    if (!this.facets) {
      return [];
    }

    let dropdowns = [];
    this.activeFilters = [];

    for (const child_id in this.facets) {
      // Skip disabled filters.
      if (this.disabledFilters.includes(child_id)) {
        continue;
      }

      const child = this.facets[child_id];
      let dropdown = {};

      dropdown = {
        id: child_id,
        label: child.label,
        selected: null,
        options: []
      };

      child.options.forEach(option => {
        if (typeof option.active !== 'undefined' && option.active) {
          dropdown.selected = option.key;
          this.activeFilters.push(option.key);
        }

        dropdown.options.push({
          key: option.key,
          label: option.label
        });
      });

      dropdowns.push(dropdown);
    }

    return dropdowns;
  }

  renderDropdowns() {
    // Build facets.
    let dropdowns = this.buildFacets();

    return html`
      <div class="cd-filter">
        <div class="cd-filter__form">
          <form>
            ${
              dropdowns.map(
                d => this.renderDropdown(d)
              )
            }
            <button @click="${this.resetData}" class="cd-button cd-button--style cd-button--small">Reset</button>
          </form>
        </div>
      </div>
    `;
  }

  renderDropdown(dropdown) {
    if (dropdown.options.length < 1) {
      return;
    }

    // Sort by label.
    dropdown.options.sort((a, b) => (a.label > b.label ? 1 : b.label > a.label ? -1 : 0));

    // Empty option.
    let emptytOption = {
      label: '- Select -',
      value: ''
    };

    if (dropdown.selected) {
      emptytOption.label = '- Remove filter -';
      emptytOption.value = dropdown.selected;
    }

    return html`
      <div class="cd-filter__group">
        <label for="${dropdown.label}">${dropdown.label}</label>
        <high-select class="dropdown" search arrow animated @change="${this.changeSrc}" id="${dropdown.id}">
          <high-option value="${emptytOption.value}">${emptytOption.label}</high-option>
          ${
            dropdown.options.map(function (o) {
              if (o.key == dropdown.selected) {
                return html`
                  <high-option value="" selected>${o.label}</high-option>
                `
              }
              else {
                return html`
                  <high-option value="${o.key}">${o.label}</high-option>
                `
              }
            })
          }
        </high-select>
      </div>
    `;
  }

  renderDate(data) {
    let output = data.field_ass_date;

    if (typeof data.field_ass_date_end_value != 'undefined' && data.field_ass_date_end_value && data.field_ass_date_end_value.length > 0) {
      output = output + ' - ' + data.field_ass_date_end_value[0];
    }

    return output;
  }

  prevPage() {
    if (this.pager.current_page > 0) {
      const url = new URL(this.src);
      if (this.pager.current_page - 1 == 0) {
        url.searchParams.delete('page');
      }
      else {
        url.searchParams.set('page', this.pager.current_page - 1);
      }
      this.src = url.toString();
    }
  }

  nextPage() {
    if (this.pager.current_page < this.pager.total_pages) {
      const url = new URL(this.src);
      url.searchParams.set('page', this.pager.current_page + 1);
      this.src = url.toString();
    }
  }

  renderPager() {
    if (!this.pager) {
      return;
    }

    if (this.pager.total_pages <= 1) {
      return;
    }

    return html`
      <div class="cd-pager">
        ${this.pager.current_page > 0?
          html`<button class="cd-pager--prev cd-pager__item" @click="${this.prevPage}">Previous</button>`: html``
        }
        <span class="cd-pager__item"><span class="page-num">${this.pager.current_page + 1}</span> / <span class="page-total">${this.pager.total_pages}</span></span>
        ${this.pager.current_page < this.pager.total_pages - 1?
          html`<button class="cd-pager--next cd-pager__item" @click="${this.nextPage}">Next</button>`: html``
        }
      </div>
    `;
  }

  renderErrorMessage() {
    if (this.errorMessage == '') {
      return;
    }

    return html`
      <div class="error">
        ${this.errorMessage}
      </div>
    `;
  }

  render() {
    if (!this.data) {
      return html`
        <div>Loading...</div>
      `;
    }
  }

  connectedCallback() {
    super.connectedCallback();
    if (this.src) {
      this.fetchData();
      this.resetUrl = this.src;
      this.setDisabledFilters();
    }
    else {
      console.error('src attribute is required.');
    }
  }

  fetchData() {
    var headers = new Headers();
    if (this.basicAuth) {
      headers.append('Authorization', 'Basic ' + btoa(this.basicAuth));
    }

    fetch(this.src, {
      headers: headers
    })
      .then(response => {
        if (response.ok) {
          return response.json();
        }

        this.errorMessage = 'Unable to load data.';
        throw new Error('Unable to load data.');
      })
      .then(json => {
        if (typeof json != 'undefined' && typeof json.search_results != 'undefined') {
          this.errorMessage = '';
          this.data = json.search_results;
          this.facets = json.facets;

          if (json.pager) {
            this.pager = json.pager;
            this.hasMultiplePages = this.pager.total_pages > 1;
          }
        }
        else {
          throw new Error('No data found.');
        }

        if (this.fetchCb) {
          this.fetchCb();
        }
      })
      .catch(error => {
        this.data = [];
        this.facets = [];
        this.pager = null;
        this.errorMessage = error;
      });
  }
}

/*
 * @namespace Util
 *
 * Various utility functions, used by Leaflet internally.
 */
Object.freeze = function (obj) { return obj; };

// @function extend(dest: Object, src?: Object): Object
// Merges the properties of the `src` object (or multiple objects) into `dest` object and returns the latter. Has an `L.extend` shortcut.
function extend(dest) {
	var i, j, len, src;

	for (j = 1, len = arguments.length; j < len; j++) {
		src = arguments[j];
		for (i in src) {
			dest[i] = src[i];
		}
	}
	return dest;
}

// @function create(proto: Object, properties?: Object): Object
// Compatibility polyfill for [Object.create](https://developer.mozilla.org/docs/Web/JavaScript/Reference/Global_Objects/Object/create)
var create = Object.create || (function () {
	function F() {}
	return function (proto) {
		F.prototype = proto;
		return new F();
	};
})();

// @function bind(fn: Function, …): Function
// Returns a new function bound to the arguments passed, like [Function.prototype.bind](https://developer.mozilla.org/docs/Web/JavaScript/Reference/Global_Objects/Function/bind).
// Has a `L.bind()` shortcut.
function bind(fn, obj) {
	var slice = Array.prototype.slice;

	if (fn.bind) {
		return fn.bind.apply(fn, slice.call(arguments, 1));
	}

	var args = slice.call(arguments, 2);

	return function () {
		return fn.apply(obj, args.length ? args.concat(slice.call(arguments)) : arguments);
	};
}

// @property lastId: Number
// Last unique ID used by [`stamp()`](#util-stamp)
var lastId = 0;

// @function stamp(obj: Object): Number
// Returns the unique ID of an object, assigning it one if it doesn't have it.
function stamp$1(obj) {
	/*eslint-disable */
	obj._leaflet_id = obj._leaflet_id || ++lastId;
	return obj._leaflet_id;
	/* eslint-enable */
}

// @function throttle(fn: Function, time: Number, context: Object): Function
// Returns a function which executes function `fn` with the given scope `context`
// (so that the `this` keyword refers to `context` inside `fn`'s code). The function
// `fn` will be called no more than one time per given amount of `time`. The arguments
// received by the bound function will be any arguments passed when binding the
// function, followed by any arguments passed when invoking the bound function.
// Has an `L.throttle` shortcut.
function throttle(fn, time, context) {
	var lock, args, wrapperFn, later;

	later = function () {
		// reset lock and call if queued
		lock = false;
		if (args) {
			wrapperFn.apply(context, args);
			args = false;
		}
	};

	wrapperFn = function () {
		if (lock) {
			// called too soon, queue to call later
			args = arguments;

		} else {
			// call and lock until later
			fn.apply(context, arguments);
			setTimeout(later, time);
			lock = true;
		}
	};

	return wrapperFn;
}

// @function wrapNum(num: Number, range: Number[], includeMax?: Boolean): Number
// Returns the number `num` modulo `range` in such a way so it lies within
// `range[0]` and `range[1]`. The returned value will be always smaller than
// `range[1]` unless `includeMax` is set to `true`.
function wrapNum(x, range, includeMax) {
	var max = range[1],
	    min = range[0],
	    d = max - min;
	return x === max && includeMax ? x : ((x - min) % d + d) % d + min;
}

// @function falseFn(): Function
// Returns a function which always returns `false`.
function falseFn() { return false; }

// @function formatNum(num: Number, digits?: Number): Number
// Returns the number `num` rounded to `digits` decimals, or to 6 decimals by default.
function formatNum(num, digits) {
	var pow = Math.pow(10, (digits === undefined ? 6 : digits));
	return Math.round(num * pow) / pow;
}

// @function trim(str: String): String
// Compatibility polyfill for [String.prototype.trim](https://developer.mozilla.org/docs/Web/JavaScript/Reference/Global_Objects/String/Trim)
function trim(str) {
	return str.trim ? str.trim() : str.replace(/^\s+|\s+$/g, '');
}

// @function splitWords(str: String): String[]
// Trims and splits the string on whitespace and returns the array of parts.
function splitWords(str) {
	return trim(str).split(/\s+/);
}

// @function setOptions(obj: Object, options: Object): Object
// Merges the given properties to the `options` of the `obj` object, returning the resulting options. See `Class options`. Has an `L.setOptions` shortcut.
function setOptions$1(obj, options) {
	if (!obj.hasOwnProperty('options')) {
		obj.options = obj.options ? create(obj.options) : {};
	}
	for (var i in options) {
		obj.options[i] = options[i];
	}
	return obj.options;
}

// @function getParamString(obj: Object, existingUrl?: String, uppercase?: Boolean): String
// Converts an object into a parameter URL string, e.g. `{a: "foo", b: "bar"}`
// translates to `'?a=foo&b=bar'`. If `existingUrl` is set, the parameters will
// be appended at the end. If `uppercase` is `true`, the parameter names will
// be uppercased (e.g. `'?A=foo&B=bar'`)
function getParamString(obj, existingUrl, uppercase) {
	var params = [];
	for (var i in obj) {
		params.push(encodeURIComponent(uppercase ? i.toUpperCase() : i) + '=' + encodeURIComponent(obj[i]));
	}
	return ((!existingUrl || existingUrl.indexOf('?') === -1) ? '?' : '&') + params.join('&');
}

var templateRe = /\{ *([\w_-]+) *\}/g;

// @function template(str: String, data: Object): String
// Simple templating facility, accepts a template string of the form `'Hello {a}, {b}'`
// and a data object like `{a: 'foo', b: 'bar'}`, returns evaluated string
// `('Hello foo, bar')`. You can also specify functions instead of strings for
// data values — they will be evaluated passing `data` as an argument.
function template(str, data) {
	return str.replace(templateRe, function (str, key) {
		var value = data[key];

		if (value === undefined) {
			throw new Error('No value provided for variable ' + str);

		} else if (typeof value === 'function') {
			value = value(data);
		}
		return value;
	});
}

// @function isArray(obj): Boolean
// Compatibility polyfill for [Array.isArray](https://developer.mozilla.org/docs/Web/JavaScript/Reference/Global_Objects/Array/isArray)
var isArray = Array.isArray || function (obj) {
	return (Object.prototype.toString.call(obj) === '[object Array]');
};

// @function indexOf(array: Array, el: Object): Number
// Compatibility polyfill for [Array.prototype.indexOf](https://developer.mozilla.org/docs/Web/JavaScript/Reference/Global_Objects/Array/indexOf)
function indexOf(array, el) {
	for (var i = 0; i < array.length; i++) {
		if (array[i] === el) { return i; }
	}
	return -1;
}

// @property emptyImageUrl: String
// Data URI string containing a base64-encoded empty GIF image.
// Used as a hack to free memory from unused images on WebKit-powered
// mobile devices (by setting image `src` to this string).
var emptyImageUrl = 'data:image/gif;base64,R0lGODlhAQABAAD/ACwAAAAAAQABAAACADs=';

// inspired by http://paulirish.com/2011/requestanimationframe-for-smart-animating/

function getPrefixed(name) {
	return window['webkit' + name] || window['moz' + name] || window['ms' + name];
}

var lastTime = 0;

// fallback for IE 7-8
function timeoutDefer(fn) {
	var time = +new Date(),
	    timeToCall = Math.max(0, 16 - (time - lastTime));

	lastTime = time + timeToCall;
	return window.setTimeout(fn, timeToCall);
}

var requestFn = window.requestAnimationFrame || getPrefixed('RequestAnimationFrame') || timeoutDefer;
var cancelFn = window.cancelAnimationFrame || getPrefixed('CancelAnimationFrame') ||
		getPrefixed('CancelRequestAnimationFrame') || function (id) { window.clearTimeout(id); };

// @function requestAnimFrame(fn: Function, context?: Object, immediate?: Boolean): Number
// Schedules `fn` to be executed when the browser repaints. `fn` is bound to
// `context` if given. When `immediate` is set, `fn` is called immediately if
// the browser doesn't have native support for
// [`window.requestAnimationFrame`](https://developer.mozilla.org/docs/Web/API/window/requestAnimationFrame),
// otherwise it's delayed. Returns a request ID that can be used to cancel the request.
function requestAnimFrame(fn, context, immediate) {
	if (immediate && requestFn === timeoutDefer) {
		fn.call(context);
	} else {
		return requestFn.call(window, bind(fn, context));
	}
}

// @function cancelAnimFrame(id: Number): undefined
// Cancels a previous `requestAnimFrame`. See also [window.cancelAnimationFrame](https://developer.mozilla.org/docs/Web/API/window/cancelAnimationFrame).
function cancelAnimFrame(id) {
	if (id) {
		cancelFn.call(window, id);
	}
}

// @class Class
// @aka L.Class

// @section
// @uninheritable

// Thanks to John Resig and Dean Edwards for inspiration!

function Class() {}

Class.extend = function (props) {

	// @function extend(props: Object): Function
	// [Extends the current class](#class-inheritance) given the properties to be included.
	// Returns a Javascript function that is a class constructor (to be called with `new`).
	var NewClass = function () {

		// call the constructor
		if (this.initialize) {
			this.initialize.apply(this, arguments);
		}

		// call all constructor hooks
		this.callInitHooks();
	};

	var parentProto = NewClass.__super__ = this.prototype;

	var proto = create(parentProto);
	proto.constructor = NewClass;

	NewClass.prototype = proto;

	// inherit parent's statics
	for (var i in this) {
		if (this.hasOwnProperty(i) && i !== 'prototype' && i !== '__super__') {
			NewClass[i] = this[i];
		}
	}

	// mix static properties into the class
	if (props.statics) {
		extend(NewClass, props.statics);
		delete props.statics;
	}

	// mix includes into the prototype
	if (props.includes) {
		checkDeprecatedMixinEvents(props.includes);
		extend.apply(null, [proto].concat(props.includes));
		delete props.includes;
	}

	// merge options
	if (proto.options) {
		props.options = extend(create(proto.options), props.options);
	}

	// mix given properties into the prototype
	extend(proto, props);

	proto._initHooks = [];

	// add method for calling all hooks
	proto.callInitHooks = function () {

		if (this._initHooksCalled) { return; }

		if (parentProto.callInitHooks) {
			parentProto.callInitHooks.call(this);
		}

		this._initHooksCalled = true;

		for (var i = 0, len = proto._initHooks.length; i < len; i++) {
			proto._initHooks[i].call(this);
		}
	};

	return NewClass;
};


// @function include(properties: Object): this
// [Includes a mixin](#class-includes) into the current class.
Class.include = function (props) {
	extend(this.prototype, props);
	return this;
};

// @function mergeOptions(options: Object): this
// [Merges `options`](#class-options) into the defaults of the class.
Class.mergeOptions = function (options) {
	extend(this.prototype.options, options);
	return this;
};

// @function addInitHook(fn: Function): this
// Adds a [constructor hook](#class-constructor-hooks) to the class.
Class.addInitHook = function (fn) { // (Function) || (String, args...)
	var args = Array.prototype.slice.call(arguments, 1);

	var init = typeof fn === 'function' ? fn : function () {
		this[fn].apply(this, args);
	};

	this.prototype._initHooks = this.prototype._initHooks || [];
	this.prototype._initHooks.push(init);
	return this;
};

function checkDeprecatedMixinEvents(includes) {
	if (typeof L === 'undefined' || !L || !L.Mixin) { return; }

	includes = isArray(includes) ? includes : [includes];

	for (var i = 0; i < includes.length; i++) {
		if (includes[i] === L.Mixin.Events) {
			console.warn('Deprecated include of L.Mixin.Events: ' +
				'this property will be removed in future releases, ' +
				'please inherit from L.Evented instead.', new Error().stack);
		}
	}
}

/*
 * @class Evented
 * @aka L.Evented
 * @inherits Class
 *
 * A set of methods shared between event-powered classes (like `Map` and `Marker`). Generally, events allow you to execute some function when something happens with an object (e.g. the user clicks on the map, causing the map to fire `'click'` event).
 *
 * @example
 *
 * ```js
 * map.on('click', function(e) {
 * 	alert(e.latlng);
 * } );
 * ```
 *
 * Leaflet deals with event listeners by reference, so if you want to add a listener and then remove it, define it as a function:
 *
 * ```js
 * function onClick(e) { ... }
 *
 * map.on('click', onClick);
 * map.off('click', onClick);
 * ```
 */

var Events = {
	/* @method on(type: String, fn: Function, context?: Object): this
	 * Adds a listener function (`fn`) to a particular event type of the object. You can optionally specify the context of the listener (object the this keyword will point to). You can also pass several space-separated types (e.g. `'click dblclick'`).
	 *
	 * @alternative
	 * @method on(eventMap: Object): this
	 * Adds a set of type/listener pairs, e.g. `{click: onClick, mousemove: onMouseMove}`
	 */
	on: function (types, fn, context) {

		// types can be a map of types/handlers
		if (typeof types === 'object') {
			for (var type in types) {
				// we don't process space-separated events here for performance;
				// it's a hot path since Layer uses the on(obj) syntax
				this._on(type, types[type], fn);
			}

		} else {
			// types can be a string of space-separated words
			types = splitWords(types);

			for (var i = 0, len = types.length; i < len; i++) {
				this._on(types[i], fn, context);
			}
		}

		return this;
	},

	/* @method off(type: String, fn?: Function, context?: Object): this
	 * Removes a previously added listener function. If no function is specified, it will remove all the listeners of that particular event from the object. Note that if you passed a custom context to `on`, you must pass the same context to `off` in order to remove the listener.
	 *
	 * @alternative
	 * @method off(eventMap: Object): this
	 * Removes a set of type/listener pairs.
	 *
	 * @alternative
	 * @method off: this
	 * Removes all listeners to all events on the object. This includes implicitly attached events.
	 */
	off: function (types, fn, context) {

		if (!types) {
			// clear all listeners if called without arguments
			delete this._events;

		} else if (typeof types === 'object') {
			for (var type in types) {
				this._off(type, types[type], fn);
			}

		} else {
			types = splitWords(types);

			for (var i = 0, len = types.length; i < len; i++) {
				this._off(types[i], fn, context);
			}
		}

		return this;
	},

	// attach listener (without syntactic sugar now)
	_on: function (type, fn, context) {
		this._events = this._events || {};

		/* get/init listeners for type */
		var typeListeners = this._events[type];
		if (!typeListeners) {
			typeListeners = [];
			this._events[type] = typeListeners;
		}

		if (context === this) {
			// Less memory footprint.
			context = undefined;
		}
		var newListener = {fn: fn, ctx: context},
		    listeners = typeListeners;

		// check if fn already there
		for (var i = 0, len = listeners.length; i < len; i++) {
			if (listeners[i].fn === fn && listeners[i].ctx === context) {
				return;
			}
		}

		listeners.push(newListener);
	},

	_off: function (type, fn, context) {
		var listeners,
		    i,
		    len;

		if (!this._events) { return; }

		listeners = this._events[type];

		if (!listeners) {
			return;
		}

		if (!fn) {
			// Set all removed listeners to noop so they are not called if remove happens in fire
			for (i = 0, len = listeners.length; i < len; i++) {
				listeners[i].fn = falseFn;
			}
			// clear all listeners for a type if function isn't specified
			delete this._events[type];
			return;
		}

		if (context === this) {
			context = undefined;
		}

		if (listeners) {

			// find fn and remove it
			for (i = 0, len = listeners.length; i < len; i++) {
				var l = listeners[i];
				if (l.ctx !== context) { continue; }
				if (l.fn === fn) {

					// set the removed listener to noop so that's not called if remove happens in fire
					l.fn = falseFn;

					if (this._firingCount) {
						/* copy array in case events are being fired */
						this._events[type] = listeners = listeners.slice();
					}
					listeners.splice(i, 1);

					return;
				}
			}
		}
	},

	// @method fire(type: String, data?: Object, propagate?: Boolean): this
	// Fires an event of the specified type. You can optionally provide an data
	// object — the first argument of the listener function will contain its
	// properties. The event can optionally be propagated to event parents.
	fire: function (type, data, propagate) {
		if (!this.listens(type, propagate)) { return this; }

		var event = extend({}, data, {
			type: type,
			target: this,
			sourceTarget: data && data.sourceTarget || this
		});

		if (this._events) {
			var listeners = this._events[type];

			if (listeners) {
				this._firingCount = (this._firingCount + 1) || 1;
				for (var i = 0, len = listeners.length; i < len; i++) {
					var l = listeners[i];
					l.fn.call(l.ctx || this, event);
				}

				this._firingCount--;
			}
		}

		if (propagate) {
			// propagate the event to parents (set with addEventParent)
			this._propagateEvent(event);
		}

		return this;
	},

	// @method listens(type: String): Boolean
	// Returns `true` if a particular event type has any listeners attached to it.
	listens: function (type, propagate) {
		var listeners = this._events && this._events[type];
		if (listeners && listeners.length) { return true; }

		if (propagate) {
			// also check parents for listeners if event propagates
			for (var id in this._eventParents) {
				if (this._eventParents[id].listens(type, propagate)) { return true; }
			}
		}
		return false;
	},

	// @method once(…): this
	// Behaves as [`on(…)`](#evented-on), except the listener will only get fired once and then removed.
	once: function (types, fn, context) {

		if (typeof types === 'object') {
			for (var type in types) {
				this.once(type, types[type], fn);
			}
			return this;
		}

		var handler = bind(function () {
			this
			    .off(types, fn, context)
			    .off(types, handler, context);
		}, this);

		// add a listener that's executed once and removed after that
		return this
		    .on(types, fn, context)
		    .on(types, handler, context);
	},

	// @method addEventParent(obj: Evented): this
	// Adds an event parent - an `Evented` that will receive propagated events
	addEventParent: function (obj) {
		this._eventParents = this._eventParents || {};
		this._eventParents[stamp$1(obj)] = obj;
		return this;
	},

	// @method removeEventParent(obj: Evented): this
	// Removes an event parent, so it will stop receiving propagated events
	removeEventParent: function (obj) {
		if (this._eventParents) {
			delete this._eventParents[stamp$1(obj)];
		}
		return this;
	},

	_propagateEvent: function (e) {
		for (var id in this._eventParents) {
			this._eventParents[id].fire(e.type, extend({
				layer: e.target,
				propagatedFrom: e.target
			}, e), true);
		}
	}
};

// aliases; we should ditch those eventually

// @method addEventListener(…): this
// Alias to [`on(…)`](#evented-on)
Events.addEventListener = Events.on;

// @method removeEventListener(…): this
// Alias to [`off(…)`](#evented-off)

// @method clearAllEventListeners(…): this
// Alias to [`off()`](#evented-off)
Events.removeEventListener = Events.clearAllEventListeners = Events.off;

// @method addOneTimeEventListener(…): this
// Alias to [`once(…)`](#evented-once)
Events.addOneTimeEventListener = Events.once;

// @method fireEvent(…): this
// Alias to [`fire(…)`](#evented-fire)
Events.fireEvent = Events.fire;

// @method hasEventListeners(…): Boolean
// Alias to [`listens(…)`](#evented-listens)
Events.hasEventListeners = Events.listens;

var Evented = Class.extend(Events);

/*
 * @class Point
 * @aka L.Point
 *
 * Represents a point with `x` and `y` coordinates in pixels.
 *
 * @example
 *
 * ```js
 * var point = L.point(200, 300);
 * ```
 *
 * All Leaflet methods and options that accept `Point` objects also accept them in a simple Array form (unless noted otherwise), so these lines are equivalent:
 *
 * ```js
 * map.panBy([200, 300]);
 * map.panBy(L.point(200, 300));
 * ```
 *
 * Note that `Point` does not inherit from Leafet's `Class` object,
 * which means new classes can't inherit from it, and new methods
 * can't be added to it with the `include` function.
 */

function Point(x, y, round) {
	// @property x: Number; The `x` coordinate of the point
	this.x = (round ? Math.round(x) : x);
	// @property y: Number; The `y` coordinate of the point
	this.y = (round ? Math.round(y) : y);
}

var trunc = Math.trunc || function (v) {
	return v > 0 ? Math.floor(v) : Math.ceil(v);
};

Point.prototype = {

	// @method clone(): Point
	// Returns a copy of the current point.
	clone: function () {
		return new Point(this.x, this.y);
	},

	// @method add(otherPoint: Point): Point
	// Returns the result of addition of the current and the given points.
	add: function (point) {
		// non-destructive, returns a new point
		return this.clone()._add(toPoint(point));
	},

	_add: function (point) {
		// destructive, used directly for performance in situations where it's safe to modify existing point
		this.x += point.x;
		this.y += point.y;
		return this;
	},

	// @method subtract(otherPoint: Point): Point
	// Returns the result of subtraction of the given point from the current.
	subtract: function (point) {
		return this.clone()._subtract(toPoint(point));
	},

	_subtract: function (point) {
		this.x -= point.x;
		this.y -= point.y;
		return this;
	},

	// @method divideBy(num: Number): Point
	// Returns the result of division of the current point by the given number.
	divideBy: function (num) {
		return this.clone()._divideBy(num);
	},

	_divideBy: function (num) {
		this.x /= num;
		this.y /= num;
		return this;
	},

	// @method multiplyBy(num: Number): Point
	// Returns the result of multiplication of the current point by the given number.
	multiplyBy: function (num) {
		return this.clone()._multiplyBy(num);
	},

	_multiplyBy: function (num) {
		this.x *= num;
		this.y *= num;
		return this;
	},

	// @method scaleBy(scale: Point): Point
	// Multiply each coordinate of the current point by each coordinate of
	// `scale`. In linear algebra terms, multiply the point by the
	// [scaling matrix](https://en.wikipedia.org/wiki/Scaling_%28geometry%29#Matrix_representation)
	// defined by `scale`.
	scaleBy: function (point) {
		return new Point(this.x * point.x, this.y * point.y);
	},

	// @method unscaleBy(scale: Point): Point
	// Inverse of `scaleBy`. Divide each coordinate of the current point by
	// each coordinate of `scale`.
	unscaleBy: function (point) {
		return new Point(this.x / point.x, this.y / point.y);
	},

	// @method round(): Point
	// Returns a copy of the current point with rounded coordinates.
	round: function () {
		return this.clone()._round();
	},

	_round: function () {
		this.x = Math.round(this.x);
		this.y = Math.round(this.y);
		return this;
	},

	// @method floor(): Point
	// Returns a copy of the current point with floored coordinates (rounded down).
	floor: function () {
		return this.clone()._floor();
	},

	_floor: function () {
		this.x = Math.floor(this.x);
		this.y = Math.floor(this.y);
		return this;
	},

	// @method ceil(): Point
	// Returns a copy of the current point with ceiled coordinates (rounded up).
	ceil: function () {
		return this.clone()._ceil();
	},

	_ceil: function () {
		this.x = Math.ceil(this.x);
		this.y = Math.ceil(this.y);
		return this;
	},

	// @method trunc(): Point
	// Returns a copy of the current point with truncated coordinates (rounded towards zero).
	trunc: function () {
		return this.clone()._trunc();
	},

	_trunc: function () {
		this.x = trunc(this.x);
		this.y = trunc(this.y);
		return this;
	},

	// @method distanceTo(otherPoint: Point): Number
	// Returns the cartesian distance between the current and the given points.
	distanceTo: function (point) {
		point = toPoint(point);

		var x = point.x - this.x,
		    y = point.y - this.y;

		return Math.sqrt(x * x + y * y);
	},

	// @method equals(otherPoint: Point): Boolean
	// Returns `true` if the given point has the same coordinates.
	equals: function (point) {
		point = toPoint(point);

		return point.x === this.x &&
		       point.y === this.y;
	},

	// @method contains(otherPoint: Point): Boolean
	// Returns `true` if both coordinates of the given point are less than the corresponding current point coordinates (in absolute values).
	contains: function (point) {
		point = toPoint(point);

		return Math.abs(point.x) <= Math.abs(this.x) &&
		       Math.abs(point.y) <= Math.abs(this.y);
	},

	// @method toString(): String
	// Returns a string representation of the point for debugging purposes.
	toString: function () {
		return 'Point(' +
		        formatNum(this.x) + ', ' +
		        formatNum(this.y) + ')';
	}
};

// @factory L.point(x: Number, y: Number, round?: Boolean)
// Creates a Point object with the given `x` and `y` coordinates. If optional `round` is set to true, rounds the `x` and `y` values.

// @alternative
// @factory L.point(coords: Number[])
// Expects an array of the form `[x, y]` instead.

// @alternative
// @factory L.point(coords: Object)
// Expects a plain object of the form `{x: Number, y: Number}` instead.
function toPoint(x, y, round) {
	if (x instanceof Point) {
		return x;
	}
	if (isArray(x)) {
		return new Point(x[0], x[1]);
	}
	if (x === undefined || x === null) {
		return x;
	}
	if (typeof x === 'object' && 'x' in x && 'y' in x) {
		return new Point(x.x, x.y);
	}
	return new Point(x, y, round);
}

/*
 * @class Bounds
 * @aka L.Bounds
 *
 * Represents a rectangular area in pixel coordinates.
 *
 * @example
 *
 * ```js
 * var p1 = L.point(10, 10),
 * p2 = L.point(40, 60),
 * bounds = L.bounds(p1, p2);
 * ```
 *
 * All Leaflet methods that accept `Bounds` objects also accept them in a simple Array form (unless noted otherwise), so the bounds example above can be passed like this:
 *
 * ```js
 * otherBounds.intersects([[10, 10], [40, 60]]);
 * ```
 *
 * Note that `Bounds` does not inherit from Leafet's `Class` object,
 * which means new classes can't inherit from it, and new methods
 * can't be added to it with the `include` function.
 */

function Bounds(a, b) {
	if (!a) { return; }

	var points = b ? [a, b] : a;

	for (var i = 0, len = points.length; i < len; i++) {
		this.extend(points[i]);
	}
}

Bounds.prototype = {
	// @method extend(point: Point): this
	// Extends the bounds to contain the given point.
	extend: function (point) { // (Point)
		point = toPoint(point);

		// @property min: Point
		// The top left corner of the rectangle.
		// @property max: Point
		// The bottom right corner of the rectangle.
		if (!this.min && !this.max) {
			this.min = point.clone();
			this.max = point.clone();
		} else {
			this.min.x = Math.min(point.x, this.min.x);
			this.max.x = Math.max(point.x, this.max.x);
			this.min.y = Math.min(point.y, this.min.y);
			this.max.y = Math.max(point.y, this.max.y);
		}
		return this;
	},

	// @method getCenter(round?: Boolean): Point
	// Returns the center point of the bounds.
	getCenter: function (round) {
		return new Point(
		        (this.min.x + this.max.x) / 2,
		        (this.min.y + this.max.y) / 2, round);
	},

	// @method getBottomLeft(): Point
	// Returns the bottom-left point of the bounds.
	getBottomLeft: function () {
		return new Point(this.min.x, this.max.y);
	},

	// @method getTopRight(): Point
	// Returns the top-right point of the bounds.
	getTopRight: function () { // -> Point
		return new Point(this.max.x, this.min.y);
	},

	// @method getTopLeft(): Point
	// Returns the top-left point of the bounds (i.e. [`this.min`](#bounds-min)).
	getTopLeft: function () {
		return this.min; // left, top
	},

	// @method getBottomRight(): Point
	// Returns the bottom-right point of the bounds (i.e. [`this.max`](#bounds-max)).
	getBottomRight: function () {
		return this.max; // right, bottom
	},

	// @method getSize(): Point
	// Returns the size of the given bounds
	getSize: function () {
		return this.max.subtract(this.min);
	},

	// @method contains(otherBounds: Bounds): Boolean
	// Returns `true` if the rectangle contains the given one.
	// @alternative
	// @method contains(point: Point): Boolean
	// Returns `true` if the rectangle contains the given point.
	contains: function (obj) {
		var min, max;

		if (typeof obj[0] === 'number' || obj instanceof Point) {
			obj = toPoint(obj);
		} else {
			obj = toBounds(obj);
		}

		if (obj instanceof Bounds) {
			min = obj.min;
			max = obj.max;
		} else {
			min = max = obj;
		}

		return (min.x >= this.min.x) &&
		       (max.x <= this.max.x) &&
		       (min.y >= this.min.y) &&
		       (max.y <= this.max.y);
	},

	// @method intersects(otherBounds: Bounds): Boolean
	// Returns `true` if the rectangle intersects the given bounds. Two bounds
	// intersect if they have at least one point in common.
	intersects: function (bounds) { // (Bounds) -> Boolean
		bounds = toBounds(bounds);

		var min = this.min,
		    max = this.max,
		    min2 = bounds.min,
		    max2 = bounds.max,
		    xIntersects = (max2.x >= min.x) && (min2.x <= max.x),
		    yIntersects = (max2.y >= min.y) && (min2.y <= max.y);

		return xIntersects && yIntersects;
	},

	// @method overlaps(otherBounds: Bounds): Boolean
	// Returns `true` if the rectangle overlaps the given bounds. Two bounds
	// overlap if their intersection is an area.
	overlaps: function (bounds) { // (Bounds) -> Boolean
		bounds = toBounds(bounds);

		var min = this.min,
		    max = this.max,
		    min2 = bounds.min,
		    max2 = bounds.max,
		    xOverlaps = (max2.x > min.x) && (min2.x < max.x),
		    yOverlaps = (max2.y > min.y) && (min2.y < max.y);

		return xOverlaps && yOverlaps;
	},

	isValid: function () {
		return !!(this.min && this.max);
	}
};


// @factory L.bounds(corner1: Point, corner2: Point)
// Creates a Bounds object from two corners coordinate pairs.
// @alternative
// @factory L.bounds(points: Point[])
// Creates a Bounds object from the given array of points.
function toBounds(a, b) {
	if (!a || a instanceof Bounds) {
		return a;
	}
	return new Bounds(a, b);
}

/*
 * @class LatLngBounds
 * @aka L.LatLngBounds
 *
 * Represents a rectangular geographical area on a map.
 *
 * @example
 *
 * ```js
 * var corner1 = L.latLng(40.712, -74.227),
 * corner2 = L.latLng(40.774, -74.125),
 * bounds = L.latLngBounds(corner1, corner2);
 * ```
 *
 * All Leaflet methods that accept LatLngBounds objects also accept them in a simple Array form (unless noted otherwise), so the bounds example above can be passed like this:
 *
 * ```js
 * map.fitBounds([
 * 	[40.712, -74.227],
 * 	[40.774, -74.125]
 * ]);
 * ```
 *
 * Caution: if the area crosses the antimeridian (often confused with the International Date Line), you must specify corners _outside_ the [-180, 180] degrees longitude range.
 *
 * Note that `LatLngBounds` does not inherit from Leafet's `Class` object,
 * which means new classes can't inherit from it, and new methods
 * can't be added to it with the `include` function.
 */

function LatLngBounds(corner1, corner2) { // (LatLng, LatLng) or (LatLng[])
	if (!corner1) { return; }

	var latlngs = corner2 ? [corner1, corner2] : corner1;

	for (var i = 0, len = latlngs.length; i < len; i++) {
		this.extend(latlngs[i]);
	}
}

LatLngBounds.prototype = {

	// @method extend(latlng: LatLng): this
	// Extend the bounds to contain the given point

	// @alternative
	// @method extend(otherBounds: LatLngBounds): this
	// Extend the bounds to contain the given bounds
	extend: function (obj) {
		var sw = this._southWest,
		    ne = this._northEast,
		    sw2, ne2;

		if (obj instanceof LatLng) {
			sw2 = obj;
			ne2 = obj;

		} else if (obj instanceof LatLngBounds) {
			sw2 = obj._southWest;
			ne2 = obj._northEast;

			if (!sw2 || !ne2) { return this; }

		} else {
			return obj ? this.extend(toLatLng(obj) || toLatLngBounds(obj)) : this;
		}

		if (!sw && !ne) {
			this._southWest = new LatLng(sw2.lat, sw2.lng);
			this._northEast = new LatLng(ne2.lat, ne2.lng);
		} else {
			sw.lat = Math.min(sw2.lat, sw.lat);
			sw.lng = Math.min(sw2.lng, sw.lng);
			ne.lat = Math.max(ne2.lat, ne.lat);
			ne.lng = Math.max(ne2.lng, ne.lng);
		}

		return this;
	},

	// @method pad(bufferRatio: Number): LatLngBounds
	// Returns bounds created by extending or retracting the current bounds by a given ratio in each direction.
	// For example, a ratio of 0.5 extends the bounds by 50% in each direction.
	// Negative values will retract the bounds.
	pad: function (bufferRatio) {
		var sw = this._southWest,
		    ne = this._northEast,
		    heightBuffer = Math.abs(sw.lat - ne.lat) * bufferRatio,
		    widthBuffer = Math.abs(sw.lng - ne.lng) * bufferRatio;

		return new LatLngBounds(
		        new LatLng(sw.lat - heightBuffer, sw.lng - widthBuffer),
		        new LatLng(ne.lat + heightBuffer, ne.lng + widthBuffer));
	},

	// @method getCenter(): LatLng
	// Returns the center point of the bounds.
	getCenter: function () {
		return new LatLng(
		        (this._southWest.lat + this._northEast.lat) / 2,
		        (this._southWest.lng + this._northEast.lng) / 2);
	},

	// @method getSouthWest(): LatLng
	// Returns the south-west point of the bounds.
	getSouthWest: function () {
		return this._southWest;
	},

	// @method getNorthEast(): LatLng
	// Returns the north-east point of the bounds.
	getNorthEast: function () {
		return this._northEast;
	},

	// @method getNorthWest(): LatLng
	// Returns the north-west point of the bounds.
	getNorthWest: function () {
		return new LatLng(this.getNorth(), this.getWest());
	},

	// @method getSouthEast(): LatLng
	// Returns the south-east point of the bounds.
	getSouthEast: function () {
		return new LatLng(this.getSouth(), this.getEast());
	},

	// @method getWest(): Number
	// Returns the west longitude of the bounds
	getWest: function () {
		return this._southWest.lng;
	},

	// @method getSouth(): Number
	// Returns the south latitude of the bounds
	getSouth: function () {
		return this._southWest.lat;
	},

	// @method getEast(): Number
	// Returns the east longitude of the bounds
	getEast: function () {
		return this._northEast.lng;
	},

	// @method getNorth(): Number
	// Returns the north latitude of the bounds
	getNorth: function () {
		return this._northEast.lat;
	},

	// @method contains(otherBounds: LatLngBounds): Boolean
	// Returns `true` if the rectangle contains the given one.

	// @alternative
	// @method contains (latlng: LatLng): Boolean
	// Returns `true` if the rectangle contains the given point.
	contains: function (obj) { // (LatLngBounds) or (LatLng) -> Boolean
		if (typeof obj[0] === 'number' || obj instanceof LatLng || 'lat' in obj) {
			obj = toLatLng(obj);
		} else {
			obj = toLatLngBounds(obj);
		}

		var sw = this._southWest,
		    ne = this._northEast,
		    sw2, ne2;

		if (obj instanceof LatLngBounds) {
			sw2 = obj.getSouthWest();
			ne2 = obj.getNorthEast();
		} else {
			sw2 = ne2 = obj;
		}

		return (sw2.lat >= sw.lat) && (ne2.lat <= ne.lat) &&
		       (sw2.lng >= sw.lng) && (ne2.lng <= ne.lng);
	},

	// @method intersects(otherBounds: LatLngBounds): Boolean
	// Returns `true` if the rectangle intersects the given bounds. Two bounds intersect if they have at least one point in common.
	intersects: function (bounds) {
		bounds = toLatLngBounds(bounds);

		var sw = this._southWest,
		    ne = this._northEast,
		    sw2 = bounds.getSouthWest(),
		    ne2 = bounds.getNorthEast(),

		    latIntersects = (ne2.lat >= sw.lat) && (sw2.lat <= ne.lat),
		    lngIntersects = (ne2.lng >= sw.lng) && (sw2.lng <= ne.lng);

		return latIntersects && lngIntersects;
	},

	// @method overlaps(otherBounds: Bounds): Boolean
	// Returns `true` if the rectangle overlaps the given bounds. Two bounds overlap if their intersection is an area.
	overlaps: function (bounds) {
		bounds = toLatLngBounds(bounds);

		var sw = this._southWest,
		    ne = this._northEast,
		    sw2 = bounds.getSouthWest(),
		    ne2 = bounds.getNorthEast(),

		    latOverlaps = (ne2.lat > sw.lat) && (sw2.lat < ne.lat),
		    lngOverlaps = (ne2.lng > sw.lng) && (sw2.lng < ne.lng);

		return latOverlaps && lngOverlaps;
	},

	// @method toBBoxString(): String
	// Returns a string with bounding box coordinates in a 'southwest_lng,southwest_lat,northeast_lng,northeast_lat' format. Useful for sending requests to web services that return geo data.
	toBBoxString: function () {
		return [this.getWest(), this.getSouth(), this.getEast(), this.getNorth()].join(',');
	},

	// @method equals(otherBounds: LatLngBounds, maxMargin?: Number): Boolean
	// Returns `true` if the rectangle is equivalent (within a small margin of error) to the given bounds. The margin of error can be overridden by setting `maxMargin` to a small number.
	equals: function (bounds, maxMargin) {
		if (!bounds) { return false; }

		bounds = toLatLngBounds(bounds);

		return this._southWest.equals(bounds.getSouthWest(), maxMargin) &&
		       this._northEast.equals(bounds.getNorthEast(), maxMargin);
	},

	// @method isValid(): Boolean
	// Returns `true` if the bounds are properly initialized.
	isValid: function () {
		return !!(this._southWest && this._northEast);
	}
};

// TODO International date line?

// @factory L.latLngBounds(corner1: LatLng, corner2: LatLng)
// Creates a `LatLngBounds` object by defining two diagonally opposite corners of the rectangle.

// @alternative
// @factory L.latLngBounds(latlngs: LatLng[])
// Creates a `LatLngBounds` object defined by the geographical points it contains. Very useful for zooming the map to fit a particular set of locations with [`fitBounds`](#map-fitbounds).
function toLatLngBounds(a, b) {
	if (a instanceof LatLngBounds) {
		return a;
	}
	return new LatLngBounds(a, b);
}

/* @class LatLng
 * @aka L.LatLng
 *
 * Represents a geographical point with a certain latitude and longitude.
 *
 * @example
 *
 * ```
 * var latlng = L.latLng(50.5, 30.5);
 * ```
 *
 * All Leaflet methods that accept LatLng objects also accept them in a simple Array form and simple object form (unless noted otherwise), so these lines are equivalent:
 *
 * ```
 * map.panTo([50, 30]);
 * map.panTo({lon: 30, lat: 50});
 * map.panTo({lat: 50, lng: 30});
 * map.panTo(L.latLng(50, 30));
 * ```
 *
 * Note that `LatLng` does not inherit from Leaflet's `Class` object,
 * which means new classes can't inherit from it, and new methods
 * can't be added to it with the `include` function.
 */

function LatLng(lat, lng, alt) {
	if (isNaN(lat) || isNaN(lng)) {
		throw new Error('Invalid LatLng object: (' + lat + ', ' + lng + ')');
	}

	// @property lat: Number
	// Latitude in degrees
	this.lat = +lat;

	// @property lng: Number
	// Longitude in degrees
	this.lng = +lng;

	// @property alt: Number
	// Altitude in meters (optional)
	if (alt !== undefined) {
		this.alt = +alt;
	}
}

LatLng.prototype = {
	// @method equals(otherLatLng: LatLng, maxMargin?: Number): Boolean
	// Returns `true` if the given `LatLng` point is at the same position (within a small margin of error). The margin of error can be overridden by setting `maxMargin` to a small number.
	equals: function (obj, maxMargin) {
		if (!obj) { return false; }

		obj = toLatLng(obj);

		var margin = Math.max(
		        Math.abs(this.lat - obj.lat),
		        Math.abs(this.lng - obj.lng));

		return margin <= (maxMargin === undefined ? 1.0E-9 : maxMargin);
	},

	// @method toString(): String
	// Returns a string representation of the point (for debugging purposes).
	toString: function (precision) {
		return 'LatLng(' +
		        formatNum(this.lat, precision) + ', ' +
		        formatNum(this.lng, precision) + ')';
	},

	// @method distanceTo(otherLatLng: LatLng): Number
	// Returns the distance (in meters) to the given `LatLng` calculated using the [Spherical Law of Cosines](https://en.wikipedia.org/wiki/Spherical_law_of_cosines).
	distanceTo: function (other) {
		return Earth.distance(this, toLatLng(other));
	},

	// @method wrap(): LatLng
	// Returns a new `LatLng` object with the longitude wrapped so it's always between -180 and +180 degrees.
	wrap: function () {
		return Earth.wrapLatLng(this);
	},

	// @method toBounds(sizeInMeters: Number): LatLngBounds
	// Returns a new `LatLngBounds` object in which each boundary is `sizeInMeters/2` meters apart from the `LatLng`.
	toBounds: function (sizeInMeters) {
		var latAccuracy = 180 * sizeInMeters / 40075017,
		    lngAccuracy = latAccuracy / Math.cos((Math.PI / 180) * this.lat);

		return toLatLngBounds(
		        [this.lat - latAccuracy, this.lng - lngAccuracy],
		        [this.lat + latAccuracy, this.lng + lngAccuracy]);
	},

	clone: function () {
		return new LatLng(this.lat, this.lng, this.alt);
	}
};



// @factory L.latLng(latitude: Number, longitude: Number, altitude?: Number): LatLng
// Creates an object representing a geographical point with the given latitude and longitude (and optionally altitude).

// @alternative
// @factory L.latLng(coords: Array): LatLng
// Expects an array of the form `[Number, Number]` or `[Number, Number, Number]` instead.

// @alternative
// @factory L.latLng(coords: Object): LatLng
// Expects an plain object of the form `{lat: Number, lng: Number}` or `{lat: Number, lng: Number, alt: Number}` instead.

function toLatLng(a, b, c) {
	if (a instanceof LatLng) {
		return a;
	}
	if (isArray(a) && typeof a[0] !== 'object') {
		if (a.length === 3) {
			return new LatLng(a[0], a[1], a[2]);
		}
		if (a.length === 2) {
			return new LatLng(a[0], a[1]);
		}
		return null;
	}
	if (a === undefined || a === null) {
		return a;
	}
	if (typeof a === 'object' && 'lat' in a) {
		return new LatLng(a.lat, 'lng' in a ? a.lng : a.lon, a.alt);
	}
	if (b === undefined) {
		return null;
	}
	return new LatLng(a, b, c);
}

/*
 * @namespace CRS
 * @crs L.CRS.Base
 * Object that defines coordinate reference systems for projecting
 * geographical points into pixel (screen) coordinates and back (and to
 * coordinates in other units for [WMS](https://en.wikipedia.org/wiki/Web_Map_Service) services). See
 * [spatial reference system](http://en.wikipedia.org/wiki/Coordinate_reference_system).
 *
 * Leaflet defines the most usual CRSs by default. If you want to use a
 * CRS not defined by default, take a look at the
 * [Proj4Leaflet](https://github.com/kartena/Proj4Leaflet) plugin.
 *
 * Note that the CRS instances do not inherit from Leafet's `Class` object,
 * and can't be instantiated. Also, new classes can't inherit from them,
 * and methods can't be added to them with the `include` function.
 */

var CRS = {
	// @method latLngToPoint(latlng: LatLng, zoom: Number): Point
	// Projects geographical coordinates into pixel coordinates for a given zoom.
	latLngToPoint: function (latlng, zoom) {
		var projectedPoint = this.projection.project(latlng),
		    scale = this.scale(zoom);

		return this.transformation._transform(projectedPoint, scale);
	},

	// @method pointToLatLng(point: Point, zoom: Number): LatLng
	// The inverse of `latLngToPoint`. Projects pixel coordinates on a given
	// zoom into geographical coordinates.
	pointToLatLng: function (point, zoom) {
		var scale = this.scale(zoom),
		    untransformedPoint = this.transformation.untransform(point, scale);

		return this.projection.unproject(untransformedPoint);
	},

	// @method project(latlng: LatLng): Point
	// Projects geographical coordinates into coordinates in units accepted for
	// this CRS (e.g. meters for EPSG:3857, for passing it to WMS services).
	project: function (latlng) {
		return this.projection.project(latlng);
	},

	// @method unproject(point: Point): LatLng
	// Given a projected coordinate returns the corresponding LatLng.
	// The inverse of `project`.
	unproject: function (point) {
		return this.projection.unproject(point);
	},

	// @method scale(zoom: Number): Number
	// Returns the scale used when transforming projected coordinates into
	// pixel coordinates for a particular zoom. For example, it returns
	// `256 * 2^zoom` for Mercator-based CRS.
	scale: function (zoom) {
		return 256 * Math.pow(2, zoom);
	},

	// @method zoom(scale: Number): Number
	// Inverse of `scale()`, returns the zoom level corresponding to a scale
	// factor of `scale`.
	zoom: function (scale) {
		return Math.log(scale / 256) / Math.LN2;
	},

	// @method getProjectedBounds(zoom: Number): Bounds
	// Returns the projection's bounds scaled and transformed for the provided `zoom`.
	getProjectedBounds: function (zoom) {
		if (this.infinite) { return null; }

		var b = this.projection.bounds,
		    s = this.scale(zoom),
		    min = this.transformation.transform(b.min, s),
		    max = this.transformation.transform(b.max, s);

		return new Bounds(min, max);
	},

	// @method distance(latlng1: LatLng, latlng2: LatLng): Number
	// Returns the distance between two geographical coordinates.

	// @property code: String
	// Standard code name of the CRS passed into WMS services (e.g. `'EPSG:3857'`)
	//
	// @property wrapLng: Number[]
	// An array of two numbers defining whether the longitude (horizontal) coordinate
	// axis wraps around a given range and how. Defaults to `[-180, 180]` in most
	// geographical CRSs. If `undefined`, the longitude axis does not wrap around.
	//
	// @property wrapLat: Number[]
	// Like `wrapLng`, but for the latitude (vertical) axis.

	// wrapLng: [min, max],
	// wrapLat: [min, max],

	// @property infinite: Boolean
	// If true, the coordinate space will be unbounded (infinite in both axes)
	infinite: false,

	// @method wrapLatLng(latlng: LatLng): LatLng
	// Returns a `LatLng` where lat and lng has been wrapped according to the
	// CRS's `wrapLat` and `wrapLng` properties, if they are outside the CRS's bounds.
	wrapLatLng: function (latlng) {
		var lng = this.wrapLng ? wrapNum(latlng.lng, this.wrapLng, true) : latlng.lng,
		    lat = this.wrapLat ? wrapNum(latlng.lat, this.wrapLat, true) : latlng.lat,
		    alt = latlng.alt;

		return new LatLng(lat, lng, alt);
	},

	// @method wrapLatLngBounds(bounds: LatLngBounds): LatLngBounds
	// Returns a `LatLngBounds` with the same size as the given one, ensuring
	// that its center is within the CRS's bounds.
	// Only accepts actual `L.LatLngBounds` instances, not arrays.
	wrapLatLngBounds: function (bounds) {
		var center = bounds.getCenter(),
		    newCenter = this.wrapLatLng(center),
		    latShift = center.lat - newCenter.lat,
		    lngShift = center.lng - newCenter.lng;

		if (latShift === 0 && lngShift === 0) {
			return bounds;
		}

		var sw = bounds.getSouthWest(),
		    ne = bounds.getNorthEast(),
		    newSw = new LatLng(sw.lat - latShift, sw.lng - lngShift),
		    newNe = new LatLng(ne.lat - latShift, ne.lng - lngShift);

		return new LatLngBounds(newSw, newNe);
	}
};

/*
 * @namespace CRS
 * @crs L.CRS.Earth
 *
 * Serves as the base for CRS that are global such that they cover the earth.
 * Can only be used as the base for other CRS and cannot be used directly,
 * since it does not have a `code`, `projection` or `transformation`. `distance()` returns
 * meters.
 */

var Earth = extend({}, CRS, {
	wrapLng: [-180, 180],

	// Mean Earth Radius, as recommended for use by
	// the International Union of Geodesy and Geophysics,
	// see http://rosettacode.org/wiki/Haversine_formula
	R: 6371000,

	// distance between two geographical points using spherical law of cosines approximation
	distance: function (latlng1, latlng2) {
		var rad = Math.PI / 180,
		    lat1 = latlng1.lat * rad,
		    lat2 = latlng2.lat * rad,
		    sinDLat = Math.sin((latlng2.lat - latlng1.lat) * rad / 2),
		    sinDLon = Math.sin((latlng2.lng - latlng1.lng) * rad / 2),
		    a = sinDLat * sinDLat + Math.cos(lat1) * Math.cos(lat2) * sinDLon * sinDLon,
		    c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
		return this.R * c;
	}
});

/*
 * @namespace Projection
 * @projection L.Projection.SphericalMercator
 *
 * Spherical Mercator projection — the most common projection for online maps,
 * used by almost all free and commercial tile providers. Assumes that Earth is
 * a sphere. Used by the `EPSG:3857` CRS.
 */

var earthRadius = 6378137;

var SphericalMercator = {

	R: earthRadius,
	MAX_LATITUDE: 85.0511287798,

	project: function (latlng) {
		var d = Math.PI / 180,
		    max = this.MAX_LATITUDE,
		    lat = Math.max(Math.min(max, latlng.lat), -max),
		    sin = Math.sin(lat * d);

		return new Point(
			this.R * latlng.lng * d,
			this.R * Math.log((1 + sin) / (1 - sin)) / 2);
	},

	unproject: function (point) {
		var d = 180 / Math.PI;

		return new LatLng(
			(2 * Math.atan(Math.exp(point.y / this.R)) - (Math.PI / 2)) * d,
			point.x * d / this.R);
	},

	bounds: (function () {
		var d = earthRadius * Math.PI;
		return new Bounds([-d, -d], [d, d]);
	})()
};

/*
 * @class Transformation
 * @aka L.Transformation
 *
 * Represents an affine transformation: a set of coefficients `a`, `b`, `c`, `d`
 * for transforming a point of a form `(x, y)` into `(a*x + b, c*y + d)` and doing
 * the reverse. Used by Leaflet in its projections code.
 *
 * @example
 *
 * ```js
 * var transformation = L.transformation(2, 5, -1, 10),
 * 	p = L.point(1, 2),
 * 	p2 = transformation.transform(p), //  L.point(7, 8)
 * 	p3 = transformation.untransform(p2); //  L.point(1, 2)
 * ```
 */


// factory new L.Transformation(a: Number, b: Number, c: Number, d: Number)
// Creates a `Transformation` object with the given coefficients.
function Transformation(a, b, c, d) {
	if (isArray(a)) {
		// use array properties
		this._a = a[0];
		this._b = a[1];
		this._c = a[2];
		this._d = a[3];
		return;
	}
	this._a = a;
	this._b = b;
	this._c = c;
	this._d = d;
}

Transformation.prototype = {
	// @method transform(point: Point, scale?: Number): Point
	// Returns a transformed point, optionally multiplied by the given scale.
	// Only accepts actual `L.Point` instances, not arrays.
	transform: function (point, scale) { // (Point, Number) -> Point
		return this._transform(point.clone(), scale);
	},

	// destructive transform (faster)
	_transform: function (point, scale) {
		scale = scale || 1;
		point.x = scale * (this._a * point.x + this._b);
		point.y = scale * (this._c * point.y + this._d);
		return point;
	},

	// @method untransform(point: Point, scale?: Number): Point
	// Returns the reverse transformation of the given point, optionally divided
	// by the given scale. Only accepts actual `L.Point` instances, not arrays.
	untransform: function (point, scale) {
		scale = scale || 1;
		return new Point(
		        (point.x / scale - this._b) / this._a,
		        (point.y / scale - this._d) / this._c);
	}
};

// factory L.transformation(a: Number, b: Number, c: Number, d: Number)

// @factory L.transformation(a: Number, b: Number, c: Number, d: Number)
// Instantiates a Transformation object with the given coefficients.

// @alternative
// @factory L.transformation(coefficients: Array): Transformation
// Expects an coefficients array of the form
// `[a: Number, b: Number, c: Number, d: Number]`.

function toTransformation(a, b, c, d) {
	return new Transformation(a, b, c, d);
}

/*
 * @namespace CRS
 * @crs L.CRS.EPSG3857
 *
 * The most common CRS for online maps, used by almost all free and commercial
 * tile providers. Uses Spherical Mercator projection. Set in by default in
 * Map's `crs` option.
 */

var EPSG3857 = extend({}, Earth, {
	code: 'EPSG:3857',
	projection: SphericalMercator,

	transformation: (function () {
		var scale = 0.5 / (Math.PI * SphericalMercator.R);
		return toTransformation(scale, 0.5, -scale, 0.5);
	}())
});

var EPSG900913 = extend({}, EPSG3857, {
	code: 'EPSG:900913'
});

// @namespace SVG; @section
// There are several static functions which can be called without instantiating L.SVG:

// @function create(name: String): SVGElement
// Returns a instance of [SVGElement](https://developer.mozilla.org/docs/Web/API/SVGElement),
// corresponding to the class name passed. For example, using 'line' will return
// an instance of [SVGLineElement](https://developer.mozilla.org/docs/Web/API/SVGLineElement).
function svgCreate(name) {
	return document.createElementNS('http://www.w3.org/2000/svg', name);
}

// @function pointsToPath(rings: Point[], closed: Boolean): String
// Generates a SVG path string for multiple rings, with each ring turning
// into "M..L..L.." instructions
function pointsToPath(rings, closed) {
	var str = '',
	i, j, len, len2, points, p;

	for (i = 0, len = rings.length; i < len; i++) {
		points = rings[i];

		for (j = 0, len2 = points.length; j < len2; j++) {
			p = points[j];
			str += (j ? 'L' : 'M') + p.x + ' ' + p.y;
		}

		// closes the ring for polygons; "x" is VML syntax
		str += closed ? (svg ? 'z' : 'x') : '';
	}

	// SVG complains about empty path strings
	return str || 'M0 0';
}

/*
 * @namespace Browser
 * @aka L.Browser
 *
 * A namespace with static properties for browser/feature detection used by Leaflet internally.
 *
 * @example
 *
 * ```js
 * if (L.Browser.ielt9) {
 *   alert('Upgrade your browser, dude!');
 * }
 * ```
 */

var style = document.documentElement.style;

// @property ie: Boolean; `true` for all Internet Explorer versions (not Edge).
var ie = 'ActiveXObject' in window;

// @property ielt9: Boolean; `true` for Internet Explorer versions less than 9.
var ielt9 = ie && !document.addEventListener;

// @property edge: Boolean; `true` for the Edge web browser.
var edge = 'msLaunchUri' in navigator && !('documentMode' in document);

// @property webkit: Boolean;
// `true` for webkit-based browsers like Chrome and Safari (including mobile versions).
var webkit = userAgentContains('webkit');

// @property android: Boolean
// `true` for any browser running on an Android platform.
var android = userAgentContains('android');

// @property android23: Boolean; `true` for browsers running on Android 2 or Android 3.
var android23 = userAgentContains('android 2') || userAgentContains('android 3');

/* See https://stackoverflow.com/a/17961266 for details on detecting stock Android */
var webkitVer = parseInt(/WebKit\/([0-9]+)|$/.exec(navigator.userAgent)[1], 10); // also matches AppleWebKit
// @property androidStock: Boolean; `true` for the Android stock browser (i.e. not Chrome)
var androidStock = android && userAgentContains('Google') && webkitVer < 537 && !('AudioNode' in window);

// @property opera: Boolean; `true` for the Opera browser
var opera = !!window.opera;

// @property chrome: Boolean; `true` for the Chrome browser.
var chrome = userAgentContains('chrome');

// @property gecko: Boolean; `true` for gecko-based browsers like Firefox.
var gecko = userAgentContains('gecko') && !webkit && !opera && !ie;

// @property safari: Boolean; `true` for the Safari browser.
var safari = !chrome && userAgentContains('safari');

var phantom = userAgentContains('phantom');

// @property opera12: Boolean
// `true` for the Opera browser supporting CSS transforms (version 12 or later).
var opera12 = 'OTransition' in style;

// @property win: Boolean; `true` when the browser is running in a Windows platform
var win = navigator.platform.indexOf('Win') === 0;

// @property ie3d: Boolean; `true` for all Internet Explorer versions supporting CSS transforms.
var ie3d = ie && ('transition' in style);

// @property webkit3d: Boolean; `true` for webkit-based browsers supporting CSS transforms.
var webkit3d = ('WebKitCSSMatrix' in window) && ('m11' in new window.WebKitCSSMatrix()) && !android23;

// @property gecko3d: Boolean; `true` for gecko-based browsers supporting CSS transforms.
var gecko3d = 'MozPerspective' in style;

// @property any3d: Boolean
// `true` for all browsers supporting CSS transforms.
var any3d = !window.L_DISABLE_3D && (ie3d || webkit3d || gecko3d) && !opera12 && !phantom;

// @property mobile: Boolean; `true` for all browsers running in a mobile device.
var mobile = typeof orientation !== 'undefined' || userAgentContains('mobile');

// @property msPointer: Boolean
// `true` for browsers implementing the Microsoft touch events model (notably IE10).
var msPointer = !window.PointerEvent && window.MSPointerEvent;

// @property pointer: Boolean
// `true` for all browsers supporting [pointer events](https://msdn.microsoft.com/en-us/library/dn433244%28v=vs.85%29.aspx).
var pointer = !webkit && !!(window.PointerEvent || msPointer);

// @property touch: Boolean
// `true` for all browsers supporting [touch events](https://developer.mozilla.org/docs/Web/API/Touch_events).
// This does not necessarily mean that the browser is running in a computer with
// a touchscreen, it only means that the browser is capable of understanding
// touch events.
var touch = !window.L_NO_TOUCH && (pointer || 'ontouchstart' in window ||
		(window.DocumentTouch && document instanceof window.DocumentTouch));

// @property mobileOpera: Boolean; `true` for the Opera browser in a mobile device.
var mobileOpera = mobile && opera;

// @property retina: Boolean
// `true` for browsers on a high-resolution "retina" screen or on any screen when browser's display zoom is more than 100%.
var retina = (window.devicePixelRatio || (window.screen.deviceXDPI / window.screen.logicalXDPI)) > 1;

// @property passiveEvents: Boolean
// `true` for browsers that support passive events.
var passiveEvents = (function () {
	var supportsPassiveOption = false;
	try {
		var opts = Object.defineProperty({}, 'passive', {
			get: function () {
				supportsPassiveOption = true;
			}
		});
		window.addEventListener('testPassiveEventSupport', falseFn, opts);
		window.removeEventListener('testPassiveEventSupport', falseFn, opts);
	} catch (e) {
		// Errors can safely be ignored since this is only a browser support test.
	}
	return supportsPassiveOption;
});

// @property canvas: Boolean
// `true` when the browser supports [`<canvas>`](https://developer.mozilla.org/docs/Web/API/Canvas_API).
var canvas = (function () {
	return !!document.createElement('canvas').getContext;
}());

// @property svg: Boolean
// `true` when the browser supports [SVG](https://developer.mozilla.org/docs/Web/SVG).
var svg = !!(document.createElementNS && svgCreate('svg').createSVGRect);

// @property vml: Boolean
// `true` if the browser supports [VML](https://en.wikipedia.org/wiki/Vector_Markup_Language).
var vml = !svg && (function () {
	try {
		var div = document.createElement('div');
		div.innerHTML = '<v:shape adj="1"/>';

		var shape = div.firstChild;
		shape.style.behavior = 'url(#default#VML)';

		return shape && (typeof shape.adj === 'object');

	} catch (e) {
		return false;
	}
}());


function userAgentContains(str) {
	return navigator.userAgent.toLowerCase().indexOf(str) >= 0;
}

/*
 * Extends L.DomEvent to provide touch support for Internet Explorer and Windows-based devices.
 */


var POINTER_DOWN =   msPointer ? 'MSPointerDown'   : 'pointerdown';
var POINTER_MOVE =   msPointer ? 'MSPointerMove'   : 'pointermove';
var POINTER_UP =     msPointer ? 'MSPointerUp'     : 'pointerup';
var POINTER_CANCEL = msPointer ? 'MSPointerCancel' : 'pointercancel';
var TAG_WHITE_LIST = ['INPUT', 'SELECT', 'OPTION'];

var _pointers = {};
var _pointerDocListener = false;

// DomEvent.DoubleTap needs to know about this
var _pointersCount = 0;

// Provides a touch events wrapper for (ms)pointer events.
// ref http://www.w3.org/TR/pointerevents/ https://www.w3.org/Bugs/Public/show_bug.cgi?id=22890

function addPointerListener(obj, type, handler, id) {
	if (type === 'touchstart') {
		_addPointerStart(obj, handler, id);

	} else if (type === 'touchmove') {
		_addPointerMove(obj, handler, id);

	} else if (type === 'touchend') {
		_addPointerEnd(obj, handler, id);
	}

	return this;
}

function removePointerListener(obj, type, id) {
	var handler = obj['_leaflet_' + type + id];

	if (type === 'touchstart') {
		obj.removeEventListener(POINTER_DOWN, handler, false);

	} else if (type === 'touchmove') {
		obj.removeEventListener(POINTER_MOVE, handler, false);

	} else if (type === 'touchend') {
		obj.removeEventListener(POINTER_UP, handler, false);
		obj.removeEventListener(POINTER_CANCEL, handler, false);
	}

	return this;
}

function _addPointerStart(obj, handler, id) {
	var onDown = bind(function (e) {
		if (e.pointerType !== 'mouse' && e.MSPOINTER_TYPE_MOUSE && e.pointerType !== e.MSPOINTER_TYPE_MOUSE) {
			// In IE11, some touch events needs to fire for form controls, or
			// the controls will stop working. We keep a whitelist of tag names that
			// need these events. For other target tags, we prevent default on the event.
			if (TAG_WHITE_LIST.indexOf(e.target.tagName) < 0) {
				preventDefault(e);
			} else {
				return;
			}
		}

		_handlePointer(e, handler);
	});

	obj['_leaflet_touchstart' + id] = onDown;
	obj.addEventListener(POINTER_DOWN, onDown, false);

	// need to keep track of what pointers and how many are active to provide e.touches emulation
	if (!_pointerDocListener) {
		// we listen documentElement as any drags that end by moving the touch off the screen get fired there
		document.documentElement.addEventListener(POINTER_DOWN, _globalPointerDown, true);
		document.documentElement.addEventListener(POINTER_MOVE, _globalPointerMove, true);
		document.documentElement.addEventListener(POINTER_UP, _globalPointerUp, true);
		document.documentElement.addEventListener(POINTER_CANCEL, _globalPointerUp, true);

		_pointerDocListener = true;
	}
}

function _globalPointerDown(e) {
	_pointers[e.pointerId] = e;
	_pointersCount++;
}

function _globalPointerMove(e) {
	if (_pointers[e.pointerId]) {
		_pointers[e.pointerId] = e;
	}
}

function _globalPointerUp(e) {
	delete _pointers[e.pointerId];
	_pointersCount--;
}

function _handlePointer(e, handler) {
	e.touches = [];
	for (var i in _pointers) {
		e.touches.push(_pointers[i]);
	}
	e.changedTouches = [e];

	handler(e);
}

function _addPointerMove(obj, handler, id) {
	var onMove = function (e) {
		// don't fire touch moves when mouse isn't down
		if ((e.pointerType === e.MSPOINTER_TYPE_MOUSE || e.pointerType === 'mouse') && e.buttons === 0) { return; }

		_handlePointer(e, handler);
	};

	obj['_leaflet_touchmove' + id] = onMove;
	obj.addEventListener(POINTER_MOVE, onMove, false);
}

function _addPointerEnd(obj, handler, id) {
	var onUp = function (e) {
		_handlePointer(e, handler);
	};

	obj['_leaflet_touchend' + id] = onUp;
	obj.addEventListener(POINTER_UP, onUp, false);
	obj.addEventListener(POINTER_CANCEL, onUp, false);
}

/*
 * Extends the event handling code with double tap support for mobile browsers.
 */

var _touchstart = msPointer ? 'MSPointerDown' : pointer ? 'pointerdown' : 'touchstart';
var _touchend = msPointer ? 'MSPointerUp' : pointer ? 'pointerup' : 'touchend';
var _pre = '_leaflet_';

// inspired by Zepto touch code by Thomas Fuchs
function addDoubleTapListener(obj, handler, id) {
	var last, touch,
	    doubleTap = false,
	    delay = 250;

	function onTouchStart(e) {
		var count;

		if (pointer) {
			if ((!edge) || e.pointerType === 'mouse') { return; }
			count = _pointersCount;
		} else {
			count = e.touches.length;
		}

		if (count > 1) { return; }

		var now = Date.now(),
		    delta = now - (last || now);

		touch = e.touches ? e.touches[0] : e;
		doubleTap = (delta > 0 && delta <= delay);
		last = now;
	}

	function onTouchEnd(e) {
		if (doubleTap && !touch.cancelBubble) {
			if (pointer) {
				if ((!edge) || e.pointerType === 'mouse') { return; }
				// work around .type being readonly with MSPointer* events
				var newTouch = {},
				    prop, i;

				for (i in touch) {
					prop = touch[i];
					newTouch[i] = prop && prop.bind ? prop.bind(touch) : prop;
				}
				touch = newTouch;
			}
			touch.type = 'dblclick';
			touch.button = 0;
			handler(touch);
			last = null;
		}
	}

	obj[_pre + _touchstart + id] = onTouchStart;
	obj[_pre + _touchend + id] = onTouchEnd;
	obj[_pre + 'dblclick' + id] = handler;

	obj.addEventListener(_touchstart, onTouchStart, passiveEvents ? {passive: false} : false);
	obj.addEventListener(_touchend, onTouchEnd, passiveEvents ? {passive: false} : false);

	// On some platforms (notably, chrome<55 on win10 + touchscreen + mouse),
	// the browser doesn't fire touchend/pointerup events but does fire
	// native dblclicks. See #4127.
	// Edge 14 also fires native dblclicks, but only for pointerType mouse, see #5180.
	obj.addEventListener('dblclick', handler, false);

	return this;
}

function removeDoubleTapListener(obj, id) {
	var touchstart = obj[_pre + _touchstart + id],
	    touchend = obj[_pre + _touchend + id],
	    dblclick = obj[_pre + 'dblclick' + id];

	obj.removeEventListener(_touchstart, touchstart, passiveEvents ? {passive: false} : false);
	obj.removeEventListener(_touchend, touchend, passiveEvents ? {passive: false} : false);
	if (!edge) {
		obj.removeEventListener('dblclick', dblclick, false);
	}

	return this;
}

/*
 * @namespace DomUtil
 *
 * Utility functions to work with the [DOM](https://developer.mozilla.org/docs/Web/API/Document_Object_Model)
 * tree, used by Leaflet internally.
 *
 * Most functions expecting or returning a `HTMLElement` also work for
 * SVG elements. The only difference is that classes refer to CSS classes
 * in HTML and SVG classes in SVG.
 */


// @property TRANSFORM: String
// Vendor-prefixed transform style name (e.g. `'webkitTransform'` for WebKit).
var TRANSFORM = testProp(
	['transform', 'webkitTransform', 'OTransform', 'MozTransform', 'msTransform']);

// webkitTransition comes first because some browser versions that drop vendor prefix don't do
// the same for the transitionend event, in particular the Android 4.1 stock browser

// @property TRANSITION: String
// Vendor-prefixed transition style name.
var TRANSITION = testProp(
	['webkitTransition', 'transition', 'OTransition', 'MozTransition', 'msTransition']);

// @property TRANSITION_END: String
// Vendor-prefixed transitionend event name.
var TRANSITION_END =
	TRANSITION === 'webkitTransition' || TRANSITION === 'OTransition' ? TRANSITION + 'End' : 'transitionend';


// @function get(id: String|HTMLElement): HTMLElement
// Returns an element given its DOM id, or returns the element itself
// if it was passed directly.
function get(id) {
	return typeof id === 'string' ? document.getElementById(id) : id;
}

// @function getStyle(el: HTMLElement, styleAttrib: String): String
// Returns the value for a certain style attribute on an element,
// including computed values or values set through CSS.
function getStyle(el, style) {
	var value = el.style[style] || (el.currentStyle && el.currentStyle[style]);

	if ((!value || value === 'auto') && document.defaultView) {
		var css = document.defaultView.getComputedStyle(el, null);
		value = css ? css[style] : null;
	}
	return value === 'auto' ? null : value;
}

// @function create(tagName: String, className?: String, container?: HTMLElement): HTMLElement
// Creates an HTML element with `tagName`, sets its class to `className`, and optionally appends it to `container` element.
function create$1(tagName, className, container) {
	var el = document.createElement(tagName);
	el.className = className || '';

	if (container) {
		container.appendChild(el);
	}
	return el;
}

// @function remove(el: HTMLElement)
// Removes `el` from its parent element
function remove(el) {
	var parent = el.parentNode;
	if (parent) {
		parent.removeChild(el);
	}
}

// @function empty(el: HTMLElement)
// Removes all of `el`'s children elements from `el`
function empty(el) {
	while (el.firstChild) {
		el.removeChild(el.firstChild);
	}
}

// @function toFront(el: HTMLElement)
// Makes `el` the last child of its parent, so it renders in front of the other children.
function toFront(el) {
	var parent = el.parentNode;
	if (parent && parent.lastChild !== el) {
		parent.appendChild(el);
	}
}

// @function toBack(el: HTMLElement)
// Makes `el` the first child of its parent, so it renders behind the other children.
function toBack(el) {
	var parent = el.parentNode;
	if (parent && parent.firstChild !== el) {
		parent.insertBefore(el, parent.firstChild);
	}
}

// @function hasClass(el: HTMLElement, name: String): Boolean
// Returns `true` if the element's class attribute contains `name`.
function hasClass(el, name) {
	if (el.classList !== undefined) {
		return el.classList.contains(name);
	}
	var className = getClass(el);
	return className.length > 0 && new RegExp('(^|\\s)' + name + '(\\s|$)').test(className);
}

// @function addClass(el: HTMLElement, name: String)
// Adds `name` to the element's class attribute.
function addClass(el, name) {
	if (el.classList !== undefined) {
		var classes = splitWords(name);
		for (var i = 0, len = classes.length; i < len; i++) {
			el.classList.add(classes[i]);
		}
	} else if (!hasClass(el, name)) {
		var className = getClass(el);
		setClass(el, (className ? className + ' ' : '') + name);
	}
}

// @function removeClass(el: HTMLElement, name: String)
// Removes `name` from the element's class attribute.
function removeClass(el, name) {
	if (el.classList !== undefined) {
		el.classList.remove(name);
	} else {
		setClass(el, trim((' ' + getClass(el) + ' ').replace(' ' + name + ' ', ' ')));
	}
}

// @function setClass(el: HTMLElement, name: String)
// Sets the element's class.
function setClass(el, name) {
	if (el.className.baseVal === undefined) {
		el.className = name;
	} else {
		// in case of SVG element
		el.className.baseVal = name;
	}
}

// @function getClass(el: HTMLElement): String
// Returns the element's class.
function getClass(el) {
	// Check if the element is an SVGElementInstance and use the correspondingElement instead
	// (Required for linked SVG elements in IE11.)
	if (el.correspondingElement) {
		el = el.correspondingElement;
	}
	return el.className.baseVal === undefined ? el.className : el.className.baseVal;
}

// @function setOpacity(el: HTMLElement, opacity: Number)
// Set the opacity of an element (including old IE support).
// `opacity` must be a number from `0` to `1`.
function setOpacity(el, value) {
	if ('opacity' in el.style) {
		el.style.opacity = value;
	} else if ('filter' in el.style) {
		_setOpacityIE(el, value);
	}
}

function _setOpacityIE(el, value) {
	var filter = false,
	    filterName = 'DXImageTransform.Microsoft.Alpha';

	// filters collection throws an error if we try to retrieve a filter that doesn't exist
	try {
		filter = el.filters.item(filterName);
	} catch (e) {
		// don't set opacity to 1 if we haven't already set an opacity,
		// it isn't needed and breaks transparent pngs.
		if (value === 1) { return; }
	}

	value = Math.round(value * 100);

	if (filter) {
		filter.Enabled = (value !== 100);
		filter.Opacity = value;
	} else {
		el.style.filter += ' progid:' + filterName + '(opacity=' + value + ')';
	}
}

// @function testProp(props: String[]): String|false
// Goes through the array of style names and returns the first name
// that is a valid style name for an element. If no such name is found,
// it returns false. Useful for vendor-prefixed styles like `transform`.
function testProp(props) {
	var style = document.documentElement.style;

	for (var i = 0; i < props.length; i++) {
		if (props[i] in style) {
			return props[i];
		}
	}
	return false;
}

// @function setTransform(el: HTMLElement, offset: Point, scale?: Number)
// Resets the 3D CSS transform of `el` so it is translated by `offset` pixels
// and optionally scaled by `scale`. Does not have an effect if the
// browser doesn't support 3D CSS transforms.
function setTransform(el, offset, scale) {
	var pos = offset || new Point(0, 0);

	el.style[TRANSFORM] =
		(ie3d ?
			'translate(' + pos.x + 'px,' + pos.y + 'px)' :
			'translate3d(' + pos.x + 'px,' + pos.y + 'px,0)') +
		(scale ? ' scale(' + scale + ')' : '');
}

// @function setPosition(el: HTMLElement, position: Point)
// Sets the position of `el` to coordinates specified by `position`,
// using CSS translate or top/left positioning depending on the browser
// (used by Leaflet internally to position its layers).
function setPosition(el, point) {

	/*eslint-disable */
	el._leaflet_pos = point;
	/* eslint-enable */

	if (any3d) {
		setTransform(el, point);
	} else {
		el.style.left = point.x + 'px';
		el.style.top = point.y + 'px';
	}
}

// @function getPosition(el: HTMLElement): Point
// Returns the coordinates of an element previously positioned with setPosition.
function getPosition(el) {
	// this method is only used for elements previously positioned using setPosition,
	// so it's safe to cache the position for performance

	return el._leaflet_pos || new Point(0, 0);
}

// @function disableTextSelection()
// Prevents the user from generating `selectstart` DOM events, usually generated
// when the user drags the mouse through a page with text. Used internally
// by Leaflet to override the behaviour of any click-and-drag interaction on
// the map. Affects drag interactions on the whole document.

// @function enableTextSelection()
// Cancels the effects of a previous [`L.DomUtil.disableTextSelection`](#domutil-disabletextselection).
var disableTextSelection;
var enableTextSelection;
var _userSelect;
if ('onselectstart' in document) {
	disableTextSelection = function () {
		on(window, 'selectstart', preventDefault);
	};
	enableTextSelection = function () {
		off(window, 'selectstart', preventDefault);
	};
} else {
	var userSelectProperty = testProp(
		['userSelect', 'WebkitUserSelect', 'OUserSelect', 'MozUserSelect', 'msUserSelect']);

	disableTextSelection = function () {
		if (userSelectProperty) {
			var style = document.documentElement.style;
			_userSelect = style[userSelectProperty];
			style[userSelectProperty] = 'none';
		}
	};
	enableTextSelection = function () {
		if (userSelectProperty) {
			document.documentElement.style[userSelectProperty] = _userSelect;
			_userSelect = undefined;
		}
	};
}

// @function disableImageDrag()
// As [`L.DomUtil.disableTextSelection`](#domutil-disabletextselection), but
// for `dragstart` DOM events, usually generated when the user drags an image.
function disableImageDrag() {
	on(window, 'dragstart', preventDefault);
}

// @function enableImageDrag()
// Cancels the effects of a previous [`L.DomUtil.disableImageDrag`](#domutil-disabletextselection).
function enableImageDrag() {
	off(window, 'dragstart', preventDefault);
}

var _outlineElement, _outlineStyle;
// @function preventOutline(el: HTMLElement)
// Makes the [outline](https://developer.mozilla.org/docs/Web/CSS/outline)
// of the element `el` invisible. Used internally by Leaflet to prevent
// focusable elements from displaying an outline when the user performs a
// drag interaction on them.
function preventOutline(element) {
	while (element.tabIndex === -1) {
		element = element.parentNode;
	}
	if (!element.style) { return; }
	restoreOutline();
	_outlineElement = element;
	_outlineStyle = element.style.outline;
	element.style.outline = 'none';
	on(window, 'keydown', restoreOutline);
}

// @function restoreOutline()
// Cancels the effects of a previous [`L.DomUtil.preventOutline`]().
function restoreOutline() {
	if (!_outlineElement) { return; }
	_outlineElement.style.outline = _outlineStyle;
	_outlineElement = undefined;
	_outlineStyle = undefined;
	off(window, 'keydown', restoreOutline);
}

// @function getSizedParentNode(el: HTMLElement): HTMLElement
// Finds the closest parent node which size (width and height) is not null.
function getSizedParentNode(element) {
	do {
		element = element.parentNode;
	} while ((!element.offsetWidth || !element.offsetHeight) && element !== document.body);
	return element;
}

// @function getScale(el: HTMLElement): Object
// Computes the CSS scale currently applied on the element.
// Returns an object with `x` and `y` members as horizontal and vertical scales respectively,
// and `boundingClientRect` as the result of [`getBoundingClientRect()`](https://developer.mozilla.org/en-US/docs/Web/API/Element/getBoundingClientRect).
function getScale(element) {
	var rect = element.getBoundingClientRect(); // Read-only in old browsers.

	return {
		x: rect.width / element.offsetWidth || 1,
		y: rect.height / element.offsetHeight || 1,
		boundingClientRect: rect
	};
}

/*
 * @namespace DomEvent
 * Utility functions to work with the [DOM events](https://developer.mozilla.org/docs/Web/API/Event), used by Leaflet internally.
 */

// Inspired by John Resig, Dean Edwards and YUI addEvent implementations.

// @function on(el: HTMLElement, types: String, fn: Function, context?: Object): this
// Adds a listener function (`fn`) to a particular DOM event type of the
// element `el`. You can optionally specify the context of the listener
// (object the `this` keyword will point to). You can also pass several
// space-separated types (e.g. `'click dblclick'`).

// @alternative
// @function on(el: HTMLElement, eventMap: Object, context?: Object): this
// Adds a set of type/listener pairs, e.g. `{click: onClick, mousemove: onMouseMove}`
function on(obj, types, fn, context) {

	if (typeof types === 'object') {
		for (var type in types) {
			addOne(obj, type, types[type], fn);
		}
	} else {
		types = splitWords(types);

		for (var i = 0, len = types.length; i < len; i++) {
			addOne(obj, types[i], fn, context);
		}
	}

	return this;
}

var eventsKey = '_leaflet_events';

// @function off(el: HTMLElement, types: String, fn: Function, context?: Object): this
// Removes a previously added listener function.
// Note that if you passed a custom context to on, you must pass the same
// context to `off` in order to remove the listener.

// @alternative
// @function off(el: HTMLElement, eventMap: Object, context?: Object): this
// Removes a set of type/listener pairs, e.g. `{click: onClick, mousemove: onMouseMove}`
function off(obj, types, fn, context) {

	if (typeof types === 'object') {
		for (var type in types) {
			removeOne(obj, type, types[type], fn);
		}
	} else if (types) {
		types = splitWords(types);

		for (var i = 0, len = types.length; i < len; i++) {
			removeOne(obj, types[i], fn, context);
		}
	} else {
		for (var j in obj[eventsKey]) {
			removeOne(obj, j, obj[eventsKey][j]);
		}
		delete obj[eventsKey];
	}

	return this;
}

function addOne(obj, type, fn, context) {
	var id = type + stamp$1(fn) + (context ? '_' + stamp$1(context) : '');

	if (obj[eventsKey] && obj[eventsKey][id]) { return this; }

	var handler = function (e) {
		return fn.call(context || obj, e || window.event);
	};

	var originalHandler = handler;

	if (pointer && type.indexOf('touch') === 0) {
		// Needs DomEvent.Pointer.js
		addPointerListener(obj, type, handler, id);

	} else if (touch && (type === 'dblclick') && addDoubleTapListener &&
	           !(pointer && chrome)) {
		// Chrome >55 does not need the synthetic dblclicks from addDoubleTapListener
		// See #5180
		addDoubleTapListener(obj, handler, id);

	} else if ('addEventListener' in obj) {

		if (type === 'mousewheel') {
			obj.addEventListener('onwheel' in obj ? 'wheel' : 'mousewheel', handler, passiveEvents ? {passive: false} : false);

		} else if ((type === 'mouseenter') || (type === 'mouseleave')) {
			handler = function (e) {
				e = e || window.event;
				if (isExternalTarget(obj, e)) {
					originalHandler(e);
				}
			};
			obj.addEventListener(type === 'mouseenter' ? 'mouseover' : 'mouseout', handler, false);

		} else {
			if (type === 'click' && android) {
				handler = function (e) {
					filterClick(e, originalHandler);
				};
			}
			obj.addEventListener(type, handler, false);
		}

	} else if ('attachEvent' in obj) {
		obj.attachEvent('on' + type, handler);
	}

	obj[eventsKey] = obj[eventsKey] || {};
	obj[eventsKey][id] = handler;
}

function removeOne(obj, type, fn, context) {

	var id = type + stamp$1(fn) + (context ? '_' + stamp$1(context) : ''),
	    handler = obj[eventsKey] && obj[eventsKey][id];

	if (!handler) { return this; }

	if (pointer && type.indexOf('touch') === 0) {
		removePointerListener(obj, type, id);

	} else if (touch && (type === 'dblclick') && removeDoubleTapListener &&
	           !(pointer && chrome)) {
		removeDoubleTapListener(obj, id);

	} else if ('removeEventListener' in obj) {

		if (type === 'mousewheel') {
			obj.removeEventListener('onwheel' in obj ? 'wheel' : 'mousewheel', handler, passiveEvents ? {passive: false} : false);

		} else {
			obj.removeEventListener(
				type === 'mouseenter' ? 'mouseover' :
				type === 'mouseleave' ? 'mouseout' : type, handler, false);
		}

	} else if ('detachEvent' in obj) {
		obj.detachEvent('on' + type, handler);
	}

	obj[eventsKey][id] = null;
}

// @function stopPropagation(ev: DOMEvent): this
// Stop the given event from propagation to parent elements. Used inside the listener functions:
// ```js
// L.DomEvent.on(div, 'click', function (ev) {
// 	L.DomEvent.stopPropagation(ev);
// });
// ```
function stopPropagation(e) {

	if (e.stopPropagation) {
		e.stopPropagation();
	} else if (e.originalEvent) {  // In case of Leaflet event.
		e.originalEvent._stopped = true;
	} else {
		e.cancelBubble = true;
	}
	skipped(e);

	return this;
}

// @function disableScrollPropagation(el: HTMLElement): this
// Adds `stopPropagation` to the element's `'mousewheel'` events (plus browser variants).
function disableScrollPropagation(el) {
	addOne(el, 'mousewheel', stopPropagation);
	return this;
}

// @function disableClickPropagation(el: HTMLElement): this
// Adds `stopPropagation` to the element's `'click'`, `'doubleclick'`,
// `'mousedown'` and `'touchstart'` events (plus browser variants).
function disableClickPropagation(el) {
	on(el, 'mousedown touchstart dblclick', stopPropagation);
	addOne(el, 'click', fakeStop);
	return this;
}

// @function preventDefault(ev: DOMEvent): this
// Prevents the default action of the DOM Event `ev` from happening (such as
// following a link in the href of the a element, or doing a POST request
// with page reload when a `<form>` is submitted).
// Use it inside listener functions.
function preventDefault(e) {
	if (e.preventDefault) {
		e.preventDefault();
	} else {
		e.returnValue = false;
	}
	return this;
}

// @function stop(ev: DOMEvent): this
// Does `stopPropagation` and `preventDefault` at the same time.
function stop(e) {
	preventDefault(e);
	stopPropagation(e);
	return this;
}

// @function getMousePosition(ev: DOMEvent, container?: HTMLElement): Point
// Gets normalized mouse position from a DOM event relative to the
// `container` (border excluded) or to the whole page if not specified.
function getMousePosition(e, container) {
	if (!container) {
		return new Point(e.clientX, e.clientY);
	}

	var scale = getScale(container),
	    offset = scale.boundingClientRect; // left and top  values are in page scale (like the event clientX/Y)

	return new Point(
		// offset.left/top values are in page scale (like clientX/Y),
		// whereas clientLeft/Top (border width) values are the original values (before CSS scale applies).
		(e.clientX - offset.left) / scale.x - container.clientLeft,
		(e.clientY - offset.top) / scale.y - container.clientTop
	);
}

// Chrome on Win scrolls double the pixels as in other platforms (see #4538),
// and Firefox scrolls device pixels, not CSS pixels
var wheelPxFactor =
	(win && chrome) ? 2 * window.devicePixelRatio :
	gecko ? window.devicePixelRatio : 1;

// @function getWheelDelta(ev: DOMEvent): Number
// Gets normalized wheel delta from a mousewheel DOM event, in vertical
// pixels scrolled (negative if scrolling down).
// Events from pointing devices without precise scrolling are mapped to
// a best guess of 60 pixels.
function getWheelDelta(e) {
	return (edge) ? e.wheelDeltaY / 2 : // Don't trust window-geometry-based delta
	       (e.deltaY && e.deltaMode === 0) ? -e.deltaY / wheelPxFactor : // Pixels
	       (e.deltaY && e.deltaMode === 1) ? -e.deltaY * 20 : // Lines
	       (e.deltaY && e.deltaMode === 2) ? -e.deltaY * 60 : // Pages
	       (e.deltaX || e.deltaZ) ? 0 :	// Skip horizontal/depth wheel events
	       e.wheelDelta ? (e.wheelDeltaY || e.wheelDelta) / 2 : // Legacy IE pixels
	       (e.detail && Math.abs(e.detail) < 32765) ? -e.detail * 20 : // Legacy Moz lines
	       e.detail ? e.detail / -32765 * 60 : // Legacy Moz pages
	       0;
}

var skipEvents = {};

function fakeStop(e) {
	// fakes stopPropagation by setting a special event flag, checked/reset with skipped(e)
	skipEvents[e.type] = true;
}

function skipped(e) {
	var events = skipEvents[e.type];
	// reset when checking, as it's only used in map container and propagates outside of the map
	skipEvents[e.type] = false;
	return events;
}

// check if element really left/entered the event target (for mouseenter/mouseleave)
function isExternalTarget(el, e) {

	var related = e.relatedTarget;

	if (!related) { return true; }

	try {
		while (related && (related !== el)) {
			related = related.parentNode;
		}
	} catch (err) {
		return false;
	}
	return (related !== el);
}

var lastClick;

// this is a horrible workaround for a bug in Android where a single touch triggers two click events
function filterClick(e, handler) {
	var timeStamp = (e.timeStamp || (e.originalEvent && e.originalEvent.timeStamp)),
	    elapsed = lastClick && (timeStamp - lastClick);

	// are they closer together than 500ms yet more than 100ms?
	// Android typically triggers them ~300ms apart while multiple listeners
	// on the same event should be triggered far faster;
	// or check if click is simulated on the element, and if it is, reject any non-simulated events

	if ((elapsed && elapsed > 100 && elapsed < 500) || (e.target._simulatedClick && !e._simulated)) {
		stop(e);
		return;
	}
	lastClick = timeStamp;

	handler(e);
}

/*
 * @class PosAnimation
 * @aka L.PosAnimation
 * @inherits Evented
 * Used internally for panning animations, utilizing CSS3 Transitions for modern browsers and a timer fallback for IE6-9.
 *
 * @example
 * ```js
 * var fx = new L.PosAnimation();
 * fx.run(el, [300, 500], 0.5);
 * ```
 *
 * @constructor L.PosAnimation()
 * Creates a `PosAnimation` object.
 *
 */

var PosAnimation = Evented.extend({

	// @method run(el: HTMLElement, newPos: Point, duration?: Number, easeLinearity?: Number)
	// Run an animation of a given element to a new position, optionally setting
	// duration in seconds (`0.25` by default) and easing linearity factor (3rd
	// argument of the [cubic bezier curve](http://cubic-bezier.com/#0,0,.5,1),
	// `0.5` by default).
	run: function (el, newPos, duration, easeLinearity) {
		this.stop();

		this._el = el;
		this._inProgress = true;
		this._duration = duration || 0.25;
		this._easeOutPower = 1 / Math.max(easeLinearity || 0.5, 0.2);

		this._startPos = getPosition(el);
		this._offset = newPos.subtract(this._startPos);
		this._startTime = +new Date();

		// @event start: Event
		// Fired when the animation starts
		this.fire('start');

		this._animate();
	},

	// @method stop()
	// Stops the animation (if currently running).
	stop: function () {
		if (!this._inProgress) { return; }

		this._step(true);
		this._complete();
	},

	_animate: function () {
		// animation loop
		this._animId = requestAnimFrame(this._animate, this);
		this._step();
	},

	_step: function (round) {
		var elapsed = (+new Date()) - this._startTime,
		    duration = this._duration * 1000;

		if (elapsed < duration) {
			this._runFrame(this._easeOut(elapsed / duration), round);
		} else {
			this._runFrame(1);
			this._complete();
		}
	},

	_runFrame: function (progress, round) {
		var pos = this._startPos.add(this._offset.multiplyBy(progress));
		if (round) {
			pos._round();
		}
		setPosition(this._el, pos);

		// @event step: Event
		// Fired continuously during the animation.
		this.fire('step');
	},

	_complete: function () {
		cancelAnimFrame(this._animId);

		this._inProgress = false;
		// @event end: Event
		// Fired when the animation ends.
		this.fire('end');
	},

	_easeOut: function (t) {
		return 1 - Math.pow(1 - t, this._easeOutPower);
	}
});

/*
 * @class Map
 * @aka L.Map
 * @inherits Evented
 *
 * The central class of the API — it is used to create a map on a page and manipulate it.
 *
 * @example
 *
 * ```js
 * // initialize the map on the "map" div with a given center and zoom
 * var map = L.map('map', {
 * 	center: [51.505, -0.09],
 * 	zoom: 13
 * });
 * ```
 *
 */

var Map$1 = Evented.extend({

	options: {
		// @section Map State Options
		// @option crs: CRS = L.CRS.EPSG3857
		// The [Coordinate Reference System](#crs) to use. Don't change this if you're not
		// sure what it means.
		crs: EPSG3857,

		// @option center: LatLng = undefined
		// Initial geographic center of the map
		center: undefined,

		// @option zoom: Number = undefined
		// Initial map zoom level
		zoom: undefined,

		// @option minZoom: Number = *
		// Minimum zoom level of the map.
		// If not specified and at least one `GridLayer` or `TileLayer` is in the map,
		// the lowest of their `minZoom` options will be used instead.
		minZoom: undefined,

		// @option maxZoom: Number = *
		// Maximum zoom level of the map.
		// If not specified and at least one `GridLayer` or `TileLayer` is in the map,
		// the highest of their `maxZoom` options will be used instead.
		maxZoom: undefined,

		// @option layers: Layer[] = []
		// Array of layers that will be added to the map initially
		layers: [],

		// @option maxBounds: LatLngBounds = null
		// When this option is set, the map restricts the view to the given
		// geographical bounds, bouncing the user back if the user tries to pan
		// outside the view. To set the restriction dynamically, use
		// [`setMaxBounds`](#map-setmaxbounds) method.
		maxBounds: undefined,

		// @option renderer: Renderer = *
		// The default method for drawing vector layers on the map. `L.SVG`
		// or `L.Canvas` by default depending on browser support.
		renderer: undefined,


		// @section Animation Options
		// @option zoomAnimation: Boolean = true
		// Whether the map zoom animation is enabled. By default it's enabled
		// in all browsers that support CSS3 Transitions except Android.
		zoomAnimation: true,

		// @option zoomAnimationThreshold: Number = 4
		// Won't animate zoom if the zoom difference exceeds this value.
		zoomAnimationThreshold: 4,

		// @option fadeAnimation: Boolean = true
		// Whether the tile fade animation is enabled. By default it's enabled
		// in all browsers that support CSS3 Transitions except Android.
		fadeAnimation: true,

		// @option markerZoomAnimation: Boolean = true
		// Whether markers animate their zoom with the zoom animation, if disabled
		// they will disappear for the length of the animation. By default it's
		// enabled in all browsers that support CSS3 Transitions except Android.
		markerZoomAnimation: true,

		// @option transform3DLimit: Number = 2^23
		// Defines the maximum size of a CSS translation transform. The default
		// value should not be changed unless a web browser positions layers in
		// the wrong place after doing a large `panBy`.
		transform3DLimit: 8388608, // Precision limit of a 32-bit float

		// @section Interaction Options
		// @option zoomSnap: Number = 1
		// Forces the map's zoom level to always be a multiple of this, particularly
		// right after a [`fitBounds()`](#map-fitbounds) or a pinch-zoom.
		// By default, the zoom level snaps to the nearest integer; lower values
		// (e.g. `0.5` or `0.1`) allow for greater granularity. A value of `0`
		// means the zoom level will not be snapped after `fitBounds` or a pinch-zoom.
		zoomSnap: 1,

		// @option zoomDelta: Number = 1
		// Controls how much the map's zoom level will change after a
		// [`zoomIn()`](#map-zoomin), [`zoomOut()`](#map-zoomout), pressing `+`
		// or `-` on the keyboard, or using the [zoom controls](#control-zoom).
		// Values smaller than `1` (e.g. `0.5`) allow for greater granularity.
		zoomDelta: 1,

		// @option trackResize: Boolean = true
		// Whether the map automatically handles browser window resize to update itself.
		trackResize: true
	},

	initialize: function (id, options) { // (HTMLElement or String, Object)
		options = setOptions$1(this, options);

		// Make sure to assign internal flags at the beginning,
		// to avoid inconsistent state in some edge cases.
		this._handlers = [];
		this._layers = {};
		this._zoomBoundLayers = {};
		this._sizeChanged = true;

		this._initContainer(id);
		this._initLayout();

		// hack for https://github.com/Leaflet/Leaflet/issues/1980
		this._onResize = bind(this._onResize, this);

		this._initEvents();

		if (options.maxBounds) {
			this.setMaxBounds(options.maxBounds);
		}

		if (options.zoom !== undefined) {
			this._zoom = this._limitZoom(options.zoom);
		}

		if (options.center && options.zoom !== undefined) {
			this.setView(toLatLng(options.center), options.zoom, {reset: true});
		}

		this.callInitHooks();

		// don't animate on browsers without hardware-accelerated transitions or old Android/Opera
		this._zoomAnimated = TRANSITION && any3d && !mobileOpera &&
				this.options.zoomAnimation;

		// zoom transitions run with the same duration for all layers, so if one of transitionend events
		// happens after starting zoom animation (propagating to the map pane), we know that it ended globally
		if (this._zoomAnimated) {
			this._createAnimProxy();
			on(this._proxy, TRANSITION_END, this._catchTransitionEnd, this);
		}

		this._addLayers(this.options.layers);
	},


	// @section Methods for modifying map state

	// @method setView(center: LatLng, zoom: Number, options?: Zoom/pan options): this
	// Sets the view of the map (geographical center and zoom) with the given
	// animation options.
	setView: function (center, zoom, options) {

		zoom = zoom === undefined ? this._zoom : this._limitZoom(zoom);
		center = this._limitCenter(toLatLng(center), zoom, this.options.maxBounds);
		options = options || {};

		this._stop();

		if (this._loaded && !options.reset && options !== true) {

			if (options.animate !== undefined) {
				options.zoom = extend({animate: options.animate}, options.zoom);
				options.pan = extend({animate: options.animate, duration: options.duration}, options.pan);
			}

			// try animating pan or zoom
			var moved = (this._zoom !== zoom) ?
				this._tryAnimatedZoom && this._tryAnimatedZoom(center, zoom, options.zoom) :
				this._tryAnimatedPan(center, options.pan);

			if (moved) {
				// prevent resize handler call, the view will refresh after animation anyway
				clearTimeout(this._sizeTimer);
				return this;
			}
		}

		// animation didn't start, just reset the map view
		this._resetView(center, zoom);

		return this;
	},

	// @method setZoom(zoom: Number, options?: Zoom/pan options): this
	// Sets the zoom of the map.
	setZoom: function (zoom, options) {
		if (!this._loaded) {
			this._zoom = zoom;
			return this;
		}
		return this.setView(this.getCenter(), zoom, {zoom: options});
	},

	// @method zoomIn(delta?: Number, options?: Zoom options): this
	// Increases the zoom of the map by `delta` ([`zoomDelta`](#map-zoomdelta) by default).
	zoomIn: function (delta, options) {
		delta = delta || (any3d ? this.options.zoomDelta : 1);
		return this.setZoom(this._zoom + delta, options);
	},

	// @method zoomOut(delta?: Number, options?: Zoom options): this
	// Decreases the zoom of the map by `delta` ([`zoomDelta`](#map-zoomdelta) by default).
	zoomOut: function (delta, options) {
		delta = delta || (any3d ? this.options.zoomDelta : 1);
		return this.setZoom(this._zoom - delta, options);
	},

	// @method setZoomAround(latlng: LatLng, zoom: Number, options: Zoom options): this
	// Zooms the map while keeping a specified geographical point on the map
	// stationary (e.g. used internally for scroll zoom and double-click zoom).
	// @alternative
	// @method setZoomAround(offset: Point, zoom: Number, options: Zoom options): this
	// Zooms the map while keeping a specified pixel on the map (relative to the top-left corner) stationary.
	setZoomAround: function (latlng, zoom, options) {
		var scale = this.getZoomScale(zoom),
		    viewHalf = this.getSize().divideBy(2),
		    containerPoint = latlng instanceof Point ? latlng : this.latLngToContainerPoint(latlng),

		    centerOffset = containerPoint.subtract(viewHalf).multiplyBy(1 - 1 / scale),
		    newCenter = this.containerPointToLatLng(viewHalf.add(centerOffset));

		return this.setView(newCenter, zoom, {zoom: options});
	},

	_getBoundsCenterZoom: function (bounds, options) {

		options = options || {};
		bounds = bounds.getBounds ? bounds.getBounds() : toLatLngBounds(bounds);

		var paddingTL = toPoint(options.paddingTopLeft || options.padding || [0, 0]),
		    paddingBR = toPoint(options.paddingBottomRight || options.padding || [0, 0]),

		    zoom = this.getBoundsZoom(bounds, false, paddingTL.add(paddingBR));

		zoom = (typeof options.maxZoom === 'number') ? Math.min(options.maxZoom, zoom) : zoom;

		if (zoom === Infinity) {
			return {
				center: bounds.getCenter(),
				zoom: zoom
			};
		}

		var paddingOffset = paddingBR.subtract(paddingTL).divideBy(2),

		    swPoint = this.project(bounds.getSouthWest(), zoom),
		    nePoint = this.project(bounds.getNorthEast(), zoom),
		    center = this.unproject(swPoint.add(nePoint).divideBy(2).add(paddingOffset), zoom);

		return {
			center: center,
			zoom: zoom
		};
	},

	// @method fitBounds(bounds: LatLngBounds, options?: fitBounds options): this
	// Sets a map view that contains the given geographical bounds with the
	// maximum zoom level possible.
	fitBounds: function (bounds, options) {

		bounds = toLatLngBounds(bounds);

		if (!bounds.isValid()) {
			throw new Error('Bounds are not valid.');
		}

		var target = this._getBoundsCenterZoom(bounds, options);
		return this.setView(target.center, target.zoom, options);
	},

	// @method fitWorld(options?: fitBounds options): this
	// Sets a map view that mostly contains the whole world with the maximum
	// zoom level possible.
	fitWorld: function (options) {
		return this.fitBounds([[-90, -180], [90, 180]], options);
	},

	// @method panTo(latlng: LatLng, options?: Pan options): this
	// Pans the map to a given center.
	panTo: function (center, options) { // (LatLng)
		return this.setView(center, this._zoom, {pan: options});
	},

	// @method panBy(offset: Point, options?: Pan options): this
	// Pans the map by a given number of pixels (animated).
	panBy: function (offset, options) {
		offset = toPoint(offset).round();
		options = options || {};

		if (!offset.x && !offset.y) {
			return this.fire('moveend');
		}
		// If we pan too far, Chrome gets issues with tiles
		// and makes them disappear or appear in the wrong place (slightly offset) #2602
		if (options.animate !== true && !this.getSize().contains(offset)) {
			this._resetView(this.unproject(this.project(this.getCenter()).add(offset)), this.getZoom());
			return this;
		}

		if (!this._panAnim) {
			this._panAnim = new PosAnimation();

			this._panAnim.on({
				'step': this._onPanTransitionStep,
				'end': this._onPanTransitionEnd
			}, this);
		}

		// don't fire movestart if animating inertia
		if (!options.noMoveStart) {
			this.fire('movestart');
		}

		// animate pan unless animate: false specified
		if (options.animate !== false) {
			addClass(this._mapPane, 'leaflet-pan-anim');

			var newPos = this._getMapPanePos().subtract(offset).round();
			this._panAnim.run(this._mapPane, newPos, options.duration || 0.25, options.easeLinearity);
		} else {
			this._rawPanBy(offset);
			this.fire('move').fire('moveend');
		}

		return this;
	},

	// @method flyTo(latlng: LatLng, zoom?: Number, options?: Zoom/pan options): this
	// Sets the view of the map (geographical center and zoom) performing a smooth
	// pan-zoom animation.
	flyTo: function (targetCenter, targetZoom, options) {

		options = options || {};
		if (options.animate === false || !any3d) {
			return this.setView(targetCenter, targetZoom, options);
		}

		this._stop();

		var from = this.project(this.getCenter()),
		    to = this.project(targetCenter),
		    size = this.getSize(),
		    startZoom = this._zoom;

		targetCenter = toLatLng(targetCenter);
		targetZoom = targetZoom === undefined ? startZoom : targetZoom;

		var w0 = Math.max(size.x, size.y),
		    w1 = w0 * this.getZoomScale(startZoom, targetZoom),
		    u1 = (to.distanceTo(from)) || 1,
		    rho = 1.42,
		    rho2 = rho * rho;

		function r(i) {
			var s1 = i ? -1 : 1,
			    s2 = i ? w1 : w0,
			    t1 = w1 * w1 - w0 * w0 + s1 * rho2 * rho2 * u1 * u1,
			    b1 = 2 * s2 * rho2 * u1,
			    b = t1 / b1,
			    sq = Math.sqrt(b * b + 1) - b;

			    // workaround for floating point precision bug when sq = 0, log = -Infinite,
			    // thus triggering an infinite loop in flyTo
			    var log = sq < 0.000000001 ? -18 : Math.log(sq);

			return log;
		}

		function sinh(n) { return (Math.exp(n) - Math.exp(-n)) / 2; }
		function cosh(n) { return (Math.exp(n) + Math.exp(-n)) / 2; }
		function tanh(n) { return sinh(n) / cosh(n); }

		var r0 = r(0);

		function w(s) { return w0 * (cosh(r0) / cosh(r0 + rho * s)); }
		function u(s) { return w0 * (cosh(r0) * tanh(r0 + rho * s) - sinh(r0)) / rho2; }

		function easeOut(t) { return 1 - Math.pow(1 - t, 1.5); }

		var start = Date.now(),
		    S = (r(1) - r0) / rho,
		    duration = options.duration ? 1000 * options.duration : 1000 * S * 0.8;

		function frame() {
			var t = (Date.now() - start) / duration,
			    s = easeOut(t) * S;

			if (t <= 1) {
				this._flyToFrame = requestAnimFrame(frame, this);

				this._move(
					this.unproject(from.add(to.subtract(from).multiplyBy(u(s) / u1)), startZoom),
					this.getScaleZoom(w0 / w(s), startZoom),
					{flyTo: true});

			} else {
				this
					._move(targetCenter, targetZoom)
					._moveEnd(true);
			}
		}

		this._moveStart(true, options.noMoveStart);

		frame.call(this);
		return this;
	},

	// @method flyToBounds(bounds: LatLngBounds, options?: fitBounds options): this
	// Sets the view of the map with a smooth animation like [`flyTo`](#map-flyto),
	// but takes a bounds parameter like [`fitBounds`](#map-fitbounds).
	flyToBounds: function (bounds, options) {
		var target = this._getBoundsCenterZoom(bounds, options);
		return this.flyTo(target.center, target.zoom, options);
	},

	// @method setMaxBounds(bounds: Bounds): this
	// Restricts the map view to the given bounds (see the [maxBounds](#map-maxbounds) option).
	setMaxBounds: function (bounds) {
		bounds = toLatLngBounds(bounds);

		if (!bounds.isValid()) {
			this.options.maxBounds = null;
			return this.off('moveend', this._panInsideMaxBounds);
		} else if (this.options.maxBounds) {
			this.off('moveend', this._panInsideMaxBounds);
		}

		this.options.maxBounds = bounds;

		if (this._loaded) {
			this._panInsideMaxBounds();
		}

		return this.on('moveend', this._panInsideMaxBounds);
	},

	// @method setMinZoom(zoom: Number): this
	// Sets the lower limit for the available zoom levels (see the [minZoom](#map-minzoom) option).
	setMinZoom: function (zoom) {
		var oldZoom = this.options.minZoom;
		this.options.minZoom = zoom;

		if (this._loaded && oldZoom !== zoom) {
			this.fire('zoomlevelschange');

			if (this.getZoom() < this.options.minZoom) {
				return this.setZoom(zoom);
			}
		}

		return this;
	},

	// @method setMaxZoom(zoom: Number): this
	// Sets the upper limit for the available zoom levels (see the [maxZoom](#map-maxzoom) option).
	setMaxZoom: function (zoom) {
		var oldZoom = this.options.maxZoom;
		this.options.maxZoom = zoom;

		if (this._loaded && oldZoom !== zoom) {
			this.fire('zoomlevelschange');

			if (this.getZoom() > this.options.maxZoom) {
				return this.setZoom(zoom);
			}
		}

		return this;
	},

	// @method panInsideBounds(bounds: LatLngBounds, options?: Pan options): this
	// Pans the map to the closest view that would lie inside the given bounds (if it's not already), controlling the animation using the options specific, if any.
	panInsideBounds: function (bounds, options) {
		this._enforcingBounds = true;
		var center = this.getCenter(),
		    newCenter = this._limitCenter(center, this._zoom, toLatLngBounds(bounds));

		if (!center.equals(newCenter)) {
			this.panTo(newCenter, options);
		}

		this._enforcingBounds = false;
		return this;
	},

	// @method panInside(latlng: LatLng, options?: options): this
	// Pans the map the minimum amount to make the `latlng` visible. Use
	// `padding`, `paddingTopLeft` and `paddingTopRight` options to fit
	// the display to more restricted bounds, like [`fitBounds`](#map-fitbounds).
	// If `latlng` is already within the (optionally padded) display bounds,
	// the map will not be panned.
	panInside: function (latlng, options) {
		options = options || {};

		var paddingTL = toPoint(options.paddingTopLeft || options.padding || [0, 0]),
		    paddingBR = toPoint(options.paddingBottomRight || options.padding || [0, 0]),
		    center = this.getCenter(),
		    pixelCenter = this.project(center),
		    pixelPoint = this.project(latlng),
		    pixelBounds = this.getPixelBounds(),
		    halfPixelBounds = pixelBounds.getSize().divideBy(2),
		    paddedBounds = toBounds([pixelBounds.min.add(paddingTL), pixelBounds.max.subtract(paddingBR)]);

		if (!paddedBounds.contains(pixelPoint)) {
			this._enforcingBounds = true;
			var diff = pixelCenter.subtract(pixelPoint),
			    newCenter = toPoint(pixelPoint.x + diff.x, pixelPoint.y + diff.y);

			if (pixelPoint.x < paddedBounds.min.x || pixelPoint.x > paddedBounds.max.x) {
				newCenter.x = pixelCenter.x - diff.x;
				if (diff.x > 0) {
					newCenter.x += halfPixelBounds.x - paddingTL.x;
				} else {
					newCenter.x -= halfPixelBounds.x - paddingBR.x;
				}
			}
			if (pixelPoint.y < paddedBounds.min.y || pixelPoint.y > paddedBounds.max.y) {
				newCenter.y = pixelCenter.y - diff.y;
				if (diff.y > 0) {
					newCenter.y += halfPixelBounds.y - paddingTL.y;
				} else {
					newCenter.y -= halfPixelBounds.y - paddingBR.y;
				}
			}
			this.panTo(this.unproject(newCenter), options);
			this._enforcingBounds = false;
		}
		return this;
	},

	// @method invalidateSize(options: Zoom/pan options): this
	// Checks if the map container size changed and updates the map if so —
	// call it after you've changed the map size dynamically, also animating
	// pan by default. If `options.pan` is `false`, panning will not occur.
	// If `options.debounceMoveend` is `true`, it will delay `moveend` event so
	// that it doesn't happen often even if the method is called many
	// times in a row.

	// @alternative
	// @method invalidateSize(animate: Boolean): this
	// Checks if the map container size changed and updates the map if so —
	// call it after you've changed the map size dynamically, also animating
	// pan by default.
	invalidateSize: function (options) {
		if (!this._loaded) { return this; }

		options = extend({
			animate: false,
			pan: true
		}, options === true ? {animate: true} : options);

		var oldSize = this.getSize();
		this._sizeChanged = true;
		this._lastCenter = null;

		var newSize = this.getSize(),
		    oldCenter = oldSize.divideBy(2).round(),
		    newCenter = newSize.divideBy(2).round(),
		    offset = oldCenter.subtract(newCenter);

		if (!offset.x && !offset.y) { return this; }

		if (options.animate && options.pan) {
			this.panBy(offset);

		} else {
			if (options.pan) {
				this._rawPanBy(offset);
			}

			this.fire('move');

			if (options.debounceMoveend) {
				clearTimeout(this._sizeTimer);
				this._sizeTimer = setTimeout(bind(this.fire, this, 'moveend'), 200);
			} else {
				this.fire('moveend');
			}
		}

		// @section Map state change events
		// @event resize: ResizeEvent
		// Fired when the map is resized.
		return this.fire('resize', {
			oldSize: oldSize,
			newSize: newSize
		});
	},

	// @section Methods for modifying map state
	// @method stop(): this
	// Stops the currently running `panTo` or `flyTo` animation, if any.
	stop: function () {
		this.setZoom(this._limitZoom(this._zoom));
		if (!this.options.zoomSnap) {
			this.fire('viewreset');
		}
		return this._stop();
	},

	// @section Geolocation methods
	// @method locate(options?: Locate options): this
	// Tries to locate the user using the Geolocation API, firing a [`locationfound`](#map-locationfound)
	// event with location data on success or a [`locationerror`](#map-locationerror) event on failure,
	// and optionally sets the map view to the user's location with respect to
	// detection accuracy (or to the world view if geolocation failed).
	// Note that, if your page doesn't use HTTPS, this method will fail in
	// modern browsers ([Chrome 50 and newer](https://sites.google.com/a/chromium.org/dev/Home/chromium-security/deprecating-powerful-features-on-insecure-origins))
	// See `Locate options` for more details.
	locate: function (options) {

		options = this._locateOptions = extend({
			timeout: 10000,
			watch: false
			// setView: false
			// maxZoom: <Number>
			// maximumAge: 0
			// enableHighAccuracy: false
		}, options);

		if (!('geolocation' in navigator)) {
			this._handleGeolocationError({
				code: 0,
				message: 'Geolocation not supported.'
			});
			return this;
		}

		var onResponse = bind(this._handleGeolocationResponse, this),
		    onError = bind(this._handleGeolocationError, this);

		if (options.watch) {
			this._locationWatchId =
			        navigator.geolocation.watchPosition(onResponse, onError, options);
		} else {
			navigator.geolocation.getCurrentPosition(onResponse, onError, options);
		}
		return this;
	},

	// @method stopLocate(): this
	// Stops watching location previously initiated by `map.locate({watch: true})`
	// and aborts resetting the map view if map.locate was called with
	// `{setView: true}`.
	stopLocate: function () {
		if (navigator.geolocation && navigator.geolocation.clearWatch) {
			navigator.geolocation.clearWatch(this._locationWatchId);
		}
		if (this._locateOptions) {
			this._locateOptions.setView = false;
		}
		return this;
	},

	_handleGeolocationError: function (error) {
		var c = error.code,
		    message = error.message ||
		            (c === 1 ? 'permission denied' :
		            (c === 2 ? 'position unavailable' : 'timeout'));

		if (this._locateOptions.setView && !this._loaded) {
			this.fitWorld();
		}

		// @section Location events
		// @event locationerror: ErrorEvent
		// Fired when geolocation (using the [`locate`](#map-locate) method) failed.
		this.fire('locationerror', {
			code: c,
			message: 'Geolocation error: ' + message + '.'
		});
	},

	_handleGeolocationResponse: function (pos) {
		var lat = pos.coords.latitude,
		    lng = pos.coords.longitude,
		    latlng = new LatLng(lat, lng),
		    bounds = latlng.toBounds(pos.coords.accuracy * 2),
		    options = this._locateOptions;

		if (options.setView) {
			var zoom = this.getBoundsZoom(bounds);
			this.setView(latlng, options.maxZoom ? Math.min(zoom, options.maxZoom) : zoom);
		}

		var data = {
			latlng: latlng,
			bounds: bounds,
			timestamp: pos.timestamp
		};

		for (var i in pos.coords) {
			if (typeof pos.coords[i] === 'number') {
				data[i] = pos.coords[i];
			}
		}

		// @event locationfound: LocationEvent
		// Fired when geolocation (using the [`locate`](#map-locate) method)
		// went successfully.
		this.fire('locationfound', data);
	},

	// TODO Appropriate docs section?
	// @section Other Methods
	// @method addHandler(name: String, HandlerClass: Function): this
	// Adds a new `Handler` to the map, given its name and constructor function.
	addHandler: function (name, HandlerClass) {
		if (!HandlerClass) { return this; }

		var handler = this[name] = new HandlerClass(this);

		this._handlers.push(handler);

		if (this.options[name]) {
			handler.enable();
		}

		return this;
	},

	// @method remove(): this
	// Destroys the map and clears all related event listeners.
	remove: function () {

		this._initEvents(true);

		if (this._containerId !== this._container._leaflet_id) {
			throw new Error('Map container is being reused by another instance');
		}

		try {
			// throws error in IE6-8
			delete this._container._leaflet_id;
			delete this._containerId;
		} catch (e) {
			/*eslint-disable */
			this._container._leaflet_id = undefined;
			/* eslint-enable */
			this._containerId = undefined;
		}

		if (this._locationWatchId !== undefined) {
			this.stopLocate();
		}

		this._stop();

		remove(this._mapPane);

		if (this._clearControlPos) {
			this._clearControlPos();
		}
		if (this._resizeRequest) {
			cancelAnimFrame(this._resizeRequest);
			this._resizeRequest = null;
		}

		this._clearHandlers();

		if (this._loaded) {
			// @section Map state change events
			// @event unload: Event
			// Fired when the map is destroyed with [remove](#map-remove) method.
			this.fire('unload');
		}

		var i;
		for (i in this._layers) {
			this._layers[i].remove();
		}
		for (i in this._panes) {
			remove(this._panes[i]);
		}

		this._layers = [];
		this._panes = [];
		delete this._mapPane;
		delete this._renderer;

		return this;
	},

	// @section Other Methods
	// @method createPane(name: String, container?: HTMLElement): HTMLElement
	// Creates a new [map pane](#map-pane) with the given name if it doesn't exist already,
	// then returns it. The pane is created as a child of `container`, or
	// as a child of the main map pane if not set.
	createPane: function (name, container) {
		var className = 'leaflet-pane' + (name ? ' leaflet-' + name.replace('Pane', '') + '-pane' : ''),
		    pane = create$1('div', className, container || this._mapPane);

		if (name) {
			this._panes[name] = pane;
		}
		return pane;
	},

	// @section Methods for Getting Map State

	// @method getCenter(): LatLng
	// Returns the geographical center of the map view
	getCenter: function () {
		this._checkIfLoaded();

		if (this._lastCenter && !this._moved()) {
			return this._lastCenter;
		}
		return this.layerPointToLatLng(this._getCenterLayerPoint());
	},

	// @method getZoom(): Number
	// Returns the current zoom level of the map view
	getZoom: function () {
		return this._zoom;
	},

	// @method getBounds(): LatLngBounds
	// Returns the geographical bounds visible in the current map view
	getBounds: function () {
		var bounds = this.getPixelBounds(),
		    sw = this.unproject(bounds.getBottomLeft()),
		    ne = this.unproject(bounds.getTopRight());

		return new LatLngBounds(sw, ne);
	},

	// @method getMinZoom(): Number
	// Returns the minimum zoom level of the map (if set in the `minZoom` option of the map or of any layers), or `0` by default.
	getMinZoom: function () {
		return this.options.minZoom === undefined ? this._layersMinZoom || 0 : this.options.minZoom;
	},

	// @method getMaxZoom(): Number
	// Returns the maximum zoom level of the map (if set in the `maxZoom` option of the map or of any layers).
	getMaxZoom: function () {
		return this.options.maxZoom === undefined ?
			(this._layersMaxZoom === undefined ? Infinity : this._layersMaxZoom) :
			this.options.maxZoom;
	},

	// @method getBoundsZoom(bounds: LatLngBounds, inside?: Boolean, padding?: Point): Number
	// Returns the maximum zoom level on which the given bounds fit to the map
	// view in its entirety. If `inside` (optional) is set to `true`, the method
	// instead returns the minimum zoom level on which the map view fits into
	// the given bounds in its entirety.
	getBoundsZoom: function (bounds, inside, padding) { // (LatLngBounds[, Boolean, Point]) -> Number
		bounds = toLatLngBounds(bounds);
		padding = toPoint(padding || [0, 0]);

		var zoom = this.getZoom() || 0,
		    min = this.getMinZoom(),
		    max = this.getMaxZoom(),
		    nw = bounds.getNorthWest(),
		    se = bounds.getSouthEast(),
		    size = this.getSize().subtract(padding),
		    boundsSize = toBounds(this.project(se, zoom), this.project(nw, zoom)).getSize(),
		    snap = any3d ? this.options.zoomSnap : 1,
		    scalex = size.x / boundsSize.x,
		    scaley = size.y / boundsSize.y,
		    scale = inside ? Math.max(scalex, scaley) : Math.min(scalex, scaley);

		zoom = this.getScaleZoom(scale, zoom);

		if (snap) {
			zoom = Math.round(zoom / (snap / 100)) * (snap / 100); // don't jump if within 1% of a snap level
			zoom = inside ? Math.ceil(zoom / snap) * snap : Math.floor(zoom / snap) * snap;
		}

		return Math.max(min, Math.min(max, zoom));
	},

	// @method getSize(): Point
	// Returns the current size of the map container (in pixels).
	getSize: function () {
		if (!this._size || this._sizeChanged) {
			this._size = new Point(
				this._container.clientWidth || 0,
				this._container.clientHeight || 0);

			this._sizeChanged = false;
		}
		return this._size.clone();
	},

	// @method getPixelBounds(): Bounds
	// Returns the bounds of the current map view in projected pixel
	// coordinates (sometimes useful in layer and overlay implementations).
	getPixelBounds: function (center, zoom) {
		var topLeftPoint = this._getTopLeftPoint(center, zoom);
		return new Bounds(topLeftPoint, topLeftPoint.add(this.getSize()));
	},

	// TODO: Check semantics - isn't the pixel origin the 0,0 coord relative to
	// the map pane? "left point of the map layer" can be confusing, specially
	// since there can be negative offsets.
	// @method getPixelOrigin(): Point
	// Returns the projected pixel coordinates of the top left point of
	// the map layer (useful in custom layer and overlay implementations).
	getPixelOrigin: function () {
		this._checkIfLoaded();
		return this._pixelOrigin;
	},

	// @method getPixelWorldBounds(zoom?: Number): Bounds
	// Returns the world's bounds in pixel coordinates for zoom level `zoom`.
	// If `zoom` is omitted, the map's current zoom level is used.
	getPixelWorldBounds: function (zoom) {
		return this.options.crs.getProjectedBounds(zoom === undefined ? this.getZoom() : zoom);
	},

	// @section Other Methods

	// @method getPane(pane: String|HTMLElement): HTMLElement
	// Returns a [map pane](#map-pane), given its name or its HTML element (its identity).
	getPane: function (pane) {
		return typeof pane === 'string' ? this._panes[pane] : pane;
	},

	// @method getPanes(): Object
	// Returns a plain object containing the names of all [panes](#map-pane) as keys and
	// the panes as values.
	getPanes: function () {
		return this._panes;
	},

	// @method getContainer: HTMLElement
	// Returns the HTML element that contains the map.
	getContainer: function () {
		return this._container;
	},


	// @section Conversion Methods

	// @method getZoomScale(toZoom: Number, fromZoom: Number): Number
	// Returns the scale factor to be applied to a map transition from zoom level
	// `fromZoom` to `toZoom`. Used internally to help with zoom animations.
	getZoomScale: function (toZoom, fromZoom) {
		// TODO replace with universal implementation after refactoring projections
		var crs = this.options.crs;
		fromZoom = fromZoom === undefined ? this._zoom : fromZoom;
		return crs.scale(toZoom) / crs.scale(fromZoom);
	},

	// @method getScaleZoom(scale: Number, fromZoom: Number): Number
	// Returns the zoom level that the map would end up at, if it is at `fromZoom`
	// level and everything is scaled by a factor of `scale`. Inverse of
	// [`getZoomScale`](#map-getZoomScale).
	getScaleZoom: function (scale, fromZoom) {
		var crs = this.options.crs;
		fromZoom = fromZoom === undefined ? this._zoom : fromZoom;
		var zoom = crs.zoom(scale * crs.scale(fromZoom));
		return isNaN(zoom) ? Infinity : zoom;
	},

	// @method project(latlng: LatLng, zoom: Number): Point
	// Projects a geographical coordinate `LatLng` according to the projection
	// of the map's CRS, then scales it according to `zoom` and the CRS's
	// `Transformation`. The result is pixel coordinate relative to
	// the CRS origin.
	project: function (latlng, zoom) {
		zoom = zoom === undefined ? this._zoom : zoom;
		return this.options.crs.latLngToPoint(toLatLng(latlng), zoom);
	},

	// @method unproject(point: Point, zoom: Number): LatLng
	// Inverse of [`project`](#map-project).
	unproject: function (point, zoom) {
		zoom = zoom === undefined ? this._zoom : zoom;
		return this.options.crs.pointToLatLng(toPoint(point), zoom);
	},

	// @method layerPointToLatLng(point: Point): LatLng
	// Given a pixel coordinate relative to the [origin pixel](#map-getpixelorigin),
	// returns the corresponding geographical coordinate (for the current zoom level).
	layerPointToLatLng: function (point) {
		var projectedPoint = toPoint(point).add(this.getPixelOrigin());
		return this.unproject(projectedPoint);
	},

	// @method latLngToLayerPoint(latlng: LatLng): Point
	// Given a geographical coordinate, returns the corresponding pixel coordinate
	// relative to the [origin pixel](#map-getpixelorigin).
	latLngToLayerPoint: function (latlng) {
		var projectedPoint = this.project(toLatLng(latlng))._round();
		return projectedPoint._subtract(this.getPixelOrigin());
	},

	// @method wrapLatLng(latlng: LatLng): LatLng
	// Returns a `LatLng` where `lat` and `lng` has been wrapped according to the
	// map's CRS's `wrapLat` and `wrapLng` properties, if they are outside the
	// CRS's bounds.
	// By default this means longitude is wrapped around the dateline so its
	// value is between -180 and +180 degrees.
	wrapLatLng: function (latlng) {
		return this.options.crs.wrapLatLng(toLatLng(latlng));
	},

	// @method wrapLatLngBounds(bounds: LatLngBounds): LatLngBounds
	// Returns a `LatLngBounds` with the same size as the given one, ensuring that
	// its center is within the CRS's bounds.
	// By default this means the center longitude is wrapped around the dateline so its
	// value is between -180 and +180 degrees, and the majority of the bounds
	// overlaps the CRS's bounds.
	wrapLatLngBounds: function (latlng) {
		return this.options.crs.wrapLatLngBounds(toLatLngBounds(latlng));
	},

	// @method distance(latlng1: LatLng, latlng2: LatLng): Number
	// Returns the distance between two geographical coordinates according to
	// the map's CRS. By default this measures distance in meters.
	distance: function (latlng1, latlng2) {
		return this.options.crs.distance(toLatLng(latlng1), toLatLng(latlng2));
	},

	// @method containerPointToLayerPoint(point: Point): Point
	// Given a pixel coordinate relative to the map container, returns the corresponding
	// pixel coordinate relative to the [origin pixel](#map-getpixelorigin).
	containerPointToLayerPoint: function (point) { // (Point)
		return toPoint(point).subtract(this._getMapPanePos());
	},

	// @method layerPointToContainerPoint(point: Point): Point
	// Given a pixel coordinate relative to the [origin pixel](#map-getpixelorigin),
	// returns the corresponding pixel coordinate relative to the map container.
	layerPointToContainerPoint: function (point) { // (Point)
		return toPoint(point).add(this._getMapPanePos());
	},

	// @method containerPointToLatLng(point: Point): LatLng
	// Given a pixel coordinate relative to the map container, returns
	// the corresponding geographical coordinate (for the current zoom level).
	containerPointToLatLng: function (point) {
		var layerPoint = this.containerPointToLayerPoint(toPoint(point));
		return this.layerPointToLatLng(layerPoint);
	},

	// @method latLngToContainerPoint(latlng: LatLng): Point
	// Given a geographical coordinate, returns the corresponding pixel coordinate
	// relative to the map container.
	latLngToContainerPoint: function (latlng) {
		return this.layerPointToContainerPoint(this.latLngToLayerPoint(toLatLng(latlng)));
	},

	// @method mouseEventToContainerPoint(ev: MouseEvent): Point
	// Given a MouseEvent object, returns the pixel coordinate relative to the
	// map container where the event took place.
	mouseEventToContainerPoint: function (e) {
		return getMousePosition(e, this._container);
	},

	// @method mouseEventToLayerPoint(ev: MouseEvent): Point
	// Given a MouseEvent object, returns the pixel coordinate relative to
	// the [origin pixel](#map-getpixelorigin) where the event took place.
	mouseEventToLayerPoint: function (e) {
		return this.containerPointToLayerPoint(this.mouseEventToContainerPoint(e));
	},

	// @method mouseEventToLatLng(ev: MouseEvent): LatLng
	// Given a MouseEvent object, returns geographical coordinate where the
	// event took place.
	mouseEventToLatLng: function (e) { // (MouseEvent)
		return this.layerPointToLatLng(this.mouseEventToLayerPoint(e));
	},


	// map initialization methods

	_initContainer: function (id) {
		var container = this._container = get(id);

		if (!container) {
			throw new Error('Map container not found.');
		} else if (container._leaflet_id) {
			throw new Error('Map container is already initialized.');
		}

		on(container, 'scroll', this._onScroll, this);
		this._containerId = stamp$1(container);
	},

	_initLayout: function () {
		var container = this._container;

		this._fadeAnimated = this.options.fadeAnimation && any3d;

		addClass(container, 'leaflet-container' +
			(touch ? ' leaflet-touch' : '') +
			(retina ? ' leaflet-retina' : '') +
			(ielt9 ? ' leaflet-oldie' : '') +
			(safari ? ' leaflet-safari' : '') +
			(this._fadeAnimated ? ' leaflet-fade-anim' : ''));

		var position = getStyle(container, 'position');

		if (position !== 'absolute' && position !== 'relative' && position !== 'fixed') {
			container.style.position = 'relative';
		}

		this._initPanes();

		if (this._initControlPos) {
			this._initControlPos();
		}
	},

	_initPanes: function () {
		var panes = this._panes = {};
		this._paneRenderers = {};

		// @section
		//
		// Panes are DOM elements used to control the ordering of layers on the map. You
		// can access panes with [`map.getPane`](#map-getpane) or
		// [`map.getPanes`](#map-getpanes) methods. New panes can be created with the
		// [`map.createPane`](#map-createpane) method.
		//
		// Every map has the following default panes that differ only in zIndex.
		//
		// @pane mapPane: HTMLElement = 'auto'
		// Pane that contains all other map panes

		this._mapPane = this.createPane('mapPane', this._container);
		setPosition(this._mapPane, new Point(0, 0));

		// @pane tilePane: HTMLElement = 200
		// Pane for `GridLayer`s and `TileLayer`s
		this.createPane('tilePane');
		// @pane overlayPane: HTMLElement = 400
		// Pane for vectors (`Path`s, like `Polyline`s and `Polygon`s), `ImageOverlay`s and `VideoOverlay`s
		this.createPane('shadowPane');
		// @pane shadowPane: HTMLElement = 500
		// Pane for overlay shadows (e.g. `Marker` shadows)
		this.createPane('overlayPane');
		// @pane markerPane: HTMLElement = 600
		// Pane for `Icon`s of `Marker`s
		this.createPane('markerPane');
		// @pane tooltipPane: HTMLElement = 650
		// Pane for `Tooltip`s.
		this.createPane('tooltipPane');
		// @pane popupPane: HTMLElement = 700
		// Pane for `Popup`s.
		this.createPane('popupPane');

		if (!this.options.markerZoomAnimation) {
			addClass(panes.markerPane, 'leaflet-zoom-hide');
			addClass(panes.shadowPane, 'leaflet-zoom-hide');
		}
	},


	// private methods that modify map state

	// @section Map state change events
	_resetView: function (center, zoom) {
		setPosition(this._mapPane, new Point(0, 0));

		var loading = !this._loaded;
		this._loaded = true;
		zoom = this._limitZoom(zoom);

		this.fire('viewprereset');

		var zoomChanged = this._zoom !== zoom;
		this
			._moveStart(zoomChanged, false)
			._move(center, zoom)
			._moveEnd(zoomChanged);

		// @event viewreset: Event
		// Fired when the map needs to redraw its content (this usually happens
		// on map zoom or load). Very useful for creating custom overlays.
		this.fire('viewreset');

		// @event load: Event
		// Fired when the map is initialized (when its center and zoom are set
		// for the first time).
		if (loading) {
			this.fire('load');
		}
	},

	_moveStart: function (zoomChanged, noMoveStart) {
		// @event zoomstart: Event
		// Fired when the map zoom is about to change (e.g. before zoom animation).
		// @event movestart: Event
		// Fired when the view of the map starts changing (e.g. user starts dragging the map).
		if (zoomChanged) {
			this.fire('zoomstart');
		}
		if (!noMoveStart) {
			this.fire('movestart');
		}
		return this;
	},

	_move: function (center, zoom, data) {
		if (zoom === undefined) {
			zoom = this._zoom;
		}
		var zoomChanged = this._zoom !== zoom;

		this._zoom = zoom;
		this._lastCenter = center;
		this._pixelOrigin = this._getNewPixelOrigin(center);

		// @event zoom: Event
		// Fired repeatedly during any change in zoom level, including zoom
		// and fly animations.
		if (zoomChanged || (data && data.pinch)) {	// Always fire 'zoom' if pinching because #3530
			this.fire('zoom', data);
		}

		// @event move: Event
		// Fired repeatedly during any movement of the map, including pan and
		// fly animations.
		return this.fire('move', data);
	},

	_moveEnd: function (zoomChanged) {
		// @event zoomend: Event
		// Fired when the map has changed, after any animations.
		if (zoomChanged) {
			this.fire('zoomend');
		}

		// @event moveend: Event
		// Fired when the center of the map stops changing (e.g. user stopped
		// dragging the map).
		return this.fire('moveend');
	},

	_stop: function () {
		cancelAnimFrame(this._flyToFrame);
		if (this._panAnim) {
			this._panAnim.stop();
		}
		return this;
	},

	_rawPanBy: function (offset) {
		setPosition(this._mapPane, this._getMapPanePos().subtract(offset));
	},

	_getZoomSpan: function () {
		return this.getMaxZoom() - this.getMinZoom();
	},

	_panInsideMaxBounds: function () {
		if (!this._enforcingBounds) {
			this.panInsideBounds(this.options.maxBounds);
		}
	},

	_checkIfLoaded: function () {
		if (!this._loaded) {
			throw new Error('Set map center and zoom first.');
		}
	},

	// DOM event handling

	// @section Interaction events
	_initEvents: function (remove) {
		this._targets = {};
		this._targets[stamp$1(this._container)] = this;

		var onOff = remove ? off : on;

		// @event click: MouseEvent
		// Fired when the user clicks (or taps) the map.
		// @event dblclick: MouseEvent
		// Fired when the user double-clicks (or double-taps) the map.
		// @event mousedown: MouseEvent
		// Fired when the user pushes the mouse button on the map.
		// @event mouseup: MouseEvent
		// Fired when the user releases the mouse button on the map.
		// @event mouseover: MouseEvent
		// Fired when the mouse enters the map.
		// @event mouseout: MouseEvent
		// Fired when the mouse leaves the map.
		// @event mousemove: MouseEvent
		// Fired while the mouse moves over the map.
		// @event contextmenu: MouseEvent
		// Fired when the user pushes the right mouse button on the map, prevents
		// default browser context menu from showing if there are listeners on
		// this event. Also fired on mobile when the user holds a single touch
		// for a second (also called long press).
		// @event keypress: KeyboardEvent
		// Fired when the user presses a key from the keyboard that produces a character value while the map is focused.
		// @event keydown: KeyboardEvent
		// Fired when the user presses a key from the keyboard while the map is focused. Unlike the `keypress` event,
		// the `keydown` event is fired for keys that produce a character value and for keys
		// that do not produce a character value.
		// @event keyup: KeyboardEvent
		// Fired when the user releases a key from the keyboard while the map is focused.
		onOff(this._container, 'click dblclick mousedown mouseup ' +
			'mouseover mouseout mousemove contextmenu keypress keydown keyup', this._handleDOMEvent, this);

		if (this.options.trackResize) {
			onOff(window, 'resize', this._onResize, this);
		}

		if (any3d && this.options.transform3DLimit) {
			(remove ? this.off : this.on).call(this, 'moveend', this._onMoveEnd);
		}
	},

	_onResize: function () {
		cancelAnimFrame(this._resizeRequest);
		this._resizeRequest = requestAnimFrame(
		        function () { this.invalidateSize({debounceMoveend: true}); }, this);
	},

	_onScroll: function () {
		this._container.scrollTop  = 0;
		this._container.scrollLeft = 0;
	},

	_onMoveEnd: function () {
		var pos = this._getMapPanePos();
		if (Math.max(Math.abs(pos.x), Math.abs(pos.y)) >= this.options.transform3DLimit) {
			// https://bugzilla.mozilla.org/show_bug.cgi?id=1203873 but Webkit also have
			// a pixel offset on very high values, see: http://jsfiddle.net/dg6r5hhb/
			this._resetView(this.getCenter(), this.getZoom());
		}
	},

	_findEventTargets: function (e, type) {
		var targets = [],
		    target,
		    isHover = type === 'mouseout' || type === 'mouseover',
		    src = e.target || e.srcElement,
		    dragging = false;

		while (src) {
			target = this._targets[stamp$1(src)];
			if (target && (type === 'click' || type === 'preclick') && !e._simulated && this._draggableMoved(target)) {
				// Prevent firing click after you just dragged an object.
				dragging = true;
				break;
			}
			if (target && target.listens(type, true)) {
				if (isHover && !isExternalTarget(src, e)) { break; }
				targets.push(target);
				if (isHover) { break; }
			}
			if (src === this._container) { break; }
			src = src.parentNode;
		}
		if (!targets.length && !dragging && !isHover && isExternalTarget(src, e)) {
			targets = [this];
		}
		return targets;
	},

	_handleDOMEvent: function (e) {
		if (!this._loaded || skipped(e)) { return; }

		var type = e.type;

		if (type === 'mousedown' || type === 'keypress' || type === 'keyup' || type === 'keydown') {
			// prevents outline when clicking on keyboard-focusable element
			preventOutline(e.target || e.srcElement);
		}

		this._fireDOMEvent(e, type);
	},

	_mouseEvents: ['click', 'dblclick', 'mouseover', 'mouseout', 'contextmenu'],

	_fireDOMEvent: function (e, type, targets) {

		if (e.type === 'click') {
			// Fire a synthetic 'preclick' event which propagates up (mainly for closing popups).
			// @event preclick: MouseEvent
			// Fired before mouse click on the map (sometimes useful when you
			// want something to happen on click before any existing click
			// handlers start running).
			var synth = extend({}, e);
			synth.type = 'preclick';
			this._fireDOMEvent(synth, synth.type, targets);
		}

		if (e._stopped) { return; }

		// Find the layer the event is propagating from and its parents.
		targets = (targets || []).concat(this._findEventTargets(e, type));

		if (!targets.length) { return; }

		var target = targets[0];
		if (type === 'contextmenu' && target.listens(type, true)) {
			preventDefault(e);
		}

		var data = {
			originalEvent: e
		};

		if (e.type !== 'keypress' && e.type !== 'keydown' && e.type !== 'keyup') {
			var isMarker = target.getLatLng && (!target._radius || target._radius <= 10);
			data.containerPoint = isMarker ?
				this.latLngToContainerPoint(target.getLatLng()) : this.mouseEventToContainerPoint(e);
			data.layerPoint = this.containerPointToLayerPoint(data.containerPoint);
			data.latlng = isMarker ? target.getLatLng() : this.layerPointToLatLng(data.layerPoint);
		}

		for (var i = 0; i < targets.length; i++) {
			targets[i].fire(type, data, true);
			if (data.originalEvent._stopped ||
				(targets[i].options.bubblingMouseEvents === false && indexOf(this._mouseEvents, type) !== -1)) { return; }
		}
	},

	_draggableMoved: function (obj) {
		obj = obj.dragging && obj.dragging.enabled() ? obj : this;
		return (obj.dragging && obj.dragging.moved()) || (this.boxZoom && this.boxZoom.moved());
	},

	_clearHandlers: function () {
		for (var i = 0, len = this._handlers.length; i < len; i++) {
			this._handlers[i].disable();
		}
	},

	// @section Other Methods

	// @method whenReady(fn: Function, context?: Object): this
	// Runs the given function `fn` when the map gets initialized with
	// a view (center and zoom) and at least one layer, or immediately
	// if it's already initialized, optionally passing a function context.
	whenReady: function (callback, context) {
		if (this._loaded) {
			callback.call(context || this, {target: this});
		} else {
			this.on('load', callback, context);
		}
		return this;
	},


	// private methods for getting map state

	_getMapPanePos: function () {
		return getPosition(this._mapPane) || new Point(0, 0);
	},

	_moved: function () {
		var pos = this._getMapPanePos();
		return pos && !pos.equals([0, 0]);
	},

	_getTopLeftPoint: function (center, zoom) {
		var pixelOrigin = center && zoom !== undefined ?
			this._getNewPixelOrigin(center, zoom) :
			this.getPixelOrigin();
		return pixelOrigin.subtract(this._getMapPanePos());
	},

	_getNewPixelOrigin: function (center, zoom) {
		var viewHalf = this.getSize()._divideBy(2);
		return this.project(center, zoom)._subtract(viewHalf)._add(this._getMapPanePos())._round();
	},

	_latLngToNewLayerPoint: function (latlng, zoom, center) {
		var topLeft = this._getNewPixelOrigin(center, zoom);
		return this.project(latlng, zoom)._subtract(topLeft);
	},

	_latLngBoundsToNewLayerBounds: function (latLngBounds, zoom, center) {
		var topLeft = this._getNewPixelOrigin(center, zoom);
		return toBounds([
			this.project(latLngBounds.getSouthWest(), zoom)._subtract(topLeft),
			this.project(latLngBounds.getNorthWest(), zoom)._subtract(topLeft),
			this.project(latLngBounds.getSouthEast(), zoom)._subtract(topLeft),
			this.project(latLngBounds.getNorthEast(), zoom)._subtract(topLeft)
		]);
	},

	// layer point of the current center
	_getCenterLayerPoint: function () {
		return this.containerPointToLayerPoint(this.getSize()._divideBy(2));
	},

	// offset of the specified place to the current center in pixels
	_getCenterOffset: function (latlng) {
		return this.latLngToLayerPoint(latlng).subtract(this._getCenterLayerPoint());
	},

	// adjust center for view to get inside bounds
	_limitCenter: function (center, zoom, bounds) {

		if (!bounds) { return center; }

		var centerPoint = this.project(center, zoom),
		    viewHalf = this.getSize().divideBy(2),
		    viewBounds = new Bounds(centerPoint.subtract(viewHalf), centerPoint.add(viewHalf)),
		    offset = this._getBoundsOffset(viewBounds, bounds, zoom);

		// If offset is less than a pixel, ignore.
		// This prevents unstable projections from getting into
		// an infinite loop of tiny offsets.
		if (offset.round().equals([0, 0])) {
			return center;
		}

		return this.unproject(centerPoint.add(offset), zoom);
	},

	// adjust offset for view to get inside bounds
	_limitOffset: function (offset, bounds) {
		if (!bounds) { return offset; }

		var viewBounds = this.getPixelBounds(),
		    newBounds = new Bounds(viewBounds.min.add(offset), viewBounds.max.add(offset));

		return offset.add(this._getBoundsOffset(newBounds, bounds));
	},

	// returns offset needed for pxBounds to get inside maxBounds at a specified zoom
	_getBoundsOffset: function (pxBounds, maxBounds, zoom) {
		var projectedMaxBounds = toBounds(
		        this.project(maxBounds.getNorthEast(), zoom),
		        this.project(maxBounds.getSouthWest(), zoom)
		    ),
		    minOffset = projectedMaxBounds.min.subtract(pxBounds.min),
		    maxOffset = projectedMaxBounds.max.subtract(pxBounds.max),

		    dx = this._rebound(minOffset.x, -maxOffset.x),
		    dy = this._rebound(minOffset.y, -maxOffset.y);

		return new Point(dx, dy);
	},

	_rebound: function (left, right) {
		return left + right > 0 ?
			Math.round(left - right) / 2 :
			Math.max(0, Math.ceil(left)) - Math.max(0, Math.floor(right));
	},

	_limitZoom: function (zoom) {
		var min = this.getMinZoom(),
		    max = this.getMaxZoom(),
		    snap = any3d ? this.options.zoomSnap : 1;
		if (snap) {
			zoom = Math.round(zoom / snap) * snap;
		}
		return Math.max(min, Math.min(max, zoom));
	},

	_onPanTransitionStep: function () {
		this.fire('move');
	},

	_onPanTransitionEnd: function () {
		removeClass(this._mapPane, 'leaflet-pan-anim');
		this.fire('moveend');
	},

	_tryAnimatedPan: function (center, options) {
		// difference between the new and current centers in pixels
		var offset = this._getCenterOffset(center)._trunc();

		// don't animate too far unless animate: true specified in options
		if ((options && options.animate) !== true && !this.getSize().contains(offset)) { return false; }

		this.panBy(offset, options);

		return true;
	},

	_createAnimProxy: function () {

		var proxy = this._proxy = create$1('div', 'leaflet-proxy leaflet-zoom-animated');
		this._panes.mapPane.appendChild(proxy);

		this.on('zoomanim', function (e) {
			var prop = TRANSFORM,
			    transform = this._proxy.style[prop];

			setTransform(this._proxy, this.project(e.center, e.zoom), this.getZoomScale(e.zoom, 1));

			// workaround for case when transform is the same and so transitionend event is not fired
			if (transform === this._proxy.style[prop] && this._animatingZoom) {
				this._onZoomTransitionEnd();
			}
		}, this);

		this.on('load moveend', this._animMoveEnd, this);

		this._on('unload', this._destroyAnimProxy, this);
	},

	_destroyAnimProxy: function () {
		remove(this._proxy);
		this.off('load moveend', this._animMoveEnd, this);
		delete this._proxy;
	},

	_animMoveEnd: function () {
		var c = this.getCenter(),
		    z = this.getZoom();
		setTransform(this._proxy, this.project(c, z), this.getZoomScale(z, 1));
	},

	_catchTransitionEnd: function (e) {
		if (this._animatingZoom && e.propertyName.indexOf('transform') >= 0) {
			this._onZoomTransitionEnd();
		}
	},

	_nothingToAnimate: function () {
		return !this._container.getElementsByClassName('leaflet-zoom-animated').length;
	},

	_tryAnimatedZoom: function (center, zoom, options) {

		if (this._animatingZoom) { return true; }

		options = options || {};

		// don't animate if disabled, not supported or zoom difference is too large
		if (!this._zoomAnimated || options.animate === false || this._nothingToAnimate() ||
		        Math.abs(zoom - this._zoom) > this.options.zoomAnimationThreshold) { return false; }

		// offset is the pixel coords of the zoom origin relative to the current center
		var scale = this.getZoomScale(zoom),
		    offset = this._getCenterOffset(center)._divideBy(1 - 1 / scale);

		// don't animate if the zoom origin isn't within one screen from the current center, unless forced
		if (options.animate !== true && !this.getSize().contains(offset)) { return false; }

		requestAnimFrame(function () {
			this
			    ._moveStart(true, false)
			    ._animateZoom(center, zoom, true);
		}, this);

		return true;
	},

	_animateZoom: function (center, zoom, startAnim, noUpdate) {
		if (!this._mapPane) { return; }

		if (startAnim) {
			this._animatingZoom = true;

			// remember what center/zoom to set after animation
			this._animateToCenter = center;
			this._animateToZoom = zoom;

			addClass(this._mapPane, 'leaflet-zoom-anim');
		}

		// @section Other Events
		// @event zoomanim: ZoomAnimEvent
		// Fired at least once per zoom animation. For continuous zoom, like pinch zooming, fired once per frame during zoom.
		this.fire('zoomanim', {
			center: center,
			zoom: zoom,
			noUpdate: noUpdate
		});

		// Work around webkit not firing 'transitionend', see https://github.com/Leaflet/Leaflet/issues/3689, 2693
		setTimeout(bind(this._onZoomTransitionEnd, this), 250);
	},

	_onZoomTransitionEnd: function () {
		if (!this._animatingZoom) { return; }

		if (this._mapPane) {
			removeClass(this._mapPane, 'leaflet-zoom-anim');
		}

		this._animatingZoom = false;

		this._move(this._animateToCenter, this._animateToZoom);

		// This anim frame should prevent an obscure iOS webkit tile loading race condition.
		requestAnimFrame(function () {
			this._moveEnd(true);
		}, this);
	}
});

/*
	L.Handler is a base class for handler classes that are used internally to inject
	interaction features like dragging to classes like Map and Marker.
*/

// @class Handler
// @aka L.Handler
// Abstract class for map interaction handlers

var Handler = Class.extend({
	initialize: function (map) {
		this._map = map;
	},

	// @method enable(): this
	// Enables the handler
	enable: function () {
		if (this._enabled) { return this; }

		this._enabled = true;
		this.addHooks();
		return this;
	},

	// @method disable(): this
	// Disables the handler
	disable: function () {
		if (!this._enabled) { return this; }

		this._enabled = false;
		this.removeHooks();
		return this;
	},

	// @method enabled(): Boolean
	// Returns `true` if the handler is enabled
	enabled: function () {
		return !!this._enabled;
	}

	// @section Extension methods
	// Classes inheriting from `Handler` must implement the two following methods:
	// @method addHooks()
	// Called when the handler is enabled, should add event hooks.
	// @method removeHooks()
	// Called when the handler is disabled, should remove the event hooks added previously.
});

// @section There is static function which can be called without instantiating L.Handler:
// @function addTo(map: Map, name: String): this
// Adds a new Handler to the given map with the given name.
Handler.addTo = function (map, name) {
	map.addHandler(name, this);
	return this;
};

/*
 * L.Handler.BoxZoom is used to add shift-drag zoom interaction to the map
 * (zoom to a selected bounding box), enabled by default.
 */

// @namespace Map
// @section Interaction Options
Map$1.mergeOptions({
	// @option boxZoom: Boolean = true
	// Whether the map can be zoomed to a rectangular area specified by
	// dragging the mouse while pressing the shift key.
	boxZoom: true
});

var BoxZoom = Handler.extend({
	initialize: function (map) {
		this._map = map;
		this._container = map._container;
		this._pane = map._panes.overlayPane;
		this._resetStateTimeout = 0;
		map.on('unload', this._destroy, this);
	},

	addHooks: function () {
		on(this._container, 'mousedown', this._onMouseDown, this);
	},

	removeHooks: function () {
		off(this._container, 'mousedown', this._onMouseDown, this);
	},

	moved: function () {
		return this._moved;
	},

	_destroy: function () {
		remove(this._pane);
		delete this._pane;
	},

	_resetState: function () {
		this._resetStateTimeout = 0;
		this._moved = false;
	},

	_clearDeferredResetState: function () {
		if (this._resetStateTimeout !== 0) {
			clearTimeout(this._resetStateTimeout);
			this._resetStateTimeout = 0;
		}
	},

	_onMouseDown: function (e) {
		if (!e.shiftKey || ((e.which !== 1) && (e.button !== 1))) { return false; }

		// Clear the deferred resetState if it hasn't executed yet, otherwise it
		// will interrupt the interaction and orphan a box element in the container.
		this._clearDeferredResetState();
		this._resetState();

		disableTextSelection();
		disableImageDrag();

		this._startPoint = this._map.mouseEventToContainerPoint(e);

		on(document, {
			contextmenu: stop,
			mousemove: this._onMouseMove,
			mouseup: this._onMouseUp,
			keydown: this._onKeyDown
		}, this);
	},

	_onMouseMove: function (e) {
		if (!this._moved) {
			this._moved = true;

			this._box = create$1('div', 'leaflet-zoom-box', this._container);
			addClass(this._container, 'leaflet-crosshair');

			this._map.fire('boxzoomstart');
		}

		this._point = this._map.mouseEventToContainerPoint(e);

		var bounds = new Bounds(this._point, this._startPoint),
		    size = bounds.getSize();

		setPosition(this._box, bounds.min);

		this._box.style.width  = size.x + 'px';
		this._box.style.height = size.y + 'px';
	},

	_finish: function () {
		if (this._moved) {
			remove(this._box);
			removeClass(this._container, 'leaflet-crosshair');
		}

		enableTextSelection();
		enableImageDrag();

		off(document, {
			contextmenu: stop,
			mousemove: this._onMouseMove,
			mouseup: this._onMouseUp,
			keydown: this._onKeyDown
		}, this);
	},

	_onMouseUp: function (e) {
		if ((e.which !== 1) && (e.button !== 1)) { return; }

		this._finish();

		if (!this._moved) { return; }
		// Postpone to next JS tick so internal click event handling
		// still see it as "moved".
		this._clearDeferredResetState();
		this._resetStateTimeout = setTimeout(bind(this._resetState, this), 0);

		var bounds = new LatLngBounds(
		        this._map.containerPointToLatLng(this._startPoint),
		        this._map.containerPointToLatLng(this._point));

		this._map
			.fitBounds(bounds)
			.fire('boxzoomend', {boxZoomBounds: bounds});
	},

	_onKeyDown: function (e) {
		if (e.keyCode === 27) {
			this._finish();
		}
	}
});

// @section Handlers
// @property boxZoom: Handler
// Box (shift-drag with mouse) zoom handler.
Map$1.addInitHook('addHandler', 'boxZoom', BoxZoom);

/*
 * L.Handler.DoubleClickZoom is used to handle double-click zoom on the map, enabled by default.
 */

// @namespace Map
// @section Interaction Options

Map$1.mergeOptions({
	// @option doubleClickZoom: Boolean|String = true
	// Whether the map can be zoomed in by double clicking on it and
	// zoomed out by double clicking while holding shift. If passed
	// `'center'`, double-click zoom will zoom to the center of the
	//  view regardless of where the mouse was.
	doubleClickZoom: true
});

var DoubleClickZoom = Handler.extend({
	addHooks: function () {
		this._map.on('dblclick', this._onDoubleClick, this);
	},

	removeHooks: function () {
		this._map.off('dblclick', this._onDoubleClick, this);
	},

	_onDoubleClick: function (e) {
		var map = this._map,
		    oldZoom = map.getZoom(),
		    delta = map.options.zoomDelta,
		    zoom = e.originalEvent.shiftKey ? oldZoom - delta : oldZoom + delta;

		if (map.options.doubleClickZoom === 'center') {
			map.setZoom(zoom);
		} else {
			map.setZoomAround(e.containerPoint, zoom);
		}
	}
});

// @section Handlers
//
// Map properties include interaction handlers that allow you to control
// interaction behavior in runtime, enabling or disabling certain features such
// as dragging or touch zoom (see `Handler` methods). For example:
//
// ```js
// map.doubleClickZoom.disable();
// ```
//
// @property doubleClickZoom: Handler
// Double click zoom handler.
Map$1.addInitHook('addHandler', 'doubleClickZoom', DoubleClickZoom);

/*
 * @class Draggable
 * @aka L.Draggable
 * @inherits Evented
 *
 * A class for making DOM elements draggable (including touch support).
 * Used internally for map and marker dragging. Only works for elements
 * that were positioned with [`L.DomUtil.setPosition`](#domutil-setposition).
 *
 * @example
 * ```js
 * var draggable = new L.Draggable(elementToDrag);
 * draggable.enable();
 * ```
 */

var START = touch ? 'touchstart mousedown' : 'mousedown';
var END = {
	mousedown: 'mouseup',
	touchstart: 'touchend',
	pointerdown: 'touchend',
	MSPointerDown: 'touchend'
};
var MOVE = {
	mousedown: 'mousemove',
	touchstart: 'touchmove',
	pointerdown: 'touchmove',
	MSPointerDown: 'touchmove'
};


var Draggable = Evented.extend({

	options: {
		// @section
		// @aka Draggable options
		// @option clickTolerance: Number = 3
		// The max number of pixels a user can shift the mouse pointer during a click
		// for it to be considered a valid click (as opposed to a mouse drag).
		clickTolerance: 3
	},

	// @constructor L.Draggable(el: HTMLElement, dragHandle?: HTMLElement, preventOutline?: Boolean, options?: Draggable options)
	// Creates a `Draggable` object for moving `el` when you start dragging the `dragHandle` element (equals `el` itself by default).
	initialize: function (element, dragStartTarget, preventOutline, options) {
		setOptions$1(this, options);

		this._element = element;
		this._dragStartTarget = dragStartTarget || element;
		this._preventOutline = preventOutline;
	},

	// @method enable()
	// Enables the dragging ability
	enable: function () {
		if (this._enabled) { return; }

		on(this._dragStartTarget, START, this._onDown, this);

		this._enabled = true;
	},

	// @method disable()
	// Disables the dragging ability
	disable: function () {
		if (!this._enabled) { return; }

		// If we're currently dragging this draggable,
		// disabling it counts as first ending the drag.
		if (Draggable._dragging === this) {
			this.finishDrag();
		}

		off(this._dragStartTarget, START, this._onDown, this);

		this._enabled = false;
		this._moved = false;
	},

	_onDown: function (e) {
		// Ignore simulated events, since we handle both touch and
		// mouse explicitly; otherwise we risk getting duplicates of
		// touch events, see #4315.
		// Also ignore the event if disabled; this happens in IE11
		// under some circumstances, see #3666.
		if (e._simulated || !this._enabled) { return; }

		this._moved = false;

		if (hasClass(this._element, 'leaflet-zoom-anim')) { return; }

		if (Draggable._dragging || e.shiftKey || ((e.which !== 1) && (e.button !== 1) && !e.touches)) { return; }
		Draggable._dragging = this;  // Prevent dragging multiple objects at once.

		if (this._preventOutline) {
			preventOutline(this._element);
		}

		disableImageDrag();
		disableTextSelection();

		if (this._moving) { return; }

		// @event down: Event
		// Fired when a drag is about to start.
		this.fire('down');

		var first = e.touches ? e.touches[0] : e,
		    sizedParent = getSizedParentNode(this._element);

		this._startPoint = new Point(first.clientX, first.clientY);

		// Cache the scale, so that we can continuously compensate for it during drag (_onMove).
		this._parentScale = getScale(sizedParent);

		on(document, MOVE[e.type], this._onMove, this);
		on(document, END[e.type], this._onUp, this);
	},

	_onMove: function (e) {
		// Ignore simulated events, since we handle both touch and
		// mouse explicitly; otherwise we risk getting duplicates of
		// touch events, see #4315.
		// Also ignore the event if disabled; this happens in IE11
		// under some circumstances, see #3666.
		if (e._simulated || !this._enabled) { return; }

		if (e.touches && e.touches.length > 1) {
			this._moved = true;
			return;
		}

		var first = (e.touches && e.touches.length === 1 ? e.touches[0] : e),
		    offset = new Point(first.clientX, first.clientY)._subtract(this._startPoint);

		if (!offset.x && !offset.y) { return; }
		if (Math.abs(offset.x) + Math.abs(offset.y) < this.options.clickTolerance) { return; }

		// We assume that the parent container's position, border and scale do not change for the duration of the drag.
		// Therefore there is no need to account for the position and border (they are eliminated by the subtraction)
		// and we can use the cached value for the scale.
		offset.x /= this._parentScale.x;
		offset.y /= this._parentScale.y;

		preventDefault(e);

		if (!this._moved) {
			// @event dragstart: Event
			// Fired when a drag starts
			this.fire('dragstart');

			this._moved = true;
			this._startPos = getPosition(this._element).subtract(offset);

			addClass(document.body, 'leaflet-dragging');

			this._lastTarget = e.target || e.srcElement;
			// IE and Edge do not give the <use> element, so fetch it
			// if necessary
			if ((window.SVGElementInstance) && (this._lastTarget instanceof SVGElementInstance)) {
				this._lastTarget = this._lastTarget.correspondingUseElement;
			}
			addClass(this._lastTarget, 'leaflet-drag-target');
		}

		this._newPos = this._startPos.add(offset);
		this._moving = true;

		cancelAnimFrame(this._animRequest);
		this._lastEvent = e;
		this._animRequest = requestAnimFrame(this._updatePosition, this, true);
	},

	_updatePosition: function () {
		var e = {originalEvent: this._lastEvent};

		// @event predrag: Event
		// Fired continuously during dragging *before* each corresponding
		// update of the element's position.
		this.fire('predrag', e);
		setPosition(this._element, this._newPos);

		// @event drag: Event
		// Fired continuously during dragging.
		this.fire('drag', e);
	},

	_onUp: function (e) {
		// Ignore simulated events, since we handle both touch and
		// mouse explicitly; otherwise we risk getting duplicates of
		// touch events, see #4315.
		// Also ignore the event if disabled; this happens in IE11
		// under some circumstances, see #3666.
		if (e._simulated || !this._enabled) { return; }
		this.finishDrag();
	},

	finishDrag: function () {
		removeClass(document.body, 'leaflet-dragging');

		if (this._lastTarget) {
			removeClass(this._lastTarget, 'leaflet-drag-target');
			this._lastTarget = null;
		}

		for (var i in MOVE) {
			off(document, MOVE[i], this._onMove, this);
			off(document, END[i], this._onUp, this);
		}

		enableImageDrag();
		enableTextSelection();

		if (this._moved && this._moving) {
			// ensure drag is not fired after dragend
			cancelAnimFrame(this._animRequest);

			// @event dragend: DragEndEvent
			// Fired when the drag ends.
			this.fire('dragend', {
				distance: this._newPos.distanceTo(this._startPos)
			});
		}

		this._moving = false;
		Draggable._dragging = false;
	}

});

/*
 * L.Handler.MapDrag is used to make the map draggable (with panning inertia), enabled by default.
 */

// @namespace Map
// @section Interaction Options
Map$1.mergeOptions({
	// @option dragging: Boolean = true
	// Whether the map be draggable with mouse/touch or not.
	dragging: true,

	// @section Panning Inertia Options
	// @option inertia: Boolean = *
	// If enabled, panning of the map will have an inertia effect where
	// the map builds momentum while dragging and continues moving in
	// the same direction for some time. Feels especially nice on touch
	// devices. Enabled by default unless running on old Android devices.
	inertia: !android23,

	// @option inertiaDeceleration: Number = 3000
	// The rate with which the inertial movement slows down, in pixels/second².
	inertiaDeceleration: 3400, // px/s^2

	// @option inertiaMaxSpeed: Number = Infinity
	// Max speed of the inertial movement, in pixels/second.
	inertiaMaxSpeed: Infinity, // px/s

	// @option easeLinearity: Number = 0.2
	easeLinearity: 0.2,

	// TODO refactor, move to CRS
	// @option worldCopyJump: Boolean = false
	// With this option enabled, the map tracks when you pan to another "copy"
	// of the world and seamlessly jumps to the original one so that all overlays
	// like markers and vector layers are still visible.
	worldCopyJump: false,

	// @option maxBoundsViscosity: Number = 0.0
	// If `maxBounds` is set, this option will control how solid the bounds
	// are when dragging the map around. The default value of `0.0` allows the
	// user to drag outside the bounds at normal speed, higher values will
	// slow down map dragging outside bounds, and `1.0` makes the bounds fully
	// solid, preventing the user from dragging outside the bounds.
	maxBoundsViscosity: 0.0
});

var Drag = Handler.extend({
	addHooks: function () {
		if (!this._draggable) {
			var map = this._map;

			this._draggable = new Draggable(map._mapPane, map._container);

			this._draggable.on({
				dragstart: this._onDragStart,
				drag: this._onDrag,
				dragend: this._onDragEnd
			}, this);

			this._draggable.on('predrag', this._onPreDragLimit, this);
			if (map.options.worldCopyJump) {
				this._draggable.on('predrag', this._onPreDragWrap, this);
				map.on('zoomend', this._onZoomEnd, this);

				map.whenReady(this._onZoomEnd, this);
			}
		}
		addClass(this._map._container, 'leaflet-grab leaflet-touch-drag');
		this._draggable.enable();
		this._positions = [];
		this._times = [];
	},

	removeHooks: function () {
		removeClass(this._map._container, 'leaflet-grab');
		removeClass(this._map._container, 'leaflet-touch-drag');
		this._draggable.disable();
	},

	moved: function () {
		return this._draggable && this._draggable._moved;
	},

	moving: function () {
		return this._draggable && this._draggable._moving;
	},

	_onDragStart: function () {
		var map = this._map;

		map._stop();
		if (this._map.options.maxBounds && this._map.options.maxBoundsViscosity) {
			var bounds = toLatLngBounds(this._map.options.maxBounds);

			this._offsetLimit = toBounds(
				this._map.latLngToContainerPoint(bounds.getNorthWest()).multiplyBy(-1),
				this._map.latLngToContainerPoint(bounds.getSouthEast()).multiplyBy(-1)
					.add(this._map.getSize()));

			this._viscosity = Math.min(1.0, Math.max(0.0, this._map.options.maxBoundsViscosity));
		} else {
			this._offsetLimit = null;
		}

		map
		    .fire('movestart')
		    .fire('dragstart');

		if (map.options.inertia) {
			this._positions = [];
			this._times = [];
		}
	},

	_onDrag: function (e) {
		if (this._map.options.inertia) {
			var time = this._lastTime = +new Date(),
			    pos = this._lastPos = this._draggable._absPos || this._draggable._newPos;

			this._positions.push(pos);
			this._times.push(time);

			this._prunePositions(time);
		}

		this._map
		    .fire('move', e)
		    .fire('drag', e);
	},

	_prunePositions: function (time) {
		while (this._positions.length > 1 && time - this._times[0] > 50) {
			this._positions.shift();
			this._times.shift();
		}
	},

	_onZoomEnd: function () {
		var pxCenter = this._map.getSize().divideBy(2),
		    pxWorldCenter = this._map.latLngToLayerPoint([0, 0]);

		this._initialWorldOffset = pxWorldCenter.subtract(pxCenter).x;
		this._worldWidth = this._map.getPixelWorldBounds().getSize().x;
	},

	_viscousLimit: function (value, threshold) {
		return value - (value - threshold) * this._viscosity;
	},

	_onPreDragLimit: function () {
		if (!this._viscosity || !this._offsetLimit) { return; }

		var offset = this._draggable._newPos.subtract(this._draggable._startPos);

		var limit = this._offsetLimit;
		if (offset.x < limit.min.x) { offset.x = this._viscousLimit(offset.x, limit.min.x); }
		if (offset.y < limit.min.y) { offset.y = this._viscousLimit(offset.y, limit.min.y); }
		if (offset.x > limit.max.x) { offset.x = this._viscousLimit(offset.x, limit.max.x); }
		if (offset.y > limit.max.y) { offset.y = this._viscousLimit(offset.y, limit.max.y); }

		this._draggable._newPos = this._draggable._startPos.add(offset);
	},

	_onPreDragWrap: function () {
		// TODO refactor to be able to adjust map pane position after zoom
		var worldWidth = this._worldWidth,
		    halfWidth = Math.round(worldWidth / 2),
		    dx = this._initialWorldOffset,
		    x = this._draggable._newPos.x,
		    newX1 = (x - halfWidth + dx) % worldWidth + halfWidth - dx,
		    newX2 = (x + halfWidth + dx) % worldWidth - halfWidth - dx,
		    newX = Math.abs(newX1 + dx) < Math.abs(newX2 + dx) ? newX1 : newX2;

		this._draggable._absPos = this._draggable._newPos.clone();
		this._draggable._newPos.x = newX;
	},

	_onDragEnd: function (e) {
		var map = this._map,
		    options = map.options,

		    noInertia = !options.inertia || this._times.length < 2;

		map.fire('dragend', e);

		if (noInertia) {
			map.fire('moveend');

		} else {
			this._prunePositions(+new Date());

			var direction = this._lastPos.subtract(this._positions[0]),
			    duration = (this._lastTime - this._times[0]) / 1000,
			    ease = options.easeLinearity,

			    speedVector = direction.multiplyBy(ease / duration),
			    speed = speedVector.distanceTo([0, 0]),

			    limitedSpeed = Math.min(options.inertiaMaxSpeed, speed),
			    limitedSpeedVector = speedVector.multiplyBy(limitedSpeed / speed),

			    decelerationDuration = limitedSpeed / (options.inertiaDeceleration * ease),
			    offset = limitedSpeedVector.multiplyBy(-decelerationDuration / 2).round();

			if (!offset.x && !offset.y) {
				map.fire('moveend');

			} else {
				offset = map._limitOffset(offset, map.options.maxBounds);

				requestAnimFrame(function () {
					map.panBy(offset, {
						duration: decelerationDuration,
						easeLinearity: ease,
						noMoveStart: true,
						animate: true
					});
				});
			}
		}
	}
});

// @section Handlers
// @property dragging: Handler
// Map dragging handler (by both mouse and touch).
Map$1.addInitHook('addHandler', 'dragging', Drag);

/*
 * L.Map.Keyboard is handling keyboard interaction with the map, enabled by default.
 */

// @namespace Map
// @section Keyboard Navigation Options
Map$1.mergeOptions({
	// @option keyboard: Boolean = true
	// Makes the map focusable and allows users to navigate the map with keyboard
	// arrows and `+`/`-` keys.
	keyboard: true,

	// @option keyboardPanDelta: Number = 80
	// Amount of pixels to pan when pressing an arrow key.
	keyboardPanDelta: 80
});

var Keyboard = Handler.extend({

	keyCodes: {
		left:    [37],
		right:   [39],
		down:    [40],
		up:      [38],
		zoomIn:  [187, 107, 61, 171],
		zoomOut: [189, 109, 54, 173]
	},

	initialize: function (map) {
		this._map = map;

		this._setPanDelta(map.options.keyboardPanDelta);
		this._setZoomDelta(map.options.zoomDelta);
	},

	addHooks: function () {
		var container = this._map._container;

		// make the container focusable by tabbing
		if (container.tabIndex <= 0) {
			container.tabIndex = '0';
		}

		on(container, {
			focus: this._onFocus,
			blur: this._onBlur,
			mousedown: this._onMouseDown
		}, this);

		this._map.on({
			focus: this._addHooks,
			blur: this._removeHooks
		}, this);
	},

	removeHooks: function () {
		this._removeHooks();

		off(this._map._container, {
			focus: this._onFocus,
			blur: this._onBlur,
			mousedown: this._onMouseDown
		}, this);

		this._map.off({
			focus: this._addHooks,
			blur: this._removeHooks
		}, this);
	},

	_onMouseDown: function () {
		if (this._focused) { return; }

		var body = document.body,
		    docEl = document.documentElement,
		    top = body.scrollTop || docEl.scrollTop,
		    left = body.scrollLeft || docEl.scrollLeft;

		this._map._container.focus();

		window.scrollTo(left, top);
	},

	_onFocus: function () {
		this._focused = true;
		this._map.fire('focus');
	},

	_onBlur: function () {
		this._focused = false;
		this._map.fire('blur');
	},

	_setPanDelta: function (panDelta) {
		var keys = this._panKeys = {},
		    codes = this.keyCodes,
		    i, len;

		for (i = 0, len = codes.left.length; i < len; i++) {
			keys[codes.left[i]] = [-1 * panDelta, 0];
		}
		for (i = 0, len = codes.right.length; i < len; i++) {
			keys[codes.right[i]] = [panDelta, 0];
		}
		for (i = 0, len = codes.down.length; i < len; i++) {
			keys[codes.down[i]] = [0, panDelta];
		}
		for (i = 0, len = codes.up.length; i < len; i++) {
			keys[codes.up[i]] = [0, -1 * panDelta];
		}
	},

	_setZoomDelta: function (zoomDelta) {
		var keys = this._zoomKeys = {},
		    codes = this.keyCodes,
		    i, len;

		for (i = 0, len = codes.zoomIn.length; i < len; i++) {
			keys[codes.zoomIn[i]] = zoomDelta;
		}
		for (i = 0, len = codes.zoomOut.length; i < len; i++) {
			keys[codes.zoomOut[i]] = -zoomDelta;
		}
	},

	_addHooks: function () {
		on(document, 'keydown', this._onKeyDown, this);
	},

	_removeHooks: function () {
		off(document, 'keydown', this._onKeyDown, this);
	},

	_onKeyDown: function (e) {
		if (e.altKey || e.ctrlKey || e.metaKey) { return; }

		var key = e.keyCode,
		    map = this._map,
		    offset;

		if (key in this._panKeys) {
			if (!map._panAnim || !map._panAnim._inProgress) {
				offset = this._panKeys[key];
				if (e.shiftKey) {
					offset = toPoint(offset).multiplyBy(3);
				}

				map.panBy(offset);

				if (map.options.maxBounds) {
					map.panInsideBounds(map.options.maxBounds);
				}
			}
		} else if (key in this._zoomKeys) {
			map.setZoom(map.getZoom() + (e.shiftKey ? 3 : 1) * this._zoomKeys[key]);

		} else if (key === 27 && map._popup && map._popup.options.closeOnEscapeKey) {
			map.closePopup();

		} else {
			return;
		}

		stop(e);
	}
});

// @section Handlers
// @section Handlers
// @property keyboard: Handler
// Keyboard navigation handler.
Map$1.addInitHook('addHandler', 'keyboard', Keyboard);

/*
 * L.Handler.ScrollWheelZoom is used by L.Map to enable mouse scroll wheel zoom on the map.
 */

// @namespace Map
// @section Interaction Options
Map$1.mergeOptions({
	// @section Mousewheel options
	// @option scrollWheelZoom: Boolean|String = true
	// Whether the map can be zoomed by using the mouse wheel. If passed `'center'`,
	// it will zoom to the center of the view regardless of where the mouse was.
	scrollWheelZoom: true,

	// @option wheelDebounceTime: Number = 40
	// Limits the rate at which a wheel can fire (in milliseconds). By default
	// user can't zoom via wheel more often than once per 40 ms.
	wheelDebounceTime: 40,

	// @option wheelPxPerZoomLevel: Number = 60
	// How many scroll pixels (as reported by [L.DomEvent.getWheelDelta](#domevent-getwheeldelta))
	// mean a change of one full zoom level. Smaller values will make wheel-zooming
	// faster (and vice versa).
	wheelPxPerZoomLevel: 60
});

var ScrollWheelZoom = Handler.extend({
	addHooks: function () {
		on(this._map._container, 'mousewheel', this._onWheelScroll, this);

		this._delta = 0;
	},

	removeHooks: function () {
		off(this._map._container, 'mousewheel', this._onWheelScroll, this);
	},

	_onWheelScroll: function (e) {
		var delta = getWheelDelta(e);

		var debounce = this._map.options.wheelDebounceTime;

		this._delta += delta;
		this._lastMousePos = this._map.mouseEventToContainerPoint(e);

		if (!this._startTime) {
			this._startTime = +new Date();
		}

		var left = Math.max(debounce - (+new Date() - this._startTime), 0);

		clearTimeout(this._timer);
		this._timer = setTimeout(bind(this._performZoom, this), left);

		stop(e);
	},

	_performZoom: function () {
		var map = this._map,
		    zoom = map.getZoom(),
		    snap = this._map.options.zoomSnap || 0;

		map._stop(); // stop panning and fly animations if any

		// map the delta with a sigmoid function to -4..4 range leaning on -1..1
		var d2 = this._delta / (this._map.options.wheelPxPerZoomLevel * 4),
		    d3 = 4 * Math.log(2 / (1 + Math.exp(-Math.abs(d2)))) / Math.LN2,
		    d4 = snap ? Math.ceil(d3 / snap) * snap : d3,
		    delta = map._limitZoom(zoom + (this._delta > 0 ? d4 : -d4)) - zoom;

		this._delta = 0;
		this._startTime = null;

		if (!delta) { return; }

		if (map.options.scrollWheelZoom === 'center') {
			map.setZoom(zoom + delta);
		} else {
			map.setZoomAround(this._lastMousePos, zoom + delta);
		}
	}
});

// @section Handlers
// @property scrollWheelZoom: Handler
// Scroll wheel zoom handler.
Map$1.addInitHook('addHandler', 'scrollWheelZoom', ScrollWheelZoom);

/*
 * L.Map.Tap is used to enable mobile hacks like quick taps and long hold.
 */

// @namespace Map
// @section Interaction Options
Map$1.mergeOptions({
	// @section Touch interaction options
	// @option tap: Boolean = true
	// Enables mobile hacks for supporting instant taps (fixing 200ms click
	// delay on iOS/Android) and touch holds (fired as `contextmenu` events).
	tap: true,

	// @option tapTolerance: Number = 15
	// The max number of pixels a user can shift his finger during touch
	// for it to be considered a valid tap.
	tapTolerance: 15
});

var Tap = Handler.extend({
	addHooks: function () {
		on(this._map._container, 'touchstart', this._onDown, this);
	},

	removeHooks: function () {
		off(this._map._container, 'touchstart', this._onDown, this);
	},

	_onDown: function (e) {
		if (!e.touches) { return; }

		preventDefault(e);

		this._fireClick = true;

		// don't simulate click or track longpress if more than 1 touch
		if (e.touches.length > 1) {
			this._fireClick = false;
			clearTimeout(this._holdTimeout);
			return;
		}

		var first = e.touches[0],
		    el = first.target;

		this._startPos = this._newPos = new Point(first.clientX, first.clientY);

		// if touching a link, highlight it
		if (el.tagName && el.tagName.toLowerCase() === 'a') {
			addClass(el, 'leaflet-active');
		}

		// simulate long hold but setting a timeout
		this._holdTimeout = setTimeout(bind(function () {
			if (this._isTapValid()) {
				this._fireClick = false;
				this._onUp();
				this._simulateEvent('contextmenu', first);
			}
		}, this), 1000);

		this._simulateEvent('mousedown', first);

		on(document, {
			touchmove: this._onMove,
			touchend: this._onUp
		}, this);
	},

	_onUp: function (e) {
		clearTimeout(this._holdTimeout);

		off(document, {
			touchmove: this._onMove,
			touchend: this._onUp
		}, this);

		if (this._fireClick && e && e.changedTouches) {

			var first = e.changedTouches[0],
			    el = first.target;

			if (el && el.tagName && el.tagName.toLowerCase() === 'a') {
				removeClass(el, 'leaflet-active');
			}

			this._simulateEvent('mouseup', first);

			// simulate click if the touch didn't move too much
			if (this._isTapValid()) {
				this._simulateEvent('click', first);
			}
		}
	},

	_isTapValid: function () {
		return this._newPos.distanceTo(this._startPos) <= this._map.options.tapTolerance;
	},

	_onMove: function (e) {
		var first = e.touches[0];
		this._newPos = new Point(first.clientX, first.clientY);
		this._simulateEvent('mousemove', first);
	},

	_simulateEvent: function (type, e) {
		var simulatedEvent = document.createEvent('MouseEvents');

		simulatedEvent._simulated = true;
		e.target._simulatedClick = true;

		simulatedEvent.initMouseEvent(
		        type, true, true, window, 1,
		        e.screenX, e.screenY,
		        e.clientX, e.clientY,
		        false, false, false, false, 0, null);

		e.target.dispatchEvent(simulatedEvent);
	}
});

// @section Handlers
// @property tap: Handler
// Mobile touch hacks (quick tap and touch hold) handler.
if (touch && !pointer) {
	Map$1.addInitHook('addHandler', 'tap', Tap);
}

/*
 * L.Handler.TouchZoom is used by L.Map to add pinch zoom on supported mobile browsers.
 */

// @namespace Map
// @section Interaction Options
Map$1.mergeOptions({
	// @section Touch interaction options
	// @option touchZoom: Boolean|String = *
	// Whether the map can be zoomed by touch-dragging with two fingers. If
	// passed `'center'`, it will zoom to the center of the view regardless of
	// where the touch events (fingers) were. Enabled for touch-capable web
	// browsers except for old Androids.
	touchZoom: touch && !android23,

	// @option bounceAtZoomLimits: Boolean = true
	// Set it to false if you don't want the map to zoom beyond min/max zoom
	// and then bounce back when pinch-zooming.
	bounceAtZoomLimits: true
});

var TouchZoom = Handler.extend({
	addHooks: function () {
		addClass(this._map._container, 'leaflet-touch-zoom');
		on(this._map._container, 'touchstart', this._onTouchStart, this);
	},

	removeHooks: function () {
		removeClass(this._map._container, 'leaflet-touch-zoom');
		off(this._map._container, 'touchstart', this._onTouchStart, this);
	},

	_onTouchStart: function (e) {
		var map = this._map;
		if (!e.touches || e.touches.length !== 2 || map._animatingZoom || this._zooming) { return; }

		var p1 = map.mouseEventToContainerPoint(e.touches[0]),
		    p2 = map.mouseEventToContainerPoint(e.touches[1]);

		this._centerPoint = map.getSize()._divideBy(2);
		this._startLatLng = map.containerPointToLatLng(this._centerPoint);
		if (map.options.touchZoom !== 'center') {
			this._pinchStartLatLng = map.containerPointToLatLng(p1.add(p2)._divideBy(2));
		}

		this._startDist = p1.distanceTo(p2);
		this._startZoom = map.getZoom();

		this._moved = false;
		this._zooming = true;

		map._stop();

		on(document, 'touchmove', this._onTouchMove, this);
		on(document, 'touchend', this._onTouchEnd, this);

		preventDefault(e);
	},

	_onTouchMove: function (e) {
		if (!e.touches || e.touches.length !== 2 || !this._zooming) { return; }

		var map = this._map,
		    p1 = map.mouseEventToContainerPoint(e.touches[0]),
		    p2 = map.mouseEventToContainerPoint(e.touches[1]),
		    scale = p1.distanceTo(p2) / this._startDist;

		this._zoom = map.getScaleZoom(scale, this._startZoom);

		if (!map.options.bounceAtZoomLimits && (
			(this._zoom < map.getMinZoom() && scale < 1) ||
			(this._zoom > map.getMaxZoom() && scale > 1))) {
			this._zoom = map._limitZoom(this._zoom);
		}

		if (map.options.touchZoom === 'center') {
			this._center = this._startLatLng;
			if (scale === 1) { return; }
		} else {
			// Get delta from pinch to center, so centerLatLng is delta applied to initial pinchLatLng
			var delta = p1._add(p2)._divideBy(2)._subtract(this._centerPoint);
			if (scale === 1 && delta.x === 0 && delta.y === 0) { return; }
			this._center = map.unproject(map.project(this._pinchStartLatLng, this._zoom).subtract(delta), this._zoom);
		}

		if (!this._moved) {
			map._moveStart(true, false);
			this._moved = true;
		}

		cancelAnimFrame(this._animRequest);

		var moveFn = bind(map._move, map, this._center, this._zoom, {pinch: true, round: false});
		this._animRequest = requestAnimFrame(moveFn, this, true);

		preventDefault(e);
	},

	_onTouchEnd: function () {
		if (!this._moved || !this._zooming) {
			this._zooming = false;
			return;
		}

		this._zooming = false;
		cancelAnimFrame(this._animRequest);

		off(document, 'touchmove', this._onTouchMove);
		off(document, 'touchend', this._onTouchEnd);

		// Pinch updates GridLayers' levels only when zoomSnap is off, so zoomSnap becomes noUpdate.
		if (this._map.options.zoomAnimation) {
			this._map._animateZoom(this._center, this._map._limitZoom(this._zoom), true, this._map.options.zoomSnap);
		} else {
			this._map._resetView(this._center, this._map._limitZoom(this._zoom));
		}
	}
});

// @section Handlers
// @property touchZoom: Handler
// Touch zoom handler.
Map$1.addInitHook('addHandler', 'touchZoom', TouchZoom);

Map$1.BoxZoom = BoxZoom;
Map$1.DoubleClickZoom = DoubleClickZoom;
Map$1.Drag = Drag;
Map$1.Keyboard = Keyboard;
Map$1.ScrollWheelZoom = ScrollWheelZoom;
Map$1.Tap = Tap;
Map$1.TouchZoom = TouchZoom;

/*
 * @class Layer
 * @inherits Evented
 * @aka L.Layer
 * @aka ILayer
 *
 * A set of methods from the Layer base class that all Leaflet layers use.
 * Inherits all methods, options and events from `L.Evented`.
 *
 * @example
 *
 * ```js
 * var layer = L.marker(latlng).addTo(map);
 * layer.addTo(map);
 * layer.remove();
 * ```
 *
 * @event add: Event
 * Fired after the layer is added to a map
 *
 * @event remove: Event
 * Fired after the layer is removed from a map
 */


var Layer = Evented.extend({

	// Classes extending `L.Layer` will inherit the following options:
	options: {
		// @option pane: String = 'overlayPane'
		// By default the layer will be added to the map's [overlay pane](#map-overlaypane). Overriding this option will cause the layer to be placed on another pane by default.
		pane: 'overlayPane',

		// @option attribution: String = null
		// String to be shown in the attribution control, e.g. "© OpenStreetMap contributors". It describes the layer data and is often a legal obligation towards copyright holders and tile providers.
		attribution: null,

		bubblingMouseEvents: true
	},

	/* @section
	 * Classes extending `L.Layer` will inherit the following methods:
	 *
	 * @method addTo(map: Map|LayerGroup): this
	 * Adds the layer to the given map or layer group.
	 */
	addTo: function (map) {
		map.addLayer(this);
		return this;
	},

	// @method remove: this
	// Removes the layer from the map it is currently active on.
	remove: function () {
		return this.removeFrom(this._map || this._mapToAdd);
	},

	// @method removeFrom(map: Map): this
	// Removes the layer from the given map
	removeFrom: function (obj) {
		if (obj) {
			obj.removeLayer(this);
		}
		return this;
	},

	// @method getPane(name? : String): HTMLElement
	// Returns the `HTMLElement` representing the named pane on the map. If `name` is omitted, returns the pane for this layer.
	getPane: function (name) {
		return this._map.getPane(name ? (this.options[name] || name) : this.options.pane);
	},

	addInteractiveTarget: function (targetEl) {
		this._map._targets[stamp$1(targetEl)] = this;
		return this;
	},

	removeInteractiveTarget: function (targetEl) {
		delete this._map._targets[stamp$1(targetEl)];
		return this;
	},

	// @method getAttribution: String
	// Used by the `attribution control`, returns the [attribution option](#gridlayer-attribution).
	getAttribution: function () {
		return this.options.attribution;
	},

	_layerAdd: function (e) {
		var map = e.target;

		// check in case layer gets added and then removed before the map is ready
		if (!map.hasLayer(this)) { return; }

		this._map = map;
		this._zoomAnimated = map._zoomAnimated;

		if (this.getEvents) {
			var events = this.getEvents();
			map.on(events, this);
			this.once('remove', function () {
				map.off(events, this);
			}, this);
		}

		this.onAdd(map);

		if (this.getAttribution && map.attributionControl) {
			map.attributionControl.addAttribution(this.getAttribution());
		}

		this.fire('add');
		map.fire('layeradd', {layer: this});
	}
});

/* @section Extension methods
 * @uninheritable
 *
 * Every layer should extend from `L.Layer` and (re-)implement the following methods.
 *
 * @method onAdd(map: Map): this
 * Should contain code that creates DOM elements for the layer, adds them to `map panes` where they should belong and puts listeners on relevant map events. Called on [`map.addLayer(layer)`](#map-addlayer).
 *
 * @method onRemove(map: Map): this
 * Should contain all clean up code that removes the layer's elements from the DOM and removes listeners previously added in [`onAdd`](#layer-onadd). Called on [`map.removeLayer(layer)`](#map-removelayer).
 *
 * @method getEvents(): Object
 * This optional method should return an object like `{ viewreset: this._reset }` for [`addEventListener`](#evented-addeventlistener). The event handlers in this object will be automatically added and removed from the map with your layer.
 *
 * @method getAttribution(): String
 * This optional method should return a string containing HTML to be shown on the `Attribution control` whenever the layer is visible.
 *
 * @method beforeAdd(map: Map): this
 * Optional method. Called on [`map.addLayer(layer)`](#map-addlayer), before the layer is added to the map, before events are initialized, without waiting until the map is in a usable state. Use for early initialization only.
 */


/* @namespace Map
 * @section Layer events
 *
 * @event layeradd: LayerEvent
 * Fired when a new layer is added to the map.
 *
 * @event layerremove: LayerEvent
 * Fired when some layer is removed from the map
 *
 * @section Methods for Layers and Controls
 */
Map$1.include({
	// @method addLayer(layer: Layer): this
	// Adds the given layer to the map
	addLayer: function (layer) {
		if (!layer._layerAdd) {
			throw new Error('The provided object is not a Layer.');
		}

		var id = stamp$1(layer);
		if (this._layers[id]) { return this; }
		this._layers[id] = layer;

		layer._mapToAdd = this;

		if (layer.beforeAdd) {
			layer.beforeAdd(this);
		}

		this.whenReady(layer._layerAdd, layer);

		return this;
	},

	// @method removeLayer(layer: Layer): this
	// Removes the given layer from the map.
	removeLayer: function (layer) {
		var id = stamp$1(layer);

		if (!this._layers[id]) { return this; }

		if (this._loaded) {
			layer.onRemove(this);
		}

		if (layer.getAttribution && this.attributionControl) {
			this.attributionControl.removeAttribution(layer.getAttribution());
		}

		delete this._layers[id];

		if (this._loaded) {
			this.fire('layerremove', {layer: layer});
			layer.fire('remove');
		}

		layer._map = layer._mapToAdd = null;

		return this;
	},

	// @method hasLayer(layer: Layer): Boolean
	// Returns `true` if the given layer is currently added to the map
	hasLayer: function (layer) {
		return !!layer && (stamp$1(layer) in this._layers);
	},

	/* @method eachLayer(fn: Function, context?: Object): this
	 * Iterates over the layers of the map, optionally specifying context of the iterator function.
	 * ```
	 * map.eachLayer(function(layer){
	 *     layer.bindPopup('Hello');
	 * });
	 * ```
	 */
	eachLayer: function (method, context) {
		for (var i in this._layers) {
			method.call(context, this._layers[i]);
		}
		return this;
	},

	_addLayers: function (layers) {
		layers = layers ? (isArray(layers) ? layers : [layers]) : [];

		for (var i = 0, len = layers.length; i < len; i++) {
			this.addLayer(layers[i]);
		}
	},

	_addZoomLimit: function (layer) {
		if (isNaN(layer.options.maxZoom) || !isNaN(layer.options.minZoom)) {
			this._zoomBoundLayers[stamp$1(layer)] = layer;
			this._updateZoomLevels();
		}
	},

	_removeZoomLimit: function (layer) {
		var id = stamp$1(layer);

		if (this._zoomBoundLayers[id]) {
			delete this._zoomBoundLayers[id];
			this._updateZoomLevels();
		}
	},

	_updateZoomLevels: function () {
		var minZoom = Infinity,
		    maxZoom = -Infinity,
		    oldZoomSpan = this._getZoomSpan();

		for (var i in this._zoomBoundLayers) {
			var options = this._zoomBoundLayers[i].options;

			minZoom = options.minZoom === undefined ? minZoom : Math.min(minZoom, options.minZoom);
			maxZoom = options.maxZoom === undefined ? maxZoom : Math.max(maxZoom, options.maxZoom);
		}

		this._layersMaxZoom = maxZoom === -Infinity ? undefined : maxZoom;
		this._layersMinZoom = minZoom === Infinity ? undefined : minZoom;

		// @section Map state change events
		// @event zoomlevelschange: Event
		// Fired when the number of zoomlevels on the map is changed due
		// to adding or removing a layer.
		if (oldZoomSpan !== this._getZoomSpan()) {
			this.fire('zoomlevelschange');
		}

		if (this.options.maxZoom === undefined && this._layersMaxZoom && this.getZoom() > this._layersMaxZoom) {
			this.setZoom(this._layersMaxZoom);
		}
		if (this.options.minZoom === undefined && this._layersMinZoom && this.getZoom() < this._layersMinZoom) {
			this.setZoom(this._layersMinZoom);
		}
	}
});

/*
 * @class GridLayer
 * @inherits Layer
 * @aka L.GridLayer
 *
 * Generic class for handling a tiled grid of HTML elements. This is the base class for all tile layers and replaces `TileLayer.Canvas`.
 * GridLayer can be extended to create a tiled grid of HTML elements like `<canvas>`, `<img>` or `<div>`. GridLayer will handle creating and animating these DOM elements for you.
 *
 *
 * @section Synchronous usage
 * @example
 *
 * To create a custom layer, extend GridLayer and implement the `createTile()` method, which will be passed a `Point` object with the `x`, `y`, and `z` (zoom level) coordinates to draw your tile.
 *
 * ```js
 * var CanvasLayer = L.GridLayer.extend({
 *     createTile: function(coords){
 *         // create a <canvas> element for drawing
 *         var tile = L.DomUtil.create('canvas', 'leaflet-tile');
 *
 *         // setup tile width and height according to the options
 *         var size = this.getTileSize();
 *         tile.width = size.x;
 *         tile.height = size.y;
 *
 *         // get a canvas context and draw something on it using coords.x, coords.y and coords.z
 *         var ctx = tile.getContext('2d');
 *
 *         // return the tile so it can be rendered on screen
 *         return tile;
 *     }
 * });
 * ```
 *
 * @section Asynchronous usage
 * @example
 *
 * Tile creation can also be asynchronous, this is useful when using a third-party drawing library. Once the tile is finished drawing it can be passed to the `done()` callback.
 *
 * ```js
 * var CanvasLayer = L.GridLayer.extend({
 *     createTile: function(coords, done){
 *         var error;
 *
 *         // create a <canvas> element for drawing
 *         var tile = L.DomUtil.create('canvas', 'leaflet-tile');
 *
 *         // setup tile width and height according to the options
 *         var size = this.getTileSize();
 *         tile.width = size.x;
 *         tile.height = size.y;
 *
 *         // draw something asynchronously and pass the tile to the done() callback
 *         setTimeout(function() {
 *             done(error, tile);
 *         }, 1000);
 *
 *         return tile;
 *     }
 * });
 * ```
 *
 * @section
 */


var GridLayer = Layer.extend({

	// @section
	// @aka GridLayer options
	options: {
		// @option tileSize: Number|Point = 256
		// Width and height of tiles in the grid. Use a number if width and height are equal, or `L.point(width, height)` otherwise.
		tileSize: 256,

		// @option opacity: Number = 1.0
		// Opacity of the tiles. Can be used in the `createTile()` function.
		opacity: 1,

		// @option updateWhenIdle: Boolean = (depends)
		// Load new tiles only when panning ends.
		// `true` by default on mobile browsers, in order to avoid too many requests and keep smooth navigation.
		// `false` otherwise in order to display new tiles _during_ panning, since it is easy to pan outside the
		// [`keepBuffer`](#gridlayer-keepbuffer) option in desktop browsers.
		updateWhenIdle: mobile,

		// @option updateWhenZooming: Boolean = true
		// By default, a smooth zoom animation (during a [touch zoom](#map-touchzoom) or a [`flyTo()`](#map-flyto)) will update grid layers every integer zoom level. Setting this option to `false` will update the grid layer only when the smooth animation ends.
		updateWhenZooming: true,

		// @option updateInterval: Number = 200
		// Tiles will not update more than once every `updateInterval` milliseconds when panning.
		updateInterval: 200,

		// @option zIndex: Number = 1
		// The explicit zIndex of the tile layer.
		zIndex: 1,

		// @option bounds: LatLngBounds = undefined
		// If set, tiles will only be loaded inside the set `LatLngBounds`.
		bounds: null,

		// @option minZoom: Number = 0
		// The minimum zoom level down to which this layer will be displayed (inclusive).
		minZoom: 0,

		// @option maxZoom: Number = undefined
		// The maximum zoom level up to which this layer will be displayed (inclusive).
		maxZoom: undefined,

		// @option maxNativeZoom: Number = undefined
		// Maximum zoom number the tile source has available. If it is specified,
		// the tiles on all zoom levels higher than `maxNativeZoom` will be loaded
		// from `maxNativeZoom` level and auto-scaled.
		maxNativeZoom: undefined,

		// @option minNativeZoom: Number = undefined
		// Minimum zoom number the tile source has available. If it is specified,
		// the tiles on all zoom levels lower than `minNativeZoom` will be loaded
		// from `minNativeZoom` level and auto-scaled.
		minNativeZoom: undefined,

		// @option noWrap: Boolean = false
		// Whether the layer is wrapped around the antimeridian. If `true`, the
		// GridLayer will only be displayed once at low zoom levels. Has no
		// effect when the [map CRS](#map-crs) doesn't wrap around. Can be used
		// in combination with [`bounds`](#gridlayer-bounds) to prevent requesting
		// tiles outside the CRS limits.
		noWrap: false,

		// @option pane: String = 'tilePane'
		// `Map pane` where the grid layer will be added.
		pane: 'tilePane',

		// @option className: String = ''
		// A custom class name to assign to the tile layer. Empty by default.
		className: '',

		// @option keepBuffer: Number = 2
		// When panning the map, keep this many rows and columns of tiles before unloading them.
		keepBuffer: 2
	},

	initialize: function (options) {
		setOptions$1(this, options);
	},

	onAdd: function () {
		this._initContainer();

		this._levels = {};
		this._tiles = {};

		this._resetView();
		this._update();
	},

	beforeAdd: function (map) {
		map._addZoomLimit(this);
	},

	onRemove: function (map) {
		this._removeAllTiles();
		remove(this._container);
		map._removeZoomLimit(this);
		this._container = null;
		this._tileZoom = undefined;
	},

	// @method bringToFront: this
	// Brings the tile layer to the top of all tile layers.
	bringToFront: function () {
		if (this._map) {
			toFront(this._container);
			this._setAutoZIndex(Math.max);
		}
		return this;
	},

	// @method bringToBack: this
	// Brings the tile layer to the bottom of all tile layers.
	bringToBack: function () {
		if (this._map) {
			toBack(this._container);
			this._setAutoZIndex(Math.min);
		}
		return this;
	},

	// @method getContainer: HTMLElement
	// Returns the HTML element that contains the tiles for this layer.
	getContainer: function () {
		return this._container;
	},

	// @method setOpacity(opacity: Number): this
	// Changes the [opacity](#gridlayer-opacity) of the grid layer.
	setOpacity: function (opacity) {
		this.options.opacity = opacity;
		this._updateOpacity();
		return this;
	},

	// @method setZIndex(zIndex: Number): this
	// Changes the [zIndex](#gridlayer-zindex) of the grid layer.
	setZIndex: function (zIndex) {
		this.options.zIndex = zIndex;
		this._updateZIndex();

		return this;
	},

	// @method isLoading: Boolean
	// Returns `true` if any tile in the grid layer has not finished loading.
	isLoading: function () {
		return this._loading;
	},

	// @method redraw: this
	// Causes the layer to clear all the tiles and request them again.
	redraw: function () {
		if (this._map) {
			this._removeAllTiles();
			this._update();
		}
		return this;
	},

	getEvents: function () {
		var events = {
			viewprereset: this._invalidateAll,
			viewreset: this._resetView,
			zoom: this._resetView,
			moveend: this._onMoveEnd
		};

		if (!this.options.updateWhenIdle) {
			// update tiles on move, but not more often than once per given interval
			if (!this._onMove) {
				this._onMove = throttle(this._onMoveEnd, this.options.updateInterval, this);
			}

			events.move = this._onMove;
		}

		if (this._zoomAnimated) {
			events.zoomanim = this._animateZoom;
		}

		return events;
	},

	// @section Extension methods
	// Layers extending `GridLayer` shall reimplement the following method.
	// @method createTile(coords: Object, done?: Function): HTMLElement
	// Called only internally, must be overridden by classes extending `GridLayer`.
	// Returns the `HTMLElement` corresponding to the given `coords`. If the `done` callback
	// is specified, it must be called when the tile has finished loading and drawing.
	createTile: function () {
		return document.createElement('div');
	},

	// @section
	// @method getTileSize: Point
	// Normalizes the [tileSize option](#gridlayer-tilesize) into a point. Used by the `createTile()` method.
	getTileSize: function () {
		var s = this.options.tileSize;
		return s instanceof Point ? s : new Point(s, s);
	},

	_updateZIndex: function () {
		if (this._container && this.options.zIndex !== undefined && this.options.zIndex !== null) {
			this._container.style.zIndex = this.options.zIndex;
		}
	},

	_setAutoZIndex: function (compare) {
		// go through all other layers of the same pane, set zIndex to max + 1 (front) or min - 1 (back)

		var layers = this.getPane().children,
		    edgeZIndex = -compare(-Infinity, Infinity); // -Infinity for max, Infinity for min

		for (var i = 0, len = layers.length, zIndex; i < len; i++) {

			zIndex = layers[i].style.zIndex;

			if (layers[i] !== this._container && zIndex) {
				edgeZIndex = compare(edgeZIndex, +zIndex);
			}
		}

		if (isFinite(edgeZIndex)) {
			this.options.zIndex = edgeZIndex + compare(-1, 1);
			this._updateZIndex();
		}
	},

	_updateOpacity: function () {
		if (!this._map) { return; }

		// IE doesn't inherit filter opacity properly, so we're forced to set it on tiles
		if (ielt9) { return; }

		setOpacity(this._container, this.options.opacity);

		var now = +new Date(),
		    nextFrame = false,
		    willPrune = false;

		for (var key in this._tiles) {
			var tile = this._tiles[key];
			if (!tile.current || !tile.loaded) { continue; }

			var fade = Math.min(1, (now - tile.loaded) / 200);

			setOpacity(tile.el, fade);
			if (fade < 1) {
				nextFrame = true;
			} else {
				if (tile.active) {
					willPrune = true;
				} else {
					this._onOpaqueTile(tile);
				}
				tile.active = true;
			}
		}

		if (willPrune && !this._noPrune) { this._pruneTiles(); }

		if (nextFrame) {
			cancelAnimFrame(this._fadeFrame);
			this._fadeFrame = requestAnimFrame(this._updateOpacity, this);
		}
	},

	_onOpaqueTile: falseFn,

	_initContainer: function () {
		if (this._container) { return; }

		this._container = create$1('div', 'leaflet-layer ' + (this.options.className || ''));
		this._updateZIndex();

		if (this.options.opacity < 1) {
			this._updateOpacity();
		}

		this.getPane().appendChild(this._container);
	},

	_updateLevels: function () {

		var zoom = this._tileZoom,
		    maxZoom = this.options.maxZoom;

		if (zoom === undefined) { return undefined; }

		for (var z in this._levels) {
			if (this._levels[z].el.children.length || z === zoom) {
				this._levels[z].el.style.zIndex = maxZoom - Math.abs(zoom - z);
				this._onUpdateLevel(z);
			} else {
				remove(this._levels[z].el);
				this._removeTilesAtZoom(z);
				this._onRemoveLevel(z);
				delete this._levels[z];
			}
		}

		var level = this._levels[zoom],
		    map = this._map;

		if (!level) {
			level = this._levels[zoom] = {};

			level.el = create$1('div', 'leaflet-tile-container leaflet-zoom-animated', this._container);
			level.el.style.zIndex = maxZoom;

			level.origin = map.project(map.unproject(map.getPixelOrigin()), zoom).round();
			level.zoom = zoom;

			this._setZoomTransform(level, map.getCenter(), map.getZoom());

			// force the browser to consider the newly added element for transition
			falseFn(level.el.offsetWidth);

			this._onCreateLevel(level);
		}

		this._level = level;

		return level;
	},

	_onUpdateLevel: falseFn,

	_onRemoveLevel: falseFn,

	_onCreateLevel: falseFn,

	_pruneTiles: function () {
		if (!this._map) {
			return;
		}

		var key, tile;

		var zoom = this._map.getZoom();
		if (zoom > this.options.maxZoom ||
			zoom < this.options.minZoom) {
			this._removeAllTiles();
			return;
		}

		for (key in this._tiles) {
			tile = this._tiles[key];
			tile.retain = tile.current;
		}

		for (key in this._tiles) {
			tile = this._tiles[key];
			if (tile.current && !tile.active) {
				var coords = tile.coords;
				if (!this._retainParent(coords.x, coords.y, coords.z, coords.z - 5)) {
					this._retainChildren(coords.x, coords.y, coords.z, coords.z + 2);
				}
			}
		}

		for (key in this._tiles) {
			if (!this._tiles[key].retain) {
				this._removeTile(key);
			}
		}
	},

	_removeTilesAtZoom: function (zoom) {
		for (var key in this._tiles) {
			if (this._tiles[key].coords.z !== zoom) {
				continue;
			}
			this._removeTile(key);
		}
	},

	_removeAllTiles: function () {
		for (var key in this._tiles) {
			this._removeTile(key);
		}
	},

	_invalidateAll: function () {
		for (var z in this._levels) {
			remove(this._levels[z].el);
			this._onRemoveLevel(z);
			delete this._levels[z];
		}
		this._removeAllTiles();

		this._tileZoom = undefined;
	},

	_retainParent: function (x, y, z, minZoom) {
		var x2 = Math.floor(x / 2),
		    y2 = Math.floor(y / 2),
		    z2 = z - 1,
		    coords2 = new Point(+x2, +y2);
		coords2.z = +z2;

		var key = this._tileCoordsToKey(coords2),
		    tile = this._tiles[key];

		if (tile && tile.active) {
			tile.retain = true;
			return true;

		} else if (tile && tile.loaded) {
			tile.retain = true;
		}

		if (z2 > minZoom) {
			return this._retainParent(x2, y2, z2, minZoom);
		}

		return false;
	},

	_retainChildren: function (x, y, z, maxZoom) {

		for (var i = 2 * x; i < 2 * x + 2; i++) {
			for (var j = 2 * y; j < 2 * y + 2; j++) {

				var coords = new Point(i, j);
				coords.z = z + 1;

				var key = this._tileCoordsToKey(coords),
				    tile = this._tiles[key];

				if (tile && tile.active) {
					tile.retain = true;
					continue;

				} else if (tile && tile.loaded) {
					tile.retain = true;
				}

				if (z + 1 < maxZoom) {
					this._retainChildren(i, j, z + 1, maxZoom);
				}
			}
		}
	},

	_resetView: function (e) {
		var animating = e && (e.pinch || e.flyTo);
		this._setView(this._map.getCenter(), this._map.getZoom(), animating, animating);
	},

	_animateZoom: function (e) {
		this._setView(e.center, e.zoom, true, e.noUpdate);
	},

	_clampZoom: function (zoom) {
		var options = this.options;

		if (undefined !== options.minNativeZoom && zoom < options.minNativeZoom) {
			return options.minNativeZoom;
		}

		if (undefined !== options.maxNativeZoom && options.maxNativeZoom < zoom) {
			return options.maxNativeZoom;
		}

		return zoom;
	},

	_setView: function (center, zoom, noPrune, noUpdate) {
		var tileZoom = this._clampZoom(Math.round(zoom));
		if ((this.options.maxZoom !== undefined && tileZoom > this.options.maxZoom) ||
		    (this.options.minZoom !== undefined && tileZoom < this.options.minZoom)) {
			tileZoom = undefined;
		}

		var tileZoomChanged = this.options.updateWhenZooming && (tileZoom !== this._tileZoom);

		if (!noUpdate || tileZoomChanged) {

			this._tileZoom = tileZoom;

			if (this._abortLoading) {
				this._abortLoading();
			}

			this._updateLevels();
			this._resetGrid();

			if (tileZoom !== undefined) {
				this._update(center);
			}

			if (!noPrune) {
				this._pruneTiles();
			}

			// Flag to prevent _updateOpacity from pruning tiles during
			// a zoom anim or a pinch gesture
			this._noPrune = !!noPrune;
		}

		this._setZoomTransforms(center, zoom);
	},

	_setZoomTransforms: function (center, zoom) {
		for (var i in this._levels) {
			this._setZoomTransform(this._levels[i], center, zoom);
		}
	},

	_setZoomTransform: function (level, center, zoom) {
		var scale = this._map.getZoomScale(zoom, level.zoom),
		    translate = level.origin.multiplyBy(scale)
		        .subtract(this._map._getNewPixelOrigin(center, zoom)).round();

		if (any3d) {
			setTransform(level.el, translate, scale);
		} else {
			setPosition(level.el, translate);
		}
	},

	_resetGrid: function () {
		var map = this._map,
		    crs = map.options.crs,
		    tileSize = this._tileSize = this.getTileSize(),
		    tileZoom = this._tileZoom;

		var bounds = this._map.getPixelWorldBounds(this._tileZoom);
		if (bounds) {
			this._globalTileRange = this._pxBoundsToTileRange(bounds);
		}

		this._wrapX = crs.wrapLng && !this.options.noWrap && [
			Math.floor(map.project([0, crs.wrapLng[0]], tileZoom).x / tileSize.x),
			Math.ceil(map.project([0, crs.wrapLng[1]], tileZoom).x / tileSize.y)
		];
		this._wrapY = crs.wrapLat && !this.options.noWrap && [
			Math.floor(map.project([crs.wrapLat[0], 0], tileZoom).y / tileSize.x),
			Math.ceil(map.project([crs.wrapLat[1], 0], tileZoom).y / tileSize.y)
		];
	},

	_onMoveEnd: function () {
		if (!this._map || this._map._animatingZoom) { return; }

		this._update();
	},

	_getTiledPixelBounds: function (center) {
		var map = this._map,
		    mapZoom = map._animatingZoom ? Math.max(map._animateToZoom, map.getZoom()) : map.getZoom(),
		    scale = map.getZoomScale(mapZoom, this._tileZoom),
		    pixelCenter = map.project(center, this._tileZoom).floor(),
		    halfSize = map.getSize().divideBy(scale * 2);

		return new Bounds(pixelCenter.subtract(halfSize), pixelCenter.add(halfSize));
	},

	// Private method to load tiles in the grid's active zoom level according to map bounds
	_update: function (center) {
		var map = this._map;
		if (!map) { return; }
		var zoom = this._clampZoom(map.getZoom());

		if (center === undefined) { center = map.getCenter(); }
		if (this._tileZoom === undefined) { return; }	// if out of minzoom/maxzoom

		var pixelBounds = this._getTiledPixelBounds(center),
		    tileRange = this._pxBoundsToTileRange(pixelBounds),
		    tileCenter = tileRange.getCenter(),
		    queue = [],
		    margin = this.options.keepBuffer,
		    noPruneRange = new Bounds(tileRange.getBottomLeft().subtract([margin, -margin]),
		                              tileRange.getTopRight().add([margin, -margin]));

		// Sanity check: panic if the tile range contains Infinity somewhere.
		if (!(isFinite(tileRange.min.x) &&
		      isFinite(tileRange.min.y) &&
		      isFinite(tileRange.max.x) &&
		      isFinite(tileRange.max.y))) { throw new Error('Attempted to load an infinite number of tiles'); }

		for (var key in this._tiles) {
			var c = this._tiles[key].coords;
			if (c.z !== this._tileZoom || !noPruneRange.contains(new Point(c.x, c.y))) {
				this._tiles[key].current = false;
			}
		}

		// _update just loads more tiles. If the tile zoom level differs too much
		// from the map's, let _setView reset levels and prune old tiles.
		if (Math.abs(zoom - this._tileZoom) > 1) { this._setView(center, zoom); return; }

		// create a queue of coordinates to load tiles from
		for (var j = tileRange.min.y; j <= tileRange.max.y; j++) {
			for (var i = tileRange.min.x; i <= tileRange.max.x; i++) {
				var coords = new Point(i, j);
				coords.z = this._tileZoom;

				if (!this._isValidTile(coords)) { continue; }

				var tile = this._tiles[this._tileCoordsToKey(coords)];
				if (tile) {
					tile.current = true;
				} else {
					queue.push(coords);
				}
			}
		}

		// sort tile queue to load tiles in order of their distance to center
		queue.sort(function (a, b) {
			return a.distanceTo(tileCenter) - b.distanceTo(tileCenter);
		});

		if (queue.length !== 0) {
			// if it's the first batch of tiles to load
			if (!this._loading) {
				this._loading = true;
				// @event loading: Event
				// Fired when the grid layer starts loading tiles.
				this.fire('loading');
			}

			// create DOM fragment to append tiles in one batch
			var fragment = document.createDocumentFragment();

			for (i = 0; i < queue.length; i++) {
				this._addTile(queue[i], fragment);
			}

			this._level.el.appendChild(fragment);
		}
	},

	_isValidTile: function (coords) {
		var crs = this._map.options.crs;

		if (!crs.infinite) {
			// don't load tile if it's out of bounds and not wrapped
			var bounds = this._globalTileRange;
			if ((!crs.wrapLng && (coords.x < bounds.min.x || coords.x > bounds.max.x)) ||
			    (!crs.wrapLat && (coords.y < bounds.min.y || coords.y > bounds.max.y))) { return false; }
		}

		if (!this.options.bounds) { return true; }

		// don't load tile if it doesn't intersect the bounds in options
		var tileBounds = this._tileCoordsToBounds(coords);
		return toLatLngBounds(this.options.bounds).overlaps(tileBounds);
	},

	_keyToBounds: function (key) {
		return this._tileCoordsToBounds(this._keyToTileCoords(key));
	},

	_tileCoordsToNwSe: function (coords) {
		var map = this._map,
		    tileSize = this.getTileSize(),
		    nwPoint = coords.scaleBy(tileSize),
		    sePoint = nwPoint.add(tileSize),
		    nw = map.unproject(nwPoint, coords.z),
		    se = map.unproject(sePoint, coords.z);
		return [nw, se];
	},

	// converts tile coordinates to its geographical bounds
	_tileCoordsToBounds: function (coords) {
		var bp = this._tileCoordsToNwSe(coords),
		    bounds = new LatLngBounds(bp[0], bp[1]);

		if (!this.options.noWrap) {
			bounds = this._map.wrapLatLngBounds(bounds);
		}
		return bounds;
	},
	// converts tile coordinates to key for the tile cache
	_tileCoordsToKey: function (coords) {
		return coords.x + ':' + coords.y + ':' + coords.z;
	},

	// converts tile cache key to coordinates
	_keyToTileCoords: function (key) {
		var k = key.split(':'),
		    coords = new Point(+k[0], +k[1]);
		coords.z = +k[2];
		return coords;
	},

	_removeTile: function (key) {
		var tile = this._tiles[key];
		if (!tile) { return; }

		remove(tile.el);

		delete this._tiles[key];

		// @event tileunload: TileEvent
		// Fired when a tile is removed (e.g. when a tile goes off the screen).
		this.fire('tileunload', {
			tile: tile.el,
			coords: this._keyToTileCoords(key)
		});
	},

	_initTile: function (tile) {
		addClass(tile, 'leaflet-tile');

		var tileSize = this.getTileSize();
		tile.style.width = tileSize.x + 'px';
		tile.style.height = tileSize.y + 'px';

		tile.onselectstart = falseFn;
		tile.onmousemove = falseFn;

		// update opacity on tiles in IE7-8 because of filter inheritance problems
		if (ielt9 && this.options.opacity < 1) {
			setOpacity(tile, this.options.opacity);
		}

		// without this hack, tiles disappear after zoom on Chrome for Android
		// https://github.com/Leaflet/Leaflet/issues/2078
		if (android && !android23) {
			tile.style.WebkitBackfaceVisibility = 'hidden';
		}
	},

	_addTile: function (coords, container) {
		var tilePos = this._getTilePos(coords),
		    key = this._tileCoordsToKey(coords);

		var tile = this.createTile(this._wrapCoords(coords), bind(this._tileReady, this, coords));

		this._initTile(tile);

		// if createTile is defined with a second argument ("done" callback),
		// we know that tile is async and will be ready later; otherwise
		if (this.createTile.length < 2) {
			// mark tile as ready, but delay one frame for opacity animation to happen
			requestAnimFrame(bind(this._tileReady, this, coords, null, tile));
		}

		setPosition(tile, tilePos);

		// save tile in cache
		this._tiles[key] = {
			el: tile,
			coords: coords,
			current: true
		};

		container.appendChild(tile);
		// @event tileloadstart: TileEvent
		// Fired when a tile is requested and starts loading.
		this.fire('tileloadstart', {
			tile: tile,
			coords: coords
		});
	},

	_tileReady: function (coords, err, tile) {
		if (err) {
			// @event tileerror: TileErrorEvent
			// Fired when there is an error loading a tile.
			this.fire('tileerror', {
				error: err,
				tile: tile,
				coords: coords
			});
		}

		var key = this._tileCoordsToKey(coords);

		tile = this._tiles[key];
		if (!tile) { return; }

		tile.loaded = +new Date();
		if (this._map._fadeAnimated) {
			setOpacity(tile.el, 0);
			cancelAnimFrame(this._fadeFrame);
			this._fadeFrame = requestAnimFrame(this._updateOpacity, this);
		} else {
			tile.active = true;
			this._pruneTiles();
		}

		if (!err) {
			addClass(tile.el, 'leaflet-tile-loaded');

			// @event tileload: TileEvent
			// Fired when a tile loads.
			this.fire('tileload', {
				tile: tile.el,
				coords: coords
			});
		}

		if (this._noTilesToLoad()) {
			this._loading = false;
			// @event load: Event
			// Fired when the grid layer loaded all visible tiles.
			this.fire('load');

			if (ielt9 || !this._map._fadeAnimated) {
				requestAnimFrame(this._pruneTiles, this);
			} else {
				// Wait a bit more than 0.2 secs (the duration of the tile fade-in)
				// to trigger a pruning.
				setTimeout(bind(this._pruneTiles, this), 250);
			}
		}
	},

	_getTilePos: function (coords) {
		return coords.scaleBy(this.getTileSize()).subtract(this._level.origin);
	},

	_wrapCoords: function (coords) {
		var newCoords = new Point(
			this._wrapX ? wrapNum(coords.x, this._wrapX) : coords.x,
			this._wrapY ? wrapNum(coords.y, this._wrapY) : coords.y);
		newCoords.z = coords.z;
		return newCoords;
	},

	_pxBoundsToTileRange: function (bounds) {
		var tileSize = this.getTileSize();
		return new Bounds(
			bounds.min.unscaleBy(tileSize).floor(),
			bounds.max.unscaleBy(tileSize).ceil().subtract([1, 1]));
	},

	_noTilesToLoad: function () {
		for (var key in this._tiles) {
			if (!this._tiles[key].loaded) { return false; }
		}
		return true;
	}
});

/*
 * @class TileLayer
 * @inherits GridLayer
 * @aka L.TileLayer
 * Used to load and display tile layers on the map. Note that most tile servers require attribution, which you can set under `Layer`. Extends `GridLayer`.
 *
 * @example
 *
 * ```js
 * L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png?{foo}', {foo: 'bar', attribution: 'Map data &copy; <a href="https://www.openstreetmap.org/">OpenStreetMap</a> contributors, <a href="https://creativecommons.org/licenses/by-sa/2.0/">CC-BY-SA</a>'}).addTo(map);
 * ```
 *
 * @section URL template
 * @example
 *
 * A string of the following form:
 *
 * ```
 * 'http://{s}.somedomain.com/blabla/{z}/{x}/{y}{r}.png'
 * ```
 *
 * `{s}` means one of the available subdomains (used sequentially to help with browser parallel requests per domain limitation; subdomain values are specified in options; `a`, `b` or `c` by default, can be omitted), `{z}` — zoom level, `{x}` and `{y}` — tile coordinates. `{r}` can be used to add "&commat;2x" to the URL to load retina tiles.
 *
 * You can use custom keys in the template, which will be [evaluated](#util-template) from TileLayer options, like this:
 *
 * ```
 * L.tileLayer('http://{s}.somedomain.com/{foo}/{z}/{x}/{y}.png', {foo: 'bar'});
 * ```
 */


var TileLayer = GridLayer.extend({

	// @section
	// @aka TileLayer options
	options: {
		// @option minZoom: Number = 0
		// The minimum zoom level down to which this layer will be displayed (inclusive).
		minZoom: 0,

		// @option maxZoom: Number = 18
		// The maximum zoom level up to which this layer will be displayed (inclusive).
		maxZoom: 18,

		// @option subdomains: String|String[] = 'abc'
		// Subdomains of the tile service. Can be passed in the form of one string (where each letter is a subdomain name) or an array of strings.
		subdomains: 'abc',

		// @option errorTileUrl: String = ''
		// URL to the tile image to show in place of the tile that failed to load.
		errorTileUrl: '',

		// @option zoomOffset: Number = 0
		// The zoom number used in tile URLs will be offset with this value.
		zoomOffset: 0,

		// @option tms: Boolean = false
		// If `true`, inverses Y axis numbering for tiles (turn this on for [TMS](https://en.wikipedia.org/wiki/Tile_Map_Service) services).
		tms: false,

		// @option zoomReverse: Boolean = false
		// If set to true, the zoom number used in tile URLs will be reversed (`maxZoom - zoom` instead of `zoom`)
		zoomReverse: false,

		// @option detectRetina: Boolean = false
		// If `true` and user is on a retina display, it will request four tiles of half the specified size and a bigger zoom level in place of one to utilize the high resolution.
		detectRetina: false,

		// @option crossOrigin: Boolean|String = false
		// Whether the crossOrigin attribute will be added to the tiles.
		// If a String is provided, all tiles will have their crossOrigin attribute set to the String provided. This is needed if you want to access tile pixel data.
		// Refer to [CORS Settings](https://developer.mozilla.org/en-US/docs/Web/HTML/CORS_settings_attributes) for valid String values.
		crossOrigin: false
	},

	initialize: function (url, options) {

		this._url = url;

		options = setOptions$1(this, options);

		// detecting retina displays, adjusting tileSize and zoom levels
		if (options.detectRetina && retina && options.maxZoom > 0) {

			options.tileSize = Math.floor(options.tileSize / 2);

			if (!options.zoomReverse) {
				options.zoomOffset++;
				options.maxZoom--;
			} else {
				options.zoomOffset--;
				options.minZoom++;
			}

			options.minZoom = Math.max(0, options.minZoom);
		}

		if (typeof options.subdomains === 'string') {
			options.subdomains = options.subdomains.split('');
		}

		// for https://github.com/Leaflet/Leaflet/issues/137
		if (!android) {
			this.on('tileunload', this._onTileRemove);
		}
	},

	// @method setUrl(url: String, noRedraw?: Boolean): this
	// Updates the layer's URL template and redraws it (unless `noRedraw` is set to `true`).
	// If the URL does not change, the layer will not be redrawn unless
	// the noRedraw parameter is set to false.
	setUrl: function (url, noRedraw) {
		if (this._url === url && noRedraw === undefined) {
			noRedraw = true;
		}

		this._url = url;

		if (!noRedraw) {
			this.redraw();
		}
		return this;
	},

	// @method createTile(coords: Object, done?: Function): HTMLElement
	// Called only internally, overrides GridLayer's [`createTile()`](#gridlayer-createtile)
	// to return an `<img>` HTML element with the appropriate image URL given `coords`. The `done`
	// callback is called when the tile has been loaded.
	createTile: function (coords, done) {
		var tile = document.createElement('img');

		on(tile, 'load', bind(this._tileOnLoad, this, done, tile));
		on(tile, 'error', bind(this._tileOnError, this, done, tile));

		if (this.options.crossOrigin || this.options.crossOrigin === '') {
			tile.crossOrigin = this.options.crossOrigin === true ? '' : this.options.crossOrigin;
		}

		/*
		 Alt tag is set to empty string to keep screen readers from reading URL and for compliance reasons
		 http://www.w3.org/TR/WCAG20-TECHS/H67
		*/
		tile.alt = '';

		/*
		 Set role="presentation" to force screen readers to ignore this
		 https://www.w3.org/TR/wai-aria/roles#textalternativecomputation
		*/
		tile.setAttribute('role', 'presentation');

		tile.src = this.getTileUrl(coords);

		return tile;
	},

	// @section Extension methods
	// @uninheritable
	// Layers extending `TileLayer` might reimplement the following method.
	// @method getTileUrl(coords: Object): String
	// Called only internally, returns the URL for a tile given its coordinates.
	// Classes extending `TileLayer` can override this function to provide custom tile URL naming schemes.
	getTileUrl: function (coords) {
		var data = {
			r: retina ? '@2x' : '',
			s: this._getSubdomain(coords),
			x: coords.x,
			y: coords.y,
			z: this._getZoomForUrl()
		};
		if (this._map && !this._map.options.crs.infinite) {
			var invertedY = this._globalTileRange.max.y - coords.y;
			if (this.options.tms) {
				data['y'] = invertedY;
			}
			data['-y'] = invertedY;
		}

		return template(this._url, extend(data, this.options));
	},

	_tileOnLoad: function (done, tile) {
		// For https://github.com/Leaflet/Leaflet/issues/3332
		if (ielt9) {
			setTimeout(bind(done, this, null, tile), 0);
		} else {
			done(null, tile);
		}
	},

	_tileOnError: function (done, tile, e) {
		var errorUrl = this.options.errorTileUrl;
		if (errorUrl && tile.getAttribute('src') !== errorUrl) {
			tile.src = errorUrl;
		}
		done(e, tile);
	},

	_onTileRemove: function (e) {
		e.tile.onload = null;
	},

	_getZoomForUrl: function () {
		var zoom = this._tileZoom,
		maxZoom = this.options.maxZoom,
		zoomReverse = this.options.zoomReverse,
		zoomOffset = this.options.zoomOffset;

		if (zoomReverse) {
			zoom = maxZoom - zoom;
		}

		return zoom + zoomOffset;
	},

	_getSubdomain: function (tilePoint) {
		var index = Math.abs(tilePoint.x + tilePoint.y) % this.options.subdomains.length;
		return this.options.subdomains[index];
	},

	// stops loading all tiles in the background layer
	_abortLoading: function () {
		var i, tile;
		for (i in this._tiles) {
			if (this._tiles[i].coords.z !== this._tileZoom) {
				tile = this._tiles[i].el;

				tile.onload = falseFn;
				tile.onerror = falseFn;

				if (!tile.complete) {
					tile.src = emptyImageUrl;
					remove(tile);
					delete this._tiles[i];
				}
			}
		}
	},

	_removeTile: function (key) {
		var tile = this._tiles[key];
		if (!tile) { return; }

		// Cancels any pending http requests associated with the tile
		// unless we're on Android's stock browser,
		// see https://github.com/Leaflet/Leaflet/issues/137
		if (!androidStock) {
			tile.el.setAttribute('src', emptyImageUrl);
		}

		return GridLayer.prototype._removeTile.call(this, key);
	},

	_tileReady: function (coords, err, tile) {
		if (!this._map || (tile && tile.getAttribute('src') === emptyImageUrl)) {
			return;
		}

		return GridLayer.prototype._tileReady.call(this, coords, err, tile);
	}
});

/*
 * @namespace Projection
 * @section
 * Leaflet comes with a set of already defined Projections out of the box:
 *
 * @projection L.Projection.LonLat
 *
 * Equirectangular, or Plate Carree projection — the most simple projection,
 * mostly used by GIS enthusiasts. Directly maps `x` as longitude, and `y` as
 * latitude. Also suitable for flat worlds, e.g. game maps. Used by the
 * `EPSG:4326` and `Simple` CRS.
 */

var LonLat = {
	project: function (latlng) {
		return new Point(latlng.lng, latlng.lat);
	},

	unproject: function (point) {
		return new LatLng(point.y, point.x);
	},

	bounds: new Bounds([-180, -90], [180, 90])
};

/*
 * @namespace CRS
 * @crs L.CRS.EPSG4326
 *
 * A common CRS among GIS enthusiasts. Uses simple Equirectangular projection.
 *
 * Leaflet 1.0.x complies with the [TMS coordinate scheme for EPSG:4326](https://wiki.osgeo.org/wiki/Tile_Map_Service_Specification#global-geodetic),
 * which is a breaking change from 0.7.x behaviour.  If you are using a `TileLayer`
 * with this CRS, ensure that there are two 256x256 pixel tiles covering the
 * whole earth at zoom level zero, and that the tile coordinate origin is (-180,+90),
 * or (-180,-90) for `TileLayer`s with [the `tms` option](#tilelayer-tms) set.
 */

var EPSG4326 = extend({}, Earth, {
	code: 'EPSG:4326',
	projection: LonLat,
	transformation: toTransformation(1 / 180, 1, -1 / 180, 0.5)
});

/*
 * @class TileLayer.WMS
 * @inherits TileLayer
 * @aka L.TileLayer.WMS
 * Used to display [WMS](https://en.wikipedia.org/wiki/Web_Map_Service) services as tile layers on the map. Extends `TileLayer`.
 *
 * @example
 *
 * ```js
 * var nexrad = L.tileLayer.wms("http://mesonet.agron.iastate.edu/cgi-bin/wms/nexrad/n0r.cgi", {
 * 	layers: 'nexrad-n0r-900913',
 * 	format: 'image/png',
 * 	transparent: true,
 * 	attribution: "Weather data © 2012 IEM Nexrad"
 * });
 * ```
 */

var TileLayerWMS = TileLayer.extend({

	// @section
	// @aka TileLayer.WMS options
	// If any custom options not documented here are used, they will be sent to the
	// WMS server as extra parameters in each request URL. This can be useful for
	// [non-standard vendor WMS parameters](http://docs.geoserver.org/stable/en/user/services/wms/vendor.html).
	defaultWmsParams: {
		service: 'WMS',
		request: 'GetMap',

		// @option layers: String = ''
		// **(required)** Comma-separated list of WMS layers to show.
		layers: '',

		// @option styles: String = ''
		// Comma-separated list of WMS styles.
		styles: '',

		// @option format: String = 'image/jpeg'
		// WMS image format (use `'image/png'` for layers with transparency).
		format: 'image/jpeg',

		// @option transparent: Boolean = false
		// If `true`, the WMS service will return images with transparency.
		transparent: false,

		// @option version: String = '1.1.1'
		// Version of the WMS service to use
		version: '1.1.1'
	},

	options: {
		// @option crs: CRS = null
		// Coordinate Reference System to use for the WMS requests, defaults to
		// map CRS. Don't change this if you're not sure what it means.
		crs: null,

		// @option uppercase: Boolean = false
		// If `true`, WMS request parameter keys will be uppercase.
		uppercase: false
	},

	initialize: function (url, options) {

		this._url = url;

		var wmsParams = extend({}, this.defaultWmsParams);

		// all keys that are not TileLayer options go to WMS params
		for (var i in options) {
			if (!(i in this.options)) {
				wmsParams[i] = options[i];
			}
		}

		options = setOptions$1(this, options);

		var realRetina = options.detectRetina && retina ? 2 : 1;
		var tileSize = this.getTileSize();
		wmsParams.width = tileSize.x * realRetina;
		wmsParams.height = tileSize.y * realRetina;

		this.wmsParams = wmsParams;
	},

	onAdd: function (map) {

		this._crs = this.options.crs || map.options.crs;
		this._wmsVersion = parseFloat(this.wmsParams.version);

		var projectionKey = this._wmsVersion >= 1.3 ? 'crs' : 'srs';
		this.wmsParams[projectionKey] = this._crs.code;

		TileLayer.prototype.onAdd.call(this, map);
	},

	getTileUrl: function (coords) {

		var tileBounds = this._tileCoordsToNwSe(coords),
		    crs = this._crs,
		    bounds = toBounds(crs.project(tileBounds[0]), crs.project(tileBounds[1])),
		    min = bounds.min,
		    max = bounds.max,
		    bbox = (this._wmsVersion >= 1.3 && this._crs === EPSG4326 ?
		    [min.y, min.x, max.y, max.x] :
		    [min.x, min.y, max.x, max.y]).join(','),
		    url = TileLayer.prototype.getTileUrl.call(this, coords);
		return url +
			getParamString(this.wmsParams, url, this.options.uppercase) +
			(this.options.uppercase ? '&BBOX=' : '&bbox=') + bbox;
	},

	// @method setParams(params: Object, noRedraw?: Boolean): this
	// Merges an object with the new parameters and re-requests tiles on the current screen (unless `noRedraw` was set to true).
	setParams: function (params, noRedraw) {

		extend(this.wmsParams, params);

		if (!noRedraw) {
			this.redraw();
		}

		return this;
	}
});

TileLayer.WMS = TileLayerWMS;

/*
 * @class Icon
 * @aka L.Icon
 *
 * Represents an icon to provide when creating a marker.
 *
 * @example
 *
 * ```js
 * var myIcon = L.icon({
 *     iconUrl: 'my-icon.png',
 *     iconRetinaUrl: 'my-icon@2x.png',
 *     iconSize: [38, 95],
 *     iconAnchor: [22, 94],
 *     popupAnchor: [-3, -76],
 *     shadowUrl: 'my-icon-shadow.png',
 *     shadowRetinaUrl: 'my-icon-shadow@2x.png',
 *     shadowSize: [68, 95],
 *     shadowAnchor: [22, 94]
 * });
 *
 * L.marker([50.505, 30.57], {icon: myIcon}).addTo(map);
 * ```
 *
 * `L.Icon.Default` extends `L.Icon` and is the blue icon Leaflet uses for markers by default.
 *
 */

var Icon = Class.extend({

	/* @section
	 * @aka Icon options
	 *
	 * @option iconUrl: String = null
	 * **(required)** The URL to the icon image (absolute or relative to your script path).
	 *
	 * @option iconRetinaUrl: String = null
	 * The URL to a retina sized version of the icon image (absolute or relative to your
	 * script path). Used for Retina screen devices.
	 *
	 * @option iconSize: Point = null
	 * Size of the icon image in pixels.
	 *
	 * @option iconAnchor: Point = null
	 * The coordinates of the "tip" of the icon (relative to its top left corner). The icon
	 * will be aligned so that this point is at the marker's geographical location. Centered
	 * by default if size is specified, also can be set in CSS with negative margins.
	 *
	 * @option popupAnchor: Point = [0, 0]
	 * The coordinates of the point from which popups will "open", relative to the icon anchor.
	 *
	 * @option tooltipAnchor: Point = [0, 0]
	 * The coordinates of the point from which tooltips will "open", relative to the icon anchor.
	 *
	 * @option shadowUrl: String = null
	 * The URL to the icon shadow image. If not specified, no shadow image will be created.
	 *
	 * @option shadowRetinaUrl: String = null
	 *
	 * @option shadowSize: Point = null
	 * Size of the shadow image in pixels.
	 *
	 * @option shadowAnchor: Point = null
	 * The coordinates of the "tip" of the shadow (relative to its top left corner) (the same
	 * as iconAnchor if not specified).
	 *
	 * @option className: String = ''
	 * A custom class name to assign to both icon and shadow images. Empty by default.
	 */

	options: {
		popupAnchor: [0, 0],
		tooltipAnchor: [0, 0]
	},

	initialize: function (options) {
		setOptions$1(this, options);
	},

	// @method createIcon(oldIcon?: HTMLElement): HTMLElement
	// Called internally when the icon has to be shown, returns a `<img>` HTML element
	// styled according to the options.
	createIcon: function (oldIcon) {
		return this._createIcon('icon', oldIcon);
	},

	// @method createShadow(oldIcon?: HTMLElement): HTMLElement
	// As `createIcon`, but for the shadow beneath it.
	createShadow: function (oldIcon) {
		return this._createIcon('shadow', oldIcon);
	},

	_createIcon: function (name, oldIcon) {
		var src = this._getIconUrl(name);

		if (!src) {
			if (name === 'icon') {
				throw new Error('iconUrl not set in Icon options (see the docs).');
			}
			return null;
		}

		var img = this._createImg(src, oldIcon && oldIcon.tagName === 'IMG' ? oldIcon : null);
		this._setIconStyles(img, name);

		return img;
	},

	_setIconStyles: function (img, name) {
		var options = this.options;
		var sizeOption = options[name + 'Size'];

		if (typeof sizeOption === 'number') {
			sizeOption = [sizeOption, sizeOption];
		}

		var size = toPoint(sizeOption),
		    anchor = toPoint(name === 'shadow' && options.shadowAnchor || options.iconAnchor ||
		            size && size.divideBy(2, true));

		img.className = 'leaflet-marker-' + name + ' ' + (options.className || '');

		if (anchor) {
			img.style.marginLeft = (-anchor.x) + 'px';
			img.style.marginTop  = (-anchor.y) + 'px';
		}

		if (size) {
			img.style.width  = size.x + 'px';
			img.style.height = size.y + 'px';
		}
	},

	_createImg: function (src, el) {
		el = el || document.createElement('img');
		el.src = src;
		return el;
	},

	_getIconUrl: function (name) {
		return retina && this.options[name + 'RetinaUrl'] || this.options[name + 'Url'];
	}
});

/*
 * @miniclass Icon.Default (Icon)
 * @aka L.Icon.Default
 * @section
 *
 * A trivial subclass of `Icon`, represents the icon to use in `Marker`s when
 * no icon is specified. Points to the blue marker image distributed with Leaflet
 * releases.
 *
 * In order to customize the default icon, just change the properties of `L.Icon.Default.prototype.options`
 * (which is a set of `Icon options`).
 *
 * If you want to _completely_ replace the default icon, override the
 * `L.Marker.prototype.options.icon` with your own icon instead.
 */

var IconDefault = Icon.extend({

	options: {
		iconUrl:       'marker-icon.png',
		iconRetinaUrl: 'marker-icon-2x.png',
		shadowUrl:     'marker-shadow.png',
		iconSize:    [25, 41],
		iconAnchor:  [12, 41],
		popupAnchor: [1, -34],
		tooltipAnchor: [16, -28],
		shadowSize:  [41, 41]
	},

	_getIconUrl: function (name) {
		if (!IconDefault.imagePath) {	// Deprecated, backwards-compatibility only
			IconDefault.imagePath = this._detectIconPath();
		}

		// @option imagePath: String
		// `Icon.Default` will try to auto-detect the location of the
		// blue icon images. If you are placing these images in a non-standard
		// way, set this option to point to the right path.
		return (this.options.imagePath || IconDefault.imagePath) + Icon.prototype._getIconUrl.call(this, name);
	},

	_detectIconPath: function () {
		var el = create$1('div',  'leaflet-default-icon-path', document.body);
		var path = getStyle(el, 'background-image') ||
		           getStyle(el, 'backgroundImage');	// IE8

		document.body.removeChild(el);

		if (path === null || path.indexOf('url') !== 0) {
			path = '';
		} else {
			path = path.replace(/^url\(["']?/, '').replace(/marker-icon\.png["']?\)$/, '');
		}

		return path;
	}
});

/*
 * @class DivIcon
 * @aka L.DivIcon
 * @inherits Icon
 *
 * Represents a lightweight icon for markers that uses a simple `<div>`
 * element instead of an image. Inherits from `Icon` but ignores the `iconUrl` and shadow options.
 *
 * @example
 * ```js
 * var myIcon = L.divIcon({className: 'my-div-icon'});
 * // you can set .my-div-icon styles in CSS
 *
 * L.marker([50.505, 30.57], {icon: myIcon}).addTo(map);
 * ```
 *
 * By default, it has a 'leaflet-div-icon' CSS class and is styled as a little white square with a shadow.
 */

var DivIcon = Icon.extend({
	options: {
		// @section
		// @aka DivIcon options
		iconSize: [12, 12], // also can be set through CSS

		// iconAnchor: (Point),
		// popupAnchor: (Point),

		// @option html: String|HTMLElement = ''
		// Custom HTML code to put inside the div element, empty by default. Alternatively,
		// an instance of `HTMLElement`.
		html: false,

		// @option bgPos: Point = [0, 0]
		// Optional relative position of the background, in pixels
		bgPos: null,

		className: 'leaflet-div-icon'
	},

	createIcon: function (oldIcon) {
		var div = (oldIcon && oldIcon.tagName === 'DIV') ? oldIcon : document.createElement('div'),
		    options = this.options;

		if (options.html instanceof Element) {
			empty(div);
			div.appendChild(options.html);
		} else {
			div.innerHTML = options.html !== false ? options.html : '';
		}

		if (options.bgPos) {
			var bgPos = toPoint(options.bgPos);
			div.style.backgroundPosition = (-bgPos.x) + 'px ' + (-bgPos.y) + 'px';
		}
		this._setIconStyles(div, 'icon');

		return div;
	},

	createShadow: function () {
		return null;
	}
});

/*
 * L.Handler.MarkerDrag is used internally by L.Marker to make the markers draggable.
 */


/* @namespace Marker
 * @section Interaction handlers
 *
 * Interaction handlers are properties of a marker instance that allow you to control interaction behavior in runtime, enabling or disabling certain features such as dragging (see `Handler` methods). Example:
 *
 * ```js
 * marker.dragging.disable();
 * ```
 *
 * @property dragging: Handler
 * Marker dragging handler (by both mouse and touch). Only valid when the marker is on the map (Otherwise set [`marker.options.draggable`](#marker-draggable)).
 */

var MarkerDrag = Handler.extend({
	initialize: function (marker) {
		this._marker = marker;
	},

	addHooks: function () {
		var icon = this._marker._icon;

		if (!this._draggable) {
			this._draggable = new Draggable(icon, icon, true);
		}

		this._draggable.on({
			dragstart: this._onDragStart,
			predrag: this._onPreDrag,
			drag: this._onDrag,
			dragend: this._onDragEnd
		}, this).enable();

		addClass(icon, 'leaflet-marker-draggable');
	},

	removeHooks: function () {
		this._draggable.off({
			dragstart: this._onDragStart,
			predrag: this._onPreDrag,
			drag: this._onDrag,
			dragend: this._onDragEnd
		}, this).disable();

		if (this._marker._icon) {
			removeClass(this._marker._icon, 'leaflet-marker-draggable');
		}
	},

	moved: function () {
		return this._draggable && this._draggable._moved;
	},

	_adjustPan: function (e) {
		var marker = this._marker,
		    map = marker._map,
		    speed = this._marker.options.autoPanSpeed,
		    padding = this._marker.options.autoPanPadding,
		    iconPos = getPosition(marker._icon),
		    bounds = map.getPixelBounds(),
		    origin = map.getPixelOrigin();

		var panBounds = toBounds(
			bounds.min._subtract(origin).add(padding),
			bounds.max._subtract(origin).subtract(padding)
		);

		if (!panBounds.contains(iconPos)) {
			// Compute incremental movement
			var movement = toPoint(
				(Math.max(panBounds.max.x, iconPos.x) - panBounds.max.x) / (bounds.max.x - panBounds.max.x) -
				(Math.min(panBounds.min.x, iconPos.x) - panBounds.min.x) / (bounds.min.x - panBounds.min.x),

				(Math.max(panBounds.max.y, iconPos.y) - panBounds.max.y) / (bounds.max.y - panBounds.max.y) -
				(Math.min(panBounds.min.y, iconPos.y) - panBounds.min.y) / (bounds.min.y - panBounds.min.y)
			).multiplyBy(speed);

			map.panBy(movement, {animate: false});

			this._draggable._newPos._add(movement);
			this._draggable._startPos._add(movement);

			setPosition(marker._icon, this._draggable._newPos);
			this._onDrag(e);

			this._panRequest = requestAnimFrame(this._adjustPan.bind(this, e));
		}
	},

	_onDragStart: function () {
		// @section Dragging events
		// @event dragstart: Event
		// Fired when the user starts dragging the marker.

		// @event movestart: Event
		// Fired when the marker starts moving (because of dragging).

		this._oldLatLng = this._marker.getLatLng();
		this._marker
		    .closePopup()
		    .fire('movestart')
		    .fire('dragstart');
	},

	_onPreDrag: function (e) {
		if (this._marker.options.autoPan) {
			cancelAnimFrame(this._panRequest);
			this._panRequest = requestAnimFrame(this._adjustPan.bind(this, e));
		}
	},

	_onDrag: function (e) {
		var marker = this._marker,
		    shadow = marker._shadow,
		    iconPos = getPosition(marker._icon),
		    latlng = marker._map.layerPointToLatLng(iconPos);

		// update shadow position
		if (shadow) {
			setPosition(shadow, iconPos);
		}

		marker._latlng = latlng;
		e.latlng = latlng;
		e.oldLatLng = this._oldLatLng;

		// @event drag: Event
		// Fired repeatedly while the user drags the marker.
		marker
		    .fire('move', e)
		    .fire('drag', e);
	},

	_onDragEnd: function (e) {
		// @event dragend: DragEndEvent
		// Fired when the user stops dragging the marker.

		 cancelAnimFrame(this._panRequest);

		// @event moveend: Event
		// Fired when the marker stops moving (because of dragging).
		delete this._oldLatLng;
		this._marker
		    .fire('moveend')
		    .fire('dragend', e);
	}
});

/*
 * @class Marker
 * @inherits Interactive layer
 * @aka L.Marker
 * L.Marker is used to display clickable/draggable icons on the map. Extends `Layer`.
 *
 * @example
 *
 * ```js
 * L.marker([50.5, 30.5]).addTo(map);
 * ```
 */

var Marker = Layer.extend({

	// @section
	// @aka Marker options
	options: {
		// @option icon: Icon = *
		// Icon instance to use for rendering the marker.
		// See [Icon documentation](#L.Icon) for details on how to customize the marker icon.
		// If not specified, a common instance of `L.Icon.Default` is used.
		icon: new IconDefault(),

		// Option inherited from "Interactive layer" abstract class
		interactive: true,

		// @option keyboard: Boolean = true
		// Whether the marker can be tabbed to with a keyboard and clicked by pressing enter.
		keyboard: true,

		// @option title: String = ''
		// Text for the browser tooltip that appear on marker hover (no tooltip by default).
		title: '',

		// @option alt: String = ''
		// Text for the `alt` attribute of the icon image (useful for accessibility).
		alt: '',

		// @option zIndexOffset: Number = 0
		// By default, marker images zIndex is set automatically based on its latitude. Use this option if you want to put the marker on top of all others (or below), specifying a high value like `1000` (or high negative value, respectively).
		zIndexOffset: 0,

		// @option opacity: Number = 1.0
		// The opacity of the marker.
		opacity: 1,

		// @option riseOnHover: Boolean = false
		// If `true`, the marker will get on top of others when you hover the mouse over it.
		riseOnHover: false,

		// @option riseOffset: Number = 250
		// The z-index offset used for the `riseOnHover` feature.
		riseOffset: 250,

		// @option pane: String = 'markerPane'
		// `Map pane` where the markers icon will be added.
		pane: 'markerPane',

		// @option pane: String = 'shadowPane'
		// `Map pane` where the markers shadow will be added.
		shadowPane: 'shadowPane',

		// @option bubblingMouseEvents: Boolean = false
		// When `true`, a mouse event on this marker will trigger the same event on the map
		// (unless [`L.DomEvent.stopPropagation`](#domevent-stoppropagation) is used).
		bubblingMouseEvents: false,

		// @section Draggable marker options
		// @option draggable: Boolean = false
		// Whether the marker is draggable with mouse/touch or not.
		draggable: false,

		// @option autoPan: Boolean = false
		// Whether to pan the map when dragging this marker near its edge or not.
		autoPan: false,

		// @option autoPanPadding: Point = Point(50, 50)
		// Distance (in pixels to the left/right and to the top/bottom) of the
		// map edge to start panning the map.
		autoPanPadding: [50, 50],

		// @option autoPanSpeed: Number = 10
		// Number of pixels the map should pan by.
		autoPanSpeed: 10
	},

	/* @section
	 *
	 * In addition to [shared layer methods](#Layer) like `addTo()` and `remove()` and [popup methods](#Popup) like bindPopup() you can also use the following methods:
	 */

	initialize: function (latlng, options) {
		setOptions$1(this, options);
		this._latlng = toLatLng(latlng);
	},

	onAdd: function (map) {
		this._zoomAnimated = this._zoomAnimated && map.options.markerZoomAnimation;

		if (this._zoomAnimated) {
			map.on('zoomanim', this._animateZoom, this);
		}

		this._initIcon();
		this.update();
	},

	onRemove: function (map) {
		if (this.dragging && this.dragging.enabled()) {
			this.options.draggable = true;
			this.dragging.removeHooks();
		}
		delete this.dragging;

		if (this._zoomAnimated) {
			map.off('zoomanim', this._animateZoom, this);
		}

		this._removeIcon();
		this._removeShadow();
	},

	getEvents: function () {
		return {
			zoom: this.update,
			viewreset: this.update
		};
	},

	// @method getLatLng: LatLng
	// Returns the current geographical position of the marker.
	getLatLng: function () {
		return this._latlng;
	},

	// @method setLatLng(latlng: LatLng): this
	// Changes the marker position to the given point.
	setLatLng: function (latlng) {
		var oldLatLng = this._latlng;
		this._latlng = toLatLng(latlng);
		this.update();

		// @event move: Event
		// Fired when the marker is moved via [`setLatLng`](#marker-setlatlng) or by [dragging](#marker-dragging). Old and new coordinates are included in event arguments as `oldLatLng`, `latlng`.
		return this.fire('move', {oldLatLng: oldLatLng, latlng: this._latlng});
	},

	// @method setZIndexOffset(offset: Number): this
	// Changes the [zIndex offset](#marker-zindexoffset) of the marker.
	setZIndexOffset: function (offset) {
		this.options.zIndexOffset = offset;
		return this.update();
	},

	// @method getIcon: Icon
	// Returns the current icon used by the marker
	getIcon: function () {
		return this.options.icon;
	},

	// @method setIcon(icon: Icon): this
	// Changes the marker icon.
	setIcon: function (icon) {

		this.options.icon = icon;

		if (this._map) {
			this._initIcon();
			this.update();
		}

		if (this._popup) {
			this.bindPopup(this._popup, this._popup.options);
		}

		return this;
	},

	getElement: function () {
		return this._icon;
	},

	update: function () {

		if (this._icon && this._map) {
			var pos = this._map.latLngToLayerPoint(this._latlng).round();
			this._setPos(pos);
		}

		return this;
	},

	_initIcon: function () {
		var options = this.options,
		    classToAdd = 'leaflet-zoom-' + (this._zoomAnimated ? 'animated' : 'hide');

		var icon = options.icon.createIcon(this._icon),
		    addIcon = false;

		// if we're not reusing the icon, remove the old one and init new one
		if (icon !== this._icon) {
			if (this._icon) {
				this._removeIcon();
			}
			addIcon = true;

			if (options.title) {
				icon.title = options.title;
			}

			if (icon.tagName === 'IMG') {
				icon.alt = options.alt || '';
			}
		}

		addClass(icon, classToAdd);

		if (options.keyboard) {
			icon.tabIndex = '0';
		}

		this._icon = icon;

		if (options.riseOnHover) {
			this.on({
				mouseover: this._bringToFront,
				mouseout: this._resetZIndex
			});
		}

		var newShadow = options.icon.createShadow(this._shadow),
		    addShadow = false;

		if (newShadow !== this._shadow) {
			this._removeShadow();
			addShadow = true;
		}

		if (newShadow) {
			addClass(newShadow, classToAdd);
			newShadow.alt = '';
		}
		this._shadow = newShadow;


		if (options.opacity < 1) {
			this._updateOpacity();
		}


		if (addIcon) {
			this.getPane().appendChild(this._icon);
		}
		this._initInteraction();
		if (newShadow && addShadow) {
			this.getPane(options.shadowPane).appendChild(this._shadow);
		}
	},

	_removeIcon: function () {
		if (this.options.riseOnHover) {
			this.off({
				mouseover: this._bringToFront,
				mouseout: this._resetZIndex
			});
		}

		remove(this._icon);
		this.removeInteractiveTarget(this._icon);

		this._icon = null;
	},

	_removeShadow: function () {
		if (this._shadow) {
			remove(this._shadow);
		}
		this._shadow = null;
	},

	_setPos: function (pos) {

		if (this._icon) {
			setPosition(this._icon, pos);
		}

		if (this._shadow) {
			setPosition(this._shadow, pos);
		}

		this._zIndex = pos.y + this.options.zIndexOffset;

		this._resetZIndex();
	},

	_updateZIndex: function (offset) {
		if (this._icon) {
			this._icon.style.zIndex = this._zIndex + offset;
		}
	},

	_animateZoom: function (opt) {
		var pos = this._map._latLngToNewLayerPoint(this._latlng, opt.zoom, opt.center).round();

		this._setPos(pos);
	},

	_initInteraction: function () {

		if (!this.options.interactive) { return; }

		addClass(this._icon, 'leaflet-interactive');

		this.addInteractiveTarget(this._icon);

		if (MarkerDrag) {
			var draggable = this.options.draggable;
			if (this.dragging) {
				draggable = this.dragging.enabled();
				this.dragging.disable();
			}

			this.dragging = new MarkerDrag(this);

			if (draggable) {
				this.dragging.enable();
			}
		}
	},

	// @method setOpacity(opacity: Number): this
	// Changes the opacity of the marker.
	setOpacity: function (opacity) {
		this.options.opacity = opacity;
		if (this._map) {
			this._updateOpacity();
		}

		return this;
	},

	_updateOpacity: function () {
		var opacity = this.options.opacity;

		if (this._icon) {
			setOpacity(this._icon, opacity);
		}

		if (this._shadow) {
			setOpacity(this._shadow, opacity);
		}
	},

	_bringToFront: function () {
		this._updateZIndex(this.options.riseOffset);
	},

	_resetZIndex: function () {
		this._updateZIndex(0);
	},

	_getPopupAnchor: function () {
		return this.options.icon.options.popupAnchor;
	},

	_getTooltipAnchor: function () {
		return this.options.icon.options.tooltipAnchor;
	}
});

Icon.Default = IconDefault;

/*
 * @class LayerGroup
 * @aka L.LayerGroup
 * @inherits Layer
 *
 * Used to group several layers and handle them as one. If you add it to the map,
 * any layers added or removed from the group will be added/removed on the map as
 * well. Extends `Layer`.
 *
 * @example
 *
 * ```js
 * L.layerGroup([marker1, marker2])
 * 	.addLayer(polyline)
 * 	.addTo(map);
 * ```
 */

var LayerGroup$1 = Layer.extend({

	initialize: function (layers, options) {
		setOptions$1(this, options);

		this._layers = {};

		var i, len;

		if (layers) {
			for (i = 0, len = layers.length; i < len; i++) {
				this.addLayer(layers[i]);
			}
		}
	},

	// @method addLayer(layer: Layer): this
	// Adds the given layer to the group.
	addLayer: function (layer) {
		var id = this.getLayerId(layer);

		this._layers[id] = layer;

		if (this._map) {
			this._map.addLayer(layer);
		}

		return this;
	},

	// @method removeLayer(layer: Layer): this
	// Removes the given layer from the group.
	// @alternative
	// @method removeLayer(id: Number): this
	// Removes the layer with the given internal ID from the group.
	removeLayer: function (layer) {
		var id = layer in this._layers ? layer : this.getLayerId(layer);

		if (this._map && this._layers[id]) {
			this._map.removeLayer(this._layers[id]);
		}

		delete this._layers[id];

		return this;
	},

	// @method hasLayer(layer: Layer): Boolean
	// Returns `true` if the given layer is currently added to the group.
	// @alternative
	// @method hasLayer(id: Number): Boolean
	// Returns `true` if the given internal ID is currently added to the group.
	hasLayer: function (layer) {
		return !!layer && (layer in this._layers || this.getLayerId(layer) in this._layers);
	},

	// @method clearLayers(): this
	// Removes all the layers from the group.
	clearLayers: function () {
		return this.eachLayer(this.removeLayer, this);
	},

	// @method invoke(methodName: String, …): this
	// Calls `methodName` on every layer contained in this group, passing any
	// additional parameters. Has no effect if the layers contained do not
	// implement `methodName`.
	invoke: function (methodName) {
		var args = Array.prototype.slice.call(arguments, 1),
		    i, layer;

		for (i in this._layers) {
			layer = this._layers[i];

			if (layer[methodName]) {
				layer[methodName].apply(layer, args);
			}
		}

		return this;
	},

	onAdd: function (map) {
		this.eachLayer(map.addLayer, map);
	},

	onRemove: function (map) {
		this.eachLayer(map.removeLayer, map);
	},

	// @method eachLayer(fn: Function, context?: Object): this
	// Iterates over the layers of the group, optionally specifying context of the iterator function.
	// ```js
	// group.eachLayer(function (layer) {
	// 	layer.bindPopup('Hello');
	// });
	// ```
	eachLayer: function (method, context) {
		for (var i in this._layers) {
			method.call(context, this._layers[i]);
		}
		return this;
	},

	// @method getLayer(id: Number): Layer
	// Returns the layer with the given internal ID.
	getLayer: function (id) {
		return this._layers[id];
	},

	// @method getLayers(): Layer[]
	// Returns an array of all the layers added to the group.
	getLayers: function () {
		var layers = [];
		this.eachLayer(layers.push, layers);
		return layers;
	},

	// @method setZIndex(zIndex: Number): this
	// Calls `setZIndex` on every layer contained in this group, passing the z-index.
	setZIndex: function (zIndex) {
		return this.invoke('setZIndex', zIndex);
	},

	// @method getLayerId(layer: Layer): Number
	// Returns the internal ID for a layer
	getLayerId: function (layer) {
		return stamp$1(layer);
	}
});

/*
 * @class FeatureGroup
 * @aka L.FeatureGroup
 * @inherits LayerGroup
 *
 * Extended `LayerGroup` that makes it easier to do the same thing to all its member layers:
 *  * [`bindPopup`](#layer-bindpopup) binds a popup to all of the layers at once (likewise with [`bindTooltip`](#layer-bindtooltip))
 *  * Events are propagated to the `FeatureGroup`, so if the group has an event
 * handler, it will handle events from any of the layers. This includes mouse events
 * and custom events.
 *  * Has `layeradd` and `layerremove` events
 *
 * @example
 *
 * ```js
 * L.featureGroup([marker1, marker2, polyline])
 * 	.bindPopup('Hello world!')
 * 	.on('click', function() { alert('Clicked on a member of the group!'); })
 * 	.addTo(map);
 * ```
 */

var FeatureGroup = LayerGroup$1.extend({

	addLayer: function (layer) {
		if (this.hasLayer(layer)) {
			return this;
		}

		layer.addEventParent(this);

		LayerGroup$1.prototype.addLayer.call(this, layer);

		// @event layeradd: LayerEvent
		// Fired when a layer is added to this `FeatureGroup`
		return this.fire('layeradd', {layer: layer});
	},

	removeLayer: function (layer) {
		if (!this.hasLayer(layer)) {
			return this;
		}
		if (layer in this._layers) {
			layer = this._layers[layer];
		}

		layer.removeEventParent(this);

		LayerGroup$1.prototype.removeLayer.call(this, layer);

		// @event layerremove: LayerEvent
		// Fired when a layer is removed from this `FeatureGroup`
		return this.fire('layerremove', {layer: layer});
	},

	// @method setStyle(style: Path options): this
	// Sets the given path options to each layer of the group that has a `setStyle` method.
	setStyle: function (style) {
		return this.invoke('setStyle', style);
	},

	// @method bringToFront(): this
	// Brings the layer group to the top of all other layers
	bringToFront: function () {
		return this.invoke('bringToFront');
	},

	// @method bringToBack(): this
	// Brings the layer group to the back of all other layers
	bringToBack: function () {
		return this.invoke('bringToBack');
	},

	// @method getBounds(): LatLngBounds
	// Returns the LatLngBounds of the Feature Group (created from bounds and coordinates of its children).
	getBounds: function () {
		var bounds = new LatLngBounds();

		for (var id in this._layers) {
			var layer = this._layers[id];
			bounds.extend(layer.getBounds ? layer.getBounds() : layer.getLatLng());
		}
		return bounds;
	}
});

/*
 * @class Path
 * @aka L.Path
 * @inherits Interactive layer
 *
 * An abstract class that contains options and constants shared between vector
 * overlays (Polygon, Polyline, Circle). Do not use it directly. Extends `Layer`.
 */

var Path = Layer.extend({

	// @section
	// @aka Path options
	options: {
		// @option stroke: Boolean = true
		// Whether to draw stroke along the path. Set it to `false` to disable borders on polygons or circles.
		stroke: true,

		// @option color: String = '#3388ff'
		// Stroke color
		color: '#3388ff',

		// @option weight: Number = 3
		// Stroke width in pixels
		weight: 3,

		// @option opacity: Number = 1.0
		// Stroke opacity
		opacity: 1,

		// @option lineCap: String= 'round'
		// A string that defines [shape to be used at the end](https://developer.mozilla.org/docs/Web/SVG/Attribute/stroke-linecap) of the stroke.
		lineCap: 'round',

		// @option lineJoin: String = 'round'
		// A string that defines [shape to be used at the corners](https://developer.mozilla.org/docs/Web/SVG/Attribute/stroke-linejoin) of the stroke.
		lineJoin: 'round',

		// @option dashArray: String = null
		// A string that defines the stroke [dash pattern](https://developer.mozilla.org/docs/Web/SVG/Attribute/stroke-dasharray). Doesn't work on `Canvas`-powered layers in [some old browsers](https://developer.mozilla.org/docs/Web/API/CanvasRenderingContext2D/setLineDash#Browser_compatibility).
		dashArray: null,

		// @option dashOffset: String = null
		// A string that defines the [distance into the dash pattern to start the dash](https://developer.mozilla.org/docs/Web/SVG/Attribute/stroke-dashoffset). Doesn't work on `Canvas`-powered layers in [some old browsers](https://developer.mozilla.org/docs/Web/API/CanvasRenderingContext2D/setLineDash#Browser_compatibility).
		dashOffset: null,

		// @option fill: Boolean = depends
		// Whether to fill the path with color. Set it to `false` to disable filling on polygons or circles.
		fill: false,

		// @option fillColor: String = *
		// Fill color. Defaults to the value of the [`color`](#path-color) option
		fillColor: null,

		// @option fillOpacity: Number = 0.2
		// Fill opacity.
		fillOpacity: 0.2,

		// @option fillRule: String = 'evenodd'
		// A string that defines [how the inside of a shape](https://developer.mozilla.org/docs/Web/SVG/Attribute/fill-rule) is determined.
		fillRule: 'evenodd',

		// className: '',

		// Option inherited from "Interactive layer" abstract class
		interactive: true,

		// @option bubblingMouseEvents: Boolean = true
		// When `true`, a mouse event on this path will trigger the same event on the map
		// (unless [`L.DomEvent.stopPropagation`](#domevent-stoppropagation) is used).
		bubblingMouseEvents: true
	},

	beforeAdd: function (map) {
		// Renderer is set here because we need to call renderer.getEvents
		// before this.getEvents.
		this._renderer = map.getRenderer(this);
	},

	onAdd: function () {
		this._renderer._initPath(this);
		this._reset();
		this._renderer._addPath(this);
	},

	onRemove: function () {
		this._renderer._removePath(this);
	},

	// @method redraw(): this
	// Redraws the layer. Sometimes useful after you changed the coordinates that the path uses.
	redraw: function () {
		if (this._map) {
			this._renderer._updatePath(this);
		}
		return this;
	},

	// @method setStyle(style: Path options): this
	// Changes the appearance of a Path based on the options in the `Path options` object.
	setStyle: function (style) {
		setOptions$1(this, style);
		if (this._renderer) {
			this._renderer._updateStyle(this);
			if (this.options.stroke && style && style.hasOwnProperty('weight')) {
				this._updateBounds();
			}
		}
		return this;
	},

	// @method bringToFront(): this
	// Brings the layer to the top of all path layers.
	bringToFront: function () {
		if (this._renderer) {
			this._renderer._bringToFront(this);
		}
		return this;
	},

	// @method bringToBack(): this
	// Brings the layer to the bottom of all path layers.
	bringToBack: function () {
		if (this._renderer) {
			this._renderer._bringToBack(this);
		}
		return this;
	},

	getElement: function () {
		return this._path;
	},

	_reset: function () {
		// defined in child classes
		this._project();
		this._update();
	},

	_clickTolerance: function () {
		// used when doing hit detection for Canvas layers
		return (this.options.stroke ? this.options.weight / 2 : 0) + this._renderer.options.tolerance;
	}
});

/*
 * @class CircleMarker
 * @aka L.CircleMarker
 * @inherits Path
 *
 * A circle of a fixed size with radius specified in pixels. Extends `Path`.
 */

var CircleMarker = Path.extend({

	// @section
	// @aka CircleMarker options
	options: {
		fill: true,

		// @option radius: Number = 10
		// Radius of the circle marker, in pixels
		radius: 10
	},

	initialize: function (latlng, options) {
		setOptions$1(this, options);
		this._latlng = toLatLng(latlng);
		this._radius = this.options.radius;
	},

	// @method setLatLng(latLng: LatLng): this
	// Sets the position of a circle marker to a new location.
	setLatLng: function (latlng) {
		var oldLatLng = this._latlng;
		this._latlng = toLatLng(latlng);
		this.redraw();

		// @event move: Event
		// Fired when the marker is moved via [`setLatLng`](#circlemarker-setlatlng). Old and new coordinates are included in event arguments as `oldLatLng`, `latlng`.
		return this.fire('move', {oldLatLng: oldLatLng, latlng: this._latlng});
	},

	// @method getLatLng(): LatLng
	// Returns the current geographical position of the circle marker
	getLatLng: function () {
		return this._latlng;
	},

	// @method setRadius(radius: Number): this
	// Sets the radius of a circle marker. Units are in pixels.
	setRadius: function (radius) {
		this.options.radius = this._radius = radius;
		return this.redraw();
	},

	// @method getRadius(): Number
	// Returns the current radius of the circle
	getRadius: function () {
		return this._radius;
	},

	setStyle : function (options) {
		var radius = options && options.radius || this._radius;
		Path.prototype.setStyle.call(this, options);
		this.setRadius(radius);
		return this;
	},

	_project: function () {
		this._point = this._map.latLngToLayerPoint(this._latlng);
		this._updateBounds();
	},

	_updateBounds: function () {
		var r = this._radius,
		    r2 = this._radiusY || r,
		    w = this._clickTolerance(),
		    p = [r + w, r2 + w];
		this._pxBounds = new Bounds(this._point.subtract(p), this._point.add(p));
	},

	_update: function () {
		if (this._map) {
			this._updatePath();
		}
	},

	_updatePath: function () {
		this._renderer._updateCircle(this);
	},

	_empty: function () {
		return this._radius && !this._renderer._bounds.intersects(this._pxBounds);
	},

	// Needed by the `Canvas` renderer for interactivity
	_containsPoint: function (p) {
		return p.distanceTo(this._point) <= this._radius + this._clickTolerance();
	}
});

/*
 * @class Circle
 * @aka L.Circle
 * @inherits CircleMarker
 *
 * A class for drawing circle overlays on a map. Extends `CircleMarker`.
 *
 * It's an approximation and starts to diverge from a real circle closer to poles (due to projection distortion).
 *
 * @example
 *
 * ```js
 * L.circle([50.5, 30.5], {radius: 200}).addTo(map);
 * ```
 */

var Circle = CircleMarker.extend({

	initialize: function (latlng, options, legacyOptions) {
		if (typeof options === 'number') {
			// Backwards compatibility with 0.7.x factory (latlng, radius, options?)
			options = extend({}, legacyOptions, {radius: options});
		}
		setOptions$1(this, options);
		this._latlng = toLatLng(latlng);

		if (isNaN(this.options.radius)) { throw new Error('Circle radius cannot be NaN'); }

		// @section
		// @aka Circle options
		// @option radius: Number; Radius of the circle, in meters.
		this._mRadius = this.options.radius;
	},

	// @method setRadius(radius: Number): this
	// Sets the radius of a circle. Units are in meters.
	setRadius: function (radius) {
		this._mRadius = radius;
		return this.redraw();
	},

	// @method getRadius(): Number
	// Returns the current radius of a circle. Units are in meters.
	getRadius: function () {
		return this._mRadius;
	},

	// @method getBounds(): LatLngBounds
	// Returns the `LatLngBounds` of the path.
	getBounds: function () {
		var half = [this._radius, this._radiusY || this._radius];

		return new LatLngBounds(
			this._map.layerPointToLatLng(this._point.subtract(half)),
			this._map.layerPointToLatLng(this._point.add(half)));
	},

	setStyle: Path.prototype.setStyle,

	_project: function () {

		var lng = this._latlng.lng,
		    lat = this._latlng.lat,
		    map = this._map,
		    crs = map.options.crs;

		if (crs.distance === Earth.distance) {
			var d = Math.PI / 180,
			    latR = (this._mRadius / Earth.R) / d,
			    top = map.project([lat + latR, lng]),
			    bottom = map.project([lat - latR, lng]),
			    p = top.add(bottom).divideBy(2),
			    lat2 = map.unproject(p).lat,
			    lngR = Math.acos((Math.cos(latR * d) - Math.sin(lat * d) * Math.sin(lat2 * d)) /
			            (Math.cos(lat * d) * Math.cos(lat2 * d))) / d;

			if (isNaN(lngR) || lngR === 0) {
				lngR = latR / Math.cos(Math.PI / 180 * lat); // Fallback for edge case, #2425
			}

			this._point = p.subtract(map.getPixelOrigin());
			this._radius = isNaN(lngR) ? 0 : p.x - map.project([lat2, lng - lngR]).x;
			this._radiusY = p.y - top.y;

		} else {
			var latlng2 = crs.unproject(crs.project(this._latlng).subtract([this._mRadius, 0]));

			this._point = map.latLngToLayerPoint(this._latlng);
			this._radius = this._point.x - map.latLngToLayerPoint(latlng2).x;
		}

		this._updateBounds();
	}
});

/*
 * @namespace LineUtil
 *
 * Various utility functions for polyline points processing, used by Leaflet internally to make polylines lightning-fast.
 */

// Simplify polyline with vertex reduction and Douglas-Peucker simplification.
// Improves rendering performance dramatically by lessening the number of points to draw.

// @function simplify(points: Point[], tolerance: Number): Point[]
// Dramatically reduces the number of points in a polyline while retaining
// its shape and returns a new array of simplified points, using the
// [Douglas-Peucker algorithm](http://en.wikipedia.org/wiki/Douglas-Peucker_algorithm).
// Used for a huge performance boost when processing/displaying Leaflet polylines for
// each zoom level and also reducing visual noise. tolerance affects the amount of
// simplification (lesser value means higher quality but slower and with more points).
// Also released as a separated micro-library [Simplify.js](http://mourner.github.com/simplify-js/).
function simplify(points, tolerance) {
	if (!tolerance || !points.length) {
		return points.slice();
	}

	var sqTolerance = tolerance * tolerance;

	    // stage 1: vertex reduction
	    points = _reducePoints(points, sqTolerance);

	    // stage 2: Douglas-Peucker simplification
	    points = _simplifyDP(points, sqTolerance);

	return points;
}

// @function pointToSegmentDistance(p: Point, p1: Point, p2: Point): Number
// Returns the distance between point `p` and segment `p1` to `p2`.
function pointToSegmentDistance(p, p1, p2) {
	return Math.sqrt(_sqClosestPointOnSegment(p, p1, p2, true));
}

// Douglas-Peucker simplification, see http://en.wikipedia.org/wiki/Douglas-Peucker_algorithm
function _simplifyDP(points, sqTolerance) {

	var len = points.length,
	    ArrayConstructor = typeof Uint8Array !== undefined + '' ? Uint8Array : Array,
	    markers = new ArrayConstructor(len);

	    markers[0] = markers[len - 1] = 1;

	_simplifyDPStep(points, markers, sqTolerance, 0, len - 1);

	var i,
	    newPoints = [];

	for (i = 0; i < len; i++) {
		if (markers[i]) {
			newPoints.push(points[i]);
		}
	}

	return newPoints;
}

function _simplifyDPStep(points, markers, sqTolerance, first, last) {

	var maxSqDist = 0,
	index, i, sqDist;

	for (i = first + 1; i <= last - 1; i++) {
		sqDist = _sqClosestPointOnSegment(points[i], points[first], points[last], true);

		if (sqDist > maxSqDist) {
			index = i;
			maxSqDist = sqDist;
		}
	}

	if (maxSqDist > sqTolerance) {
		markers[index] = 1;

		_simplifyDPStep(points, markers, sqTolerance, first, index);
		_simplifyDPStep(points, markers, sqTolerance, index, last);
	}
}

// reduce points that are too close to each other to a single point
function _reducePoints(points, sqTolerance) {
	var reducedPoints = [points[0]];

	for (var i = 1, prev = 0, len = points.length; i < len; i++) {
		if (_sqDist(points[i], points[prev]) > sqTolerance) {
			reducedPoints.push(points[i]);
			prev = i;
		}
	}
	if (prev < len - 1) {
		reducedPoints.push(points[len - 1]);
	}
	return reducedPoints;
}

var _lastCode;

// @function clipSegment(a: Point, b: Point, bounds: Bounds, useLastCode?: Boolean, round?: Boolean): Point[]|Boolean
// Clips the segment a to b by rectangular bounds with the
// [Cohen-Sutherland algorithm](https://en.wikipedia.org/wiki/Cohen%E2%80%93Sutherland_algorithm)
// (modifying the segment points directly!). Used by Leaflet to only show polyline
// points that are on the screen or near, increasing performance.
function clipSegment(a, b, bounds, useLastCode, round) {
	var codeA = useLastCode ? _lastCode : _getBitCode(a, bounds),
	    codeB = _getBitCode(b, bounds),

	    codeOut, p, newCode;

	    // save 2nd code to avoid calculating it on the next segment
	    _lastCode = codeB;

	while (true) {
		// if a,b is inside the clip window (trivial accept)
		if (!(codeA | codeB)) {
			return [a, b];
		}

		// if a,b is outside the clip window (trivial reject)
		if (codeA & codeB) {
			return false;
		}

		// other cases
		codeOut = codeA || codeB;
		p = _getEdgeIntersection(a, b, codeOut, bounds, round);
		newCode = _getBitCode(p, bounds);

		if (codeOut === codeA) {
			a = p;
			codeA = newCode;
		} else {
			b = p;
			codeB = newCode;
		}
	}
}

function _getEdgeIntersection(a, b, code, bounds, round) {
	var dx = b.x - a.x,
	    dy = b.y - a.y,
	    min = bounds.min,
	    max = bounds.max,
	    x, y;

	if (code & 8) { // top
		x = a.x + dx * (max.y - a.y) / dy;
		y = max.y;

	} else if (code & 4) { // bottom
		x = a.x + dx * (min.y - a.y) / dy;
		y = min.y;

	} else if (code & 2) { // right
		x = max.x;
		y = a.y + dy * (max.x - a.x) / dx;

	} else if (code & 1) { // left
		x = min.x;
		y = a.y + dy * (min.x - a.x) / dx;
	}

	return new Point(x, y, round);
}

function _getBitCode(p, bounds) {
	var code = 0;

	if (p.x < bounds.min.x) { // left
		code |= 1;
	} else if (p.x > bounds.max.x) { // right
		code |= 2;
	}

	if (p.y < bounds.min.y) { // bottom
		code |= 4;
	} else if (p.y > bounds.max.y) { // top
		code |= 8;
	}

	return code;
}

// square distance (to avoid unnecessary Math.sqrt calls)
function _sqDist(p1, p2) {
	var dx = p2.x - p1.x,
	    dy = p2.y - p1.y;
	return dx * dx + dy * dy;
}

// return closest point on segment or distance to that point
function _sqClosestPointOnSegment(p, p1, p2, sqDist) {
	var x = p1.x,
	    y = p1.y,
	    dx = p2.x - x,
	    dy = p2.y - y,
	    dot = dx * dx + dy * dy,
	    t;

	if (dot > 0) {
		t = ((p.x - x) * dx + (p.y - y) * dy) / dot;

		if (t > 1) {
			x = p2.x;
			y = p2.y;
		} else if (t > 0) {
			x += dx * t;
			y += dy * t;
		}
	}

	dx = p.x - x;
	dy = p.y - y;

	return sqDist ? dx * dx + dy * dy : new Point(x, y);
}


// @function isFlat(latlngs: LatLng[]): Boolean
// Returns true if `latlngs` is a flat array, false is nested.
function isFlat(latlngs) {
	return !isArray(latlngs[0]) || (typeof latlngs[0][0] !== 'object' && typeof latlngs[0][0] !== 'undefined');
}

function _flat(latlngs) {
	console.warn('Deprecated use of _flat, please use L.LineUtil.isFlat instead.');
	return isFlat(latlngs);
}

/*
 * @class Polyline
 * @aka L.Polyline
 * @inherits Path
 *
 * A class for drawing polyline overlays on a map. Extends `Path`.
 *
 * @example
 *
 * ```js
 * // create a red polyline from an array of LatLng points
 * var latlngs = [
 * 	[45.51, -122.68],
 * 	[37.77, -122.43],
 * 	[34.04, -118.2]
 * ];
 *
 * var polyline = L.polyline(latlngs, {color: 'red'}).addTo(map);
 *
 * // zoom the map to the polyline
 * map.fitBounds(polyline.getBounds());
 * ```
 *
 * You can also pass a multi-dimensional array to represent a `MultiPolyline` shape:
 *
 * ```js
 * // create a red polyline from an array of arrays of LatLng points
 * var latlngs = [
 * 	[[45.51, -122.68],
 * 	 [37.77, -122.43],
 * 	 [34.04, -118.2]],
 * 	[[40.78, -73.91],
 * 	 [41.83, -87.62],
 * 	 [32.76, -96.72]]
 * ];
 * ```
 */


var Polyline = Path.extend({

	// @section
	// @aka Polyline options
	options: {
		// @option smoothFactor: Number = 1.0
		// How much to simplify the polyline on each zoom level. More means
		// better performance and smoother look, and less means more accurate representation.
		smoothFactor: 1.0,

		// @option noClip: Boolean = false
		// Disable polyline clipping.
		noClip: false
	},

	initialize: function (latlngs, options) {
		setOptions$1(this, options);
		this._setLatLngs(latlngs);
	},

	// @method getLatLngs(): LatLng[]
	// Returns an array of the points in the path, or nested arrays of points in case of multi-polyline.
	getLatLngs: function () {
		return this._latlngs;
	},

	// @method setLatLngs(latlngs: LatLng[]): this
	// Replaces all the points in the polyline with the given array of geographical points.
	setLatLngs: function (latlngs) {
		this._setLatLngs(latlngs);
		return this.redraw();
	},

	// @method isEmpty(): Boolean
	// Returns `true` if the Polyline has no LatLngs.
	isEmpty: function () {
		return !this._latlngs.length;
	},

	// @method closestLayerPoint(p: Point): Point
	// Returns the point closest to `p` on the Polyline.
	closestLayerPoint: function (p) {
		var minDistance = Infinity,
		    minPoint = null,
		    closest = _sqClosestPointOnSegment,
		    p1, p2;

		for (var j = 0, jLen = this._parts.length; j < jLen; j++) {
			var points = this._parts[j];

			for (var i = 1, len = points.length; i < len; i++) {
				p1 = points[i - 1];
				p2 = points[i];

				var sqDist = closest(p, p1, p2, true);

				if (sqDist < minDistance) {
					minDistance = sqDist;
					minPoint = closest(p, p1, p2);
				}
			}
		}
		if (minPoint) {
			minPoint.distance = Math.sqrt(minDistance);
		}
		return minPoint;
	},

	// @method getCenter(): LatLng
	// Returns the center ([centroid](http://en.wikipedia.org/wiki/Centroid)) of the polyline.
	getCenter: function () {
		// throws error when not yet added to map as this center calculation requires projected coordinates
		if (!this._map) {
			throw new Error('Must add layer to map before using getCenter()');
		}

		var i, halfDist, segDist, dist, p1, p2, ratio,
		    points = this._rings[0],
		    len = points.length;

		if (!len) { return null; }

		// polyline centroid algorithm; only uses the first ring if there are multiple

		for (i = 0, halfDist = 0; i < len - 1; i++) {
			halfDist += points[i].distanceTo(points[i + 1]) / 2;
		}

		// The line is so small in the current view that all points are on the same pixel.
		if (halfDist === 0) {
			return this._map.layerPointToLatLng(points[0]);
		}

		for (i = 0, dist = 0; i < len - 1; i++) {
			p1 = points[i];
			p2 = points[i + 1];
			segDist = p1.distanceTo(p2);
			dist += segDist;

			if (dist > halfDist) {
				ratio = (dist - halfDist) / segDist;
				return this._map.layerPointToLatLng([
					p2.x - ratio * (p2.x - p1.x),
					p2.y - ratio * (p2.y - p1.y)
				]);
			}
		}
	},

	// @method getBounds(): LatLngBounds
	// Returns the `LatLngBounds` of the path.
	getBounds: function () {
		return this._bounds;
	},

	// @method addLatLng(latlng: LatLng, latlngs? LatLng[]): this
	// Adds a given point to the polyline. By default, adds to the first ring of
	// the polyline in case of a multi-polyline, but can be overridden by passing
	// a specific ring as a LatLng array (that you can earlier access with [`getLatLngs`](#polyline-getlatlngs)).
	addLatLng: function (latlng, latlngs) {
		latlngs = latlngs || this._defaultShape();
		latlng = toLatLng(latlng);
		latlngs.push(latlng);
		this._bounds.extend(latlng);
		return this.redraw();
	},

	_setLatLngs: function (latlngs) {
		this._bounds = new LatLngBounds();
		this._latlngs = this._convertLatLngs(latlngs);
	},

	_defaultShape: function () {
		return isFlat(this._latlngs) ? this._latlngs : this._latlngs[0];
	},

	// recursively convert latlngs input into actual LatLng instances; calculate bounds along the way
	_convertLatLngs: function (latlngs) {
		var result = [],
		    flat = isFlat(latlngs);

		for (var i = 0, len = latlngs.length; i < len; i++) {
			if (flat) {
				result[i] = toLatLng(latlngs[i]);
				this._bounds.extend(result[i]);
			} else {
				result[i] = this._convertLatLngs(latlngs[i]);
			}
		}

		return result;
	},

	_project: function () {
		var pxBounds = new Bounds();
		this._rings = [];
		this._projectLatlngs(this._latlngs, this._rings, pxBounds);

		if (this._bounds.isValid() && pxBounds.isValid()) {
			this._rawPxBounds = pxBounds;
			this._updateBounds();
		}
	},

	_updateBounds: function () {
		var w = this._clickTolerance(),
		    p = new Point(w, w);
		this._pxBounds = new Bounds([
			this._rawPxBounds.min.subtract(p),
			this._rawPxBounds.max.add(p)
		]);
	},

	// recursively turns latlngs into a set of rings with projected coordinates
	_projectLatlngs: function (latlngs, result, projectedBounds) {
		var flat = latlngs[0] instanceof LatLng,
		    len = latlngs.length,
		    i, ring;

		if (flat) {
			ring = [];
			for (i = 0; i < len; i++) {
				ring[i] = this._map.latLngToLayerPoint(latlngs[i]);
				projectedBounds.extend(ring[i]);
			}
			result.push(ring);
		} else {
			for (i = 0; i < len; i++) {
				this._projectLatlngs(latlngs[i], result, projectedBounds);
			}
		}
	},

	// clip polyline by renderer bounds so that we have less to render for performance
	_clipPoints: function () {
		var bounds = this._renderer._bounds;

		this._parts = [];
		if (!this._pxBounds || !this._pxBounds.intersects(bounds)) {
			return;
		}

		if (this.options.noClip) {
			this._parts = this._rings;
			return;
		}

		var parts = this._parts,
		    i, j, k, len, len2, segment, points;

		for (i = 0, k = 0, len = this._rings.length; i < len; i++) {
			points = this._rings[i];

			for (j = 0, len2 = points.length; j < len2 - 1; j++) {
				segment = clipSegment(points[j], points[j + 1], bounds, j, true);

				if (!segment) { continue; }

				parts[k] = parts[k] || [];
				parts[k].push(segment[0]);

				// if segment goes out of screen, or it's the last one, it's the end of the line part
				if ((segment[1] !== points[j + 1]) || (j === len2 - 2)) {
					parts[k].push(segment[1]);
					k++;
				}
			}
		}
	},

	// simplify each clipped part of the polyline for performance
	_simplifyPoints: function () {
		var parts = this._parts,
		    tolerance = this.options.smoothFactor;

		for (var i = 0, len = parts.length; i < len; i++) {
			parts[i] = simplify(parts[i], tolerance);
		}
	},

	_update: function () {
		if (!this._map) { return; }

		this._clipPoints();
		this._simplifyPoints();
		this._updatePath();
	},

	_updatePath: function () {
		this._renderer._updatePoly(this);
	},

	// Needed by the `Canvas` renderer for interactivity
	_containsPoint: function (p, closed) {
		var i, j, k, len, len2, part,
		    w = this._clickTolerance();

		if (!this._pxBounds || !this._pxBounds.contains(p)) { return false; }

		// hit detection for polylines
		for (i = 0, len = this._parts.length; i < len; i++) {
			part = this._parts[i];

			for (j = 0, len2 = part.length, k = len2 - 1; j < len2; k = j++) {
				if (!closed && (j === 0)) { continue; }

				if (pointToSegmentDistance(p, part[k], part[j]) <= w) {
					return true;
				}
			}
		}
		return false;
	}
});

// Retrocompat. Allow plugins to support Leaflet versions before and after 1.1.
Polyline._flat = _flat;

/*
 * @namespace PolyUtil
 * Various utility functions for polygon geometries.
 */

/* @function clipPolygon(points: Point[], bounds: Bounds, round?: Boolean): Point[]
 * Clips the polygon geometry defined by the given `points` by the given bounds (using the [Sutherland-Hodgman algorithm](https://en.wikipedia.org/wiki/Sutherland%E2%80%93Hodgman_algorithm)).
 * Used by Leaflet to only show polygon points that are on the screen or near, increasing
 * performance. Note that polygon points needs different algorithm for clipping
 * than polyline, so there's a separate method for it.
 */
function clipPolygon(points, bounds, round) {
	var clippedPoints,
	    edges = [1, 4, 2, 8],
	    i, j, k,
	    a, b,
	    len, edge, p;

	for (i = 0, len = points.length; i < len; i++) {
		points[i]._code = _getBitCode(points[i], bounds);
	}

	// for each edge (left, bottom, right, top)
	for (k = 0; k < 4; k++) {
		edge = edges[k];
		clippedPoints = [];

		for (i = 0, len = points.length, j = len - 1; i < len; j = i++) {
			a = points[i];
			b = points[j];

			// if a is inside the clip window
			if (!(a._code & edge)) {
				// if b is outside the clip window (a->b goes out of screen)
				if (b._code & edge) {
					p = _getEdgeIntersection(b, a, edge, bounds, round);
					p._code = _getBitCode(p, bounds);
					clippedPoints.push(p);
				}
				clippedPoints.push(a);

			// else if b is inside the clip window (a->b enters the screen)
			} else if (!(b._code & edge)) {
				p = _getEdgeIntersection(b, a, edge, bounds, round);
				p._code = _getBitCode(p, bounds);
				clippedPoints.push(p);
			}
		}
		points = clippedPoints;
	}

	return points;
}

/*
 * @class Polygon
 * @aka L.Polygon
 * @inherits Polyline
 *
 * A class for drawing polygon overlays on a map. Extends `Polyline`.
 *
 * Note that points you pass when creating a polygon shouldn't have an additional last point equal to the first one — it's better to filter out such points.
 *
 *
 * @example
 *
 * ```js
 * // create a red polygon from an array of LatLng points
 * var latlngs = [[37, -109.05],[41, -109.03],[41, -102.05],[37, -102.04]];
 *
 * var polygon = L.polygon(latlngs, {color: 'red'}).addTo(map);
 *
 * // zoom the map to the polygon
 * map.fitBounds(polygon.getBounds());
 * ```
 *
 * You can also pass an array of arrays of latlngs, with the first array representing the outer shape and the other arrays representing holes in the outer shape:
 *
 * ```js
 * var latlngs = [
 *   [[37, -109.05],[41, -109.03],[41, -102.05],[37, -102.04]], // outer ring
 *   [[37.29, -108.58],[40.71, -108.58],[40.71, -102.50],[37.29, -102.50]] // hole
 * ];
 * ```
 *
 * Additionally, you can pass a multi-dimensional array to represent a MultiPolygon shape.
 *
 * ```js
 * var latlngs = [
 *   [ // first polygon
 *     [[37, -109.05],[41, -109.03],[41, -102.05],[37, -102.04]], // outer ring
 *     [[37.29, -108.58],[40.71, -108.58],[40.71, -102.50],[37.29, -102.50]] // hole
 *   ],
 *   [ // second polygon
 *     [[41, -111.03],[45, -111.04],[45, -104.05],[41, -104.05]]
 *   ]
 * ];
 * ```
 */

var Polygon = Polyline.extend({

	options: {
		fill: true
	},

	isEmpty: function () {
		return !this._latlngs.length || !this._latlngs[0].length;
	},

	getCenter: function () {
		// throws error when not yet added to map as this center calculation requires projected coordinates
		if (!this._map) {
			throw new Error('Must add layer to map before using getCenter()');
		}

		var i, j, p1, p2, f, area, x, y, center,
		    points = this._rings[0],
		    len = points.length;

		if (!len) { return null; }

		// polygon centroid algorithm; only uses the first ring if there are multiple

		area = x = y = 0;

		for (i = 0, j = len - 1; i < len; j = i++) {
			p1 = points[i];
			p2 = points[j];

			f = p1.y * p2.x - p2.y * p1.x;
			x += (p1.x + p2.x) * f;
			y += (p1.y + p2.y) * f;
			area += f * 3;
		}

		if (area === 0) {
			// Polygon is so small that all points are on same pixel.
			center = points[0];
		} else {
			center = [x / area, y / area];
		}
		return this._map.layerPointToLatLng(center);
	},

	_convertLatLngs: function (latlngs) {
		var result = Polyline.prototype._convertLatLngs.call(this, latlngs),
		    len = result.length;

		// remove last point if it equals first one
		if (len >= 2 && result[0] instanceof LatLng && result[0].equals(result[len - 1])) {
			result.pop();
		}
		return result;
	},

	_setLatLngs: function (latlngs) {
		Polyline.prototype._setLatLngs.call(this, latlngs);
		if (isFlat(this._latlngs)) {
			this._latlngs = [this._latlngs];
		}
	},

	_defaultShape: function () {
		return isFlat(this._latlngs[0]) ? this._latlngs[0] : this._latlngs[0][0];
	},

	_clipPoints: function () {
		// polygons need a different clipping algorithm so we redefine that

		var bounds = this._renderer._bounds,
		    w = this.options.weight,
		    p = new Point(w, w);

		// increase clip padding by stroke width to avoid stroke on clip edges
		bounds = new Bounds(bounds.min.subtract(p), bounds.max.add(p));

		this._parts = [];
		if (!this._pxBounds || !this._pxBounds.intersects(bounds)) {
			return;
		}

		if (this.options.noClip) {
			this._parts = this._rings;
			return;
		}

		for (var i = 0, len = this._rings.length, clipped; i < len; i++) {
			clipped = clipPolygon(this._rings[i], bounds, true);
			if (clipped.length) {
				this._parts.push(clipped);
			}
		}
	},

	_updatePath: function () {
		this._renderer._updatePoly(this, true);
	},

	// Needed by the `Canvas` renderer for interactivity
	_containsPoint: function (p) {
		var inside = false,
		    part, p1, p2, i, j, k, len, len2;

		if (!this._pxBounds || !this._pxBounds.contains(p)) { return false; }

		// ray casting algorithm for detecting if point is in polygon
		for (i = 0, len = this._parts.length; i < len; i++) {
			part = this._parts[i];

			for (j = 0, len2 = part.length, k = len2 - 1; j < len2; k = j++) {
				p1 = part[j];
				p2 = part[k];

				if (((p1.y > p.y) !== (p2.y > p.y)) && (p.x < (p2.x - p1.x) * (p.y - p1.y) / (p2.y - p1.y) + p1.x)) {
					inside = !inside;
				}
			}
		}

		// also check if it's on polygon stroke
		return inside || Polyline.prototype._containsPoint.call(this, p, true);
	}

});

/*
 * @class GeoJSON
 * @aka L.GeoJSON
 * @inherits FeatureGroup
 *
 * Represents a GeoJSON object or an array of GeoJSON objects. Allows you to parse
 * GeoJSON data and display it on the map. Extends `FeatureGroup`.
 *
 * @example
 *
 * ```js
 * L.geoJSON(data, {
 * 	style: function (feature) {
 * 		return {color: feature.properties.color};
 * 	}
 * }).bindPopup(function (layer) {
 * 	return layer.feature.properties.description;
 * }).addTo(map);
 * ```
 */

var GeoJSON = FeatureGroup.extend({

	/* @section
	 * @aka GeoJSON options
	 *
	 * @option pointToLayer: Function = *
	 * A `Function` defining how GeoJSON points spawn Leaflet layers. It is internally
	 * called when data is added, passing the GeoJSON point feature and its `LatLng`.
	 * The default is to spawn a default `Marker`:
	 * ```js
	 * function(geoJsonPoint, latlng) {
	 * 	return L.marker(latlng);
	 * }
	 * ```
	 *
	 * @option style: Function = *
	 * A `Function` defining the `Path options` for styling GeoJSON lines and polygons,
	 * called internally when data is added.
	 * The default value is to not override any defaults:
	 * ```js
	 * function (geoJsonFeature) {
	 * 	return {}
	 * }
	 * ```
	 *
	 * @option onEachFeature: Function = *
	 * A `Function` that will be called once for each created `Feature`, after it has
	 * been created and styled. Useful for attaching events and popups to features.
	 * The default is to do nothing with the newly created layers:
	 * ```js
	 * function (feature, layer) {}
	 * ```
	 *
	 * @option filter: Function = *
	 * A `Function` that will be used to decide whether to include a feature or not.
	 * The default is to include all features:
	 * ```js
	 * function (geoJsonFeature) {
	 * 	return true;
	 * }
	 * ```
	 * Note: dynamically changing the `filter` option will have effect only on newly
	 * added data. It will _not_ re-evaluate already included features.
	 *
	 * @option coordsToLatLng: Function = *
	 * A `Function` that will be used for converting GeoJSON coordinates to `LatLng`s.
	 * The default is the `coordsToLatLng` static method.
	 *
	 * @option markersInheritOptions: Boolean = false
	 * Whether default Markers for "Point" type Features inherit from group options.
	 */

	initialize: function (geojson, options) {
		setOptions$1(this, options);

		this._layers = {};

		if (geojson) {
			this.addData(geojson);
		}
	},

	// @method addData( <GeoJSON> data ): this
	// Adds a GeoJSON object to the layer.
	addData: function (geojson) {
		var features = isArray(geojson) ? geojson : geojson.features,
		    i, len, feature;

		if (features) {
			for (i = 0, len = features.length; i < len; i++) {
				// only add this if geometry or geometries are set and not null
				feature = features[i];
				if (feature.geometries || feature.geometry || feature.features || feature.coordinates) {
					this.addData(feature);
				}
			}
			return this;
		}

		var options = this.options;

		if (options.filter && !options.filter(geojson)) { return this; }

		var layer = geometryToLayer(geojson, options);
		if (!layer) {
			return this;
		}
		layer.feature = asFeature(geojson);

		layer.defaultOptions = layer.options;
		this.resetStyle(layer);

		if (options.onEachFeature) {
			options.onEachFeature(geojson, layer);
		}

		return this.addLayer(layer);
	},

	// @method resetStyle( <Path> layer? ): this
	// Resets the given vector layer's style to the original GeoJSON style, useful for resetting style after hover events.
	// If `layer` is omitted, the style of all features in the current layer is reset.
	resetStyle: function (layer) {
		if (layer === undefined) {
			return this.eachLayer(this.resetStyle, this);
		}
		// reset any custom styles
		layer.options = extend({}, layer.defaultOptions);
		this._setLayerStyle(layer, this.options.style);
		return this;
	},

	// @method setStyle( <Function> style ): this
	// Changes styles of GeoJSON vector layers with the given style function.
	setStyle: function (style) {
		return this.eachLayer(function (layer) {
			this._setLayerStyle(layer, style);
		}, this);
	},

	_setLayerStyle: function (layer, style) {
		if (layer.setStyle) {
			if (typeof style === 'function') {
				style = style(layer.feature);
			}
			layer.setStyle(style);
		}
	}
});

// @section
// There are several static functions which can be called without instantiating L.GeoJSON:

// @function geometryToLayer(featureData: Object, options?: GeoJSON options): Layer
// Creates a `Layer` from a given GeoJSON feature. Can use a custom
// [`pointToLayer`](#geojson-pointtolayer) and/or [`coordsToLatLng`](#geojson-coordstolatlng)
// functions if provided as options.
function geometryToLayer(geojson, options) {

	var geometry = geojson.type === 'Feature' ? geojson.geometry : geojson,
	    coords = geometry ? geometry.coordinates : null,
	    layers = [],
	    pointToLayer = options && options.pointToLayer,
	    _coordsToLatLng = options && options.coordsToLatLng || coordsToLatLng,
	    latlng, latlngs, i, len;

	if (!coords && !geometry) {
		return null;
	}

	switch (geometry.type) {
	case 'Point':
		latlng = _coordsToLatLng(coords);
		return _pointToLayer(pointToLayer, geojson, latlng, options);

	case 'MultiPoint':
		for (i = 0, len = coords.length; i < len; i++) {
			latlng = _coordsToLatLng(coords[i]);
			layers.push(_pointToLayer(pointToLayer, geojson, latlng, options));
		}
		return new FeatureGroup(layers);

	case 'LineString':
	case 'MultiLineString':
		latlngs = coordsToLatLngs(coords, geometry.type === 'LineString' ? 0 : 1, _coordsToLatLng);
		return new Polyline(latlngs, options);

	case 'Polygon':
	case 'MultiPolygon':
		latlngs = coordsToLatLngs(coords, geometry.type === 'Polygon' ? 1 : 2, _coordsToLatLng);
		return new Polygon(latlngs, options);

	case 'GeometryCollection':
		for (i = 0, len = geometry.geometries.length; i < len; i++) {
			var layer = geometryToLayer({
				geometry: geometry.geometries[i],
				type: 'Feature',
				properties: geojson.properties
			}, options);

			if (layer) {
				layers.push(layer);
			}
		}
		return new FeatureGroup(layers);

	default:
		throw new Error('Invalid GeoJSON object.');
	}
}

function _pointToLayer(pointToLayerFn, geojson, latlng, options) {
	return pointToLayerFn ?
		pointToLayerFn(geojson, latlng) :
		new Marker(latlng, options && options.markersInheritOptions && options);
}

// @function coordsToLatLng(coords: Array): LatLng
// Creates a `LatLng` object from an array of 2 numbers (longitude, latitude)
// or 3 numbers (longitude, latitude, altitude) used in GeoJSON for points.
function coordsToLatLng(coords) {
	return new LatLng(coords[1], coords[0], coords[2]);
}

// @function coordsToLatLngs(coords: Array, levelsDeep?: Number, coordsToLatLng?: Function): Array
// Creates a multidimensional array of `LatLng`s from a GeoJSON coordinates array.
// `levelsDeep` specifies the nesting level (0 is for an array of points, 1 for an array of arrays of points, etc., 0 by default).
// Can use a custom [`coordsToLatLng`](#geojson-coordstolatlng) function.
function coordsToLatLngs(coords, levelsDeep, _coordsToLatLng) {
	var latlngs = [];

	for (var i = 0, len = coords.length, latlng; i < len; i++) {
		latlng = levelsDeep ?
			coordsToLatLngs(coords[i], levelsDeep - 1, _coordsToLatLng) :
			(_coordsToLatLng || coordsToLatLng)(coords[i]);

		latlngs.push(latlng);
	}

	return latlngs;
}

// @function latLngToCoords(latlng: LatLng, precision?: Number): Array
// Reverse of [`coordsToLatLng`](#geojson-coordstolatlng)
function latLngToCoords(latlng, precision) {
	precision = typeof precision === 'number' ? precision : 6;
	return latlng.alt !== undefined ?
		[formatNum(latlng.lng, precision), formatNum(latlng.lat, precision), formatNum(latlng.alt, precision)] :
		[formatNum(latlng.lng, precision), formatNum(latlng.lat, precision)];
}

// @function latLngsToCoords(latlngs: Array, levelsDeep?: Number, closed?: Boolean): Array
// Reverse of [`coordsToLatLngs`](#geojson-coordstolatlngs)
// `closed` determines whether the first point should be appended to the end of the array to close the feature, only used when `levelsDeep` is 0. False by default.
function latLngsToCoords(latlngs, levelsDeep, closed, precision) {
	var coords = [];

	for (var i = 0, len = latlngs.length; i < len; i++) {
		coords.push(levelsDeep ?
			latLngsToCoords(latlngs[i], levelsDeep - 1, closed, precision) :
			latLngToCoords(latlngs[i], precision));
	}

	if (!levelsDeep && closed) {
		coords.push(coords[0]);
	}

	return coords;
}

function getFeature(layer, newGeometry) {
	return layer.feature ?
		extend({}, layer.feature, {geometry: newGeometry}) :
		asFeature(newGeometry);
}

// @function asFeature(geojson: Object): Object
// Normalize GeoJSON geometries/features into GeoJSON features.
function asFeature(geojson) {
	if (geojson.type === 'Feature' || geojson.type === 'FeatureCollection') {
		return geojson;
	}

	return {
		type: 'Feature',
		properties: {},
		geometry: geojson
	};
}

var PointToGeoJSON = {
	toGeoJSON: function (precision) {
		return getFeature(this, {
			type: 'Point',
			coordinates: latLngToCoords(this.getLatLng(), precision)
		});
	}
};

// @namespace Marker
// @section Other methods
// @method toGeoJSON(precision?: Number): Object
// `precision` is the number of decimal places for coordinates.
// The default value is 6 places.
// Returns a [`GeoJSON`](http://en.wikipedia.org/wiki/GeoJSON) representation of the marker (as a GeoJSON `Point` Feature).
Marker.include(PointToGeoJSON);

// @namespace CircleMarker
// @method toGeoJSON(precision?: Number): Object
// `precision` is the number of decimal places for coordinates.
// The default value is 6 places.
// Returns a [`GeoJSON`](http://en.wikipedia.org/wiki/GeoJSON) representation of the circle marker (as a GeoJSON `Point` Feature).
Circle.include(PointToGeoJSON);
CircleMarker.include(PointToGeoJSON);


// @namespace Polyline
// @method toGeoJSON(precision?: Number): Object
// `precision` is the number of decimal places for coordinates.
// The default value is 6 places.
// Returns a [`GeoJSON`](http://en.wikipedia.org/wiki/GeoJSON) representation of the polyline (as a GeoJSON `LineString` or `MultiLineString` Feature).
Polyline.include({
	toGeoJSON: function (precision) {
		var multi = !isFlat(this._latlngs);

		var coords = latLngsToCoords(this._latlngs, multi ? 1 : 0, false, precision);

		return getFeature(this, {
			type: (multi ? 'Multi' : '') + 'LineString',
			coordinates: coords
		});
	}
});

// @namespace Polygon
// @method toGeoJSON(precision?: Number): Object
// `precision` is the number of decimal places for coordinates.
// The default value is 6 places.
// Returns a [`GeoJSON`](http://en.wikipedia.org/wiki/GeoJSON) representation of the polygon (as a GeoJSON `Polygon` or `MultiPolygon` Feature).
Polygon.include({
	toGeoJSON: function (precision) {
		var holes = !isFlat(this._latlngs),
		    multi = holes && !isFlat(this._latlngs[0]);

		var coords = latLngsToCoords(this._latlngs, multi ? 2 : holes ? 1 : 0, true, precision);

		if (!holes) {
			coords = [coords];
		}

		return getFeature(this, {
			type: (multi ? 'Multi' : '') + 'Polygon',
			coordinates: coords
		});
	}
});


// @namespace LayerGroup
LayerGroup$1.include({
	toMultiPoint: function (precision) {
		var coords = [];

		this.eachLayer(function (layer) {
			coords.push(layer.toGeoJSON(precision).geometry.coordinates);
		});

		return getFeature(this, {
			type: 'MultiPoint',
			coordinates: coords
		});
	},

	// @method toGeoJSON(precision?: Number): Object
	// `precision` is the number of decimal places for coordinates.
	// The default value is 6 places.
	// Returns a [`GeoJSON`](http://en.wikipedia.org/wiki/GeoJSON) representation of the layer group (as a GeoJSON `FeatureCollection`, `GeometryCollection`, or `MultiPoint`).
	toGeoJSON: function (precision) {

		var type = this.feature && this.feature.geometry && this.feature.geometry.type;

		if (type === 'MultiPoint') {
			return this.toMultiPoint(precision);
		}

		var isGeometryCollection = type === 'GeometryCollection',
		    jsons = [];

		this.eachLayer(function (layer) {
			if (layer.toGeoJSON) {
				var json = layer.toGeoJSON(precision);
				if (isGeometryCollection) {
					jsons.push(json.geometry);
				} else {
					var feature = asFeature(json);
					// Squash nested feature collections
					if (feature.type === 'FeatureCollection') {
						jsons.push.apply(jsons, feature.features);
					} else {
						jsons.push(feature);
					}
				}
			}
		});

		if (isGeometryCollection) {
			return getFeature(this, {
				geometries: jsons,
				type: 'GeometryCollection'
			});
		}

		return {
			type: 'FeatureCollection',
			features: jsons
		};
	}
});

/*
 * @class ImageOverlay
 * @aka L.ImageOverlay
 * @inherits Interactive layer
 *
 * Used to load and display a single image over specific bounds of the map. Extends `Layer`.
 *
 * @example
 *
 * ```js
 * var imageUrl = 'http://www.lib.utexas.edu/maps/historical/newark_nj_1922.jpg',
 * 	imageBounds = [[40.712216, -74.22655], [40.773941, -74.12544]];
 * L.imageOverlay(imageUrl, imageBounds).addTo(map);
 * ```
 */

var ImageOverlay = Layer.extend({

	// @section
	// @aka ImageOverlay options
	options: {
		// @option opacity: Number = 1.0
		// The opacity of the image overlay.
		opacity: 1,

		// @option alt: String = ''
		// Text for the `alt` attribute of the image (useful for accessibility).
		alt: '',

		// @option interactive: Boolean = false
		// If `true`, the image overlay will emit [mouse events](#interactive-layer) when clicked or hovered.
		interactive: false,

		// @option crossOrigin: Boolean|String = false
		// Whether the crossOrigin attribute will be added to the image.
		// If a String is provided, the image will have its crossOrigin attribute set to the String provided. This is needed if you want to access image pixel data.
		// Refer to [CORS Settings](https://developer.mozilla.org/en-US/docs/Web/HTML/CORS_settings_attributes) for valid String values.
		crossOrigin: false,

		// @option errorOverlayUrl: String = ''
		// URL to the overlay image to show in place of the overlay that failed to load.
		errorOverlayUrl: '',

		// @option zIndex: Number = 1
		// The explicit [zIndex](https://developer.mozilla.org/docs/Web/CSS/CSS_Positioning/Understanding_z_index) of the overlay layer.
		zIndex: 1,

		// @option className: String = ''
		// A custom class name to assign to the image. Empty by default.
		className: ''
	},

	initialize: function (url, bounds, options) { // (String, LatLngBounds, Object)
		this._url = url;
		this._bounds = toLatLngBounds(bounds);

		setOptions$1(this, options);
	},

	onAdd: function () {
		if (!this._image) {
			this._initImage();

			if (this.options.opacity < 1) {
				this._updateOpacity();
			}
		}

		if (this.options.interactive) {
			addClass(this._image, 'leaflet-interactive');
			this.addInteractiveTarget(this._image);
		}

		this.getPane().appendChild(this._image);
		this._reset();
	},

	onRemove: function () {
		remove(this._image);
		if (this.options.interactive) {
			this.removeInteractiveTarget(this._image);
		}
	},

	// @method setOpacity(opacity: Number): this
	// Sets the opacity of the overlay.
	setOpacity: function (opacity) {
		this.options.opacity = opacity;

		if (this._image) {
			this._updateOpacity();
		}
		return this;
	},

	setStyle: function (styleOpts) {
		if (styleOpts.opacity) {
			this.setOpacity(styleOpts.opacity);
		}
		return this;
	},

	// @method bringToFront(): this
	// Brings the layer to the top of all overlays.
	bringToFront: function () {
		if (this._map) {
			toFront(this._image);
		}
		return this;
	},

	// @method bringToBack(): this
	// Brings the layer to the bottom of all overlays.
	bringToBack: function () {
		if (this._map) {
			toBack(this._image);
		}
		return this;
	},

	// @method setUrl(url: String): this
	// Changes the URL of the image.
	setUrl: function (url) {
		this._url = url;

		if (this._image) {
			this._image.src = url;
		}
		return this;
	},

	// @method setBounds(bounds: LatLngBounds): this
	// Update the bounds that this ImageOverlay covers
	setBounds: function (bounds) {
		this._bounds = toLatLngBounds(bounds);

		if (this._map) {
			this._reset();
		}
		return this;
	},

	getEvents: function () {
		var events = {
			zoom: this._reset,
			viewreset: this._reset
		};

		if (this._zoomAnimated) {
			events.zoomanim = this._animateZoom;
		}

		return events;
	},

	// @method setZIndex(value: Number): this
	// Changes the [zIndex](#imageoverlay-zindex) of the image overlay.
	setZIndex: function (value) {
		this.options.zIndex = value;
		this._updateZIndex();
		return this;
	},

	// @method getBounds(): LatLngBounds
	// Get the bounds that this ImageOverlay covers
	getBounds: function () {
		return this._bounds;
	},

	// @method getElement(): HTMLElement
	// Returns the instance of [`HTMLImageElement`](https://developer.mozilla.org/docs/Web/API/HTMLImageElement)
	// used by this overlay.
	getElement: function () {
		return this._image;
	},

	_initImage: function () {
		var wasElementSupplied = this._url.tagName === 'IMG';
		var img = this._image = wasElementSupplied ? this._url : create$1('img');

		addClass(img, 'leaflet-image-layer');
		if (this._zoomAnimated) { addClass(img, 'leaflet-zoom-animated'); }
		if (this.options.className) { addClass(img, this.options.className); }

		img.onselectstart = falseFn;
		img.onmousemove = falseFn;

		// @event load: Event
		// Fired when the ImageOverlay layer has loaded its image
		img.onload = bind(this.fire, this, 'load');
		img.onerror = bind(this._overlayOnError, this, 'error');

		if (this.options.crossOrigin || this.options.crossOrigin === '') {
			img.crossOrigin = this.options.crossOrigin === true ? '' : this.options.crossOrigin;
		}

		if (this.options.zIndex) {
			this._updateZIndex();
		}

		if (wasElementSupplied) {
			this._url = img.src;
			return;
		}

		img.src = this._url;
		img.alt = this.options.alt;
	},

	_animateZoom: function (e) {
		var scale = this._map.getZoomScale(e.zoom),
		    offset = this._map._latLngBoundsToNewLayerBounds(this._bounds, e.zoom, e.center).min;

		setTransform(this._image, offset, scale);
	},

	_reset: function () {
		var image = this._image,
		    bounds = new Bounds(
		        this._map.latLngToLayerPoint(this._bounds.getNorthWest()),
		        this._map.latLngToLayerPoint(this._bounds.getSouthEast())),
		    size = bounds.getSize();

		setPosition(image, bounds.min);

		image.style.width  = size.x + 'px';
		image.style.height = size.y + 'px';
	},

	_updateOpacity: function () {
		setOpacity(this._image, this.options.opacity);
	},

	_updateZIndex: function () {
		if (this._image && this.options.zIndex !== undefined && this.options.zIndex !== null) {
			this._image.style.zIndex = this.options.zIndex;
		}
	},

	_overlayOnError: function () {
		// @event error: Event
		// Fired when the ImageOverlay layer fails to load its image
		this.fire('error');

		var errorUrl = this.options.errorOverlayUrl;
		if (errorUrl && this._url !== errorUrl) {
			this._url = errorUrl;
			this._image.src = errorUrl;
		}
	}
});

/*
 * @class VideoOverlay
 * @aka L.VideoOverlay
 * @inherits ImageOverlay
 *
 * Used to load and display a video player over specific bounds of the map. Extends `ImageOverlay`.
 *
 * A video overlay uses the [`<video>`](https://developer.mozilla.org/docs/Web/HTML/Element/video)
 * HTML5 element.
 *
 * @example
 *
 * ```js
 * var videoUrl = 'https://www.mapbox.com/bites/00188/patricia_nasa.webm',
 * 	videoBounds = [[ 32, -130], [ 13, -100]];
 * L.videoOverlay(videoUrl, videoBounds ).addTo(map);
 * ```
 */

var VideoOverlay = ImageOverlay.extend({

	// @section
	// @aka VideoOverlay options
	options: {
		// @option autoplay: Boolean = true
		// Whether the video starts playing automatically when loaded.
		autoplay: true,

		// @option loop: Boolean = true
		// Whether the video will loop back to the beginning when played.
		loop: true,

		// @option keepAspectRatio: Boolean = true
		// Whether the video will save aspect ratio after the projection.
		// Relevant for supported browsers. Browser compatibility- https://developer.mozilla.org/en-US/docs/Web/CSS/object-fit
		keepAspectRatio: true
	},

	_initImage: function () {
		var wasElementSupplied = this._url.tagName === 'VIDEO';
		var vid = this._image = wasElementSupplied ? this._url : create$1('video');

		addClass(vid, 'leaflet-image-layer');
		if (this._zoomAnimated) { addClass(vid, 'leaflet-zoom-animated'); }
		if (this.options.className) { addClass(vid, this.options.className); }

		vid.onselectstart = falseFn;
		vid.onmousemove = falseFn;

		// @event load: Event
		// Fired when the video has finished loading the first frame
		vid.onloadeddata = bind(this.fire, this, 'load');

		if (wasElementSupplied) {
			var sourceElements = vid.getElementsByTagName('source');
			var sources = [];
			for (var j = 0; j < sourceElements.length; j++) {
				sources.push(sourceElements[j].src);
			}

			this._url = (sourceElements.length > 0) ? sources : [vid.src];
			return;
		}

		if (!isArray(this._url)) { this._url = [this._url]; }

		if (!this.options.keepAspectRatio && vid.style.hasOwnProperty('objectFit')) { vid.style['objectFit'] = 'fill'; }
		vid.autoplay = !!this.options.autoplay;
		vid.loop = !!this.options.loop;
		for (var i = 0; i < this._url.length; i++) {
			var source = create$1('source');
			source.src = this._url[i];
			vid.appendChild(source);
		}
	}

	// @method getElement(): HTMLVideoElement
	// Returns the instance of [`HTMLVideoElement`](https://developer.mozilla.org/docs/Web/API/HTMLVideoElement)
	// used by this overlay.
});

/*
 * @class SVGOverlay
 * @aka L.SVGOverlay
 * @inherits ImageOverlay
 *
 * Used to load, display and provide DOM access to an SVG file over specific bounds of the map. Extends `ImageOverlay`.
 *
 * An SVG overlay uses the [`<svg>`](https://developer.mozilla.org/docs/Web/SVG/Element/svg) element.
 *
 * @example
 *
 * ```js
 * var svgElement = document.createElementNS("http://www.w3.org/2000/svg", "svg");
 * svgElement.setAttribute('xmlns', "http://www.w3.org/2000/svg");
 * svgElement.setAttribute('viewBox', "0 0 200 200");
 * svgElement.innerHTML = '<rect width="200" height="200"/><rect x="75" y="23" width="50" height="50" style="fill:red"/><rect x="75" y="123" width="50" height="50" style="fill:#0013ff"/>';
 * var svgElementBounds = [ [ 32, -130 ], [ 13, -100 ] ];
 * L.svgOverlay(svgElement, svgElementBounds).addTo(map);
 * ```
 */

var SVGOverlay = ImageOverlay.extend({
	_initImage: function () {
		var el = this._image = this._url;

		addClass(el, 'leaflet-image-layer');
		if (this._zoomAnimated) { addClass(el, 'leaflet-zoom-animated'); }
		if (this.options.className) { addClass(el, this.options.className); }

		el.onselectstart = falseFn;
		el.onmousemove = falseFn;
	}

	// @method getElement(): SVGElement
	// Returns the instance of [`SVGElement`](https://developer.mozilla.org/docs/Web/API/SVGElement)
	// used by this overlay.
});

/*
 * @class DivOverlay
 * @inherits Layer
 * @aka L.DivOverlay
 * Base model for L.Popup and L.Tooltip. Inherit from it for custom popup like plugins.
 */

// @namespace DivOverlay
var DivOverlay = Layer.extend({

	// @section
	// @aka DivOverlay options
	options: {
		// @option offset: Point = Point(0, 7)
		// The offset of the popup position. Useful to control the anchor
		// of the popup when opening it on some overlays.
		offset: [0, 7],

		// @option className: String = ''
		// A custom CSS class name to assign to the popup.
		className: '',

		// @option pane: String = 'popupPane'
		// `Map pane` where the popup will be added.
		pane: 'popupPane'
	},

	initialize: function (options, source) {
		setOptions$1(this, options);

		this._source = source;
	},

	onAdd: function (map) {
		this._zoomAnimated = map._zoomAnimated;

		if (!this._container) {
			this._initLayout();
		}

		if (map._fadeAnimated) {
			setOpacity(this._container, 0);
		}

		clearTimeout(this._removeTimeout);
		this.getPane().appendChild(this._container);
		this.update();

		if (map._fadeAnimated) {
			setOpacity(this._container, 1);
		}

		this.bringToFront();
	},

	onRemove: function (map) {
		if (map._fadeAnimated) {
			setOpacity(this._container, 0);
			this._removeTimeout = setTimeout(bind(remove, undefined, this._container), 200);
		} else {
			remove(this._container);
		}
	},

	// @namespace Popup
	// @method getLatLng: LatLng
	// Returns the geographical point of popup.
	getLatLng: function () {
		return this._latlng;
	},

	// @method setLatLng(latlng: LatLng): this
	// Sets the geographical point where the popup will open.
	setLatLng: function (latlng) {
		this._latlng = toLatLng(latlng);
		if (this._map) {
			this._updatePosition();
			this._adjustPan();
		}
		return this;
	},

	// @method getContent: String|HTMLElement
	// Returns the content of the popup.
	getContent: function () {
		return this._content;
	},

	// @method setContent(htmlContent: String|HTMLElement|Function): this
	// Sets the HTML content of the popup. If a function is passed the source layer will be passed to the function. The function should return a `String` or `HTMLElement` to be used in the popup.
	setContent: function (content) {
		this._content = content;
		this.update();
		return this;
	},

	// @method getElement: String|HTMLElement
	// Alias for [getContent()](#popup-getcontent)
	getElement: function () {
		return this._container;
	},

	// @method update: null
	// Updates the popup content, layout and position. Useful for updating the popup after something inside changed, e.g. image loaded.
	update: function () {
		if (!this._map) { return; }

		this._container.style.visibility = 'hidden';

		this._updateContent();
		this._updateLayout();
		this._updatePosition();

		this._container.style.visibility = '';

		this._adjustPan();
	},

	getEvents: function () {
		var events = {
			zoom: this._updatePosition,
			viewreset: this._updatePosition
		};

		if (this._zoomAnimated) {
			events.zoomanim = this._animateZoom;
		}
		return events;
	},

	// @method isOpen: Boolean
	// Returns `true` when the popup is visible on the map.
	isOpen: function () {
		return !!this._map && this._map.hasLayer(this);
	},

	// @method bringToFront: this
	// Brings this popup in front of other popups (in the same map pane).
	bringToFront: function () {
		if (this._map) {
			toFront(this._container);
		}
		return this;
	},

	// @method bringToBack: this
	// Brings this popup to the back of other popups (in the same map pane).
	bringToBack: function () {
		if (this._map) {
			toBack(this._container);
		}
		return this;
	},

	_prepareOpen: function (parent, layer, latlng) {
		if (!(layer instanceof Layer)) {
			latlng = layer;
			layer = parent;
		}

		if (layer instanceof FeatureGroup) {
			for (var id in parent._layers) {
				layer = parent._layers[id];
				break;
			}
		}

		if (!latlng) {
			if (layer.getCenter) {
				latlng = layer.getCenter();
			} else if (layer.getLatLng) {
				latlng = layer.getLatLng();
			} else {
				throw new Error('Unable to get source layer LatLng.');
			}
		}

		// set overlay source to this layer
		this._source = layer;

		// update the overlay (content, layout, ect...)
		this.update();

		return latlng;
	},

	_updateContent: function () {
		if (!this._content) { return; }

		var node = this._contentNode;
		var content = (typeof this._content === 'function') ? this._content(this._source || this) : this._content;

		if (typeof content === 'string') {
			node.innerHTML = content;
		} else {
			while (node.hasChildNodes()) {
				node.removeChild(node.firstChild);
			}
			node.appendChild(content);
		}
		this.fire('contentupdate');
	},

	_updatePosition: function () {
		if (!this._map) { return; }

		var pos = this._map.latLngToLayerPoint(this._latlng),
		    offset = toPoint(this.options.offset),
		    anchor = this._getAnchor();

		if (this._zoomAnimated) {
			setPosition(this._container, pos.add(anchor));
		} else {
			offset = offset.add(pos).add(anchor);
		}

		var bottom = this._containerBottom = -offset.y,
		    left = this._containerLeft = -Math.round(this._containerWidth / 2) + offset.x;

		// bottom position the popup in case the height of the popup changes (images loading etc)
		this._container.style.bottom = bottom + 'px';
		this._container.style.left = left + 'px';
	},

	_getAnchor: function () {
		return [0, 0];
	}

});

/*
 * @class Popup
 * @inherits DivOverlay
 * @aka L.Popup
 * Used to open popups in certain places of the map. Use [Map.openPopup](#map-openpopup) to
 * open popups while making sure that only one popup is open at one time
 * (recommended for usability), or use [Map.addLayer](#map-addlayer) to open as many as you want.
 *
 * @example
 *
 * If you want to just bind a popup to marker click and then open it, it's really easy:
 *
 * ```js
 * marker.bindPopup(popupContent).openPopup();
 * ```
 * Path overlays like polylines also have a `bindPopup` method.
 * Here's a more complicated way to open a popup on a map:
 *
 * ```js
 * var popup = L.popup()
 * 	.setLatLng(latlng)
 * 	.setContent('<p>Hello world!<br />This is a nice popup.</p>')
 * 	.openOn(map);
 * ```
 */


// @namespace Popup
var Popup = DivOverlay.extend({

	// @section
	// @aka Popup options
	options: {
		// @option maxWidth: Number = 300
		// Max width of the popup, in pixels.
		maxWidth: 300,

		// @option minWidth: Number = 50
		// Min width of the popup, in pixels.
		minWidth: 50,

		// @option maxHeight: Number = null
		// If set, creates a scrollable container of the given height
		// inside a popup if its content exceeds it.
		maxHeight: null,

		// @option autoPan: Boolean = true
		// Set it to `false` if you don't want the map to do panning animation
		// to fit the opened popup.
		autoPan: true,

		// @option autoPanPaddingTopLeft: Point = null
		// The margin between the popup and the top left corner of the map
		// view after autopanning was performed.
		autoPanPaddingTopLeft: null,

		// @option autoPanPaddingBottomRight: Point = null
		// The margin between the popup and the bottom right corner of the map
		// view after autopanning was performed.
		autoPanPaddingBottomRight: null,

		// @option autoPanPadding: Point = Point(5, 5)
		// Equivalent of setting both top left and bottom right autopan padding to the same value.
		autoPanPadding: [5, 5],

		// @option keepInView: Boolean = false
		// Set it to `true` if you want to prevent users from panning the popup
		// off of the screen while it is open.
		keepInView: false,

		// @option closeButton: Boolean = true
		// Controls the presence of a close button in the popup.
		closeButton: true,

		// @option autoClose: Boolean = true
		// Set it to `false` if you want to override the default behavior of
		// the popup closing when another popup is opened.
		autoClose: true,

		// @option closeOnEscapeKey: Boolean = true
		// Set it to `false` if you want to override the default behavior of
		// the ESC key for closing of the popup.
		closeOnEscapeKey: true,

		// @option closeOnClick: Boolean = *
		// Set it if you want to override the default behavior of the popup closing when user clicks
		// on the map. Defaults to the map's [`closePopupOnClick`](#map-closepopuponclick) option.

		// @option className: String = ''
		// A custom CSS class name to assign to the popup.
		className: ''
	},

	// @namespace Popup
	// @method openOn(map: Map): this
	// Adds the popup to the map and closes the previous one. The same as `map.openPopup(popup)`.
	openOn: function (map) {
		map.openPopup(this);
		return this;
	},

	onAdd: function (map) {
		DivOverlay.prototype.onAdd.call(this, map);

		// @namespace Map
		// @section Popup events
		// @event popupopen: PopupEvent
		// Fired when a popup is opened in the map
		map.fire('popupopen', {popup: this});

		if (this._source) {
			// @namespace Layer
			// @section Popup events
			// @event popupopen: PopupEvent
			// Fired when a popup bound to this layer is opened
			this._source.fire('popupopen', {popup: this}, true);
			// For non-path layers, we toggle the popup when clicking
			// again the layer, so prevent the map to reopen it.
			if (!(this._source instanceof Path)) {
				this._source.on('preclick', stopPropagation);
			}
		}
	},

	onRemove: function (map) {
		DivOverlay.prototype.onRemove.call(this, map);

		// @namespace Map
		// @section Popup events
		// @event popupclose: PopupEvent
		// Fired when a popup in the map is closed
		map.fire('popupclose', {popup: this});

		if (this._source) {
			// @namespace Layer
			// @section Popup events
			// @event popupclose: PopupEvent
			// Fired when a popup bound to this layer is closed
			this._source.fire('popupclose', {popup: this}, true);
			if (!(this._source instanceof Path)) {
				this._source.off('preclick', stopPropagation);
			}
		}
	},

	getEvents: function () {
		var events = DivOverlay.prototype.getEvents.call(this);

		if (this.options.closeOnClick !== undefined ? this.options.closeOnClick : this._map.options.closePopupOnClick) {
			events.preclick = this._close;
		}

		if (this.options.keepInView) {
			events.moveend = this._adjustPan;
		}

		return events;
	},

	_close: function () {
		if (this._map) {
			this._map.closePopup(this);
		}
	},

	_initLayout: function () {
		var prefix = 'leaflet-popup',
		    container = this._container = create$1('div',
			prefix + ' ' + (this.options.className || '') +
			' leaflet-zoom-animated');

		var wrapper = this._wrapper = create$1('div', prefix + '-content-wrapper', container);
		this._contentNode = create$1('div', prefix + '-content', wrapper);

		disableClickPropagation(wrapper);
		disableScrollPropagation(this._contentNode);
		on(wrapper, 'contextmenu', stopPropagation);

		this._tipContainer = create$1('div', prefix + '-tip-container', container);
		this._tip = create$1('div', prefix + '-tip', this._tipContainer);

		if (this.options.closeButton) {
			var closeButton = this._closeButton = create$1('a', prefix + '-close-button', container);
			closeButton.href = '#close';
			closeButton.innerHTML = '&#215;';

			on(closeButton, 'click', this._onCloseButtonClick, this);
		}
	},

	_updateLayout: function () {
		var container = this._contentNode,
		    style = container.style;

		style.width = '';
		style.whiteSpace = 'nowrap';

		var width = container.offsetWidth;
		width = Math.min(width, this.options.maxWidth);
		width = Math.max(width, this.options.minWidth);

		style.width = (width + 1) + 'px';
		style.whiteSpace = '';

		style.height = '';

		var height = container.offsetHeight,
		    maxHeight = this.options.maxHeight,
		    scrolledClass = 'leaflet-popup-scrolled';

		if (maxHeight && height > maxHeight) {
			style.height = maxHeight + 'px';
			addClass(container, scrolledClass);
		} else {
			removeClass(container, scrolledClass);
		}

		this._containerWidth = this._container.offsetWidth;
	},

	_animateZoom: function (e) {
		var pos = this._map._latLngToNewLayerPoint(this._latlng, e.zoom, e.center),
		    anchor = this._getAnchor();
		setPosition(this._container, pos.add(anchor));
	},

	_adjustPan: function () {
		if (!this.options.autoPan) { return; }
		if (this._map._panAnim) { this._map._panAnim.stop(); }

		var map = this._map,
		    marginBottom = parseInt(getStyle(this._container, 'marginBottom'), 10) || 0,
		    containerHeight = this._container.offsetHeight + marginBottom,
		    containerWidth = this._containerWidth,
		    layerPos = new Point(this._containerLeft, -containerHeight - this._containerBottom);

		layerPos._add(getPosition(this._container));

		var containerPos = map.layerPointToContainerPoint(layerPos),
		    padding = toPoint(this.options.autoPanPadding),
		    paddingTL = toPoint(this.options.autoPanPaddingTopLeft || padding),
		    paddingBR = toPoint(this.options.autoPanPaddingBottomRight || padding),
		    size = map.getSize(),
		    dx = 0,
		    dy = 0;

		if (containerPos.x + containerWidth + paddingBR.x > size.x) { // right
			dx = containerPos.x + containerWidth - size.x + paddingBR.x;
		}
		if (containerPos.x - dx - paddingTL.x < 0) { // left
			dx = containerPos.x - paddingTL.x;
		}
		if (containerPos.y + containerHeight + paddingBR.y > size.y) { // bottom
			dy = containerPos.y + containerHeight - size.y + paddingBR.y;
		}
		if (containerPos.y - dy - paddingTL.y < 0) { // top
			dy = containerPos.y - paddingTL.y;
		}

		// @namespace Map
		// @section Popup events
		// @event autopanstart: Event
		// Fired when the map starts autopanning when opening a popup.
		if (dx || dy) {
			map
			    .fire('autopanstart')
			    .panBy([dx, dy]);
		}
	},

	_onCloseButtonClick: function (e) {
		this._close();
		stop(e);
	},

	_getAnchor: function () {
		// Where should we anchor the popup on the source layer?
		return toPoint(this._source && this._source._getPopupAnchor ? this._source._getPopupAnchor() : [0, 0]);
	}

});


/* @namespace Map
 * @section Interaction Options
 * @option closePopupOnClick: Boolean = true
 * Set it to `false` if you don't want popups to close when user clicks the map.
 */
Map$1.mergeOptions({
	closePopupOnClick: true
});


// @namespace Map
// @section Methods for Layers and Controls
Map$1.include({
	// @method openPopup(popup: Popup): this
	// Opens the specified popup while closing the previously opened (to make sure only one is opened at one time for usability).
	// @alternative
	// @method openPopup(content: String|HTMLElement, latlng: LatLng, options?: Popup options): this
	// Creates a popup with the specified content and options and opens it in the given point on a map.
	openPopup: function (popup, latlng, options) {
		if (!(popup instanceof Popup)) {
			popup = new Popup(options).setContent(popup);
		}

		if (latlng) {
			popup.setLatLng(latlng);
		}

		if (this.hasLayer(popup)) {
			return this;
		}

		if (this._popup && this._popup.options.autoClose) {
			this.closePopup();
		}

		this._popup = popup;
		return this.addLayer(popup);
	},

	// @method closePopup(popup?: Popup): this
	// Closes the popup previously opened with [openPopup](#map-openpopup) (or the given one).
	closePopup: function (popup) {
		if (!popup || popup === this._popup) {
			popup = this._popup;
			this._popup = null;
		}
		if (popup) {
			this.removeLayer(popup);
		}
		return this;
	}
});

/*
 * @namespace Layer
 * @section Popup methods example
 *
 * All layers share a set of methods convenient for binding popups to it.
 *
 * ```js
 * var layer = L.Polygon(latlngs).bindPopup('Hi There!').addTo(map);
 * layer.openPopup();
 * layer.closePopup();
 * ```
 *
 * Popups will also be automatically opened when the layer is clicked on and closed when the layer is removed from the map or another popup is opened.
 */

// @section Popup methods
Layer.include({

	// @method bindPopup(content: String|HTMLElement|Function|Popup, options?: Popup options): this
	// Binds a popup to the layer with the passed `content` and sets up the
	// necessary event listeners. If a `Function` is passed it will receive
	// the layer as the first argument and should return a `String` or `HTMLElement`.
	bindPopup: function (content, options) {

		if (content instanceof Popup) {
			setOptions$1(content, options);
			this._popup = content;
			content._source = this;
		} else {
			if (!this._popup || options) {
				this._popup = new Popup(options, this);
			}
			this._popup.setContent(content);
		}

		if (!this._popupHandlersAdded) {
			this.on({
				click: this._openPopup,
				keypress: this._onKeyPress,
				remove: this.closePopup,
				move: this._movePopup
			});
			this._popupHandlersAdded = true;
		}

		return this;
	},

	// @method unbindPopup(): this
	// Removes the popup previously bound with `bindPopup`.
	unbindPopup: function () {
		if (this._popup) {
			this.off({
				click: this._openPopup,
				keypress: this._onKeyPress,
				remove: this.closePopup,
				move: this._movePopup
			});
			this._popupHandlersAdded = false;
			this._popup = null;
		}
		return this;
	},

	// @method openPopup(latlng?: LatLng): this
	// Opens the bound popup at the specified `latlng` or at the default popup anchor if no `latlng` is passed.
	openPopup: function (layer, latlng) {
		if (this._popup && this._map) {
			latlng = this._popup._prepareOpen(this, layer, latlng);

			// open the popup on the map
			this._map.openPopup(this._popup, latlng);
		}

		return this;
	},

	// @method closePopup(): this
	// Closes the popup bound to this layer if it is open.
	closePopup: function () {
		if (this._popup) {
			this._popup._close();
		}
		return this;
	},

	// @method togglePopup(): this
	// Opens or closes the popup bound to this layer depending on its current state.
	togglePopup: function (target) {
		if (this._popup) {
			if (this._popup._map) {
				this.closePopup();
			} else {
				this.openPopup(target);
			}
		}
		return this;
	},

	// @method isPopupOpen(): boolean
	// Returns `true` if the popup bound to this layer is currently open.
	isPopupOpen: function () {
		return (this._popup ? this._popup.isOpen() : false);
	},

	// @method setPopupContent(content: String|HTMLElement|Popup): this
	// Sets the content of the popup bound to this layer.
	setPopupContent: function (content) {
		if (this._popup) {
			this._popup.setContent(content);
		}
		return this;
	},

	// @method getPopup(): Popup
	// Returns the popup bound to this layer.
	getPopup: function () {
		return this._popup;
	},

	_openPopup: function (e) {
		var layer = e.layer || e.target;

		if (!this._popup) {
			return;
		}

		if (!this._map) {
			return;
		}

		// prevent map click
		stop(e);

		// if this inherits from Path its a vector and we can just
		// open the popup at the new location
		if (layer instanceof Path) {
			this.openPopup(e.layer || e.target, e.latlng);
			return;
		}

		// otherwise treat it like a marker and figure out
		// if we should toggle it open/closed
		if (this._map.hasLayer(this._popup) && this._popup._source === layer) {
			this.closePopup();
		} else {
			this.openPopup(layer, e.latlng);
		}
	},

	_movePopup: function (e) {
		this._popup.setLatLng(e.latlng);
	},

	_onKeyPress: function (e) {
		if (e.originalEvent.keyCode === 13) {
			this._openPopup(e);
		}
	}
});

/*
 * @class Tooltip
 * @inherits DivOverlay
 * @aka L.Tooltip
 * Used to display small texts on top of map layers.
 *
 * @example
 *
 * ```js
 * marker.bindTooltip("my tooltip text").openTooltip();
 * ```
 * Note about tooltip offset. Leaflet takes two options in consideration
 * for computing tooltip offsetting:
 * - the `offset` Tooltip option: it defaults to [0, 0], and it's specific to one tooltip.
 *   Add a positive x offset to move the tooltip to the right, and a positive y offset to
 *   move it to the bottom. Negatives will move to the left and top.
 * - the `tooltipAnchor` Icon option: this will only be considered for Marker. You
 *   should adapt this value if you use a custom icon.
 */


// @namespace Tooltip
var Tooltip = DivOverlay.extend({

	// @section
	// @aka Tooltip options
	options: {
		// @option pane: String = 'tooltipPane'
		// `Map pane` where the tooltip will be added.
		pane: 'tooltipPane',

		// @option offset: Point = Point(0, 0)
		// Optional offset of the tooltip position.
		offset: [0, 0],

		// @option direction: String = 'auto'
		// Direction where to open the tooltip. Possible values are: `right`, `left`,
		// `top`, `bottom`, `center`, `auto`.
		// `auto` will dynamically switch between `right` and `left` according to the tooltip
		// position on the map.
		direction: 'auto',

		// @option permanent: Boolean = false
		// Whether to open the tooltip permanently or only on mouseover.
		permanent: false,

		// @option sticky: Boolean = false
		// If true, the tooltip will follow the mouse instead of being fixed at the feature center.
		sticky: false,

		// @option interactive: Boolean = false
		// If true, the tooltip will listen to the feature events.
		interactive: false,

		// @option opacity: Number = 0.9
		// Tooltip container opacity.
		opacity: 0.9
	},

	onAdd: function (map) {
		DivOverlay.prototype.onAdd.call(this, map);
		this.setOpacity(this.options.opacity);

		// @namespace Map
		// @section Tooltip events
		// @event tooltipopen: TooltipEvent
		// Fired when a tooltip is opened in the map.
		map.fire('tooltipopen', {tooltip: this});

		if (this._source) {
			// @namespace Layer
			// @section Tooltip events
			// @event tooltipopen: TooltipEvent
			// Fired when a tooltip bound to this layer is opened.
			this._source.fire('tooltipopen', {tooltip: this}, true);
		}
	},

	onRemove: function (map) {
		DivOverlay.prototype.onRemove.call(this, map);

		// @namespace Map
		// @section Tooltip events
		// @event tooltipclose: TooltipEvent
		// Fired when a tooltip in the map is closed.
		map.fire('tooltipclose', {tooltip: this});

		if (this._source) {
			// @namespace Layer
			// @section Tooltip events
			// @event tooltipclose: TooltipEvent
			// Fired when a tooltip bound to this layer is closed.
			this._source.fire('tooltipclose', {tooltip: this}, true);
		}
	},

	getEvents: function () {
		var events = DivOverlay.prototype.getEvents.call(this);

		if (touch && !this.options.permanent) {
			events.preclick = this._close;
		}

		return events;
	},

	_close: function () {
		if (this._map) {
			this._map.closeTooltip(this);
		}
	},

	_initLayout: function () {
		var prefix = 'leaflet-tooltip',
		    className = prefix + ' ' + (this.options.className || '') + ' leaflet-zoom-' + (this._zoomAnimated ? 'animated' : 'hide');

		this._contentNode = this._container = create$1('div', className);
	},

	_updateLayout: function () {},

	_adjustPan: function () {},

	_setPosition: function (pos) {
		var map = this._map,
		    container = this._container,
		    centerPoint = map.latLngToContainerPoint(map.getCenter()),
		    tooltipPoint = map.layerPointToContainerPoint(pos),
		    direction = this.options.direction,
		    tooltipWidth = container.offsetWidth,
		    tooltipHeight = container.offsetHeight,
		    offset = toPoint(this.options.offset),
		    anchor = this._getAnchor();

		if (direction === 'top') {
			pos = pos.add(toPoint(-tooltipWidth / 2 + offset.x, -tooltipHeight + offset.y + anchor.y, true));
		} else if (direction === 'bottom') {
			pos = pos.subtract(toPoint(tooltipWidth / 2 - offset.x, -offset.y, true));
		} else if (direction === 'center') {
			pos = pos.subtract(toPoint(tooltipWidth / 2 + offset.x, tooltipHeight / 2 - anchor.y + offset.y, true));
		} else if (direction === 'right' || direction === 'auto' && tooltipPoint.x < centerPoint.x) {
			direction = 'right';
			pos = pos.add(toPoint(offset.x + anchor.x, anchor.y - tooltipHeight / 2 + offset.y, true));
		} else {
			direction = 'left';
			pos = pos.subtract(toPoint(tooltipWidth + anchor.x - offset.x, tooltipHeight / 2 - anchor.y - offset.y, true));
		}

		removeClass(container, 'leaflet-tooltip-right');
		removeClass(container, 'leaflet-tooltip-left');
		removeClass(container, 'leaflet-tooltip-top');
		removeClass(container, 'leaflet-tooltip-bottom');
		addClass(container, 'leaflet-tooltip-' + direction);
		setPosition(container, pos);
	},

	_updatePosition: function () {
		var pos = this._map.latLngToLayerPoint(this._latlng);
		this._setPosition(pos);
	},

	setOpacity: function (opacity) {
		this.options.opacity = opacity;

		if (this._container) {
			setOpacity(this._container, opacity);
		}
	},

	_animateZoom: function (e) {
		var pos = this._map._latLngToNewLayerPoint(this._latlng, e.zoom, e.center);
		this._setPosition(pos);
	},

	_getAnchor: function () {
		// Where should we anchor the tooltip on the source layer?
		return toPoint(this._source && this._source._getTooltipAnchor && !this.options.sticky ? this._source._getTooltipAnchor() : [0, 0]);
	}

});

// @namespace Map
// @section Methods for Layers and Controls
Map$1.include({

	// @method openTooltip(tooltip: Tooltip): this
	// Opens the specified tooltip.
	// @alternative
	// @method openTooltip(content: String|HTMLElement, latlng: LatLng, options?: Tooltip options): this
	// Creates a tooltip with the specified content and options and open it.
	openTooltip: function (tooltip, latlng, options) {
		if (!(tooltip instanceof Tooltip)) {
			tooltip = new Tooltip(options).setContent(tooltip);
		}

		if (latlng) {
			tooltip.setLatLng(latlng);
		}

		if (this.hasLayer(tooltip)) {
			return this;
		}

		return this.addLayer(tooltip);
	},

	// @method closeTooltip(tooltip?: Tooltip): this
	// Closes the tooltip given as parameter.
	closeTooltip: function (tooltip) {
		if (tooltip) {
			this.removeLayer(tooltip);
		}
		return this;
	}

});

/*
 * @namespace Layer
 * @section Tooltip methods example
 *
 * All layers share a set of methods convenient for binding tooltips to it.
 *
 * ```js
 * var layer = L.Polygon(latlngs).bindTooltip('Hi There!').addTo(map);
 * layer.openTooltip();
 * layer.closeTooltip();
 * ```
 */

// @section Tooltip methods
Layer.include({

	// @method bindTooltip(content: String|HTMLElement|Function|Tooltip, options?: Tooltip options): this
	// Binds a tooltip to the layer with the passed `content` and sets up the
	// necessary event listeners. If a `Function` is passed it will receive
	// the layer as the first argument and should return a `String` or `HTMLElement`.
	bindTooltip: function (content, options) {

		if (content instanceof Tooltip) {
			setOptions$1(content, options);
			this._tooltip = content;
			content._source = this;
		} else {
			if (!this._tooltip || options) {
				this._tooltip = new Tooltip(options, this);
			}
			this._tooltip.setContent(content);

		}

		this._initTooltipInteractions();

		if (this._tooltip.options.permanent && this._map && this._map.hasLayer(this)) {
			this.openTooltip();
		}

		return this;
	},

	// @method unbindTooltip(): this
	// Removes the tooltip previously bound with `bindTooltip`.
	unbindTooltip: function () {
		if (this._tooltip) {
			this._initTooltipInteractions(true);
			this.closeTooltip();
			this._tooltip = null;
		}
		return this;
	},

	_initTooltipInteractions: function (remove) {
		if (!remove && this._tooltipHandlersAdded) { return; }
		var onOff = remove ? 'off' : 'on',
		    events = {
			remove: this.closeTooltip,
			move: this._moveTooltip
		    };
		if (!this._tooltip.options.permanent) {
			events.mouseover = this._openTooltip;
			events.mouseout = this.closeTooltip;
			if (this._tooltip.options.sticky) {
				events.mousemove = this._moveTooltip;
			}
			if (touch) {
				events.click = this._openTooltip;
			}
		} else {
			events.add = this._openTooltip;
		}
		this[onOff](events);
		this._tooltipHandlersAdded = !remove;
	},

	// @method openTooltip(latlng?: LatLng): this
	// Opens the bound tooltip at the specified `latlng` or at the default tooltip anchor if no `latlng` is passed.
	openTooltip: function (layer, latlng) {
		if (this._tooltip && this._map) {
			latlng = this._tooltip._prepareOpen(this, layer, latlng);

			// open the tooltip on the map
			this._map.openTooltip(this._tooltip, latlng);

			// Tooltip container may not be defined if not permanent and never
			// opened.
			if (this._tooltip.options.interactive && this._tooltip._container) {
				addClass(this._tooltip._container, 'leaflet-clickable');
				this.addInteractiveTarget(this._tooltip._container);
			}
		}

		return this;
	},

	// @method closeTooltip(): this
	// Closes the tooltip bound to this layer if it is open.
	closeTooltip: function () {
		if (this._tooltip) {
			this._tooltip._close();
			if (this._tooltip.options.interactive && this._tooltip._container) {
				removeClass(this._tooltip._container, 'leaflet-clickable');
				this.removeInteractiveTarget(this._tooltip._container);
			}
		}
		return this;
	},

	// @method toggleTooltip(): this
	// Opens or closes the tooltip bound to this layer depending on its current state.
	toggleTooltip: function (target) {
		if (this._tooltip) {
			if (this._tooltip._map) {
				this.closeTooltip();
			} else {
				this.openTooltip(target);
			}
		}
		return this;
	},

	// @method isTooltipOpen(): boolean
	// Returns `true` if the tooltip bound to this layer is currently open.
	isTooltipOpen: function () {
		return this._tooltip.isOpen();
	},

	// @method setTooltipContent(content: String|HTMLElement|Tooltip): this
	// Sets the content of the tooltip bound to this layer.
	setTooltipContent: function (content) {
		if (this._tooltip) {
			this._tooltip.setContent(content);
		}
		return this;
	},

	// @method getTooltip(): Tooltip
	// Returns the tooltip bound to this layer.
	getTooltip: function () {
		return this._tooltip;
	},

	_openTooltip: function (e) {
		var layer = e.layer || e.target;

		if (!this._tooltip || !this._map) {
			return;
		}
		this.openTooltip(layer, this._tooltip.options.sticky ? e.latlng : undefined);
	},

	_moveTooltip: function (e) {
		var latlng = e.latlng, containerPoint, layerPoint;
		if (this._tooltip.options.sticky && e.originalEvent) {
			containerPoint = this._map.mouseEventToContainerPoint(e.originalEvent);
			layerPoint = this._map.containerPointToLayerPoint(containerPoint);
			latlng = this._map.layerPointToLatLng(layerPoint);
		}
		this._tooltip.setLatLng(latlng);
	}
});

/*
 * @class Renderer
 * @inherits Layer
 * @aka L.Renderer
 *
 * Base class for vector renderer implementations (`SVG`, `Canvas`). Handles the
 * DOM container of the renderer, its bounds, and its zoom animation.
 *
 * A `Renderer` works as an implicit layer group for all `Path`s - the renderer
 * itself can be added or removed to the map. All paths use a renderer, which can
 * be implicit (the map will decide the type of renderer and use it automatically)
 * or explicit (using the [`renderer`](#path-renderer) option of the path).
 *
 * Do not use this class directly, use `SVG` and `Canvas` instead.
 *
 * @event update: Event
 * Fired when the renderer updates its bounds, center and zoom, for example when
 * its map has moved
 */

var Renderer = Layer.extend({

	// @section
	// @aka Renderer options
	options: {
		// @option padding: Number = 0.1
		// How much to extend the clip area around the map view (relative to its size)
		// e.g. 0.1 would be 10% of map view in each direction
		padding: 0.1,

		// @option tolerance: Number = 0
		// How much to extend click tolerance round a path/object on the map
		tolerance : 0
	},

	initialize: function (options) {
		setOptions$1(this, options);
		stamp$1(this);
		this._layers = this._layers || {};
	},

	onAdd: function () {
		if (!this._container) {
			this._initContainer(); // defined by renderer implementations

			if (this._zoomAnimated) {
				addClass(this._container, 'leaflet-zoom-animated');
			}
		}

		this.getPane().appendChild(this._container);
		this._update();
		this.on('update', this._updatePaths, this);
	},

	onRemove: function () {
		this.off('update', this._updatePaths, this);
		this._destroyContainer();
	},

	getEvents: function () {
		var events = {
			viewreset: this._reset,
			zoom: this._onZoom,
			moveend: this._update,
			zoomend: this._onZoomEnd
		};
		if (this._zoomAnimated) {
			events.zoomanim = this._onAnimZoom;
		}
		return events;
	},

	_onAnimZoom: function (ev) {
		this._updateTransform(ev.center, ev.zoom);
	},

	_onZoom: function () {
		this._updateTransform(this._map.getCenter(), this._map.getZoom());
	},

	_updateTransform: function (center, zoom) {
		var scale = this._map.getZoomScale(zoom, this._zoom),
		    position = getPosition(this._container),
		    viewHalf = this._map.getSize().multiplyBy(0.5 + this.options.padding),
		    currentCenterPoint = this._map.project(this._center, zoom),
		    destCenterPoint = this._map.project(center, zoom),
		    centerOffset = destCenterPoint.subtract(currentCenterPoint),

		    topLeftOffset = viewHalf.multiplyBy(-scale).add(position).add(viewHalf).subtract(centerOffset);

		if (any3d) {
			setTransform(this._container, topLeftOffset, scale);
		} else {
			setPosition(this._container, topLeftOffset);
		}
	},

	_reset: function () {
		this._update();
		this._updateTransform(this._center, this._zoom);

		for (var id in this._layers) {
			this._layers[id]._reset();
		}
	},

	_onZoomEnd: function () {
		for (var id in this._layers) {
			this._layers[id]._project();
		}
	},

	_updatePaths: function () {
		for (var id in this._layers) {
			this._layers[id]._update();
		}
	},

	_update: function () {
		// Update pixel bounds of renderer container (for positioning/sizing/clipping later)
		// Subclasses are responsible of firing the 'update' event.
		var p = this.options.padding,
		    size = this._map.getSize(),
		    min = this._map.containerPointToLayerPoint(size.multiplyBy(-p)).round();

		this._bounds = new Bounds(min, min.add(size.multiplyBy(1 + p * 2)).round());

		this._center = this._map.getCenter();
		this._zoom = this._map.getZoom();
	}
});

/*
 * @class Canvas
 * @inherits Renderer
 * @aka L.Canvas
 *
 * Allows vector layers to be displayed with [`<canvas>`](https://developer.mozilla.org/docs/Web/API/Canvas_API).
 * Inherits `Renderer`.
 *
 * Due to [technical limitations](http://caniuse.com/#search=canvas), Canvas is not
 * available in all web browsers, notably IE8, and overlapping geometries might
 * not display properly in some edge cases.
 *
 * @example
 *
 * Use Canvas by default for all paths in the map:
 *
 * ```js
 * var map = L.map('map', {
 * 	renderer: L.canvas()
 * });
 * ```
 *
 * Use a Canvas renderer with extra padding for specific vector geometries:
 *
 * ```js
 * var map = L.map('map');
 * var myRenderer = L.canvas({ padding: 0.5 });
 * var line = L.polyline( coordinates, { renderer: myRenderer } );
 * var circle = L.circle( center, { renderer: myRenderer } );
 * ```
 */

var Canvas = Renderer.extend({
	getEvents: function () {
		var events = Renderer.prototype.getEvents.call(this);
		events.viewprereset = this._onViewPreReset;
		return events;
	},

	_onViewPreReset: function () {
		// Set a flag so that a viewprereset+moveend+viewreset only updates&redraws once
		this._postponeUpdatePaths = true;
	},

	onAdd: function () {
		Renderer.prototype.onAdd.call(this);

		// Redraw vectors since canvas is cleared upon removal,
		// in case of removing the renderer itself from the map.
		this._draw();
	},

	_initContainer: function () {
		var container = this._container = document.createElement('canvas');

		on(container, 'mousemove', this._onMouseMove, this);
		on(container, 'click dblclick mousedown mouseup contextmenu', this._onClick, this);
		on(container, 'mouseout', this._handleMouseOut, this);

		this._ctx = container.getContext('2d');
	},

	_destroyContainer: function () {
		cancelAnimFrame(this._redrawRequest);
		delete this._ctx;
		remove(this._container);
		off(this._container);
		delete this._container;
	},

	_updatePaths: function () {
		if (this._postponeUpdatePaths) { return; }

		var layer;
		this._redrawBounds = null;
		for (var id in this._layers) {
			layer = this._layers[id];
			layer._update();
		}
		this._redraw();
	},

	_update: function () {
		if (this._map._animatingZoom && this._bounds) { return; }

		Renderer.prototype._update.call(this);

		var b = this._bounds,
		    container = this._container,
		    size = b.getSize(),
		    m = retina ? 2 : 1;

		setPosition(container, b.min);

		// set canvas size (also clearing it); use double size on retina
		container.width = m * size.x;
		container.height = m * size.y;
		container.style.width = size.x + 'px';
		container.style.height = size.y + 'px';

		if (retina) {
			this._ctx.scale(2, 2);
		}

		// translate so we use the same path coordinates after canvas element moves
		this._ctx.translate(-b.min.x, -b.min.y);

		// Tell paths to redraw themselves
		this.fire('update');
	},

	_reset: function () {
		Renderer.prototype._reset.call(this);

		if (this._postponeUpdatePaths) {
			this._postponeUpdatePaths = false;
			this._updatePaths();
		}
	},

	_initPath: function (layer) {
		this._updateDashArray(layer);
		this._layers[stamp$1(layer)] = layer;

		var order = layer._order = {
			layer: layer,
			prev: this._drawLast,
			next: null
		};
		if (this._drawLast) { this._drawLast.next = order; }
		this._drawLast = order;
		this._drawFirst = this._drawFirst || this._drawLast;
	},

	_addPath: function (layer) {
		this._requestRedraw(layer);
	},

	_removePath: function (layer) {
		var order = layer._order;
		var next = order.next;
		var prev = order.prev;

		if (next) {
			next.prev = prev;
		} else {
			this._drawLast = prev;
		}
		if (prev) {
			prev.next = next;
		} else {
			this._drawFirst = next;
		}

		delete layer._order;

		delete this._layers[stamp$1(layer)];

		this._requestRedraw(layer);
	},

	_updatePath: function (layer) {
		// Redraw the union of the layer's old pixel
		// bounds and the new pixel bounds.
		this._extendRedrawBounds(layer);
		layer._project();
		layer._update();
		// The redraw will extend the redraw bounds
		// with the new pixel bounds.
		this._requestRedraw(layer);
	},

	_updateStyle: function (layer) {
		this._updateDashArray(layer);
		this._requestRedraw(layer);
	},

	_updateDashArray: function (layer) {
		if (typeof layer.options.dashArray === 'string') {
			var parts = layer.options.dashArray.split(/[, ]+/),
			    dashArray = [],
			    dashValue,
			    i;
			for (i = 0; i < parts.length; i++) {
				dashValue = Number(parts[i]);
				// Ignore dash array containing invalid lengths
				if (isNaN(dashValue)) { return; }
				dashArray.push(dashValue);
			}
			layer.options._dashArray = dashArray;
		} else {
			layer.options._dashArray = layer.options.dashArray;
		}
	},

	_requestRedraw: function (layer) {
		if (!this._map) { return; }

		this._extendRedrawBounds(layer);
		this._redrawRequest = this._redrawRequest || requestAnimFrame(this._redraw, this);
	},

	_extendRedrawBounds: function (layer) {
		if (layer._pxBounds) {
			var padding = (layer.options.weight || 0) + 1;
			this._redrawBounds = this._redrawBounds || new Bounds();
			this._redrawBounds.extend(layer._pxBounds.min.subtract([padding, padding]));
			this._redrawBounds.extend(layer._pxBounds.max.add([padding, padding]));
		}
	},

	_redraw: function () {
		this._redrawRequest = null;

		if (this._redrawBounds) {
			this._redrawBounds.min._floor();
			this._redrawBounds.max._ceil();
		}

		this._clear(); // clear layers in redraw bounds
		this._draw(); // draw layers

		this._redrawBounds = null;
	},

	_clear: function () {
		var bounds = this._redrawBounds;
		if (bounds) {
			var size = bounds.getSize();
			this._ctx.clearRect(bounds.min.x, bounds.min.y, size.x, size.y);
		} else {
			this._ctx.clearRect(0, 0, this._container.width, this._container.height);
		}
	},

	_draw: function () {
		var layer, bounds = this._redrawBounds;
		this._ctx.save();
		if (bounds) {
			var size = bounds.getSize();
			this._ctx.beginPath();
			this._ctx.rect(bounds.min.x, bounds.min.y, size.x, size.y);
			this._ctx.clip();
		}

		this._drawing = true;

		for (var order = this._drawFirst; order; order = order.next) {
			layer = order.layer;
			if (!bounds || (layer._pxBounds && layer._pxBounds.intersects(bounds))) {
				layer._updatePath();
			}
		}

		this._drawing = false;

		this._ctx.restore();  // Restore state before clipping.
	},

	_updatePoly: function (layer, closed) {
		if (!this._drawing) { return; }

		var i, j, len2, p,
		    parts = layer._parts,
		    len = parts.length,
		    ctx = this._ctx;

		if (!len) { return; }

		ctx.beginPath();

		for (i = 0; i < len; i++) {
			for (j = 0, len2 = parts[i].length; j < len2; j++) {
				p = parts[i][j];
				ctx[j ? 'lineTo' : 'moveTo'](p.x, p.y);
			}
			if (closed) {
				ctx.closePath();
			}
		}

		this._fillStroke(ctx, layer);

		// TODO optimization: 1 fill/stroke for all features with equal style instead of 1 for each feature
	},

	_updateCircle: function (layer) {

		if (!this._drawing || layer._empty()) { return; }

		var p = layer._point,
		    ctx = this._ctx,
		    r = Math.max(Math.round(layer._radius), 1),
		    s = (Math.max(Math.round(layer._radiusY), 1) || r) / r;

		if (s !== 1) {
			ctx.save();
			ctx.scale(1, s);
		}

		ctx.beginPath();
		ctx.arc(p.x, p.y / s, r, 0, Math.PI * 2, false);

		if (s !== 1) {
			ctx.restore();
		}

		this._fillStroke(ctx, layer);
	},

	_fillStroke: function (ctx, layer) {
		var options = layer.options;

		if (options.fill) {
			ctx.globalAlpha = options.fillOpacity;
			ctx.fillStyle = options.fillColor || options.color;
			ctx.fill(options.fillRule || 'evenodd');
		}

		if (options.stroke && options.weight !== 0) {
			if (ctx.setLineDash) {
				ctx.setLineDash(layer.options && layer.options._dashArray || []);
			}
			ctx.globalAlpha = options.opacity;
			ctx.lineWidth = options.weight;
			ctx.strokeStyle = options.color;
			ctx.lineCap = options.lineCap;
			ctx.lineJoin = options.lineJoin;
			ctx.stroke();
		}
	},

	// Canvas obviously doesn't have mouse events for individual drawn objects,
	// so we emulate that by calculating what's under the mouse on mousemove/click manually

	_onClick: function (e) {
		var point = this._map.mouseEventToLayerPoint(e), layer, clickedLayer;

		for (var order = this._drawFirst; order; order = order.next) {
			layer = order.layer;
			if (layer.options.interactive && layer._containsPoint(point) && !this._map._draggableMoved(layer)) {
				clickedLayer = layer;
			}
		}
		if (clickedLayer)  {
			fakeStop(e);
			this._fireEvent([clickedLayer], e);
		}
	},

	_onMouseMove: function (e) {
		if (!this._map || this._map.dragging.moving() || this._map._animatingZoom) { return; }

		var point = this._map.mouseEventToLayerPoint(e);
		this._handleMouseHover(e, point);
	},


	_handleMouseOut: function (e) {
		var layer = this._hoveredLayer;
		if (layer) {
			// if we're leaving the layer, fire mouseout
			removeClass(this._container, 'leaflet-interactive');
			this._fireEvent([layer], e, 'mouseout');
			this._hoveredLayer = null;
			this._mouseHoverThrottled = false;
		}
	},

	_handleMouseHover: function (e, point) {
		if (this._mouseHoverThrottled) {
			return;
		}

		var layer, candidateHoveredLayer;

		for (var order = this._drawFirst; order; order = order.next) {
			layer = order.layer;
			if (layer.options.interactive && layer._containsPoint(point)) {
				candidateHoveredLayer = layer;
			}
		}

		if (candidateHoveredLayer !== this._hoveredLayer) {
			this._handleMouseOut(e);

			if (candidateHoveredLayer) {
				addClass(this._container, 'leaflet-interactive'); // change cursor
				this._fireEvent([candidateHoveredLayer], e, 'mouseover');
				this._hoveredLayer = candidateHoveredLayer;
			}
		}

		if (this._hoveredLayer) {
			this._fireEvent([this._hoveredLayer], e);
		}

		this._mouseHoverThrottled = true;
		setTimeout(L.bind(function () {
			this._mouseHoverThrottled = false;
		}, this), 32);
	},

	_fireEvent: function (layers, e, type) {
		this._map._fireDOMEvent(e, type || e.type, layers);
	},

	_bringToFront: function (layer) {
		var order = layer._order;

		if (!order) { return; }

		var next = order.next;
		var prev = order.prev;

		if (next) {
			next.prev = prev;
		} else {
			// Already last
			return;
		}
		if (prev) {
			prev.next = next;
		} else if (next) {
			// Update first entry unless this is the
			// single entry
			this._drawFirst = next;
		}

		order.prev = this._drawLast;
		this._drawLast.next = order;

		order.next = null;
		this._drawLast = order;

		this._requestRedraw(layer);
	},

	_bringToBack: function (layer) {
		var order = layer._order;

		if (!order) { return; }

		var next = order.next;
		var prev = order.prev;

		if (prev) {
			prev.next = next;
		} else {
			// Already first
			return;
		}
		if (next) {
			next.prev = prev;
		} else if (prev) {
			// Update last entry unless this is the
			// single entry
			this._drawLast = prev;
		}

		order.prev = null;

		order.next = this._drawFirst;
		this._drawFirst.prev = order;
		this._drawFirst = order;

		this._requestRedraw(layer);
	}
});

// @factory L.canvas(options?: Renderer options)
// Creates a Canvas renderer with the given options.
function canvas$1(options) {
	return canvas ? new Canvas(options) : null;
}

/*
 * Thanks to Dmitry Baranovsky and his Raphael library for inspiration!
 */


var vmlCreate = (function () {
	try {
		document.namespaces.add('lvml', 'urn:schemas-microsoft-com:vml');
		return function (name) {
			return document.createElement('<lvml:' + name + ' class="lvml">');
		};
	} catch (e) {
		return function (name) {
			return document.createElement('<' + name + ' xmlns="urn:schemas-microsoft.com:vml" class="lvml">');
		};
	}
})();


/*
 * @class SVG
 *
 *
 * VML was deprecated in 2012, which means VML functionality exists only for backwards compatibility
 * with old versions of Internet Explorer.
 */

// mixin to redefine some SVG methods to handle VML syntax which is similar but with some differences
var vmlMixin = {

	_initContainer: function () {
		this._container = create$1('div', 'leaflet-vml-container');
	},

	_update: function () {
		if (this._map._animatingZoom) { return; }
		Renderer.prototype._update.call(this);
		this.fire('update');
	},

	_initPath: function (layer) {
		var container = layer._container = vmlCreate('shape');

		addClass(container, 'leaflet-vml-shape ' + (this.options.className || ''));

		container.coordsize = '1 1';

		layer._path = vmlCreate('path');
		container.appendChild(layer._path);

		this._updateStyle(layer);
		this._layers[stamp$1(layer)] = layer;
	},

	_addPath: function (layer) {
		var container = layer._container;
		this._container.appendChild(container);

		if (layer.options.interactive) {
			layer.addInteractiveTarget(container);
		}
	},

	_removePath: function (layer) {
		var container = layer._container;
		remove(container);
		layer.removeInteractiveTarget(container);
		delete this._layers[stamp$1(layer)];
	},

	_updateStyle: function (layer) {
		var stroke = layer._stroke,
		    fill = layer._fill,
		    options = layer.options,
		    container = layer._container;

		container.stroked = !!options.stroke;
		container.filled = !!options.fill;

		if (options.stroke) {
			if (!stroke) {
				stroke = layer._stroke = vmlCreate('stroke');
			}
			container.appendChild(stroke);
			stroke.weight = options.weight + 'px';
			stroke.color = options.color;
			stroke.opacity = options.opacity;

			if (options.dashArray) {
				stroke.dashStyle = isArray(options.dashArray) ?
				    options.dashArray.join(' ') :
				    options.dashArray.replace(/( *, *)/g, ' ');
			} else {
				stroke.dashStyle = '';
			}
			stroke.endcap = options.lineCap.replace('butt', 'flat');
			stroke.joinstyle = options.lineJoin;

		} else if (stroke) {
			container.removeChild(stroke);
			layer._stroke = null;
		}

		if (options.fill) {
			if (!fill) {
				fill = layer._fill = vmlCreate('fill');
			}
			container.appendChild(fill);
			fill.color = options.fillColor || options.color;
			fill.opacity = options.fillOpacity;

		} else if (fill) {
			container.removeChild(fill);
			layer._fill = null;
		}
	},

	_updateCircle: function (layer) {
		var p = layer._point.round(),
		    r = Math.round(layer._radius),
		    r2 = Math.round(layer._radiusY || r);

		this._setPath(layer, layer._empty() ? 'M0 0' :
			'AL ' + p.x + ',' + p.y + ' ' + r + ',' + r2 + ' 0,' + (65535 * 360));
	},

	_setPath: function (layer, path) {
		layer._path.v = path;
	},

	_bringToFront: function (layer) {
		toFront(layer._container);
	},

	_bringToBack: function (layer) {
		toBack(layer._container);
	}
};

var create$2 = vml ? vmlCreate : svgCreate;

/*
 * @class SVG
 * @inherits Renderer
 * @aka L.SVG
 *
 * Allows vector layers to be displayed with [SVG](https://developer.mozilla.org/docs/Web/SVG).
 * Inherits `Renderer`.
 *
 * Due to [technical limitations](http://caniuse.com/#search=svg), SVG is not
 * available in all web browsers, notably Android 2.x and 3.x.
 *
 * Although SVG is not available on IE7 and IE8, these browsers support
 * [VML](https://en.wikipedia.org/wiki/Vector_Markup_Language)
 * (a now deprecated technology), and the SVG renderer will fall back to VML in
 * this case.
 *
 * @example
 *
 * Use SVG by default for all paths in the map:
 *
 * ```js
 * var map = L.map('map', {
 * 	renderer: L.svg()
 * });
 * ```
 *
 * Use a SVG renderer with extra padding for specific vector geometries:
 *
 * ```js
 * var map = L.map('map');
 * var myRenderer = L.svg({ padding: 0.5 });
 * var line = L.polyline( coordinates, { renderer: myRenderer } );
 * var circle = L.circle( center, { renderer: myRenderer } );
 * ```
 */

var SVG = Renderer.extend({

	getEvents: function () {
		var events = Renderer.prototype.getEvents.call(this);
		events.zoomstart = this._onZoomStart;
		return events;
	},

	_initContainer: function () {
		this._container = create$2('svg');

		// makes it possible to click through svg root; we'll reset it back in individual paths
		this._container.setAttribute('pointer-events', 'none');

		this._rootGroup = create$2('g');
		this._container.appendChild(this._rootGroup);
	},

	_destroyContainer: function () {
		remove(this._container);
		off(this._container);
		delete this._container;
		delete this._rootGroup;
		delete this._svgSize;
	},

	_onZoomStart: function () {
		// Drag-then-pinch interactions might mess up the center and zoom.
		// In this case, the easiest way to prevent this is re-do the renderer
		//   bounds and padding when the zooming starts.
		this._update();
	},

	_update: function () {
		if (this._map._animatingZoom && this._bounds) { return; }

		Renderer.prototype._update.call(this);

		var b = this._bounds,
		    size = b.getSize(),
		    container = this._container;

		// set size of svg-container if changed
		if (!this._svgSize || !this._svgSize.equals(size)) {
			this._svgSize = size;
			container.setAttribute('width', size.x);
			container.setAttribute('height', size.y);
		}

		// movement: update container viewBox so that we don't have to change coordinates of individual layers
		setPosition(container, b.min);
		container.setAttribute('viewBox', [b.min.x, b.min.y, size.x, size.y].join(' '));

		this.fire('update');
	},

	// methods below are called by vector layers implementations

	_initPath: function (layer) {
		var path = layer._path = create$2('path');

		// @namespace Path
		// @option className: String = null
		// Custom class name set on an element. Only for SVG renderer.
		if (layer.options.className) {
			addClass(path, layer.options.className);
		}

		if (layer.options.interactive) {
			addClass(path, 'leaflet-interactive');
		}

		this._updateStyle(layer);
		this._layers[stamp$1(layer)] = layer;
	},

	_addPath: function (layer) {
		if (!this._rootGroup) { this._initContainer(); }
		this._rootGroup.appendChild(layer._path);
		layer.addInteractiveTarget(layer._path);
	},

	_removePath: function (layer) {
		remove(layer._path);
		layer.removeInteractiveTarget(layer._path);
		delete this._layers[stamp$1(layer)];
	},

	_updatePath: function (layer) {
		layer._project();
		layer._update();
	},

	_updateStyle: function (layer) {
		var path = layer._path,
		    options = layer.options;

		if (!path) { return; }

		if (options.stroke) {
			path.setAttribute('stroke', options.color);
			path.setAttribute('stroke-opacity', options.opacity);
			path.setAttribute('stroke-width', options.weight);
			path.setAttribute('stroke-linecap', options.lineCap);
			path.setAttribute('stroke-linejoin', options.lineJoin);

			if (options.dashArray) {
				path.setAttribute('stroke-dasharray', options.dashArray);
			} else {
				path.removeAttribute('stroke-dasharray');
			}

			if (options.dashOffset) {
				path.setAttribute('stroke-dashoffset', options.dashOffset);
			} else {
				path.removeAttribute('stroke-dashoffset');
			}
		} else {
			path.setAttribute('stroke', 'none');
		}

		if (options.fill) {
			path.setAttribute('fill', options.fillColor || options.color);
			path.setAttribute('fill-opacity', options.fillOpacity);
			path.setAttribute('fill-rule', options.fillRule || 'evenodd');
		} else {
			path.setAttribute('fill', 'none');
		}
	},

	_updatePoly: function (layer, closed) {
		this._setPath(layer, pointsToPath(layer._parts, closed));
	},

	_updateCircle: function (layer) {
		var p = layer._point,
		    r = Math.max(Math.round(layer._radius), 1),
		    r2 = Math.max(Math.round(layer._radiusY), 1) || r,
		    arc = 'a' + r + ',' + r2 + ' 0 1,0 ';

		// drawing a circle with two half-arcs
		var d = layer._empty() ? 'M0 0' :
			'M' + (p.x - r) + ',' + p.y +
			arc + (r * 2) + ',0 ' +
			arc + (-r * 2) + ',0 ';

		this._setPath(layer, d);
	},

	_setPath: function (layer, path) {
		layer._path.setAttribute('d', path);
	},

	// SVG does not have the concept of zIndex so we resort to changing the DOM order of elements
	_bringToFront: function (layer) {
		toFront(layer._path);
	},

	_bringToBack: function (layer) {
		toBack(layer._path);
	}
});

if (vml) {
	SVG.include(vmlMixin);
}

// @namespace SVG
// @factory L.svg(options?: Renderer options)
// Creates a SVG renderer with the given options.
function svg$1(options) {
	return svg || vml ? new SVG(options) : null;
}

Map$1.include({
	// @namespace Map; @method getRenderer(layer: Path): Renderer
	// Returns the instance of `Renderer` that should be used to render the given
	// `Path`. It will ensure that the `renderer` options of the map and paths
	// are respected, and that the renderers do exist on the map.
	getRenderer: function (layer) {
		// @namespace Path; @option renderer: Renderer
		// Use this specific instance of `Renderer` for this path. Takes
		// precedence over the map's [default renderer](#map-renderer).
		var renderer = layer.options.renderer || this._getPaneRenderer(layer.options.pane) || this.options.renderer || this._renderer;

		if (!renderer) {
			renderer = this._renderer = this._createRenderer();
		}

		if (!this.hasLayer(renderer)) {
			this.addLayer(renderer);
		}
		return renderer;
	},

	_getPaneRenderer: function (name) {
		if (name === 'overlayPane' || name === undefined) {
			return false;
		}

		var renderer = this._paneRenderers[name];
		if (renderer === undefined) {
			renderer = this._createRenderer({pane: name});
			this._paneRenderers[name] = renderer;
		}
		return renderer;
	},

	_createRenderer: function (options) {
		// @namespace Map; @option preferCanvas: Boolean = false
		// Whether `Path`s should be rendered on a `Canvas` renderer.
		// By default, all `Path`s are rendered in a `SVG` renderer.
		return (this.options.preferCanvas && canvas$1(options)) || svg$1(options);
	}
});

/*
 * L.Rectangle extends Polygon and creates a rectangle when passed a LatLngBounds object.
 */

/*
 * @class Rectangle
 * @aka L.Rectangle
 * @inherits Polygon
 *
 * A class for drawing rectangle overlays on a map. Extends `Polygon`.
 *
 * @example
 *
 * ```js
 * // define rectangle geographical bounds
 * var bounds = [[54.559322, -5.767822], [56.1210604, -3.021240]];
 *
 * // create an orange rectangle
 * L.rectangle(bounds, {color: "#ff7800", weight: 1}).addTo(map);
 *
 * // zoom the map to the rectangle bounds
 * map.fitBounds(bounds);
 * ```
 *
 */


var Rectangle = Polygon.extend({
	initialize: function (latLngBounds, options) {
		Polygon.prototype.initialize.call(this, this._boundsToLatLngs(latLngBounds), options);
	},

	// @method setBounds(latLngBounds: LatLngBounds): this
	// Redraws the rectangle with the passed bounds.
	setBounds: function (latLngBounds) {
		return this.setLatLngs(this._boundsToLatLngs(latLngBounds));
	},

	_boundsToLatLngs: function (latLngBounds) {
		latLngBounds = toLatLngBounds(latLngBounds);
		return [
			latLngBounds.getSouthWest(),
			latLngBounds.getNorthWest(),
			latLngBounds.getNorthEast(),
			latLngBounds.getSouthEast()
		];
	}
});

SVG.create = create$2;
SVG.pointsToPath = pointsToPath;

GeoJSON.geometryToLayer = geometryToLayer;
GeoJSON.coordsToLatLng = coordsToLatLng;
GeoJSON.coordsToLatLngs = coordsToLatLngs;
GeoJSON.latLngToCoords = latLngToCoords;
GeoJSON.latLngsToCoords = latLngsToCoords;
GeoJSON.getFeature = getFeature;
GeoJSON.asFeature = asFeature;

/*
 * @namespace Projection
 * @projection L.Projection.Mercator
 *
 * Elliptical Mercator projection — more complex than Spherical Mercator. Assumes that Earth is an ellipsoid. Used by the EPSG:3395 CRS.
 */

var Mercator = {
	R: 6378137,
	R_MINOR: 6356752.314245179,

	bounds: new Bounds([-20037508.34279, -15496570.73972], [20037508.34279, 18764656.23138]),

	project: function (latlng) {
		var d = Math.PI / 180,
		    r = this.R,
		    y = latlng.lat * d,
		    tmp = this.R_MINOR / r,
		    e = Math.sqrt(1 - tmp * tmp),
		    con = e * Math.sin(y);

		var ts = Math.tan(Math.PI / 4 - y / 2) / Math.pow((1 - con) / (1 + con), e / 2);
		y = -r * Math.log(Math.max(ts, 1E-10));

		return new Point(latlng.lng * d * r, y);
	},

	unproject: function (point) {
		var d = 180 / Math.PI,
		    r = this.R,
		    tmp = this.R_MINOR / r,
		    e = Math.sqrt(1 - tmp * tmp),
		    ts = Math.exp(-point.y / r),
		    phi = Math.PI / 2 - 2 * Math.atan(ts);

		for (var i = 0, dphi = 0.1, con; i < 15 && Math.abs(dphi) > 1e-7; i++) {
			con = e * Math.sin(phi);
			con = Math.pow((1 - con) / (1 + con), e / 2);
			dphi = Math.PI / 2 - 2 * Math.atan(ts * con) - phi;
			phi += dphi;
		}

		return new LatLng(phi * d, point.x * d / r);
	}
};

/*
 * @namespace CRS
 * @crs L.CRS.EPSG3395
 *
 * Rarely used by some commercial tile providers. Uses Elliptical Mercator projection.
 */
var EPSG3395 = extend({}, Earth, {
	code: 'EPSG:3395',
	projection: Mercator,

	transformation: (function () {
		var scale = 0.5 / (Math.PI * Mercator.R);
		return toTransformation(scale, 0.5, -scale, 0.5);
	}())
});

/*
 * @namespace CRS
 * @crs L.CRS.Simple
 *
 * A simple CRS that maps longitude and latitude into `x` and `y` directly.
 * May be used for maps of flat surfaces (e.g. game maps). Note that the `y`
 * axis should still be inverted (going from bottom to top). `distance()` returns
 * simple euclidean distance.
 */

var Simple = extend({}, CRS, {
	projection: LonLat,
	transformation: toTransformation(1, 0, -1, 0),

	scale: function (zoom) {
		return Math.pow(2, zoom);
	},

	zoom: function (scale) {
		return Math.log(scale) / Math.LN2;
	},

	distance: function (latlng1, latlng2) {
		var dx = latlng2.lng - latlng1.lng,
		    dy = latlng2.lat - latlng1.lat;

		return Math.sqrt(dx * dx + dy * dy);
	},

	infinite: true
});

CRS.Earth = Earth;
CRS.EPSG3395 = EPSG3395;
CRS.EPSG3857 = EPSG3857;
CRS.EPSG900913 = EPSG900913;
CRS.EPSG4326 = EPSG4326;
CRS.Simple = Simple;

var MarkerCluster$1 = Marker.extend({
	options: Icon.prototype.options,

	initialize: function (group, zoom, a, b) {

		Marker.prototype.initialize.call(this, a ? (a._cLatLng || a.getLatLng()) : new LatLng(0, 0),
            { icon: this, pane: group.options.clusterPane });

		this._group = group;
		this._zoom = zoom;

		this._markers = [];
		this._childClusters = [];
		this._childCount = 0;
		this._iconNeedsUpdate = true;
		this._boundsNeedUpdate = true;

		this._bounds = new LatLngBounds();

		if (a) {
			this._addChild(a);
		}
		if (b) {
			this._addChild(b);
		}
	},

	//Recursively retrieve all child markers of this cluster
	getAllChildMarkers: function (storageArray, ignoreDraggedMarker) {
		storageArray = storageArray || [];

		for (var i = this._childClusters.length - 1; i >= 0; i--) {
			this._childClusters[i].getAllChildMarkers(storageArray);
		}

		for (var j = this._markers.length - 1; j >= 0; j--) {
			if (ignoreDraggedMarker && this._markers[j].__dragStart) {
				continue;
			}
			storageArray.push(this._markers[j]);
		}

		return storageArray;
	},

	//Returns the count of how many child markers we have
	getChildCount: function () {
		return this._childCount;
	},

	//Zoom to the minimum of showing all of the child markers, or the extents of this cluster
	zoomToBounds: function (fitBoundsOptions) {
		var childClusters = this._childClusters.slice(),
			map = this._group._map,
			boundsZoom = map.getBoundsZoom(this._bounds),
			zoom = this._zoom + 1,
			mapZoom = map.getZoom(),
			i;

		//calculate how far we need to zoom down to see all of the markers
		while (childClusters.length > 0 && boundsZoom > zoom) {
			zoom++;
			var newClusters = [];
			for (i = 0; i < childClusters.length; i++) {
				newClusters = newClusters.concat(childClusters[i]._childClusters);
			}
			childClusters = newClusters;
		}

		if (boundsZoom > zoom) {
			this._group._map.setView(this._latlng, zoom);
		} else if (boundsZoom <= mapZoom) { //If fitBounds wouldn't zoom us down, zoom us down instead
			this._group._map.setView(this._latlng, mapZoom + 1);
		} else {
			this._group._map.fitBounds(this._bounds, fitBoundsOptions);
		}
	},

	getBounds: function () {
		var bounds = new LatLngBounds();
		bounds.extend(this._bounds);
		return bounds;
	},

	_updateIcon: function () {
		this._iconNeedsUpdate = true;
		if (this._icon) {
			this.setIcon(this);
		}
	},

	//Cludge for Icon, we pretend to be an icon for performance
	createIcon: function () {
		if (this._iconNeedsUpdate) {
			this._iconObj = this._group.options.iconCreateFunction(this);
			this._iconNeedsUpdate = false;
		}
		return this._iconObj.createIcon();
	},
	createShadow: function () {
		return this._iconObj.createShadow();
	},


	_addChild: function (new1, isNotificationFromChild) {

		this._iconNeedsUpdate = true;

		this._boundsNeedUpdate = true;
		this._setClusterCenter(new1);

		if (new1 instanceof MarkerCluster$1) {
			if (!isNotificationFromChild) {
				this._childClusters.push(new1);
				new1.__parent = this;
			}
			this._childCount += new1._childCount;
		} else {
			if (!isNotificationFromChild) {
				this._markers.push(new1);
			}
			this._childCount++;
		}

		if (this.__parent) {
			this.__parent._addChild(new1, true);
		}
	},

	/**
	 * Makes sure the cluster center is set. If not, uses the child center if it is a cluster, or the marker position.
	 * @param child MarkerCluster|Marker that will be used as cluster center if not defined yet.
	 * @private
	 */
	_setClusterCenter: function (child) {
		if (!this._cLatLng) {
			// when clustering, take position of the first point as the cluster center
			this._cLatLng = child._cLatLng || child._latlng;
		}
	},

	/**
	 * Assigns impossible bounding values so that the next extend entirely determines the new bounds.
	 * This method avoids having to trash the previous LatLngBounds object and to create a new one, which is much slower for this class.
	 * As long as the bounds are not extended, most other methods would probably fail, as they would with bounds initialized but not extended.
	 * @private
	 */
	_resetBounds: function () {
		var bounds = this._bounds;

		if (bounds._southWest) {
			bounds._southWest.lat = Infinity;
			bounds._southWest.lng = Infinity;
		}
		if (bounds._northEast) {
			bounds._northEast.lat = -Infinity;
			bounds._northEast.lng = -Infinity;
		}
	},

	_recalculateBounds: function () {
		var markers = this._markers,
		    childClusters = this._childClusters,
		    latSum = 0,
		    lngSum = 0,
		    totalCount = this._childCount,
		    i, child, childLatLng, childCount;

		// Case where all markers are removed from the map and we are left with just an empty _topClusterLevel.
		if (totalCount === 0) {
			return;
		}

		// Reset rather than creating a new object, for performance.
		this._resetBounds();

		// Child markers.
		for (i = 0; i < markers.length; i++) {
			childLatLng = markers[i]._latlng;

			this._bounds.extend(childLatLng);

			latSum += childLatLng.lat;
			lngSum += childLatLng.lng;
		}

		// Child clusters.
		for (i = 0; i < childClusters.length; i++) {
			child = childClusters[i];

			// Re-compute child bounds and weighted position first if necessary.
			if (child._boundsNeedUpdate) {
				child._recalculateBounds();
			}

			this._bounds.extend(child._bounds);

			childLatLng = child._wLatLng;
			childCount = child._childCount;

			latSum += childLatLng.lat * childCount;
			lngSum += childLatLng.lng * childCount;
		}

		this._latlng = this._wLatLng = new LatLng(latSum / totalCount, lngSum / totalCount);

		// Reset dirty flag.
		this._boundsNeedUpdate = false;
	},

	//Set our markers position as given and add it to the map
	_addToMap: function (startPos) {
		if (startPos) {
			this._backupLatlng = this._latlng;
			this.setLatLng(startPos);
		}
		this._group._featureGroup.addLayer(this);
	},

	_recursivelyAnimateChildrenIn: function (bounds, center, maxZoom) {
		this._recursively(bounds, this._group._map.getMinZoom(), maxZoom - 1,
			function (c) {
				var markers = c._markers,
					i, m;
				for (i = markers.length - 1; i >= 0; i--) {
					m = markers[i];

					//Only do it if the icon is still on the map
					if (m._icon) {
						m._setPos(center);
						m.clusterHide();
					}
				}
			},
			function (c) {
				var childClusters = c._childClusters,
					j, cm;
				for (j = childClusters.length - 1; j >= 0; j--) {
					cm = childClusters[j];
					if (cm._icon) {
						cm._setPos(center);
						cm.clusterHide();
					}
				}
			}
		);
	},

	_recursivelyAnimateChildrenInAndAddSelfToMap: function (bounds, mapMinZoom, previousZoomLevel, newZoomLevel) {
		this._recursively(bounds, newZoomLevel, mapMinZoom,
			function (c) {
				c._recursivelyAnimateChildrenIn(bounds, c._group._map.latLngToLayerPoint(c.getLatLng()).round(), previousZoomLevel);

				//TODO: depthToAnimateIn affects _isSingleParent, if there is a multizoom we may/may not be.
				//As a hack we only do a animation free zoom on a single level zoom, if someone does multiple levels then we always animate
				if (c._isSingleParent() && previousZoomLevel - 1 === newZoomLevel) {
					c.clusterShow();
					c._recursivelyRemoveChildrenFromMap(bounds, mapMinZoom, previousZoomLevel); //Immediately remove our children as we are replacing them. TODO previousBounds not bounds
				} else {
					c.clusterHide();
				}

				c._addToMap();
			}
		);
	},

	_recursivelyBecomeVisible: function (bounds, zoomLevel) {
		this._recursively(bounds, this._group._map.getMinZoom(), zoomLevel, null, function (c) {
			c.clusterShow();
		});
	},

	_recursivelyAddChildrenToMap: function (startPos, zoomLevel, bounds) {
		this._recursively(bounds, this._group._map.getMinZoom() - 1, zoomLevel,
			function (c) {
				if (zoomLevel === c._zoom) {
					return;
				}

				//Add our child markers at startPos (so they can be animated out)
				for (var i = c._markers.length - 1; i >= 0; i--) {
					var nm = c._markers[i];

					if (!bounds.contains(nm._latlng)) {
						continue;
					}

					if (startPos) {
						nm._backupLatlng = nm.getLatLng();

						nm.setLatLng(startPos);
						if (nm.clusterHide) {
							nm.clusterHide();
						}
					}

					c._group._featureGroup.addLayer(nm);
				}
			},
			function (c) {
				c._addToMap(startPos);
			}
		);
	},

	_recursivelyRestoreChildPositions: function (zoomLevel) {
		//Fix positions of child markers
		for (var i = this._markers.length - 1; i >= 0; i--) {
			var nm = this._markers[i];
			if (nm._backupLatlng) {
				nm.setLatLng(nm._backupLatlng);
				delete nm._backupLatlng;
			}
		}

		if (zoomLevel - 1 === this._zoom) {
			//Reposition child clusters
			for (var j = this._childClusters.length - 1; j >= 0; j--) {
				this._childClusters[j]._restorePosition();
			}
		} else {
			for (var k = this._childClusters.length - 1; k >= 0; k--) {
				this._childClusters[k]._recursivelyRestoreChildPositions(zoomLevel);
			}
		}
	},

	_restorePosition: function () {
		if (this._backupLatlng) {
			this.setLatLng(this._backupLatlng);
			delete this._backupLatlng;
		}
	},

	//exceptBounds: If set, don't remove any markers/clusters in it
	_recursivelyRemoveChildrenFromMap: function (previousBounds, mapMinZoom, zoomLevel, exceptBounds) {
		var m, i;
		this._recursively(previousBounds, mapMinZoom - 1, zoomLevel - 1,
			function (c) {
				//Remove markers at every level
				for (i = c._markers.length - 1; i >= 0; i--) {
					m = c._markers[i];
					if (!exceptBounds || !exceptBounds.contains(m._latlng)) {
						c._group._featureGroup.removeLayer(m);
						if (m.clusterShow) {
							m.clusterShow();
						}
					}
				}
			},
			function (c) {
				//Remove child clusters at just the bottom level
				for (i = c._childClusters.length - 1; i >= 0; i--) {
					m = c._childClusters[i];
					if (!exceptBounds || !exceptBounds.contains(m._latlng)) {
						c._group._featureGroup.removeLayer(m);
						if (m.clusterShow) {
							m.clusterShow();
						}
					}
				}
			}
		);
	},

	//Run the given functions recursively to this and child clusters
	// boundsToApplyTo: a LatLngBounds representing the bounds of what clusters to recurse in to
	// zoomLevelToStart: zoom level to start running functions (inclusive)
	// zoomLevelToStop: zoom level to stop running functions (inclusive)
	// runAtEveryLevel: function that takes an MarkerCluster as an argument that should be applied on every level
	// runAtBottomLevel: function that takes an MarkerCluster as an argument that should be applied at only the bottom level
	_recursively: function (boundsToApplyTo, zoomLevelToStart, zoomLevelToStop, runAtEveryLevel, runAtBottomLevel) {
		var childClusters = this._childClusters,
		    zoom = this._zoom,
		    i, c;

		if (zoomLevelToStart <= zoom) {
			if (runAtEveryLevel) {
				runAtEveryLevel(this);
			}
			if (runAtBottomLevel && zoom === zoomLevelToStop) {
				runAtBottomLevel(this);
			}
		}

		if (zoom < zoomLevelToStart || zoom < zoomLevelToStop) {
			for (i = childClusters.length - 1; i >= 0; i--) {
				c = childClusters[i];
				if (c._boundsNeedUpdate) {
					c._recalculateBounds();
				}
				if (boundsToApplyTo.intersects(c._bounds)) {
					c._recursively(boundsToApplyTo, zoomLevelToStart, zoomLevelToStop, runAtEveryLevel, runAtBottomLevel);
				}
			}
		}
	},

	//Returns true if we are the parent of only one cluster and that cluster is the same as us
	_isSingleParent: function () {
		//Don't need to check this._markers as the rest won't work if there are any
		return this._childClusters.length > 0 && this._childClusters[0]._childCount === this._childCount;
	}
});

var DistanceGrid = function (cellSize) {
	this._cellSize = cellSize;
	this._sqCellSize = cellSize * cellSize;
	this._grid = {};
	this._objectPoint = { };
};

DistanceGrid.prototype = {

	addObject: function (obj, point) {
		var x = this._getCoord(point.x),
		    y = this._getCoord(point.y),
		    grid = this._grid,
		    row = grid[y] = grid[y] || {},
		    cell = row[x] = row[x] || [],
		    stamp = stamp$1(obj);

		this._objectPoint[stamp] = point;

		cell.push(obj);
	},

	updateObject: function (obj, point) {
		this.removeObject(obj);
		this.addObject(obj, point);
	},

	//Returns true if the object was found
	removeObject: function (obj, point) {
		var x = this._getCoord(point.x),
		    y = this._getCoord(point.y),
		    grid = this._grid,
		    row = grid[y] = grid[y] || {},
		    cell = row[x] = row[x] || [],
		    i, len;

		delete this._objectPoint[stamp$1(obj)];

		for (i = 0, len = cell.length; i < len; i++) {
			if (cell[i] === obj) {

				cell.splice(i, 1);

				if (len === 1) {
					delete row[x];
				}

				return true;
			}
		}

	},

	eachObject: function (fn, context) {
		var i, j, k, len, row, cell, removed,
		    grid = this._grid;

		for (i in grid) {
			row = grid[i];

			for (j in row) {
				cell = row[j];

				for (k = 0, len = cell.length; k < len; k++) {
					removed = fn.call(context, cell[k]);
					if (removed) {
						k--;
						len--;
					}
				}
			}
		}
	},

	getNearObject: function (point) {
		var x = this._getCoord(point.x),
		    y = this._getCoord(point.y),
		    i, j, k, row, cell, len, obj, dist,
		    objectPoint = this._objectPoint,
		    closestDistSq = this._sqCellSize,
		    closest = null;

		for (i = y - 1; i <= y + 1; i++) {
			row = this._grid[i];
			if (row) {

				for (j = x - 1; j <= x + 1; j++) {
					cell = row[j];
					if (cell) {

						for (k = 0, len = cell.length; k < len; k++) {
							obj = cell[k];
							dist = this._sqDist(objectPoint[stamp$1(obj)], point);
							if (dist < closestDistSq ||
								dist <= closestDistSq && closest === null) {
								closestDistSq = dist;
								closest = obj;
							}
						}
					}
				}
			}
		}
		return closest;
	},

	_getCoord: function (x) {
		var coord = Math.floor(x / this._cellSize);
		return isFinite(coord) ? coord : x;
	},

	_sqDist: function (p, p2) {
		var dx = p2.x - p.x,
		    dy = p2.y - p.y;
		return dx * dx + dy * dy;
	}
};

/*
 * MarkerClusterGroup extends FeatureGroup by clustering the markers contained within
 */

var MarkerClusterGroup = FeatureGroup.extend({

	options: {
		maxClusterRadius: 80, //A cluster will cover at most this many pixels from its center
		iconCreateFunction: null,
		clusterPane: Marker.prototype.options.pane,

		spiderfyOnMaxZoom: true,
		showCoverageOnHover: true,
		zoomToBoundsOnClick: true,
		singleMarkerMode: false,

		disableClusteringAtZoom: null,

		// Setting this to false prevents the removal of any clusters outside of the viewpoint, which
		// is the default behaviour for performance reasons.
		removeOutsideVisibleBounds: true,

		// Set to false to disable all animations (zoom and spiderfy).
		// If false, option animateAddingMarkers below has no effect.
		// If DomUtil.TRANSITION is falsy, this option has no effect.
		animate: true,

		//Whether to animate adding markers after adding the MarkerClusterGroup to the map
		// If you are adding individual markers set to true, if adding bulk markers leave false for massive performance gains.
		animateAddingMarkers: false,

		// Make it possible to provide custom function to calculate spiderfy shape positions
		spiderfyShapePositions: null,

		//Increase to increase the distance away that spiderfied markers appear from the center
		spiderfyDistanceMultiplier: 1,

		// Make it possible to specify a polyline options on a spider leg
		spiderLegPolylineOptions: { weight: 1.5, color: '#222', opacity: 0.5 },

		// When bulk adding layers, adds markers in chunks. Means addLayers may not add all the layers in the call, others will be loaded during setTimeouts
		chunkedLoading: false,
		chunkInterval: 200, // process markers for a maximum of ~ n milliseconds (then trigger the chunkProgress callback)
		chunkDelay: 50, // at the end of each interval, give n milliseconds back to system/browser
		chunkProgress: null, // progress callback: function(processed, total, elapsed) (e.g. for a progress indicator)

		//Options to pass to the Polygon constructor
		polygonOptions: {}
	},

	initialize: function (options) {
		setOptions$1(this, options);
		if (!this.options.iconCreateFunction) {
			this.options.iconCreateFunction = this._defaultIconCreateFunction;
		}

		this._featureGroup = new FeatureGroup();
		this._featureGroup.addEventParent(this);

		this._nonPointGroup = new FeatureGroup();
		this._nonPointGroup.addEventParent(this);

		this._inZoomAnimation = 0;
		this._needsClustering = [];
		this._needsRemoving = []; //Markers removed while we aren't on the map need to be kept track of
		//The bounds of the currently shown area (from _getExpandedVisibleBounds) Updated on zoom/move
		this._currentShownBounds = null;

		this._queue = [];

		this._childMarkerEventHandlers = {
			'dragstart': this._childMarkerDragStart,
			'move': this._childMarkerMoved,
			'dragend': this._childMarkerDragEnd,
		};

		// Hook the appropriate animation methods.
		var animate = TRANSITION && this.options.animate;
		extend(this, animate ? this._withAnimation : this._noAnimation);
		// Remember which MarkerCluster class to instantiate (animated or not).
		this._markerCluster = animate ? MarkerCluster$1 : MarkerClusterNonAnimated;
	},

	addLayer: function (layer) {

		if (layer instanceof LayerGroup$1) {
			return this.addLayers([layer]);
		}

		//Don't cluster non point data
		if (!layer.getLatLng) {
			this._nonPointGroup.addLayer(layer);
			this.fire('layeradd', { layer: layer });
			return this;
		}

		if (!this._map) {
			this._needsClustering.push(layer);
			this.fire('layeradd', { layer: layer });
			return this;
		}

		if (this.hasLayer(layer)) {
			return this;
		}


		//If we have already clustered we'll need to add this one to a cluster

		if (this._unspiderfy) {
			this._unspiderfy();
		}

		this._addLayer(layer, this._maxZoom);
		this.fire('layeradd', { layer: layer });

		// Refresh bounds and weighted positions.
		this._topClusterLevel._recalculateBounds();

		this._refreshClustersIcons();

		//Work out what is visible
		var visibleLayer = layer,
		    currentZoom = this._zoom;
		if (layer.__parent) {
			while (visibleLayer.__parent._zoom >= currentZoom) {
				visibleLayer = visibleLayer.__parent;
			}
		}

		if (this._currentShownBounds.contains(visibleLayer.getLatLng())) {
			if (this.options.animateAddingMarkers) {
				this._animationAddLayer(layer, visibleLayer);
			} else {
				this._animationAddLayerNonAnimated(layer, visibleLayer);
			}
		}
		return this;
	},

	removeLayer: function (layer) {

		if (layer instanceof LayerGroup$1) {
			return this.removeLayers([layer]);
		}

		//Non point layers
		if (!layer.getLatLng) {
			this._nonPointGroup.removeLayer(layer);
			this.fire('layerremove', { layer: layer });
			return this;
		}

		if (!this._map) {
			if (!this._arraySplice(this._needsClustering, layer) && this.hasLayer(layer)) {
				this._needsRemoving.push({ layer: layer, latlng: layer._latlng });
			}
			this.fire('layerremove', { layer: layer });
			return this;
		}

		if (!layer.__parent) {
			return this;
		}

		if (this._unspiderfy) {
			this._unspiderfy();
			this._unspiderfyLayer(layer);
		}

		//Remove the marker from clusters
		this._removeLayer(layer, true);
		this.fire('layerremove', { layer: layer });

		// Refresh bounds and weighted positions.
		this._topClusterLevel._recalculateBounds();

		this._refreshClustersIcons();

		layer.off(this._childMarkerEventHandlers, this);

		if (this._featureGroup.hasLayer(layer)) {
			this._featureGroup.removeLayer(layer);
			if (layer.clusterShow) {
				layer.clusterShow();
			}
		}

		return this;
	},

	//Takes an array of markers and adds them in bulk
	addLayers: function (layersArray, skipLayerAddEvent) {
		if (!isArray(layersArray)) {
			return this.addLayer(layersArray);
		}

		var fg = this._featureGroup,
		    npg = this._nonPointGroup,
		    chunked = this.options.chunkedLoading,
		    chunkInterval = this.options.chunkInterval,
		    chunkProgress = this.options.chunkProgress,
		    l = layersArray.length,
		    offset = 0,
		    originalArray = true,
		    m;

		if (this._map) {
			var started = (new Date()).getTime();
			var process = bind(function () {
				var start = (new Date()).getTime();

				// Make sure to unspiderfy before starting to add some layers
				if (this._map && this._unspiderfy) {
					this._unspiderfy();
				}

				for (; offset < l; offset++) {
					if (chunked && offset % 200 === 0) {
						// every couple hundred markers, instrument the time elapsed since processing started:
						var elapsed = (new Date()).getTime() - start;
						if (elapsed > chunkInterval) {
							break; // been working too hard, time to take a break :-)
						}
					}

					m = layersArray[offset];

					// Group of layers, append children to layersArray and skip.
					// Side effects:
					// - Total increases, so chunkProgress ratio jumps backward.
					// - Groups are not included in this group, only their non-group child layers (hasLayer).
					// Changing array length while looping does not affect performance in current browsers:
					// http://jsperf.com/for-loop-changing-length/6
					if (m instanceof LayerGroup$1) {
						if (originalArray) {
							layersArray = layersArray.slice();
							originalArray = false;
						}
						this._extractNonGroupLayers(m, layersArray);
						l = layersArray.length;
						continue;
					}

					//Not point data, can't be clustered
					if (!m.getLatLng) {
						npg.addLayer(m);
						if (!skipLayerAddEvent) {
							this.fire('layeradd', { layer: m });
						}
						continue;
					}

					if (this.hasLayer(m)) {
						continue;
					}

					this._addLayer(m, this._maxZoom);
					if (!skipLayerAddEvent) {
						this.fire('layeradd', { layer: m });
					}

					//If we just made a cluster of size 2 then we need to remove the other marker from the map (if it is) or we never will
					if (m.__parent) {
						if (m.__parent.getChildCount() === 2) {
							var markers = m.__parent.getAllChildMarkers(),
							    otherMarker = markers[0] === m ? markers[1] : markers[0];
							fg.removeLayer(otherMarker);
						}
					}
				}

				if (chunkProgress) {
					// report progress and time elapsed:
					chunkProgress(offset, l, (new Date()).getTime() - started);
				}

				// Completed processing all markers.
				if (offset === l) {

					// Refresh bounds and weighted positions.
					this._topClusterLevel._recalculateBounds();

					this._refreshClustersIcons();

					this._topClusterLevel._recursivelyAddChildrenToMap(null, this._zoom, this._currentShownBounds);
				} else {
					setTimeout(process, this.options.chunkDelay);
				}
			}, this);

			process();
		} else {
			var needsClustering = this._needsClustering;

			for (; offset < l; offset++) {
				m = layersArray[offset];

				// Group of layers, append children to layersArray and skip.
				if (m instanceof LayerGroup$1) {
					if (originalArray) {
						layersArray = layersArray.slice();
						originalArray = false;
					}
					this._extractNonGroupLayers(m, layersArray);
					l = layersArray.length;
					continue;
				}

				//Not point data, can't be clustered
				if (!m.getLatLng) {
					npg.addLayer(m);
					continue;
				}

				if (this.hasLayer(m)) {
					continue;
				}

				needsClustering.push(m);
			}
		}
		return this;
	},

	//Takes an array of markers and removes them in bulk
	removeLayers: function (layersArray) {
		var i, m,
		    l = layersArray.length,
		    fg = this._featureGroup,
		    npg = this._nonPointGroup,
		    originalArray = true;

		if (!this._map) {
			for (i = 0; i < l; i++) {
				m = layersArray[i];

				// Group of layers, append children to layersArray and skip.
				if (m instanceof LayerGroup$1) {
					if (originalArray) {
						layersArray = layersArray.slice();
						originalArray = false;
					}
					this._extractNonGroupLayers(m, layersArray);
					l = layersArray.length;
					continue;
				}

				this._arraySplice(this._needsClustering, m);
				npg.removeLayer(m);
				if (this.hasLayer(m)) {
					this._needsRemoving.push({ layer: m, latlng: m._latlng });
				}
				this.fire('layerremove', { layer: m });
			}
			return this;
		}

		if (this._unspiderfy) {
			this._unspiderfy();

			// Work on a copy of the array, so that next loop is not affected.
			var layersArray2 = layersArray.slice(),
			    l2 = l;
			for (i = 0; i < l2; i++) {
				m = layersArray2[i];

				// Group of layers, append children to layersArray and skip.
				if (m instanceof LayerGroup$1) {
					this._extractNonGroupLayers(m, layersArray2);
					l2 = layersArray2.length;
					continue;
				}

				this._unspiderfyLayer(m);
			}
		}

		for (i = 0; i < l; i++) {
			m = layersArray[i];

			// Group of layers, append children to layersArray and skip.
			if (m instanceof LayerGroup$1) {
				if (originalArray) {
					layersArray = layersArray.slice();
					originalArray = false;
				}
				this._extractNonGroupLayers(m, layersArray);
				l = layersArray.length;
				continue;
			}

			if (!m.__parent) {
				npg.removeLayer(m);
				this.fire('layerremove', { layer: m });
				continue;
			}

			this._removeLayer(m, true, true);
			this.fire('layerremove', { layer: m });

			if (fg.hasLayer(m)) {
				fg.removeLayer(m);
				if (m.clusterShow) {
					m.clusterShow();
				}
			}
		}

		// Refresh bounds and weighted positions.
		this._topClusterLevel._recalculateBounds();

		this._refreshClustersIcons();

		//Fix up the clusters and markers on the map
		this._topClusterLevel._recursivelyAddChildrenToMap(null, this._zoom, this._currentShownBounds);

		return this;
	},

	//Removes all layers from the MarkerClusterGroup
	clearLayers: function () {
		//Need our own special implementation as the LayerGroup one doesn't work for us

		//If we aren't on the map (yet), blow away the markers we know of
		if (!this._map) {
			this._needsClustering = [];
			this._needsRemoving = [];
			delete this._gridClusters;
			delete this._gridUnclustered;
		}

		if (this._noanimationUnspiderfy) {
			this._noanimationUnspiderfy();
		}

		//Remove all the visible layers
		this._featureGroup.clearLayers();
		this._nonPointGroup.clearLayers();

		this.eachLayer(function (marker) {
			marker.off(this._childMarkerEventHandlers, this);
			delete marker.__parent;
		}, this);

		if (this._map) {
			//Reset _topClusterLevel and the DistanceGrids
			this._generateInitialClusters();
		}

		return this;
	},

	//Override FeatureGroup.getBounds as it doesn't work
	getBounds: function () {
		var bounds = new LatLngBounds();

		if (this._topClusterLevel) {
			bounds.extend(this._topClusterLevel._bounds);
		}

		for (var i = this._needsClustering.length - 1; i >= 0; i--) {
			bounds.extend(this._needsClustering[i].getLatLng());
		}

		bounds.extend(this._nonPointGroup.getBounds());

		return bounds;
	},

	//Overrides LayerGroup.eachLayer
	eachLayer: function (method, context) {
		var markers = this._needsClustering.slice(),
			needsRemoving = this._needsRemoving,
			thisNeedsRemoving, i, j;

		if (this._topClusterLevel) {
			this._topClusterLevel.getAllChildMarkers(markers);
		}

		for (i = markers.length - 1; i >= 0; i--) {
			thisNeedsRemoving = true;

			for (j = needsRemoving.length - 1; j >= 0; j--) {
				if (needsRemoving[j].layer === markers[i]) {
					thisNeedsRemoving = false;
					break;
				}
			}

			if (thisNeedsRemoving) {
				method.call(context, markers[i]);
			}
		}

		this._nonPointGroup.eachLayer(method, context);
	},

	//Overrides LayerGroup.getLayers
	getLayers: function () {
		var layers = [];
		this.eachLayer(function (l) {
			layers.push(l);
		});
		return layers;
	},

	//Overrides LayerGroup.getLayer, WARNING: Really bad performance
	getLayer: function (id) {
		var result = null;

		id = parseInt(id, 10);

		this.eachLayer(function (l) {
			if (stamp(l) === id) {
				result = l;
			}
		});

		return result;
	},

	//Returns true if the given layer is in this MarkerClusterGroup
	hasLayer: function (layer) {
		if (!layer) {
			return false;
		}

		var i, anArray = this._needsClustering;

		for (i = anArray.length - 1; i >= 0; i--) {
			if (anArray[i] === layer) {
				return true;
			}
		}

		anArray = this._needsRemoving;
		for (i = anArray.length - 1; i >= 0; i--) {
			if (anArray[i].layer === layer) {
				return false;
			}
		}

		return !!(layer.__parent && layer.__parent._group === this) || this._nonPointGroup.hasLayer(layer);
	},

	//Zoom down to show the given layer (spiderfying if necessary) then calls the callback
	zoomToShowLayer: function (layer, callback) {

		var map = this._map;

		if (typeof callback !== 'function') {
			callback = function () {};
		}

		var showMarker = function () {
			// Assumes that map.hasLayer checks for direct appearance on map, not recursively calling
			// hasLayer on Layer Groups that are on map (typically not calling this MarkerClusterGroup.hasLayer, which would always return true)
			if ((map.hasLayer(layer) || map.hasLayer(layer.__parent)) && !this._inZoomAnimation) {
				this._map.off('moveend', showMarker, this);
				this.off('animationend', showMarker, this);

				if (map.hasLayer(layer)) {
					callback();
				} else if (layer.__parent._icon) {
					this.once('spiderfied', callback, this);
					layer.__parent.spiderfy();
				}
			}
		};

		if (layer._icon && this._map.getBounds().contains(layer.getLatLng())) {
			//Layer is visible ond on screen, immediate return
			callback();
		} else if (layer.__parent._zoom < Math.round(this._map._zoom)) {
			//Layer should be visible at this zoom level. It must not be on screen so just pan over to it
			this._map.on('moveend', showMarker, this);
			this._map.panTo(layer.getLatLng());
		} else {
			this._map.on('moveend', showMarker, this);
			this.on('animationend', showMarker, this);
			layer.__parent.zoomToBounds();
		}
	},

	//Overrides FeatureGroup.onAdd
	onAdd: function (map) {
		this._map = map;
		var i, l, layer;

		if (!isFinite(this._map.getMaxZoom())) {
			throw "Map has no maxZoom specified";
		}

		this._featureGroup.addTo(map);
		this._nonPointGroup.addTo(map);

		if (!this._gridClusters) {
			this._generateInitialClusters();
		}

		this._maxLat = map.options.crs.projection.MAX_LATITUDE;

		//Restore all the positions as they are in the MCG before removing them
		for (i = 0, l = this._needsRemoving.length; i < l; i++) {
			layer = this._needsRemoving[i];
			layer.newlatlng = layer.layer._latlng;
			layer.layer._latlng = layer.latlng;
		}
		//Remove them, then restore their new positions
		for (i = 0, l = this._needsRemoving.length; i < l; i++) {
			layer = this._needsRemoving[i];
			this._removeLayer(layer.layer, true);
			layer.layer._latlng = layer.newlatlng;
		}
		this._needsRemoving = [];

		//Remember the current zoom level and bounds
		this._zoom = Math.round(this._map._zoom);
		this._currentShownBounds = this._getExpandedVisibleBounds();

		this._map.on('zoomend', this._zoomEnd, this);
		this._map.on('moveend', this._moveEnd, this);

		if (this._spiderfierOnAdd) { //TODO FIXME: Not sure how to have spiderfier add something on here nicely
			this._spiderfierOnAdd();
		}

		this._bindEvents();

		//Actually add our markers to the map:
		l = this._needsClustering;
		this._needsClustering = [];
		this.addLayers(l, true);
	},

	//Overrides FeatureGroup.onRemove
	onRemove: function (map) {
		map.off('zoomend', this._zoomEnd, this);
		map.off('moveend', this._moveEnd, this);

		this._unbindEvents();

		//In case we are in a cluster animation
		this._map._mapPane.className = this._map._mapPane.className.replace(' leaflet-cluster-anim', '');

		if (this._spiderfierOnRemove) { //TODO FIXME: Not sure how to have spiderfier add something on here nicely
			this._spiderfierOnRemove();
		}

		delete this._maxLat;

		//Clean up all the layers we added to the map
		this._hideCoverage();
		this._featureGroup.remove();
		this._nonPointGroup.remove();

		this._featureGroup.clearLayers();

		this._map = null;
	},

	getVisibleParent: function (marker) {
		var vMarker = marker;
		while (vMarker && !vMarker._icon) {
			vMarker = vMarker.__parent;
		}
		return vMarker || null;
	},

	//Remove the given object from the given array
	_arraySplice: function (anArray, obj) {
		for (var i = anArray.length - 1; i >= 0; i--) {
			if (anArray[i] === obj) {
				anArray.splice(i, 1);
				return true;
			}
		}
	},

	/**
	 * Removes a marker from all _gridUnclustered zoom levels, starting at the supplied zoom.
	 * @param marker to be removed from _gridUnclustered.
	 * @param z integer bottom start zoom level (included)
	 * @private
	 */
	_removeFromGridUnclustered: function (marker, z) {
		var map = this._map,
		    gridUnclustered = this._gridUnclustered,
			minZoom = Math.floor(this._map.getMinZoom());

		for (; z >= minZoom; z--) {
			if (!gridUnclustered[z].removeObject(marker, map.project(marker.getLatLng(), z))) {
				break;
			}
		}
	},

	_childMarkerDragStart: function (e) {
		e.target.__dragStart = e.target._latlng;
	},

	_childMarkerMoved: function (e) {
		if (!this._ignoreMove && !e.target.__dragStart) {
			var isPopupOpen = e.target._popup && e.target._popup.isOpen();

			this._moveChild(e.target, e.oldLatLng, e.latlng);

			if (isPopupOpen) {
				e.target.openPopup();
			}
		}
	},

	_moveChild: function (layer, from, to) {
		layer._latlng = from;
		this.removeLayer(layer);

		layer._latlng = to;
		this.addLayer(layer);
	},

	_childMarkerDragEnd: function (e) {
		var dragStart = e.target.__dragStart;
		delete e.target.__dragStart;
		if (dragStart) {
			this._moveChild(e.target, dragStart, e.target._latlng);
		}
	},


	//Internal function for removing a marker from everything.
	//dontUpdateMap: set to true if you will handle updating the map manually (for bulk functions)
	_removeLayer: function (marker, removeFromDistanceGrid, dontUpdateMap) {
		var gridClusters = this._gridClusters,
			gridUnclustered = this._gridUnclustered,
			fg = this._featureGroup,
			map = this._map,
			minZoom = Math.floor(this._map.getMinZoom());

		//Remove the marker from distance clusters it might be in
		if (removeFromDistanceGrid) {
			this._removeFromGridUnclustered(marker, this._maxZoom);
		}

		//Work our way up the clusters removing them as we go if required
		var cluster = marker.__parent,
			markers = cluster._markers,
			otherMarker;

		//Remove the marker from the immediate parents marker list
		this._arraySplice(markers, marker);

		while (cluster) {
			cluster._childCount--;
			cluster._boundsNeedUpdate = true;

			if (cluster._zoom < minZoom) {
				//Top level, do nothing
				break;
			} else if (removeFromDistanceGrid && cluster._childCount <= 1) { //Cluster no longer required
				//We need to push the other marker up to the parent
				otherMarker = cluster._markers[0] === marker ? cluster._markers[1] : cluster._markers[0];

				//Update distance grid
				gridClusters[cluster._zoom].removeObject(cluster, map.project(cluster._cLatLng, cluster._zoom));
				gridUnclustered[cluster._zoom].addObject(otherMarker, map.project(otherMarker.getLatLng(), cluster._zoom));

				//Move otherMarker up to parent
				this._arraySplice(cluster.__parent._childClusters, cluster);
				cluster.__parent._markers.push(otherMarker);
				otherMarker.__parent = cluster.__parent;

				if (cluster._icon) {
					//Cluster is currently on the map, need to put the marker on the map instead
					fg.removeLayer(cluster);
					if (!dontUpdateMap) {
						fg.addLayer(otherMarker);
					}
				}
			} else {
				cluster._iconNeedsUpdate = true;
			}

			cluster = cluster.__parent;
		}

		delete marker.__parent;
	},

	_isOrIsParent: function (el, oel) {
		while (oel) {
			if (el === oel) {
				return true;
			}
			oel = oel.parentNode;
		}
		return false;
	},

	//Override Evented.fire
	fire: function (type, data, propagate) {
		if (data && data.layer instanceof MarkerCluster$1) {
			//Prevent multiple clustermouseover/off events if the icon is made up of stacked divs (Doesn't work in ie <= 8, no relatedTarget)
			if (data.originalEvent && this._isOrIsParent(data.layer._icon, data.originalEvent.relatedTarget)) {
				return;
			}
			type = 'cluster' + type;
		}

		FeatureGroup.prototype.fire.call(this, type, data, propagate);
	},

	//Override Evented.listens
	listens: function (type, propagate) {
		return FeatureGroup.prototype.listens.call(this, type, propagate) || FeatureGroup.prototype.listens.call(this, 'cluster' + type, propagate);
	},

	//Default functionality
	_defaultIconCreateFunction: function (cluster) {
		var childCount = cluster.getChildCount();

		var c = ' marker-cluster-';
		if (childCount < 10) {
			c += 'small';
		} else if (childCount < 100) {
			c += 'medium';
		} else {
			c += 'large';
		}

		return new DivIcon({ html: '<div><span>' + childCount + '</span></div>', className: 'marker-cluster' + c, iconSize: new Point(40, 40) });
	},

	_bindEvents: function () {
		var map = this._map,
		    spiderfyOnMaxZoom = this.options.spiderfyOnMaxZoom,
		    showCoverageOnHover = this.options.showCoverageOnHover,
		    zoomToBoundsOnClick = this.options.zoomToBoundsOnClick;

		//Zoom on cluster click or spiderfy if we are at the lowest level
		if (spiderfyOnMaxZoom || zoomToBoundsOnClick) {
			this.on('clusterclick', this._zoomOrSpiderfy, this);
		}

		//Show convex hull (boundary) polygon on mouse over
		if (showCoverageOnHover) {
			this.on('clustermouseover', this._showCoverage, this);
			this.on('clustermouseout', this._hideCoverage, this);
			map.on('zoomend', this._hideCoverage, this);
		}
	},

	_zoomOrSpiderfy: function (e) {
		var cluster = e.layer,
		    bottomCluster = cluster;

		while (bottomCluster._childClusters.length === 1) {
			bottomCluster = bottomCluster._childClusters[0];
		}

		if (bottomCluster._zoom === this._maxZoom &&
			bottomCluster._childCount === cluster._childCount &&
			this.options.spiderfyOnMaxZoom) {

			// All child markers are contained in a single cluster from this._maxZoom to this cluster.
			cluster.spiderfy();
		} else if (this.options.zoomToBoundsOnClick) {
			cluster.zoomToBounds();
		}

		// Focus the map again for keyboard users.
		if (e.originalEvent && e.originalEvent.keyCode === 13) {
			this._map._container.focus();
		}
	},

	_showCoverage: function (e) {
		var map = this._map;
		if (this._inZoomAnimation) {
			return;
		}
		if (this._shownPolygon) {
			map.removeLayer(this._shownPolygon);
		}
		if (e.layer.getChildCount() > 2 && e.layer !== this._spiderfied) {
			this._shownPolygon = new Polygon(e.layer.getConvexHull(), this.options.polygonOptions);
			map.addLayer(this._shownPolygon);
		}
	},

	_hideCoverage: function () {
		if (this._shownPolygon) {
			this._map.removeLayer(this._shownPolygon);
			this._shownPolygon = null;
		}
	},

	_unbindEvents: function () {
		var spiderfyOnMaxZoom = this.options.spiderfyOnMaxZoom,
			showCoverageOnHover = this.options.showCoverageOnHover,
			zoomToBoundsOnClick = this.options.zoomToBoundsOnClick,
			map = this._map;

		if (spiderfyOnMaxZoom || zoomToBoundsOnClick) {
			this.off('clusterclick', this._zoomOrSpiderfy, this);
		}
		if (showCoverageOnHover) {
			this.off('clustermouseover', this._showCoverage, this);
			this.off('clustermouseout', this._hideCoverage, this);
			map.off('zoomend', this._hideCoverage, this);
		}
	},

	_zoomEnd: function () {
		if (!this._map) { //May have been removed from the map by a zoomEnd handler
			return;
		}
		this._mergeSplitClusters();

		this._zoom = Math.round(this._map._zoom);
		this._currentShownBounds = this._getExpandedVisibleBounds();
	},

	_moveEnd: function () {
		if (this._inZoomAnimation) {
			return;
		}

		var newBounds = this._getExpandedVisibleBounds();

		this._topClusterLevel._recursivelyRemoveChildrenFromMap(this._currentShownBounds, Math.floor(this._map.getMinZoom()), this._zoom, newBounds);
		this._topClusterLevel._recursivelyAddChildrenToMap(null, Math.round(this._map._zoom), newBounds);

		this._currentShownBounds = newBounds;
		return;
	},

	_generateInitialClusters: function () {
		var maxZoom = Math.ceil(this._map.getMaxZoom()),
			minZoom = Math.floor(this._map.getMinZoom()),
			radius = this.options.maxClusterRadius,
			radiusFn = radius;

		//If we just set maxClusterRadius to a single number, we need to create
		//a simple function to return that number. Otherwise, we just have to
		//use the function we've passed in.
		if (typeof radius !== "function") {
			radiusFn = function () { return radius; };
		}

		if (this.options.disableClusteringAtZoom !== null) {
			maxZoom = this.options.disableClusteringAtZoom - 1;
		}
		this._maxZoom = maxZoom;
		this._gridClusters = {};
		this._gridUnclustered = {};

		//Set up DistanceGrids for each zoom
		for (var zoom = maxZoom; zoom >= minZoom; zoom--) {
			this._gridClusters[zoom] = new DistanceGrid(radiusFn(zoom));
			this._gridUnclustered[zoom] = new DistanceGrid(radiusFn(zoom));
		}

		// Instantiate the appropriate MarkerCluster class (animated or not).
		this._topClusterLevel = new this._markerCluster(this, minZoom - 1);
	},

	//Zoom: Zoom to start adding at (Pass this._maxZoom to start at the bottom)
	_addLayer: function (layer, zoom) {
		var gridClusters = this._gridClusters,
		    gridUnclustered = this._gridUnclustered,
			minZoom = Math.floor(this._map.getMinZoom()),
		    markerPoint, z;

		if (this.options.singleMarkerMode) {
			this._overrideMarkerIcon(layer);
		}

		layer.on(this._childMarkerEventHandlers, this);

		//Find the lowest zoom level to slot this one in
		for (; zoom >= minZoom; zoom--) {
			markerPoint = this._map.project(layer.getLatLng(), zoom); // calculate pixel position

			//Try find a cluster close by
			var closest = gridClusters[zoom].getNearObject(markerPoint);
			if (closest) {
				closest._addChild(layer);
				layer.__parent = closest;
				return;
			}

			//Try find a marker close by to form a new cluster with
			closest = gridUnclustered[zoom].getNearObject(markerPoint);
			if (closest) {
				var parent = closest.__parent;
				if (parent) {
					this._removeLayer(closest, false);
				}

				//Create new cluster with these 2 in it

				var newCluster = new this._markerCluster(this, zoom, closest, layer);
				gridClusters[zoom].addObject(newCluster, this._map.project(newCluster._cLatLng, zoom));
				closest.__parent = newCluster;
				layer.__parent = newCluster;

				//First create any new intermediate parent clusters that don't exist
				var lastParent = newCluster;
				for (z = zoom - 1; z > parent._zoom; z--) {
					lastParent = new this._markerCluster(this, z, lastParent);
					gridClusters[z].addObject(lastParent, this._map.project(closest.getLatLng(), z));
				}
				parent._addChild(lastParent);

				//Remove closest from this zoom level and any above that it is in, replace with newCluster
				this._removeFromGridUnclustered(closest, zoom);

				return;
			}

			//Didn't manage to cluster in at this zoom, record us as a marker here and continue upwards
			gridUnclustered[zoom].addObject(layer, markerPoint);
		}

		//Didn't get in anything, add us to the top
		this._topClusterLevel._addChild(layer);
		layer.__parent = this._topClusterLevel;
		return;
	},

	/**
	 * Refreshes the icon of all "dirty" visible clusters.
	 * Non-visible "dirty" clusters will be updated when they are added to the map.
	 * @private
	 */
	_refreshClustersIcons: function () {
		this._featureGroup.eachLayer(function (c) {
			if (c instanceof MarkerCluster$1 && c._iconNeedsUpdate) {
				c._updateIcon();
			}
		});
	},

	//Enqueue code to fire after the marker expand/contract has happened
	_enqueue: function (fn) {
		this._queue.push(fn);
		if (!this._queueTimeout) {
			this._queueTimeout = setTimeout(bind(this._processQueue, this), 300);
		}
	},
	_processQueue: function () {
		for (var i = 0; i < this._queue.length; i++) {
			this._queue[i].call(this);
		}
		this._queue.length = 0;
		clearTimeout(this._queueTimeout);
		this._queueTimeout = null;
	},

	//Merge and split any existing clusters that are too big or small
	_mergeSplitClusters: function () {
		var mapZoom = Math.round(this._map._zoom);

		//In case we are starting to split before the animation finished
		this._processQueue();

		if (this._zoom < mapZoom && this._currentShownBounds.intersects(this._getExpandedVisibleBounds())) { //Zoom in, split
			this._animationStart();
			//Remove clusters now off screen
			this._topClusterLevel._recursivelyRemoveChildrenFromMap(this._currentShownBounds, Math.floor(this._map.getMinZoom()), this._zoom, this._getExpandedVisibleBounds());

			this._animationZoomIn(this._zoom, mapZoom);

		} else if (this._zoom > mapZoom) { //Zoom out, merge
			this._animationStart();

			this._animationZoomOut(this._zoom, mapZoom);
		} else {
			this._moveEnd();
		}
	},

	//Gets the maps visible bounds expanded in each direction by the size of the screen (so the user cannot see an area we do not cover in one pan)
	_getExpandedVisibleBounds: function () {
		if (!this.options.removeOutsideVisibleBounds) {
			return this._mapBoundsInfinite;
		} else if (mobile) {
			return this._checkBoundsMaxLat(this._map.getBounds());
		}

		return this._checkBoundsMaxLat(this._map.getBounds().pad(1)); // Padding expands the bounds by its own dimensions but scaled with the given factor.
	},

	/**
	 * Expands the latitude to Infinity (or -Infinity) if the input bounds reach the map projection maximum defined latitude
	 * (in the case of Web/Spherical Mercator, it is 85.0511287798 / see https://en.wikipedia.org/wiki/Web_Mercator#Formulas).
	 * Otherwise, the removeOutsideVisibleBounds option will remove markers beyond that limit, whereas the same markers without
	 * this option (or outside MCG) will have their position floored (ceiled) by the projection and rendered at that limit,
	 * making the user think that MCG "eats" them and never displays them again.
	 * @param bounds L.LatLngBounds
	 * @returns {LatLngBounds}
	 * @private
	 */
	_checkBoundsMaxLat: function (bounds) {
		var maxLat = this._maxLat;

		if (maxLat !== undefined) {
			if (bounds.getNorth() >= maxLat) {
				bounds._northEast.lat = Infinity;
			}
			if (bounds.getSouth() <= -maxLat) {
				bounds._southWest.lat = -Infinity;
			}
		}

		return bounds;
	},

	//Shared animation code
	_animationAddLayerNonAnimated: function (layer, newCluster) {
		if (newCluster === layer) {
			this._featureGroup.addLayer(layer);
		} else if (newCluster._childCount === 2) {
			newCluster._addToMap();

			var markers = newCluster.getAllChildMarkers();
			this._featureGroup.removeLayer(markers[0]);
			this._featureGroup.removeLayer(markers[1]);
		} else {
			newCluster._updateIcon();
		}
	},

	/**
	 * Extracts individual (i.e. non-group) layers from a Layer Group.
	 * @param group to extract layers from.
	 * @param output {Array} in which to store the extracted layers.
	 * @returns {*|Array}
	 * @private
	 */
	_extractNonGroupLayers: function (group, output) {
		var layers = group.getLayers(),
		    i = 0,
		    layer;

		output = output || [];

		for (; i < layers.length; i++) {
			layer = layers[i];

			if (layer instanceof LayerGroup$1) {
				this._extractNonGroupLayers(layer, output);
				continue;
			}

			output.push(layer);
		}

		return output;
	},

	/**
	 * Implements the singleMarkerMode option.
	 * @param layer Marker to re-style using the Clusters iconCreateFunction.
	 * @returns {Icon} The newly created icon.
	 * @private
	 */
	_overrideMarkerIcon: function (layer) {
		var icon = layer.options.icon = this.options.iconCreateFunction({
			getChildCount: function () {
				return 1;
			},
			getAllChildMarkers: function () {
				return [layer];
			}
		});

		return icon;
	}
});

// Constant bounds used in case option "removeOutsideVisibleBounds" is set to false.
MarkerClusterGroup.include({
	_mapBoundsInfinite: new LatLngBounds(new LatLng(-Infinity, -Infinity), new LatLng(Infinity, Infinity))
});

MarkerClusterGroup.include({
	_noAnimation: {
		//Non Animated versions of everything
		_animationStart: function () {
			//Do nothing...
		},
		_animationZoomIn: function (previousZoomLevel, newZoomLevel) {
			this._topClusterLevel._recursivelyRemoveChildrenFromMap(this._currentShownBounds, Math.floor(this._map.getMinZoom()), previousZoomLevel);
			this._topClusterLevel._recursivelyAddChildrenToMap(null, newZoomLevel, this._getExpandedVisibleBounds());

			//We didn't actually animate, but we use this event to mean "clustering animations have finished"
			this.fire('animationend');
		},
		_animationZoomOut: function (previousZoomLevel, newZoomLevel) {
			this._topClusterLevel._recursivelyRemoveChildrenFromMap(this._currentShownBounds, Math.floor(this._map.getMinZoom()), previousZoomLevel);
			this._topClusterLevel._recursivelyAddChildrenToMap(null, newZoomLevel, this._getExpandedVisibleBounds());

			//We didn't actually animate, but we use this event to mean "clustering animations have finished"
			this.fire('animationend');
		},
		_animationAddLayer: function (layer, newCluster) {
			this._animationAddLayerNonAnimated(layer, newCluster);
		}
	},

	_withAnimation: {
		//Animated versions here
		_animationStart: function () {
			this._map._mapPane.className += ' leaflet-cluster-anim';
			this._inZoomAnimation++;
		},

		_animationZoomIn: function (previousZoomLevel, newZoomLevel) {
			var bounds = this._getExpandedVisibleBounds(),
			    fg = this._featureGroup,
				minZoom = Math.floor(this._map.getMinZoom()),
			    i;

			this._ignoreMove = true;

			//Add all children of current clusters to map and remove those clusters from map
			this._topClusterLevel._recursively(bounds, previousZoomLevel, minZoom, function (c) {
				var startPos = c._latlng,
				    markers  = c._markers,
				    m;

				if (!bounds.contains(startPos)) {
					startPos = null;
				}

				if (c._isSingleParent() && previousZoomLevel + 1 === newZoomLevel) { //Immediately add the new child and remove us
					fg.removeLayer(c);
					c._recursivelyAddChildrenToMap(null, newZoomLevel, bounds);
				} else {
					//Fade out old cluster
					c.clusterHide();
					c._recursivelyAddChildrenToMap(startPos, newZoomLevel, bounds);
				}

				//Remove all markers that aren't visible any more
				//TODO: Do we actually need to do this on the higher levels too?
				for (i = markers.length - 1; i >= 0; i--) {
					m = markers[i];
					if (!bounds.contains(m._latlng)) {
						fg.removeLayer(m);
					}
				}

			});

			this._forceLayout();

			//Update opacities
			this._topClusterLevel._recursivelyBecomeVisible(bounds, newZoomLevel);
			//TODO Maybe? Update markers in _recursivelyBecomeVisible
			fg.eachLayer(function (n) {
				if (!(n instanceof MarkerCluster$1) && n._icon) {
					n.clusterShow();
				}
			});

			//update the positions of the just added clusters/markers
			this._topClusterLevel._recursively(bounds, previousZoomLevel, newZoomLevel, function (c) {
				c._recursivelyRestoreChildPositions(newZoomLevel);
			});

			this._ignoreMove = false;

			//Remove the old clusters and close the zoom animation
			this._enqueue(function () {
				//update the positions of the just added clusters/markers
				this._topClusterLevel._recursively(bounds, previousZoomLevel, minZoom, function (c) {
					fg.removeLayer(c);
					c.clusterShow();
				});

				this._animationEnd();
			});
		},

		_animationZoomOut: function (previousZoomLevel, newZoomLevel) {
			this._animationZoomOutSingle(this._topClusterLevel, previousZoomLevel - 1, newZoomLevel);

			//Need to add markers for those that weren't on the map before but are now
			this._topClusterLevel._recursivelyAddChildrenToMap(null, newZoomLevel, this._getExpandedVisibleBounds());
			//Remove markers that were on the map before but won't be now
			this._topClusterLevel._recursivelyRemoveChildrenFromMap(this._currentShownBounds, Math.floor(this._map.getMinZoom()), previousZoomLevel, this._getExpandedVisibleBounds());
		},

		_animationAddLayer: function (layer, newCluster) {
			var me = this,
			    fg = this._featureGroup;

			fg.addLayer(layer);
			if (newCluster !== layer) {
				if (newCluster._childCount > 2) { //Was already a cluster

					newCluster._updateIcon();
					this._forceLayout();
					this._animationStart();

					layer._setPos(this._map.latLngToLayerPoint(newCluster.getLatLng()));
					layer.clusterHide();

					this._enqueue(function () {
						fg.removeLayer(layer);
						layer.clusterShow();

						me._animationEnd();
					});

				} else { //Just became a cluster
					this._forceLayout();

					me._animationStart();
					me._animationZoomOutSingle(newCluster, this._map.getMaxZoom(), this._zoom);
				}
			}
		}
	},

	// Private methods for animated versions.
	_animationZoomOutSingle: function (cluster, previousZoomLevel, newZoomLevel) {
		var bounds = this._getExpandedVisibleBounds(),
			minZoom = Math.floor(this._map.getMinZoom());

		//Animate all of the markers in the clusters to move to their cluster center point
		cluster._recursivelyAnimateChildrenInAndAddSelfToMap(bounds, minZoom, previousZoomLevel + 1, newZoomLevel);

		var me = this;

		//Update the opacity (If we immediately set it they won't animate)
		this._forceLayout();
		cluster._recursivelyBecomeVisible(bounds, newZoomLevel);

		//TODO: Maybe use the transition timing stuff to make this more reliable
		//When the animations are done, tidy up
		this._enqueue(function () {

			//This cluster stopped being a cluster before the timeout fired
			if (cluster._childCount === 1) {
				var m = cluster._markers[0];
				//If we were in a cluster animation at the time then the opacity and position of our child could be wrong now, so fix it
				this._ignoreMove = true;
				m.setLatLng(m.getLatLng());
				this._ignoreMove = false;
				if (m.clusterShow) {
					m.clusterShow();
				}
			} else {
				cluster._recursively(bounds, newZoomLevel, minZoom, function (c) {
					c._recursivelyRemoveChildrenFromMap(bounds, minZoom, previousZoomLevel + 1);
				});
			}
			me._animationEnd();
		});
	},

	_animationEnd: function () {
		if (this._map) {
			this._map._mapPane.className = this._map._mapPane.className.replace(' leaflet-cluster-anim', '');
		}
		this._inZoomAnimation--;
		this.fire('animationend');
	},

	//Force a browser layout of stuff in the map
	// Should apply the current opacity and location to all elements so we can update them again for an animation
	_forceLayout: function () {
		//In my testing this works, infact offsetWidth of any element seems to work.
		//Could loop all this._layers and do this for each _icon if it stops working

		falseFn(document.body.offsetWidth);
	}
});

/*
* Extends Marker to include two extra methods: clusterHide and clusterShow.
*
* They work as setOpacity(0) and setOpacity(1) respectively, but
* don't overwrite the options.opacity
*
*/

Marker.include({
	clusterHide: function () {
		var backup = this.options.opacity;
		this.setOpacity(0);
		this.options.opacity = backup;
		return this;
	},

	clusterShow: function () {
		return this.setOpacity(this.options.opacity);
	}
});

/* Copyright (c) 2012 the authors listed at the following URL, and/or
the authors of referenced articles or incorporated external code:
http://en.literateprograms.org/Quickhull_(Javascript)?action=history&offset=20120410175256

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Retrieved from: http://en.literateprograms.org/Quickhull_(Javascript)?oldid=18434
*/

//(function () {
	var QuickHull = {

		/*
		 * @param {Object} cpt a point to be measured from the baseline
		 * @param {Array} bl the baseline, as represented by a two-element
		 *   array of latlng objects.
		 * @returns {Number} an approximate distance measure
		 */
		getDistant: function (cpt, bl) {
			var vY = bl[1].lat - bl[0].lat,
				vX = bl[0].lng - bl[1].lng;
			return (vX * (cpt.lat - bl[0].lat) + vY * (cpt.lng - bl[0].lng));
		},

		/*
		 * @param {Array} baseLine a two-element array of latlng objects
		 *   representing the baseline to project from
		 * @param {Array} latLngs an array of latlng objects
		 * @returns {Object} the maximum point and all new points to stay
		 *   in consideration for the hull.
		 */
		findMostDistantPointFromBaseLine: function (baseLine, latLngs) {
			var maxD = 0,
				maxPt = null,
				newPoints = [],
				i, pt, d;

			for (i = latLngs.length - 1; i >= 0; i--) {
				pt = latLngs[i];
				d = this.getDistant(pt, baseLine);

				if (d > 0) {
					newPoints.push(pt);
				} else {
					continue;
				}

				if (d > maxD) {
					maxD = d;
					maxPt = pt;
				}
			}

			return { maxPoint: maxPt, newPoints: newPoints };
		},


		/*
		 * Given a baseline, compute the convex hull of latLngs as an array
		 * of latLngs.
		 *
		 * @param {Array} latLngs
		 * @returns {Array}
		 */
		buildConvexHull: function (baseLine, latLngs) {
			var convexHullBaseLines = [],
				t = this.findMostDistantPointFromBaseLine(baseLine, latLngs);

			if (t.maxPoint) { // if there is still a point "outside" the base line
				convexHullBaseLines =
					convexHullBaseLines.concat(
						this.buildConvexHull([baseLine[0], t.maxPoint], t.newPoints)
					);
				convexHullBaseLines =
					convexHullBaseLines.concat(
						this.buildConvexHull([t.maxPoint, baseLine[1]], t.newPoints)
					);
				return convexHullBaseLines;
			} else {  // if there is no more point "outside" the base line, the current base line is part of the convex hull
				return [baseLine[0]];
			}
		},

		/*
		 * Given an array of latlngs, compute a convex hull as an array
		 * of latlngs
		 *
		 * @param {Array} latLngs
		 * @returns {Array}
		 */
		getConvexHull: function (latLngs) {
			// find first baseline
			var maxLat = false, minLat = false,
				maxLng = false, minLng = false,
				maxLatPt = null, minLatPt = null,
				maxLngPt = null, minLngPt = null,
				maxPt = null, minPt = null,
				i;

			for (i = latLngs.length - 1; i >= 0; i--) {
				var pt = latLngs[i];
				if (maxLat === false || pt.lat > maxLat) {
					maxLatPt = pt;
					maxLat = pt.lat;
				}
				if (minLat === false || pt.lat < minLat) {
					minLatPt = pt;
					minLat = pt.lat;
				}
				if (maxLng === false || pt.lng > maxLng) {
					maxLngPt = pt;
					maxLng = pt.lng;
				}
				if (minLng === false || pt.lng < minLng) {
					minLngPt = pt;
					minLng = pt.lng;
				}
			}

			if (minLat !== maxLat) {
				minPt = minLatPt;
				maxPt = maxLatPt;
			} else {
				minPt = minLngPt;
				maxPt = maxLngPt;
			}

			var ch = [].concat(this.buildConvexHull([minPt, maxPt], latLngs),
								this.buildConvexHull([maxPt, minPt], latLngs));
			return ch;
		}
	};
//}());

MarkerCluster$1.include({
	getConvexHull: function () {
		var childMarkers = this.getAllChildMarkers(),
			points = [],
			p, i;

		for (i = childMarkers.length - 1; i >= 0; i--) {
			p = childMarkers[i].getLatLng();
			points.push(p);
		}

		return QuickHull.getConvexHull(points);
	}
});

//This code is 100% based on https://github.com/jawj/OverlappingMarkerSpiderfier-Leaflet

MarkerCluster$1.include({

	_2PI: Math.PI * 2,
	_circleFootSeparation: 25, //related to circumference of circle
	_circleStartAngle: 0,

	_spiralFootSeparation:  28, //related to size of spiral (experiment!)
	_spiralLengthStart: 11,
	_spiralLengthFactor: 5,

	_circleSpiralSwitchover: 9, //show spiral instead of circle from this marker count upwards.
								// 0 -> always spiral; Infinity -> always circle

	spiderfy: function () {
		if (this._group._spiderfied === this || this._group._inZoomAnimation) {
			return;
		}

		var childMarkers = this.getAllChildMarkers(null, true),
			group = this._group,
			map = group._map,
			center = map.latLngToLayerPoint(this._latlng),
			positions;

		this._group._unspiderfy();
		this._group._spiderfied = this;

		//TODO Maybe: childMarkers order by distance to center

		if (this._group.options.spiderfyShapePositions) {
			positions = this._group.options.spiderfyShapePositions(childMarkers.length, center);
		} else if (childMarkers.length >= this._circleSpiralSwitchover) {
			positions = this._generatePointsSpiral(childMarkers.length, center);
		} else {
			center.y += 10; // Otherwise circles look wrong => hack for standard blue icon, renders differently for other icons.
			positions = this._generatePointsCircle(childMarkers.length, center);
		}

		this._animationSpiderfy(childMarkers, positions);
	},

	unspiderfy: function (zoomDetails) {
		/// <param Name="zoomDetails">Argument from zoomanim if being called in a zoom animation or null otherwise</param>
		if (this._group._inZoomAnimation) {
			return;
		}
		this._animationUnspiderfy(zoomDetails);

		this._group._spiderfied = null;
	},

	_generatePointsCircle: function (count, centerPt) {
		var circumference = this._group.options.spiderfyDistanceMultiplier * this._circleFootSeparation * (2 + count),
			legLength = circumference / this._2PI,  //radius from circumference
			angleStep = this._2PI / count,
			res = [],
			i, angle;

		legLength = Math.max(legLength, 35); // Minimum distance to get outside the cluster icon.

		res.length = count;

		for (i = 0; i < count; i++) { // Clockwise, like spiral.
			angle = this._circleStartAngle + i * angleStep;
			res[i] = new Point(centerPt.x + legLength * Math.cos(angle), centerPt.y + legLength * Math.sin(angle))._round();
		}

		return res;
	},

	_generatePointsSpiral: function (count, centerPt) {
		var spiderfyDistanceMultiplier = this._group.options.spiderfyDistanceMultiplier,
			legLength = spiderfyDistanceMultiplier * this._spiralLengthStart,
			separation = spiderfyDistanceMultiplier * this._spiralFootSeparation,
			lengthFactor = spiderfyDistanceMultiplier * this._spiralLengthFactor * this._2PI,
			angle = 0,
			res = [],
			i;

		res.length = count;

		// Higher index, closer position to cluster center.
		for (i = count; i >= 0; i--) {
			// Skip the first position, so that we are already farther from center and we avoid
			// being under the default cluster icon (especially important for Circle Markers).
			if (i < count) {
				res[i] = new Point(centerPt.x + legLength * Math.cos(angle), centerPt.y + legLength * Math.sin(angle))._round();
			}
			angle += separation / legLength + i * 0.0005;
			legLength += lengthFactor / angle;
		}
		return res;
	},

	_noanimationUnspiderfy: function () {
		var group = this._group,
			map = group._map,
			fg = group._featureGroup,
			childMarkers = this.getAllChildMarkers(null, true),
			m, i;

		group._ignoreMove = true;

		this.setOpacity(1);
		for (i = childMarkers.length - 1; i >= 0; i--) {
			m = childMarkers[i];

			fg.removeLayer(m);

			if (m._preSpiderfyLatlng) {
				m.setLatLng(m._preSpiderfyLatlng);
				delete m._preSpiderfyLatlng;
			}
			if (m.setZIndexOffset) {
				m.setZIndexOffset(0);
			}

			if (m._spiderLeg) {
				map.removeLayer(m._spiderLeg);
				delete m._spiderLeg;
			}
		}

		group.fire('unspiderfied', {
			cluster: this,
			markers: childMarkers
		});
		group._ignoreMove = false;
		group._spiderfied = null;
	}
});

//Non Animated versions of everything
let MarkerClusterNonAnimated$1 = MarkerCluster$1.extend({
	_animationSpiderfy: function (childMarkers, positions) {
		var group = this._group,
			map = group._map,
			fg = group._featureGroup,
			legOptions = this._group.options.spiderLegPolylineOptions,
			i, m, leg, newPos;

		group._ignoreMove = true;

		// Traverse in ascending order to make sure that inner circleMarkers are on top of further legs. Normal markers are re-ordered by newPosition.
		// The reverse order trick no longer improves performance on modern browsers.
		for (i = 0; i < childMarkers.length; i++) {
			newPos = map.layerPointToLatLng(positions[i]);
			m = childMarkers[i];

			// Add the leg before the marker, so that in case the latter is a circleMarker, the leg is behind it.
			leg = new Polyline([this._latlng, newPos], legOptions);
			map.addLayer(leg);
			m._spiderLeg = leg;

			// Now add the marker.
			m._preSpiderfyLatlng = m._latlng;
			m.setLatLng(newPos);
			if (m.setZIndexOffset) {
				m.setZIndexOffset(1000000); //Make these appear on top of EVERYTHING
			}

			fg.addLayer(m);
		}
		this.setOpacity(0.3);

		group._ignoreMove = false;
		group.fire('spiderfied', {
			cluster: this,
			markers: childMarkers
		});
	},

	_animationUnspiderfy: function () {
		this._noanimationUnspiderfy();
	}
});

//Animated versions here
MarkerCluster$1.include({

	_animationSpiderfy: function (childMarkers, positions) {
		var me = this,
			group = this._group,
			map = group._map,
			fg = group._featureGroup,
			thisLayerLatLng = this._latlng,
			thisLayerPos = map.latLngToLayerPoint(thisLayerLatLng),
			svg = Path.SVG,
			legOptions = extend({}, this._group.options.spiderLegPolylineOptions), // Copy the options so that we can modify them for animation.
			finalLegOpacity = legOptions.opacity,
			i, m, leg, legPath, legLength, newPos;

		if (finalLegOpacity === undefined) {
			finalLegOpacity = MarkerClusterGroup.prototype.options.spiderLegPolylineOptions.opacity;
		}

		if (svg) {
			// If the initial opacity of the spider leg is not 0 then it appears before the animation starts.
			legOptions.opacity = 0;

			// Add the class for CSS transitions.
			legOptions.className = (legOptions.className || '') + ' leaflet-cluster-spider-leg';
		} else {
			// Make sure we have a defined opacity.
			legOptions.opacity = finalLegOpacity;
		}

		group._ignoreMove = true;

		// Add markers and spider legs to map, hidden at our center point.
		// Traverse in ascending order to make sure that inner circleMarkers are on top of further legs. Normal markers are re-ordered by newPosition.
		// The reverse order trick no longer improves performance on modern browsers.
		for (i = 0; i < childMarkers.length; i++) {
			m = childMarkers[i];

			newPos = map.layerPointToLatLng(positions[i]);

			// Add the leg before the marker, so that in case the latter is a circleMarker, the leg is behind it.
			leg = new Polyline([thisLayerLatLng, newPos], legOptions);
			map.addLayer(leg);
			m._spiderLeg = leg;

			// Explanations: https://jakearchibald.com/2013/animated-line-drawing-svg/
			// In our case the transition property is declared in the CSS file.
			if (svg) {
				legPath = leg._path;
				legLength = legPath.getTotalLength() + 0.1; // Need a small extra length to avoid remaining dot in Firefox.
				legPath.style.strokeDasharray = legLength; // Just 1 length is enough, it will be duplicated.
				legPath.style.strokeDashoffset = legLength;
			}

			// If it is a marker, add it now and we'll animate it out
			if (m.setZIndexOffset) {
				m.setZIndexOffset(1000000); // Make normal markers appear on top of EVERYTHING
			}
			if (m.clusterHide) {
				m.clusterHide();
			}

			// Vectors just get immediately added
			fg.addLayer(m);

			if (m._setPos) {
				m._setPos(thisLayerPos);
			}
		}

		group._forceLayout();
		group._animationStart();

		// Reveal markers and spider legs.
		for (i = childMarkers.length - 1; i >= 0; i--) {
			newPos = map.layerPointToLatLng(positions[i]);
			m = childMarkers[i];

			//Move marker to new position
			m._preSpiderfyLatlng = m._latlng;
			m.setLatLng(newPos);

			if (m.clusterShow) {
				m.clusterShow();
			}

			// Animate leg (animation is actually delegated to CSS transition).
			if (svg) {
				leg = m._spiderLeg;
				legPath = leg._path;
				legPath.style.strokeDashoffset = 0;
				//legPath.style.strokeOpacity = finalLegOpacity;
				leg.setStyle({opacity: finalLegOpacity});
			}
		}
		this.setOpacity(0.3);

		group._ignoreMove = false;

		setTimeout(function () {
			group._animationEnd();
			group.fire('spiderfied', {
				cluster: me,
				markers: childMarkers
			});
		}, 200);
	},

	_animationUnspiderfy: function (zoomDetails) {
		var me = this,
			group = this._group,
			map = group._map,
			fg = group._featureGroup,
			thisLayerPos = zoomDetails ? map._latLngToNewLayerPoint(this._latlng, zoomDetails.zoom, zoomDetails.center) : map.latLngToLayerPoint(this._latlng),
			childMarkers = this.getAllChildMarkers(null, true),
			svg = Path.SVG,
			m, i, leg, legPath, legLength, nonAnimatable;

		group._ignoreMove = true;
		group._animationStart();

		//Make us visible and bring the child markers back in
		this.setOpacity(1);
		for (i = childMarkers.length - 1; i >= 0; i--) {
			m = childMarkers[i];

			//Marker was added to us after we were spiderfied
			if (!m._preSpiderfyLatlng) {
				continue;
			}

			//Close any popup on the marker first, otherwise setting the location of the marker will make the map scroll
			m.closePopup();

			//Fix up the location to the real one
			m.setLatLng(m._preSpiderfyLatlng);
			delete m._preSpiderfyLatlng;

			//Hack override the location to be our center
			nonAnimatable = true;
			if (m._setPos) {
				m._setPos(thisLayerPos);
				nonAnimatable = false;
			}
			if (m.clusterHide) {
				m.clusterHide();
				nonAnimatable = false;
			}
			if (nonAnimatable) {
				fg.removeLayer(m);
			}

			// Animate the spider leg back in (animation is actually delegated to CSS transition).
			if (svg) {
				leg = m._spiderLeg;
				legPath = leg._path;
				legLength = legPath.getTotalLength() + 0.1;
				legPath.style.strokeDashoffset = legLength;
				leg.setStyle({opacity: 0});
			}
		}

		group._ignoreMove = false;

		setTimeout(function () {
			//If we have only <= one child left then that marker will be shown on the map so don't remove it!
			var stillThereChildCount = 0;
			for (i = childMarkers.length - 1; i >= 0; i--) {
				m = childMarkers[i];
				if (m._spiderLeg) {
					stillThereChildCount++;
				}
			}


			for (i = childMarkers.length - 1; i >= 0; i--) {
				m = childMarkers[i];

				if (!m._spiderLeg) { //Has already been unspiderfied
					continue;
				}

				if (m.clusterShow) {
					m.clusterShow();
				}
				if (m.setZIndexOffset) {
					m.setZIndexOffset(0);
				}

				if (stillThereChildCount > 1) {
					fg.removeLayer(m);
				}

				map.removeLayer(m._spiderLeg);
				delete m._spiderLeg;
			}
			group._animationEnd();
			group.fire('unspiderfied', {
				cluster: me,
				markers: childMarkers
			});
		}, 200);
	}
});


MarkerClusterGroup.include({
	//The MarkerCluster currently spiderfied (if any)
	_spiderfied: null,

	unspiderfy: function () {
		this._unspiderfy.apply(this, arguments);
	},

	_spiderfierOnAdd: function () {
		this._map.on('click', this._unspiderfyWrapper, this);

		if (this._map.options.zoomAnimation) {
			this._map.on('zoomstart', this._unspiderfyZoomStart, this);
		}
		//Browsers without zoomAnimation or a big zoom don't fire zoomstart
		this._map.on('zoomend', this._noanimationUnspiderfy, this);

		if (!touch) {
			this._map.getRenderer(this);
			//Needs to happen in the pageload, not after, or animations don't work in webkit
			//  http://stackoverflow.com/questions/8455200/svg-animate-with-dynamically-added-elements
			//Disable on touch browsers as the animation messes up on a touch zoom and isn't very noticable
		}
	},

	_spiderfierOnRemove: function () {
		this._map.off('click', this._unspiderfyWrapper, this);
		this._map.off('zoomstart', this._unspiderfyZoomStart, this);
		this._map.off('zoomanim', this._unspiderfyZoomAnim, this);
		this._map.off('zoomend', this._noanimationUnspiderfy, this);

		//Ensure that markers are back where they should be
		// Use no animation to avoid a sticky leaflet-cluster-anim class on mapPane
		this._noanimationUnspiderfy();
	},

	//On zoom start we add a zoomanim handler so that we are guaranteed to be last (after markers are animated)
	//This means we can define the animation they do rather than Markers doing an animation to their actual location
	_unspiderfyZoomStart: function () {
		if (!this._map) { //May have been removed from the map by a zoomEnd handler
			return;
		}

		this._map.on('zoomanim', this._unspiderfyZoomAnim, this);
	},

	_unspiderfyZoomAnim: function (zoomDetails) {
		//Wait until the first zoomanim after the user has finished touch-zooming before running the animation
		if (hasClass(this._map._mapPane, 'leaflet-touching')) {
			return;
		}

		this._map.off('zoomanim', this._unspiderfyZoomAnim, this);
		this._unspiderfy(zoomDetails);
	},

	_unspiderfyWrapper: function () {
		/// <summary>_unspiderfy but passes no arguments</summary>
		this._unspiderfy();
	},

	_unspiderfy: function (zoomDetails) {
		if (this._spiderfied) {
			this._spiderfied.unspiderfy(zoomDetails);
		}
	},

	_noanimationUnspiderfy: function () {
		if (this._spiderfied) {
			this._spiderfied._noanimationUnspiderfy();
		}
	},

	//If the given layer is currently being spiderfied then we unspiderfy it so it isn't on the map anymore etc
	_unspiderfyLayer: function (layer) {
		if (layer._spiderLeg) {
			this._featureGroup.removeLayer(layer);

			if (layer.clusterShow) {
				layer.clusterShow();
			}
				//Position will be fixed up immediately in _animationUnspiderfy
			if (layer.setZIndexOffset) {
				layer.setZIndexOffset(0);
			}

			this._map.removeLayer(layer._spiderLeg);
			delete layer._spiderLeg;
		}
	}
});

/**
 * Adds 1 public method to MCG and 1 to Marker to facilitate changing
 * markers' icon options and refreshing their icon and their parent clusters
 * accordingly (case where their iconCreateFunction uses data of childMarkers
 * to make up the cluster icon).
 */

MarkerClusterGroup.include({
	/**
	 * Updates the icon of all clusters which are parents of the given marker(s).
	 * In singleMarkerMode, also updates the given marker(s) icon.
	 * @param layers MarkerClusterGroup|LayerGroup|Array(Marker)|Map(Marker)|
	 * MarkerCluster|Marker (optional) list of markers (or single marker) whose parent
	 * clusters need to be updated. If not provided, retrieves all child markers of this.
	 * @returns {MarkerClusterGroup}
	 */
	refreshClusters: function (layers) {
		if (!layers) {
			layers = this._topClusterLevel.getAllChildMarkers();
		} else if (layers instanceof MarkerClusterGroup) {
			layers = layers._topClusterLevel.getAllChildMarkers();
		} else if (layers instanceof LayerGroup) {
			layers = layers._layers;
		} else if (layers instanceof MarkerCluster) {
			layers = layers.getAllChildMarkers();
		} else if (layers instanceof Marker) {
			layers = [layers];
		} // else: must be an Array(Marker)|Map(Marker)
		this._flagParentsIconsNeedUpdate(layers);
		this._refreshClustersIcons();

		// In case of singleMarkerMode, also re-draw the markers.
		if (this.options.singleMarkerMode) {
			this._refreshSingleMarkerModeMarkers(layers);
		}

		return this;
	},

	/**
	 * Simply flags all parent clusters of the given markers as having a "dirty" icon.
	 * @param layers Array(Marker)|Map(Marker) list of markers.
	 * @private
	 */
	_flagParentsIconsNeedUpdate: function (layers) {
		var id, parent;

		// Assumes layers is an Array or an Object whose prototype is non-enumerable.
		for (id in layers) {
			// Flag parent clusters' icon as "dirty", all the way up.
			// Dumb process that flags multiple times upper parents, but still
			// much more efficient than trying to be smart and make short lists,
			// at least in the case of a hierarchy following a power law:
			// http://jsperf.com/flag-nodes-in-power-hierarchy/2
			parent = layers[id].__parent;
			while (parent) {
				parent._iconNeedsUpdate = true;
				parent = parent.__parent;
			}
		}
	},

	/**
	 * Re-draws the icon of the supplied markers.
	 * To be used in singleMarkerMode only.
	 * @param layers Array(Marker)|Map(Marker) list of markers.
	 * @private
	 */
	_refreshSingleMarkerModeMarkers: function (layers) {
		var id, layer;

		for (id in layers) {
			layer = layers[id];

			// Make sure we do not override markers that do not belong to THIS group.
			if (this.hasLayer(layer)) {
				// Need to re-create the icon first, then re-draw the marker.
				layer.setIcon(this._overrideMarkerIcon(layer));
			}
		}
	}
});

Marker.include({
	/**
	 * Updates the given options in the marker's icon and refreshes the marker.
	 * @param options map object of icon options.
	 * @param directlyRefreshClusters boolean (optional) true to trigger
	 * MCG.refreshClustersOf() right away with this single marker.
	 * @returns {Marker}
	 */
	refreshIconOptions: function (options, directlyRefreshClusters) {
		var icon = this.options.icon;

		setOptions(icon, options);

		this.setIcon(icon);

		// Shortcut to refresh the associated MCG clusters right away.
		// To be used when refreshing a single marker.
		// Otherwise, better use MCG.refreshClusters() once at the end with
		// the list of modified markers.
		if (directlyRefreshClusters && this.__parent) {
			this.__parent._group.refreshClusters(this);
		}

		return this;
	}
});

// Extend the LitElement base class
class OchaAssessmentsMap extends OchaAssessmentsBase {
  static get styles() {
    return [
      super.styles,
      css`
        :host {
          display: block;
          border: 1px solid transparent;
        }`
    ]
  }

  render() {
    return html`
      <link rel="stylesheet" href="${this.componenturl}leaflet.css" />
      <link rel="stylesheet" href="${this.componenturl}MarkerCluster.Default.css" />

      <style>
        #map {
          width: 100%;
          height: 100%;
          z-index: 0;
          @apply (--leaflet-map-component)
        }
      </style>

      ${this.renderErrorMessage()}

      ${this.renderDropdowns()}

      <div id="loading-message">Loading...</div>
      <div id="map" style="display:none;">
        <slot></slot>
      </div>
    `;
  }

  addMarkers() {

    if (!this.cluster) {
      this.cluster = new MarkerClusterGroup();
    }
    else  {
      this.cluster.clearLayers();
    }

    if (this.data.length == 0) {
      return;
    }

    this.data.forEach(row => {
      if (typeof row.field_locations_lat_lon != 'undefined' && row.field_locations_lat_lon.length > 0) {
        const latlon = row.field_locations_lat_lon[0].split(',');
        // Skip empty markers.
        if (latlon[0] != '' && latlon[1] != '') {
          const m = new Marker([latlon[0], latlon[1]]);
          m.bindPopup('<a href="' + this.baseurl + '/assessment/' + row.uuid + '">' + row.title + '</a>');
          this.cluster.addLayer(m);
        }
      }
    });

    this.shadowRoot.getElementById('loading-message').style.display = 'none';
    this.shadowRoot.getElementById('map').style.display = 'block';
    this.map.invalidateSize();

    this.map.addLayer(this.cluster);
    if (this.cluster.getLayers().length > 0) {
      this.map.fitBounds(this.cluster.getBounds(), {
        maxZoom: this.maxZoom || 15
      });
    }
  }

  connectedCallback() {
    this.fetchCb = this.addMarkers;
    super.connectedCallback();
  }

  firstUpdated(changedProperties) {
    if (!this.map) {
      Icon.Default.imagePath = this.componenturl;

      this.map = new Map$1(this.shadowRoot.getElementById('map'), {
        center: [this.latitude, this.longitude],
        zoom: this.zoom,
        zoomControl: this.zoomControl,
        inertiaDeceleration: 3000,
        inertiaMaxSpeed: 3000,
        attributionControl: true,
        minZoom: this.minZoom || 2,
        maxZoom: this.maxZoom || 15,
        tapTolerance: 40,
        tap: false
      });

      this.map.setView([this.latitude, this.longitude], this.zoom);

      const l = new TileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
        maxZoom: 17,
        attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
      });
      l.addTo(this.map);
    }
  }

  static get properties() {
    return {
      baseurl: {
        type: String
      },
      src: {
        type: String
      },
      componenturl: {
        type: String
      },
      basicAuth: {
        type: String
      },
      errorMessage: {
        type: String
      },
      data: {
        type: Array
      },
      map: {
        type: Object
      },
      latitude: {
        type: Number
      },
      longitude: {
        type: Number
      },
      zoom: {
        type: Number
      },
      minZoom: {
        type: Number
      },
      maxZoom: {
        type: Number
      },
      zoomControl: {
        type: Boolean,
        value: false
      },
    };
  }

}

customElements.define('ocha-assessments-map', OchaAssessmentsMap);

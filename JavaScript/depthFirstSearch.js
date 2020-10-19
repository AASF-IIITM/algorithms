function initCallbacks(callbacks = {}) {
  const initiatedCallbacks = {};

  const stubCallback = () => {};
  const defaultAllowTraversalCallback = () => true;

  initiatedCallbacks.allowTraversal = callbacks.allowTraversal || defaultAllowTraversalCallback;
  initiatedCallbacks.enterNode = callbacks.enterNode || stubCallback;
  initiatedCallbacks.leaveNode = callbacks.leaveNode || stubCallback;

  return initiatedCallbacks;
}

export function depthFirstSearchRecursive(node, callbacks) {
  callbacks.enterNode(node);

  if (node.left && callbacks.allowTraversal(node, node.left)) {
    depthFirstSearchRecursive(node.left, callbacks);
  }

  if (node.right && callbacks.allowTraversal(node, node.right)) {
    depthFirstSearchRecursive(node.right, callbacks);
  }

  callbacks.leaveNode(node);
}
export default function depthFirstSearch(rootNode, callbacks) {
  
  const processedCallbacks = initCallbacks(callbacks);
  
  depthFirstSearchRecursive(rootNode, processedCallbacks);
}

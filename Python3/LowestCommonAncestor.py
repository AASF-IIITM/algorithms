# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def search(node, p, q):
            if(not node):   return None
            
            if(node == p):  return p
            elif(node == q):    return q
            
            leftNode = search(node.left, p, q)
            rightNode = search(node.right, p, q)
            
            if(leftNode and rightNode): return node
            else:   return leftNode or rightNode
        return search(root, p, q)

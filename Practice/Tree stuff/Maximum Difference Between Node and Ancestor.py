# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root, mn=100000, mx=0):
        return max(self.maxAncestorDiff(root.left, min(mn, root.val), max(mx, root.val)),
                   self.maxAncestorDiff(root.right, min(mn, root.val), max(mx, root.val))) \
            if root else mx - mn
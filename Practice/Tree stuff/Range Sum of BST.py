def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
    if not root:
        return 0
    elif root.val < L:
        return self.rangeSumBST(root.right, L, R)
    elif root.val > R:
        return self.rangeSumBST(root.left, L, R)
    return root.val + self.rangeSumBST(root.left, L, R) + self.rangeSumBST(root.right, L, R)
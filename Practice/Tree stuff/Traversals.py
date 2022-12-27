def preorder(root):
    return [root.val] + preorder(root.left) + preorder(root.right) if root else []


def inorder(root):
    return inorder(root.left) + [root.val] + inorder(root.right) if root else []


def postorder(root):
    return postorder(root.left) + postorder(root.right) + [root.val] if root else []


"""
DFS traversals always start at the root node and then go to the most left to right

Preorder:
- Node is printed when it is touched for the first time
Inorder:
- Node is printed when it is touched for the second time
Postorder:
- Node is printed when it is touched the last time 


BFS traversal is just traversing through the tree by going layer by layer, left to right in each layer
"""
from collections import deque


class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


class BinaryTree(Node):
    def __init__(self, root: Node):
        self.root = root

    def __str__(self):
        print("BFS:", self.bfs_traversal(self.root))
        print()
        print("Inorder:", self.inorder_print(self.root)[1:])
        print("Preorder:", self.preorder_print(self.root)[:-1])
        print("Postorder:", self.postorder_print(self.root)[1:])
        return "Done!"

    def search(self, find_val):
        return self.preorder_search(self.root, find_val)

    def get_root(self):
        return self.root.value

    def preorder_search(self, start, find_val):
        if start:
            if start.value == find_val:
                return True
            else:
                return self.preorder_search(start.left, find_val) or self.preorder_search(start.right, find_val)
        return False

    def preorder_print(self, start, traversal=""):
        if start:
            traversal = str(start.value) + "-" \
                        + self.preorder_print(start.left, traversal) \
                        + self.preorder_print(start.right, traversal)
        return traversal

    def postorder_print(self, start, traversal=""):
        if start:
            traversal = self.postorder_print(start.left, traversal)\
                        + self.postorder_print(start.right, traversal) + "-"  \
                        + str(start.value)
        return traversal

    def inorder_print(self, start, traversal=""):
        if start:
            traversal = self.inorder_print(start.left, traversal) + "-" \
                        + str(start.value) \
                        + self.inorder_print(start.right, traversal)
        return traversal

    def bfs_traversal(self, start: Node):
        if not start: return []
        queue, result = deque([start]), []

        while queue:
            level = []
            for i in range(len(queue)):
                node = queue.popleft()
                level.append(node.value)
                if node.left:  queue.append(node.left)
                if node.right: queue.append(node.right)
            result.append(level)
        return result

if __name__ == "__main__":
    tree = BinaryTree(Node(1))
    tree.root.left = Node(2)
    tree.root.left.left = Node(3)
    tree.root.left.right = Node(4)
    tree.root.right = Node(5)
    tree.root.right.left = Node(6)
    tree.root.right.right = Node(7)
    print(tree)

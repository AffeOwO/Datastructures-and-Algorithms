# ToDo: better
class Node:
    def __init__(self, value, children=None, parent=None):
        if children is None:
            children = []
        self.value = value
        self.children = children
        self.parent = parent


class Tree(Node):
    def __init__(self, root):
        self.root = Node(root)

    def add_child(self, child):
        child.parent = self
        self.children.append(child)


if __name__ == "__main__":
    tree = Tree("test")
    print( tree.children)
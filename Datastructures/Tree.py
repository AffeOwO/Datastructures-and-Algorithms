class Node:
    def __init__(self, value, children=None):
        if children is None:
            children = []
        self.value = value
        self.children = children


class Tree(Node):
    def __init__(self, root):
        self.root = Node(root)

    def add_child(self, child):
        pass

    # ToDo: implement everythin


if __name__ == "__main__":
    tree = Tree("test")
    print(tree.children)
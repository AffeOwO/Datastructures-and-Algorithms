class Node:
    def __init__(self, value, children=[]):
        self.value = value
        self.children = children


class Tree(Node):
    def __init__(self, root):
        self.root = Node(root)


if __name__ == "__main__":
    tree = Tree("test")
    tree.root.children = [Node("test2"), Node("test3")]
    tree.root.children[0].children = [Node("test4")]
    print(tree.root.value)
    print(tree.root.children[0].value)
    print(tree.root.children[1].value)
    print(tree.root.children[0].children[0].value)
class Node:
    def __init__(self, data=None, prev=None, next=None):
        self.data = data
        self.prev = prev
        self.next = next


class LinkedList(Node):
    def __init__(self):
        self.head = None
        self.length = 0


    def __len__(self):
        return self.length
# ToDo: implement stuff


if __name__ == "__main__":
    pass
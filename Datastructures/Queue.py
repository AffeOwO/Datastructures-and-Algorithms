class Queue:
    def __init__(self, head=None):
        self.head = [head]

    def push(self, new_element):
        self.head.append(new_element)

    def pop(self):
        self.head.pop(0)

    def peek(self):
        return self.head[0]
class Stack:
    def __init__(self):
        self.head = []

    def push(self, new_element):
        self.head.append(new_element)

    def pop(self):
        if not self.head:
            raise "IndexError"
        self.head.pop()

    def peek(self):
        if not self.head:
            raise "IndexError"
        return self.head[-1]

    def is_empty(self):
        if not self.head:
            return True
        return False


if __name__ == "__main__":
    test = Stack()
    test.peek()
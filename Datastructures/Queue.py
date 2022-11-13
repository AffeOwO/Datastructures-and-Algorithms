class Queue:
    def __init__(self):
        self.head = []

    def enqueue(self, new_element):
        self.head.append(new_element)

    def dequeue(self):
        if not self.head:
            raise "IndexError"
        self.head.pop(0)

    def peek(self):
        if not self.head:
            raise "IndexError"
        return self.head[0]


if __name__ == "__main__":
    test = Queue()
    test.peek()
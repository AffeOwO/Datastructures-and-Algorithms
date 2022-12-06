class Heap:
    def __init__(self, values: list=[]):
        self.values = values

    def __str__(self):
        return " ".join([str(i) for i in self.values])

    def __len__(self):
        return len(self.values)

    def heapify(self):
        self.values.sort()

    def add_value(self, value):
        self.values.append(value)
        self.heapify()

    def add_values(self, values: list):
        for item in values:
            self.values.append(item)
        self.heapify()

    def remove_value(self, value):
        for _ in range(self.values.count(value)):
            self.values.remove(value)

    def is_in_heap(self, value):
        return value in self.values


if __name__ == "__main__":
    heap = Heap(["a", "b", 1])
    print(heap)
    print(len(heap))
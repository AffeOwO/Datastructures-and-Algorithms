class Heap:
    def __init__(self, values: list=[]):
        self.values = values

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
    pass
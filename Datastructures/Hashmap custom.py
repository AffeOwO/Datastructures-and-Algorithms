class MyHashMap:

    def __init__(self):
        self.hash = {}

    def put(self, key: int, value: int) -> None:
        self.hash[key] = value

    def get(self, key: int) -> int:
        if key in self.hash.keys():
            return self.hash[key]
        return -1

    def remove(self, key: int) -> None:
        if key in self.hash.keys():
            self.hash.pop(key)
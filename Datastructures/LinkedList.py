class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


class LinkedList(Node):
    def __init__(self, values: list = None):
        self.head = None
        self.length = 0
        if values:
            self.insert_values_at_start(values)

    def __len__(self):
        return self.length

    def __str__(self):
        if not self.head:
            return "Linked List is empty"
        itr = self.head
        linked_list_str = ""
        while itr:
            linked_list_str += str(itr.data) + "-->"
            itr = itr.next
        linked_list_str = linked_list_str[:-3]
        return linked_list_str

    def insert_at(self, index, data):
        if index < -1 * len(self) or index > len(self):
            raise Exception("Invalid Index")
        elif index == len(self):
            self.insert_at_end(data)
            return
        elif index == 0:
            self.insert_at_start(data)
            return

        self.length += 1
        count = 0
        itr = self.head
        while itr:
            if count == index - 1 or count == len(self) + index - 1:
                node = Node(data, itr.next)
                itr.next = node
                break
            count += 1
            itr = itr.next

    def insert_at_start(self, data):
        node = Node(data, self.head)
        self.head = node
        self.length += 1

    def insert_at_end(self, data):
        if not self.head:
            self.head = Node(data)
            self.length += 1
            return

        itr = self.head
        while itr.next:
            itr = itr.next
        itr.next = Node(data)
        self.length += 1

    def insert_values_at_start(self, data_list: list):
        for data in data_list[::-1]:
            self.insert_at_start(data)

    def insert_values_at_end(self, data_list: list):
        for data in data_list:
            self.insert_at_end(data)

    def remove_element(self, index):
        if index < -1 * len(self) or index >= len(self):
            raise Exception("Invalid Index")
        elif index == 0:
            self.head = self.head.next
            self.length -= 1
            return

        self.length -= 1
        count = 0
        itr = self.head
        while itr:
            if count == index - 1 or count == len(self) + index - 1:
                itr.next = itr.next.next
                break
            count += 1
            itr = itr.next


if __name__ == "__main__":
    ll = LinkedList(["teddy", "yas"])
    print(ll)
    print(len(ll))

    ll.insert_at(1, "discord")

    print(ll)
    print(len(ll))
class Solution:
    def middle_node(self, head):
        fast = slow = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.net
        return slow
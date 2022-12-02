# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# mine
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        temp = []
        while head:
            temp.append(head.val)
            head = head.next
        index_convert = len(temp) - n
        idk = sol = ListNode()
        for index, i in enumerate(temp):
            if index == index_convert:
                continue
            sol.next = ListNode(i)
            sol = sol.next

        return idk.next


# optimal
class Solution:
    def removeNthFromEnd(self, head, n):
        fast = slow = head
        for _ in range(n):
            fast = fast.next
        if not fast:
            return head.next
        while fast.next:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return head

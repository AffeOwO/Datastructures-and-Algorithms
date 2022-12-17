# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        sol = rev_head = ListNode()
        temp = []
        while head:
            temp.append(head.val)
            head = head.next
        for i in temp[::-1]:
            sol.next = ListNode(i)
            sol = sol.next
        return rev_head.next

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        sol = ListNode(head.val)
        head = head.next
        while head:
            temp = ListNode(head.val, sol)
            sol = temp
            head = head.next
        return sol
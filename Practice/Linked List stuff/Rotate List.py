# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return head
        ll_arr = []
        while head:
            ll_arr.append(head.val)
            head = head.next
        for i in range(k % len(ll_arr)):
            temp = ll_arr.pop()
            ll_arr.insert(0, temp)
        sol = idk = ListNode(ll_arr[0])
        for i in ll_arr[1:]:
            sol.next = ListNode(i)
            sol = sol.next

        return idk
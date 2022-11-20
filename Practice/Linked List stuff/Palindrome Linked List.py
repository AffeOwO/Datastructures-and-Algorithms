# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        temp = []
        temp2 = head
        while temp2:
            temp.append(temp2.val)
            temp2 = temp2.next
        for i in temp[::-1]:
            if head.val != i:
                return False
            head = head.next
        return True
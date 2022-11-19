# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        bin_num = ""
        temp = head
        while temp:
            bin_num += str(temp.val)
            temp = temp.next
        return int(bin_num, 2)
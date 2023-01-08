class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        negs, pos = 0, 0
        for i in nums:
            if i < 0:
                negs += 1
            elif i > 0:
                pos += 1

        return max((negs, pos))
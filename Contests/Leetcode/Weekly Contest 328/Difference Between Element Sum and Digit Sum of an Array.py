class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        digits = 0
        arrsum = sum(nums)
        for i in nums:
            for j in str(i): digits += int(j)
        return abs(digits-arrsum)
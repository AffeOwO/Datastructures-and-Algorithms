class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        temp = sorted(set(nums))
        return nums.index(temp[-1]) if temp[-1] >= temp[-2]*2 else -1
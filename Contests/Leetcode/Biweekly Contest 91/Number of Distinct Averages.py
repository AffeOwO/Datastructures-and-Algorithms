# accepted
class Solution:
    def distinctAverages(self, nums: list[int]) -> int:
        avgList = []
        while nums:
            minNum = min(nums)
            maxNum = max(nums)
            avg = (minNum + maxNum) / 2
            avgList.append(avg)
            nums.remove(minNum)
            nums.remove(maxNum)
        return len(set(avgList))

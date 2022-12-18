class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        temp = 0
        for index, i in enumerate(nums[::-1]):
            if i == val:
                nums.pop((index + 1 - temp) * -1)
                temp += 1
        return len(nums)


# better solution:
class Solution2:
    def removeElement2(self, nums, val):
        i = 0
        for x in nums:
            if x != val:
                nums[i] = x
                i += 1
        return i

class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        sol = []
        for i in nums:
            i = str(i)
            for j in i:
                sol.append(int(j))
        return sol
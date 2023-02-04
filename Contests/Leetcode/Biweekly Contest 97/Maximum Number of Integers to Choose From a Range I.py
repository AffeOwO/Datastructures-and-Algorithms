class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        chosen = set()
        banned = set(banned)
        sol = 0
        for i in range(1, n+1):
            if i in banned: continue
            chosen.add(i)
            if sum(chosen) > maxSum: break
            sol += 1
        return sol
class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        sol = 0

        for i in strs:
            if i.isnumeric():
                if int(i) > sol:
                    sol = int(i)
            else:
                if len(i) > sol:
                    sol = len(i)

        return sol
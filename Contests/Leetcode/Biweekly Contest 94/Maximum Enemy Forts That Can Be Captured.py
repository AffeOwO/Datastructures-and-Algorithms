class Solution:
    def captureForts(self, forts: List[int]) -> int:
        sol = 0
        for index, i in enumerate(forts):
            if i == 1:
                temp = index
                temp2 = 0
                while forts[temp] != -1:
                    if temp == 0:
                        temp2 = 0
                        break
                    temp -= 1
                    if forts[temp] == 0:
                        temp2 += 1
                    elif forts[temp] == 1:
                        temp2 = 0
                        break
                if temp2 > sol: sol = temp2
                temp = index
                temp2 = 0
                while forts[temp] != -1:
                    if temp == len(forts) - 1:
                        temp2 = 0
                        break
                    temp += 1
                    if forts[temp] == 0:
                        temp2 += 1
                    elif forts[temp] == 1:
                        temp2 = 0
                        break
                if temp2 > sol: sol = temp2

        return sol
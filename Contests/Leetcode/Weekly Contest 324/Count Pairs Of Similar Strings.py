class Solution:
    def similarPairs(self, words: List[str]) -> int:
        words = list(map(set, words))
        sol = 0
        temp = []
        for index, i in enumerate(words):
            for index2, i2 in enumerate(words):
                if index == index2:
                    continue
                if f"{index}|{index2}" in temp:
                    continue
                elif i == i2:
                    sol += 1
                    temp.append(f"{index2}|{index}")
        return sol
class Solution:
    def beautifulPartitions(self, s: str, k: int, minLength: int) -> int:
        # s=string k=needed_strings minLen=minlen
        prime_digs = (2, 3, 5, 7)
        dif_parts = 0
        temp = dict.fromkeys(([i for i in range(1, k+1)]), 0)
        for i in range(int(len(s)/minLength+1)):
            temp2 = 0
            for o in range(1,k+1):
                temp[o] = s[temp2:temp2+minLength]
                if o == k:
                    temp[o] = s[temp2:]
                temp2 += minLength

        print(temp)

        return dif_parts
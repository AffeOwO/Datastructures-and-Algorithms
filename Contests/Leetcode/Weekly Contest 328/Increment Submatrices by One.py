class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        from collections import defaultdict
        prefix = {n: defaultdict(int) for n in range(n)}
        for query in queries:
            for i in range(query[0], query[2]+1):
                prefix[i][query[1]] += 1
                prefix[i][query[3]+1] -= 1
        mat = []
        idk = 0
        for i in prefix.values():
            cur = 0
            mat.append([])
            for j in range(n):
                cur += i[j]
                mat[idk].append(cur)
            idk += 1
        return mat
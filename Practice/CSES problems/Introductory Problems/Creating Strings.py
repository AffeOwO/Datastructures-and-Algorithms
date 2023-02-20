from math import factorial
from collections import Counter
from itertools import permutations

s = input()
n = len(s)
s_cnt = Counter(s)

perms = factorial(n)
for i in s_cnt:
    perms //= factorial(s_cnt[i])

print(perms)
perms = permutations(s)
perms = set(perms)
for i in sorted(perms):
    print("".join(i))
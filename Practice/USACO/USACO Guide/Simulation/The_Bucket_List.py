from collections import defaultdict

fin = open("blist.in").read().splitlines()
fout = open("blist.out", "w")

n = int(fin[0])
hashy = defaultdict(int)
for i in range(n):
    s, t, b = map(int, fin[i+1].split())
    hashy[s] += b
    hashy[t] -= b

temp = 0
needed = 0
for i in sorted(hashy.keys()):
    temp += hashy[i]
    if temp > needed: needed = temp

fout.write(f"{needed}\n")
fout.close()
n, q = map(int, input().split())
s = input()
pref = [0]
cur = 0
for index, i in enumerate(s):
    cur += (ord(i)-96)
    pref.append(cur)

for _ in range(q):
    l, r = map(int, input().split())
    print(pref[r]-pref[l-1])
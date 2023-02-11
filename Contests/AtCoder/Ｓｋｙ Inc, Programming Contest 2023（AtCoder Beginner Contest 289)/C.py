def powerset(s):
    x = len(s)
    idk2 = []
    for i in range(1 << x):
         idk2.append([s[j] for j in range(x) if (i & (1 << j))])
    return idk2

n, m = map(int, input().split())

idk = []
sets = []
for _ in range(m):
    temp = int(input())
    idk.append(temp)
    sety = list(map(int, input().split()))
    sets.append(sety)

sets = powerset(sets)
sol = 0
for i in sets:
    temp = set()
    for j in i:
        temp = temp | set(j)
    if len(temp) == n: sol += 1
print(sol)
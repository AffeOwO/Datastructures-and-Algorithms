n, m = map(int, input().split())
postals = []
new = set()
for i in range(n):
    temp = input()
    postals.append(temp[3:])
for j in range(m):
    temp = input()
    new.add(temp)

sol = 0
for i in postals:
    if i in new: sol += 1
print(sol)
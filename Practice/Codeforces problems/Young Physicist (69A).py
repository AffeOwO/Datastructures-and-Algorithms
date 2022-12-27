forces = int(input())

cur = [0, 0, 0]  # x=0. y=1, z=2  -> index
for _ in range(forces):
    x, y, z = map(int, input().split())
    cur[0], cur[1], cur[2] = cur[0] + x, cur[1] + y, cur[2] + z

if len(set(cur)) == 1 and sum(cur) == 0:
    print("YES")
else:
    print("NO")

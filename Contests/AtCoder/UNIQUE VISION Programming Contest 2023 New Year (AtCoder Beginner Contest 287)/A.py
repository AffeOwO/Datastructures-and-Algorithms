n = int(input())
f, d = 0, 0

for _ in range(n):
    temp = input()
    if temp == "For": f += 1
    else: d+= 1
if f > d: print("Yes")
else: print("No")
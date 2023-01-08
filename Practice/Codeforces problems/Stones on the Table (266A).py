n = int(input())
s = input()

sol = 0
bef = -1
for i in s:
    if i == bef: sol+=1
    bef = i
print(sol)
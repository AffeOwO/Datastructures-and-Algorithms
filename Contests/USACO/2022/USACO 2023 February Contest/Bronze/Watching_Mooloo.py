n, k = map(int, input().split())
days = sorted(map(int, input().split()))

sol = 0
cur = 1+k
for index, i in enumerate(days):
    if index == n-1: 
        sol += cur
        break
    temp = days[index+1]-i
    if temp <= k:
        cur += temp
    else:
        sol += cur
        cur = 1+k

print(sol)
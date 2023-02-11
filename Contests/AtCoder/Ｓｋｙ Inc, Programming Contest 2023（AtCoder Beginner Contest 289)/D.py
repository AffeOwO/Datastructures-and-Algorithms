n1 = int(input())
climb = list(map(int, input().split()))
m1 = int(input())
traps = set(map(int, input().split()))
x = int(input())

def combination(c, t):
    dp = [[] for _ in range(t+1)]
    for c in c:
        for i in range(c, t+1):
            if i == c: dp[i].append([c])
            for comb in dp[i-c]: dp[i].append(comb + [c])
    return dp[-1]

combs = combination(climb, x)
sol = False
for i in combs:
    temp = 0
    idk = True
    for j in i:
        temp += j
        if temp in traps:
            idk = False
            break
    if idk:
        sol = True
        break
if sol:
    print("Yes")
else:
    print("No")
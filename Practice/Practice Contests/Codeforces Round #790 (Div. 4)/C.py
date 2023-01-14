def cost(a, b):
    val = 0
    for index in range(len(a)):
        val += abs(ord(a[index])-ord(b[index]))
    return val

for _ in range(int(input())):
    n, m = map(int, input().split())
    strings = []
    for _ in range(n):
        strings.append(input())
    sol = float("inf")
    for i in range(n):
        for j in range(n):
            if i == j: continue
            sol = min((sol, cost(strings[i], strings[j])))


    print(sol)
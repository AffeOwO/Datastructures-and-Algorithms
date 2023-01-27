for _ in range(int(input())):
    n = int(input())
    perms = [[] for _ in range(n-1)]
    for _ in range(n):
        temp = list(map(int, input().split()))
        for index, j in enumerate(temp):
            perms[index].append(j)

    sol = []
    prev = -1
    used = set()
    for i in perms:
        temp = max(i, key=i.count)
        if prev == -1 and i.count(temp) > n//2 and temp not in used:
            sol.append(temp)
            used.add(temp)
            for j in i:
                if j != temp:
                    prev = j
                    break
        else:
            sol.append(prev)
            used.add(prev)
            bef = prev
            for j in i:
                if j != bef and j not in used:
                    prev = j
                    break
    sol.append(max(perms[-1], key=perms[-1].count))

    print(*sol)

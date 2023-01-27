for _ in range(int(input())):
    n = int(input())
    sizes = sorted(map(int, input().split()))
    sol = 0
    hashy = {}
    for i in sizes:
        if i not in hashy: hashy[i] = 0
        hashy[i] += 1
    while hashy:
        temp = set()
        for i in hashy:
            hashy[i] -= 1
            if hashy[i] == 0:
                temp.add(i)
            if i+1 not in hashy:
                sol += 1
                break
        for i in temp:
            del hashy[i]
    print(sol)
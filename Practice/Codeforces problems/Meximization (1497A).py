for _ in range(int(input())):
    n = int(input())
    arr = sorted(map(int, input().split()))
    prev = -1
    temp = []
    sol = []
    for index, i in enumerate(arr):
        if i > prev:
            sol.append(i)
        else:
            temp.append(i)
        prev = i
    sol += temp
    print(*sol)
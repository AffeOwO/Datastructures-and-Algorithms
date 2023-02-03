for _ in range(int(input())):
    n, c = map(int, input().split())
    arr = list(map(int, input().split()))

    bruh = sorted([i+index+1 for index, i in enumerate(arr)])

    sol = 0
    temp = 0
    for i in bruh:
        temp += i
        if temp > c: break
        sol += 1
    print(sol)
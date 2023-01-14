for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    low = min(arr)
    sol = 0

    for i in arr:
        sol += (i-low)

    print(sol)
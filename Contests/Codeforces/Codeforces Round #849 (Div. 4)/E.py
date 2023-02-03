for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    sol = 0
    for i in arr: sol += abs(i)

    cnt = 0
    for i in arr:
        if i < 0:
            cnt += 1
    cnt %= 2
    if cnt == 0:
        print(sol)
        continue

    arr = sorted(arr, key=lambda x: abs(x))
    for i in range(cnt):
        sol -= (2*abs(arr[i]))

    print(sol)

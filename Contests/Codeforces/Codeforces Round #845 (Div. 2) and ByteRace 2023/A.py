for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    sol = 0
    arr[0] %= 2
    for index, i in enumerate(arr[1:]):
        temp = i % 2
        if temp == arr[index]: sol += 1
        arr[index+1] = temp

    print(sol)
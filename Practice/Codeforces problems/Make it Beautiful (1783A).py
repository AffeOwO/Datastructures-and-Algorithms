for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))[::-1]

    if len(set(arr)) == 1:
        print("NO")
    else:
        if arr[0] == arr[1]:
            arr[1], arr[-1] = arr[-1], arr[1]
        print("YES")
        print(*arr)
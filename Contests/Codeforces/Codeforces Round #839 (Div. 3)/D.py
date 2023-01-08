for _ in range(int(input())):
    length = int(input())
    arr = list(map(int, input().split()))

    arr_sorted = sorted(arr)
    set_len = len(set(arr))


    if arr == arr_sorted:
        print(0)
    elif arr[0] == arr[-1] and set_len != 1:
        if set_len == 2 and (arr[0] + arr[1]) % 2 == 0:
            print((arr[0] + arr[1]) // 2)
        else:
            print(-1)
    elif arr[::-1] == arr_sorted:
        print(arr[0])
    elif arr[1] < arr[0] < arr[-1]:
        print(-1)
    else:
        print((arr_sorted[-1]+arr_sorted[0]) // 2 + 1)

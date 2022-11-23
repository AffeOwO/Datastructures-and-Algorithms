test_cases = int(input())

for i in range(test_cases):
    arr_len = int(input())
    arr = list(map(int, input().split()))
    sorted_way = sorted(arr)
    for o in arr:
        if o != sorted_way[-1]:
            print(o - sorted_way[-1], end=" ")
        else:
            print(o - sorted_way[-2], end=" ")
    print()

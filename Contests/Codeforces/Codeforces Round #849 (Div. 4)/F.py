def idk(num):
    num = str(num)
    temp2 = 0
    for j in num:
        temp2 += int(j)
    return temp2

for _ in range(int(input())):
    n, q = map(int, input().split())
    arr_s = input().split()
    arr = list(map(int, arr_s))
    arr2 = [0 for _ in range(n)]
    for query in range(q):
        temp = list(map(int, input().split()))
        if temp[0] == 1:
            for i in range(temp[1]-1, temp[2]):
                arr2[i] += 1
        elif temp[0] == 2:
            for _ in range(arr2[temp[1]-1]):
                arr[temp[1]-1] = idk(arr[temp[1]-1])
            arr2[temp[1]-1] = 0
            print(arr[temp[1]-1])
for _ in range(int(input())):
    n, c = map(int, input().split())
    arr = list(map(int, input().split()))


    bruh = sorted([[i+index+1, i+(n-index)] for index, i in enumerate(arr)], key=lambda x: min(x))
    sol = 1
    temp2 = min(bruh, key=lambda x: (x[1] - x[0])*-1)
    temp = temp2[0]
    if temp > c:
        print(0)
        continue

    for i in bruh:
        if temp2 == i:
            continue
        temp += min(i)
        if temp > c:
            break
        sol += 1
    print(sol)
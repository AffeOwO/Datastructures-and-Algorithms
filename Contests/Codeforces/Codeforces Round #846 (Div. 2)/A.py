for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))

    odds, even = 0, 0
    ods, eve = [], []
    for index, i in enumerate(nums):
        index += 1
        if i % 2 == 1:
            odds += 1
            ods.append(index)
        else:
            even += 1
            eve.append(index)

    if odds == 0:
        print("NO")
    elif odds >= 3:
        print("YES")
        print(ods[-1], ods[-2], ods[-3])
    elif even >= 2:
        print("YES")
        print(ods[-1], eve[0], eve[1])
    else:
        print("NO")
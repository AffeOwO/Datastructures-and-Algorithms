for _ in range(int(input())):
    candies = int(input())

    if candies % 2 == 1:
        print(candies // 2)
    else:
        print(candies // 2 - 1)
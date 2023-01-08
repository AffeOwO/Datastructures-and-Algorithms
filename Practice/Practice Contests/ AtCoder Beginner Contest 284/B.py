for _ in range(int(input())):
    n = int(input())
    nums = [i for i in input().split() if int(i)%2==1]
    print(len(nums))
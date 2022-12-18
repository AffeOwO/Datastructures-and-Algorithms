for _ in range(int(input())):
    length = int(input())
    nums = list(map(int, input().split()))
    tower1 = nums[0]
    nums = sorted(nums[1:])
    for i in nums:
        if i > tower1:
            tower1 += (i-tower1+1)//2

    print(tower1)
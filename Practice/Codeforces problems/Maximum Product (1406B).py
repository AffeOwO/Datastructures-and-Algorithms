for _ in range(int(input())):
    _ = int(input())
    nums = list(map(int, input().split()))
    nums = sorted(nums)
    sol = float("-inf")
    for i in range(5):
        temp = nums[:i] + nums[i-5:]
        cur = 1
        for j in temp: cur*=j
        sol = max(sol, cur)
 
    temp2 = nums[:5]
    cur2 = 1
    for i in temp2: cur2 *= i
    print(max(sol, cur2))
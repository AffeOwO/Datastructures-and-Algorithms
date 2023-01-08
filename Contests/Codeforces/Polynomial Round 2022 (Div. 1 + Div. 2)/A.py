for _ in range(int(input())):
    length = int(input())
    nums = input()
    sol = []
    cur = int(nums[0])
    for i in nums[1:]:
        i = int(i)
        if i == 0:
            sol.append("+")
        else:
            sol.append("-") if cur == 1 else sol.append("+")
            cur = 0 if cur == 1 else 1

    print("".join(sol))
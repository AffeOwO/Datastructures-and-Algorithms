nums = sorted(map(int, input().split()))  # A, B, C, A+B, B+C, C+A, A+B+C in random order

abc = nums[-1]  # max val bcs obvious
nums.pop()

for index1 in range(len(nums)):
    for index2 in range(len(nums)):
        for index3 in range(len(nums)):
            if index1 == index2 or index1 == index3 or index2 == index3:
                pass
            else:
                temp = nums[:]
                temp.remove(nums[index1])
                temp.remove(nums[index2])
                temp.remove(nums[index3])

                if nums[index1] + nums[index2] in temp and nums[index2] + nums[index3] in temp and nums[index1] + nums[index3] in temp:
                    if nums[index1] + nums[index2] + nums[index3] == abc:
                        print(nums[index1], nums[index2], nums[index3])
                        exit()
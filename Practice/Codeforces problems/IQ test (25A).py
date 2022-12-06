num_nums = int(input())
nums = list(map(int, input().split()))

even, odd = [], []

for i in nums:
    if i % 2 == 1:
        odd.append(i)
    else:
        even.append(i)

if len(even) == 1:
    print(nums.index(even[0])+1)
else:
    print(nums.index(odd[0])+1)
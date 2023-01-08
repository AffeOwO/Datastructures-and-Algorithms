# correct
test_cases = int(input())

for i in range(test_cases):
    # line 1
    found_num, lost_sum = map(int, input().split())
    found_list = list(map(int, input().split()))

    cur_max = max(found_list)
    needed_sum = sum([i+1 for i in range(cur_max)])
    if len(found_list) == cur_max and cur_max+1 > lost_sum:
        print("No")
    elif needed_sum-sum(found_list) > lost_sum:
        print("No")
    else:
        lost_sum = lost_sum - needed_sum+sum(found_list)
        temp = 0
        while lost_sum > 0:
            temp += 1
            lost_sum = lost_sum - cur_max - temp
        if lost_sum == 0:
            print("Yes")
        else:
            print("No")
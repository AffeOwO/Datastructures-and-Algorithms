cans = int(input())
volume_of_remaining = list(map(int, input().split()))
capacity_of_cans = list(map(int, input().split()))

capacity_of_cans = sorted(capacity_of_cans)
if sum(volume_of_remaining) <= sum(capacity_of_cans[-2:]):
    print("Yes")
    exit()
print("No")
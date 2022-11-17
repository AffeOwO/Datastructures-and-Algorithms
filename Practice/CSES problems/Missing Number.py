n = int(input())
nums = input().split()
print(sum([i for i in range(1, n + 1)]) - sum(map(int, nums)))
from collections import Counter

n = int(input())
arr = list(map(int, input().split()))
cnt = Counter(arr)

print(max(cnt.values()))
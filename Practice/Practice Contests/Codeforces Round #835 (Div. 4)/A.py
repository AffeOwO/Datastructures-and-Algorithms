test_cases = int(input())

for i in range(test_cases):
    ints = list(map(int, input().split()))
    print(sum(ints) - max(ints) - min(ints))
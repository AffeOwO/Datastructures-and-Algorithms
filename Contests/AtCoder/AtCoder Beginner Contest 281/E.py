length, M, K = map(int, input().split())
ints = list(map(int, input().split()))

for k in range(length - M + 1):
    print(sum(sorted(ints[k:k+M])[:K]), end=" ")
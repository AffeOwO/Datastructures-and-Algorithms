n = int(input())

sequence = list(map(int, input().split()))
temp = []

for i in range(n):
    temp.append(sequence[i] - sum(temp))


print(*temp)
participate = 0
for _ in range(int(input())):
    sure = list(map(int, input().split()))
    if sum(sure) >= 2: participate+=1
print(participate)
n = int(input())
xs = []
ys = []
dirs = []
for _ in range(n):
    cow = input().split(' ')
    xs.append(int(cow[1]))
    ys.append(int(cow[2]))
    dirs.append(cow[0])
answer = [float('inf') for _ in range(n)]
diffs = []
for j in range(n):
    for k in range(1,n):
        diffs.append(abs(xs[k]-xs[j]))
        diffs.append(abs(ys[k]-ys[j]))
diffs.sort()

for d in diffs:
    for j in range(n): #iterating through every pair of cows
        for k in range(n):
            if dirs[j] == 'E' and dirs[k] == 'N' and xs[j] < xs[k] and ys[k] < ys[j]:
                if xs[j] + d == xs[k] and ys[k] + min(answer[k],d) > ys[j]:
                    answer[j] = min(answer[j],d)
                elif ys[k] + d == ys[j] and xs[j] + min(answer[j],d) > xs[k]:
                    answer[k] = min(answer[k], d)
for j in range(n):
    print("Infinity" if answer[j] == float('inf') else answer[j])
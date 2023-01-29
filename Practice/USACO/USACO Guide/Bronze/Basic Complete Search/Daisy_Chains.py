n = int(input())  # num of pics: (n*(n+1))//2
arr = list(map(int, input().split()))

sol = n  # pic with one flower always correct
for i in range(2, n+1):  # different ways
    for j in range(n-i+1):
        temp = arr[j:j+i]
        avg = sum(temp) / len(temp)
        if avg % 1 != 0: continue
        if avg in temp: sol += 1

print(sol)
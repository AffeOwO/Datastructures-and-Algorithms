n = int(input())

if n % 4 in (1, 2):
    print("NO")
    exit()

# set1 and set2 aren't actually sets, that's just how they were called in the question
set1 = []
set2 = []
if n % 2 == 0:
    for i in range(1, n+1):
        if i <= n // 4 or i > n // 4 * 3: set1.append(i)
        else: set2.append(i)
else:
    for i in range(1, n+1):
        if i <= n // 4 or i >= n - n // 4: set1.append(i)
        else: set2.append(i)

print("YES")
print(len(set1))
print(*set1)
print(len(set2))
print(*set2)
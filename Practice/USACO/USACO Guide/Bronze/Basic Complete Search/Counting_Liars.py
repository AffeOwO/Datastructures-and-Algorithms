n = int(input())

sweepy = {0: 0}
for _ in range(n):
    direction, amount = input().split()
    amount = int(amount)
    if direction == "G":
        if amount not in sweepy:
            sweepy[amount] = 0
        sweepy[amount] += 1
    else:
        sweepy[0] += 1
        if amount + 1 not in sweepy:
            sweepy[amount+1] = 0
        sweepy[amount+1] -= 1

maxi = -1
cur = 0
for i in sorted(sweepy):
    cur += sweepy[i]
    if cur > maxi:
        maxi = cur
print(n-maxi)
n, t = map(int, input().split())

arrive = {}
for i in range(n):
    day, amount = map(int, input().split())
    arrive[day-1] = amount

"""for i in range(t):
    if i in arrive:
        hay += arrive[i]
    if hay > 0:
        hay -= 1
        sol += 1"""

temp = sorted(arrive)
cur = 0
last = 0
sol = 0
hay = 0
for index, i in enumerate(temp):
    idk = min(hay, abs(last-i))
    if i > t: break
    sol += idk
    hay -= idk
    last = i
    hay += arrive[i]
sol += min(hay, t-last)
print(sol)
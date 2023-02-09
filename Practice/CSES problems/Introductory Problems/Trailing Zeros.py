n = int(input())
sol = 0
x = 1
while 5**x <= n:
    sol += (n//5**x)
    x += 1
print(sol)

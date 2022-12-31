n = int(input())

sol = 1
for i in range(n):
    sol *= 2
    sol %= (10**9 + 7)

print(sol)

from math import factorial

for _ in range(int(input())):
    n = int(input())
    sol = factorial(n) * n * (n-1)
    sol %= (10**9+7)
    print(sol)
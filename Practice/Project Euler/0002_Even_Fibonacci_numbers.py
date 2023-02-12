from functools import cache

@cache
def get_fib_recursive(n: int):
    if n in (0, 1):
        return n
    return get_fib_recursive(n - 1) + get_fib_recursive(n - 2)

i = 1
sol = 0
while True:
    temp = get_fib_recursive(i)
    i += 1
    if temp > 4 * 10**6: break
    if temp % 2 == 0:
        sol += temp

print(sol)
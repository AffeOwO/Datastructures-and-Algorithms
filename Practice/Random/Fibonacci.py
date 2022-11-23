from functools import cache

# practice for recursion
# fibs = 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 ...


@cache
def get_fib(n: int):
    if n < 0:
        raise ValueError("must be >= 0")
    if n in (0, 1):
        return n
    return get_fib(n - 1) + get_fib(n - 2)


if __name__ == "__main__":
    for i in range(1, 10001):
        print(f"{i}: {get_fib(i)}")

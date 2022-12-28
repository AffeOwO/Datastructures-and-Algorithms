from functools import cache

@cache
def trib(n: int):
    if n<0: return ValueError
    if n in (0, 1): return n
    if n == 2: return 1
    return trib(n-1) + trib(n-2) + trib(n-3)


if __name__ == "__main__":
    for i in range(101):
        print(f"{i}: {trib(i)}")
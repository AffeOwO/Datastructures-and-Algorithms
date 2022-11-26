# input >= 0

def solution_1(x):
    return x ** 0.5


def solution_2(x):
    res = 0
    while res ** 2 <= x:
        res += 1
    return (res - 1) // 1


# newton's method
def solution_3(x):
    r = x
    while r ** 2 > x:
        r = (r + x/r) / 2
    return r


if __name__ == "__main__":
    print(solution_1(484))
    print(solution_2(484))
    print(solution_3(484))
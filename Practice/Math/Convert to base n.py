digits = ['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J']  # (first 20 digits)
def to_base(num):
    if base == 10:
        return num
    if num < base: return digits[num]
    return to_base(num // base) + digits[num % base]


if __name__ == "__main__":
    base = int(input())
    print(to_base(int(input())))

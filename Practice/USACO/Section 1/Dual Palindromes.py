"""
ID: yamato berner (affeowo1)
TASK: dualpal
LANG: PYTHON3
"""

digits = list("0123456789")

def to_base(num, base):
    if base == 10:
        return num
    if num < base: return digits[num]
    return to_base(num // base, base) + digits[num % base]

def is_pal(num):
    if num == int(str(num)[::-1]): return True
    for j in range(2, 10):
        temp2 = to_base(num, j)
        if temp2 == str(temp2)[::-1]:
            return True
    return False

fin = open("dualpal.in")
fout = open("dualpal.out", "w")
n, cur = map(int, fin.read().split())

sol = []
while len(sol) != n:
    if is_pal(cur):
        sol.append(cur)
    cur += 1

for i in sol:
    fout.write(f"{i}\n")
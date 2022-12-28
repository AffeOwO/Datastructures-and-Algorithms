"""
ID: yamato berner (affeowo1)
TASK: palsquare
LANG: PYTHON3
"""

fin = open("palsquare.in", "r")
fout = open("palsquare.out", "w")

base = int(fin.read())

digits = ['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J']  # (first 20 digits)
def to_base(num):
    if base == 10:
        return num
    if num < base: return digits[num]
    return to_base(num // base) + digits[num % base]

sol = []
for i in range(1, 301):
    i_square = to_base(i*i)
    if str(i_square) == str(i_square)[::-1]:
        sol.append([str(to_base(i)), str(i_square)])

for i in sol:
    fout.write(f"{' '.join(i)}\n")
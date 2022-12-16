"""
ID: yamato berner (affeowo1)
TASK: namenum
LANG: PYTHON3
"""

fin = open("namenum.in", "r")
fout = open("namenum.out", "w")
names = open("dict.txt", "r").read().splitlines()

serial_num = fin.read().strip()
serial_len = len(serial_num)
translation = [["A", "B", "C"], ["D", "E", "F"],
               ["G", "H", "I"], ["J", "K", "L"],
               ["M", "N", "O"], ["P", "R", "S"],
               ["T", "U", "V"], ["W", "X", "Y"]]  # num - 2 = index | 2=0,3=1,4=2...
name_range = ["".join([translation[int(i) - 2][0] for i in serial_num]), "".join([translation[int(i)-2][-1] for i in serial_num])]
possible_names = []

for i in names:
    if serial_len != len(i):
        continue
    for o in range(serial_len):
        if name_range[0][o] <= i[o] <= name_range[1][o]:
            pass
        else:
            break
    else:
        possible_names.append(i)

for i in possible_names:
    fout.write(f"{i}\n")
if len(possible_names) == 0:
    fout.write("NONE\n")
fout.close()
"""
ID: yamato berner (affeowo1)
TASK: ride
LANG: PYTHON3
"""

fin = open("ride.in", "r")
fout = open("ride.out", "w")

fin = fin.readlines()

comet = fin[0]
group = fin[1]

comet_sum = 1
group_sum = 1

for i in comet:
    comet_sum *= ord(i) - ord("A") + 1
for i in group:
    group_sum *= ord(i) - ord("A") + 1

if comet_sum % 47 == group_sum % 47:
    fout.write("GO\n")
else:
    fout.write("STAY\n")

fout.close()
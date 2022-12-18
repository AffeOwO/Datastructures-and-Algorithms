fin = open("mixmilk.in").read().splitlines()
fout = open("mixmilk.out")

milks = [list(map(int, fin[i].split())) for i in range(3)]

for _ in range(33):
    temp1 = min([milks[0][1], milks[1][0]-milks[1][1]])
    milks[0][1] -= temp1
    milks[1][1] += temp1
    temp2 = min([milks[1][1], milks[2][0]-milks[2][1]])
    milks[1][1] -= temp2
    milks[2][1] += temp2
    temp3 = min([milks[2][1], milks[0][0]-milks[0][1]])
    milks[2][1] -= temp3
    milks[0][1] += temp3
temp1 = min([milks[0][1], milks[1][0]-milks[1][1]])
milks[0][1] -= temp1
milks[1][1] += temp1

for i in milks:
    fout.write(f"{i[1]}\n")
fout.close()
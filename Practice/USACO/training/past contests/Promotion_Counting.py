fin = open("promote.in")
fout = open("promote.out")
fin = list(map(int, fin.read().split()))

temp = []

for _ in range(3): temp.append(fin[7]-fin[6])
for i in range(2): temp[i] += (fin[5]-fin[4])
temp[0] += (fin[3]-fin[2])

for i in temp:
    fout.write(f"{i}\n")
fout.close()
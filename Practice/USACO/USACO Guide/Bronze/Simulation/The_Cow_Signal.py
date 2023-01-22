fin = open("cowsignal.in").read().splitlines()
fout = open("cowsignal.out")

height, length, bigger = map(int, fin[0].split())
sol = []

for index, i in enumerate(fin[1:]):
    temp = ""
    for o in range(length):
        temp += (i[o] * bigger)
    for _ in range(bigger):
        sol.append(temp)


for i in sol:
    fout.write(f"{i}\n")
fout.close()
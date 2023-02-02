fin = open("cownomics.in").read().splitlines()
fout = open("cownomics.out", "w")

n, m = map(int, fin[0].split())

spotty, not_spotty = [set() for _ in range(m)], [set() for _ in range(m)]
for i in range(n):
    dna = fin[i+1]
    for index, j in enumerate(dna):
        spotty[index].add(j)
for i in range(n):
    dna = fin[i+1+n]
    for index, j in enumerate(dna):
        not_spotty[index].add(j)

sol = 0
for index, i in enumerate(spotty):
    temp = True
    for j in i:
        if j in not_spotty[index]:
            temp = False
            break
    if temp:
        sol += 1

fout.write(f"{sol}\n")
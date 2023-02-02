fin = open("gymnastics.in").read().splitlines()
fout = open("gymnastics.out", "w")

k, n = map(int, fin[0].split())
better = {i: set() for i in range(1, n+1)}
for k in range(k):
    session = list(map(int, fin[k+1].split()))
    temp = set()
    for i in session:
        for j in temp:
            better[i].add(j)
        temp.add(i)

total = 0
for i in better:
    total +=  n - len(better[i])-1

fout.write(f"{total}\n")
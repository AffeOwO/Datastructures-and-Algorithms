fin = open("lifeguards.in").read().splitlines()
fout = open("lifeguards.out", "w")

n = int(fin[0])
guards = []
for i in fin[1:]:
    shift = list(map(int, i.split()))
    guards.append(shift)
sol = -1

sweepy = {}
for i in guards:
    start, end = i
    if start not in sweepy: sweepy[start] = 0
    if end not in sweepy: sweepy[end] = 0
    sweepy[start] += 1
    sweepy[end] -= 1


for index, i in enumerate(guards):
    cur = 0
    start, end = i[0], i[1]
    temp = 0
    for j in range(max(sweepy)):
        if j in sweepy:
            temp += sweepy[j]
            if j == start:
                temp -= 1
            if j == end:
                temp += 1
        if temp > 0:
            cur += 1
    if cur > sol:
        sol = cur

fout.write(f"{sol}\n")
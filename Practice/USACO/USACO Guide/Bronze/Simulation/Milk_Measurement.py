fin = open("measurement.in").read().splitlines()
fout = open("measurement.out", "w")

n = int(fin[0])
sol = 0
cows = {"b": 7, "m": 7, "e": 7}
top = ["b", "m", "e"]
queries = []
for i in range(n):
    time, name, change = fin[i+1].split()
    time, change = int(time), int(change)
    name = name[0].lower()
    queries.append([time, name, change])
queries = sorted(queries, key=lambda x: x[0])
for i in queries:
    cows[i[1]] += i[2]
    temp = max(cows.values())
    temp_top = []
    for j in cows:
        if cows[j] == temp: temp_top.append(j)
    if temp_top != top: sol += 1
    top = temp_top

fout.write(f"{sol}\n")
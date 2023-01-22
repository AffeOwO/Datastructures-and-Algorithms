fin = open("mowing.in").read().splitlines()
fout = open("mowing.out", "w")

n = int(fin[0])
sol = float("inf")
visited = {(0, 0): 0}
time = 0
cur = [0, 0]
for i in range(n):
    direction, amount = fin[i+1].split()
    amount = int(amount)
    if direction == "N":
        for j in range(amount):
            cur[1] += 1
            time += 1
            temp = tuple(cur)
            if temp in visited:
                temp2 = time - visited[temp]
                if temp2 < sol: sol = temp2
            visited[temp] = time
    if direction == "E":
        for j in range(amount):
            cur[0] += 1
            time += 1
            temp = tuple(cur)
            if temp in visited:
                temp2 = time - visited[temp]
                if temp2 < sol: sol = temp2
            visited[temp] = time
    if direction == "S":
        for j in range(amount):
            cur[1] -= 1
            time += 1
            temp = tuple(cur)
            if temp in visited:
                temp2 = time - visited[temp]
                if temp2 < sol: sol = temp2
            visited[temp] = time
    if direction == "W":
        for j in range(amount):
            cur[0] -= 1
            time += 1
            temp = tuple(cur)
            if temp in visited:
                temp2 = time - visited[temp]
                if temp2 < sol: sol = temp2
            visited[temp] = time

if sol == float("inf"): sol = -1
fout.write(f"{sol}\n")
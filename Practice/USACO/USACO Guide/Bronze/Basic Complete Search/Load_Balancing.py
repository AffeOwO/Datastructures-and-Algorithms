fin = open("balancing.in").read().splitlines()
fout = open("balancing.out", "w")

n, b = map(int, fin[0].split())
sol = 0
cows_x = {}
for i in range(n):
    x, _ = map(int, fin[i+1].split())
    if x not in cows_x: cows_x[x] = 0
    cows_x[x] += 1

x_vals = sorted(cows_x)
vertical = [0, n]
border_x = 0
for i in x_vals:
    temp = [vertical[0] + cows_x[i], vertical[1] - cows_x[i]]
    if abs(temp[1]-temp[0]) < abs(vertical[1]-vertical[0]):
        vertical = temp
        border_x = vertical[0]
    # vertical = min((temp, vertical), key=lambda z: abs(z[1]-z[0]))

cows_y = {}
y_vals = set()
for i in range(n):
    x, y = map(int, fin[i+1].split())
    y_vals.add(y)
    if f"{y}_1" not in cows_y:
        cows_y[f"{y}_1"] = 0
        cows_y[f"{y}_2"] = 0
    if x < border_x: cows_y[f"{y}_1"] += 1
    else: cows_y[f"{y}_2"] += 1

y_vals = sorted(y_vals)
horizontal = [[0, 0], [vertical[0], vertical[1]]]
for i in y_vals:
    temp = [[horizontal[0][0] + cows_y[f"{i}_1"], horizontal[0][1] + cows_y[f"{i}_2"]],
            [horizontal[1][0] - cows_y[f"{i}_1"], horizontal[1][1] - cows_y[f"{i}_2"]]]
    print(temp, horizontal)
    if max((max(temp[0]), max(temp[1]))) < max((max(horizontal[0]), max(horizontal[1]))):
        horizontal = temp

fout.write(f"{max((max(horizontal[0]), max(horizontal[1])))}\n")
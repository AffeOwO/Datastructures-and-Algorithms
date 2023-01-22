fin = open("lostcow.in")
fout = open("lostcow.out", "w")

x, y = map(int, fin.readline().split())
difference = abs(x-y)
original_direction = x < y  # True=right, False=left
direction = True

if difference == 0:
    fout.write("0\n")
    exit()

cur = 1
sol = 1
prev = 1
while abs(cur) < difference:
    cur *= -2
    sol += abs(cur) + abs(prev)
    direction = not direction
    prev = cur

if direction != original_direction:
    cur *= -2
    sol += abs(prev) + abs(cur)
sol -= (abs(cur) - difference)

fout.write(f"{sol}\n")
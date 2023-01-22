fin = open("cbarn.in").read().splitlines()
fout = open("cbarn.out", "w")

n = int(fin[0])
rooms = []
cows = 0
for i in fin[1:]:
    temp = int(i)
    rooms.append(temp)
    cows += temp

def simulate(start_index):
    cur = 0
    temp_cows = cows
    for j in rooms[start_index:]+rooms[:start_index]:
        temp_cows -= j
        cur += temp_cows
    return cur

sol = float("inf")
for index in range(n):
    temp = simulate(index)
    if temp < sol:
        sol = temp

fout.write(f"{sol}\n")
fout.close()
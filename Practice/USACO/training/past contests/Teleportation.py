fin = list(map(int, open("teleport.in").read().split()))
fout = open("teleport.out")
sol = 0

a = max(fin[:2])
b = min(fin[:2])

def teleport(int1, int2):
    return abs(int1 - a) + abs(int2-b)

ab_sub = a - b
teleported = teleport(max(fin[2:]), min(fin[2:]))

if ab_sub <= teleported:
    sol = ab_sub
else:
    sol = teleported

fout.write(f"{sol}\n")
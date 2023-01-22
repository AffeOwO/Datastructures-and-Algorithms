fin = open("shells.in").read().splitlines()
fout = open("shells.out")

N = int(fin[0])
shells=[0, 1, 2]
sol=[0, 0, 0]

for i in range(N):
    a, b, g = map(int, fin[i + 1].split())
    shells[a - 1], shells[b - 1] = shells[b - 1], shells[a - 1]
    sol[shells[g - 1]] += 1

fout.write(f"{max(sol)}\n")
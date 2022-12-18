fin = open("word.in")
fout = open("word.out")

fin = fin.read().splitlines()
N, K = map(int, fin[0].split())
string = fin[1].split()
string_lengths = list(map(len, string))

sol = []

temp = 0
for i in range(len(string)):
    if temp + string_lengths[i] > K:
        sol.append("\n")
        temp = 0
    temp += string_lengths[i]
    sol.append(f"{string[i]} ")

for i in sol:
    fout.write(i)

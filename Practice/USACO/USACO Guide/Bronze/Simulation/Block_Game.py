fin = open("blocks.in").read().splitlines()
fout = open("blocks.out", "w")

n = int(fin[0])
final = {}
for i in fin[1:]:
    word1, word2 = i.split()
    temp1, temp2 = {}, {}
    for j in word1:
        if j not in temp1:
            temp1[j] = 0
        temp1[j] += 1
    for j in word2:
        if j not in temp2:
            temp2[j] = 0
        temp2[j] += 1
    for j in temp2:
        if j not in temp1:
            temp1[j] = temp2[j]
        else:
            temp1[j] = max(temp1[j], temp2[j])
    for j in temp1:
        if j not in final:
            final[j] = 0
        final[j] += temp1[j]

letters = "abcdefghijklmnopqrstuvwxyz"
sol = ""
for i in letters:
    if i not in final:
        sol += "0\n"
    else:
        sol += f"{final[i]}\n"
fout.write(sol)
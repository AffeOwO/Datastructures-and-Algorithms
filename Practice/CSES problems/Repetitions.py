dna = input()
sol = 1
sol_ll = []
prev = ""
for index, i in enumerate(dna):
    if dna[index] == prev:
        sol += 1
    else:
        sol = 1
    prev = i
    sol_ll.append(sol)

print(max(sol_ll))
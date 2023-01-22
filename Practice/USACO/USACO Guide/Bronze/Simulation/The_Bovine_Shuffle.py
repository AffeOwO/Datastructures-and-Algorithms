fin = open("shuffle.in").read().splitlines()
fout = open("shuffle.out", "w")

n = int(fin[0])
operations = list(map(int, fin[1].split()))  # 1-indexed
end = list(map(int, fin[2].split()))

def reverse_operations(ops):
    rev_ops = [0 for _ in range(n)]
    for index2, j in enumerate(ops):
        rev_ops[j-1] = index2
    return rev_ops
operations = reverse_operations(operations)  # reversed and 0-indexed now

sol = [0 for _ in range(n)]
for index in range(n):
    if operations[index] == index:
        sol[index] = end[index]
    else:
        temp = operations[index]
        temp = operations[temp]
        temp = operations[temp]
        sol[temp] = end[index]

for i in sol:
    fout.write(f"{i}\n")
fout.close()
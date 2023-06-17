binaryinp = list(map(int, input().split()))

sol = 0
for index, i in enumerate(binaryinp):
    if i == 1: sol += (2**index)

print(sol)
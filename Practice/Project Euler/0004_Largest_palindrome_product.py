sol = 0

for i in range(999, 99, -1):
    for j in range(i, 99, -1):
        temp = str(i*j)
        if temp == temp[::-1]:
            temp = i*j
            if temp > sol:
                sol = temp
print(sol)

# uppercase -38 | lowercase -96

sol = 0

while True:
    temp = input()
    if temp == "":
        break
    half_1, half_2 = set(temp[:len(temp)//2]), temp[len(temp)//2:]

    for i in half_1:
        if i in half_2:
            sol += ord(i)
            if i.islower():
                sol -= 96
            else:
                sol -= 38
print(sol)


sol = 0
while True:
    temp2 = []
    for i in range(3):
        temp = input()
        if temp == "":
            print(sol)
            exit()
        temp2.append(temp)
    for i in temp2[0]:
        if i in temp2[1] and i in temp2[2]:
            sol += ord(i)
            if i.islower():
                sol -= 96
            else:
                sol -= 38
            break
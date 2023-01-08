# wrong
cur_floor = 1
anzahl = int(input())

leitern = []

for i in range(anzahl):
    leitern.append(input())

while True:
    temp = []
    for o in leitern:
        if str(cur_floor) in o.split():
            temp.append(o)
    if not temp:
        break

    tempList = []
    for x in temp:
        u1, u2 = x.split()
        if u1 != str(cur_floor):
            tempList.append(int(u1))
        else:
            tempList.append(int(u2))
    if max(tempList) > cur_floor:
        cur_floor = max(tempList)
    else:
        break

print(cur_floor)
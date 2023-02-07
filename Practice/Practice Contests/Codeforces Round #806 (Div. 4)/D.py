for _ in range(int(input())):
    n = int(input())
    strings = []
    idk = set()
    strings2 = set()
    for _ in range(n):
        temp = input()
        strings.append(temp)
        strings2.add(temp)
    strings2 = list(strings2)
    for index, i in enumerate(strings2):
        for index2, j in enumerate(strings2):
            if index2 < index or len(i)+len(j) > 8: continue
            temp1, temp2 = i+j, j+i
            idk.add(temp1)
            idk.add(temp2)

    sol = ""
    for i in strings:
        if i in idk:
            sol += "1"
        else:
            sol += "0"

    print(sol)
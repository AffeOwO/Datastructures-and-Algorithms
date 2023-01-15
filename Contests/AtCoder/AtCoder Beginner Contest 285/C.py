def convert(columnTitle):
    columnTitle = list(columnTitle)
    cur = 0
    sol = 0
    while columnTitle:  # ord(letter) - 64
        score = ord(columnTitle[-1]) - 64
        sol += score * 26 ** cur
        cur += 1
        columnTitle.pop()
    return sol
id_abc = input()
print(convert(id_abc))
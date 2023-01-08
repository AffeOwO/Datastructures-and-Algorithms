with open("input.in", "r", encoding="utf-8") as file:
    file = file.read()
    # part 1
    for index in range(len(file) - 3):
        if len(set(file[index:index+4])) == 4:
            print(index+4)
            break

    # part 2
    for index in range(len(file) - 13):
        if len(set(file[index:index+14])) == 14:
            print(index+14)
            break
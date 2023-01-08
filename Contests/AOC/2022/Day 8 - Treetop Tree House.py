with open("input.in", "r", encoding="utf-8") as file:
    file = file.readlines()

    for i in range(len(file)):
        file[i] = file[i][:-1]
        file[i] = list(map(int, list(file[i])))

    # part 1
    coords = set()
    trees1 = 0

    for i in range(len(file)):
        cur_max = -1
        for index, o in enumerate(file[i]):
            if o > cur_max:
                cur_max = o
                coords.add(f"{i}:{index}")
        cur_max = -1
        for index, o in enumerate(file[i][::-1]):
            if o > cur_max:
                cur_max = o
                coords.add(f"{i}:{len(file[i]) - index - 1}")

    for i in range(len(file[0])):
        cur_max = -1
        for index, o in enumerate(file):
            if o[i] > cur_max:
                cur_max = o[i]
                coords.add(f"{index}:{i}")
        cur_max = -1
        for index, o in enumerate(file[::-1]):
            if o[i] > cur_max:
                cur_max = o[i]
                coords.add(f"{len(file) - index - 1}:{i}")
    print(len(coords))

    # part 2
    score = 1

    def measure(x, y):
        scores = {"x": 0, "-x": 0, "y": 0, "-y": 0}
        temp_score = 1
        cur_value = file[y][x]  # format: file[y][x]
        # loop: left -> right if no right then go 1 row below
        if x == 0 or y == 0 or x == len(file[0]) - 1 or y == len(file) - 1:
            return 0
        # loop through each direction in matrix
        for p in range(x+1, len(file[0])):
            scores["x"] += 1
            if file[y][p] >= cur_value:
                break
        if x == len(file[0]) - 2:
            scores["x"] = 1
        for p in range(x - 1, -1, -1):
            scores["-x"] += 1
            if file[y][p] >= cur_value:
                break

        for p in range(y+1, len(file)):
            scores["y"] += 1
            if file[p][x] >= cur_value:
                break
        if y == len(file) - 2:
            scores["y"] = 1
        for p in range(y - 1, -1, -1):
            scores["-y"] += 1
            if file[p][x] >= cur_value:
                break

        for p in scores:
            temp_score *= scores[p]

        return temp_score

    for index_y in range(len(file)):
        for index_x in range(len(file[0])):
            cur_score = measure(index_x, index_y)
            if cur_score > score:
                score = cur_score

    print(score)
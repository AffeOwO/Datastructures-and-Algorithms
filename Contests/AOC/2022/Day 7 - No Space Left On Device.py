with open("input.in", "r", encoding="utf-8") as file:
    file = file.readlines()
    size_1 = 0
    cur_loc = "/"
    locs = {}

    for index, i in enumerate(file):
        cur_loc = "".join(cur_loc)
        if cur_loc not in locs.keys():
            locs[cur_loc] = []
        #i = i[:-1]
        i.strip()
        if i[0] == "$":
            if i[2:4] == "cd":
                if i[5] == "/":
                    cur_loc = "/"
                elif i[5:7] == "..":
                    cur_loc = list(cur_loc)
                    cur_loc.pop()
                    while cur_loc[-2] != "/":
                        cur_loc.pop()
                else:
                    cur_loc += f"{i[5:]}/"

            else:
                for o in file[index+1:]:
                    if o[0].isnumeric():
                        size, _ = o.split()
                        locs[cur_loc].append(int(size))
                    elif o[0] == "$":
                        break

    for i in locs:
        locs[i] = sum(locs[i])
    locs_sorted_keys = sorted(locs, key=lambda x: x.count("/"))

    for i in locs_sorted_keys[::-1]:
        if i.count("/") == 1:
            continue

        temp = list(i)
        temp.pop()
        while temp[-2] != "/":
            temp.pop()
        temp.pop()
        temp = "".join(temp)
        locs[temp] += locs[i]

    for i in locs:
        if locs[i] <= 100000:
            size_1 += locs[i]
    print(size_1)

    # part 2
    temp = locs["/"] - 40000000
    sol = 70000000
    for i in locs:
        if temp < locs[i] < sol:
            sol = locs[i]
    print(sol)
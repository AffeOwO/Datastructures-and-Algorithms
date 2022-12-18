fin = open("buckets.in")
fout = open("buckets.out")

fin = fin.read().splitlines()

lake, rock, barn = [], [], []

for index, i in enumerate(fin):
    if "L" in i:
        lake.append(index)
        for index2, i2 in enumerate(i):
            if i2 == "L":
                lake.append(index2)
                break
    if "B" in i:
        barn.append(index)
        for index2, i2 in enumerate(i):
            if i2 == "B":
                barn.append(index2)
                break
    if "R" in i:
        rock.append(index)
        for index2, i2 in enumerate(i):
            if i2 == "R":
                rock.append(index2)
                break

distance = abs(lake[0]-barn[0]) + abs(lake[1]-barn[1]) - 1

fout.write(f"{distance}\n")
fout.close()
# part 1
pairs = 0
while True:
    try:
        pair1, pair2 = input().split(",")
    except ValueError:
        break

    pair1 = list(map(int, pair1.split("-")))
    pair2 = list(map(int, pair2.split("-")))

    if (pair1[0] <= pair2[0] and pair1[1] >= pair2[1]) or (pair1[0] >= pair2[0] and pair1[1] <= pair2[1]):
        pairs += 1
print(pairs)


# part 2
overlaps = 0
while True:
    try:
        pair1, pair2 = input().split(",")
    except ValueError:
        break

    pair1 = list(map(int, pair1.split("-")))
    pair2 = list(map(int, pair2.split("-")))

    if pair1[0] <= pair2[0] <= pair1[1] or pair1[0] <= pair2[1] <= pair1[1] or pair2[0] <= pair1[0] <= pair2[1] or pair2[0] <= pair1[1] <= pair2[1]:
        overlaps += 1

print(overlaps)
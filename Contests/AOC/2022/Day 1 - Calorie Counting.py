elves = {}
i = 1

while True:
    if i not in elves.keys():
        elves[i] = []
    temp = input()
    if temp == '':
        i += 1
        continue
    elif temp == "nah":
        break
    elves[i].append(int(temp))

sum_elves = []

for i in elves:
    sum_elves.append(sum(elves[i]))

sum_elves.sort()
print(sum_elves[-1])
print(sum(sum_elves[-3:]))
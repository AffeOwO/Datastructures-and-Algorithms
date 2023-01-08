height, width = map(int, input().split())

temp = 0

for i in range(height):
    temp2 = input()
    for o in temp2:
        if o == "#":
            temp += 1

print(temp)
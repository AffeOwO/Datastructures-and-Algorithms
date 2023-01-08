string = input()

bottoms = 0

for i in string:
    if i == "v": bottoms += 1
    if i == "w": bottoms += 2
print(bottoms)
def isValid(s):
    stack = []
    sol = {}
    temp = {")": "("}
    for index2, char in enumerate(s):
        if char.islower():
            pass
        elif char in temp.values():
            stack.append(index2)
        elif char in temp.keys():
            sol[index2] = stack.pop()
    return sol

string = input()

box = []
pars = isValid(string)

for index, i in enumerate(string):
    if i.islower():
        if i in box:
            print("No")
            exit()
        box.append(i)
    elif i == ")":
        j = pars[index]
        for i2 in string[j:index]:
            if i2 in box:
                box.remove(i2)

print("Yes")
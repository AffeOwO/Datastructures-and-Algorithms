inp = int(input())
while inp != 1:
    print(inp, end=" ")
    if inp % 2 == 0:
        inp = inp // 2
    else:
        inp = inp * 3 + 1
print(inp)
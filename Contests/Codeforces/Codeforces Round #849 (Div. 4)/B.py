for _ in range(int(input())):
    n = int(input())
    strs = input()

    pos = [0,0]
    sol = False
    for s in strs:
        if s == "U":
            pos[1] += 1
        elif s == "D":
            pos[1] -= 1
        elif s == "R":
            pos[0] += 1
        elif s == "L":
            pos[0] -= 1
        if pos == [1,1]:
            sol = True
    if sol: print("Yes")
    else: print("No")
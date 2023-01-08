S = input()
temp = 0

if len(S) == 1:
    print(1)
    exit()

while S:
    if len(S) == 1:
        temp += 1
        break
    elif S[0] != "0" or S[1] != "0":
        temp += 1
        S = S[1:]
    elif S[0] == "0" and S[1] == "0":
        temp += 1
        S = S[2:]

print(temp)
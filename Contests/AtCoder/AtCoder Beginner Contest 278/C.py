users, times = map(int, input().split())
temp = {}
for i in range(times):
    op1, usr1, usr2 = map(int, input().split())
    if usr1 not in temp.keys(): temp[usr1] = ""
    if usr2 not in temp.keys(): temp[usr2] = ""
    if op1 == 1:
        if f"|{usr1}>{usr2}|" not in temp[usr1]:
            temp[usr1] = temp[usr1] + f"|{usr1}>{usr2}|"
    elif op1 == 2:
        if f"|{usr1}>{usr2}|" in temp[usr1]:
            temp[usr1] = temp[usr1].replace(f"|{usr1}>{usr2}|", "")
    else:
        if f"|{usr1}>{usr2}|" in temp[usr1] and f"|{usr2}>{usr1}|" in temp[usr2]:
            print("Yes")
        else:
            print("No")

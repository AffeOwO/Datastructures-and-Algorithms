t = int(input())
while t>0:
    t-=1
    n = int(input())
    s = input()
    tmp = True
    for index, i in enumerate(s):
        if not i.islower() and not i.isdigit():
            tmp = False
        if index != 0 and i.isdigit() and s[index-1].islower():
            tmp = False
        if index != 0 and i.isdigit() and s[index-1].isdigit() and  int(i)<int(s[index-1]):
            tmp = False
        if index != 0 and i.islower() and s[index-1].islower() and s[index-1]>i:
            tmp = False

    if tmp: print("YES")
    else: print("NO")

    
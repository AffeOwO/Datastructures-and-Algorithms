n = int(input())
s = list(input())
q = int(input())

for _ in range(q):
    query = input().split()
    if query[0] == "1":
        s[int(query[1])-1] = query[2]
    else:
        t = "".join(sorted(s))
        temp = "".join(s[int(query[1])-1:int(query[2])])
        if temp in t: print("Yes")
        else: print("No")
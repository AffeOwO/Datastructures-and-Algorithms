k = int(input())
s = input()
s1 = [i+"." for i in s.split()]
s2 = []
for i in s1:
    temp = i.split("-")
    for j in temp:
        if j[-1]==".": s2.append(j)
        else: s2.append(j+".")
s2[-1] = s2[-1][:-1]

l, r, sol = 1, len(s)+1, len(s)+1
while l<=r:
    m = (l+r)//2
    cnt, cur = 1, 0
    for i in s2:
        if cur + len(i)<=m: cur += len(i)
        else:
            cur = len(i)
            cnt += 1
            if cur > m:
                cnt = k+1

    if(cnt<=k):
        r = m-1
        sol = m
    else: l = m+1
print(sol)

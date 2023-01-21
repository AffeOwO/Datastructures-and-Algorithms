n, a, b = map(int, input().split())
s = list(input())

def idk():
    price = 0
    for index in range(n // 2):
        if s[index] != s[n - index - 1]: price += b
    return price

added = 0
orig = idk()
cur = orig
for i in range(n-1):
    s.append(s[0])
    s = s[1:]
    added += a
    temp = idk() + added
    if temp < cur: cur = temp
    if added > cur: break
print(cur)
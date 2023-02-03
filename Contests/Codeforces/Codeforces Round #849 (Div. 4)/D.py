for _ in range(int(input())):
    n = int(input())
    s = list(input())
    sol = 0
    first, second = {}, {i: s.count(i) for i in set(s)}
    for i in s:
        if i not in first:
            first[i] = 0
        second[i] -= 1
        if second[i] == 0:
            del second[i]
        temp = len(first) + len(second)
        if temp > sol:
            sol = temp

    print(sol)
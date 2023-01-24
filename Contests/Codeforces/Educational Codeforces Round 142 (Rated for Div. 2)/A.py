for _ in range(int(input())):
    n = int(input())
    monsters = sorted(list(map(int, input().split())))
    sol = n
    cur = 0
    for index, i in enumerate(monsters):
        if index == n-1 and i != 0:
            cur += 1
        elif i == 1 and monsters[index+1] == 1:
            cur += 1
            if index != n-1:
                monsters[index + 1] -= 1
        elif i == 0:
            continue
        else:
            cur += 1
    print(min((cur, sol)))
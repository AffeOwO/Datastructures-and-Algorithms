for _ in range(int(input())):
    n, s, r = map(int, input().split())  # number, bef, aft
    dices = [s-r] # removed dice
    n -= 1
    temp = r // n
    for i in range(n):
        dices.append(temp)
        r -= temp
        n -= 1
        if n == 0: break
        temp = r // n
    print(*dices)
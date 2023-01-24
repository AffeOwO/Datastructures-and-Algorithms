for _ in range(int(input())):
    types = list(map(int, input().split()))  # t1 = both, t2 = l likes, t3 = r likes, t4 = nobody likes ||| +1 -1, < 0 -> leave
    status = [types[0], types[0]]
    amount = types[0]
    types[0] = 0

    if amount == 0:
        if sum(types) == 0: print(0)
        else: print(1)
        continue

    temp = min((types[1], types[2]))
    amount += (2*temp)
    types[1] -= temp
    types[2] -= temp

    temp = min((types[3], 1+min(status)))
    amount += temp
    types[3] -= temp
    status[0] -= temp
    status[1] -= temp

    if min(status) >= 0 and (types[1] > 0 or types[2] > 0):
        amount += min((min(status) + 1, max(types)))
    print(amount)

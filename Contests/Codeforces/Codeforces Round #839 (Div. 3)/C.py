for _ in range(int(input())):
    length, last_val = map(int, input().split())

    if length == last_val:
        print(*[i for i in range(1, length+1)])
    else:
        sol = [1]
        for i in range(1, length):
            sol.append(sol[-1]+i)
        while sol[-1] > last_val:
            sol[-1] -= 1
            sol = sorted(sol)
        sol[-1] = last_val
        if len(set(sol)) != length:
            for i in range(length):
                while sol.count(sol[i]) > 1:
                    sol[i] -= 1


        print(*sorted(sol))
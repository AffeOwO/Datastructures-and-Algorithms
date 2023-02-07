for _ in range(int(input())):
    n = int(input())
    s = input()

    sol = 0
    solved = set()
    for i in s:
        if i not in solved:
            sol += 1
            solved.add(i)
        sol += 1
    print(sol)
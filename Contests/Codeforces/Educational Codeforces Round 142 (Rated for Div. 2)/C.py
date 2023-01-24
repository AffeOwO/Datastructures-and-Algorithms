for _ in range(int(input())):
    n = int(input())
    perm = list(map(int, input().split()))

    sol = 0
    for index, i in enumerate(perm[:-1]):
        if i > perm[index+1]: sol += 1
    print(sol)
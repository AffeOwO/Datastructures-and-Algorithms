for _ in range(int(input())):
    n, x = map(int, input().split())

    if n in (1,2): print(1)
    else:
        if (n-2) % x == 0: print((n-2)//x+1)
        else: print((n-2)//x+2)
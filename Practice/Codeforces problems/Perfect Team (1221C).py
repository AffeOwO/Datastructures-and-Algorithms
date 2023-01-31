for _ in range(int(input())):
    c, m, n = map(int, input().split())
    print(min(sum((c, m, n))//3, min(c, m)))
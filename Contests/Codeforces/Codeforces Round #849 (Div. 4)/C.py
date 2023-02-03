for _ in range(int(input())):
    n = int(input())
    s = input()

    sol = 0
    for i in range(n//2):
        if s[i] == s[-1*(1+i)]:
            break
        n -= 2

    print(n)
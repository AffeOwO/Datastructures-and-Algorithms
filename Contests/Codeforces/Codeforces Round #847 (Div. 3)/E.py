for _ in range(int(input())):
    x = int(input())  # bitwise xor sol
    a, b = int(0.5*x), int(1.5*x)

    if x % 2 == 1:
        print(-1)  # because then a xor b has to be odd and (odd+even) != interger
        continue
    if a ^ b == x:
        print(a, b)
        continue
    print(-1)


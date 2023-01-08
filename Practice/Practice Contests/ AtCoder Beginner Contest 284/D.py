def isPrime(n):
    if n < 2: return False
    for x in range(2, int(n ** 0.5) + 1):
        if n % x == 0:
            return False
    return True

for _ in range(int(input())):
    N = int(input())

    temp = N/4
    if N%4==0 and isPrime(temp):
        print(2, int(temp))
        continue
    temp = int((N/2)**0.5)
    if N%2==0 and temp%1==0 and isPrime(temp):
        print(int(temp), 2)
        continue

    cur = 3
    while True:
        temp = N/(cur**2)
        if temp % 1 == 0 and isPrime(temp):
            print(cur, int(temp))
            break
        cur += 2
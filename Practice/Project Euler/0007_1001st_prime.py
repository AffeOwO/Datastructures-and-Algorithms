def is_prime(num):
    for i in range(2, int(num**0.5)+1):
        if num % i == 0:
            return False
    return True

primes = []
cur = 2
while True:
    temp = is_prime(cur)
    if temp:
        primes.append(cur)
        if len(primes) == 10001:
            print(cur)
            break
    cur += 1
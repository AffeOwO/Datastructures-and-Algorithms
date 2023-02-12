def is_prime(num):
    for j in range(2, int(n**0.5)+3):
        if num % j == 0:
            return False
    return True

n = 600851475143
while True:
    for i in range(3, n//2+3):
        if n % i == 0:
            n //= i
            break
    if is_prime(n):
        break

print(n)
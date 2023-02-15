sieve = {}


def is_prime(num):
    for i in range(2, int(num**0.5+1)):
        if num % i == 0:
            return False
    return True

sol = 2
for j in range(3, 2*10**6, 2):
    if is_prime(j):
        sol += j

print(sol)
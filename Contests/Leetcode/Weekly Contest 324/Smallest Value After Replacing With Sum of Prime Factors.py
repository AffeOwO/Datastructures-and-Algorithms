class Solution:
    def smallestValue(self, n: int) -> int:
        def isprime(n):
            for i in range(2, int(n ** 0.5) + 1):
                if n % i == 0:
                    return False
            return True

        def get_factors(n):
            temp = []
            for i in range(2, n // 2 + 1):
                while n % i == 0:
                    temp.append(i)
                    n //= i
            return temp

        prev = 0
        while not isprime(n):
            factors = get_factors(n)
            n = sum(factors)
            if prev == n:
                break
            prev = n
        return n

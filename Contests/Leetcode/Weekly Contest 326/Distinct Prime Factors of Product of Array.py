class Solution:
    def distinctPrimeFactors(self, nums: List[int]) -> int:

        import math

        def prime_factors(n):
            factors = []
            while n % 2 == 0:
                factors.append(2)
                n = n / 2
            for i in range(3, int(math.sqrt(n)) + 1, 2):
                while n % i == 0:
                    factors.append(i)
                    n = n / i
            if n > 2:
                factors.append(n)
            return list(set(factors))

        sol = set()
        nums = set(nums)
        for i in nums:
            temp = prime_factors(i)
            for j in temp: sol.add(j)

        return len(sol)
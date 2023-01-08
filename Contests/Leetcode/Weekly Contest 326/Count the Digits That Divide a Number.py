class Solution:
    def countDigits(self, num: int) -> int:
        digits = [int(i) for i in str(num)]
        sol = 0
        for i in digits:
            if num%i==0: sol += 1
        return sol
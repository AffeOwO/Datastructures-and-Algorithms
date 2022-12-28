# base < 10
class Solution:
    def convertToBase(self, n: int, base: int):
        if n < 0: return '-' + self.convertToBase(-n)
        if n < base: return str(n)
        return self.convertToBase(n // base) + str(n % base)
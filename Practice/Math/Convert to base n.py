class Solution:
    def convertToBase7(self, n: int, base: int):
        if n < 0: return '-' + self.convertToBase7(-n)
        if n < base: return str(n)
        return self.convertToBase7(n // base) + str(n % base)
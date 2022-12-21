class Solution:
    def isPowerOfFour(self, num):
        return 0b1010101010101010101010101010101 & num == num > 0 == num & (num - 1)
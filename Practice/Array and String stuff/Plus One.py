class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits[-1] += 1

        for index, i in enumerate(digits[::-1]):
            index = (index + 1) * -1
            if digits[index] != 10:
                break
            digits[index] -= 10
            try:
                digits[index-1] += 1
            except IndexError:
                digits.insert(0, 1)
        return digits
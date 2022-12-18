class Solution:
    def rotate(self, A):
        A[:] = map(list, zip(*A[::-1]))
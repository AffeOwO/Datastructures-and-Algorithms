import math

n, m, a = map(int, input().split())  # n*m = fläche | a*a fläche von flagstone

len_squares = math.ceil(m / a)
len2_squares = math.ceil(n / a)
print(len_squares*len2_squares)

from math import acos, degrees
def law_of_cosines(a, b, c):
    cos_c = (a**2 + b**2 - c**2) / (2 * a * b)
    return degrees(acos(cos_c))
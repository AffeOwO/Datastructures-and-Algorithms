import math

k = int(input())

temp = 1
n = 1

while True:
    if temp % k == 0:
        print(n)
        exit()
    n += 1
    temp *= n

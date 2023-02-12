from math import lcm

sol = 1
for i in range(2, 21):
    sol = lcm(i, sol)
print(sol)
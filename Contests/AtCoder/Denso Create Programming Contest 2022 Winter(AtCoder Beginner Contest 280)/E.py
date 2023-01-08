import math

init_stamina, probab = map(int, input().split())

# 2 damaga with : P/100
# 1 damage with : 1 - P/100 = 100/100 - P/100

if probab == 100:
    print(math.ceil(init_stamina / 2))
    exit()

temp = 0

while init_stamina >= 1:
    pass

print(temp % 998244353)


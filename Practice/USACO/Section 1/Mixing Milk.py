"""
ID: yamato berner (affeowo1)
TASK: milk
LANG: PYTHON3
"""

fin = open("milk.in", "r").read().splitlines()
fout = open("milk.out", "w")

milk_needed, farmers = map(int, fin[0].split())
total_cost = 0

shops = []  # [price, available]
for i in range(farmers):
    shops.append(list(map(int, fin[i+1].split())))
shops = sorted(shops)

for i in shops:
    if milk_needed > i[1]:
        milk_needed -= i[1]
        total_cost += (i[0] * i[1])
    else:
        total_cost += (milk_needed * i[0])
        break
fout.write(f"{total_cost}\n")
fout.close()
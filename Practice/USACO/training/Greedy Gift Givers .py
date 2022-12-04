"""
ID: yamato berner (affeowo1)
TASK: gift1
LANG: PYTHON3
"""

fin = open("gift1.in", "r")
fout = open("gift1.out", "w")

fin = fin.readlines()
friends = {}
num_friends = int(fin[0])

for i in range(1, num_friends + 1):
    friends[fin[i][:-1]] = 0

fin = fin[num_friends + 1:]

while fin:
    gifter = fin[0][:-1]
    amount, people = map(int, fin[1].split())
    if amount == 0:
        fin = fin[2 + people:]
        continue
    if people == 0:
        friends[gifter] += amount
        fin = fin[2 + people:]
        continue
    friends[gifter] = friends[gifter] - amount + amount % people
    for i in range(2, people + 2):
        cur = fin[i]
        friends[cur[:-1]] += amount // people
    fin = fin[2 + people:]

for i in friends:
    fout.write(f"{i} {friends[i]}\n")
fout.close()
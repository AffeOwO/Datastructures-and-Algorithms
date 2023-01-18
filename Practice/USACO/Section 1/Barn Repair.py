"""
ID: yamato berner (affeowo1)
TASK: barn1
LANG: PYTHON3
"""

fin = open("barn1.in", "r").read().splitlines()
fout = open("barn1.out", "w")

M, S, C = map(int, fin[0].split())  # boards, stalls, cows
fin = sorted(map(int, fin[1:]))
stalls = [[fin[0]]]
print(fin)
cur = 1
for i in range(C-1):
    if fin[i+1] == stalls[-1][-1] + 1: stalls[-1].append(fin[i+1])
    else: stalls.append([fin[i+1]])
    cur += 1
differences = []
prev = stalls[0]
for i in stalls[1:]:
    differences.append(i[0]-prev[-1]-1)
    prev = i
differences = sorted(differences)
for i in range(len(stalls)-M):
    cur += differences[i]
fout.write(f"{cur}\n")
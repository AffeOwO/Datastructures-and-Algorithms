"""
ID: yamato berner (affeowo1)
TASK: milk2
LANG: PYTHON3
"""

fin = open("temp.in", "r")
fout = open("temp.out", "w")

fin = fin.readlines()
fin = fin[1:]

longest, longest_non = 0, 0
intervals = sorted([list(map(int, i.split())) for i in fin])

# ToDo: make it faster than O(n^2)
for i in intervals:
    start, end = i[0], i[1]
    for i2 in intervals:
        if start <= i2[0] and end >= i2[1]:
            i2[0] = start
            i2[1] = end
        elif start <= i2[0] <= end <= i2[1]:
            i2[0] = start
        elif i2[0] <= start <= i2[1] <= end:
            i2[1] = end

for index in range(len(intervals) - 1):
    if intervals[index+1][0] - intervals[index][1] > longest_non:
        longest_non = intervals[index+1][0] - intervals[index][1]
    if intervals[index][1] - intervals[index][0] > longest:
        longest = intervals[index][1] - intervals[index][0]
if intervals[-1][1] - intervals[-1][0] > longest:
    longest = intervals[-1][1] - intervals[-1][0]

fout.write(f"{longest} {longest_non}\n")
fout.close()
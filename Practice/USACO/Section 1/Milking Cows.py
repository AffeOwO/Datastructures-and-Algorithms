"""
ID: yamato berner (affeowo1)
TASK: milk2
LANG: PYTHON3
"""

fin = open("milk2.in", "r")
fout = open("milk2.out", "w")

fin = fin.readlines()[1:]
fin.sort(key=lambda x: list(map(int, x.split()))[0])
start, end = map(int, fin[0].split())
longest, non_longest = end - start, 0

for milking in fin:
    temp_start, temp_end = map(int, milking.split())
    if temp_start - end >= non_longest:
        non_longest = temp_start - end
    if start <= temp_start <= end:
        if end < temp_end:
            end = temp_end
    else:
        if end - start > longest:
            longest = end - start
        start, end = temp_start, temp_end

fout.write(f"{longest} {non_longest}\n")
fout.close()
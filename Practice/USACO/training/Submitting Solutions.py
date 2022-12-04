"""
ID: yamato berner (affeowo1)
TASK: test
LANG: PYTHON3
"""

fin = open("test.in", "r")
fout = open("test.out", "w")

fin = fin.readline()

num1, num2 = map(int, fin.split())

sumnum = num1 + num2

fout.write(f"{sumnum}\n")
fout.close()
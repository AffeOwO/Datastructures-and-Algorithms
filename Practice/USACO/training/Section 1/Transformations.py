"""
ID: yamato berner (affeowo1)
TASK: transform
LANG: PYTHON3
"""

fin = open("transform.in", "r")
fout = open("transform.out", "w")

fin = fin.readlines()
n = int(fin[0])
square_1 = [i.strip() for i in fin[1:n+1]]
square_2 = [i.strip() for i in fin[n+1:]]
transformations = 0

def rotate_90(matrix):
    temp = matrix[:]
    temp = list(map(lambda x: "".join(x), zip(*temp[::-1])))
    return temp

def rotate_180(matrix):
    temp = matrix[:]
    for index in range(len(temp)):
        temp[index] = temp[index][::-1]
    temp = temp[::-1]
    return temp

def rotate_270(matrix):
    temp = matrix[:]
    for i in range(3):
        temp = rotate_90(temp)
    return temp

def horizontal_reflection(matrix):
    temp = matrix[:]
    for index in range(len(temp)):
        temp[index] = temp[index][::-1]
    return  temp

# 1
if rotate_90(square_1) == square_2:
    fout.write("1\n")

# 2
elif rotate_180(square_1) == square_2:
    fout.write("2\n")

# 3
elif rotate_270(square_1) == square_2:
    fout.write("3\n")

# 4
elif horizontal_reflection(square_1) == square_2:
    fout.write("4\n")

# 5
elif rotate_90(horizontal_reflection(square_1)) == square_2 or rotate_180(horizontal_reflection(square_1)) == square_2 or rotate_270(horizontal_reflection(square_1)) == square_2:
    fout.write("5\n")

# 6
elif square_1 == square_2:
    fout.write("6\n")

# 7
else:
    fout.write("7\n")

fout.close()
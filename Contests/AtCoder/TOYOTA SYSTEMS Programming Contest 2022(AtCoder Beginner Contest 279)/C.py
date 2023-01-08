rows, columns = map(int, input().split())  # column -> / row |

matrix1 = []  # [#,.]
matrix2 = []

for i in range(rows):
    temp = input()
    matrix1.append([temp.count("#"), temp.count(".")])
for i in range(rows):
    temp = input()
    matrix2.append([temp.count("#"), temp.count(".")])

if matrix1 == matrix2:
    print("Yes")
else:
    print("No")
def beautiful(matrix):
    if matrix[0][0] < matrix[0][1] < matrix[1][1] and matrix[0][0] < matrix[1][0] < matrix[1][1]:
        return True
    return False

for _ in range(int(input())):
    matrix = [list(map(int, input().split())) for _ in range(2)]
    temp = 0
    if beautiful(matrix):
        print("Yes")
        temp = 1
    else:
        for i in range(3):

            matrix = [[matrix[1][0], matrix[0][0]], [matrix[1][1], matrix[0][1]]]
            if beautiful(matrix):
                print("Yes")
                temp = 1
                break

    if temp == 0: print("NO")


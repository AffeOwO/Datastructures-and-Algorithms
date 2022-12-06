my_matrix = []

for _ in range(5):
    my_matrix.append(list(input().replace(" ", "")))

for index in range(5):
    for index2 in range(5):
        if my_matrix[index][index2] == str(1):
            print(abs(index - 2) +  abs(index2 - 2))
            exit()

test_cases = int(input())

for i in range(test_cases):
    y_coord, x_coord = map(int, input().split())
    if y_coord < x_coord:
        if x_coord % 2 == 1:
            print(x_coord * x_coord - y_coord + 1)
        else:
            print((x_coord - 1) ** 2 + y_coord)
    else:
        if y_coord % 2 == 0:
            print(y_coord * y_coord - x_coord + 1)
        else:
            print((y_coord - 1) ** 2 + x_coord)


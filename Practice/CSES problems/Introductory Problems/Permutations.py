num = int(input())

if num in (2, 3):
    print("NO SOLUTION")
    exit()

elif num == 4:
    print(2, 4, 1, 3)

elif num % 2 == 0:
    temp1 = [i for i in range(1, num + 1) if i % 2 == 0]
    temp2 = [num - i for i in range(1, num + 1) if i % 2 == 1]
    print(*temp1[::-1], *temp2)
    exit()

else:
    temp1 = [i for i in range(1, num + 1) if i % 2 == 1]
    temp2 = [num - i for i in range(1, num + 1) if i % 2 == 1]
    print(*temp1[::-1], *temp2)

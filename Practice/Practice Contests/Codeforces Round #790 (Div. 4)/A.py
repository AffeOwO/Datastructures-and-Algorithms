for _ in range(int(input())):
    num = input()
    sum1 = int(num[0]) + int(num[1]) + int(num[2])
    sum2 = int(num[3]) + int(num[4]) + int(num[5])
    if sum1 == sum2: print("YES")
    else: print("NO")
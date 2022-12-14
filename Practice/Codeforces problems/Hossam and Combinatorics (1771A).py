for _ in range(int(input())):
    length = int(input())
    array = sorted(map(int, input().split()))

    if array[0] == array[-1]:
        print(length*(length-1))
        continue

    minimum = 0
    maximum = length-1

    while array[0]==array[minimum]:
        minimum+=1
    while array[-1] == array[maximum]:
        maximum-=1
    maximum = length-maximum-1

    print(2*minimum*maximum)
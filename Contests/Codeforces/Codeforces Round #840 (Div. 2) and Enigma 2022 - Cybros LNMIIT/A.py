for _ in range(int(input())):
    length = int(input())
    array = list(map(int, input().split()))

    if len(set(array)) == 1:
        print(array[0])

for _ in range(int(input())):
    n = int(input())
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))

    end1, end2 = [], []
    for index in range(n):
        if arr1[index] > arr2[index]:
            end1.append(arr1[index])
            end2.append(arr2[index])
        else:
            end2.append(arr1[index])
            end1.append(arr2[index])

    print(max(end1) * max(end2))
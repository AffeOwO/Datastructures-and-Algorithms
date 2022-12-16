for _ in range(int(input())):
    length = int(input())
    string = input()
    
    if length <= 2:
        print("No")
        continue

    for index in range(1, length):
        temp2 = string[index-1]+string[index]
        if temp2 in string[:index-1]:
            print("Yes")
            break
    else:
        print("No")
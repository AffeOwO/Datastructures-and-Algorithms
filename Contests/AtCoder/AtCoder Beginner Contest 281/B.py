string = input()

if len(string) != 8:
    print("No")
    exit()

if string[0].isalpha():
    if string[1:7].isnumeric() and string[1] != "0":
        if string[7].isalpha():
            print("Yes")
        else:
            print("No")
    else:
        print("No")
else:
    print("No")
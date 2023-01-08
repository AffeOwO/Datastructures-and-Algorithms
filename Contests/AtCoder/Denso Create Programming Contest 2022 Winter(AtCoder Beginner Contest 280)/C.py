str1 = input()
str2 = input()

if str1 == str2[:-1]:
    print(len(str2))
    exit()

for index in range(len(str2)):
    if str1[index] != str2[index]:
        print(index+1)
        exit()
str1 = input().lower()
str2 = input().lower()

if str1.lower() == str2.lower():
    print(0)
    exit()

for index in range(len(str1)):
    if str1[index] > str2[index]:
        print(1)
        exit()
    elif str1[index] < str2[index]:
        print(-1)
        exit()
string1 = input()
string2 = input()

if string1 == string2:
    print("Yes")
elif string2 in string1:
    print("Yes")
else:
    print("No")
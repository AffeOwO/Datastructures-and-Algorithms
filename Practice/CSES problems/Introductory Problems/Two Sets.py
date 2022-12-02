n = int(input())

temp = 0
for i in range(1, n+1):
    temp += i

if temp % 2 != 0:
    print("No")
    exit()


set1 = set()
set2 = set()

# ToDo: get the content of both sets

print("Yes")
print(len(set1))
print(set1)
print(len(set2))
print(set2)
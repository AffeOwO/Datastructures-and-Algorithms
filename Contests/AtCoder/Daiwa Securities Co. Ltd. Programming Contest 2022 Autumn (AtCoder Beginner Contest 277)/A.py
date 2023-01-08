# passed
length, gesucht = input().split()
string = list(input().split())

for index, i in enumerate(string):
    if int(i) == int(gesucht):
        print(index + 1)

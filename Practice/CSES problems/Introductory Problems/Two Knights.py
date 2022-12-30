xy = int(input())

for n in range(1, xy+1):
    print(int((n - 1)*(n + 4)*(n**2 - 3*n + 4)/2))
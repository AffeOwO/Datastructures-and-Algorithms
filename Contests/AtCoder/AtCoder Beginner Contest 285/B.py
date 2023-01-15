n = int(input())
s = input()

for i in range(1, n):
    temp = s[i-1:]
    sol = 0
    for index in range(n-i):
        if s[index]== s[index+i]: break
        sol += 1
    print(sol)
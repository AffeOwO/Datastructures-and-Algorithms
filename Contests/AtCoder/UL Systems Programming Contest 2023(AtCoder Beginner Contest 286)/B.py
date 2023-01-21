n = int(input())
string = input()
sol = ""

for index, i in enumerate(string):
    if index == n-1:
        sol += i
    elif i == "n" and string[index+1] == "a":
        sol += "ny"
    else:
        sol += i

print(sol)
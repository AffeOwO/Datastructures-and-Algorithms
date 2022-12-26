string = input().lower()
sol = ""

for i in string:
    if i not in "aeiouy":
        sol += f".{i}"

print(sol)
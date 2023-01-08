length = int(input())
string = list(input())

enclosed = False
for index, i in enumerate(string):
    if i == "," and not enclosed:
        string[index] = "."
    elif i == '"':
        enclosed = True if not enclosed else False

print("".join(string))
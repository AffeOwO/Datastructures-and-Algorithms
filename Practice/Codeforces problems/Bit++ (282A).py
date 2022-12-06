lines = int(input())

val = 0
for _ in range(lines):
    op = input()
    if op[1] == "+":
        val += 1
    else:
        val -= 1
print(val)
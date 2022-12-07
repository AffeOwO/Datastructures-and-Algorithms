test_cases = int(input())

for _ in range(test_cases):
    columns = int(input())
    grid = [input(), input()]

    for i in range(columns):

        if grid[0][i] == "R" and grid[1][i] in ("G", "B"):
            print("NO")
            break
        elif grid[0][i] in ("G", "B") and grid[1][i] == "R":
            print("NO")
            break
    else:
        print("YES")
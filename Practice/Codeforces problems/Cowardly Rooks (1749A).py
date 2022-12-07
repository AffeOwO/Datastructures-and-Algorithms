test_cases = int(input())

for _ in range(test_cases):
    size, rooks = map(int, input().split())
    xs = []
    ys = []
    for _ in range(rooks):
        x, y = map(int, input().split())
        xs.append(x)
        ys.append(y)
    if len(set(xs)) != len(set(ys)) or size == rooks:
        print("NO")
    else:
        print("YES")
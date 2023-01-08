for _ in range(int(input())):
    cells, colors, consecutive = map(int, input().split())  # num of cells, num of colors, consecutive
    times_used = sorted(map(int, input().split()))
    max_times = times_used[-1]


    if consecutive == 1:
        print("YES")
    elif consecutive > colors:
        print("NO")
    elif max_times > cells / consecutive:
        print("NO")
    else:
        print("YES")


A, B = map(int, input().split())  # A = Strecke | B = gravity

time = 0
g = 1
cur_shortest = -1
temp2 = -1
while True:
    temp = B * time + (A / (g ** 0.5))
    g += (A//4)
    time += (A//4)
    if temp < cur_shortest or cur_shortest == -1:
        cur_shortest = temp
    elif cur_shortest <= temp <= temp2 != -1:
        g = g - (A//4) - 1
        time = temp - (A//4) - 1
    else:
        print("{:.10f}".format(cur_shortest))
        break
    temp2 = temp
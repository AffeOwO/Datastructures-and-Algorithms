tests = int(input())
for i in range(tests):
    space = list(map(int, input().split()))
    table1 = list(map(int, input().split()))
    table2 = list(map(int, input().split()))
    tb1szx = table1[2] - table1[0]
    tb1szy = table1[3] - table1[1]
    lowest = float('inf')
    if tb1szx + table2[0] <= space[0]:
        lowest = min(max(0, table2[0] - table1[0]),  max(0, table1[2] - (space[0] - table2[0])))
    if tb1szy + table2[1] <= space[1]:
        lowest = min(lowest, max(0, table2[1] - table1[1]),  max(0, table1[3] - (space[1] - table2[1])))
    print(lowest if lowest < float('inf') else -1)
for _ in range(int(input())):
    n = int(input())
    wheels = list(map(int, input().split()))
    for i in range(n):
        moves = input().split()
        for j in moves[1]:
            if j == "D":
                wheels[i] += 1
            else:
                wheels[i] -= 1
        wheels[i] %= 10
        if wheels[i] < 0:
            wheels[i] = 10 + wheels[i]
    print(*wheels)

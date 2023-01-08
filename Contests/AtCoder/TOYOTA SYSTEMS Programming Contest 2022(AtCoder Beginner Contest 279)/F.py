N, Q = map(int, input().split())  # N = boxes | Q = operations

boxes = dict.fromkeys((i for i in range(1, N+1)), -1)
balls = dict.fromkeys((i for i in range(1, N+1)), )

for i in range(Q):
    operation = list(map(int, input().split()))
    if operation[0] == 1:
        if boxes[operation[1]] == -1: boxes[operation[1]] = str(operation[1])
        if boxes[operation[2]] == -1: boxes[operation[2]] = str(operation[2])

        boxes[operation[1]] += f"|{boxes[operation[2]]}|"
        boxes[operation[2]] = ""
    print(boxes)
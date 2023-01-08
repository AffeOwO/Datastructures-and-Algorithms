length = int(input())
sequence = list(map(int, input().split()))
Q = int(input())

for _ in range(Q):
    query = list(map(int, input().split()))
    if query[0] == 2:
        print(sequence[query[1]-1])
    elif query[0] == 1:
        sequence[query[1]-1] = query[2]
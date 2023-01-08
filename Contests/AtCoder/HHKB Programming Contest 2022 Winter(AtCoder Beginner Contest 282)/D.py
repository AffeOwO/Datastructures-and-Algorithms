N, M = map(int, input().split())  # vertex | edges

connections = []
for _ in range(M):
    connections.append(list(map(int, input().split())))

print(connections)
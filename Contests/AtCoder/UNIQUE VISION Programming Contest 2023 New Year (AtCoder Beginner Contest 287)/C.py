import sys
sys.setrecursionlimit(10**9)

def sol(n, edges):
    graph = {}
    for u, w in edges:
        if u not in graph: graph[u] = []
        if w not in graph: graph[w] = []
        graph[u].append(w)
        graph[w].append(u)
    visited = [False for _ in range(n+1)]
    def dfs(v, parent):
        visited[v] = True
        for neighbor in graph[v]:
            if not visited[neighbor]:
                if dfs(neighbor, v): return True
            elif neighbor != parent: return True
        return False

    for w in range(1, n + 1):
        if not visited[w]:
            if dfs(w, -1): return False
    for w in range(1, n + 1):
        if not visited[w]: return False
    return True

N, M = map(int, input().split())
EDGES = []
used = set()
for _ in range(M):
    temp = tuple(map(int, input().split()))
    used.add(temp[0])
    used.add(temp[1])
    EDGES.append(temp)
if len(used) != N:
    print("No")
else:
    if sol(N, EDGES): print("Yes")
    else: print("No")
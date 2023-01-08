vertices, edges = map(int, input().split())
graphs = {}


for _ in range(edges):
    start, end = map(int, input().split())
    if start not in graphs:
        graphs[start] = set()

from heapq import heappop, heappush


def shortest_path(grid, start, ends, direction):
    next_node = []
    visited = set()
    heappush(next_node, (0, start))
    while True:
        steps, (x, y) = heappop(next_node)
        if (x, y) in visited:
            continue
        if (x, y) in ends:
            return steps
        visited.add((x, y))
        for nx, ny in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
            if 0 <= ny < len(grid):
                if 0 <= nx < len(grid[ny]):
                    if (ord(grid[ny][nx]) - ord(grid[y][x])) * direction <= 1:
                        heappush(next_node, (steps + 1, (nx, ny)))


with open("input.in") as puzzle_input:
    height_map = [list(row) for row in puzzle_input.read().splitlines()]
    starts = [None, None]
    ends = [set(), set()]
    for y, line in enumerate(height_map):
        for x, height in enumerate(line):
            if height == "S":
                height_map[y][x] = "a"
                starts[0] = (x, y)
            if height == "E":
                height_map[y][x] = "z"
                starts[1] = (x, y)
                ends[0].add((x, y))
            if height_map[y][x] == "a":
                ends[1].add((x, y))

# Part one
print(shortest_path(height_map, starts[0], ends[0], 1))
# Part two
print(shortest_path(height_map, starts[1], ends[1], -1))
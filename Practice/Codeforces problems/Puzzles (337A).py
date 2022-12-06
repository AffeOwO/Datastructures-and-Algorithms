num_students, num_puzzles = map(int, input().split())
puzzles = sorted(list(map(int, input().split())))

cur = -1
for index in range(num_puzzles - num_students + 1):
    if puzzles[index+num_students-1] - puzzles[index] < cur or cur == -1:
        cur = puzzles[index+num_students-1] - puzzles[index]

print(cur)
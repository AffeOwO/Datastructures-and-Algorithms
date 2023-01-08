with open("input.in", "r", encoding="utf-8") as file:
    file = file.readlines()

    # part 1

    # first = x | seconds = y
    cur_head = [0, 0]
    cur_tail = [0, 0]

    visited = set()
    visited.add(tuple(cur_tail))

    for i in file:
        direction, value = i.split()
        value = int(value)


        if direction == "U":
            for o in range(value):
                cur_head[1] += 1
                if abs(cur_head[1] - cur_tail[1]) > 1 and cur_head[0] == cur_tail[0]:
                    cur_tail[1] += 1
                    visited.add(tuple(cur_tail))
                elif abs(cur_head[1] - cur_tail[1]) > 1 and cur_head[0] != cur_tail[0]:
                    cur_tail[1] += 1
                    if cur_head[0] > cur_tail[0]:
                        cur_tail[0] += 1
                    else:
                        cur_tail[0] -= 1
                    visited.add(tuple(cur_tail))
        elif direction == "R":
            for o in range(value):
                cur_head[0] += 1
                if abs(cur_head[0] - cur_tail[0]) > 1 and cur_head[1] == cur_tail[1]:
                    cur_tail[0] += 1
                    visited.add(tuple(cur_tail))
                elif abs(cur_head[0] - cur_tail[0]) > 1 and cur_head[1] != cur_tail[1]:
                    cur_tail[0] += 1
                    if cur_head[1] > cur_tail[1]:
                        cur_tail[1] += 1
                    else:
                        cur_tail[1] -= 1
                    visited.add(tuple(cur_tail))

        elif direction == "D":
            for o in range(value):
                cur_head[1] -= 1
                if abs(cur_head[1] - cur_tail[1]) > 1 and cur_head[0] == cur_tail[0]:
                    cur_tail[1] -= 1
                    visited.add(tuple(cur_tail))
                elif abs(cur_head[1] - cur_tail[1]) > 1 and cur_head[0] != cur_tail[0]:
                    cur_tail[1] -= 1
                    if cur_head[0] > cur_tail[0]:
                        cur_tail[0] += 1
                    else:
                        cur_tail[0] -= 1
                    visited.add(tuple(cur_tail))
        elif direction == "L":
            for o in range(value):
                cur_head[0] -= 1
                if abs(cur_head[0] - cur_tail[0]) > 1 and cur_head[1] == cur_tail[1]:
                    cur_tail[0] -= 1
                    visited.add(tuple(cur_tail))
                elif abs(cur_head[0] - cur_tail[0]) > 1 and cur_head[1] != cur_tail[1]:
                    cur_tail[0] -= 1
                    if cur_head[1] > cur_tail[1]:
                        cur_tail[1] += 1
                    else:
                        cur_tail[1] -= 1
                    visited.add(tuple(cur_tail))
    print(len(visited))

    # part 2
    tail_locs = set()
    knots = [(0, 0) for _ in range(10)]

    def make_1(x):
        if x > 0:
            return 1
        if x < 0:
            return -1
        return 0
    def update_tail(head, tail):
        if is_touching(head, tail):
            return tail
        vect = make_1(head[0] - tail[0]), make_1(head[1] - tail[1])
        return tail[0] + vect[0], tail[1] + vect[1]
    def is_touching(head, tail):
        return head[0] - 1 <= tail[0] <= head[0] + 1 and head[1] - 1 <= tail[1] <= head[1] + 1
    def move_head(head, direction_2):
        x, y = head

        if direction_2 == 'U':
            y += 1
        elif direction_2 == 'D':
            y -= 1
        elif direction_2 == 'L':
            x -= 1
        else:
            x += 1

        return x, y

    for i in file:
        direction, repeats = i.split()
        repeats = int(repeats)

        for _ in range(repeats):
            knots[0] = move_head(knots[0], direction)

            for n, k in enumerate(knots):
                if n == 0:
                    knots[n] = k
                    continue
                knots[n] = update_tail(knots[n - 1], k)

            tail_locs.add(knots[-1])
    print(len(tail_locs))

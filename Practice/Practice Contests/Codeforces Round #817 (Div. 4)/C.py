test_cases = int(input())

for _ in range(test_cases):
    words_per = int(input())  # 3 guys
    words = {}
    scores = [0,0,0]

    for i in range(0, 3):
        temp = input().split()
        for o in temp:
            if o not in words.keys():
                words[o] = [i]
            else:
                words[o].append(i)
    for i in words:
        if len(words[i]) == 1:
            scores[words[i][0]] += 3
        elif len(words[i]) == 2:
            scores[words[i][0]] += 1
            scores[words[i][1]] += 1

    print(*scores)
N, M = map(int, input().split())  # partis, problems
sol = 0
idk = []
for _ in range(N):
    idk.append(list(input()))

for index1, i in enumerate(idk):
    for index2, j in enumerate(idk):
        if index1 == index2:
            continue
        if i.count("o") == M or j.count("o") == M:
            sol += 1
            continue
        for index in range(len(i)):
            if i[index] == "o" or j[index] == "o":
                continue
            break
        else:
            sol += 1



print(sol//2)
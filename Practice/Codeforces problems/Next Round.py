n, k = map(int, input().split())
scores = list(map(int, input().split()))

advance = 0
for i in scores:
    if i < scores[k-1] or i < 1:
        break
    advance += 1

print(advance)
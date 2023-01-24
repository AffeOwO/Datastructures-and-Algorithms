with open('diamond.in') as fin:
	n, k = map(int, fin.readline().split())
	diamonds = [int(fin.readline()) for _ in range(n)]

most = 0
for x in diamonds:
	fittable = 0
	for y in diamonds:
		if x <= y <= x + k:
			fittable += 1

	most = max(most, fittable)

print(most, file=open('diamond.out', 'w'))
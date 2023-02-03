with open('triangles.in') as read:
	n = int(read.readline())
	x = []
	y = []
	for _ in range(n):
		x_i, y_i = [int(i) for i in read.readline().split()]
		x.append(x_i)
		y.append(y_i)

max_area = 0
for i in range(n):
	for j in range(n):
		for k in range(n):
			if y[i] == y[j] and x[i] == x[k]:
				area = abs((x[j] - x[i]) * (y[k] - y[i]))
				max_area = max(max_area, area)

print(max_area, file=open('triangles.out', 'w'))
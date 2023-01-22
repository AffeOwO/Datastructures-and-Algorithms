n = int(input())
ncows = []
ecows = []
for i in range(n):
	dir, x, y = input().split()
	if dir == 'N':
		ncows.append((i, int(x), int(y)))
	elif dir == 'E':
		ecows.append((i, int(x), int(y)))
ncows.sort(key = lambda cow: cow[1])
ecows.sort(key = lambda cow: cow[2])
res = [float('inf')]*n
for c1 in ncows:
	for c2 in ecows:
		a,b = c1[1],c1[2]
		c,d = c2[1],c2[2]
		if a-c < 0 or d-b < 0 or a-c == d-b: continue
		if a-c > d-b:
			if a-c > res[c1[0]]:continue
			res[c2[0]] = min(res[c2[0]], a-c)
		else:
			if d-b > res[c2[0]]:continue
			res[c1[0]] = min(res[c1[0]], d-b)

for j in range(n):
	print("Infinity" if res[j] == float('inf') else res[j])
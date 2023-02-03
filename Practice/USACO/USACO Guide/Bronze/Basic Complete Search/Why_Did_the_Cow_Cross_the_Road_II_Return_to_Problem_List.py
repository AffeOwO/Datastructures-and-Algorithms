with open('circlecross.in') as read:
	crossings = read.readline().strip()

start = [-1 for _ in range(26)]
end = [-1 for _ in range(26)]
for v, c in enumerate(crossings):
	c_id = ord(c) - ord('A')
	if start[c_id] == -1:
		start[c_id] = v
	else:
		end[c_id] = v

crossing_pairs = 0
for i in range(26):
	for j in range(26):
		crossing_pairs += (start[i] < start[j] < end[i] < end[j])

print(crossing_pairs, file=open('circlecross.out', 'w'))
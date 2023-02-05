animals = []
with open('guess.in') as read:
	animal_num = int(read.readline())
	for _ in range(animal_num):
		line = read.readline().split()
		# We don't care about the 1st or 2nd token.
		animals.append(set(line[2:]))

max_yes = 0
for a1 in range(animal_num):
	for a2 in range(a1 + 1, animal_num):
		max_yes = max(max_yes, len(animals[a1].intersection(animals[a2])) + 1)

print(max_yes, file=open('guess.out', 'w'))
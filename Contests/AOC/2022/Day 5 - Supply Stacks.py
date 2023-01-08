containers = {}
containers2 = {}

with open("input.in", "r", encoding="utf-8") as file:
    file = file.readlines()

    # get amount of stacks without looking at the file b4 and only knowing the file scheme
    for index in range(len(file)):
        if file[index].split()[0].isnumeric():
            temp = index
            for i in file[index].split():
                containers[i] = []
                containers2[i] = []
            break

    # assign containers to correct stack in start position
    for layer in range(temp - 1, -1, -1):
        for index, char in enumerate(file[layer]):
            if index % 2 == 1 and char != " " and char != "\n":
                containers[str(index // 4 + 1)].append(char)
                containers2[str(index // 4 + 1)].append(char)
    file = file[temp+2:]

    for operation in file:
        _, amount, _, prev, _, after = operation.split()
        amount = int(amount)
        for i in range(amount):
            temp = containers[prev].pop()
            containers[after].append(temp)
        containers2[after] += containers2[prev][-amount:]
        containers2[prev] = containers2[prev][:-amount]

    # outputting solution for task 1
    for stack in containers:
        print(containers[stack][-1], end="")

    print()

    # output for task 2
    for stack in containers2:
        print(containers2[stack][-1], end="")
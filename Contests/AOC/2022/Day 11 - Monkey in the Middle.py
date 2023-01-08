# part 1
with open("input.in", "r", encoding="utf-8") as file:
    file = file.readlines()

    monkeys = dict.fromkeys((f"monkey{i}" for i in range(8)), [])

    # monkey num
    monkey_num = (len(file) + 1) // 7

    # index = monkey number(0-7)
    items = [[] for i in range(monkey_num)]  # lists with worry level of items
    operations = []  # new = string content
    actions = ["" for i in range(monkey_num)]  # string: 1: divisor 2: if true monkey 3: if false monkey
    cur_score = [0 for i in range(monkey_num)]  # items inspected

    # get starting stuff
    temp = 0
    temp_2 = 0
    for index, i in enumerate(file):
        if "Starting" in i:
            temp_list = i.replace(",", "").split()
            for o in temp_list:
                if o.isnumeric():
                    items[temp].append(int(o))
            temp += 1

        elif "Operation" in i:
            _, operation = i.split("=")
            operations.append(operation.strip())

        elif "Test:" in i:
            for p in range(3):
                temp_list = file[index+p].split()
                actions[temp_2] += f"{temp_list[-1]} "
            temp_2 += 1

    for _ in range(20):
        for i in range(monkey_num):
            divisor, if_true, if_false = map(int, actions[i].split())

            cur_score[i] += len(items[i])
            for index, item in enumerate(items[i]):
                temp = operations[i].replace("old", str(item))
                if "*" in temp:
                    int1, int2 = map(int, temp.split("*"))
                    items[i][index] = int1 * int2
                else:
                    int1, int2 = map(int, temp.split("+"))
                    items[i][index] = int1 + int2

                items[i][index] //= 3

                if items[i][index] % divisor == 0:
                    items[if_true].append(items[i][index])
                else:
                    items[if_false].append(items[i][index])
            items[i] = []

    cur_score = sorted(cur_score)
    print(cur_score[-1] * cur_score[-2])



# part 2
# extremely extremely extremely**extremely slow
from math import gcd

with open("input.in", "r", encoding="utf-8") as file:
    file = file.readlines()

    monkeys = dict.fromkeys((f"monkey{i}" for i in range(8)), [])

    # monkey num
    monkey_num = (len(file) + 1) // 7

    # index = monkey number(0-7)
    items = [[] for i in range(monkey_num)]  # lists with worry level of items
    operations = []  # new = string content
    actions = ["" for i in range(monkey_num)]  # string: 1: divisor 2: if true monkey 3: if false monkey
    cur_score = [0 for i in range(monkey_num)]  # items inspected

    # get starting stuff
    temp = 0
    temp_2 = 0
    for index, i in enumerate(file):
        if "Starting" in i:
            temp_list = i.replace(",", "").split()
            for o in temp_list:
                if o.isnumeric():
                    items[temp].append(int(o))
            temp += 1

        elif "Operation" in i:
            _, operation = i.split("=")
            operations.append(operation.strip())

        elif "Test:" in i:
            for p in range(3):
                temp_list = file[index+p].split()
                actions[temp_2] += f"{temp_list[-1]} "
            temp_2 += 1

    divisors = [list(map(int, i.split()))[0] for i in actions]
    remainder = divisors[0]
    for index in range(1, len(divisors)):
        remainder = remainder*divisors[index] // gcd(remainder, divisors[index])

    temp = dict.fromkeys(i for i in range(8))
    for index in range(len(temp)):
        temp[index] = list(map(int, actions[index].split()))

    for _ in range(10000):
        print(_)
        for i in range(monkey_num):
            divisor, if_true, if_false = temp[i]

            cur_score[i] += len(items[i])
            for index, item in enumerate(items[i]):
                old = item
                items[i][index] = eval(operations[i])

                if items[i][index] % remainder == 0:
                    items[i][index] = 0

                if items[i][index] % divisor == 0:
                    items[if_true].append(items[i][index])
                else:
                    items[if_false].append(items[i][index])
            items[i] = []

    cur_score = sorted(cur_score)
    print(cur_score[-1] * cur_score[-2])

test_cases = int(input())

for _ in range(test_cases):
    n, a, b = map(int, input().split())  # price, 1gold -> a silver, b silver -> 1gold
    quests = 0  # 1 quest -> 1gold

    if a > b:
        print(1)
    else:
        temp = n // a
        if n % a != 0:
            temp += 1
        print(temp)

test_cases = int(input())

for _ in range(test_cases):
    string = input()
    for i in string[::-1]:
        string += i
    print(string)
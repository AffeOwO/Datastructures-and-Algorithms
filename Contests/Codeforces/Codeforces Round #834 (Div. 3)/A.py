# correct
test_cases = int(input())
yesss = 20 * "Yes"

for i in range(test_cases):
    case = input()
    if case not in yesss:
        print("No")
    else:
        print("Yes")
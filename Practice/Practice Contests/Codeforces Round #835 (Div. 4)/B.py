alphabet = list("abcdefghijklmnopqrstuvwxyz")

test_cases = int(input())

for i in range(test_cases):
    _ = int(input())
    string = input()
    print(alphabet.index(max(string))+1)
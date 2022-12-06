test_cases = int(input())

for _ in range(test_cases):
    word_len = int(input())
    word = input()
    temp = 1

    if word_len % 3 == 2:
        print("NO")
        continue

    for i in range(word_len // 3):
        if word[temp] != word[temp+1]:
            print("NO")
            break
        temp += 3
    else:
        print("YES")

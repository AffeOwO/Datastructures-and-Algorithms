for _ in range(int(input())):
    n = input()
    pi = "3141592653589793238462643383279"
    correct = 0
    for index, i in enumerate(n):
        if i == pi[index]: correct += 1
        else: break

    print(correct)
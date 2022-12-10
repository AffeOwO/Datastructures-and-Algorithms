test_cases = int(input())

for _ in range(test_cases):
    n = int(input())

    if n % 2 == 1:
        print(f"{n} "*n)
    else:
        print("1", "2 " * (n-2) + "3")
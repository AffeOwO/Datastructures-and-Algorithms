test_cases = int(input())

for _ in range(test_cases):
    str_len = int(input())
    val = input()
    if sorted(set(val)) != sorted(list("Timur")) or str_len != 5:
        print("No")
        continue
    print("YES")
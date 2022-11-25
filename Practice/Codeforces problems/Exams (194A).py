n, k = map(int, input().split())  # n = exam numb | k = sum of all exams
print(max(n*3-k, 0))

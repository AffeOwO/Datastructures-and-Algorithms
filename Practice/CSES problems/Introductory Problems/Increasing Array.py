_ = input()
arr = list(map(int, input().split()))
steps = 0
for index, i in enumerate(arr):
    if index - 1 >= 0:
        if arr[index] < arr[index-1]:
            steps = steps + arr[index - 1] - arr[index]
            arr[index] = arr[index] + arr[index-1] - arr[index]
print(steps)
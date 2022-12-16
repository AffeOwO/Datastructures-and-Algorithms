def ternarySearch(arr, x):
    (left, right) = (0, len(arr) - 1)

    while left <= right:

        left_mid = (2*left + right) // 3
        right_mid = (left + 2*right) // 3

        if arr[left_mid] == x:
            return left_mid
        elif arr[right_mid] == x:
            return right_mid
        elif arr[left_mid] > x:
            right = left_mid - 1
        elif arr[right_mid] < x:
            left = right_mid + 1
        else:
            left = left_mid + 1
            right = right_mid - 1

    return -1
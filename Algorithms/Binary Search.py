def binary_search(array, value):
    start = 0
    end = len(array) - 1

    while start <= end:
        mid = start + (end - start) // 2
        if value == array[mid]:
            return mid
        elif value < array[mid]:
            end = mid - 1
        else:
            start = mid + 1

    # if not in array
    return -1


if __name__ == "__main__":
    print(binary_search([1, 3, 9, 10, 11, 15, 19, 29], 11))

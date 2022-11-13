def binary_search(array: list, value) -> int:
    start = 0
    end = len(array) - 1

    while start <= end:
        mid = start + (end - start) // 2
        # print(mid, start, end)  # DEBUGGING
        if value == array[mid]:
            return mid
        elif value < array[mid]:
            end = mid - 1
        else:
            start = mid + 1

    # if not in array
    return -1


def recursive_binary_search(array: list, value, start: int, end: int):

    if end < start:
        return -1

    mid = start + (end - start) // 2
    # print(mid, start, end)  # DEBUGGING
    if value == array[mid]:
        return mid
    elif value < array[mid]:
        end = mid - 1
    else:
        start = mid + 1

    return recursive_binary_search(array, value, start, end)


if __name__ == "__main__":
    temp = [1, 3, 9, 10, 11, 13, 15, 19, 29]
    print(binary_search(temp, 13))
    print()
    print(recursive_binary_search(temp, 13, 0, len(temp) - 1))

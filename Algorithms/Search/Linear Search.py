# O(n)
def linear_search(array: list, value) -> int:
    for index, i in enumerate(array):
        if i == value:
            return index
    return -1


if __name__ == "__main__":
    arr = [1, 1, 3, 4, 6, 6, 21, 42, 63, 122, 213]
    print(linear_search(arr, 3))

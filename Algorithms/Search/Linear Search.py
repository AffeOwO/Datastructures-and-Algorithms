# O(n)
def linear_search(array: list, value) -> int:
    for index, i in enumerate(array):
        if i == value:
            return index
    return -1


if __name__ == "__main__":
    pass

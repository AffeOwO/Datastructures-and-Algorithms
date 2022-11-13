def linear_search(array, value):
    for index, i in enumerate(array):
        if i == value:
            return index
    return -1
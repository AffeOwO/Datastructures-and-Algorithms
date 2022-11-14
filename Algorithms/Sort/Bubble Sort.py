# O(n^2)
def bubble_sort(array: list):
    length = len(array) - 1
    for o in range(length):
        for i in range(length - o):
            if array[i] > array[i + 1]:
                array[i], array[i + 1] = array[i + 1], array[i]
    return array


if __name__ == "__main__":
    print(bubble_sort([9-i for i in range(10)]))
    # Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

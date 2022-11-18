# O(n*log(n)), but worst case is O(n^2)
def quick_sort(array):
    sort(array, 0, len(array) - 1)
    return array


def sort(array, lo, hi):
    if lo < hi:
        p = partition(array, lo, hi)
        sort(array, lo, p - 1)
        sort(array, p + 1, hi)


def partition(array, lo, hi):
    pivot = array[hi]
    i = lo
    for j in range(lo, hi):
        if array[j] < pivot:
            array[i], array[j] = array[j], array[i]
            i += 1
    array[i], array[hi] = array[hi], array[i]
    return i


if __name__ == "__main__":
    arr = [9 - i for i in range(10)]
    print(quick_sort(arr))
    print(quick_sort([87, 68, 62, 19, 90, 99, 77, 38, 37, 43, 66, 42, 14, 30, 57, 95, 67, 53, 76, 97, 75, 1, 15, 7, 100]))

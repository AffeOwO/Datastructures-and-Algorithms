# O(n*log(n))
def merge_sort(array: list):
    if len(array) > 1:
        # r = place where array is divided
        r = len(array) // 2
        left = array[:r]
        right = array[r:]

        merge_sort(left)
        merge_sort(right)

        i = j = k = 0

        while i < len(left) and j < len(right):
            if left[i] < right[i]:
                array[k] = left[i]
                i += 1
            else:
                array[k] = right[j]
                j += 1
            k += 1

        while i < len(left):
            array[k] = left[i]
            i += 1
            k += 1
        while j < len(right):
            array[k] = right[j]
            j += 1
            k += 1
        return array


if __name__ == "__main__":
    array = [9 - i for i in range(10)]
    print(merge_sort(array))

# O(n*log(n))
def merge(left, right):
    if not len(left) or not len(right):
        return left or right
    result = []
    i, j = 0, 0
    while len(result) < len(left) + len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
        if i == len(left) or j == len(right):
            result.extend(left[i:] or right[j:])
            break
    return result


def merge_sort(array):
    if len(array) < 2:
        return array
    middle = int(len(array) / 2)
    left = merge_sort(array[:middle])
    right = merge_sort(array[middle:])
    return merge(left, right)


if __name__ == "__main__":
    arr = [9 - i for i in range(10)]
    print(merge_sort(arr))
    arr2 = [87, 68, 62, 19, 90, 99, 77, 38, 37, 43, 66, 42, 14, 30, 57, 95, 67, 53, 76, 97, 75, 1, 15, 7, 100]
    print(merge_sort(arr2))
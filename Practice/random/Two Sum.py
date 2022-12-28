def hash_approach(nums: list, target: int) -> list:
    hashy = {}
    for index, i in enumerate(nums):
        if i in hashy:
            return [hashy[i], index]
        hashy[target-i] = index

def two_pointer_approach(nums: list, target: int) -> list:
    for index, i in enumerate(nums[:-1]):
        for index2, j in enumerate(nums[index+1:]):
            if i + j == target:
                return [index, index+index2+1]


if __name__ == "__main__":
    print(hash_approach([1, 2, 3, 5], 7))
    print(two_pointer_approach([1, 2, 3, 5], 7))
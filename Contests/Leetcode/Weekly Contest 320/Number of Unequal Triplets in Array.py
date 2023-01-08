class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        triplets = 0
        for index, i in enumerate(nums):
            for index2, i2 in enumerate(nums):
                for index3, i3 in enumerate(nums):
                    if i != i2 and i != i3 and i2 != i3 and index < index2< index3:
                        triplets +=1
        return triplets
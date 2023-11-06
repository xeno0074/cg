from typing import List


def listToStr(ls):
    string = ''
    for item in ls:
        string += str(item)

    return string


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        h = {}

        nums.sort()

        for i in range(n):
            for j in range(i + 1, n):
                remains = target - nums[i] - nums[j]
                l = j + 1
                r = n - 1
                while l < r:
                    quad = []
                    sum = nums[l] + nums[r]
                    if sum < remains:
                        l += 1
                    if sum > remains:
                        r -= 1
                    if sum == remains:
                        quad += [nums[i], nums[j], nums[l], nums[r]]
                        l += 1
                        r -= 1
                    if quad:
                        h[listToStr(quad)] = quad

        return list(h.values())


sol = Solution()

nums = [1, 0, -1, 0, -2, 2]
target = 0
print(sol.fourSum(nums, target))

nums = [2, 2, 2, 2, 2]
target = 8
print(sol.fourSum(nums, target))

nums = [-2, -1, -1, 1, 1, 2, 2]
target = 0
print(sol.fourSum(nums, target))

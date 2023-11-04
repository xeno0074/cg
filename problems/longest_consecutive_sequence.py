# https://leetcode.com/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-interview-150

from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        maxCount = 0
        mp = {}  # key -> [count, start_range, end_range]
        for x in nums:
            if x in mp:
                continue

            l = x - 1
            r = x + 1
            count = 1
            start = x
            end = x

            if l in mp:
                start = mp[l][1]
                count += mp[start][0]

            if r in mp:
                end = mp[r][-1]
                count += mp[end][0]

            mp[x] = [None] * 3

            mp[start][0] = count
            mp[start][-1] = end

            mp[end][0] = count
            mp[end][1] = start

            maxCount = max(maxCount, count)

        return maxCount


def main():
    v1 = [100, 4, 200, 1, 3, 2]
    v2 = [100, 4, 200, 1, 3, 2, 6, 0, 5]
    v3 = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]

    solution = Solution()
    print(solution.longestConsecutive(v3))


main()

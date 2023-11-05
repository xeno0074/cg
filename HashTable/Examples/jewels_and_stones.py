# https://leetcode.com/explore/learn/card/hash-table/187/conclusion-hash-table/1136/


class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        jewelsSet = set()

        for jewel in jewels:
            jewelsSet.add(jewel)

        count = 0

        for stone in stones:
            if stone in jewelsSet:
                count += 1

        return count


# Test ----------------------------
jewels = "aA"
stones = "aAAbbbb"

sol = Solution()

print(sol.numJewelsInStones(jewels, stones))

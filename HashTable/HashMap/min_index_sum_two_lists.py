# https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1177/

import sys


def findStrings(l1, l2):
    minimum = sys.maxsize
    strList = []
    h = {}
    for i in range(len(l1)):
        h[l1[i]] = i

    for i in range(len(l2)):
        if l2[i] in h:  # common string
            if (i + h[l2[i]]) < minimum:
                minimum = i + h[l2[i]]
                strList = [l2[i]]
            elif (i + h[l2[i]]) == minimum:
                strList.append(l2[i])

    return strList


class Solution:
    def findRestaurant(self, list1: [str], list2: [str]) -> [str]:
        return findStrings(list1, list2)


list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]
list2 = ["KFC", "Shogun", "Burger King"]

solution = Solution()
print(solution.findRestaurant(list1, list2))

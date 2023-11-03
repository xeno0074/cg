# https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1117/

def isIsomorphic_(s: str, t: str) -> bool:
    h = {}
    for i in range(len(s)):
        if s[i] in h:
            if h[s[i]] != t[i]:
                return False
        else:
            h[s[i]] = t[i]
    return True


class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        return isIsomorphic_(s, t) and isIsomorphic_(t, s)


s1 = "12"
s2 = "\u0067\u0068"

s = Solution()

print(s.isIsomorphic(s1, s2))

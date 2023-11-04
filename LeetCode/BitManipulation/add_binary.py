# https://leetcode.com/problems/add-binary/?envType=study-plan-v2&envId=top-interview-150

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:]


def main():
    sol = Solution()

    print(sol.addBinary('11', '1'))


main()

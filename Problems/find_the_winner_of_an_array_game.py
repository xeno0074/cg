from typing import List

def getNextGreater(arr: List[int]):
    # find the next greater element index for each element
    n = len(arr)
    nextGreater = []
    stack = []
    for i in range(n - 1, 0, -1):
        while stack[-1] < arr[i]:






class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
            

        return 0


input = [2, 1, 3, 5, 4, 6, 7]
k = 2

solution = Solution()

print(solution.getWinner(input, k))

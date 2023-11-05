from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def print(self):
        print('val=', self.val)
        print('left=', self.left)
        print('right=', self.right)


def preTraversalIterative(root):
    global preList
    global stack
    stack = []
    stack.append(root)

    while (len(stack) > 0):
        node = stack.pop()

        if node is None:
            continue

        preList.append(node.val)
        stack.append(node.right)
        stack.append(node.left)


def preTraversalRecursive(root):
    global preList
    if root is None:
        return
    preList.append(root.val)
    preTraversalRecursive(root.left)
    preTraversalRecursive(root.right)


class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        global preList
        # recursive
        preList = []
        preTraversalRecursive(root)
        print('recursive', preList)
        # iterative
        preList = []
        preTraversalIterative(root)
        print('iterative', preList)

        return preList


def main():
    x1 = TreeNode(1, None, TreeNode(2, TreeNode(3, None, None), None))
    x2 = TreeNode(
        3,
        TreeNode(
            1,
            None,
            None
        ),
        TreeNode(
            2,
            None,
            None
        )
    )

    s = Solution()
    ans = s.preorderTraversal(x2)

    print(ans)


main()

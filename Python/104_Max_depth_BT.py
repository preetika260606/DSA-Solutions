from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def solve(self, root):
        if root is None:
            return 0

        left = self.solve(root.left)
        right = self.solve(root.right)

        return 1 + max(left, right)

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.solve(root)


# -------------------------
# TAKE INPUT FROM USER
# -------------------------

values = input("Enter tree: ").split()


# -------------------------
# CREATE TREE
# -------------------------

if values[0].lower() == "null":
    root = None
else:
    root = TreeNode(int(values[0]))

    queue = deque([root])
    i = 1

    while queue and i < len(values):

        current = queue.popleft()

        # Left child
        if i < len(values) and values[i].lower() != "null":
            current.left = TreeNode(int(values[i]))
            queue.append(current.left)

        i += 1

        # Right child
        if i < len(values) and values[i].lower() != "null":
            current.right = TreeNode(int(values[i]))
            queue.append(current.right)

        i += 1


# -------------------------
# FIND MAXIMUM DEPTH
# -------------------------

solution = Solution()

answer = solution.maxDepth(root)

print("Maximum Depth:", answer)
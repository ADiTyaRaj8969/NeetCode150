# Topic: Sum Root to Leaf Numbers
# Description: Given a binary tree where each node contains a single digit, each root-to-leaf path
#              forms a number. Return the total sum of all root-to-leaf numbers.
# Approach: DFS to accumulate path values.

from typing import Optional, List
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def build_tree(arr: List[int]) -> Optional[TreeNode]:
    if not arr or arr[0] == -1:
        return None
    root = TreeNode(arr[0])
    queue = deque([root])
    i = 1
    while i < len(arr) and queue:
        node = queue.popleft()
        if i < len(arr) and arr[i] != -1:
            node.left = TreeNode(arr[i])
            queue.append(node.left)
        i += 1
        if i < len(arr) and arr[i] != -1:
            node.right = TreeNode(arr[i])
            queue.append(node.right)
        i += 1
    return root


class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(node: Optional[TreeNode], cur: int) -> int:
            if not node:
                return 0
            cur = cur * 10 + node.val
            if not node.left and not node.right:
                return cur
            return dfs(node.left, cur) + dfs(node.right, cur)

        return dfs(root, 0)


if __name__ == "__main__":
    tests = [[1, 2, 3], [4, 9, 0, 5, 1]]
    for i, arr in enumerate(tests):
        root = build_tree(arr)
        print(f"Test {i + 1}: {Solution().sumNumbers(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""

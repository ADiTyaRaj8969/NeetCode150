# Topic: Invert Binary Tree
# Description: Swap left and right subtrees recursively (mirror a binary tree).
# Approach: Simple recursion (or iterative stack) visiting each node once.

from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        root.left, root.right = root.right, root.left
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root


def print_level(root):
    if not root:
        print("Empty")
        return
    result = []
    q = deque([root])
    while q:
        node = q.popleft()
        if node:
            result.append(str(node.val))
            q.append(node.left)
            q.append(node.right)
        else:
            result.append("null")
    # Remove trailing nulls
    while result and result[-1] == "null":
        result.pop()
    print(' '.join(result))


if __name__ == "__main__":
    # Test 1
    root = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(7, TreeNode(6), TreeNode(9)))
    result = Solution().invertTree(root)
    print_level(result)

    # Test 2
    root = TreeNode(2, TreeNode(1), TreeNode(3))
    result = Solution().invertTree(root)
    print_level(result)

"""
Time Complexity: O(n)
Space Complexity: O(h) recursion stack
"""

# Topic: Maximum Depth of Binary Tree
# Description: Find longest path from root to leaf.
# Approach: Simple recursion returning max depth of left/right + 1.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))


if __name__ == "__main__":
    # Test 1
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(f"Test 1 -> {Solution().maxDepth(root)}")

    # Test 2
    root = None
    print(f"Test 2 -> {Solution().maxDepth(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(h) recursion stack
"""

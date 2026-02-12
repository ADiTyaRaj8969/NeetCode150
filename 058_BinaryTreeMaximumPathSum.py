# Topic: Binary Tree Maximum Path Sum
# Description: Find highest path sum among all node paths (path may start/end anywhere).
# Approach: DFS returning max gain from node downward and tracking global maximum sum.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.best = float('-inf')

        def max_gain(node):
            if not node:
                return 0
            left_gain = max(0, max_gain(node.left))
            right_gain = max(0, max_gain(node.right))
            self.best = max(self.best, node.val + left_gain + right_gain)
            return node.val + max(left_gain, right_gain)

        max_gain(root)
        return self.best


if __name__ == "__main__":
    # Test 1
    root = TreeNode(1, TreeNode(2), TreeNode(3))
    print(f"Test 1 -> {Solution().maxPathSum(root)}")

    # Test 2
    root = TreeNode(-10, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(f"Test 2 -> {Solution().maxPathSum(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""

# Topic: Balanced Binary Tree
# Description: Check if every subtree's height difference ≤ 1.
# Approach: DFS returning height or -1 if unbalanced to short-circuit.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def check_height(node):
            if not node:
                return 0
            lh = check_height(node.left)
            if lh == -1:
                return -1
            rh = check_height(node.right)
            if rh == -1:
                return -1
            if abs(lh - rh) > 1:
                return -1
            return 1 + max(lh, rh)

        return check_height(root) != -1


if __name__ == "__main__":
    # Test 1
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(f"Test 1 -> {Solution().isBalanced(root)}")

    # Test 2
    root = TreeNode(1, TreeNode(2, TreeNode(3, TreeNode(4), TreeNode(4)), TreeNode(3)), TreeNode(2))
    print(f"Test 2 -> {Solution().isBalanced(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""

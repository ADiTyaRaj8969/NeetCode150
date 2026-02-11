# Topic: Diameter of Binary Tree
# Description: Compute longest path (number of edges) between any two nodes.
# Approach: DFS returning height while tracking max diameter as left_height + right_height.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.diameter = 0

        def height(node):
            if not node:
                return 0
            lh = height(node.left)
            rh = height(node.right)
            self.diameter = max(self.diameter, lh + rh)
            return 1 + max(lh, rh)

        height(root)
        return self.diameter


if __name__ == "__main__":
    # Test 1
    root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))
    print(f"Test 1 -> {Solution().diameterOfBinaryTree(root)}")

    # Test 2
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(f"Test 2 -> {Solution().diameterOfBinaryTree(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""

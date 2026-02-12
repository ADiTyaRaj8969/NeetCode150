# Topic: Validate Binary Search Tree
# Description: Verify if tree follows BST property (inorder strictly increasing).
# Approach: Inorder traversal comparing previous value, or recursion with bounds.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.prev = float('-inf')

        def inorder(node):
            if not node:
                return True
            if not inorder(node.left):
                return False
            if node.val <= self.prev:
                return False
            self.prev = node.val
            return inorder(node.right)

        return inorder(root)


if __name__ == "__main__":
    # Test 1
    root = TreeNode(2, TreeNode(1), TreeNode(3))
    print(f"Test 1 -> {Solution().isValidBST(root)}")

    # Test 2
    root = TreeNode(5, TreeNode(1), TreeNode(4, TreeNode(3), TreeNode(6)))
    print(f"Test 2 -> {Solution().isValidBST(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""

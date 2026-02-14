# Topic: Validate Binary Search Tree
# Description: Determine if a binary tree is a valid BST.
# Approach: Iterative inorder traversal to ensure values are strictly increasing.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        stack = []
        cur = root
        prev = float('-inf')
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            if cur.val <= prev:
                return False
            prev = cur.val
            cur = cur.right
        return True


if __name__ == "__main__":
    # Test 1: Valid BST
    root = TreeNode(2, TreeNode(1), TreeNode(3))
    print(f"Test 1: {Solution().isValidBST(root)}")

    # Test 2: Invalid BST
    root = TreeNode(5, TreeNode(1), TreeNode(4, TreeNode(3), TreeNode(6)))
    print(f"Test 2: {Solution().isValidBST(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""

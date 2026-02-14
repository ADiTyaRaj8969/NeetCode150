# Topic: Binary Tree Inorder Traversal
# Description: Return inorder traversal of a binary tree.
# Approach: Iterative inorder using stack. O(n) time.

from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        stack = []
        cur = root
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            result.append(cur.val)
            cur = cur.right
        return result


if __name__ == "__main__":
    # Test 1
    root = TreeNode(1, None, TreeNode(2, TreeNode(3)))
    print(f"Test 1: {Solution().inorderTraversal(root)}")

    # Test 2
    root = None
    print(f"Test 2: {Solution().inorderTraversal(root)}")

    # Test 3
    root = TreeNode(1)
    print(f"Test 3: {Solution().inorderTraversal(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

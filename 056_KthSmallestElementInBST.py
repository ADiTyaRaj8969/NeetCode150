# Topic: Kth Smallest Element in a BST
# Description: Find the kth smallest element in a binary search tree.
# Approach: Inorder traversal yields sorted order; perform iterative inorder and stop at k.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = []
        cur = root
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            k -= 1
            if k == 0:
                return cur.val
            cur = cur.right
        return -1


if __name__ == "__main__":
    # Test 1
    root = TreeNode(3, TreeNode(1, None, TreeNode(2)), TreeNode(4))
    print(f"Test 1 -> {Solution().kthSmallest(root, 1)}")

    # Test 2
    print(f"Test 2 -> {Solution().kthSmallest(root, 2)}")

"""
Time Complexity: O(h + k) where h is tree height
Space Complexity: O(h)
"""

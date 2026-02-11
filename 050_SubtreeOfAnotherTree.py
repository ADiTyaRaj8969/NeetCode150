# Topic: Subtree of Another Tree
# Description: Determine if one tree is a subtree of another.
# Approach: Check if subRoot matches any subtree using same-tree comparison.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not subRoot:
            return True
        if not root:
            return False
        if self.isSameTree(root, subRoot):
            return True
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        if not p or not q:
            return False
        if p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)


if __name__ == "__main__":
    # Test 1
    root = TreeNode(3, TreeNode(4, TreeNode(1), TreeNode(2)), TreeNode(5))
    sub = TreeNode(4, TreeNode(1), TreeNode(2))
    print(f"Test 1 -> {Solution().isSubtree(root, sub)}")

    # Test 2
    root = TreeNode(3, TreeNode(4, TreeNode(1), TreeNode(2, TreeNode(0))), TreeNode(5))
    sub = TreeNode(4, TreeNode(1), TreeNode(2))
    print(f"Test 2 -> {Solution().isSubtree(root, sub)}")

"""
Time Complexity: O(n * m) worst case
Space Complexity: O(h)
"""

# Topic: Same Tree
# Description: Check whether two binary trees are structurally identical with same node values.
# Approach: Recursive comparison or iterative BFS. We'll use recursion for simplicity.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
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
    p = TreeNode(1, TreeNode(2), TreeNode(3))
    q = TreeNode(1, TreeNode(2), TreeNode(3))
    print(f"Test 1: {Solution().isSameTree(p, q)}")

    # Test 2
    p = TreeNode(1, TreeNode(2))
    q = TreeNode(1, None, TreeNode(2))
    print(f"Test 2: {Solution().isSameTree(p, q)}")

"""
Time Complexity: O(min(n,m))
Space Complexity: O(min(h1,h2))
"""

# Topic: Same Tree
# Description: Check if two binary trees are structurally identical with same values.
# Approach: DFS comparing nodes recursively.

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
    t1 = TreeNode(1, TreeNode(2), TreeNode(3))
    t2 = TreeNode(1, TreeNode(2), TreeNode(3))
    print(f"Test 1 -> {Solution().isSameTree(t1, t2)}")

    # Test 2
    t1 = TreeNode(1, TreeNode(2), TreeNode(3))
    t3 = TreeNode(1, TreeNode(2, None, TreeNode(3)))
    print(f"Test 2 -> {Solution().isSameTree(t1, t3)}")

"""
Time Complexity: O(min(n,m)) up to nodes compared
Space Complexity: O(min(h1,h2))
"""

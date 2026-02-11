# Topic: Lowest Common Ancestor of a BST
# Description: Find lowest ancestor shared by two nodes in a Binary Search Tree.
# Approach: Use BST property: if both nodes < root go left, if both > root go right, else root is LCA.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        while root:
            if p.val < root.val and q.val < root.val:
                root = root.left
            elif p.val > root.val and q.val > root.val:
                root = root.right
            else:
                return root
        return None


if __name__ == "__main__":
    # Test 1
    root = TreeNode(6, TreeNode(2, TreeNode(0), TreeNode(4, TreeNode(3), TreeNode(5))),
                    TreeNode(8, TreeNode(7), TreeNode(9)))
    p = root.left       # node 2
    q = root.right      # node 8
    result = Solution().lowestCommonAncestor(root, p, q)
    print(f"Test 1 -> {result.val}")

    # Test 2
    p = root.left       # node 2
    q = root.left.right # node 4
    result = Solution().lowestCommonAncestor(root, p, q)
    print(f"Test 2 -> {result.val}")

"""
Time Complexity: O(h)
Space Complexity: O(1)
"""

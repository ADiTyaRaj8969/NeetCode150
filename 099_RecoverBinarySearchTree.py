# Topic: Recover Binary Search Tree
# Description: Two nodes of a BST are swapped by mistake. Recover the tree without changing its structure.
# Approach: Inorder traversal to find two misplaced nodes, then swap their values.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        x = y = prev = None
        stack = []
        cur = root
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            if prev and cur.val < prev.val:
                if not x:
                    x = prev
                y = cur
            prev = cur
            cur = cur.right
        if x and y:
            x.val, y.val = y.val, x.val


def inorder(root):
    if not root:
        return []
    return inorder(root.left) + [root.val] + inorder(root.right)


if __name__ == "__main__":
    # Test 1
    root = TreeNode(1, TreeNode(3, None, TreeNode(2)))
    print(f"Before: {inorder(root)}")
    Solution().recoverTree(root)
    print(f"After: {inorder(root)}")

    # Test 2
    root = TreeNode(3, TreeNode(1), TreeNode(4, TreeNode(2)))
    print(f"Before: {inorder(root)}")
    Solution().recoverTree(root)
    print(f"After: {inorder(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""

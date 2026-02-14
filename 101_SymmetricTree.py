# Topic: Symmetric Tree
# Description: Check whether a binary tree is symmetric (mirror of itself).
# Approach: Recursively compare left and right subtrees as mirrors.

from typing import Optional, List
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def build_tree_level(vals: List[int]) -> Optional[TreeNode]:
    if not vals or vals[0] == -1:
        return None
    root = TreeNode(vals[0])
    queue = deque([root])
    i = 1
    while queue and i < len(vals):
        node = queue.popleft()
        if i < len(vals) and vals[i] != -1:
            node.left = TreeNode(vals[i])
            queue.append(node.left)
        i += 1
        if i < len(vals) and vals[i] != -1:
            node.right = TreeNode(vals[i])
            queue.append(node.right)
        i += 1
    return root


class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def is_mirror(a: Optional[TreeNode], b: Optional[TreeNode]) -> bool:
            if not a and not b:
                return True
            if not a or not b:
                return False
            return a.val == b.val and is_mirror(a.left, b.right) and is_mirror(a.right, b.left)

        return is_mirror(root, root)


if __name__ == "__main__":
    tests = [[1, 2, 2, 3, 4, 4, 3], [1, 2, 2, -1, 3, -1, 3]]
    for i, vals in enumerate(tests):
        root = build_tree_level(vals)
        print(f"Test {i + 1}: {Solution().isSymmetric(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(h) for recursion stack
"""

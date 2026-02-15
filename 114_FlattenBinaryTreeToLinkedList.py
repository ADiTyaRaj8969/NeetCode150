# Topic: Flatten Binary Tree to Linked List
# Description: Flatten tree to linked list in-place following preorder (right pointers as next).
# Approach: Iterative stack or reverse preorder recursion. Using iterative stack.

from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def build_tree_level(vals: List[int]) -> Optional[TreeNode]:
    if not vals or vals[0] is None:
        return None
    nodes = [TreeNode(v) if v is not None else None for v in vals]
    for i, node in enumerate(nodes):
        if node:
            l, r = 2 * i + 1, 2 * i + 2
            if l < len(nodes):
                node.left = nodes[l]
            if r < len(nodes):
                node.right = nodes[r]
    return nodes[0]


class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        if not root:
            return
        stack = [root]
        prev = None
        while stack:
            cur = stack.pop()
            if prev:
                prev.left = None
                prev.right = cur
            if cur.right:
                stack.append(cur.right)
            if cur.left:
                stack.append(cur.left)
            prev = cur


def print_flattened(root: Optional[TreeNode]) -> List[int]:
    result = []
    while root:
        result.append(root.val)
        root = root.right
    return result


if __name__ == "__main__":
    tests = [[1, 2, 5, 3, 4, None, 6], []]
    for i, vals in enumerate(tests):
        root = build_tree_level(vals) if vals else None
        Solution().flatten(root)
        print(f"Test {i + 1}: {print_flattened(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(n) stack
"""

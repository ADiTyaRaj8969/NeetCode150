# Topic: Minimum Depth of Binary Tree
# Description: Find the minimum depth from root to the nearest leaf.
# Approach: BFS level-order; first time we see a leaf, return depth.

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
    nodes = [TreeNode(v) if v != -1 else None for v in vals]
    for i, node in enumerate(nodes):
        if node:
            l, r = 2 * i + 1, 2 * i + 2
            if l < len(nodes):
                node.left = nodes[l]
            if r < len(nodes):
                node.right = nodes[r]
    return nodes[0]


class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        queue = deque([(root, 1)])
        while queue:
            node, d = queue.popleft()
            if not node.left and not node.right:
                return d
            if node.left:
                queue.append((node.left, d + 1))
            if node.right:
                queue.append((node.right, d + 1))
        return 0


if __name__ == "__main__":
    tests = [[3, 9, 20, -1, -1, 15, 7], [2, -1, 3, -1, 4, -1, 5]]
    for i, vals in enumerate(tests):
        root = build_tree_level(vals)
        print(f"Test {i + 1}: {Solution().minDepth(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

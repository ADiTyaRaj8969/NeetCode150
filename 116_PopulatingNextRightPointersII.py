# Topic: Populating Next Right Pointers II
# Description: Connect each node to its next right node in any binary tree (not necessarily perfect).
# Approach: Use BFS level-order traversal and connect nodes across each level.

from typing import Optional, List
from collections import deque


class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


def build_tree_level(vals: List[int]) -> Optional[Node]:
    if not vals or vals[0] is None:
        return None
    nodes = [Node(v) if v is not None else None for v in vals]
    for i, node in enumerate(nodes):
        if node:
            l, r = 2 * i + 1, 2 * i + 2
            if l < len(nodes):
                node.left = nodes[l]
            if r < len(nodes):
                node.right = nodes[r]
    return nodes[0]


class Solution:
    def connect(self, root: Optional[Node]) -> Optional[Node]:
        if not root:
            return root
        queue = deque([root])
        while queue:
            size = len(queue)
            prev = None
            for _ in range(size):
                cur = queue.popleft()
                if prev:
                    prev.next = cur
                prev = cur
                if cur.left:
                    queue.append(cur.left)
                if cur.right:
                    queue.append(cur.right)
        return root


def print_levels(root: Optional[Node]) -> None:
    while root:
        cur = root
        vals = []
        next_level = None
        while cur:
            vals.append(str(cur.val))
            if not next_level:
                if cur.left:
                    next_level = cur.left
                elif cur.right:
                    next_level = cur.right
            cur = cur.next
        print(' '.join(vals))
        root = next_level


if __name__ == "__main__":
    tests = [[1, 2, 3, 4, 5, None, 7], []]
    for i, vals in enumerate(tests):
        root = build_tree_level(vals) if vals else None
        Solution().connect(root)
        print(f"Test {i + 1}:")
        if root:
            print_levels(root)
        else:
            print("Empty")

"""
Time Complexity: O(n)
Space Complexity: O(n) for BFS queue
"""

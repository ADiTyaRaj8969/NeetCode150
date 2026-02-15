# Topic: Populating Next Right Pointers in Each Node
# Description: Given a perfect binary tree, connect each node's next pointer to its next right node.
# Approach: Use level traversal or next pointers to iterate O(1) space. Iterative level-by-level.

from typing import Optional, List


class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


def build_perfect_tree(vals: List[int]) -> Optional[Node]:
    if not vals:
        return None
    nodes = [Node(v) if v != -1 else None for v in vals]
    for i, node in enumerate(nodes):
        if node:
            left = 2 * i + 1
            right = 2 * i + 2
            if left < len(nodes):
                node.left = nodes[left]
            if right < len(nodes):
                node.right = nodes[right]
    return nodes[0] if nodes else None


class Solution:
    def connect(self, root: Optional[Node]) -> Optional[Node]:
        if not root:
            return root
        leftmost = root
        while leftmost.left:
            head = leftmost
            while head:
                head.left.next = head.right
                if head.next:
                    head.right.next = head.next.left
                head = head.next
            leftmost = leftmost.left
        return root


def print_levels(root: Optional[Node]) -> None:
    level = root
    while level:
        cur = level
        vals = []
        while cur:
            vals.append(str(cur.val))
            cur = cur.next
        print(' '.join(vals))
        level = level.left


if __name__ == "__main__":
    tests = [[1, 2, 3, 4, 5, 6, 7], [1], []]
    for i, vals in enumerate(tests):
        root = build_perfect_tree(vals) if vals else None
        Solution().connect(root)
        print(f"Test {i + 1}:")
        if root:
            print_levels(root)
        else:
            print("Empty")

"""
Time Complexity: O(n)
Space Complexity: O(1) extra (excluding tree)
"""

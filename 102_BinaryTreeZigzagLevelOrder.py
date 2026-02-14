# Topic: Binary Tree Zigzag Level Order Traversal
# Description: Return level order traversal where the traversal direction alternates each level.
# Approach: BFS level-order and reverse every other level (or use deque to push accordingly).

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
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        result = []
        queue = deque([root])
        left_to_right = True
        while queue:
            size = len(queue)
            level = [0] * size
            for i in range(size):
                node = queue.popleft()
                idx = i if left_to_right else (size - 1 - i)
                level[idx] = node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            result.append(level)
            left_to_right = not left_to_right
        return result


if __name__ == "__main__":
    tests = [[3, 9, 20, -1, -1, 15, 7], [1], []]
    for i, vals in enumerate(tests):
        root = build_tree_level(vals) if vals else None
        print(f"Test {i + 1}: {Solution().zigzagLevelOrder(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

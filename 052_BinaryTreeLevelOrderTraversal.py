# Topic: Binary Tree Level Order Traversal
# Description: Traverse tree by level using BFS and return nodes grouped by level.
# Approach: Standard BFS using queue.

from typing import Optional, List
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        result = []
        q = deque([root])
        while q:
            level = []
            for _ in range(len(q)):
                node = q.popleft()
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            result.append(level)
        return result


if __name__ == "__main__":
    # Test 1
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    print(f"Test 1 -> {Solution().levelOrder(root)}")

    # Test 2
    root = None
    print(f"Test 2 -> {Solution().levelOrder(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

# Topic: Binary Tree Right Side View
# Description: Return visible nodes from right side view (one per level).
# Approach: BFS taking last node of each level or DFS prioritizing right child.

from typing import Optional, List
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        result = []
        q = deque([root])
        while q:
            sz = len(q)
            for i in range(sz):
                node = q.popleft()
                if i == sz - 1:
                    result.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return result


if __name__ == "__main__":
    # Test 1
    root = TreeNode(1, TreeNode(2, None, TreeNode(5)), TreeNode(3, None, TreeNode(4)))
    print(f"Test 1 -> {Solution().rightSideView(root)}")

    # Test 2
    root = TreeNode(1, TreeNode(2))
    print(f"Test 2 -> {Solution().rightSideView(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

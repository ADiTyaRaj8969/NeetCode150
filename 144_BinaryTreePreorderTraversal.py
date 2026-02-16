# Topic: Binary Tree Preorder Traversal
# Description: Given a binary tree, return preorder traversal.
# Approach: Iterative stack-based preorder.

from typing import Optional, List
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def build_tree(arr: List[int]) -> Optional[TreeNode]:
    if not arr or arr[0] == -1:
        return None
    root = TreeNode(arr[0])
    queue = deque([root])
    i = 1
    while i < len(arr) and queue:
        node = queue.popleft()
        if i < len(arr) and arr[i] != -1:
            node.left = TreeNode(arr[i])
            queue.append(node.left)
        i += 1
        if i < len(arr) and arr[i] != -1:
            node.right = TreeNode(arr[i])
            queue.append(node.right)
        i += 1
    return root


class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        if not root:
            return result
        stack = [root]
        while stack:
            node = stack.pop()
            result.append(node.val)
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
        return result


if __name__ == "__main__":
    tests = [[1, 2, 3, -1, -1, 4, 5], [1, -1, 2, 3]]
    for i, arr in enumerate(tests):
        root = build_tree(arr)
        print(f"Test {i + 1}: {Solution().preorderTraversal(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

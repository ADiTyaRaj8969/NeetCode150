# Topic: Count Good Nodes in Binary Tree
# Description: Count nodes not smaller than any ancestor on path from root.
# Approach: DFS passing current maximum along path; increment when node.val >= current max.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(node, max_so_far):
            if not node:
                return 0
            count = 1 if node.val >= max_so_far else 0
            max_so_far = max(max_so_far, node.val)
            count += dfs(node.left, max_so_far)
            count += dfs(node.right, max_so_far)
            return count

        return dfs(root, float('-inf'))


if __name__ == "__main__":
    # Test 1
    root = TreeNode(3, TreeNode(1, TreeNode(3)), TreeNode(4, TreeNode(1), TreeNode(5)))
    print(f"Test 1 -> {Solution().goodNodes(root)}")

    # Test 2
    root = TreeNode(3, TreeNode(3, TreeNode(4), TreeNode(2)))
    print(f"Test 2 -> {Solution().goodNodes(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""

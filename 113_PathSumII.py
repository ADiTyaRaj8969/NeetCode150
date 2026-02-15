# Topic: Path Sum II
# Description: Find all root-to-leaf paths where sum equals target.
# Approach: DFS backtracking to collect paths.

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
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        result = []
        path = []

        def dfs(node: Optional[TreeNode], remaining: int) -> None:
            if not node:
                return
            path.append(node.val)
            if not node.left and not node.right and node.val == remaining:
                result.append(path[:])
            else:
                dfs(node.left, remaining - node.val)
                dfs(node.right, remaining - node.val)
            path.pop()

        dfs(root, targetSum)
        return result


if __name__ == "__main__":
    tests = [([5, 4, 8, 11, None, 13, 4, 7, 2, None, None, 5, 1], 22),
             ([1, 2, 3], 5)]
    for i, (vals, target) in enumerate(tests):
        root = build_tree_level(vals)
        print(f"Test {i + 1}: {Solution().pathSum(root, target)}")

"""
Time Complexity: O(n) to visit nodes; number of paths may cause extra cost
Space Complexity: O(h) recursion + output
"""

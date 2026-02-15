# Topic: Path Sum
# Description: Determine if the tree has a root-to-leaf path summing to target.
# Approach: DFS recursion carrying remaining sum.

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
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        if not root.left and not root.right:
            return root.val == targetSum
        return (self.hasPathSum(root.left, targetSum - root.val) or
                self.hasPathSum(root.right, targetSum - root.val))


if __name__ == "__main__":
    tests = [([5, 4, 8, 11, None, 13, 4, 7, 2, None, None, None, 1], 22),
             ([1, 2, 3], 5), ([], 0)]
    for i, (vals, target) in enumerate(tests):
        root = build_tree_level(vals) if vals else None
        print(f"Test {i + 1}: {Solution().hasPathSum(root, target)}")

"""
Time Complexity: O(n)
Space Complexity: O(h)
"""

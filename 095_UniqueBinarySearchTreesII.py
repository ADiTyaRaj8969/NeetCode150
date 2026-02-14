# Topic: Unique Binary Search Trees II
# Description: Generate all structurally unique BSTs that store values 1..n.
# Approach: Recursively generate trees by choosing each root and combining left/right subtrees.

from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        if n == 0:
            return []

        def generate(lo, hi):
            if lo > hi:
                return [None]
            trees = []
            for root_val in range(lo, hi + 1):
                lefts = generate(lo, root_val - 1)
                rights = generate(root_val + 1, hi)
                for L in lefts:
                    for R in rights:
                        root = TreeNode(root_val)
                        root.left = L
                        root.right = R
                        trees.append(root)
            return trees

        return generate(1, n)


def serialize_preorder(root):
    if not root:
        return "#"
    return f"{root.val} {serialize_preorder(root.left)} {serialize_preorder(root.right)}"


if __name__ == "__main__":
    tests = [2, 3]
    for i, n in enumerate(tests):
        trees = Solution().generateTrees(n)
        print(f"Test {i + 1} (n={n}): count={len(trees)}")
        for t in trees:
            print(f"  {serialize_preorder(t)}")

"""
Time Complexity: O(4^n / sqrt(n)) Catalan number
Space Complexity: O(4^n / sqrt(n)) for storing all trees
"""

# Topic: Convert Sorted Array to Binary Search Tree
# Description: Given a sorted (increasing) array, convert it to a height-balanced BST.
# Approach: Recursively choose middle element as root to get balanced BST.

from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def build(l: int, r: int) -> Optional[TreeNode]:
            if l > r:
                return None
            m = l + (r - l) // 2
            root = TreeNode(nums[m])
            root.left = build(l, m - 1)
            root.right = build(m + 1, r)
            return root

        return build(0, len(nums) - 1)


def preorder(root: Optional[TreeNode]) -> List[int]:
    if not root:
        return []
    return [root.val] + preorder(root.left) + preorder(root.right)


if __name__ == "__main__":
    tests = [[-10, -3, 0, 5, 9], [1]]
    for i, nums in enumerate(tests):
        root = Solution().sortedArrayToBST(nums)
        print(f"Test {i + 1}: {preorder(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(log n) recursion stack
"""

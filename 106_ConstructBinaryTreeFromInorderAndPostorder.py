# Topic: Construct Binary Tree from Inorder and Postorder
# Description: Given inorder and postorder traversal of a tree, construct the binary tree.
# Approach: Use the last element of postorder as root; split inorder into left/right using index map; recurse.

from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        idx_map = {val: i for i, val in enumerate(inorder)}

        def build(iL: int, iR: int, pL: int, pR: int) -> Optional[TreeNode]:
            if iL > iR or pL > pR:
                return None
            root_val = postorder[pR]
            root = TreeNode(root_val)
            in_root_idx = idx_map[root_val]
            left_size = in_root_idx - iL
            root.left = build(iL, in_root_idx - 1, pL, pL + left_size - 1)
            root.right = build(in_root_idx + 1, iR, pL + left_size, pR - 1)
            return root

        return build(0, len(inorder) - 1, 0, len(postorder) - 1)


def preorder_print(root: Optional[TreeNode]) -> List[int]:
    if not root:
        return []
    return [root.val] + preorder_print(root.left) + preorder_print(root.right)


if __name__ == "__main__":
    tests = [([9, 3, 15, 20, 7], [9, 15, 7, 20, 3]), ([2, 1, 3], [2, 3, 1])]
    for i, (inorder, postorder) in enumerate(tests):
        root = Solution().buildTree(inorder, postorder)
        print(f"Test {i + 1}: {preorder_print(root)}")

"""
Time Complexity: O(n)
Space Complexity: O(n) for index map and recursion stack
"""

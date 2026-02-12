# Topic: Construct Binary Tree from Preorder and Inorder Traversal
# Description: Rebuild binary tree given preorder and inorder traversals.
# Approach: Recursively partition arrays using a value->index map for inorder positions.

from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        idx_map = {val: i for i, val in enumerate(inorder)}

        def build(p_start, p_end, i_start, i_end):
            if p_start > p_end:
                return None
            root_val = preorder[p_start]
            root = TreeNode(root_val)
            mid = idx_map[root_val]
            left_size = mid - i_start
            root.left = build(p_start + 1, p_start + left_size, i_start, mid - 1)
            root.right = build(p_start + left_size + 1, p_end, mid + 1, i_end)
            return root

        return build(0, len(preorder) - 1, 0, len(inorder) - 1)


def print_level(root):
    if not root:
        print("Empty")
        return
    from collections import deque
    result = []
    q = deque([root])
    while q:
        node = q.popleft()
        result.append(str(node.val))
        if node.left:
            q.append(node.left)
        if node.right:
            q.append(node.right)
    print(' '.join(result))


if __name__ == "__main__":
    # Test 1
    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]
    root = Solution().buildTree(preorder, inorder)
    print_level(root)

    # Test 2
    preorder = [1, 2, 3]
    inorder = [2, 1, 3]
    root = Solution().buildTree(preorder, inorder)
    print_level(root)

"""
Time Complexity: O(n)
Space Complexity: O(n) for recursion and index map
"""

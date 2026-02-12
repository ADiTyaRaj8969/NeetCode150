# Topic: Serialize and Deserialize Binary Tree
# Description: Encode and decode binary tree structure.
# Approach: Preorder traversal with null markers for serialization; deserialize by reading tokens.

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Codec:
    def serialize(self, root: Optional[TreeNode]) -> str:
        tokens = []

        def dfs(node):
            if not node:
                tokens.append('#')
                return
            tokens.append(str(node.val))
            dfs(node.left)
            dfs(node.right)

        dfs(root)
        return ' '.join(tokens)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        tokens = iter(data.split())

        def build():
            token = next(tokens)
            if token == '#':
                return None
            node = TreeNode(int(token))
            node.left = build()
            node.right = build()
            return node

        return build()


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
    codec = Codec()

    # Test 1
    root = TreeNode(1, TreeNode(2), TreeNode(3, TreeNode(4), TreeNode(5)))
    data = codec.serialize(root)
    print(f"Serialized: {data}")
    decoded = codec.deserialize(data)
    print_level(decoded)

    # Test 2
    root = None
    data = codec.serialize(root)
    print(f"Serialized: {data}")
    decoded = codec.deserialize(data)
    print_level(decoded)

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

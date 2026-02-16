# Topic: Copy List with Random Pointer
# Description: Given a linked list where each node has a next and a random pointer, return a deep copy of the list.
# Approach: Clone using hashmap from original->copy.

from typing import Optional, Dict


class Node:
    def __init__(self, val: int = 0, next: 'Node' = None, random: 'Node' = None):
        self.val = val
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        if not head:
            return None
        cloned: Dict[Node, Node] = {}
        cur = head
        while cur:
            cloned[cur] = Node(cur.val)
            cur = cur.next
        cur = head
        while cur:
            cloned[cur].next = cloned.get(cur.next)
            cloned[cur].random = cloned.get(cur.random)
            cur = cur.next
        return cloned[head]


def build_list(vals, randoms):
    if not vals:
        return None
    nodes = [Node(v) for v in vals]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    for i, r in enumerate(randoms):
        nodes[i].random = nodes[r] if r != -1 else None
    return nodes[0]


if __name__ == "__main__":
    tests = [([7, 13, 11, 10, 1], [-1, 0, 4, 2, 0]),
             ([1, 2, 3], [-1, 0, 1])]
    for i, (vals, randoms) in enumerate(tests):
        head = build_list(vals, randoms)
        cloned = Solution().copyRandomList(head)
        result = []
        while cloned:
            result.append(cloned.val)
            cloned = cloned.next
        print(f"Test {i + 1}: {result}")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

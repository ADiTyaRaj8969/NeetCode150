# Topic: Linked List Cycle
# Description: Given a linked list, determine if it has a cycle.
# Approach: Floyd's Tortoise and Hare algorithm.

from typing import Optional, List


class ListNode:
    def __init__(self, val: int = 0, next: 'ListNode' = None):
        self.val = val
        self.next = next


def build_list(vals: List[int], pos: int) -> Optional[ListNode]:
    if not vals:
        return None
    nodes = [ListNode(v) for v in vals]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    if pos >= 0:
        nodes[-1].next = nodes[pos]
    return nodes[0]


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False


if __name__ == "__main__":
    tests = [([3, 2, 0, -4], 1), ([1, 2], -1), ([1], -1)]
    for i, (vals, pos) in enumerate(tests):
        head = build_list(vals, pos)
        print(f"Test {i + 1}: {Solution().hasCycle(head)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

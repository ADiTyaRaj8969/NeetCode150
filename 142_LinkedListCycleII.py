# Topic: Linked List Cycle II
# Description: Given a linked list, return the node where the cycle begins. If there is no cycle, return None.
# Approach: Use Floyd's algorithm to find the meeting point, then find cycle start.

from typing import Optional, List


class ListNode:
    def __init__(self, val: int = 0, next: 'ListNode' = None):
        self.val = val
        self.next = next


def build_list_with_nodes(vals: List[int], pos: int) -> tuple:
    if not vals:
        return None, []
    nodes = [ListNode(v) for v in vals]
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    if pos >= 0:
        nodes[-1].next = nodes[pos]
    return nodes[0], nodes


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                # Found cycle, find entry point
                p = head
                while p != slow:
                    p = p.next
                    slow = slow.next
                return p
        return None


if __name__ == "__main__":
    tests = [([3, 2, 0, -4], 1), ([1, 2], -1)]
    for i, (vals, pos) in enumerate(tests):
        head, nodes = build_list_with_nodes(vals, pos)
        result = Solution().detectCycle(head)
        if result:
            idx = next((j for j, n in enumerate(nodes) if n == result), -1)
            print(f"Test {i + 1}: index {idx}")
        else:
            print(f"Test {i + 1}: -1")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

# Topic: Linked List Cycle
# Description: Detect if a singly linked list has a cycle.
# Approach: Floyd's Tortoise and Hare (fast & slow pointers) O(n) time, O(1) space.

from typing import Optional


class ListNode:
    def __init__(self, x: int):
        self.val = x
        self.next = None


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
    # Test 1: cycle at pos=1
    n0, n1, n2, n3 = ListNode(3), ListNode(2), ListNode(0), ListNode(-4)
    n0.next, n1.next, n2.next, n3.next = n1, n2, n3, n1
    print(f"Test 1 -> {Solution().hasCycle(n0)}")

    # Test 2: no cycle
    a, b = ListNode(1), ListNode(2)
    a.next = b
    print(f"Test 2 -> {Solution().hasCycle(a)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

# Topic: Partition List
# Description: Partition a linked list around value x such that nodes < x come before nodes >= x, preserving original relative order.
# Approach: Build two lists (less and greater) and concatenate. O(n) time, O(1) extra space.

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        less_dummy = ListNode(0)
        greater_dummy = ListNode(0)
        less = less_dummy
        greater = greater_dummy

        while head:
            if head.val < x:
                less.next = head
                less = less.next
            else:
                greater.next = head
                greater = greater.next
            head = head.next

        greater.next = None
        less.next = greater_dummy.next
        return less_dummy.next


def print_list(head):
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(' '.join(vals) if vals else "Empty")


if __name__ == "__main__":
    # Test 1
    head = ListNode(1, ListNode(4, ListNode(3, ListNode(2, ListNode(5, ListNode(2))))))
    result = Solution().partition(head, 3)
    print_list(result)

    # Test 2
    head = ListNode(2, ListNode(1))
    result = Solution().partition(head, 2)
    print_list(result)

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

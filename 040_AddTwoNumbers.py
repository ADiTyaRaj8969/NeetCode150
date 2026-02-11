# Topic: Add Two Numbers
# Description: Add two numbers represented by linked lists (digits stored in reverse order).
# Approach: Iterate lists, sum digits with carry, build result list.

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        tail = dummy
        carry = 0
        while l1 or l2 or carry:
            s = carry + (l1.val if l1 else 0) + (l2.val if l2 else 0)
            carry = s // 10
            tail.next = ListNode(s % 10)
            tail = tail.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        return dummy.next


def print_list(head):
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(' '.join(vals))


if __name__ == "__main__":
    # Test 1
    a = ListNode(2, ListNode(4, ListNode(3)))
    b = ListNode(5, ListNode(6, ListNode(4)))
    result = Solution().addTwoNumbers(a, b)
    print_list(result)

    # Test 2
    a = ListNode(0)
    b = ListNode(0)
    result = Solution().addTwoNumbers(a, b)
    print_list(result)

"""
Time Complexity: O(max(n,m))
Space Complexity: O(max(n,m)) for result
"""

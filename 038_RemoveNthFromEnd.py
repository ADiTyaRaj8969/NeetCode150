# Topic: Remove Nth Node From End of List
# Description: Delete node located n positions from list end.
# Approach: Two-pointer with gap n, remove target in one pass.

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        first = second = dummy
        for _ in range(n + 1):
            first = first.next
        while first:
            first = first.next
            second = second.next
        second.next = second.next.next
        return dummy.next


def print_list(head):
    if not head:
        print("Empty")
        return
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(' '.join(vals))


if __name__ == "__main__":
    # Test 1
    h = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    result = Solution().removeNthFromEnd(h, 2)
    print_list(result)

    # Test 2
    h = ListNode(1)
    result = Solution().removeNthFromEnd(h, 1)
    print_list(result)

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

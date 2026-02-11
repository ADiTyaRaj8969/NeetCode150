# Topic: Reverse Linked List
# Description: Reverse order of nodes in singly linked list.
# Approach: Iterative in-place reversal using three pointers.

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        while head:
            nxt = head.next
            head.next = prev
            prev = head
            head = nxt
        return prev


def print_list(head):
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(' '.join(vals))


if __name__ == "__main__":
    # Test 1
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    result = Solution().reverseList(head)
    print_list(result)

    # Test 2
    head = ListNode(1, ListNode(2))
    result = Solution().reverseList(head)
    print_list(result)

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

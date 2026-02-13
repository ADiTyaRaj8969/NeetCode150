# Topic: Remove Duplicates from Sorted List
# Description: Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
# Approach: Iterate once and skip nodes with same value. O(n) time, O(1) space.

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        while cur and cur.next:
            if cur.val == cur.next.val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return head


def print_list(head):
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(' '.join(vals) if vals else "Empty")


if __name__ == "__main__":
    # Test 1
    head = ListNode(1, ListNode(1, ListNode(2)))
    result = Solution().deleteDuplicates(head)
    print_list(result)

    # Test 2
    head = ListNode(1, ListNode(1, ListNode(2, ListNode(3, ListNode(3)))))
    result = Solution().deleteDuplicates(head)
    print_list(result)

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

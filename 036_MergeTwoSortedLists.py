# Topic: Merge Two Sorted Lists
# Description: Merge two sorted linked lists into one sorted list.
# Approach: Iterative dummy-head merging in O(n) time and O(1) extra space.

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        tail = dummy
        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
        tail.next = list1 if list1 else list2
        return dummy.next


def print_list(head):
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(' '.join(vals))


if __name__ == "__main__":
    # Test 1
    a = ListNode(1, ListNode(2, ListNode(4)))
    b = ListNode(1, ListNode(3, ListNode(4)))
    result = Solution().mergeTwoLists(a, b)
    print_list(result)

    # Test 2
    a = None
    b = ListNode(0)
    result = Solution().mergeTwoLists(a, b)
    print_list(result)

"""
Time Complexity: O(n+m)
Space Complexity: O(1)
"""

# Topic: Reverse Linked List II
# Description: Reverse a linked list from position m to n in one-pass.
# Approach: Use pointers to find the m-1 node, reverse the sublist, reconnect. O(n) time, O(1) space.

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head or left == right:
            return head
        dummy = ListNode(0, head)
        prev = dummy
        for _ in range(left - 1):
            prev = prev.next
        curr = prev.next
        for _ in range(right - left):
            temp = curr.next
            curr.next = temp.next
            temp.next = prev.next
            prev.next = temp
        return dummy.next


def print_list(head):
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(' '.join(vals) if vals else "Empty")


if __name__ == "__main__":
    # Test 1
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    result = Solution().reverseBetween(head, 2, 4)
    print_list(result)

    # Test 2
    head = ListNode(5)
    result = Solution().reverseBetween(head, 1, 1)
    print_list(result)

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

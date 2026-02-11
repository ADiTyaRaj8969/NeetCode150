# Topic: Reorder List
# Description: Rearrange nodes: first, last, second, second-last pattern.
# Approach: Find middle, reverse second half, and merge alternatingly.

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head or not head.next:
            return
        
        # Find middle
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        # Reverse second half
        second = slow.next
        slow.next = None
        prev = None
        while second:
            nxt = second.next
            second.next = prev
            prev = second
            second = nxt
        
        # Merge two halves
        p, q = head, prev
        while q:
            pn, qn = p.next, q.next
            p.next = q
            q.next = pn
            p, q = pn, qn


def print_list(head):
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(' '.join(vals))


if __name__ == "__main__":
    # Test 1
    h = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    Solution().reorderList(h)
    print_list(h)

    # Test 2
    h = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    Solution().reorderList(h)
    print_list(h)

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

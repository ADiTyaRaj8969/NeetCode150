# Topic: Reorder List
# Description: Given a singly linked list L: L0→L1→…→Ln-1→Ln, reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
# Approach: Find middle, reverse second half, merge lists.

from typing import Optional, List


class ListNode:
    def __init__(self, val: int = 0, next: 'ListNode' = None):
        self.val = val
        self.next = next


def build_list(vals: List[int]) -> Optional[ListNode]:
    if not vals:
        return None
    head = ListNode(vals[0])
    cur = head
    for v in vals[1:]:
        cur.next = ListNode(v)
        cur = cur.next
    return head


def list_to_array(head: Optional[ListNode]) -> List[int]:
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head or not head.next:
            return
        # Find middle
        slow = fast = head
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
        # Merge
        p, q = head, prev
        while q:
            n1, n2 = p.next, q.next
            p.next = q
            q.next = n1
            p, q = n1, n2


if __name__ == "__main__":
    tests = [[1, 2, 3, 4], [1, 2, 3, 4, 5]]
    for i, vals in enumerate(tests):
        head = build_list(vals)
        Solution().reorderList(head)
        print(f"Test {i + 1}: {list_to_array(head)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

# Topic: Sort List
# Description: Sort a linked list in O(n log n) time and O(log n) space (merge sort on list).
# Approach: Use fast/slow to split and merge lists recursively.

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
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        # Find middle
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        mid = slow.next
        slow.next = None

        # Recursively sort
        left = self.sortList(head)
        right = self.sortList(mid)

        # Merge
        return self.merge(left, right)

    def merge(self, a: Optional[ListNode], b: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        t = dummy
        while a and b:
            if a.val < b.val:
                t.next = a
                a = a.next
            else:
                t.next = b
                b = b.next
            t = t.next
        t.next = a if a else b
        return dummy.next


if __name__ == "__main__":
    tests = [[4, 2, 1, 3], [-1, 5, 3, 4, 0]]
    for i, vals in enumerate(tests):
        head = build_list(vals)
        sorted_head = Solution().sortList(head)
        print(f"Test {i + 1}: {list_to_array(sorted_head)}")

"""
Time Complexity: O(n log n)
Space Complexity: O(log n) recursion
"""

# Topic: Insertion Sort List
# Description: Sort a singly linked list using insertion sort.
# Approach: Maintain a sorted dummy list and insert nodes one by one.

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
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(float('-inf'))
        cur = head
        while cur:
            nxt = cur.next
            # Find insertion point
            p = dummy
            while p.next and p.next.val < cur.val:
                p = p.next
            cur.next = p.next
            p.next = cur
            cur = nxt
        return dummy.next


if __name__ == "__main__":
    tests = [[4, 2, 1, 3], [-1, 5, 3, 4, 0]]
    for i, vals in enumerate(tests):
        head = build_list(vals)
        sorted_head = Solution().insertionSortList(head)
        print(f"Test {i + 1}: {list_to_array(sorted_head)}")

"""
Time Complexity: O(n^2) worst-case
Space Complexity: O(1)
"""

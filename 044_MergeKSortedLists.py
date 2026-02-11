# Topic: Merge K Sorted Lists
# Description: Merge multiple sorted linked lists into one sorted list efficiently.
# Approach: Use a min-heap (heapq) of current nodes, O(N log k) where N total nodes.

from typing import List, Optional
import heapq


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __lt__(self, other):
        return self.val < other.val


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        for l in lists:
            if l:
                heapq.heappush(heap, l)
        dummy = ListNode(0)
        tail = dummy
        while heap:
            node = heapq.heappop(heap)
            tail.next = node
            tail = tail.next
            if node.next:
                heapq.heappush(heap, node.next)
        return dummy.next


def print_list(head):
    vals = []
    while head:
        vals.append(str(head.val))
        head = head.next
    print(' '.join(vals))


if __name__ == "__main__":
    # Test 1
    a = ListNode(1, ListNode(4, ListNode(5)))
    b = ListNode(1, ListNode(3, ListNode(4)))
    c = ListNode(2, ListNode(6))
    result = Solution().mergeKLists([a, b, c])
    print_list(result)

"""
Time Complexity: O(N log k)
Space Complexity: O(k)
"""

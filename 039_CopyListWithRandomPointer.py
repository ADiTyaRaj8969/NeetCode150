# Topic: Copy List With Random Pointer
# Description: Clone linked list with next and random pointers.
# Approach: Interleave copied nodes, fix random pointers, then separate lists (O(n) time, O(1) extra).

from typing import Optional


class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = x
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        if not head:
            return None
        
        # 1. Copy nodes next to originals
        p = head
        while p:
            copy = Node(p.val)
            copy.next = p.next
            p.next = copy
            p = copy.next
        
        # 2. Assign randoms
        p = head
        while p:
            if p.random:
                p.next.random = p.random.next
            p = p.next.next
        
        # 3. Separate lists
        dummy = Node(0)
        tail = dummy
        p = head
        while p:
            copy = p.next
            p.next = copy.next
            tail.next = copy
            tail = copy
            p = p.next
        
        return dummy.next


if __name__ == "__main__":
    # Test 1: small list
    n0 = Node(7)
    n1 = Node(13)
    n2 = Node(11)
    n0.next = n1
    n1.next = n2
    n0.random = None
    n1.random = n0
    n2.random = n1
    
    copy = Solution().copyRandomList(n0)
    
    # Build index map for printing
    idx = {}
    i = 0
    p = copy
    while p:
        idx[p] = i
        i += 1
        p = p.next
    
    p = copy
    result = []
    while p:
        r = f"({idx[p.random]})" if p.random else ""
        result.append(f"{p.val}{r}")
        p = p.next
    print(' '.join(result))

    # Test 2: empty
    copy = Solution().copyRandomList(None)
    print("Empty" if not copy else "Not empty")

"""
Time Complexity: O(n)
Space Complexity: O(1) extra (excluding output)
"""

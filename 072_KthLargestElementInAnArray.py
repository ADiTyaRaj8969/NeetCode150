# Topic: Kth Largest Element in an Array
# Description: Find kth largest element using selection algorithm.
# Approach: Use heapq for O(n log k) or quickselect for O(n) average.

from typing import List
import heapq


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # Using min-heap of size k
        heap = nums[:k]
        heapq.heapify(heap)
        for num in nums[k:]:
            if num > heap[0]:
                heapq.heapreplace(heap, num)
        return heap[0]


if __name__ == "__main__":
    a = [3, 2, 1, 5, 6, 4]
    print(f"Test 1 -> {Solution().findKthLargest(a, 2)}")  # expect 5
    b = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    print(f"Test 2 -> {Solution().findKthLargest(b, 4)}")  # expect 4

"""
Time Complexity: O(n log k)
Space Complexity: O(k)
"""

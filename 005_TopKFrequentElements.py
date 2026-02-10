# Topic: Top K Frequent Elements
# Description: Return the k most frequently occurring elements in the array.
# Approach: Count frequencies and use a min-heap of size k (or bucket sort).

from typing import List
from collections import Counter
import heapq


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        # Use min-heap of size k
        pq = []
        for num, count in freq.items():
            heapq.heappush(pq, (count, num))
            if len(pq) > k:
                heapq.heappop(pq)
        return [num for count, num in sorted(pq, reverse=True)]


if __name__ == "__main__":
    tests = [([1, 1, 1, 2, 2, 3], 2), ([1], 1)]
    sol = Solution()
    for i, (nums, k) in enumerate(tests):
        result = sol.topKFrequent(nums, k)
        print(f"Test {i + 1}: {nums} k={k} -> {','.join(map(str, result))}")

"""
Time Complexity: O(n log k)
Space Complexity: O(n)
"""

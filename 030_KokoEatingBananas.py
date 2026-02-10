# Topic: Koko Eating Bananas
# Description: Find minimum eating speed to finish all bananas in time H.
# Approach: Binary search on speed k and check total hours required.

from typing import List
import math


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def hours_needed(k: int) -> int:
            return sum(math.ceil(p / k) for p in piles)
        
        l, r = 1, max(piles)
        while l < r:
            mid = l + (r - l) // 2
            if hours_needed(mid) <= h:
                r = mid
            else:
                l = mid + 1
        return l


if __name__ == "__main__":
    tests = [([3, 6, 7, 11], 8), ([30, 11, 23, 4, 20], 5)]
    sol = Solution()
    for i, (piles, h) in enumerate(tests):
        result = sol.minEatingSpeed(piles, h)
        print(f"Test {i + 1}: -> {result}")

"""
Time Complexity: O(n log M) where M = max pile
Space Complexity: O(1)
"""

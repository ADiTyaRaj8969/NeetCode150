# Topic: Search Insert Position
# Description: Given a sorted array and a target, return the index if the target is found.
# If not, return the index where it would be inserted in order.
# Approach: Binary search (lower_bound). O(log n) time.

from typing import List
import bisect


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        return bisect.bisect_left(nums, target)


if __name__ == "__main__":
    tests = [([1, 3, 5, 6], 5), ([1, 3, 5, 6], 2), ([1, 3, 5, 6], 7)]
    for i, (nums, target) in enumerate(tests):
        print(f"Test {i + 1}: {Solution().searchInsert(nums, target)}")

"""
Time Complexity: O(log n)
Space Complexity: O(1)
"""

# Topic: Binary Search
# Description: Search target value in sorted array efficiently using divide-and-conquer.
# Approach: Standard iterative binary search returning index or -1.

from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return -1


if __name__ == "__main__":
    tests = [([-1, 0, 3, 5, 9, 12], 9), ([1, 2, 3, 4, 5], 2)]
    sol = Solution()
    for i, (nums, target) in enumerate(tests):
        result = sol.search(nums, target)
        print(f"Test {i + 1}: target={target} -> {result}")

"""
Time Complexity: O(log n)
Space Complexity: O(1)
"""

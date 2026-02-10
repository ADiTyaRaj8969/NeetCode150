# Topic: Find Minimum in Rotated Sorted Array
# Description: Return smallest element in rotated sorted array without duplicates.
# Approach: Binary search using mid vs right to decide which half contains minimum.

from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = l + (r - l) // 2
            if nums[mid] > nums[r]:
                l = mid + 1
            else:
                r = mid
        return nums[l]


if __name__ == "__main__":
    tests = [[3, 4, 5, 1, 2], [4, 5, 6, 7, 0, 1, 2]]
    sol = Solution()
    for i, nums in enumerate(tests):
        result = sol.findMin(nums)
        print(f"Test {i + 1}: -> {result}")

"""
Time Complexity: O(log n)
Space Complexity: O(1)
"""

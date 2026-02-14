# Topic: House Robber
# Description: Given an array of non-negative integers representing money at each house, determine the maximum amount that can be robbed without robbing adjacent houses.
# Approach: Dynamic programming with two variables (prev and curr). O(n) time, O(1) space.

from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        prev, curr = 0, 0
        for x in nums:
            prev, curr = curr, max(curr, prev + x)
        return curr


if __name__ == "__main__":
    tests = [[1, 2, 3, 1], [2, 7, 9, 3, 1], [0]]
    for i, nums in enumerate(tests):
        print(f"Test {i + 1}: {Solution().rob(nums)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

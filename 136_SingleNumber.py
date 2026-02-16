# Topic: Single Number
# Description: Given a non-empty array of integers, every element appears twice except for one. Find that single one.
# Approach: XOR all numbers; pairs cancel out.

from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for num in nums:
            result ^= num
        return result


if __name__ == "__main__":
    tests = [[2, 2, 1], [4, 1, 2, 1, 2], [1]]
    for i, nums in enumerate(tests):
        print(f"Test {i + 1}: {Solution().singleNumber(nums)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

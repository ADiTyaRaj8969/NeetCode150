# Topic: Single Number II
# Description: Given an array of integers, every element appears three times except for one which
#              appears once. Find that single one.
# Approach: Count bits modulo 3 across 32 bit positions.

from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for i in range(32):
            bit_sum = 0
            for num in nums:
                if num < 0:
                    num = num & 0xFFFFFFFF  # Handle negative numbers
                bit_sum += (num >> i) & 1
            if bit_sum % 3:
                result |= (1 << i)
        # Handle negative result (Python integers are arbitrary precision)
        if result >= 2**31:
            result -= 2**32
        return result


if __name__ == "__main__":
    tests = [[2, 2, 3, 2], [0, 1, 0, 1, 0, 1, 99]]
    for i, nums in enumerate(tests):
        print(f"Test {i + 1}: {Solution().singleNumber(nums)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

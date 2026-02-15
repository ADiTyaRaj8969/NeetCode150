# Topic: Maximum Subarray
# Description: Find contiguous subarray with largest sum.
# Approach: Kadane's algorithm (DP in O(n) time, O(1) space).

from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        best = float('-inf')
        cur = 0
        for x in nums:
            cur = max(x, cur + x)
            best = max(best, cur)
        return best


if __name__ == "__main__":
    tests = [[-2, 1, -3, 4, -1, 2, 1, -5, 4], [1], [-1, -2, -3]]
    for i, nums in enumerate(tests):
        print(f"Test {i + 1}: {Solution().maxSubArray(nums)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

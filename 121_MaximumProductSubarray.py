# Topic: Maximum Product Subarray
# Description: Find the contiguous subarray within an array (containing at least one number) which
#              has the largest product.
# Approach: Track both maximum and minimum products at each position because negative numbers flip sign.

from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        max_prod = min_prod = result = nums[0]
        for i in range(1, len(nums)):
            x = nums[i]
            if x < 0:
                max_prod, min_prod = min_prod, max_prod
            max_prod = max(x, max_prod * x)
            min_prod = min(x, min_prod * x)
            result = max(result, max_prod)
        return result


if __name__ == "__main__":
    tests = [[2, 3, -2, 4], [-2, 0, -1], [0, 2]]
    for i, nums in enumerate(tests):
        print(f"Test {i + 1}: {Solution().maxProduct(nums)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

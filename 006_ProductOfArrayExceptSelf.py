# Topic: Product of Array Except Self
# Description: Compute array of products excluding the current element without division.
# Approach: Prefix and suffix products in two passes, O(n) time and O(1) extra space (output array not counted).

from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        out = [1] * n
        prefix = 1
        for i in range(n):
            out[i] = prefix
            prefix *= nums[i]
        suffix = 1
        for i in range(n - 1, -1, -1):
            out[i] *= suffix
            suffix *= nums[i]
        return out


if __name__ == "__main__":
    tests = [[1, 2, 3, 4], [0, 0], [-1, 1, 0]]
    sol = Solution()
    for i, nums in enumerate(tests):
        result = sol.productExceptSelf(nums)
        print(f"Test {i + 1}: {nums} -> {result}")

"""
Time Complexity: O(n)
Space Complexity: O(1) extra (excluding output)
"""

# Topic: Move Zeroes
# Description: Move all zeros in an array to the end while maintaining relative order of non-zero elements.
# Approach: Two-pointer in-place: write index for non-zero.

from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        j = 0  # position to write non-zero
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[j] = nums[i]
                j += 1
        while j < len(nums):
            nums[j] = 0
            j += 1


if __name__ == "__main__":
    tests = [[0, 1, 0, 3, 12], [0], [1, 2, 3]]
    for i, a in enumerate(tests):
        Solution().moveZeroes(a)
        print(f"Test {i + 1}: {a}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

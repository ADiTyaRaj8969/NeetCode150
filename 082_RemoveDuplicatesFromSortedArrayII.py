# Topic: Remove Duplicates from Sorted Array II
# Description: Given a sorted array, remove duplicates in-place such that duplicates are allowed at most twice.
# Approach: Two pointers. Maintain a write index and allow up to two copies.

from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return len(nums)
        j = 2  # next write position
        for i in range(2, len(nums)):
            if nums[i] != nums[j - 2]:
                nums[j] = nums[i]
                j += 1
        return j


if __name__ == "__main__":
    tests = [[1, 1, 1, 2, 2, 3], [0, 0, 1, 1, 1, 2], [1, 2, 3]]
    for i, a in enumerate(tests):
        length = Solution().removeDuplicates(a)
        print(f"Test {i + 1}: len={length} -> {a[:length]}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

# Topic: Sort Colors (Dutch National Flag)
# Description: Given an array with values 0,1,2 representing colors, sort in-place so that same colors are adjacent in order 0,1,2.
# Approach: Three-way partitioning (low, mid, high pointers). Single pass O(n), O(1) extra space.

from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        low, mid, high = 0, 0, len(nums) - 1
        while mid <= high:
            if nums[mid] == 0:
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else:
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1


if __name__ == "__main__":
    a = [2, 0, 2, 1, 1, 0]
    Solution().sortColors(a)
    print(a)

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

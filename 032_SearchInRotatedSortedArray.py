# Topic: Search in Rotated Sorted Array
# Description: Search element's index in rotated sorted array without duplicates.
# Approach: Modified binary search deciding which half is sorted.

from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                return mid
            if nums[l] <= nums[mid]:
                if nums[l] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
        return -1


if __name__ == "__main__":
    a = [4, 5, 6, 7, 0, 1, 2]
    sol = Solution()
    print(f"Test 1: target=0 -> {sol.search(a, 0)}")
    print(f"Test 2: target=3 -> {sol.search(a, 3)}")

"""
Time Complexity: O(log n)
Space Complexity: O(1)
"""

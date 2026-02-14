# Topic: Merge Sorted Array
# Description: Merge two sorted arrays where the first has enough space at the end to hold the second. Modify nums1 in-place.
# Approach: Merge from the end using three pointers.

from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i, j, k = m - 1, n - 1, m + n - 1
        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1


if __name__ == "__main__":
    tests = [([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3), ([1], 1, [], 0), ([0], 0, [1], 1)]
    for i, (nums1, m, nums2, n) in enumerate(tests):
        Solution().merge(nums1, m, nums2, n)
        print(f"Test {i + 1}: {nums1}")

"""
Time Complexity: O(m+n)
Space Complexity: O(1)
"""

# Topic: Median of Two Sorted Arrays
# Description: Find median from two individually sorted arrays.
# Approach: Binary search on partition in smaller array; O(log(min(m,n))).

from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        A, B = nums1, nums2
        if len(A) > len(B):
            A, B = B, A
        m, n = len(A), len(B)
        imin, imax = 0, m
        half = (m + n + 1) // 2
        
        while imin <= imax:
            i = (imin + imax) // 2
            j = half - i
            
            a_left = float('-inf') if i == 0 else A[i - 1]
            a_right = float('inf') if i == m else A[i]
            b_left = float('-inf') if j == 0 else B[j - 1]
            b_right = float('inf') if j == n else B[j]
            
            if a_left <= b_right and b_left <= a_right:
                if (m + n) % 2 == 1:
                    return max(a_left, b_left)
                return (max(a_left, b_left) + min(a_right, b_right)) / 2.0
            elif a_left > b_right:
                imax = i - 1
            else:
                imin = i + 1
        
        return 0.0


if __name__ == "__main__":
    sol = Solution()
    print(f"Test 1 -> {sol.findMedianSortedArrays([1, 3], [2]):.5f}")
    print(f"Test 2 -> {sol.findMedianSortedArrays([1, 2], [3, 4]):.5f}")

"""
Time Complexity: O(log(min(m,n)))
Space Complexity: O(1)
"""

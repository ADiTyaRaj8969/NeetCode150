# Topic: Search a 2D Matrix
# Description: Determine if target exists in sorted 2D matrix (rows and columns sorted such that flatten is sorted).
# Approach: Treat matrix as flattened sorted array and binary search.

from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        m, n = len(matrix), len(matrix[0])
        l, r = 0, m * n - 1
        while l <= r:
            mid = l + (r - l) // 2
            val = matrix[mid // n][mid % n]
            if val == target:
                return True
            if val < target:
                l = mid + 1
            else:
                r = mid - 1
        return False


if __name__ == "__main__":
    mats = [[[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], [[1]]]
    targets = [3, 2]
    sol = Solution()
    for i, (mat, target) in enumerate(zip(mats, targets)):
        result = sol.searchMatrix(mat, target)
        print(f"Test {i + 1}: target={target} -> {result}")

"""
Time Complexity: O(log(m*n)) = O(log m + log n)
Space Complexity: O(1)
"""

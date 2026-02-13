# Topic: Rotate Image
# Description: Rotate an n x n 2D matrix by 90 degrees clockwise in-place.
# Approach: Transpose the matrix, then reverse each row. In-place, O(1) extra space.

from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        # Transpose
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        # Reverse each row
        for row in matrix:
            row.reverse()


if __name__ == "__main__":
    mat1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    Solution().rotate(mat1)
    for row in mat1:
        print(row)
    print()

    mat2 = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]
    Solution().rotate(mat2)
    for row in mat2:
        print(row)

"""
Time Complexity: O(n^2)
Space Complexity: O(1) extra space
"""

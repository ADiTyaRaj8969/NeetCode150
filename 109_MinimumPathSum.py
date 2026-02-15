# Topic: Minimum Path Sum
# Description: Given a m x n grid of non-negative numbers, find a path from top-left to
#              bottom-right which minimizes sum of all numbers along its path.
# Approach: DP in-place or with O(n) rolling array. Using in-place modification.

from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                top = grid[i - 1][j] if i > 0 else float('inf')
                left = grid[i][j - 1] if j > 0 else float('inf')
                grid[i][j] += min(top, left)
        return grid[m - 1][n - 1]


if __name__ == "__main__":
    tests = [[[1, 3, 1], [1, 5, 1], [4, 2, 1]], [[1, 2, 3], [4, 5, 6]], [[5]]]
    for i, grid in enumerate(tests):
        # Deep copy to avoid modifying original
        g = [row[:] for row in grid]
        print(f"Test {i + 1}: {Solution().minPathSum(g)}")

"""
Time Complexity: O(m*n)
Space Complexity: O(1) extra (in-place)
"""

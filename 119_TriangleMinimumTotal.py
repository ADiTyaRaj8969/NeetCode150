# Topic: Triangle (Minimum Total)
# Description: Given a triangle array, return minimum path sum from top to bottom.
# Approach: Bottom-up DP modifying last row (O(n) space where n is width of triangle base).

from typing import List


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle:
            return 0
        n = len(triangle)
        dp = triangle[-1][:]
        for layer in range(n - 2, -1, -1):
            for i in range(layer + 1):
                dp[i] = triangle[layer][i] + min(dp[i], dp[i + 1])
        return dp[0]


if __name__ == "__main__":
    tests = [[[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]], [[-10]]]
    for i, triangle in enumerate(tests):
        print(f"Test {i + 1}: {Solution().minimumTotal(triangle)}")

"""
Time Complexity: O(n^2)
Space Complexity: O(n)
"""

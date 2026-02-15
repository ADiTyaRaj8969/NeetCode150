# Topic: Unique Paths
# Description: Number of unique paths from top-left to bottom-right in m x n grid moving only right/down.
# Approach: DP with O(n) space.


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [1] * n
        for i in range(1, m):
            for j in range(1, n):
                dp[j] += dp[j - 1]
        return dp[n - 1]


if __name__ == "__main__":
    tests = [(3, 7), (3, 2), (1, 1)]
    for i, (m, n) in enumerate(tests):
        print(f"Test {i + 1}: {Solution().uniquePaths(m, n)}")

"""
Time Complexity: O(m*n)
Space Complexity: O(n)
"""

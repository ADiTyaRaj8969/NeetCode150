# Topic: Unique Binary Search Trees
# Description: Given n, return number of structurally unique BSTs that store values 1..n.
# Approach: DP using Catalan numbers: dp[n] = sum_{i=1..n} dp[i-1]*dp[n-i].


class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[0] = 1
        for length in range(1, n + 1):
            for root in range(1, length + 1):
                dp[length] += dp[root - 1] * dp[length - root]
        return dp[n]


if __name__ == "__main__":
    tests = [3, 0, 1]
    for i, n in enumerate(tests):
        print(f"Test {i + 1} (n={n}): {Solution().numTrees(n)}")

"""
Time Complexity: O(n^2)
Space Complexity: O(n)
"""

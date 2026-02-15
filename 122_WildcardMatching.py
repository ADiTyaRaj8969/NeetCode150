# Topic: Wildcard Matching
# Description: Implement wildcard pattern matching with '?' and '*' where '?' matches any single
#              char and '*' matches any sequence of chars.
# Approach: DP with dp[i][j] indicating if s[0..i-1] matches p[0..j-1].


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)
        dp = [[False] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = True
        for j in range(1, m + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 1]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if p[j - 1] == '?' or p[j - 1] == s[i - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]
        return dp[n][m]


if __name__ == "__main__":
    tests = [("aa", "a"), ("aa", "*"), ("cb", "?b")]
    for i, (s, p) in enumerate(tests):
        print(f"Test {i + 1}: {Solution().isMatch(s, p)}")

"""
Time Complexity: O(n*m)
Space Complexity: O(n*m) (can be reduced to O(n))
"""

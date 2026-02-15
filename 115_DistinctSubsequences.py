# Topic: Distinct Subsequences
# Description: Count number of distinct subsequences of s which equals t.
# Approach: DP (1D rolling) with dp[0]=1 and update backwards for matches.


class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        dp = [0] * (m + 1)
        dp[0] = 1
        for i in range(n):
            for j in range(m, 0, -1):
                if s[i] == t[j - 1]:
                    dp[j] += dp[j - 1]
        return dp[m]


if __name__ == "__main__":
    tests = [("rabbbit", "rabbit"), ("babgbag", "bag"), ("", "")]
    for i, (s, t) in enumerate(tests):
        print(f"Test {i + 1}: {Solution().numDistinct(s, t)}")

"""
Time Complexity: O(n*m)
Space Complexity: O(m)
"""

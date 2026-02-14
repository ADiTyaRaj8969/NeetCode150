# Topic: Interleaving String
# Description: Given s1, s2, s3 determine if s3 is formed by interleaving s1 and s2.
# Approach: 2D DP where dp[i][j] means s3[0..i+j-1] can be formed using s1[0..i-1] and s2[0..j-1].


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n1, n2, n3 = len(s1), len(s2), len(s3)
        if n1 + n2 != n3:
            return False
        dp = [[False] * (n2 + 1) for _ in range(n1 + 1)]
        dp[0][0] = True
        for i in range(n1 + 1):
            for j in range(n2 + 1):
                if i > 0:
                    dp[i][j] = dp[i][j] or (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1])
                if j > 0:
                    dp[i][j] = dp[i][j] or (dp[i][j - 1] and s2[j - 1] == s3[i + j - 1])
        return dp[n1][n2]


if __name__ == "__main__":
    tests = [("aabcc", "dbbca", "aadbbcbcac"), ("aabcc", "dbbca", "aadbbbaccc"), ("", "", "")]
    for i, (s1, s2, s3) in enumerate(tests):
        print(f"Test {i + 1}: {Solution().isInterleave(s1, s2, s3)}")

"""
Time Complexity: O(n1 * n2)
Space Complexity: O(n1 * n2) (can be reduced to O(min(n1,n2)))
"""

# Topic: Decode Ways
# Description: Given a string of digits, count how many ways it can be decoded (1->A, 2->B, ..., 26->Z).
# Approach: DP - ways[i] = number ways to decode suffix starting at i; compute iteratively from end.


class Solution:
    def numDecodings(self, s: str) -> int:
        if not s:
            return 0
        n = len(s)
        dp = [0] * (n + 1)
        dp[n] = 1  # empty string
        for i in range(n - 1, -1, -1):
            if s[i] == '0':
                dp[i] = 0
                continue
            dp[i] = dp[i + 1]
            if i + 1 < n:
                val = int(s[i:i + 2])
                if 10 <= val <= 26:
                    dp[i] += dp[i + 2]
        return dp[0]


if __name__ == "__main__":
    tests = ["12", "226", "0"]
    for i, s in enumerate(tests):
        print(f"Test {i + 1}: {Solution().numDecodings(s)}")

"""
Time Complexity: O(n)
Space Complexity: O(n) (can be reduced to O(1))
"""

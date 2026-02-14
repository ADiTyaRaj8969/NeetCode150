# Topic: Scramble String
# Description: Determine if one string is a scramble of another (binary partition + possible swap at each split).
# Approach: Recursion with memoization and early pruning using character counts.

from functools import lru_cache
from collections import Counter


class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        @lru_cache(maxsize=None)
        def dfs(i1, i2, length):
            if s1[i1:i1 + length] == s2[i2:i2 + length]:
                return True
            if Counter(s1[i1:i1 + length]) != Counter(s2[i2:i2 + length]):
                return False
            for cut in range(1, length):
                # no swap
                if dfs(i1, i2, cut) and dfs(i1 + cut, i2 + cut, length - cut):
                    return True
                # swap
                if dfs(i1, i2 + length - cut, cut) and dfs(i1 + cut, i2, length - cut):
                    return True
            return False

        return dfs(0, 0, len(s1))


if __name__ == "__main__":
    tests = [("great", "rgeat"), ("abcde", "caebd"), ("a", "a")]
    for i, (s1, s2) in enumerate(tests):
        print(f"Test {i + 1}: {Solution().isScramble(s1, s2)}")

"""
Time Complexity: Exponential worst-case without memo; memo reduces repeated states
Space Complexity: O(n^3) in worst-case for memoization storage
"""

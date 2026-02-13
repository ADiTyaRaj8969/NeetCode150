# Topic: Palindrome Partitioning
# Description: Split string into all possible palindrome partitions.
# Approach: Backtracking with palindrome check (expand or DP precompute). We'll use memoization.

from typing import List
from functools import lru_cache


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        result = []
        cur = []

        @lru_cache(maxsize=None)
        def is_pal(l, r):
            if l >= r:
                return True
            return s[l] == s[r] and is_pal(l + 1, r - 1)

        def dfs(idx):
            if idx == n:
                result.append(cur[:])
                return
            for j in range(idx, n):
                if is_pal(idx, j):
                    cur.append(s[idx:j + 1])
                    dfs(j + 1)
                    cur.pop()

        dfs(0)
        return result


if __name__ == "__main__":
    tests = ["aab", "a"]
    for i, s in enumerate(tests):
        print(f'Test {i + 1}: "{s}" ->')
        result = Solution().partition(s)
        for v in result:
            print(v)

"""
Time Complexity: O(n * 2^n) in worst case
Space Complexity: O(n^2) for memo + O(n) recursion
"""

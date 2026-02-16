# Topic: Palindrome Partitioning
# Description: Given a string s, partition s such that every substring of the partition is a palindrome.
#              Return all possible palindrome partitioning of s.
# Approach: Backtracking with palindrome check.

from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        result = []
        path = []

        def is_palindrome(left: int, right: int) -> bool:
            while left < right:
                if s[left] != s[right]:
                    return False
                left += 1
                right -= 1
            return True

        def dfs(idx: int) -> None:
            if idx == len(s):
                result.append(path[:])
                return
            for j in range(idx, len(s)):
                if is_palindrome(idx, j):
                    path.append(s[idx:j + 1])
                    dfs(j + 1)
                    path.pop()

        dfs(0)
        return result


if __name__ == "__main__":
    tests = ["aab", "a", "racecar"]
    for i, s in enumerate(tests):
        result = Solution().partition(s)
        print(f"Test {i + 1} (s=\"{s}\"): count={len(result)}")
        for p in result:
            print(f"  {p}")

"""
Time Complexity: Exponential in worst-case (output-sensitive)
Space Complexity: O(n) recursion + output size
"""

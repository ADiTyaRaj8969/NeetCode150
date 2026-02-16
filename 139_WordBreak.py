# Topic: Word Break
# Description: Given a string s and a dictionary of words, determine if s can be segmented into a
#              sequence of dictionary words.
# Approach: DP where dp[i] = true if s[0..i) can be segmented.

from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(1, n + 1):
            for j in range(i):
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True
                    break
        return dp[n]


if __name__ == "__main__":
    tests = [("leetcode", ["leet", "code"]),
             ("applepenapple", ["apple", "pen"]),
             ("catsandog", ["cats", "dog", "sand", "and", "cat"])]
    for i, (s, word_dict) in enumerate(tests):
        print(f"Test {i + 1}: {Solution().wordBreak(s, word_dict)}")

"""
Time Complexity: O(n^2 * k) where k is average substring creation cost, can be optimized with trie
Space Complexity: O(n + dict)
"""

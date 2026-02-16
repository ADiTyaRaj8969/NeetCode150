# Topic: Word Break II
# Description: Given a string s and a dictionary, return all possible sentences where words are separated by spaces.
# Approach: DFS with memoization (backtracking + DP) to avoid recomputation.

from typing import List, Dict


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        word_set = set(wordDict)
        memo: Dict[int, List[str]] = {}

        def dfs(start: int) -> List[str]:
            if start in memo:
                return memo[start]
            if start == len(s):
                return [""]
            result = []
            for end in range(start + 1, len(s) + 1):
                word = s[start:end]
                if word in word_set:
                    tails = dfs(end)
                    for tail in tails:
                        sentence = word + (" " + tail if tail else "")
                        result.append(sentence)
            memo[start] = result
            return result

        return dfs(0)


if __name__ == "__main__":
    tests = [("catsanddog", ["cat", "cats", "and", "sand", "dog"]),
             ("pineapplepenapple", ["apple", "pen", "applepen", "pine", "pineapple"])]
    for i, (s, word_dict) in enumerate(tests):
        result = Solution().wordBreak(s, word_dict)
        print(f"Test {i + 1}: s=\"{s}\"")
        print(f"  Count={len(result)}")
        for sentence in result:
            print(f"    {sentence}")

"""
Time Complexity: Exponential in worst-case but memoization prunes; depends on number of valid segmentations
Space Complexity: O(n * average sentence length + memo)
"""

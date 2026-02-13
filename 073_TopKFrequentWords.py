# Topic: Top K Frequent Words
# Description: Given a list of words, return the k most frequent words. If frequencies tie, return lexicographically smaller first.
# Approach: Count frequencies with Counter, then sort with custom comparator.

from typing import List
from collections import Counter


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = Counter(words)
        # Sort by frequency desc, then alphabetically asc
        uniq = sorted(cnt.keys(), key=lambda w: (-cnt[w], w))
        return uniq[:k]


if __name__ == "__main__":
    words = ["i", "love", "leetcode", "i", "love", "coding"]
    result = Solution().topKFrequent(words, 2)
    for s in result:
        print(s)

"""
Time Complexity: O(m log m) where m = number of unique words (plus O(n) to count)
Space Complexity: O(m)
"""

# Topic: Word Ladder
# Description: Given beginWord, endWord, and a dictionary, return length of shortest transformation sequence.
# Approach: BFS over words using generic transformations.

from typing import List
from collections import deque


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        word_set = set(wordList)
        if endWord not in word_set:
            return 0
        queue = deque([(beginWord, 1)])
        seen = {beginWord}
        while queue:
            word, dist = queue.popleft()
            if word == endWord:
                return dist
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    if c == word[i]:
                        continue
                    new_word = word[:i] + c + word[i + 1:]
                    if new_word in word_set and new_word not in seen:
                        seen.add(new_word)
                        queue.append((new_word, dist + 1))
        return 0


if __name__ == "__main__":
    tests = [("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]),
             ("hit", "cog", ["hot", "dot", "dog", "lot", "log"])]
    for i, (begin, end, words) in enumerate(tests):
        print(f"Test {i + 1}: {Solution().ladderLength(begin, end, words)}")

"""
Time Complexity: O(N * L * 26) where L is word length
Space Complexity: O(N)
"""

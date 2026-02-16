# Topic: Word Ladder II
# Description: Find all shortest transformation sequences from beginWord to endWord.
# Approach: BFS to build distance map, then DFS backtracking to collect all shortest paths.

from typing import List
from collections import deque


class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        word_set = set(wordList)
        if endWord not in word_set:
            return []
        word_set.add(beginWord)

        # BFS to build distance map
        dist = {beginWord: 0}
        queue = deque([beginWord])
        while queue:
            word = queue.popleft()
            d = dist[word]
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    if c == word[i]:
                        continue
                    new_word = word[:i] + c + word[i + 1:]
                    if new_word in word_set and new_word not in dist:
                        dist[new_word] = d + 1
                        queue.append(new_word)

        if endWord not in dist:
            return []

        # DFS to collect all shortest paths
        result = []

        def dfs(word: str, path: List[str]) -> None:
            if word == endWord:
                result.append(path[:])
                return
            d = dist[word]
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    if c == word[i]:
                        continue
                    new_word = word[:i] + c + word[i + 1:]
                    if new_word in dist and dist[new_word] == d + 1:
                        path.append(new_word)
                        dfs(new_word, path)
                        path.pop()

        dfs(beginWord, [beginWord])
        return result


if __name__ == "__main__":
    tests = [("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]),
             ("a", "c", ["a", "b", "c"])]
    for i, (begin, end, words) in enumerate(tests):
        result = Solution().findLadders(begin, end, words)
        print(f"Test {i + 1}:")
        for path in result:
            print(f"  {' -> '.join(path)}")

"""
Time Complexity: O(N * L * 26 + P) where P is total path length
Space Complexity: O(N * L)
"""

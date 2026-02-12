# Topic: Word Search II
# Description: Find all words present on board using Trie and backtracking.
# Approach: Build Trie of words, DFS from each cell, mark visited and collect words when Trie node is end.

from typing import List


class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # Build Trie
        root = TrieNode()
        for w in words:
            node = root
            for c in w:
                if c not in node.children:
                    node.children[c] = TrieNode()
                node = node.children[c]
            node.word = w

        m, n = len(board), len(board[0])
        result = []

        def dfs(i, j, node):
            c = board[i][j]
            if c == '#' or c not in node.children:
                return
            nxt = node.children[c]
            if nxt.word:
                result.append(nxt.word)
                nxt.word = None  # avoid duplicates
            board[i][j] = '#'
            for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n:
                    dfs(ni, nj, nxt)
            board[i][j] = c

        for i in range(m):
            for j in range(n):
                dfs(i, j, root)

        return result


if __name__ == "__main__":
    board = [['o', 'a', 'a', 'n'], ['e', 't', 'a', 'e'], ['i', 'h', 'k', 'r'], ['i', 'f', 'l', 'v']]
    words = ["oath", "pea", "eat", "rain"]
    result = Solution().findWords(board, words)
    print(result)

"""
Time Complexity: O(m*n*4^L) worst case, L = max word length, but trie + pruning reduces work
Space Complexity: O(sum length of words + recursion depth)
"""

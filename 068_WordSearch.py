# Topic: Word Search
# Description: Determine if a word exists in grid sequentially (adjacent cells, no reuse).
# Approach: Backtracking DFS with visited marking.

from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])

        def dfs(i, j, idx):
            if idx == len(word):
                return True
            if i < 0 or j < 0 or i >= m or j >= n or board[i][j] != word[idx]:
                return False
            tmp = board[i][j]
            board[i][j] = '#'
            found = (dfs(i - 1, j, idx + 1) or dfs(i + 1, j, idx + 1) or
                     dfs(i, j - 1, idx + 1) or dfs(i, j + 1, idx + 1))
            board[i][j] = tmp
            return found

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0] and dfs(i, j, 0):
                    return True
        return False


if __name__ == "__main__":
    board = [['A', 'B', 'C', 'E'], ['S', 'F', 'C', 'S'], ['A', 'D', 'E', 'E']]
    print(f"Test 1 (ABCCED) -> {Solution().exist(board, 'ABCCED')}")
    print(f"Test 2 (SEE) -> {Solution().exist(board, 'SEE')}")
    print(f"Test 3 (ABCB) -> {Solution().exist(board, 'ABCB')}")

"""
Time Complexity: O(m*n * 4^L) worst-case where L is word length
Space Complexity: O(L) recursion depth
"""

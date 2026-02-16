# Topic: Surrounded Regions
# Description: Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
#              Replace surrounded 'O's with 'X'.
# Approach: Flood-fill from border 'O's to mark safe cells, then flip remaining 'O's to 'X', restore marked.

from typing import List
from collections import deque


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        if not board or not board[0]:
            return
        m, n = len(board), len(board[0])
        queue = deque()

        # Mark border 'O's and connected 'O's
        for i in range(m):
            if board[i][0] == 'O':
                queue.append((i, 0))
                board[i][0] = 'T'
            if board[i][n - 1] == 'O':
                queue.append((i, n - 1))
                board[i][n - 1] = 'T'
        for j in range(n):
            if board[0][j] == 'O':
                queue.append((0, j))
                board[0][j] = 'T'
            if board[m - 1][j] == 'O':
                queue.append((m - 1, j))
                board[m - 1][j] = 'T'

        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        while queue:
            r, c = queue.popleft()
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and board[nr][nc] == 'O':
                    board[nr][nc] = 'T'
                    queue.append((nr, nc))

        # Flip 'O' to 'X' and 'T' back to 'O'
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == 'T':
                    board[i][j] = 'O'


if __name__ == "__main__":
    tests = [[['X', 'O', 'X'], ['O', 'X', 'O'], ['X', 'O', 'X']],
             [['X', 'X', 'X', 'X'], ['X', 'O', 'O', 'X'], ['X', 'X', 'O', 'X'], ['X', 'O', 'X', 'X']]]
    for i, board in enumerate(tests):
        # Deep copy
        b = [row[:] for row in board]
        Solution().solve(b)
        print(f"Test {i + 1}:")
        for row in b:
            print(''.join(row))

"""
Time Complexity: O(m*n)
Space Complexity: O(m*n) for BFS queue in worst case
"""

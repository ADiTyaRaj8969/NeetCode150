# Topic: N-Queens
# Description: Place n queens on an n x n board so that no two queens attack each other.
# Approach: Backtracking with sets for columns and diagonals for O(n!) worst-case with pruning.

from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []
        cols = [-1] * n
        col_used = set()
        diag1 = set()  # r - c
        diag2 = set()  # r + c

        def dfs(r):
            if r == n:
                board = ['.' * c + 'Q' + '.' * (n - c - 1) for c in cols]
                result.append(board)
                return
            for c in range(n):
                if c in col_used or (r - c) in diag1 or (r + c) in diag2:
                    continue
                cols[r] = c
                col_used.add(c)
                diag1.add(r - c)
                diag2.add(r + c)
                dfs(r + 1)
                col_used.remove(c)
                diag1.remove(r - c)
                diag2.remove(r + c)

        dfs(0)
        return result


if __name__ == "__main__":
    n = 4
    ans = Solution().solveNQueens(n)
    print(f"Solutions for n={n} -> {len(ans)}")
    for board in ans:
        for row in board:
            print(row)
        print()

"""
Time Complexity: O(n!) worst-case (backtracking), heavy pruning reduces actual runtime
Space Complexity: O(n^2) for storing solutions (plus O(n) recursion)
"""

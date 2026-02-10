# Topic: Valid Sudoku
# Description: Validate if a 9x9 Sudoku board is correctly filled so far.
# Approach: Check rows, columns and 3x3 boxes using sets or bitmasks.

from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [0] * 9
        cols = [0] * 9
        boxes = [0] * 9
        
        for r in range(9):
            for c in range(9):
                ch = board[r][c]
                if ch == '.':
                    continue
                d = int(ch) - 1
                mask = 1 << d
                if rows[r] & mask:
                    return False
                if cols[c] & mask:
                    return False
                b = (r // 3) * 3 + (c // 3)
                if boxes[b] & mask:
                    return False
                rows[r] |= mask
                cols[c] |= mask
                boxes[b] |= mask
        return True


if __name__ == "__main__":
    tests = [
        ["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", 
         "7...2...6", ".6....28.", "...419..5", "....8..79"],
        ["83..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", 
         "7...2...6", ".6....28.", "...419..5", "....8..79"]
    ]
    sol = Solution()
    for i, test in enumerate(tests):
        board = [list(row) for row in test]
        result = sol.isValidSudoku(board)
        print(f"Test {i + 1} -> {result}")

"""
Time Complexity: O(1) (9x9 constant) ~ O(81)
Space Complexity: O(1)
"""

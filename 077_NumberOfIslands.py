# Topic: Number of Islands
# Description: Given a 2D grid of '1's (land) and '0's (water), count islands (connected components of 1s).
# Approach: DFS/BFS flood-fill to mark visited land. Time O(m*n), space O(m*n) recursion/queue.

from typing import List
from collections import deque


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        count = 0
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    count += 1
                    # BFS
                    q = deque([(i, j)])
                    grid[i][j] = '0'
                    while q:
                        r, c = q.popleft()
                        for dr, dc in dirs:
                            nr, nc = r + dr, c + dc
                            if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == '1':
                                grid[nr][nc] = '0'
                                q.append((nr, nc))
        return count


if __name__ == "__main__":
    tests = [
        [["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"], ["1", "1", "0", "0", "0"], ["0", "0", "0", "0", "0"]],
        [["1", "1", "0", "0", "0"], ["1", "1", "0", "0", "0"], ["0", "0", "1", "0", "0"], ["0", "0", "0", "1", "1"]],
    ]
    for i, grid in enumerate(tests):
        print(f"Test {i + 1}: {Solution().numIslands(grid)}")

"""
Time Complexity: O(m * n)
Space Complexity: O(min(m, n)) for BFS queue in worst-case
"""

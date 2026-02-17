# Topic: Max Points on a Line
# Description: Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
# Approach: For each point, build a hashmap of slopes to counts. Handle duplicates and vertical lines. O(n^2) time.

from typing import List
from math import gcd
from collections import defaultdict


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n < 3:
            return n
        best = 0
        for i in range(n):
            cnt = defaultdict(int)
            dup = 0
            local_max = 0
            for j in range(i + 1, n):
                dx = points[j][0] - points[i][0]
                dy = points[j][1] - points[i][1]
                if dx == 0 and dy == 0:
                    dup += 1
                    continue
                g = gcd(dx, dy)
                dx //= g
                dy //= g
                # Normalize sign
                if dx < 0:
                    dx, dy = -dx, -dy
                elif dx == 0 and dy < 0:
                    dy = -dy
                key = (dx, dy)
                cnt[key] += 1
                local_max = max(local_max, cnt[key])
            best = max(best, local_max + dup + 1)
        return best


if __name__ == "__main__":
    tests = [[[1, 1], [2, 2], [3, 3]],
             [[1, 1], [3, 2], [5, 3], [4, 1], [2, 3], [1, 4]]]
    for i, points in enumerate(tests):
        print(f"Test {i + 1}: {Solution().maxPoints(points)}")

"""
Time Complexity: O(n^2)
Space Complexity: O(n)
"""

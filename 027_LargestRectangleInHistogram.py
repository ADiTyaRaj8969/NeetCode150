# Topic: Largest Rectangle in Histogram
# Description: Find largest rectangular area in histogram bars.
# Approach: Monotonic stack of indices to compute nearest smaller to left/right in O(n).

from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stack = []
        best = 0
        for i in range(n + 1):
            h = heights[i] if i < n else 0
            while stack and h < heights[stack[-1]]:
                height = heights[stack.pop()]
                left = stack[-1] if stack else -1
                best = max(best, height * (i - left - 1))
            stack.append(i)
        return best


if __name__ == "__main__":
    tests = [[2, 1, 5, 6, 2, 3], [2, 4]]
    sol = Solution()
    for i, heights in enumerate(tests):
        result = sol.largestRectangleArea(heights)
        print(f"Test {i + 1}: {result}")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

# Topic: Container With Most Water
# Description: Maximize area formed by two lines and x-axis.
# Approach: Two-pointer narrowing; maximize area by moving the smaller height pointer.

from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        best = 0
        while l < r:
            h = min(height[l], height[r])
            best = max(best, h * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return best


if __name__ == "__main__":
    tests = [[1, 8, 6, 2, 5, 4, 8, 3, 7], [1, 1]]
    sol = Solution()
    for i, height in enumerate(tests):
        result = sol.maxArea(height)
        print(f"Test {i + 1}: {height} -> {result}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

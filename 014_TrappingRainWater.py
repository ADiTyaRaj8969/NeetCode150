# Topic: Trapping Rain Water
# Description: Compute trapped rainwater between elevation bars.
# Approach: Two-pointer keeping left_max and right_max to compute water in O(n) time and O(1) space.

from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        l, r = 0, len(height) - 1
        left_max, right_max = 0, 0
        res = 0
        while l < r:
            if height[l] < height[r]:
                if height[l] >= left_max:
                    left_max = height[l]
                else:
                    res += left_max - height[l]
                l += 1
            else:
                if height[r] >= right_max:
                    right_max = height[r]
                else:
                    res += right_max - height[r]
                r -= 1
        return res


if __name__ == "__main__":
    tests = [[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], [4, 2, 0, 3, 2, 5]]
    sol = Solution()
    for i, height in enumerate(tests):
        result = sol.trap(height)
        print(f"Test {i + 1}: {height} -> {result}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

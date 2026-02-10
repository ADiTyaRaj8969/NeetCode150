# Topic: Two Sum II - Input array is sorted
# Description: Find two numbers in a sorted array that sum to a target.
# Approach: Two-pointer from both ends, O(n) time, O(1) space.

from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1
        while l < r:
            s = numbers[l] + numbers[r]
            if s == target:
                return [l + 1, r + 1]  # 1-based index
            if s < target:
                l += 1
            else:
                r -= 1
        return [-1, -1]


if __name__ == "__main__":
    tests = [([2, 7, 11, 15], 9), ([2, 3, 4], 6)]
    sol = Solution()
    for i, (nums, target) in enumerate(tests):
        result = sol.twoSum(nums, target)
        print(f"Test {i + 1}: {nums} target={target} -> {result[0]},{result[1]}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

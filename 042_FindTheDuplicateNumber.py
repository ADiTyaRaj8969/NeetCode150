# Topic: Find the Duplicate Number
# Description: Identify duplicate element in array where numbers are in range [1,n] with one duplicate.
# Approach: Floyd's Tortoise and Hare cycle detection on value-index mapping, O(n) time, O(1) space.

from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        tortoise = hare = nums[0]
        while True:
            tortoise = nums[tortoise]
            hare = nums[nums[hare]]
            if tortoise == hare:
                break
        tortoise = nums[0]
        while tortoise != hare:
            tortoise = nums[tortoise]
            hare = nums[hare]
        return hare


if __name__ == "__main__":
    tests = [[1, 3, 4, 2, 2], [3, 1, 3, 4, 2]]
    sol = Solution()
    for i, nums in enumerate(tests):
        print(f"Test {i + 1} -> {sol.findDuplicate(nums)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

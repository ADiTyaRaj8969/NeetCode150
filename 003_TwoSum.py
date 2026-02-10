# Topic: Two Sum
# Description: Find two indices whose elements sum up to a target value.
# Approach: Single-pass hashmap to store seen numbers and their indices.

from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        for i, num in enumerate(nums):
            need = target - num
            if need in mp:
                return [mp[need], i]
            mp[num] = i
        return []


if __name__ == "__main__":
    tests = [([2, 7, 11, 15], 9), ([3, 2, 4], 6), ([3, 3], 6)]
    sol = Solution()
    for i, (nums, target) in enumerate(tests):
        result = sol.twoSum(nums, target)
        if result:
            print(f"Test {i + 1}: {nums} target={target} -> {result[0]},{result[1]}")
        else:
            print(f"Test {i + 1}: {nums} target={target} -> No solution")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

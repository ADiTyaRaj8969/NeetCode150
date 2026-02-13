# Topic: Majority Element
# Description: Given an array of size n, find the majority element (appears more than n/2 times).
# Approach: Boyer-Moore Voting Algorithm (O(n) time, O(1) space).

from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        candidate = 0
        for num in nums:
            if count == 0:
                candidate = num
            count += 1 if num == candidate else -1
        return candidate


if __name__ == "__main__":
    tests = [[3, 2, 3], [2, 2, 1, 1, 1, 2, 2], [1]]
    for i, nums in enumerate(tests):
        print(f"Test {i + 1}: {Solution().majorityElement(nums)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

# Topic: Longest Consecutive Sequence
# Description: Find length of the longest consecutive number sequence in an array.
# Approach: Use set to expand sequences starting from numbers that are sequence starts.

from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        best = 0
        for x in nums:
            if x - 1 not in s:  # start of a sequence
                cur = 1
                while x + cur in s:
                    cur += 1
                best = max(best, cur)
        return best


if __name__ == "__main__":
    tests = [[100, 4, 200, 1, 3, 2], [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]]
    sol = Solution()
    for i, test in enumerate(tests):
        result = sol.longestConsecutive(test)
        print(f"Test {i + 1}: {test} -> {result}")

"""
Time Complexity: O(n) average
Space Complexity: O(n)
"""

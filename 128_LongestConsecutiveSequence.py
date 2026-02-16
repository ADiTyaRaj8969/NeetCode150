# Topic: Longest Consecutive Sequence
# Description: Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
# Approach: Use a set for O(1) lookup. For each number that is the start of a sequence (num-1 not in set),
#          count consecutive numbers.

from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        best = 0
        for num in num_set:
            if num - 1 in num_set:
                continue  # not start of sequence
            cur = num
            length = 1
            while cur + 1 in num_set:
                cur += 1
                length += 1
            best = max(best, length)
        return best


if __name__ == "__main__":
    tests = [[100, 4, 200, 1, 3, 2], [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]]
    for i, nums in enumerate(tests):
        print(f"Test {i + 1}: {Solution().longestConsecutive(nums)}")

"""
Time Complexity: O(n) average
Space Complexity: O(n)
"""

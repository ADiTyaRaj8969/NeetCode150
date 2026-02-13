# Topic: Longest Increasing Subsequence
# Description: Find length of LIS in O(n log n) using patience sorting (tails + binary search).
# Approach: Maintain tails where tails[len] = smallest ending value of an increasing subsequence of length len+1.

from typing import List
import bisect


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        tails = []
        for x in nums:
            pos = bisect.bisect_left(tails, x)
            if pos == len(tails):
                tails.append(x)
            else:
                tails[pos] = x
        return len(tails)


if __name__ == "__main__":
    tests = [[10, 9, 2, 5, 3, 7, 101, 18], [0], [3, 1, 2]]
    for i, a in enumerate(tests):
        print(f"Test {i + 1}: {Solution().lengthOfLIS(a)}")

"""
Time Complexity: O(n log n)
Space Complexity: O(n)
"""

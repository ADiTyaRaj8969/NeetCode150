# Topic: Subsets
# Description: Generate all possible subsets of a list.
# Approach: Backtracking or iterative bitmask. We'll use backtracking.

from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        cur = []

        def dfs(idx):
            result.append(cur[:])
            for i in range(idx, len(nums)):
                cur.append(nums[i])
                dfs(i + 1)
                cur.pop()

        dfs(0)
        return result


if __name__ == "__main__":
    nums = [1, 2, 3]
    result = Solution().subsets(nums)
    for s in result:
        print(s)

"""
Time Complexity: O(n * 2^n) total output size
Space Complexity: O(n) recursion depth + output
"""

# Topic: Subsets II
# Description: Generate unique subsets avoiding duplicates.
# Approach: Sort input and backtrack skipping duplicates at the same recursion level.

from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        cur = []

        def dfs(idx):
            result.append(cur[:])
            for i in range(idx, len(nums)):
                if i > idx and nums[i] == nums[i - 1]:
                    continue
                cur.append(nums[i])
                dfs(i + 1)
                cur.pop()

        dfs(0)
        return result


if __name__ == "__main__":
    nums = [1, 2, 2]
    result = Solution().subsetsWithDup(nums)
    for v in result:
        print(v)

"""
Time Complexity: O(n * 2^n) worst-case (output size)
Space Complexity: O(n) recursion depth + output
"""

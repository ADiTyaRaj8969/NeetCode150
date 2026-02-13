# Topic: Permutations
# Description: Return all possible orderings of elements.
# Approach: Backtracking swapping or using used array. We'll use in-place swapping.

from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []

        def dfs(start):
            if start == len(nums):
                result.append(nums[:])
                return
            for i in range(start, len(nums)):
                nums[start], nums[i] = nums[i], nums[start]
                dfs(start + 1)
                nums[start], nums[i] = nums[i], nums[start]

        dfs(0)
        return result


if __name__ == "__main__":
    nums = [1, 2, 3]
    result = Solution().permute(nums)
    for v in result:
        print(v)

"""
Time Complexity: O(n! * n) to generate all permutations
Space Complexity: O(n) recursion depth + output
"""

# Topic: 3Sum
# Description: Return all unique triplets that sum to zero without duplicates.
# Approach: Sort and use two-pointer for each fixed i, skip duplicates.

from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            target = -nums[i]
            l, r = i + 1, len(nums) - 1
            while l < r:
                s = nums[l] + nums[r]
                if s == target:
                    res.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif s < target:
                    l += 1
                else:
                    r -= 1
        return res


if __name__ == "__main__":
    tests = [[-1, 0, 1, 2, -1, -4], [0, 0, 0, 0]]
    sol = Solution()
    for i, nums in enumerate(tests):
        print(f"Test {i + 1}: {nums} ->")
        result = sol.threeSum(nums)
        for trip in result:
            print(','.join(map(str, trip)))
        print()

"""
Time Complexity: O(n^2)
Space Complexity: O(log n) for sort or O(n) depending on sort implementation
"""

# Topic: Sliding Window Maximum
# Description: Return maximum value from every window of size k.
# Approach: Use deque to maintain indices of candidates (monotonic queue).

from typing import List
from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()  # store indices, decreasing values
        res = []
        for i in range(len(nums)):
            while dq and dq[0] <= i - k:
                dq.popleft()
            while dq and nums[dq[-1]] <= nums[i]:
                dq.pop()
            dq.append(i)
            if i >= k - 1:
                res.append(nums[dq[0]])
        return res


if __name__ == "__main__":
    tests = [([1, 3, -1, -3, 5, 3, 6, 7], 3), ([1], 1), ([1, -1], 1)]
    sol = Solution()
    for i, (nums, k) in enumerate(tests):
        result = sol.maxSlidingWindow(nums, k)
        print(f"Test {i + 1}: {' '.join(map(str, result))}")

"""
Time Complexity: O(n)
Space Complexity: O(k)
"""

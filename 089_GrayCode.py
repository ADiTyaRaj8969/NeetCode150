# Topic: Gray Code
# Description: Generate n-bit Gray code sequence.
# Approach: Use formula i ^ (i >> 1) for 0..(1<<n)-1. O(2^n) time.

from typing import List


class Solution:
    def grayCode(self, n: int) -> List[int]:
        return [i ^ (i >> 1) for i in range(1 << n)]


if __name__ == "__main__":
    tests = [2, 3, 1]
    for i, n in enumerate(tests):
        print(f"Test {i + 1} (n={n}): {Solution().grayCode(n)}")

"""
Time Complexity: O(2^n)
Space Complexity: O(2^n) for result
"""

# Topic: Pascal's Triangle II
# Description: Return the k-th (0-indexed) row of Pascal's triangle.
# Approach: Build iteratively using O(k) space.

from typing import List


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        row = [1]
        for i in range(1, rowIndex + 1):
            row.append(1)
            for j in range(i - 1, 0, -1):
                row[j] += row[j - 1]
        return row


if __name__ == "__main__":
    tests = [0, 1, 4]
    for i, k in enumerate(tests):
        print(f"Test {i + 1} (k={k}): {Solution().getRow(k)}")

"""
Time Complexity: O(k^2)
Space Complexity: O(k)
"""

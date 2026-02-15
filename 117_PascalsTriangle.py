# Topic: Pascal's Triangle
# Description: Generate the first numRows of Pascal's triangle.
# Approach: Iteratively build rows from previous row.

from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result = []
        for r in range(numRows):
            row = [1] * (r + 1)
            for i in range(1, r):
                row[i] = result[r - 1][i - 1] + result[r - 1][i]
            result.append(row)
        return result


if __name__ == "__main__":
    tests = [1, 3, 5]
    for i, num_rows in enumerate(tests):
        print(f"Test {i + 1} (rows={num_rows}):")
        result = Solution().generate(num_rows)
        for row in result:
            print(row)

"""
Time Complexity: O(numRows^2)
Space Complexity: O(numRows^2)
"""

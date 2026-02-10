# Topic: Daily Temperatures
# Description: For each day, find days until a warmer temperature.
# Approach: Monotonic decreasing stack of indices.

from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        res = [0] * n
        stack = []  # indices with decreasing temperatures
        for i in range(n):
            while stack and temperatures[i] > temperatures[stack[-1]]:
                idx = stack.pop()
                res[idx] = i - idx
            stack.append(i)
        return res


if __name__ == "__main__":
    tests = [[73, 74, 75, 71, 69, 72, 76, 73], [30, 40, 50, 60]]
    sol = Solution()
    for i, temps in enumerate(tests):
        result = sol.dailyTemperatures(temps)
        print(f"Test {i + 1}: {' '.join(map(str, result))}")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

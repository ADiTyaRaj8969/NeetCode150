# Topic: Gas Station
# Description: Given gas and cost arrays, return the starting gas station's index if you can travel
#              around the circuit once, otherwise -1.
# Approach: Greedy: if total gas >= total cost there is a solution; track current tank and reset start when tank < 0.

from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        total = 0
        tank = 0
        start = 0
        for i in range(n):
            total += gas[i] - cost[i]
            tank += gas[i] - cost[i]
            if tank < 0:
                start = i + 1
                tank = 0
        return start if total >= 0 else -1


if __name__ == "__main__":
    tests = [([1, 2, 3, 4, 5], [3, 4, 5, 1, 2]),
             ([2, 3, 4], [3, 4, 3]),
             ([2, 2, 2], [1, 1, 1])]
    for i, (gas, cost) in enumerate(tests):
        print(f"Test {i + 1}: {Solution().canCompleteCircuit(gas, cost)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

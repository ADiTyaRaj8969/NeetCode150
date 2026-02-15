# Topic: Best Time to Buy and Sell Stock II
# Description: Maximize profit with as many transactions as you like (can't hold multiple shares simultaneously).
# Approach: Greedy - sum all positive differences between consecutive days.

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]
        return profit


if __name__ == "__main__":
    tests = [[7, 1, 5, 3, 6, 4], [1, 2, 3, 4, 5], [7, 6, 4, 3, 1]]
    for i, prices in enumerate(tests):
        print(f"Test {i + 1}: {Solution().maxProfit(prices)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

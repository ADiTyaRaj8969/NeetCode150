# Topic: Best Time to Buy and Sell Stock III
# Description: Max profit with at most two transactions.
# Approach: DP: track max profit after first buy/sell and second buy/sell.

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        hold1 = float('-inf')
        sold1 = 0
        hold2 = float('-inf')
        sold2 = 0
        for price in prices:
            hold1 = max(hold1, -price)
            sold1 = max(sold1, hold1 + price)
            hold2 = max(hold2, sold1 - price)
            sold2 = max(sold2, hold2 + price)
        return sold2


if __name__ == "__main__":
    tests = [[3, 3, 5, 0, 0, 3, 1, 4], [1, 2, 3, 4, 5], [7, 6, 4, 3, 1]]
    for i, prices in enumerate(tests):
        print(f"Test {i + 1}: {Solution().maxProfit(prices)}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

# Topic: Best Time to Buy and Sell Stock
# Description: Find max profit from one buy-sell transaction.
# Approach: Track minimum price so far and compute max profit.

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minp = float('inf')
        best = 0
        for p in prices:
            minp = min(minp, p)
            best = max(best, p - minp)
        return best


if __name__ == "__main__":
    tests = [[7, 1, 5, 3, 6, 4], [7, 6, 4, 3, 1]]
    sol = Solution()
    for i, prices in enumerate(tests):
        result = sol.maxProfit(prices)
        print(f"Test {i + 1}: {prices} -> {result}")

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

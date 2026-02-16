# Topic: Candy
# Description: Given ratings of children, distribute candies such that each child has at least one
#              candy and children with higher ratings get more candies than neighbors. Minimize total candies.
# Approach: Two-pass greedy: left-to-right then right-to-left ensuring constraints.

from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        if n == 0:
            return 0
        candies = [1] * n
        # Left to right
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1
        # Right to left
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candies[i] = max(candies[i], candies[i + 1] + 1)
        return sum(candies)


if __name__ == "__main__":
    tests = [[1, 0, 2], [1, 2, 2]]
    for i, ratings in enumerate(tests):
        print(f"Test {i + 1}: {Solution().candy(ratings)}")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

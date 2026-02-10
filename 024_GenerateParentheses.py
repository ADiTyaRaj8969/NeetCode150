# Topic: Generate Parentheses
# Description: Generate all valid combinations of n pairs of parentheses.
# Approach: Backtracking keeping counts of open/close used.

from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        
        def dfs(cur: str, open_count: int, close_count: int):
            if len(cur) == 2 * n:
                res.append(cur)
                return
            if open_count < n:
                dfs(cur + '(', open_count + 1, close_count)
            if close_count < open_count:
                dfs(cur + ')', open_count, close_count + 1)
        
        dfs('', 0, 0)
        return res


if __name__ == "__main__":
    tests = [3, 1]
    sol = Solution()
    for i, n in enumerate(tests):
        result = sol.generateParenthesis(n)
        print(f"Test {i + 1}: n={n} -> {', '.join(result)}")

"""
Time Complexity: Catalan number ~ O(4^n / sqrt(n)) outputs
Space Complexity: O(n) recursion depth plus output storage
"""

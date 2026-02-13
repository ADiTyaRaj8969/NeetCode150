# Topic: Letter Combinations of a Phone Number
# Description: Map digits to letter combinations (telephone digits 2-9).
# Approach: Backtracking building combinations using mapping table.

from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        mapping = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        result = []
        cur = []

        def dfs(idx):
            if idx == len(digits):
                result.append(''.join(cur))
                return
            d = int(digits[idx])
            for c in mapping[d]:
                cur.append(c)
                dfs(idx + 1)
                cur.pop()

        dfs(0)
        return result


if __name__ == "__main__":
    tests = ["23", ""]
    for i, digits in enumerate(tests):
        result = Solution().letterCombinations(digits)
        print(f"Test {i + 1} -> {result}")

"""
Time Complexity: O(4^n * n) where n = number of digits (4 for digits with 4 letters)
Space Complexity: O(n) recursion depth + output
"""

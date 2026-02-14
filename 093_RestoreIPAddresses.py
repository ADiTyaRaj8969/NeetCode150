# Topic: Restore IP Addresses
# Description: Given a string containing only digits, restore all possible valid IP address combinations.
# Approach: Backtracking with pruning; each segment must be 0..255 and no leading zeros (unless segment is '0').

from typing import List


class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n = len(s)
        if n < 4 or n > 12:
            return []
        result = []
        cur = []

        def valid(start, length):
            if length <= 0 or length > 3:
                return False
            if s[start] == '0' and length > 1:
                return False
            val = int(s[start:start + length])
            return val <= 255

        def dfs(idx, seg):
            if seg == 4:
                if idx == n:
                    result.append('.'.join(cur))
                return
            for length in range(1, 4):
                if idx + length > n:
                    break
                if not valid(idx, length):
                    continue
                cur.append(s[idx:idx + length])
                dfs(idx + length, seg + 1)
                cur.pop()

        dfs(0, 0)
        return result


if __name__ == "__main__":
    tests = ["25525511135", "0000", "101023"]
    for i, s in enumerate(tests):
        print(f"Test {i + 1}:")
        result = Solution().restoreIpAddresses(s)
        for r in result:
            print(f"  {r}")

"""
Time Complexity: O(1) bounded by branching factor (at most 3^4 candidates)
Space Complexity: O(1) extra excluding output (recursive depth <= 4)
"""

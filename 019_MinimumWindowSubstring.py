# Topic: Minimum Window Substring
# Description: Find smallest substring containing all characters of another string.
# Approach: Sliding window with frequency counts and expand/contract pointers.

from collections import Counter


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""
        need = Counter(t)
        required = len(t)
        l = 0
        best_l, best_len = 0, float('inf')
        
        for r in range(len(s)):
            if need[s[r]] > 0:
                required -= 1
            need[s[r]] -= 1
            
            while required == 0:
                if r - l + 1 < best_len:
                    best_len = r - l + 1
                    best_l = l
                need[s[l]] += 1
                if need[s[l]] > 0:
                    required += 1
                l += 1
        
        return "" if best_len == float('inf') else s[best_l:best_l + best_len]


if __name__ == "__main__":
    tests = [("ADOBECODEBANC", "ABC"), ("a", "a"), ("a", "aa")]
    sol = Solution()
    for i, (s, t) in enumerate(tests):
        result = sol.minWindow(s, t)
        print(f'Test {i + 1}: s="{s}", t="{t}" -> "{result}"')

"""
Time Complexity: O(n + m)
Space Complexity: O(1) (limited charset)
"""

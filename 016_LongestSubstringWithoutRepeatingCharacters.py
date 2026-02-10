# Topic: Longest Substring Without Repeating Characters
# Description: Find length of substring with all unique characters.
# Approach: Sliding window with last-seen indices dictionary.


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last = {}
        start = 0
        best = 0
        for i, c in enumerate(s):
            if c in last and last[c] >= start:
                start = last[c] + 1
            best = max(best, i - start + 1)
            last[c] = i
        return best


if __name__ == "__main__":
    tests = ["abcabcbb", "bbbbb", "pwwkew"]
    sol = Solution()
    for i, s in enumerate(tests):
        result = sol.lengthOfLongestSubstring(s)
        print(f'Test {i + 1}: "{s}" -> {result}')

"""
Time Complexity: O(n)
Space Complexity: O(min(n, charset_size))
"""

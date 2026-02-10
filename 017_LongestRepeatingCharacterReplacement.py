# Topic: Longest Repeating Character Replacement
# Description: Maximize substring length after at most k replacements.
# Approach: Sliding window keeping counts and max frequency in window.


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        cnt = [0] * 26
        maxf = 0
        left = 0
        best = 0
        for right in range(len(s)):
            cnt[ord(s[right]) - ord('A')] += 1
            maxf = max(maxf, cnt[ord(s[right]) - ord('A')])
            while right - left + 1 - maxf > k:
                cnt[ord(s[left]) - ord('A')] -= 1
                left += 1
            best = max(best, right - left + 1)
        return best


if __name__ == "__main__":
    tests = [("ABAB", 2), ("AABABBA", 1), ("AAAA", 2)]
    sol = Solution()
    for i, (s, k) in enumerate(tests):
        result = sol.characterReplacement(s, k)
        print(f'Test {i + 1}: "{s}", k={k} -> {result}')

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

# Topic: Valid Anagram
# Description: Determine if two strings have identical character frequencies.
# Approach: Count characters using a dictionary or Counter.

from collections import Counter


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        cnt = [0] * 26
        for i in range(len(s)):
            cnt[ord(s[i]) - ord('a')] += 1
            cnt[ord(t[i]) - ord('a')] -= 1
        return all(x == 0 for x in cnt)


if __name__ == "__main__":
    tests = [("anagram", "nagaram"), ("rat", "car")]
    sol = Solution()
    for i, (s, t) in enumerate(tests):
        result = sol.isAnagram(s, t)
        print(f"Test {i + 1}: ({s},{t}) -> {result}")

"""
Time Complexity: O(n)
Space Complexity: O(1) (26-size array)
"""

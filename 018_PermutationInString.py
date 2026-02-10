# Topic: Permutation in String
# Description: Check if one string's permutation exists within another.
# Approach: Sliding window with char counts, compare frequency arrays.


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m, n = len(s1), len(s2)
        if m > n:
            return False
        need = [0] * 26
        for c in s1:
            need[ord(c) - ord('a')] += 1
        window = [0] * 26
        for i in range(n):
            window[ord(s2[i]) - ord('a')] += 1
            if i >= m:
                window[ord(s2[i - m]) - ord('a')] -= 1
            if window == need:
                return True
        return False


if __name__ == "__main__":
    tests = [("ab", "eidbaooo"), ("ab", "eidboaoo"), ("adc", "dcda")]
    sol = Solution()
    for i, (s1, s2) in enumerate(tests):
        result = sol.checkInclusion(s1, s2)
        print(f'Test {i + 1}: s1="{s1}", s2="{s2}" -> {result}')

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

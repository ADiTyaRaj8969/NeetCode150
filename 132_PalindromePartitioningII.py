# Topic: Palindrome Partitioning II
# Description: Given a string s, return the minimum cuts needed for a palindrome partitioning of s.
# Approach: Expand-around-center to find palindromes and maintain min-cuts DP array in O(n^2) time.


class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        if n <= 1:
            return 0
        cuts = list(range(n))  # max cuts: cuts[i] = i

        for center in range(n):
            # Odd length palindromes
            l, r = center, center
            while l >= 0 and r < n and s[l] == s[r]:
                new_cut = cuts[l - 1] + 1 if l > 0 else 0
                cuts[r] = min(cuts[r], new_cut)
                l -= 1
                r += 1

            # Even length palindromes
            l, r = center, center + 1
            while l >= 0 and r < n and s[l] == s[r]:
                new_cut = cuts[l - 1] + 1 if l > 0 else 0
                cuts[r] = min(cuts[r], new_cut)
                l -= 1
                r += 1

        return cuts[n - 1]


if __name__ == "__main__":
    tests = ["aab", "a", "ab"]
    for i, s in enumerate(tests):
        print(f"Test {i + 1}: {Solution().minCut(s)}")

"""
Time Complexity: O(n^2)
Space Complexity: O(n)
"""

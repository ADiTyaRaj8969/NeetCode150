# Topic: Valid Palindrome
# Description: Check if a string reads the same backward ignoring punctuation and case.
# Approach: Two-pointer with char filtering and case normalization.


class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            while i < j and not s[i].isalnum():
                i += 1
            while i < j and not s[j].isalnum():
                j -= 1
            if s[i].lower() != s[j].lower():
                return False
            i += 1
            j -= 1
        return True


if __name__ == "__main__":
    tests = ["A man, a plan, a canal: Panama", "race a car"]
    sol = Solution()
    for i, test in enumerate(tests):
        result = sol.isPalindrome(test)
        print(f'Test {i + 1}: "{test}" -> {result}')

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""

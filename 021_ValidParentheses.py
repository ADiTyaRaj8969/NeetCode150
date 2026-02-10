# Topic: Valid Parentheses
# Description: Determine if parentheses sequence is properly nested.
# Approach: Use a stack to match closing to last opening bracket.


class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {')': '(', ']': '[', '}': '{'}
        for c in s:
            if c in '([{':
                stack.append(c)
            else:
                if not stack:
                    return False
                t = stack.pop()
                if t != mapping[c]:
                    return False
        return len(stack) == 0


if __name__ == "__main__":
    tests = ["()", "()[]{}", "(]"]
    sol = Solution()
    for i, test in enumerate(tests):
        result = sol.isValid(test)
        print(f'Test {i + 1}: "{test}" -> {result}')

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

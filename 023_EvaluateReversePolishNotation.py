# Topic: Evaluate Reverse Polish Notation
# Description: Compute arithmetic expression written in postfix notation.
# Approach: Use stack to evaluate tokens; support + - * / (integer division trunc toward zero)

from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for tok in tokens:
            if tok in "+-*/":
                b = stack.pop()
                a = stack.pop()
                if tok == '+':
                    stack.append(a + b)
                elif tok == '-':
                    stack.append(a - b)
                elif tok == '*':
                    stack.append(a * b)
                else:
                    # Integer division truncates toward zero
                    stack.append(int(a / b))
            else:
                stack.append(int(tok))
        return stack[-1]


if __name__ == "__main__":
    tests = [["2", "1", "+", "3", "*"], ["4", "13", "5", "/", "+"]]
    sol = Solution()
    for i, tokens in enumerate(tests):
        result = sol.evalRPN(tokens)
        print(f"Test {i + 1}: {' '.join(tokens)} -> {result}")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

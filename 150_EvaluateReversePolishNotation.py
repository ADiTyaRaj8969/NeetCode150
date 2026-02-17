# Topic: Evaluate Reverse Polish Notation
# Description: Evaluate the value of an arithmetic expression in Reverse Polish Notation.
# Approach: Use a stack to process tokens (numbers or operators).

from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token in {'+', '-', '*', '/'}:
                b = stack.pop()
                a = stack.pop()
                if token == '+':
                    stack.append(a + b)
                elif token == '-':
                    stack.append(a - b)
                elif token == '*':
                    stack.append(a * b)
                elif token == '/':
                    # Truncate toward zero
                    stack.append(int(a / b))
            else:
                stack.append(int(token))
        return stack[0]


if __name__ == "__main__":
    tests = [["2", "1", "+", "3", "*"],
             ["4", "13", "5", "/", "+"],
             ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]]
    for i, tokens in enumerate(tests):
        print(f"Test {i + 1}: {Solution().evalRPN(tokens)}")

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""

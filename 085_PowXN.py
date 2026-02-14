# Topic: Pow(x, n)
# Description: Implement pow(x, n) to compute x raised to the power n (n can be negative).
# Approach: Fast exponentiation (binary exponentiation). Handle negative exponent by reciprocal.


class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1.0
        exp = abs(n)
        result = 1.0
        while exp > 0:
            if exp & 1:
                result *= x
            x *= x
            exp >>= 1
        return result if n > 0 else 1.0 / result


if __name__ == "__main__":
    tests = [(2.00000, 10), (2.10000, 3), (2.00000, -2)]
    for i, (x, n) in enumerate(tests):
        print(f"Test {i + 1}: {Solution().myPow(x, n):.5f}")

"""
Time Complexity: O(log |n|)
Space Complexity: O(1)
"""

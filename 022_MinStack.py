# Topic: Min Stack
# Description: Design stack supporting push, pop, top, and retrieving current minimum in O(1).
# Approach: Maintain main stack and stack of current minimums (or store paired values).


class MinStack:
    def __init__(self):
        self.stack = []  # stores (value, current_min)

    def push(self, val: int) -> None:
        if not self.stack:
            self.stack.append((val, val))
        else:
            self.stack.append((val, min(val, self.stack[-1][1])))

    def pop(self) -> None:
        if self.stack:
            self.stack.pop()

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]


if __name__ == "__main__":
    # Test scenario 1
    ms = MinStack()
    ms.push(-2)
    ms.push(0)
    ms.push(-3)
    print(f"Test 1: getMin -> {ms.getMin()}")  # expect -3
    ms.pop()
    print(f"Test 1: top -> {ms.top()}")  # expect 0
    print(f"Test 1: getMin -> {ms.getMin()}")  # expect -2

    # Test scenario 2
    ms2 = MinStack()
    ms2.push(2)
    ms2.push(2)
    ms2.pop()
    print(f"Test 2: top -> {ms2.top()}")  # expect 2
    print(f"Test 2: getMin -> {ms2.getMin()}")  # expect 2

"""
Time Complexity: O(1) per operation
Space Complexity: O(n)
"""

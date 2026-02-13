# Topic: Implement Queue using Stacks
# Description: Implement a queue with push, pop, peek, and empty using two stacks.
# Approach: Use two stacks, 'in_stack' for pushing and 'out_stack' for popping. Amortized O(1) per operation.


class MyQueue:
    def __init__(self):
        self.in_stack = []
        self.out_stack = []

    def _move(self):
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())

    def push(self, x: int) -> None:
        self.in_stack.append(x)

    def pop(self) -> int:
        self._move()
        return self.out_stack.pop()

    def peek(self) -> int:
        self._move()
        return self.out_stack[-1]

    def empty(self) -> bool:
        return not self.in_stack and not self.out_stack


if __name__ == "__main__":
    q = MyQueue()
    q.push(1)
    q.push(2)
    print(f"peek -> {q.peek()}")   # 1
    print(f"pop -> {q.pop()}")     # 1
    print(f"empty -> {q.empty()}") # False

"""
Time Complexity: Amortized O(1) per operation
Space Complexity: O(n)
"""
